/*****************************************************************************
 *   uarttest.c:  main C entry file for NXP LPC23xx Family Microprocessors
 *
 *   Copyright(C) 2006, NXP Semiconductor
 *   All rights reserved.
 *
 *   History
 *   2006.07.13  ver 1.00    Prelimnary version, first Release
 *
 ******************************************************************************/
//#define EXT extern



#ifndef __ESPECIFIC_H
#define __ESPECIFIC_H
#include "config1.h"
#include "config.h"
#include "linhabasica_port.h"
#include "rtc.h"
#include "flash.h"
#include "battram.h"


extern regmodbus MapaModbus;

extern U8 own_hw_adr[];
extern U8 lhost_name[];

#define vol


#define  Versao                     (*((vol float *) &MapaModbus.RegistrosModbus[0*2]))
#define  FuncaoRemota               (*((vol short *) &MapaModbus.RegistrosModbus[2*2]))
#define  FuncaoRemota1              (*((vol short *) &MapaModbus.RegistrosModbus[3*2]))
#define  relacaoTPpri               (*((vol short *) &MapaModbus.RegistrosModbus[4*2]))
#define  relacaoTPsec               (*((vol short *) &MapaModbus.RegistrosModbus[5*2]))
#define  relacaoTPfat               (*((vol short *) &MapaModbus.RegistrosModbus[6*2]))
#define  relacaoTCpri               (*((vol short *) &MapaModbus.RegistrosModbus[7*2]))
#define  relacaoTCsec               (*((vol short *) &MapaModbus.RegistrosModbus[8*2]))
#define  relacaoTCfat               (*((vol short *) &MapaModbus.RegistrosModbus[9*2]))
#define  rtc_data                   (*((vol RTCTime *) &MapaModbus.RegistrosModbus[10*2]))
#define  hora_ponta_inicio1        (*((vol short *) &MapaModbus.RegistrosModbus[18*2]))
#define  min_ponta_inicio1 		   (*((vol short *) &MapaModbus.RegistrosModbus[19*2]))
#define  hora_fora_ponta_inicio1   (*((vol short *) &MapaModbus.RegistrosModbus[20*2]))
#define  min_fora_ponta_inicio1    (*((vol short *) &MapaModbus.RegistrosModbus[21*2]))
#define  hora_reserv_inicio1 	   (*((vol short *) &MapaModbus.RegistrosModbus[22*2]))
#define  min_reserv_inicio1 	   (*((vol short *) &MapaModbus.RegistrosModbus[23*2]))
#define  hora_ponta_inicio2 	   (*((vol short *) &MapaModbus.RegistrosModbus[24*2]))
#define  min_ponta_inicio2 		   (*((vol short *) &MapaModbus.RegistrosModbus[25*2]))
#define  hora_fora_ponta_inicio2   (*((vol short *) &MapaModbus.RegistrosModbus[26*2]))
#define  min_fora_ponta_inicio2    (*((vol short *) &MapaModbus.RegistrosModbus[27*2]))
#define  hora_reserv_inicio2 	   (*((vol short *) &MapaModbus.RegistrosModbus[28*2]))
#define  min_reserv_inicio2 	   (*((vol short *) &MapaModbus.RegistrosModbus[29*2]))
#define  hora_ponta_inicio3 	   (*((vol short *) &MapaModbus.RegistrosModbus[30*2]))
#define  min_ponta_inicio3 		   (*((vol short *) &MapaModbus.RegistrosModbus[31*2]))
#define  hora_fora_ponta_inicio3   (*((vol short *) &MapaModbus.RegistrosModbus[32*2]))
#define  min_fora_ponta_inicio3    (*((vol short *) &MapaModbus.RegistrosModbus[33*2]))
#define  hora_reserv_inicio3 	   (*((vol short *) &MapaModbus.RegistrosModbus[34*2]))
#define  min_reserv_inicio3 	   (*((vol short *) &MapaModbus.RegistrosModbus[35*2]))
#define  hora_ponta_inicio4 	   (*((vol short *) &MapaModbus.RegistrosModbus[36*2]))
#define  min_ponta_inicio4 		   (*((vol short *) &MapaModbus.RegistrosModbus[37*2]))
#define  hora_fora_ponta_inicio4   (*((vol short *) &MapaModbus.RegistrosModbus[38*2]))
#define  min_fora_ponta_inicio4    (*((vol short *) &MapaModbus.RegistrosModbus[39*2]))
#define  hora_reserv_inicio4 	   (*((vol short *) &MapaModbus.RegistrosModbus[40*2]))
#define  min_reserv_inicio4 	   (*((vol short *) &MapaModbus.RegistrosModbus[41*2]))

//aten��o abaixo � defini��o de vetores
#define  feriados    			   (((vol short * ) &MapaModbus.RegistrosModbus[42*2]))

#define  relacaoTP 	 	                            (*((vol float *) &MapaModbus.RegistrosModbus[62*2]))
#define  relacaoTC 					 	 	        (*((vol float *) &MapaModbus.RegistrosModbus[64*2]))
#define  FreqA 						 	 	        (*((vol float *) &MapaModbus.RegistrosModbus[66*2]))
#define  UrmsA						 	 	        (*((vol float *) &MapaModbus.RegistrosModbus[68*2]))
#define  UrmsB						 	 	        (*((vol float *) &MapaModbus.RegistrosModbus[70*2]))
#define  UrmsC 						 	 	        (*((vol float *) &MapaModbus.RegistrosModbus[72*2]))
#define  IrmsA						 	 	        (*((vol float *) &MapaModbus.RegistrosModbus[74*2]))
#define  IrmsB						 	 	        (*((vol float *) &MapaModbus.RegistrosModbus[76*2]))
#define  IrmsC 						 	 	        (*((vol float *) &MapaModbus.RegistrosModbus[78*2]))
#define  PotAtivA						 	 	    (*((vol float *) &MapaModbus.RegistrosModbus[80*2]))
#define  PotAtivB						 	 	    (*((vol float *) &MapaModbus.RegistrosModbus[82*2]))
#define  PotAtivC						 	 	    (*((vol float *) &MapaModbus.RegistrosModbus[84*2]))
#define  PotAtivT 					 	 	        (*((vol float *) &MapaModbus.RegistrosModbus[86*2]))
#define  PotReatA						 	 	    (*((vol float *) &MapaModbus.RegistrosModbus[88*2]))
#define  PotReatB					 	 	 	    (*((vol float *) &MapaModbus.RegistrosModbus[90*2]))
#define  PotReatC						 	 	    (*((vol float *) &MapaModbus.RegistrosModbus[92*2]))
#define  PotReatT 					 	 	        (*((vol float *) &MapaModbus.RegistrosModbus[94*2]))
#define  PotAparA						 	 	    (*((vol float *) &MapaModbus.RegistrosModbus[96*2]))
#define  PotAparB						 	 	    (*((vol float *) &MapaModbus.RegistrosModbus[98*2]))
#define  PotAparC						 	 	    (*((vol float *) &MapaModbus.RegistrosModbus[100*2]))
#define  PotAparT 					 	 	        (*((vol float *) &MapaModbus.RegistrosModbus[102*2]))
#define  FatPotA						 	 	    (*((vol float *) &MapaModbus.RegistrosModbus[104*2]))
#define  FatPotB						 	 	    (*((vol float *) &MapaModbus.RegistrosModbus[106*2]))
#define  FatPotC						 	 	    (*((vol float *) &MapaModbus.RegistrosModbus[108*2]))
#define  FatPotT 						 	 	    (*((vol float *) &MapaModbus.RegistrosModbus[110*2]))
#define  DhtUA						 	 	        (*((vol float *) &MapaModbus.RegistrosModbus[112*2]))
#define  DhtUB						 	 	        (*((vol float *) &MapaModbus.RegistrosModbus[114*2]))
#define  DhtUC 						 	 	        (*((vol float *) &MapaModbus.RegistrosModbus[116*2]))
#define  DhtIA						 	 	        (*((vol float *) &MapaModbus.RegistrosModbus[118*2]))
#define  DhtIB						 	 	        (*((vol float *) &MapaModbus.RegistrosModbus[120*2]))
#define  DhtIC 						 	 	        (*((vol float *) &MapaModbus.RegistrosModbus[122*2]))
#define  EnergGerA					 	 	        (*((vol float *) &MapaModbus.RegistrosModbus[124*2]))
#define  EnergGerB					 	 	        (*((vol float *) &MapaModbus.RegistrosModbus[126*2]))
#define  EnergGerC					 	 	        (*((vol float *) &MapaModbus.RegistrosModbus[128*2]))
#define  EnergGerT					 	 	        (*((vol float *) &MapaModbus.RegistrosModbus[130*2]))
#define  ConsumoA						 	 	    (*((vol float *) &MapaModbus.RegistrosModbus[132*2]))
#define  ConsumoB						 	 	    (*((vol float *) &MapaModbus.RegistrosModbus[134*2]))
#define  ConsumoC						 	 	    (*((vol float *) &MapaModbus.RegistrosModbus[136*2]))
#define  ConsumoT 					 	 	        (*((vol float *) &MapaModbus.RegistrosModbus[138*2]))
#define  EnergIndA					 	 	        (*((vol float *) &MapaModbus.RegistrosModbus[140*2]))
#define  EnergIndB					 	 	        (*((vol float *) &MapaModbus.RegistrosModbus[142*2]))
#define  EnergIndC					 	 	        (*((vol float *) &MapaModbus.RegistrosModbus[144*2]))
#define  EnergIndT					 		        (*((vol float *) &MapaModbus.RegistrosModbus[146*2]))
#define  EnergCapA					 		        (*((vol float *) &MapaModbus.RegistrosModbus[148*2]))
#define  EnergCapB					 		        (*((vol float *) &MapaModbus.RegistrosModbus[150*2]))
#define  EnergCapC					 		        (*((vol float *) &MapaModbus.RegistrosModbus[152*2]))
#define  EnergCapT					 		        (*((vol float *) &MapaModbus.RegistrosModbus[154*2]))

