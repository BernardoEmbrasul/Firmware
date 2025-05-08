#ifndef __LINHABASICA_PORT_H
#define __LINHABASICA_PORT_H


#include <stdint.h>

#define BYTE uint8_t
#define BOOL uint8_t
#define U8 uint8_t
#define U16 uint16_t
#define U32 uint32_t
#define WORD uint16_t
#define DWORD  uint32_t
typedef long long          S64;
typedef unsigned long long U64;

#ifndef NULL
#define NULL    ((void *)0)
#endif

#ifndef FALSE
#define FALSE   (0)
#endif

#ifndef TRUE
#define TRUE    (1)
#endif




#define __irq
//#define  BaseBattRam                     (*((volatile float *)    &MapaModbus.RegistrosModbus[0]))

#define NETIF_ETH       0         /* Network interface: Ethernet             */
#define __FALSE 0
#define __TRUE 1


#define IP4_ADDR_LEN    4
#define IP_ADRLEN       4

typedef struct localm {
  uint8_t IpAdr [IP4_ADDR_LEN];  // Local IP Address
  uint8_t DefGW  [IP4_ADDR_LEN];  // Default GateWay
  uint8_t NetMask[IP4_ADDR_LEN];  // Net Mask
  uint8_t PriDNS [IP4_ADDR_LEN];  // Primary DNS Server
  uint8_t SecDNS [IP4_ADDR_LEN];  // Secondary DNS Server
} LOCALM;


typedef struct {
uint8_t RegistrosModbus[1024*2];
} __attribute__ ((packed)) regmodbus;








EXT void	TargetInit();
EXT void	GPIOResetInit();


EXT void ConfigurePLL_72Mhz();
EXT void ConfigurePLL_48Mhz();
EXT void ConfigurePLL_18Mhz();




EXT void main_TcpNet();

extern unsigned int program(void *flash_addr, unsigned long int data, unsigned int size);
extern void erase(void* start, void* end);


EXT unsigned int T0CCR;
EXT unsigned int SSP0SR;
EXT unsigned int SSP0DR;
EXT unsigned int SSP1DR;
EXT unsigned int SSP1SR;


EXT uint32_t LerPinosEmPorta(uint32_t PortaLPC,uint32_t mascara);
//EXT void EscreverPinosEmPorta(uint32_t PortaLPC,uint32_t mascara);
EXT void SETpinoEmPorta(uint32_t PortaLPC,uint32_t mascara);
EXT void CLRpinoEmPorta(uint32_t PortaLPC,uint32_t mascara);


EXT void DisableAllInterrupts(void);
EXT void DisablePoweDownInterrupt(void);
EXT void EnablePoweDownInterrupt(void);

#endif
