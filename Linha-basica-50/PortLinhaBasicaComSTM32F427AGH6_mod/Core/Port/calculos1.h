/*****************************************************************************
 *   calculos.h:  Header file for calculos.c
 *
 *   Copyright(C) 2006, Embrasul Ind. Eletr�nica
 *   All rights reserved.
 *
 *   History
 *   2006.17.04  ver 1.00    Prelimnary version, first Release
 *
 ******************************************************************************/
#ifndef __CALCULOS_H 
#define __CALCULOS_H

EXT void Calculos1 (void);
void RotinasDeCalibracao(void);
float Sign(float numero);
void CarregaBuffer(void);
void ResgistrarIntervalo15minAgora(void);
void MomentoDeAvaliacaoDeIntervalo15min(void);
void ZeraVariaveisDeHoje(void);
void TrocaDeMes(void);
void ZeraEsteMesAteAgora(void);
void ZeraMesPassado(void);
void Zera15min(void);
void Zera15minAcc(void);
void ZeraTotaisHorarios(void);
//void EncheMapa(void); 
void ReorganizaLista(float *Lista ,short *MesDiaLista ,short *HoraMinLista );
void MomentoDeAvaliacaoDeIntervalo1min(void);

void AcumulaPotenciasNow(float Pot, float *GNowPos, float *GNowNeg);


void ResgistrarIntervaloMMAgora(void);
void AcumulaGrandezaMM(void);
void CalculaGrandezaMM(void);
void ZeraGrandezaMMAcc(void);

#endif /* end __CALCULOS_H */
/******************************************************************************
 **                            End Of File
 ******************************************************************************/