#define  TemperaturaCh0							(*((vol float *) &MapaModbus.RegistrosModbus[156*2]))
#define  TemperaturaCh1							(*((vol float *) &MapaModbus.RegistrosModbus[158*2]))


#define TimeStampToRead	(*((vol  U64 *) &MapaModbus.RegistrosModbus[160*2]))
#define TimeStampReaded	(*((vol  U64 *) &MapaModbus.RegistrosModbus[200*2]))


#define UaReaded 	 	          (*((vol float *) &MapaModbus.RegistrosModbus[204*2]))
#define UbReaded		          (*((vol float *) &MapaModbus.RegistrosModbus[206*2]))
#define UcReaded		          (*((vol float *) &MapaModbus.RegistrosModbus[208*2]))
#define IaReaded		          (*((vol float *) &MapaModbus.RegistrosModbus[210*2]))
#define IbReaded 	 	          (*((vol float *) &MapaModbus.RegistrosModbus[212*2]))
#define IcReaded 		          (*((vol float *) &MapaModbus.RegistrosModbus[214*2]))
#define PReaded 		          (*((vol float *) &MapaModbus.RegistrosModbus[216*2]))
#define QReaded   	              (*((vol float *) &MapaModbus.RegistrosModbus[218*2]))
#define TempReaded 	              (*((vol float *) &MapaModbus.RegistrosModbus[220*2]))
#define TempReaded2 	          (*((vol float *) &MapaModbus.RegistrosModbus[222*2]))
#define pulso1readed              (*((vol float *) &MapaModbus.RegistrosModbus[224*2]))
#define pulso2readed              (*((vol float *) &MapaModbus.RegistrosModbus[226*2]))
#define StatusDosRelesReaded      (*((vol float *) &MapaModbus.RegistrosModbus[228*2]))
#define flashLRC	               (*((vol U64 *) &MapaModbus.RegistrosModbus[230*2]))


