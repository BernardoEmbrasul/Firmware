# -*- coding: utf-8 -*-
import struct
import socket
import numpy as np
import time 
import sys

def longwordTobuffer(buffer,lword):
   array=np.zeros(4, dtype=np.uint8)
   offset=0
   array[3] = ( lword>>24) & 0xff
   array[2] = ( lword>>16) & 0xff
   array[1] = ( lword>>8) & 0xff
   array[0] =  lword & 0xff      
   buffer.append(array[0+offset])
   buffer.append(array[1+offset])
   buffer.append(array[2+offset])
   buffer.append(array[3+offset])
   
   return buffer
 

def longwordTobuffer1(buffer,lword):
   array=np.zeros(4, dtype=np.uint8)
   offset=0
   array[0] = ( lword>>24) & 0xff
   array[1] = ( lword>>16) & 0xff
   array[2] = ( lword>>8) & 0xff
   array[3] =  lword & 0xff      
   buffer.append(array[0+offset])
   buffer.append(array[1+offset])
   buffer.append(array[2+offset])
   buffer.append(array[3+offset])
   
   return buffer
   
def enviar(buffer,equip_addr):
    sent=sock.sendto(buffer,equip_addr)
    #i=0
    #while True:
    #    try:
    #        print(hex(buffer[i]))
    #        i=i+1
    #    except:
    #        break

 

# total arguments
print("O bootloader usará o ip:10.1.25.100, porta 1001")
n = len(sys.argv)
#if n!=2:
if False:
    print("use apenas 1 argumento: filename_with_fullpath")
else:
    print("conectando...")
    #x = sys.argv[1] #.split(" ", 1)
    #filename_with_fullpath=(x)
    filename_with_fullpath="PortLinhaBasicaComSTM32F427AGH6_mod.bin"
    #print(filename_with_fullpath)
    sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    sock.settimeout(10)
    equip_addr=('10.1.25.100', 1001)

    #vamos apagar tudo...
    for i in range(0,5):
        buffer=bytearray(0)
        command=0xFFFFFFFF
        adressFlash=0x08020000+0x20000*i #do setor 5: 0x08020000  até setor 8 :0x08080000
        dataToFlash=0xFFFFFFFF
        buffer=longwordTobuffer(buffer,command)
        buffer=longwordTobuffer(buffer,adressFlash)
        buffer=longwordTobuffer1(buffer,dataToFlash)


        sent=sock.sendto(buffer,equip_addr)
        data, equip =sock.recvfrom(4096)
        time.sleep(1)
        print('in hex =', hex(adressFlash))
        print(adressFlash)
    
    print("abrindo o arquivo .bin  ...")

    #f = open("C:\\Users\\cesar\\OneDrive\\ProjetosSTM32\\PortLinhaBasicaComSTM32F427AGH6\\Debug\\PortLinhaBasicaComSTM32F427AGH6.bin","rb")
    #filename_with_fullpath="C:\\Users\\cesar\\OneDrive\\ProjetosSTM32\\PortLinhaBasicaComSTM32F427AGH6\\Debug\\PortLinhaBasicaComSTM32F427AGH6.bin"

    f = open("update.bin", "rb")
    word = f.read(4)
       
    #print("first word ")
    #print(word)
    command=0x1BABACA1
    adressFlash=0x08020000
    buffer=bytearray(0)
    gogo=0
    dadofake=0 
    DADOS_FAKE=0
    buffer=longwordTobuffer(buffer,command)
    buffer=longwordTobuffer(buffer,adressFlash)
    finalizando=0
        
    while (True):

        gogo=gogo+1  #a cada gogo, vai uma word de 32bits a mais...
        if finalizando==0:
            if DADOS_FAKE==0:
                dataToFlash=struct.unpack('>I',word)[0]
            else:
                dataToFlash=dadofake
        else:
            dataToFlash=0xFFFFFFFF
       
        buffer=longwordTobuffer1(buffer,dataToFlash)
        adressFlash=adressFlash+4
        #print(hex(dataToFlash))

        
 
        if gogo%(64*2)==0:
            print("enviando rajada..."+str(gogo*4))

            #time.sleep(0.1)
            enviar(buffer,equip_addr)
            
            data, equip =sock.recvfrom(4096)
   
            buffer=bytearray(0)
            
            if ((finalizando==1) and (command==0x2BABACA2)):
                break
            if finalizando==1:
                command=0x2BABACA2
            else:
                command=0x1BABACA1
            
             
            buffer=longwordTobuffer(buffer,command)
            buffer=longwordTobuffer(buffer,adressFlash)
            
        if (gogo%(256*64))==0:
            print("programando 64kbytes..."+str(gogo*4))
            buffer=bytearray(0)
            command=0x2BABACA2
            buffer=longwordTobuffer(buffer,command)
            buffer=longwordTobuffer(buffer,adressFlash)
            buffer=longwordTobuffer1(buffer,dataToFlash)            
            time.sleep(1)
            sent=sock.sendto(buffer,equip_addr)
            data, equip =sock.recvfrom(4096)            
            time.sleep(2)
            buffer=bytearray(0)
            command=0x1BABACA1
            buffer=longwordTobuffer(buffer,command)
            buffer=longwordTobuffer(buffer,adressFlash)
            if finalizando==1:
                break

        
        word=f.read(4)
  
        dadofake=dadofake+1
        
        if (word):
            pass
        else:#chegou ao fim do arquivo....
            word=0xFFFFFFFF;
            finalizando=1
            print("...completando buffer ... ")
        
        
        
             
        
        
    #print(dadofake)
    f.close()
    #vamos resetar a placa
    buffer=bytearray(0)
    command=0xDEADBEEF
    adressFlash=0x08020000 #setor 5: 0x08020000 
    dataToFlash=0xFFFFFFFF
    buffer=longwordTobuffer(buffer,command)
    buffer=longwordTobuffer(buffer,adressFlash)
    buffer=longwordTobuffer1(buffer,dataToFlash)
  

    sent=sock.sendto(buffer,equip_addr)
    #data, equip =sock.recvfrom(4096)

    sock.close()

    input("feito!")

