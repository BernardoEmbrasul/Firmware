/*****************************************************************************
 *   calculos.h:  Header file for calculos.c
 *
 *   Copyright(C) 2006, Embrasul Ind. Eletrônica
 *   All rights reserved.
 *
 *   History
 *   2006.1.12  ver 1.00    Prelimnary version, first Release
 *
 ******************************************************************************/
#ifndef __CALCULOSCM_H 
#define __CALCULOSCM_H

#define NAO_DEFINIDA 0
#define MENOS_BANCOS 1
#define MAIS_BANCOS  2


#define COLOCA_1_DO_RODIZIO       0
#define RETIRA_1_DO_RODIZIO       1
#define CONTROLE_NORMAL           2
#define DESLIGA_TODOS             3
#define NAO_ALTERA                4
#define OPERA_MANUAL              5


#define Vmax 			400
#define Imax 			5
#define Smax 			2000 //fundo de escala analogico por fase (400V*5A)
#define Smax3f 			6000

#ifdef Trifasico
#define Imaxd 5791.204537
#define Vmaxd 5791.204537
#define Smaxd  16769025.0
#define Smaxd3f 50307075.0
#else
#ifdef FRANK
#define Vmaxd 2895.6022
#define Imaxd 2895.6022
#define Smaxd 8384512.3
#define Smaxd3f 25153536.900
#else
#define Imaxd 180.3122
#define Vmaxd 180.3122
#define Smaxd  1.625624473442000e+004//(float)0.5*Vmaxd*Imaxd//x2
#define Smaxd3f 4.876873420326000e+004 //(float)3*Smaxd//x2
#endif
#endif


EXT void Cal_BuscaDeBancosIguais(void);
EXT float Cal_BancoKVARtoRealWorld(unsigned short valordobanco);
EXT void Cal_Geratabela(void);
EXT unsigned char Cal_ContaUns(unsigned short sequencia);	
EXT unsigned char Cal_EncontraCombinacao(void);
EXT void Cal_ZeraAcumulos(void);
EXT void Cal_TestFaltaCorrente(void);
EXT void Cal_TestFaltaTensao(void);	 
EXT void Sys_AlarmeVerificacao(void);
EXT void Cal_VerifiaRodizio(void);
EXT void Cal_ZeraGrandezas(char fase);
EXT unsigned short Cal_Xor(unsigned short in1,unsigned short in2);
EXT unsigned char Cal_CalcChaveamentos(unsigned short Statusfinal);
EXT void Cal_CalControleCM4020m(void);
EXT void Cal_CalculoControl1(void);
EXT void Cal_CalculoGrandezas(void);


#endif /* end __CALCULOS_H */
/******************************************************************************
 **                            End Of File
 ******************************************************************************/