#if EQUIP==MD_EQUIP
#define  EnergGerPontaMesPassado			(*((vol float *) &MapaModbus.RegistrosModbus[854*2]))
#define  EnergGerForaPontaMesPassado		(*((vol float *) &MapaModbus.RegistrosModbus[856*2]))   //     (*((vol float *) &MapaModbus.RegistrosModbus[158*2]))
#define  EnergGerReservMesPassado 			(*((vol float *) &MapaModbus.RegistrosModbus[858*2]))       //     (*((vol float *) &MapaModbus.RegistrosModbus[160*2]))
#define  ConsumoPontaMesPassado				(*((vol float *) &MapaModbus.RegistrosModbus[860*2]))       //     (*((vol float *) &MapaModbus.RegistrosModbus[162*2]))
#define  ConsumoForaPontaMesPassado			(*((vol float *) &MapaModbus.RegistrosModbus[862*2]))       //     (*((vol float *) &MapaModbus.RegistrosModbus[164*2]))
#define  ConsumoReservMesPassado 			(*((vol float *) &MapaModbus.RegistrosModbus[864*2]))   //     (*((vol float *) &MapaModbus.RegistrosModbus[166*2]))
#define  EnergIndPontaMesPassado			(*((vol float *) &MapaModbus.RegistrosModbus[866*2]))   //     (*((vol float *) &MapaModbus.RegistrosModbus[168*2]))
#define  EnergIndForaPontaMesPassado		(*((vol float *) &MapaModbus.RegistrosModbus[868*2]))   //     (*((vol float *) &MapaModbus.RegistrosModbus[170*2]))
#define  EnergIndReservMesPassado 			(*((vol float *) &MapaModbus.RegistrosModbus[870*2]))       //     (*((vol float *) &MapaModbus.RegistrosModbus[172*2]))
#define  EnergCapPontaMesPassado			(*((vol float *) &MapaModbus.RegistrosModbus[872*2]))   //     (*((vol float *) &MapaModbus.RegistrosModbus[174*2]))
#define  EnergCapForaPontaMesPassado		(*((vol float *) &MapaModbus.RegistrosModbus[874*2]))   //     (*((vol float *) &MapaModbus.RegistrosModbus[176*2]))
#define  EnergCapReservMesPassado 			(*((vol float *) &MapaModbus.RegistrosModbus[876*2]))       //     (*((vol float *) &MapaModbus.RegistrosModbus[178*2]))
#define  MaxPotAtivPontaMesPassado			(*((vol float *) &MapaModbus.RegistrosModbus[878*2]))       //     (*((vol float *) &MapaModbus.RegistrosModbus[180*2]))
#define  MaxPotAtivForaPontaMesPassado		(*((vol float *) &MapaModbus.RegistrosModbus[880*2]))       //     (*((vol float *) &MapaModbus.RegistrosModbus[182*2]))
#define  MaxPotAtivReservMesPassado			(*((vol float *) &MapaModbus.RegistrosModbus[882*2]))       //     (*((vol float *) &MapaModbus.RegistrosModbus[184*2]))
#define  MaxPotReatPontaMesPassado			(*((vol float *) &MapaModbus.RegistrosModbus[884*2]))       //     (*((vol float *) &MapaModbus.RegistrosModbus[186*2]))
#define  MaxPotReatForaPontaMesPassado		(*((vol float *) &MapaModbus.RegistrosModbus[886*2]))       //     (*((vol float *) &MapaModbus.RegistrosModbus[188*2]))
#define  MaxPotReatReservMesPassado 		(*((vol float *) &MapaModbus.RegistrosModbus[888*2]))   //     (*((vol float *) &MapaModbus.RegistrosModbus[190*2]))
#define  EnergGerPontaEsteMesAteAgora		(*((vol float *) &MapaModbus.RegistrosModbus[890*2]))   //     (*((vol float *) &MapaModbus.RegistrosModbus[192*2]))
#define  EnergGerForaPontaEsteMesAteAgora	(*((vol float *) &MapaModbus.RegistrosModbus[892*2]))   //     (*((vol float *) &MapaModbus.RegistrosModbus[194*2]))
#define  EnergGerReservEsteMesAteAgora 		(*((vol float *) &MapaModbus.RegistrosModbus[894*2]))       //     (*((vol float *) &MapaModbus.RegistrosModbus[196*2]))
#define  ConsumoPontaEsteMesAteAgora		(*((vol float *) &MapaModbus.RegistrosModbus[896*2]))   //     (*((vol float *) &MapaModbus.RegistrosModbus[198*2]))
#define  ConsumoForaPontaEsteMesAteAgora	(*((vol float *) &MapaModbus.RegistrosModbus[898*2]))  //     (*((vol float *) &MapaModbus.RegistrosModbus[200*2]))
#define  ConsumoReservEsteMesAteAgora 	 	(*((vol float *) &MapaModbus.RegistrosModbus[900*2]))      //     (*((vol float *) &MapaModbus.RegistrosModbus[202*2]))
#define  EnergIndPontaEsteMesAteAgora		(*((vol float *) &MapaModbus.RegistrosModbus[902*2]))  //     (*((vol float *) &MapaModbus.RegistrosModbus[204*2]))
#define  EnergIndForaPontaEsteMesAteAgora	(*((vol float *) &MapaModbus.RegistrosModbus[904*2]))  //     (*((vol float *) &MapaModbus.RegistrosModbus[206*2]))
#define  EnergIndReservEsteMesAteAgora 	 	(*((vol float *) &MapaModbus.RegistrosModbus[906*2]))	    //    (*((vol float *) &MapaModbus.RegistrosModbus[208*2]))
#define  EnergCapPontaEsteMesAteAgora		(*((vol float *) &MapaModbus.RegistrosModbus[908*2]))	//    (*((vol float *) &MapaModbus.RegistrosModbus[210*2]))
#define  EnergCapForaPontaEsteMesAteAgora	(*((vol float *) &MapaModbus.RegistrosModbus[910*2]))	//    (*((vol float *) &MapaModbus.RegistrosModbus[212*2]))
#define  EnergCapReservEsteMesAteAgora 	 	(*((vol float *) &MapaModbus.RegistrosModbus[912*2]))	    //    (*((vol float *) &MapaModbus.RegistrosModbus[214*2]))
#define  MaxPotAtivPontaEsteMesAteAgora	 	(*((vol float *) &MapaModbus.RegistrosModbus[914*2]))	    //    (*((vol float *) &MapaModbus.RegistrosModbus[216*2]))
#define  MaxPotAtivForaPontaEsteMesAteAgora	(*((vol float *) &MapaModbus.RegistrosModbus[916*2]))	//        (*((vol float *) &MapaModbus.RegistrosModbus[218*2]))
#define  MaxPotAtivReservEsteMesAteAgora	(*((vol float *) &MapaModbus.RegistrosModbus[918*2]))	//    (*((vol float *) &MapaModbus.RegistrosModbus[220*2]))
#define  MaxPotReatPontaEsteMesAteAgora	 	(*((vol float *) &MapaModbus.RegistrosModbus[920*2]))	    //    (*((vol float *) &MapaModbus.RegistrosModbus[222*2]))
#define  MaxPotReatForaPontaEsteMesAteAgora	(*((vol float *) &MapaModbus.RegistrosModbus[922*2]))	//        (*((vol float *) &MapaModbus.RegistrosModbus[224*2]))
#define  MaxPotReatReservEsteMesAteAgora	(*((vol float *) &MapaModbus.RegistrosModbus[924*2]))	//    (*((vol float *) &MapaModbus.RegistrosModbus[226*2]))
#define  EnergGerPontaHojeAteAgora		 	(*((vol float *) &MapaModbus.RegistrosModbus[926*2]))      //     (*((vol float *) &MapaModbus.RegistrosModbus[228*2]))
#define  EnergGerForaPontaHojeAteAgora	 	(*((vol float *) &MapaModbus.RegistrosModbus[928*2]))      //     (*((vol float *) &MapaModbus.RegistrosModbus[230*2]))
#define  EnergGerReservHojeAteAgora 		(*((vol float *) &MapaModbus.RegistrosModbus[930*2]))	//    (*((vol float *) &MapaModbus.RegistrosModbus[232*2]))
#define  ConsumoPontaHojeAteAgora			(*((vol float *) &MapaModbus.RegistrosModbus[932*2]))	//    (*((vol float *) &MapaModbus.RegistrosModbus[234*2]))
#define  ConsumoForaPontaHojeAteAgora 	 	(*((vol float *) &MapaModbus.RegistrosModbus[934*2]))	    //    (*((vol float *) &MapaModbus.RegistrosModbus[236*2]))
#define  ConsumoReservHojeAteAgora 		 	(*((vol float *) &MapaModbus.RegistrosModbus[936*2]))	    //    (*((vol float *) &MapaModbus.RegistrosModbus[238*2]))
#define  EnergIndPontaHojeAteAgora		 	(*((vol float *) &MapaModbus.RegistrosModbus[938*2]))	    //    (*((vol float *) &MapaModbus.RegistrosModbus[240*2]))
#define  EnergIndForaPontaHojeAteAgora	 	(*((vol float *) &MapaModbus.RegistrosModbus[940*2]))	    //    (*((vol float *) &MapaModbus.RegistrosModbus[242*2]))
#define  EnergIndReservHojeAteAgora 	    (*((vol float *) &MapaModbus.RegistrosModbus[942*2]))	//    (*((vol float *) &MapaModbus.RegistrosModbus[244*2]))


#define PotAtivPonta15min		 (*((vol float *) &MapaModbus.RegistrosModbus[944*2]))	   //	   	__at(1073750592 );//registro MODBUS: 288-289
#define PotAtivForaPonta15min 	 (*((vol float *) &MapaModbus.RegistrosModbus[946*2]))	   //	__at(1073750596 );//registro MODBUS: 290-291
#define PotAtivReserv15min 	 	 (*((vol float *) &MapaModbus.RegistrosModbus[948*2]))	   //	__at(1073750600 );//registro MODBUS: 292-293
#define PotReatPonta15min		 (*((vol float *) &MapaModbus.RegistrosModbus[950*2]))	   	//   	__at(1073750604 );//registro MODBUS: 294-295
#define PotReatForaPonta15min	 (*((vol float *) &MapaModbus.RegistrosModbus[952*2]))	   //	   	__at(1073750608 );//registro MODBUS: 296-297
#define PotReatReserv15min 		 (*((vol float *) &MapaModbus.RegistrosModbus[954*2]))	  // 	__at(1073750612 );//registro MODBUS: 298-299*/

#endif



#define  EnergCapPontaHojeAteAgora			        (*((vol float *) &MapaModbus.RegistrosModbus[246*2]))
#define  EnergCapForaPontaHojeAteAgora		        (*((vol float *) &MapaModbus.RegistrosModbus[248*2]))
#define  EnergCapReservHojeAteAgora 			    (*((vol float *) &MapaModbus.RegistrosModbus[250*2]))
#define  MaxPotAtivPontaHojeAteAgora			    (*((vol float *) &MapaModbus.RegistrosModbus[252*2]))
#define  MaxPotAtivForaPontaHojeAteAgora		    (*((vol float *) &MapaModbus.RegistrosModbus[254*2]))
#define  MaxPotAtivReservHojeAteAgora 		        (*((vol float *) &MapaModbus.RegistrosModbus[256*2]))
#define  MaxPotReatPontaHojeAteAgora			    (*((vol float *) &MapaModbus.RegistrosModbus[258*2]))
#define  MaxPotReatForaPontaHojeAteAgora		    (*((vol float *) &MapaModbus.RegistrosModbus[260*2]))
#define  MaxPotReatReservHojeAteAgora			    (*((vol float *) &MapaModbus.RegistrosModbus[262*2]))
#define  EnergGerPonta15min				   	        (*((vol float *) &MapaModbus.RegistrosModbus[264*2]))
#define  EnergGerForaPonta15min			   	        (*((vol float *) &MapaModbus.RegistrosModbus[266*2]))
#define  EnergGerReserv15min 		 	   		    (*((vol float *) &MapaModbus.RegistrosModbus[268*2]))
#define  ConsumoPonta15min 		 	   		        (*((vol float *) &MapaModbus.RegistrosModbus[270*2]))
#define  ConsumoForaPonta15min	 	   		        (*((vol float *) &MapaModbus.RegistrosModbus[272*2]))
#define  ConsumoReserv15min 		 	   		    (*((vol float *) &MapaModbus.RegistrosModbus[274*2]))
#define  EnergIndPonta15min					        (*((vol float *) &MapaModbus.RegistrosModbus[276*2]))
#define  EnergIndForaPonta15min	 	 		        (*((vol float *) &MapaModbus.RegistrosModbus[278*2]))
#define  EnergIndReserv15min 		 			    (*((vol float *) &MapaModbus.RegistrosModbus[280*2]))
#define  EnergCapPonta15min		 			        (*((vol float *) &MapaModbus.RegistrosModbus[282*2]))
#define  EnergCapForaPonta15min	 			        (*((vol float *) &MapaModbus.RegistrosModbus[284*2]))
#define  EnergCapReserv15min 		 			    (*((vol float *) &MapaModbus.RegistrosModbus[286*2]))

