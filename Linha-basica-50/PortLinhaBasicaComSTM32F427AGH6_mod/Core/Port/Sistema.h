/*****************************************************************************
 *   sistema.h:  Header file for calculos.c
 *
 *   Copyright(C) 2006, Embrasul Ind. Eletrônica
 *   All rights reserved.
 *
 *   History
 *   2006.1.12  ver 1.00    Prelimnary version, first Release
 *
 ******************************************************************************/
#ifndef __SISTEMA_CM_H 
#define __SISTEMA_CM_H


#define MascaraAlarme 0x1000

#ifdef Trifasico
#define AMOSTRAS 101
#define AMOSTRAS_1 AMOSTRAS-1
#define AMOSTRASf AMOSTRAS_1
#else
#define nAMOSTRAS 216
#endif


//#define Latch1 StatusLatchs.Latch_c[1]
//#define Latch2 StatusLatchs.Latch_c[0]
//#define Latch12 StatusLatchs.Latch_i

EXT void Sys_SetDefault(void);
EXT void Sys_OperaSaidas(void);
EXT void Sys_OperaSaidas1(void);
EXT void Sys_ProgramaAlvo(unsigned short valor);
EXT void Sys_Delay200Ms(void);
EXT void Sys_Delay1Ms(void);
EXT void Sys_AtualizaValorDosBancos(void);
EXT void Sys_HexBcd(unsigned long int numero);
EXT void Sys_AlarmeVerificacao(void);
EXT void Sys_MudaEstadoDoAlarme(unsigned char alarme);
EXT void Sys_SalvaParametrizacao(void);
EXT void Sys_RestauraParametrizacao(void);

EXT void Sys_RestauraParametrizacaoDefault(void);
EXT void Sys_SalvaParametrizacaoCM(void);
EXT void Sys_RestauraParametrizacaoCM(void);
EXT void Sys_EfetuaComando(void);
EXT void Cal_OFFmaior(void);
EXT void Cal_OFFmenor(void);
EXT void Cal_ONmaior(void);
EXT void Sys_VericaHorario(void);
EXT void Cal_ONmenor(void);
#endif /* end __SISTEMA_CM_H */
/******************************************************************************
 **                            End Of File
 ******************************************************************************/