#if EQUIP==CM_EQUIP

  #define PotAtivPonta15min		        (*((vol float *) &MapaModbus.RegistrosModbus[288*2]))
  #define PotAtivForaPonta15min 	    (*((vol float *) &MapaModbus.RegistrosModbus[290*2]))
  #define PotAtivReserv15min 	 	    (*((vol float *) &MapaModbus.RegistrosModbus[292*2]))
  #define PotReatPonta15min		        (*((vol float *) &MapaModbus.RegistrosModbus[294*2]))
  #define PotReatForaPonta15min	        (*((vol float *) &MapaModbus.RegistrosModbus[296*2]))
  #define PotReatReserv15min 		    (*((vol float *) &MapaModbus.RegistrosModbus[298*2]))

#else



  #define  ConstanteUsuario1		 			(*((vol float *) &MapaModbus.RegistrosModbus[288*2]))
  #define  ConstanteUsuario2 		 			(*((vol float *) &MapaModbus.RegistrosModbus[290*2]))
  #define  ConstanteUsuario3 		 			(*((vol float *) &MapaModbus.RegistrosModbus[292*2]))
  #define  ConstanteUsuario4		 			(*((vol float *) &MapaModbus.RegistrosModbus[294*2]))
  #define  ConstanteUsuario5		 			(*((vol float *) &MapaModbus.RegistrosModbus[296*2]))
  #define  ConstanteUsuario6 		 			(*((vol float *) &MapaModbus.RegistrosModbus[298*2]))

#endif

#define  EnergGerPonta		 			(*((vol float *) &MapaModbus.RegistrosModbus[300*2]))
#define  EnergGerForaPonta				(*((vol float *) &MapaModbus.RegistrosModbus[302*2]))
#define  EnergGerReserv 		 		(*((vol float *) &MapaModbus.RegistrosModbus[304*2]))
#define  ConsumoPonta 		 			(*((vol float *) &MapaModbus.RegistrosModbus[306*2]))
#define  ConsumoForaPonta	 			(*((vol float *) &MapaModbus.RegistrosModbus[308*2]))
#define  ConsumoReserv 	    			(*((vol float *) &MapaModbus.RegistrosModbus[310*2]))
#define  EnergIndPonta	    		    (*((vol float *) &MapaModbus.RegistrosModbus[312*2]))
#define  EnergIndForaPonta    		    (*((vol float *) &MapaModbus.RegistrosModbus[314*2]))
#define  EnergIndReserv 	    		(*((vol float *) &MapaModbus.RegistrosModbus[316*2]))
#define  EnergCapPonta	        		(*((vol float *) &MapaModbus.RegistrosModbus[318*2]))
#define  EnergCapForaPonta        	    (*((vol float *) &MapaModbus.RegistrosModbus[320*2]))
#define  EnergCapReserv 	    		(*((vol float *) &MapaModbus.RegistrosModbus[322*2]))
#define  MaxPotAtivPonta				(*((vol float *) &MapaModbus.RegistrosModbus[324*2]))
#define  MaxPotAtivForaPonta			(*((vol float *) &MapaModbus.RegistrosModbus[326*2]))
#define  MaxPotAtivReserv 				(*((vol float *) &MapaModbus.RegistrosModbus[328*2]))
#define  MaxPotReatPonta				(*((vol float *) &MapaModbus.RegistrosModbus[330*2]))
#define  MaxPotReatForaPonta			(*((vol float *) &MapaModbus.RegistrosModbus[332*2]))
#define  MaxPotReatReserv 				(*((vol float *) &MapaModbus.RegistrosModbus[334*2]))
#define  EnergGerPonta15minAcc			(*((vol float *) &MapaModbus.RegistrosModbus[336*2]))
#define  EnergGerForaPonta15minAcc		(*((vol float *) &MapaModbus.RegistrosModbus[338*2]))
#define  EnergGerReserv15minAcc 		(*((vol float *) &MapaModbus.RegistrosModbus[340*2]))
#define  ConsumoPonta15minAcc 			(*((vol float *) &MapaModbus.RegistrosModbus[342*2]))
#define  ConsumoForaPonta15minAcc	 	(*((vol float *) &MapaModbus.RegistrosModbus[344*2]))
#define  ConsumoReserv15minAcc			(*((vol float *) &MapaModbus.RegistrosModbus[346*2]))
#define  EnergIndPonta15minAcc			(*((vol float *) &MapaModbus.RegistrosModbus[348*2]))
#define  EnergIndForaPonta15minAcc		(*((vol float *) &MapaModbus.RegistrosModbus[350*2]))
#define  EnergIndReserv15minAcc 		(*((vol float *) &MapaModbus.RegistrosModbus[352*2]))
#define  EnergCapPonta15minAcc			(*((vol float *) &MapaModbus.RegistrosModbus[354*2]))
#define  EnergCapForaPonta15minAcc		(*((vol float *) &MapaModbus.RegistrosModbus[356*2]))
#define  EnergCapReserv15minAcc 		(*((vol float *) &MapaModbus.RegistrosModbus[358*2]))
#define  PotAtivPonta15minAcc			(*((vol float *) &MapaModbus.RegistrosModbus[360*2]))
#define  PotAtivForaPonta15minAcc		(*((vol float *) &MapaModbus.RegistrosModbus[362*2]))
#define  PotAtivReserv15minAcc			(*((vol float *) &MapaModbus.RegistrosModbus[364*2]))
#define  PotReatPonta15minAcc			(*((vol float *) &MapaModbus.RegistrosModbus[366*2]))
#define  PotReatForaPonta15minAcc		(*((vol float *) &MapaModbus.RegistrosModbus[368*2]))
#define  PotReatReserv15minAcc 			(*((vol float *) &MapaModbus.RegistrosModbus[370*2]))

#if EQUIP==CM_EQUIP
//relativos somente ao CM4040
#define Q_controlador   (*((vol float *) &MapaModbus.RegistrosModbus[854*2]))
#define estagio1 		(*((vol float *) &MapaModbus.RegistrosModbus[856*2]))
#define estagio2 		(*((vol float *) &MapaModbus.RegistrosModbus[858*2]))
#define estagio3 		(*((vol float *) &MapaModbus.RegistrosModbus[860*2]))
#define estagio4 		(*((vol float *) &MapaModbus.RegistrosModbus[862*2]))
#define estagio5 		(*((vol float *) &MapaModbus.RegistrosModbus[864*2]))
#define estagio6 		(*((vol float *) &MapaModbus.RegistrosModbus[866*2]))
#define estagio7 		(*((vol float *) &MapaModbus.RegistrosModbus[868*2]))
#define estagio8 		(*((vol float *) &MapaModbus.RegistrosModbus[870*2]))
#define estagio9 		(*((vol float *) &MapaModbus.RegistrosModbus[872*2]))
#define estagio10 		(*((vol float *) &MapaModbus.RegistrosModbus[874*2]))
#define estagio11 		(*((vol float *) &MapaModbus.RegistrosModbus[876*2]))
#define estagio12 		(*((vol float *) &MapaModbus.RegistrosModbus[878*2]))
#define CF_inf 			(*((vol float *) &MapaModbus.RegistrosModbus[880*2]))
#define CF_sup 			(*((vol float *) &MapaModbus.RegistrosModbus[882*2]))
#define CF_al_inf 		(*((vol float *) &MapaModbus.RegistrosModbus[884*2]))
#define CF_al_sup 		(*((vol float *) &MapaModbus.RegistrosModbus[886*2]))
#define Td 				(*((vol float *) &MapaModbus.RegistrosModbus[888*2]))
#define Talarme 		(*((vol float *) &MapaModbus.RegistrosModbus[890*2]))
#define Vlim_inf 		(*((vol float *) &MapaModbus.RegistrosModbus[892*2]))
#define Vlim_sup 		(*((vol float *) &MapaModbus.RegistrosModbus[894*2]))
#define DHTVlim 		(*((vol float *) &MapaModbus.RegistrosModbus[896*2]))

#define StatusDosReles		(*((vol short *) &MapaModbus.RegistrosModbus[898*2]))

/* somente leitura
   x  x  x  x - 1FF(12 reles)
   |  |  |	 |
   |  |  |	 |
   |  |  |	 |_________________________Alarme DHTv
   |  |  |____________________________Alarme I
   |_______________________________Alarme V
   |__________________________________Alarme fp
 */
#define ParametrizacaoCM		(*((vol short *) &MapaModbus.RegistrosModbus[899*2]))

/*
									11 10  9 8	7  6  5  4	3  2  1	 0
									x  x  x	 x  x  x  x  x  x  x  x  x
									|  |  |	 |  |  |  |  |  |  |  |  |
									|  |  |	 |  |  |  |  |  |  |  |  |_BloQCapativo    			 (ON,OFF)
									|  |  |	 |  |  |  |  | 	|  |  |____ModoAcionaTodos 			 (ON,OFF)
									|  |  |	 |  |  |  |  | 	|  |_______Alarme Falta Corrente 	 (ON,OFF)
									|  |  |	 |  |  |  |  | 	|__________Modo Al. Corrente, Desliga(ON,OFF)
									|  |  |	 |  |  |  |  |_____________Alarme Falta Corrente 	 (ON,OFF)
									|  |  |	 |  |  |  |________________Modo Al. Corrente, Desliga(ON,OFF)
									|  |  |	 |  |  |___________________Alarme Falta Tens�o  	 (ON,OFF)
									|  |  |	 |  |______________________Modo Al. Tens�o,Desliga   (ON,OFF)
									|  |  |	 |_________________________Alarme DHTv			  	 (ON,OFF)
									|  |  |____________________________Modo Al. DHTv,Desliga	 (ON,OFF)
									|  |_______________________________Tipo de Ligacao LSB
									|__________________________________Tipo de Ligacao MSB
 */


#endif

//aten��o abaixo � defini��o de vetores
#define  feriados    			   (((vol short * ) &MapaModbus.RegistrosModbus[42*2]))

#define Lista1DeMaxPotAtivPontaNesteMesAteAgora            			   (((vol float * ) &MapaModbus.RegistrosModbus[ 372*2]))
#define Lista2DeMaxPotAtivForaPontaNesteMesAteAgora        			   (((vol float * ) &MapaModbus.RegistrosModbus[ 380*2]))
#define Lista3DeMaxPotAtivReservNesteMesAteAgora	   	     		   (((vol float * ) &MapaModbus.RegistrosModbus[ 388*2]))
#define Lista4DeMaxPotReatPontaNesteMesAteAgora            			   (((vol float * ) &MapaModbus.RegistrosModbus[ 396*2]))
#define Lista5DeMaxPotReatForaPontaNesteMesAteAgora        			   (((vol float * ) &MapaModbus.RegistrosModbus[ 404*2]))
#define Lista6DeMaxPotReatReservNesteMesAteAgora	   	     		   (((vol float * ) &MapaModbus.RegistrosModbus[ 412*2]))
#define Lista7DeMaxPotAtivPontaMesPassado      	 	     			   (((vol float * ) &MapaModbus.RegistrosModbus[ 420*2]))
#define Lista8DeMaxPotAtivForaPontaMesPassado   		     		   (((vol float * ) &MapaModbus.RegistrosModbus[ 428*2]))
#define Lista9DeMaxPotAtivReservMesPassado	   		     			   (((vol float * ) &MapaModbus.RegistrosModbus[ 436*2]))
#define Lista10DeMaxPotReatPontaMesPassado       		     		   (((vol float * ) &MapaModbus.RegistrosModbus[ 444*2]))
#define Lista11DeMaxPotReatForaPontaMesPassado   		     		   (((vol float * ) &MapaModbus.RegistrosModbus[ 452*2]))
#define Lista12DeMaxPotReatReservMesPassado	   		     			   (((vol float * ) &MapaModbus.RegistrosModbus[ 460*2]))

#define  MesDiaLista1                              (((vol short *)&MapaModbus.RegistrosModbus[468*2]))
#define  HoraMinLista1                             (((vol short *)&MapaModbus.RegistrosModbus[472*2]))
#define  MesDiaLista2			     			   (((vol short *)&MapaModbus.RegistrosModbus[476*2]))
#define  HoraMinLista2			     			   (((vol short *)&MapaModbus.RegistrosModbus[480*2]))
#define  MesDiaLista3			     			   (((vol short *)&MapaModbus.RegistrosModbus[484*2]))
#define  HoraMinLista3			     			   (((vol short *)&MapaModbus.RegistrosModbus[488*2]))
#define  MesDiaLista4			     			   (((vol short *)&MapaModbus.RegistrosModbus[492*2]))
#define  HoraMinLista4			     			   (((vol short *)&MapaModbus.RegistrosModbus[496*2]))
#define  MesDiaLista5			     			   (((vol short *)&MapaModbus.RegistrosModbus[500*2]))
#define  HoraMinLista5			     			   (((vol short * ) &MapaModbus.RegistrosModbus[504*2]))
#define  MesDiaLista6			     			   (((vol short * ) &MapaModbus.RegistrosModbus[508*2]))
#define  HoraMinLista6			     			   (((vol short * ) &MapaModbus.RegistrosModbus[512*2]))
#define  MesDiaLista7			     			   (((vol short * ) &MapaModbus.RegistrosModbus[516*2]))
#define  HoraMinLista7			     			   (((vol short * ) &MapaModbus.RegistrosModbus[520*2]))
#define  MesDiaLista8			     			   (((vol short * ) &MapaModbus.RegistrosModbus[524*2]))
#define  HoraMinLista8			     			   (((vol short * ) &MapaModbus.RegistrosModbus[528*2]))
#define  MesDiaLista9			     			   (((vol short * ) &MapaModbus.RegistrosModbus[532*2]))
#define  HoraMinLista9			     			   (((vol short * ) &MapaModbus.RegistrosModbus[536*2]))
#define  MesDiaLista10			     			   (((vol short * ) &MapaModbus.RegistrosModbus[540*2]))
#define  HoraMinLista10		     			       (((vol short * ) &MapaModbus.RegistrosModbus[544*2]))
#define  MesDiaLista11			     			   (((vol short * ) &MapaModbus.RegistrosModbus[548*2]))
#define  HoraMinLista11		     			       (((vol short * ) &MapaModbus.RegistrosModbus[552*2]))
#define  MesDiaLista12			     			   (((vol short * ) &MapaModbus.RegistrosModbus[556*2]))
#define  HoraMinLista12		     			       (((vol short * ) &MapaModbus.RegistrosModbus[560*2]))

#define  DiaHoraParaMedAutomatica	     		  (*((vol short * ) &MapaModbus.RegistrosModbus[564*2]))
#define  StatusDeTodosOsReles		      		  (*((vol short * ) &MapaModbus.RegistrosModbus[565*2]))

/*
//EXT short MesDiaLista1  [4];
EXT short HoraMinLista1 [4];
EXT short MesDiaLista2	[4];
EXT short HoraMinLista2	[4];
EXT short MesDiaLista3	[4];
EXT short HoraMinLista3	[4];
EXT short MesDiaLista4	[4];
EXT short HoraMinLista4	 [4];
EXT short MesDiaLista5	 [4];
EXT short HoraMinLista5	[4];
EXT short MesDiaLista6		[4];
EXT short HoraMinLista6	[4];
EXT short MesDiaLista7		[4];
EXT short HoraMinLista7	[4];
EXT short MesDiaLista8	 [4];
EXT short HoraMinLista8	 [4];
EXT short MesDiaLista9	[4];
EXT short HoraMinLista9		[4];
EXT short MesDiaLista10	[4];
EXT short HoraMinLista10	[4];
EXT short MesDiaLista11	[4];
EXT short HoraMinLista11	[4];
EXT short MesDiaLista12	[4];
EXT short HoraMinLista12	[4];*/

//////////relacionados a controle de rel�s///////////
#if  EQUIP!=CM_EQUIP
    #define    Rele1_	      		  (*((vol RelesStruct * ) &MapaModbus.RegistrosModbus[566*2]))
    #define    Rele2_	      		  (*((vol RelesStruct * ) &MapaModbus.RegistrosModbus[582*2]))
    #define    Rele3_	      		  (*((vol RelesStruct * ) &MapaModbus.RegistrosModbus[574*2]))
#else
    #define    HorarioSemAtuarInicio      		  (*((vol short * ) &MapaModbus.RegistrosModbus[566*2]))
    #define    HorarioSemAtuarFim	      		  (*((vol short * ) &MapaModbus.RegistrosModbus[567*2]))
#endif
///////////relacionados � 'memoria de massa' MM	 //////////

//grandezas integradas
#define MMUa		    	 (*((vol float *) &MapaModbus.RegistrosModbus[590*2]))
#define MMUb		    	 (*((vol float *) &MapaModbus.RegistrosModbus[592*2]))
#define MMUc		    	 (*((vol float *)  &MapaModbus.RegistrosModbus[594*2]))
#define MMIa		    	 (*((vol float *)  &MapaModbus.RegistrosModbus[596*2]))
#define MMIb          	     (*((vol float *)  &MapaModbus.RegistrosModbus[598*2]))
#define MMIc          	     (*((vol float *) &MapaModbus.RegistrosModbus[600*2]))
#define MMDemP	    	     (*((vol float *) &MapaModbus.RegistrosModbus[602*2]))
#define MMDemQ        	     (*((vol float *)  &MapaModbus.RegistrosModbus[604*2]))
#define MMFp  	    	     (*((vol float *)  &MapaModbus.RegistrosModbus[606*2]))
#define tMMgrandezas         (*((vol short *) &MapaModbus.RegistrosModbus[608*2]))


#define ip_config    (*((vol LOCALM * ) &MapaModbus.RegistrosModbus[609*2]))
#define NroPorta2    (*((vol short * ) &MapaModbus.RegistrosModbus[619*2]))
#define dev_name     (((vol U8 * ) &MapaModbus.RegistrosModbus[620*2]))

#define meuMAC             (*((vol short *) &MapaModbus.RegistrosModbus[628*2]))
#define ultima_variavel      (*((vol U16 * ) &MapaModbus.RegistrosModbus[629*2]))



//U8 srv_ip[4];



#define UrmsAB     	     (*((vol float *) &MapaModbus.RegistrosModbus[630*2]))
#define UrmsBC   	     (*((vol float *) &MapaModbus.RegistrosModbus[632*2]))
#define UrmsCA     	     (*((vol float *) &MapaModbus.RegistrosModbus[634*2]))
//#if  EQUIP!=CM_EQUIP

#if ((EQUIP_LINHA50== CP_EQUIP) || (EQUIP_LINHA50== CD_EQUIP))
    #define pulso_cp_1   	        (*((vol float * ) &MapaModbus.RegistrosModbus[636*2]))
    #define pulso_cp_2      	    (*((vol float * ) &MapaModbus.RegistrosModbus[638*2]))
    #define MMFp_copy	    	(*((vol float * ) &MapaModbus.RegistrosModbus[640*2]))
    #define pulso_cp_3   	        (*((vol float * ) &MapaModbus.RegistrosModbus[642*2]))
    #define pulso_cp_4     	    (*((vol float * ) &MapaModbus.RegistrosModbus[644*2]))
	#define pulso_cp_5     	    (*((vol float * ) &MapaModbus.RegistrosModbus[646*2]))
	#define pulso_cp_6     	    (*((vol float * ) &MapaModbus.RegistrosModbus[648*2]))
#else
	#define pulso_cp_1    	         (*((vol float * ) &MapaModbus.RegistrosModbus[636*2]))
	#define pulso_cp_2      	     (*((vol float * ) &MapaModbus.RegistrosModbus[638*2]))
	#define MMFp_copy	    	 (*((vol float * ) &MapaModbus.RegistrosModbus[640*2]))

#endif


///#endif
//EnergGerA  0x400020f8	 ==> 400024EA deve3 ser o �ltimo endereco!




#define  FatorCalibUa			(*((vol float *) &MapaModbus.RegistrosModbus[ 656*2]))
#define  FatorCalibUb			(*((vol float *) &MapaModbus.RegistrosModbus[ 658*2]))
#define  FatorCalibUc 		    (*((vol float *) &MapaModbus.RegistrosModbus[ 660*2]))
#define  FatorCalibIa			(*((vol float *) &MapaModbus.RegistrosModbus[ 662*2]))
#define  FatorCalibIb			(*((vol float *) &MapaModbus.RegistrosModbus[ 664*2]))
#define  FatorCalibIc 		 	(*((vol float *) &MapaModbus.RegistrosModbus[ 666*2]))
#define  FatorCalibUa_		 	(*((vol float *) &MapaModbus.RegistrosModbus[ 668*2]))
#define  FatorCalibUb_		 	(*((vol float *) &MapaModbus.RegistrosModbus[ 670*2]))
#define  FatorCalibUc_		 	(*((vol float *) &MapaModbus.RegistrosModbus[ 672*2]))
#define  FatorCalibIa_		 	(*((vol float *) &MapaModbus.RegistrosModbus[ 674*2]))
#define  FatorCalibIb_		 	(*((vol float *) &MapaModbus.RegistrosModbus[ 676*2]))
#define  FatorCalibIc_ 		 	(*((vol float *) &MapaModbus.RegistrosModbus[ 678*2]))
#define  FatorCalibFreq  		(*((vol float *) &MapaModbus.RegistrosModbus[ 680*2]))




#define nivelDCUa   	(*((vol short *) &MapaModbus.RegistrosModbus[ 682*2]))
#define nivelDCUb   	(*((vol short *) &MapaModbus.RegistrosModbus[ 683*2]))
#define nivelDCUc   	(*((vol short *) &MapaModbus.RegistrosModbus[ 684*2]))
#define nivelDCIa   	(*((vol short *) &MapaModbus.RegistrosModbus[ 685*2]))
#define nivelDCIb   	(*((vol short *) &MapaModbus.RegistrosModbus[ 686*2]))
#define nivelDCIc   	(*((vol short *) &MapaModbus.RegistrosModbus[ 687*2]))
#define polinomioUA  	(((vol float *) &MapaModbus.RegistrosModbus[ 688*2]))
#define polinomioUB  	(((vol float *) &MapaModbus.RegistrosModbus[ 696*2]))
#define polinomioUC  	(((vol float *) &MapaModbus.RegistrosModbus[ 704*2]))
#define polinomioIA  	(((vol float *) &MapaModbus.RegistrosModbus[ 712*2]))
#define polinomioIB  	(((vol float *) &MapaModbus.RegistrosModbus[ 728*2]))
#define polinomioIC  	(((vol float *) &MapaModbus.RegistrosModbus[ 744*2]))
//#define  TpAlote	    (*((vol float *) &MapaModbus.RegistrosModbus[ 760*2]))
//#define  TpBlote 	    (*((vol float *) &MapaModbus.RegistrosModbus[ 762*2]))
//#define  TpClote 	    (*((vol float *) &MapaModbus.RegistrosModbus[ 764*2]))
//#define  TcAlote 	    (*((vol float *) &MapaModbus.RegistrosModbus[ 766*2]))
#define  TcBlote 	    (*((vol float *) &MapaModbus.RegistrosModbus[ 768*2]))
#define  TcClote 	    (*((vol float *) &MapaModbus.RegistrosModbus[ 770*2]))


#define TemperaturaCoefA_ch0 	           *((vol float *) &MapaModbus.RegistrosModbus[ 760*2])
#define TemperaturaCoefB_ch0	           *((vol float *) &MapaModbus.RegistrosModbus[ 762*2])
#define TemperaturaCoefA_ch1	           *((vol float *) &MapaModbus.RegistrosModbus[ 764*2])
#define TemperaturaCoefB_ch1 	           *((vol float *) &MapaModbus.RegistrosModbus[ 766*2])



#define nserie_str 	    ( ((vol U8 *) &MapaModbus.RegistrosModbus[ 772*2]))

#define polMa		    (* ((vol U8 *) &MapaModbus.RegistrosModbus[1552]))
#define polMb		    (* ((vol U8 *) &MapaModbus.RegistrosModbus[1553]))
#define polMc		    (* ((vol U8 *) &MapaModbus.RegistrosModbus[1554]))





#define  UrmsAforCalib			    (*((vol float *) &MapaModbus.RegistrosModbus[778*2]))
#define  UrmsBforCalib			    (*((vol float *) &MapaModbus.RegistrosModbus[780*2 ]))
#define  UrmsCforCalib			    (*((vol float *) &MapaModbus.RegistrosModbus[782*2 ]))
#define  IrmsAforCalib			    (*((vol float *) &MapaModbus.RegistrosModbus[784*2 ]))
#define  IrmsBforCalib			    (*((vol float *) &MapaModbus.RegistrosModbus[786*2 ]))
#define  IrmsCforCalib			    (*((vol float *) &MapaModbus.RegistrosModbus[788*2 ]))

//#define  DhtUAforCalib			    (*((vol float *) &MapaModbus.RegistrosModbus[790*2 ]))
//#define  DhtUBforCalib			    (*((vol float *) &MapaModbus.RegistrosModbus[792*2 ]))
//#define  DhtUCforCalib			    (*((vol float *) &MapaModbus.RegistrosModbus[794*2 ]))
//#define  DhtIAforCalib			    (*((vol float *) &MapaModbus.RegistrosModbus[796*2 ]))

#define  TemperaturaCoefA_ch0forCalib			    (*((vol float *) &MapaModbus.RegistrosModbus[790*2 ]))
#define  TemperaturaCoefB_ch0forCalib			    (*((vol float *) &MapaModbus.RegistrosModbus[792*2 ]))
#define  TemperaturaCoefA_ch1forCalib			    (*((vol float *) &MapaModbus.RegistrosModbus[794*2 ]))
#define  TemperaturaCoefB_ch1forCalib			    (*((vol float *) &MapaModbus.RegistrosModbus[796*2 ]))

#define  DhtIBforCalib			    (*((vol float *) &MapaModbus.RegistrosModbus[798*2 ]))
#define  DhtICforCalib			    (*((vol float *) &MapaModbus.RegistrosModbus[800*2 ]))
#define  AnguloAforCalib			(*((vol float *) &MapaModbus.RegistrosModbus[802*2 ]))
#define  AnguloBforCalib			(*((vol float *) &MapaModbus.RegistrosModbus[804*2 ]))
#define  AnguloCforCalib			(*((vol float *) &MapaModbus.RegistrosModbus[806*2 ]))
#define  IndiceDeModulo_IA		    (*((vol short *)  &MapaModbus.RegistrosModbus[808*2 ]))
#define  IndiceDeModulo_IB		    (*((vol short *)  &MapaModbus.RegistrosModbus[809*2 ]))
#define  IndiceDeModulo_IC		    (*((vol short *)  &MapaModbus.RegistrosModbus[810*2 ]))


#define  EtapaDeCalibracao	 	    (*((vol short *) &MapaModbus.RegistrosModbus[811*2 ]))




//SSS  BYTE Reservado3 __at (1073751713);
#define    MeuEnderecoMODBUS 		  	 		(*((vol uint8_t *)     &MapaModbus.RegistrosModbus[1698]))
#define    EquipamentoCalibrado 	 	 		(*((vol uint8_t *)     &MapaModbus.RegistrosModbus[1699]))
#define    EquipamentoParametrizado 	 		(*((vol uint8_t *)     &MapaModbus.RegistrosModbus[1700]))
#define    BaudRatex 				  	 		(*((vol uint8_t *)     &MapaModbus.RegistrosModbus[1701]))
#define    ParidadeStops 			  	 		(*((vol uint8_t *)     &MapaModbus.RegistrosModbus[1702]))
#define    ModBusLiberado 		  	 		    (*((vol uint8_t *)     &MapaModbus.RegistrosModbus[1703]))

#define  IPOcteto1		    (*((vol uint8_t *)     &MapaModbus.RegistrosModbus[1684]))
#define  IPOcteto2		    (*((vol uint8_t *)     &MapaModbus.RegistrosModbus[1685]))
#define  IPOcteto3		    (*((vol uint8_t *)     &MapaModbus.RegistrosModbus[1686]))
#define  IPOcteto4		    (*((vol uint8_t *)     &MapaModbus.RegistrosModbus[1687]))
#define  MKOcteto1		    (*((vol uint8_t *)     &MapaModbus.RegistrosModbus[1688]))
#define  MKOcteto2		    (*((vol uint8_t *)     &MapaModbus.RegistrosModbus[1689]))
#define  MKOcteto3		    (*((vol uint8_t *)     &MapaModbus.RegistrosModbus[1690]))
#define  MKOcteto4	  		(*((vol uint8_t *)     &MapaModbus.RegistrosModbus[1691]))
#define  GWOcteto1	  		(*((vol uint8_t *)     &MapaModbus.RegistrosModbus[1692]))
#define  GWOcteto2	  		(*((vol uint8_t *)     &MapaModbus.RegistrosModbus[1693]))
#define  GWOcteto3	  		(*((vol uint8_t *)     &MapaModbus.RegistrosModbus[1694]))
#define  GWOcteto4	        (*((vol uint8_t *)     &MapaModbus.RegistrosModbus[1695]))
#define  NroPorta           (*((vol short *)       &MapaModbus.RegistrosModbus[1696]))




#if  EQUIP!=CM_EQUIP

#define hora_segunda1 		(*((vol uint8_t *)     &MapaModbus.RegistrosModbus[1705]))
#define min_segunda1 		(*((vol uint8_t *)     &MapaModbus.RegistrosModbus[1704]))
#define hora_segunda2 		(*((vol uint8_t *)     &MapaModbus.RegistrosModbus[1707]))
#define min_segunda2 		(*((vol uint8_t *)     &MapaModbus.RegistrosModbus[1706]))
#define hora_segunda3 		(*((vol uint8_t *)     &MapaModbus.RegistrosModbus[1709]))
#define min_segunda3 		(*((vol uint8_t *)     &MapaModbus.RegistrosModbus[1708]))
#define hora_segunda4 		(*((vol uint8_t *)     &MapaModbus.RegistrosModbus[1711]))
#define min_segunda4 		(*((vol uint8_t *)     &MapaModbus.RegistrosModbus[1710]))
#define hora_terca1 		(*((vol uint8_t *) 	   &MapaModbus.RegistrosModbus[1713]))
#define min_terca1 		 	(*((vol uint8_t *)     &MapaModbus.RegistrosModbus[1712]))
#define hora_terca2 		(*((vol uint8_t *) 	   &MapaModbus.RegistrosModbus[1715]))
#define min_terca2 		 	(*((vol uint8_t *)     &MapaModbus.RegistrosModbus[1714]))
#define hora_terca3 		(*((vol uint8_t *) 	   &MapaModbus.RegistrosModbus[1717]))
#define min_terca3 		 	(*((vol uint8_t *)     &MapaModbus.RegistrosModbus[1716]))
#define hora_terca4 		(*((vol uint8_t *) 	   &MapaModbus.RegistrosModbus[1719]))
#define min_terca4 		 	(*((vol uint8_t *)     &MapaModbus.RegistrosModbus[1718]))
#define hora_quarta1 		(*((vol uint8_t *) 	   &MapaModbus.RegistrosModbus[1721]))
#define min_quarta1 		(*((vol uint8_t *)     &MapaModbus.RegistrosModbus[1720]))
#define hora_quarta2 		(*((vol uint8_t *) 	   &MapaModbus.RegistrosModbus[1723]))
#define min_quarta2 		(*((vol uint8_t *)     &MapaModbus.RegistrosModbus[1722]))
#define hora_quarta3 		(*((vol uint8_t *) 	   &MapaModbus.RegistrosModbus[1725]))
#define min_quarta3 		(*((vol uint8_t *)     &MapaModbus.RegistrosModbus[1724]))
#define hora_quarta4 		(*((vol uint8_t *) 	   &MapaModbus.RegistrosModbus[1727]))
#define min_quarta4 		(*((vol uint8_t *)     &MapaModbus.RegistrosModbus[1726]))
#define hora_quinta1 		(*((vol uint8_t *) 	   &MapaModbus.RegistrosModbus[1729]))
#define min_quinta1 		(*((vol uint8_t *)     &MapaModbus.RegistrosModbus[1728]))
#define hora_quinta2 		(*((vol uint8_t *) 	    &MapaModbus.RegistrosModbus[1731]))
#define min_quinta2 		(*((vol uint8_t *)  	&MapaModbus.RegistrosModbus[1730]))
#define hora_quinta3 		(*((vol uint8_t *) 	&MapaModbus.RegistrosModbus[1733]))
#define min_quinta3 		(*((vol uint8_t *)  	&MapaModbus.RegistrosModbus[1732]))
#define hora_quinta4 		(*((vol uint8_t *) 	&MapaModbus.RegistrosModbus[1735]))
#define min_quinta4 		(*((vol uint8_t *)  	&MapaModbus.RegistrosModbus[1734]))
#define hora_sexta1 		(*((vol uint8_t *) 	&MapaModbus.RegistrosModbus[1737]))
#define min_sexta1 		 	(*((vol uint8_t *)     &MapaModbus.RegistrosModbus[1736]))
#define hora_sexta2 		(*((vol uint8_t *) 	&MapaModbus.RegistrosModbus[1739]))
#define min_sexta2 		 	(*((vol uint8_t *)     &MapaModbus.RegistrosModbus[1738]))
#define hora_sexta3 		(*((vol uint8_t *) 	&MapaModbus.RegistrosModbus[1741]))
#define min_sexta3 		 	(*((vol uint8_t *)     &MapaModbus.RegistrosModbus[1740]))
#define hora_sexta4 		(*((vol uint8_t *) 	&MapaModbus.RegistrosModbus[1743]))
#define min_sexta4 		 	(*((vol uint8_t *)     &MapaModbus.RegistrosModbus[1742]))
#define hora_sabado1 		(*((vol uint8_t *) 	&MapaModbus.RegistrosModbus[1745]))
#define min_sabado1 		(*((vol uint8_t *)  	&MapaModbus.RegistrosModbus[1744]))
#define hora_sabado2 		(*((vol uint8_t *) 	&MapaModbus.RegistrosModbus[1747]))
#define min_sabado2 		(*((vol uint8_t *)  	&MapaModbus.RegistrosModbus[1746]))
#define hora_sabado3 		(*((vol uint8_t *) 	&MapaModbus.RegistrosModbus[1749]))
#define min_sabado3 		(*((vol uint8_t *)  	&MapaModbus.RegistrosModbus[1748]))
#define hora_sabado4 		(*((vol uint8_t *) 	&MapaModbus.RegistrosModbus[1751]))
#define min_sabado4 		(*((vol uint8_t *) 	&MapaModbus.RegistrosModbus[1750]))
#define hora_domingo1 		(*((vol uint8_t *)     &MapaModbus.RegistrosModbus[1753]))
#define min_domingo1 		(*((vol uint8_t *) 	&MapaModbus.RegistrosModbus[1752]))
#define hora_domingo2 		(*((vol uint8_t *)     &MapaModbus.RegistrosModbus[1755]))
#define min_domingo2 		(*((vol uint8_t *) 	&MapaModbus.RegistrosModbus[1754]))
#define hora_domingo3 		(*((vol uint8_t *)     &MapaModbus.RegistrosModbus[1757]))
#define min_domingo3 		(*((vol uint8_t *) 	&MapaModbus.RegistrosModbus[1756]))
#define hora_domingo4 		(*((vol uint8_t *)     &MapaModbus.RegistrosModbus[1759]))
#define min_domingo4 	 	(*((vol uint8_t *) 	&MapaModbus.RegistrosModbus[1758]))
#define hora_feriados1		(*((vol uint8_t *)     &MapaModbus.RegistrosModbus[1761]))
#define min_feriados1  		(*((vol uint8_t *)     &MapaModbus.RegistrosModbus[1760]))
#define hora_feriados2		(*((vol uint8_t *)     &MapaModbus.RegistrosModbus[1763]))
#define min_feriados2  		(*((vol uint8_t *)     &MapaModbus.RegistrosModbus[1762]))
#define hora_feriados3		(*((vol uint8_t *)     &MapaModbus.RegistrosModbus[1765]))
#define min_feriados3  		(*((vol uint8_t *)     &MapaModbus.RegistrosModbus[1764]))
#define hora_feriados4		(*((vol uint8_t *)     &MapaModbus.RegistrosModbus[1767]))
#define min_feriados4 		(*((vol uint8_t *)     &MapaModbus.RegistrosModbus[1766]))



#define inicio_hora_atua_rele1_ini 	 (*((vol uint8_t *)     &MapaModbus.RegistrosModbus[1769]))
#define inicio_minuto_atua_rele1_ini (*((vol uint8_t *)	 &MapaModbus.RegistrosModbus[1768]))
#define inicio_hora_atua_rele1_fim 	 (*((vol uint8_t *)     &MapaModbus.RegistrosModbus[1771]))
#define inicio_minuto_atua_rele1_fim (*((vol uint8_t *)	 &MapaModbus.RegistrosModbus[1770]))
#define inicio_hora_atua_rele2_ini 	 (*((vol uint8_t *)     &MapaModbus.RegistrosModbus[1773]))
#define inicio_minuto_atua_rele2_ini (*((vol uint8_t *)	 &MapaModbus.RegistrosModbus[1772]))
#define inicio_hora_atua_rele2_fim   (*((vol uint8_t *)	 &MapaModbus.RegistrosModbus[1775]))
#define inicio_minuto_atua_rele2_fim (*((vol uint8_t *)	 &MapaModbus.RegistrosModbus[1774]))
#define inicio_hora_atua_rele3_ini   (*((vol uint8_t *)	 &MapaModbus.RegistrosModbus[1777]))
#define inicio_minuto_atua_rele3_ini (*((vol uint8_t *)	 &MapaModbus.RegistrosModbus[1776]))
#define inicio_hora_atua_rele3_fim	 (*((vol uint8_t *)     &MapaModbus.RegistrosModbus[1779]))
#define inicio_minuto_atua_rele3_fim (*((vol uint8_t *)	 &MapaModbus.RegistrosModbus[1778]))




#endif




#endif






