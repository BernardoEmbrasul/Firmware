#define EXT extern
#include "global.h"


extern short modo_escritaMM;
float const loteTP1[3]={
	1.7002518967039e-009, // polinomioUC[0]=  1.7002518967039e-009;
	-1.23731886278975e-006,// polinomioUC[1]=-1.23731886278975e-006;
	0.000366358582617384  // polinomioUC[2]=  0.000366358582617384;
	// polinomioUC[3]=   -0.0360495465982403;
};

float const loteTP2[3]={
	0.00000000054116,
	-0.00000030451850,
	0.00001206354734
		//0.05258721584117
} ;

float const loteTC1[8]={
	//baixas correntes
	0.361093615845142,
	-0.852488219412815,
	0.656128245549836,
	0.0,//-0.163638557564571,

	//altas correntes
	0.000800189633649975,
	-0.0066649097870429,
	0.011289988518537,
	-0.00647326308316515
};

float const loteTC2[8]={
	//baixas correntes
	0.138763440776496,
	-0.3556342658742,
	0.296194800464576,
	0.0,//-0.0795446039952648,

	//altas correntes
	0.000637809318308983,
	-0.00509136260490325,
	0.006913931372163,
	-0.00411489432817802
};

float const loteTC3[8]={
	//baixas correntes
	0.0774607826193481,
	-0.226244697217735,
	0.193526091663143,
	0.0,//-0.0317841822340672,

	//altas correntes
	0.000303599831586341,
	-0.000764767013230881,
	-0.0139403524679011,
	0.0265498228233773
};

float const loteTC4[8]={
	//baixas correntes
	0.11157682259235,
	-0.23138015574750,
	0.13915068188910,
	0.05477057421403,

	//altas correntes
	0.00007324304619,
	0.00054305002274,
	-0.01083883452258,
	0.08348598291002
};


float const loteTCToroide1[8]={
	//baixas correntes
	0.11157682259235,
	-0.23138015574750,
	0.13915068188910,
	0.05477057421403,

	//altas correntes
	0.00007324304619,
	0.00054305002274,
	-0.01083883452258,
	0.08348598291002
};


float const TCsemPolinomio[8]={
	//baixas correntes
	0.0,
	0.0,
	0.0,
	0.0,

	//altas correntes
	0.0,
	0.0,
	0.0,
	0.0
};




#define NUMERO_DE_CURVAS_DE_TP 2
#define NUMERO_DE_CURVAS_DE_TC 5

#ifdef LEGADO
const unsigned long int EnderecosLotesTP[NUMERO_DE_CURVAS_DE_TP]={(const unsigned long)&loteTP1, (const unsigned long)&loteTP2};
const unsigned long int EnderecosLotesTC[NUMERO_DE_CURVAS_DE_TC]={(const unsigned long)&TCsemPolinomio, (const unsigned long)&loteTC2, (const unsigned long)&loteTC3, (const unsigned long)&loteTC4 , (const unsigned long)&loteTCToroide1} ;
#else
unsigned long int EnderecosLotesTP[NUMERO_DE_CURVAS_DE_TP];
unsigned long int EnderecosLotesTC[NUMERO_DE_CURVAS_DE_TC];

#endif




void MoveRamToBuffer(BYTE *pToRam, BYTE *pToBuffer, unsigned int NumberOfBytes)
{
	void *src = (void *)pToRam;
	void *dst = (void *)pToBuffer;

	memcpy(dst, src, NumberOfBytes);
/*
	unsigned int i;
	for (i=0;i<NumberOfBytes;i++)
	{
		*pToBuffer=*pToRam;
		pToBuffer++; pToRam++;
	}
*/
}



void MoveBytesBufferToBuffer(BYTE *pBufferSource,BYTE *pToBufferDest, short NumberOfBytes)
{
	void *src = (void *)pBufferSource;
	void *dst = (void *)pToBufferDest;

	memcpy(dst, src, NumberOfBytes);
/*
	short i;
	for (i=0;i<NumberOfBytes;i++)
	{
		*pToBufferDest=  *pBufferSource;
		pToBufferDest++; pBufferSource++;
	}
*/
}

void MoveBufferToRam(BYTE *pToBuffer,BYTE *pToRam, unsigned int NumberOfBytes)
{
	void *src = (void *)pToBuffer;
	void *dst = (void *)pToRam;

	memcpy(dst, src, NumberOfBytes);
/*
	unsigned int i;
	for (i=0;i<NumberOfBytes;i++)
	{
		*pToRam=*pToBuffer;
		pToBuffer++; pToRam++;
	}
*/
}


void MoveFlashToBuffer( BYTE const *pFromFlash, BYTE *pToBuffer, unsigned int NumberOfBytes)
{
	void *src = (void *)pFromFlash;
	void *dst = (void *)pToBuffer;

	memcpy(dst, src, NumberOfBytes);
/*
	unsigned int i;
	for (i=0;i<NumberOfBytes;i++)
	{
		*pToBuffer=*pToflash;
		pToBuffer++; pToflash++;
	}
*/
}

void IniciaParametrosCalibracaoDefault()
{
#if (EQUIP_LINHA50 == CT_EQUIP)
	nivelDCUa=0;
	nivelDCUb=0;
	nivelDCUc=0;
	nivelDCIa=0;
	nivelDCIb=0;
	nivelDCIc=0;
	FatorCalibUa=1;
	FatorCalibUb=1;
	FatorCalibUc=1;
	FatorCalibIa=1;
	FatorCalibIb=1;
	FatorCalibIc=1;
	FatorCalibUa_=0;
	FatorCalibUb_=0;
	FatorCalibUc_=0;
	FatorCalibIa_=0;
	FatorCalibIb_=0;
	FatorCalibIc_=0;

#else
	nivelDCUa=512;
	nivelDCUb=512;
	nivelDCUc=512;
	nivelDCIa=512;
	nivelDCIb=512;
	nivelDCIc=512;
	FatorCalibUa=1;
	FatorCalibUb=1;
	FatorCalibUc=1;
	FatorCalibIa=1;
	FatorCalibIb=1;
	FatorCalibIc=1;
#endif

#if EQUIP!=CM_EQUIP
	OnOffPulseRate=2;
#endif

	#if (EQUIP_LINHA50 != CT_EQUIP)
	FatorCalibUa_=1;
	FatorCalibUb_=1;
	FatorCalibUc_=1;
	FatorCalibIa_=1;
	FatorCalibIb_=1;
	FatorCalibIc_=1;
	#endif
	FatorCalibFreq=1;
	/*defini��o de lotes de tp e tc...*/
	TpAlote=1;
	TpBlote=1;
	TpClote=1;
#if EQUIP!=CM_EQUIP
#ifndef COM_TOROIDE
	TcAlote=4;
	TcBlote=4;
	TcClote=4;
#endif


#ifdef COM_TOROIDE
	TcAlote=5;
	TcBlote=5;
	TcClote=5;
#endif
#else
	TcAlote=5;
	TcBlote=5;
	TcClote=5; /*
				  TcAlote=3; //este era o lote padrao do CM4040
				  TcBlote=3;
				  TcClote=3;*/
#endif

#ifdef TOROIDE_TRIFASICO
	TcAlote=0;
	TcBlote=0;
	TcClote=0;
#endif

#ifdef COM_FLEX
	TcAlote=0;
	TcBlote=0;
	TcClote=0;
#endif

	/*definicao do nivel DC de cada polinomio*/
	polinomioUA[3]=0.0;
	polinomioUB[3]=0.0;
	polinomioUC[3]=0.0;
	polinomioIA[3]=0.0;
	polinomioIB[3]=0.0;
	polinomioIC[3]=0.0;
	EquipamentoCalibrado=NAO;
	HabCapator=OFF;	//o capator inicia desabilitado!
	ModBusLiberado=SIM;
//#if FIRST==SIM
if (EquipVirgem==SIM)
{
	nserie_str[0]='1';
	nserie_str[1]='2';
	nserie_str[2]='3';
	nserie_str[3]='4';
	nserie_str[4]='5';
	nserie_str[5]='6';
	nserie_str[6]='7';
	nserie_str[7]='8';
}
//#endif
	BloqueioTeclado=OFF;

	ZeraEsteMesAteAgora();
	ZeraMesPassado();
	ZeraVariaveisDeHoje();
	Zera15min();
	Zera15minAcc();
	JaRegistrouNoIntervalode15Min=NAO;
	ZeraTotaisHorarios();
	ConsumoT=0;ConsumoA=0;ConsumoB=0;ConsumoC=0;
	EnergGerT=0;EnergGerA=0;EnergGerB=0;EnergGerC=0;
	EnergIndT=0;EnergIndA=0;EnergIndB=0;EnergIndC=0;
	EnergCapT=0; EnergCapA=0;EnergCapB=0;EnergCapC=0;

//Variaveis int64 de calc de Consumo e Energias s�o zeradas durante CALIBRACAO
// Add by CCT
	EnergGerT_int64=0; EnergGerA_int64=0; EnergGerB_int64=0; EnergGerC_int64=0;
	ConsumoT_int64=0;  ConsumoA_int64=0;  ConsumoB_int64=0;  ConsumoC_int64=0;
	EnergIndT_int64=0; EnergIndA_int64=0; EnergIndB_int64=0; EnergIndC_int64=0;
	EnergCapT_int64=0; EnergCapA_int64=0; EnergCapB_int64=0; EnergCapC_int64=0;

	TemperaturaCoefA_ch0=1.00;
	TemperaturaCoefB_ch0=0.00;
	TemperaturaCoefA_ch1=1.00;
	TemperaturaCoefB_ch1=0.00;




}

void RestauraCalibracao()
{
	float const *pFlashFloat;
	short const *pFlashShort;
	BYTE const  *pFlashByte;
	U8 mac_adr[6];
#if EQUIP==CM_EQUIP
	EquipamentoCalibrado=StatusFuncaoFinal[45];
	if (StatusFuncaoFinal[45]!=NAO)
	{
		if (StatusFuncaoFinal[45]!=SIM) {
			StatusFuncaoFinal[45]=NAO;
			EquipamentoCalibrado=NAO;
		}
	}
#else
	OnOffPulseRate=10;
#endif
//	EquipVirgem= SIM ;
//#if FIRST==SIM
if (EquipVirgem==SIM)
	EquipamentoCalibrado=NAO;
//#endif

	if (EquipamentoCalibrado==NAO) {
		EquipamentoCalibrado=SIM;
		EtapaDeCalibracao=0;
		IniciaParametrosCalibracaoDefault();

		//toogleWDI();
		//erase((void*)SETOR_CALIBRACAO_INICIO,(void*)SETOR_CALIBRACAO_FIM);	  //apaga um setor de 4Kbytes
		//toogleWDI();
		//program((void*)SETOR_CALIBRACAO_INICIO,(unsigned int)&FatorCalibUa,256);
		//toogleWDI();
	}
	else
	{

		HabCapator=ON;
	#if ((EQUIP_LINHA50== CA_EQUIP)||((EQUIP_LINHA50== CT_EQUIP)))
		HabCapator=OFF;
	#endif

		get_calib_addr( );
		pFlashFloat=(const float*)(curr_calib_addr);

		//pFlashFloat=(const float*)SETOR_CALIBRACAO_INICIO;
		FatorCalibUa=*pFlashFloat; pFlashFloat++;
		FatorCalibUb=*pFlashFloat; pFlashFloat++;
		FatorCalibUc=*pFlashFloat; pFlashFloat++;
		FatorCalibIa=*pFlashFloat; pFlashFloat++;
		FatorCalibIb=*pFlashFloat; pFlashFloat++;
		FatorCalibIc=*pFlashFloat; pFlashFloat++;
		FatorCalibUa_=*pFlashFloat; pFlashFloat++;
		FatorCalibUb_=*pFlashFloat; pFlashFloat++;
		FatorCalibUc_=*pFlashFloat; pFlashFloat++;
		FatorCalibIa_=*pFlashFloat; pFlashFloat++;
		FatorCalibIb_=*pFlashFloat; pFlashFloat++;
		FatorCalibIc_=*pFlashFloat; pFlashFloat++;
		FatorCalibFreq=  *pFlashFloat; pFlashFloat++;
		pFlashShort=(const short*)pFlashFloat;
		nivelDCUa=*pFlashShort; pFlashShort++;
		nivelDCUb=*pFlashShort; pFlashShort++;
		nivelDCUc=*pFlashShort; pFlashShort++;
		nivelDCIa=*pFlashShort; pFlashShort++;
		nivelDCIb=*pFlashShort; pFlashShort++;
		nivelDCIc=*pFlashShort; pFlashShort++;
		/*definicao do nivel DC de cada polinomio*/
		pFlashFloat=(const float*)pFlashShort;    //UA[0]
		pFlashFloat++; pFlashFloat++; pFlashFloat++; //UA[3]
		polinomioUA[3]=*pFlashFloat;
		pFlashFloat++;  //UB[0]
		pFlashFloat++; pFlashFloat++; pFlashFloat++; //UB[3]
		polinomioUB[3]=*pFlashFloat;
		pFlashFloat++;  //UC[0]
		pFlashFloat++; pFlashFloat++; pFlashFloat++;
		polinomioUC[3]=*pFlashFloat;
		pFlashFloat++;//IA[0]
		pFlashFloat++;//IA[1]
		pFlashFloat++;//IA[2]
		pFlashFloat++;//IA[3]
		polinomioIA[3]=*pFlashFloat;
		pFlashFloat++;//IA[4]
		pFlashFloat++;//IA[5]
		pFlashFloat++;//IA[6]
		pFlashFloat++;//IA[7]

		pFlashFloat++;//IB[0]
		pFlashFloat++;//IB[1]
		pFlashFloat++;//IB[2]
		pFlashFloat++;//IB[3]
		polinomioIB[3]=*pFlashFloat;
		pFlashFloat++;//IB[4]
		pFlashFloat++;//IB[5]
		pFlashFloat++;//IB[6]
		pFlashFloat++;//IB[7]

		pFlashFloat++;//IC[0]
		pFlashFloat++;//IC[1]
		pFlashFloat++;//IC[2]
		pFlashFloat++;//IC[3]
		polinomioIC[3]=*pFlashFloat;
		pFlashFloat++;//IC[4]
		pFlashFloat++;//IC[5]
		pFlashFloat++;//IC[6]
		pFlashFloat++;//IC[7]

		pFlashFloat++;// TpAlote
		TemperaturaCoefA_ch0=*pFlashFloat; pFlashFloat++;
		TemperaturaCoefB_ch0=*pFlashFloat; pFlashFloat++;
		TemperaturaCoefA_ch1=*pFlashFloat; pFlashFloat++;
		TemperaturaCoefB_ch1=*pFlashFloat; pFlashFloat++;
		TcBlote=*pFlashFloat; pFlashFloat++;
		TcClote=*pFlashFloat; pFlashFloat++;



	//	pFlashByte = (const BYTE*)SETOR_CALIBRACAO_INICIO + 0xf0-8;

		pFlashByte = (const BYTE*)curr_calib_addr + 0xf0-8;

		nserie_str[0] = *pFlashByte++;
		nserie_str[1] = *pFlashByte++;
		nserie_str[2] = *pFlashByte++;
		nserie_str[3] = *pFlashByte++;
		nserie_str[4] = *pFlashByte++;
		nserie_str[5] = *pFlashByte++;
		nserie_str[6] = *pFlashByte++;
		nserie_str[7] = *pFlashByte++;

		/*nserie_str[0] = '9';
		nserie_str[1] = '9';
		nserie_str[2] = '9';
		nserie_str[3] = '9';
		nserie_str[4] = '9';
		nserie_str[5] = '9';
		nserie_str[6] = '9';
		nserie_str[7] = '9';
*/





	//	pFlashByte = (const BYTE*)SETOR_CALIBRACAO_INICIO + 0xf0;
		pFlashByte = (const BYTE*)curr_calib_addr + 0xf0;
		//pFlashByte = (const BYTE *)pFlashFloat;
//		nserie_str[0] = *pFlashByte++;
//		nserie_str[1] = *pFlashByte++;
//		nserie_str[2] = *pFlashByte++;
//		nserie_str[3] = *pFlashByte++;
//		nserie_str[4] = *pFlashByte++;
//		nserie_str[5] = *pFlashByte++;
//		nserie_str[6] = *pFlashByte++;
//		nserie_str[7] = *pFlashByte++;

		polMa = *pFlashByte++;
		polMb = *pFlashByte++;
		polMc = *pFlashByte++;



	}






	AtualizaPolinomios();

#if 0
	numeroSerieHexa=(nserie_str[4]-0x30)*1000+(nserie_str[5]-0x30)*100+(nserie_str[6]-0x30)*10+(nserie_str[7]-0x30)*1;
	mac_adr[0]=0x1E;//
	mac_adr[1]=0x30;//
	mac_adr[2]=0x6C;//
#if EQUIP==CM_EQUIP
	mac_adr[3]=0xA3;//
#endif
#if EQUIP==TR_EQUIP
	mac_adr[3]=0xA2;//
#endif
#if EQUIP==MD_EQUIP
	mac_adr[3]=0xA1;//
#endif
	mac_adr[4]=(numeroSerieHexa>>8)&0x00FF;
	mac_adr[5]=numeroSerieHexa&0x00FF;
	#ifdef LEGADO
	mem_copy (own_hw_adr, mac_adr, 6);
	#endif
#endif
#if EQUIP==CM_EQUIP
	SenhaMestre.s_char[0]=(nserie_str[7]-0x30)+(nserie_str[6]-0x30)*0x10;
	SenhaMestre.s_char[1]=(nserie_str[5]-0x30)+(nserie_str[4]-0x30)*0x10;
#endif

}


void load_MAC (uint8_t *MACAddr){



if (EquipVirgem == SIM)
	RestauraParametrizacaoDefault();
else
	RestauraParametrizacao();

MACAddr[0] = 0x00;
MACAddr[1] = 0x80;
MACAddr[2] = 0xE1;


	 //numeroSerieHexa=(nserie_str[4]-0x30)*1000+(nserie_str[5]-0x30)*100+(nserie_str[6]-0x30)*10+(nserie_str[7]-0x30)*1;
	//extern RTC_HandleTypeDef hrtc;
	//numeroSerieHexa=HAL_RTCEx_BKUPRead(&hrtc, RTC_BKP_DR0);

	 MACAddr[3]=0xB0+EQUIP_LINHA50;//

//	 MACAddr[4]=nserie_str[0]+nserie_str[1]+nserie_str[2]+nserie_str[3];//=(numeroSerieHexa>>8)&0x00FF;  //(U8)(FatorCalibUa+FatorCalibIb+FatorCalibIc);//
	 //MACAddr[5]=nserie_str[4]+nserie_str[5]+nserie_str[6]+nserie_str[7];//numeroSerieHexa&0x00FF; (U8)(FatorCalibIa+FatorCalibUb+FatorCalibUc);//
	MACAddr[4]=(meuMAC>>8)&0x00FF;
	MACAddr[5]=meuMAC&0x00FF;


}


void AtualizaPolinomios( )
{
	float const *pfloat;

#ifdef TOROIDE_TRIFASICO
	TcAlote=0;
	TcBlote=0;
	TcClote=0;
#endif

	if (TpAlote>(float)(NUMERO_DE_CURVAS_DE_TP-1)) {TpAlote=0;}
	if (TpBlote>(float)(NUMERO_DE_CURVAS_DE_TP-1)) {TpBlote=0;}
	if (TpClote>(float)(NUMERO_DE_CURVAS_DE_TP-1)) {TpClote=0;}
	if (TcAlote>(float)(NUMERO_DE_CURVAS_DE_TC-1)) {TcAlote=0;}
	if (TcBlote>(float)(NUMERO_DE_CURVAS_DE_TC-1)) {TcBlote=0;}
	if (TcClote>(float)(NUMERO_DE_CURVAS_DE_TC-1)) {TcClote=0;}

	pfloat=(const float *)EnderecosLotesTP[(short)TpAlote];
	polinomioUA[0]=*pfloat; pfloat++;
	polinomioUA[1]=*pfloat; pfloat++;
	polinomioUA[2]=*pfloat; pfloat++;

	pfloat=(const float *)EnderecosLotesTP[(short)TpBlote];
	polinomioUB[0]=*pfloat; pfloat++;
	polinomioUB[1]=*pfloat; pfloat++;
	polinomioUB[2]=*pfloat; pfloat++;

	pfloat=(const float *)EnderecosLotesTP[(short)TpClote];
	polinomioUC[0]=*pfloat; pfloat++;
	polinomioUC[1]=*pfloat; pfloat++;
	polinomioUC[2]=*pfloat; pfloat++;

	pfloat=(const float *)EnderecosLotesTC[(short)TcAlote];
	polinomioIA[0]=*pfloat; pfloat++;
	polinomioIA[1]=*pfloat; pfloat++;
	polinomioIA[2]=*pfloat; pfloat++;
	//polinomioIA[3]=*pfloat;
	pfloat++;
	polinomioIA[4]=*pfloat; pfloat++;
	polinomioIA[5]=*pfloat; pfloat++;
	polinomioIA[6]=*pfloat; pfloat++;
	polinomioIA[7]=*pfloat; pfloat++;

	pfloat=(const float *)EnderecosLotesTC[(short)TcBlote];
	polinomioIB[0]=*pfloat; pfloat++;
	polinomioIB[1]=*pfloat; pfloat++;
	polinomioIB[2]=*pfloat; pfloat++;
	//polinomioIB[3]=*pfloat;
	pfloat++;
	polinomioIB[4]=*pfloat; pfloat++;
	polinomioIB[5]=*pfloat; pfloat++;
	polinomioIB[6]=*pfloat; pfloat++;
	polinomioIB[7]=*pfloat; pfloat++;

	pfloat=(const float *)EnderecosLotesTC[(short)TcClote];
	polinomioIC[0]=*pfloat; pfloat++;
	polinomioIC[1]=*pfloat; pfloat++;
	polinomioIC[2]=*pfloat; pfloat++;
	//polinomioIC[3]=*pfloat;
	pfloat++;
	polinomioIC[4]=*pfloat; pfloat++;
	polinomioIC[5]=*pfloat; pfloat++;
	polinomioIC[6]=*pfloat; pfloat++;
	polinomioIC[7]=*pfloat; pfloat++;

	/*
	   if (polMa==0)
	   {
	   polinomioModuloIa[0]=0.0;
	   polinomioModuloIa[1]=0.0;
	   polinomioModuloIa[2]=1.0;
	   polinomioModuloIa[3]=-0.030;
	   }

	   if (polMa==1)
	   {
	   polinomioModuloIa[0]=polinomioMIa[0];
	   polinomioModuloIa[1]=polinomioMIa[1];
	   polinomioModuloIa[2]=polinomioMIa[2];
	   polinomioModuloIa[3]=polinomioMIa[3];
	   }

	   if (polMa==2)
	   {
	   polinomioModuloIa[0]=polinomioMIb[0];
	   polinomioModuloIa[1]=polinomioMIb[1];
	   polinomioModuloIa[2]=polinomioMIb[2];
	   polinomioModuloIa[3]=polinomioMIb[3];
	   }

	   if (polMa==3)
	   {
	   polinomioModuloIa[0]=polinomioMIc[0];
	   polinomioModuloIa[1]=polinomioMIc[1];
	   polinomioModuloIa[2]=polinomioMIc[2];
	   polinomioModuloIa[3]=polinomioMIc[3];
	   }

	//
	if (polMb==0)
	{
	polinomioModuloIb[0]=0.0;
	polinomioModuloIb[1]=0.0;
	polinomioModuloIb[2]=1.0;
	polinomioModuloIb[3]=-0.030;
	}

	if (polMb==1)
	{
	polinomioModuloIb[0]=polinomioMIa[0];
	polinomioModuloIb[1]=polinomioMIa[1];
	polinomioModuloIb[2]=polinomioMIa[2];
	polinomioModuloIb[3]=polinomioMIa[3];
	}

	if (polMb==2)
	{
	polinomioModuloIb[0]=polinomioMIb[0];
	polinomioModuloIb[1]=polinomioMIb[1];
	polinomioModuloIb[2]=polinomioMIb[2];
	polinomioModuloIb[3]=polinomioMIb[3];
	}

	if (polMb==3)
	{
	polinomioModuloIb[0]=polinomioMIc[0];
	polinomioModuloIb[1]=polinomioMIc[1];
	polinomioModuloIb[2]=polinomioMIc[2];
	polinomioModuloIb[3]=polinomioMIc[3];
	}

	//
	if (polMc==0)
	{
	polinomioModuloIc[0]=0.0;
	polinomioModuloIc[1]=0.0;
	polinomioModuloIc[2]=1.0;
	polinomioModuloIc[3]=-0.030;
}

if (polMc==1)
{
	polinomioModuloIc[0]=polinomioMIa[0];
	polinomioModuloIc[1]=polinomioMIa[1];
	polinomioModuloIc[2]=polinomioMIa[2];
	polinomioModuloIc[3]=polinomioMIa[3];
}

if (polMc==2)
{
	polinomioModuloIc[0]=polinomioMIb[0];
	polinomioModuloIc[1]=polinomioMIb[1];
	polinomioModuloIc[2]=polinomioMIb[2];
	polinomioModuloIc[3]=polinomioMIb[3];
}

if (polMc==3)
{
	polinomioModuloIc[0]=polinomioMIc[0];
	polinomioModuloIc[1]=polinomioMIc[1];
	polinomioModuloIc[2]=polinomioMIc[2];
	polinomioModuloIc[3]=polinomioMIc[3];
}

*/
}


void RestauraParametrizacao()
{

	BYTE const *pFlashByte;
	BYTE DataInFlash;
	BYTE DataInFlash1;
	BYTE DataInFlash2;
	short i;
	long int cntx=0;
//	long int ii;
	char RestauraParametrizacaoDeFabrica=ON;

	for (i=0;i<16;i++)
	{
		pFlashByte=(const BYTE*)SETOR_PARAMETRIZACAO_INICIO;
		toogleWDI();
		pFlashByte += (long int)SALTO_NO_SETOR*i;
		//for(ii=0;ii<(long int)SALTO_NO_SETOR*i;ii++)
		//{
		//	pFlashByte++;
		//}
		DataInFlash=*pFlashByte;
		pFlashByte++;
		DataInFlash1=*pFlashByte;
		pFlashByte--;
		DataInFlash2=*pFlashByte;
		while (DataInFlash!=DataInFlash2)
		{
			DataInFlash=*pFlashByte;
			pFlashByte++;
			DataInFlash1=*pFlashByte;
			pFlashByte--;
			DataInFlash2=*pFlashByte;
			toogleWDI();
			cntx++;
			if (cntx==100000) break;
		}

		if (cntx==100000)
		{
			toogleWDI();
			erase((void*)SETOR_DADOS1_INICIO,(void*)SETOR_DADOS1_FIM);
			toogleWDI();
    		erase((void*)SETOR_DADOS2_INICIO,(void*)SETOR_DADOS2_FIM);
			RegistroCabecalho2K.id = ~REG_BATT_MEM_INIT;
			InitBatteryRam();
			RestauraParametrizacaoDefault();
			AtualizaParametrizacao();

		    goto sai_com_decencia;
		}



		if (DataInFlash==0xFF)
		{
			if (i==0)
			{
				RestauraParametrizacaoDeFabrica=ON;
//#if (FIRST==NAO)
				if (EquipVirgem==NAO)
				{
					toogleWDI();
					erase((void*)SETOR_DADOS1_INICIO,(void*)SETOR_DADOS1_FIM);
					toogleWDI();
    				erase((void*)SETOR_DADOS2_INICIO,(void*)SETOR_DADOS2_FIM);
					RegistroCabecalho2K.id = ~REG_BATT_MEM_INIT;
					InitBatteryRam();
				//	RestauraParametrizacaoDefault();	 >>tentar aqui dar o while (1)
				//	AtualizaParametrizacao();
					goto sai_com_decencia;
				    //while (1);
				}
//#endif
			}
			else
			{
				pFlashByte=(const BYTE*)SETOR_PARAMETRIZACAO_INICIO;
				pFlashByte += (long int)SALTO_NO_SETOR*(i-1);
				//for(ii=0;ii<(long int)SALTO_NO_SETOR*(i-1);ii++)
				//{
				//	pFlashByte++;
				//}
				RestauraParametrizacaoDeFabrica=OFF;
				break;
			}
		}
		else
		{
			if (i==15)
			{
				pFlashByte=(const BYTE*)SETOR_PARAMETRIZACAO_INICIO+(long int)SALTO_NO_SETOR*(i);
				RestauraParametrizacaoDeFabrica=OFF;
			}
		}
	}
	toogleWDI();

	if (RestauraParametrizacaoDeFabrica==ON)
		RestauraParametrizacaoDefault();
	else
	{
		//MoveFlashToBuffer(pFlashByte,&BufferMovimentacao[0],120+2+5+14+64);
		MoveFlashToBuffer(pFlashByte,&BufferMovimentacao[0],120+2+5+14+64+50);  //cm

		MoveBytesBufferToBuffer((BYTE*)&BufferMovimentacao[2],(BYTE*)&relacaoTPpri,2);
		MoveBytesBufferToBuffer((BYTE*)&BufferMovimentacao[4],(BYTE*)&relacaoTPsec,2);
		MoveBytesBufferToBuffer((BYTE*)&BufferMovimentacao[6],(BYTE*)&relacaoTPfat,2);
		MoveBytesBufferToBuffer((BYTE*)&BufferMovimentacao[8],(BYTE*)&relacaoTCpri,2);
		MoveBytesBufferToBuffer((BYTE*)&BufferMovimentacao[10],(BYTE*)&relacaoTCsec,2);
		MoveBytesBufferToBuffer((BYTE*)&BufferMovimentacao[12],(BYTE*)&relacaoTCfat,2);
		MoveBytesBufferToBuffer((BYTE*)&BufferMovimentacao[14],(BYTE*)&hora_ponta_inicio1,100);

		MoveBytesBufferToBuffer((BYTE*)&BufferMovimentacao[120+2],&MeuEnderecoMODBUS,5);
		MoveBytesBufferToBuffer((BYTE*)&BufferMovimentacao[120+2+5],&IPOcteto1,14);
#if EQUIP!=CM_EQUIP
		//MoveBytesBufferToBuffer(&BufferMovimentacao[120+2+5+14],&hora_segunda1,64);
		MoveBytesBufferToBuffer(&BufferMovimentacao[120+2+5+14],&hora_segunda1,64+12); //inclui novos horarios..
		MoveBytesBufferToBuffer((BYTE*)&BufferMovimentacao[253],(BYTE*)&meuMAC,2);

#endif
#if EQUIP==CM_EQUIP
		MoveBytesBufferToBuffer((BYTE*)&BufferMovimentacao[120+2+5+14+64],(BYTE*)&StatusFuncaoFinal,50);
		HorarioSemAtuarInicio=((short)StatusFuncaoFinal[47]<<8)|StatusFuncaoFinal[46]	;
		HorarioSemAtuarFim=   ((short)StatusFuncaoFinal[49]<<8)|StatusFuncaoFinal[48]	;
#endif


	}

	rtc_data=RTCGetTime();

//#if (FIRST==SIM)
if (EquipVirgem==SIM)
	if (EquipamentoParametrizado==NAO)
		RestauraParametrizacaoDefault();
//#endif

	AtualizaParametrizacao();

sai_com_decencia:
NroPorta2=NroPorta;
refresh_ip();
	return;
}

void RestauraParametrizacaoDefault()
{
	//restauramos valores default
	short i;
	meuMAC=0xABCD;
	relacaoTPpri=220;
	relacaoTPsec=220;
	relacaoTPfat=1;
	relacaoTCpri=5;
	relacaoTCsec=5;
	relacaoTCfat=1;
	relacaoTP=1.0;
	relacaoTC=1.0;
	//goto pulo1;

	hora_ponta_inicio1=18; 	 	//inicio do ponta
	min_ponta_inicio1=0;

	hora_fora_ponta_inicio1=6; //inicio do fora ponta
	min_fora_ponta_inicio1=0;

	hora_reserv_inicio1=0;	    //inicio do reserv
	min_reserv_inicio1=0;

	hora_ponta_inicio2=-1; 	 	//inicio do ponta
	min_ponta_inicio2=-1;
	hora_fora_ponta_inicio2=21; //inicio do fora ponta
	min_fora_ponta_inicio2=0;
	hora_reserv_inicio2=-1; 	    //inicio do reserv
	min_reserv_inicio2=-1;
	hora_ponta_inicio3=-1; 	 	//inicio do ponta
	min_ponta_inicio3=-1;
	hora_fora_ponta_inicio3=-1; //inicio do fora ponta
	min_fora_ponta_inicio3=-1;
	hora_reserv_inicio3=-1; 	    //inicio do reserv
	min_reserv_inicio3=-1;
	hora_ponta_inicio4=-1; 	 	//inicio do ponta
	min_ponta_inicio4=-1;
	hora_fora_ponta_inicio4=-1; //inicio do fora ponta
	min_fora_ponta_inicio4=-1;
	hora_reserv_inicio4=-1; 	    //inicio do reserv
	min_reserv_inicio4=-1;
#if EQUIP!=CM_EQUIP
	hora_segunda1 =0xFF;
	min_segunda1  =0xFF;
	hora_segunda2 =0xFF;
	min_segunda2  =0xFF;
	hora_segunda3 =0xFF;
	min_segunda3  =0xFF;
	hora_segunda4 =0xFF;
	min_segunda4  =0xFF;
	hora_terca1   =0xFF;
	min_terca1    =0xFF;
	hora_terca2   =0xFF;
	min_terca2    =0xFF;
	hora_terca3   =0xFF;
	min_terca3    =0xFF;
	hora_terca4   =0xFF;
	min_terca4    =0xFF;
	hora_quarta1  =0xFF;
	min_quarta1   =0xFF;
	hora_quarta2  =0xFF;
	min_quarta2   =0xFF;
	hora_quarta3  =0xFF;
	min_quarta3 =0xFF;
	hora_quarta4 =0xFF;
	min_quarta4 =0xFF;
	hora_quinta1 =0xFF;
	min_quinta1 =0xFF;
	hora_quinta2 =0xFF;
	min_quinta2 =0xFF;
	hora_quinta3 =0xFF;
	min_quinta3 =0xFF;
	hora_quinta4 =0xFF;
	min_quinta4 =0xFF;
	hora_sexta1 =0xFF;
	min_sexta1 =0xFF;
	hora_sexta2 =0xFF;
	min_sexta2 =0xFF;
	hora_sexta3 =0xFF;
	min_sexta3 =0xFF;
	hora_sexta4 =0xFF;
	min_sexta4 =0xFF;
	hora_sabado1=0xFF;
	min_sabado1 =0xFF;
	hora_sabado2=0xFF;
	min_sabado2 =0xFF;
	hora_sabado3=0xFF;
	min_sabado3 =0xFF;
	hora_sabado4=0xFF;
	min_sabado4 =0xFF;
	hora_domingo1 =0xFF;
	min_domingo1 =0xFF;
	hora_domingo2 =0xFF;
	min_domingo2 =0xFF;
	hora_domingo3 =0xFF;
	min_domingo3 =0xFF;
	hora_domingo4 =0xFF;
	min_domingo4 =0xFF;
	hora_feriados1=0xFF;
	min_feriados1 =0xFF;
	hora_feriados2=0xFF;
	min_feriados2 =0xFF;
	hora_feriados3=0xFF;
	min_feriados3 =0xFF;
	hora_feriados4=0xFF;
	min_feriados4 =0xFF;

	inicio_hora_atua_rele1_ini 	=0xFF;
	inicio_minuto_atua_rele1_ini =0xFF;
	inicio_hora_atua_rele1_fim =0xFF;
	inicio_minuto_atua_rele1_fim 	=0xFF;
	inicio_hora_atua_rele2_ini =0xFF;
	inicio_minuto_atua_rele2_ini 	=0xFF;
	inicio_hora_atua_rele2_fim   	=0xFF;
	inicio_minuto_atua_rele2_fim 	=0xFF;
	inicio_hora_atua_rele3_ini 	=0xFF;
	inicio_minuto_atua_rele3_ini =0xFF;
	inicio_hora_atua_rele3_fim	   =0xFF;
	inicio_minuto_atua_rele3_fim	=0xFF;
#endif
	toogleWDI();

#if EQUIP==CM_EQUIP
	for	 (i=0;i<=12;i++)
	{
		StatusFuncaoFinal[i]=0;
	}

	StatusFuncaoFinal[13]=92; //cf_inf
	StatusFuncaoFinal[14]=98; //cf_sup
	StatusFuncaoFinal[15]=0; //tab_valorTD[0] 5seg
	StatusFuncaoFinal[16]=3; //tab_rel_TP[3] 220/220  (obsoleto, nao tem mais tabela!!)
	StatusFuncaoFinal[17]=23; //tab_rel_TC[23] 500/5  (obsoleto, nao tem mais tabela!!)
	StatusFuncaoFinal[18]=70; //al_inf
	StatusFuncaoFinal[19]=100; //al_sup
	StatusFuncaoFinal[20]=0; //nao=bloq capacit
	StatusFuncaoFinal[21]=1; //sim=modo aciona todos  e n�o delta sangrado
	StatusFuncaoFinal[22]=3; //modo alarme corrente= nao atua
	StatusFuncaoFinal[23]=3; //Vlim
	StatusFuncaoFinal[24]=3; //modo alarme tensao
	StatusFuncaoFinal[25]=5; //DHTlim
	StatusFuncaoFinal[26]=3; //modo alarme DHT]= nao atua
	StatusFuncaoFinal[27]=1; //Temp alarme TDx1
	StatusFuncaoFinal[29]=1; //Nro Rede
	StatusFuncaoFinal[30]=7; //Baudrate 115200
	StatusFuncaoFinal[31]=0; //Paridade sem 2 sb
	StatusFuncaoFinal[32]=1; //Manual a ser ligado
	StatusFuncaoFinal[33]=1; //Tipo de Liga��o = 1:trifasica;
	//EquipamentoParametrizado=NAO;
	StatusFuncaoFinal[34]=EquipamentoParametrizado; //nova funcao no CM4020T-ARM
	StatusFuncaoFinal[36]=0;  //senha.senha_c[1]
	StatusFuncaoFinal[35]=0;  //senha.senha_c[0]

	tptc.tptc_i=220;
	StatusFuncaoFinal[38]=tptc.tptc_c[1]; //relacao TP
	StatusFuncaoFinal[37]=tptc.tptc_c[0];
	StatusFuncaoFinal[40]=tptc.tptc_c[1];
	StatusFuncaoFinal[39]=tptc.tptc_c[0];
	tptc.tptc_i=5;
	StatusFuncaoFinal[42]=tptc.tptc_c[1]; //relacao TC
	StatusFuncaoFinal[41]=tptc.tptc_c[0];
	tptc.tptc_i=5;
	StatusFuncaoFinal[44]=tptc.tptc_c[1];
	StatusFuncaoFinal[43]=tptc.tptc_c[0];
	StatusFuncaoFinal[45]=EquipamentoCalibrado ; //NAO;//EquipamentoCalibrado==
	//funcoes com RTC
	StatusFuncaoFinal[46]=0x00;//sem controle inicio, horas
	StatusFuncaoFinal[47]=0x00;//sem controle inicio, minutos
	StatusFuncaoFinal[48]=0x00;//sem controle fim, horas
	StatusFuncaoFinal[49]=0x00;//sem controle fim, minutos
	DiaHoraParaMedAutomatica=0;

#endif

//pulo1:
	MeuEnderecoMODBUS=1;

	#if  MD4040TI==1
		StatusFuncaoFinal[30]=3; //Baudrate 19200
		BaudRatex=BR19200;
		ParidadeStops=ps8O1;
	#else
		BaudRatex=BR115200;
		ParidadeStops=ps8N2;

	#endif
	//	EquipamentoCalibrado=NAO;

#ifdef LEGADO
	IPOcteto1=10;
	IPOcteto2=1;
	IPOcteto3=25;
	IPOcteto4=100;

	MKOcteto1=255;
	MKOcteto2=0;
	MKOcteto3=0;
	MKOcteto4=0;
	GWOcteto1=10;
	GWOcteto2=1;
	GWOcteto3=25;
	GWOcteto4=1;
#else
	/*IPOcteto1=192;
	IPOcteto2=168;
	IPOcteto3=0;
	IPOcteto4=111;

	MKOcteto1=255;
	MKOcteto2=255;
	MKOcteto3=255;
	MKOcteto4=0;
	GWOcteto1=192;
	GWOcteto2=168;
	GWOcteto3=0;
	GWOcteto4=1;*/

	IPOcteto1=10;
	IPOcteto2=1;
	IPOcteto3=25;
	IPOcteto4=100;

	MKOcteto1=255;
	MKOcteto2=255;
	MKOcteto3=255;
	MKOcteto4=0;
	GWOcteto1=10;
	GWOcteto2=1;
	GWOcteto3=25;
	GWOcteto4=1;

#endif ///LEGADO
	//		Reservado3=0;
	NroPorta=1001;
	LeituraConcessionariaSolicitada=OFF;

#if EQUIP==TR_EQUIP
	CiclarTelas=ON;
#else
	CiclarTelas=OFF;
#endif

	BloqueioTeclado	=OFF;
	DiaHoraParaMedAutomatica=0;

	toogleWDI();
	ip_config.IpAdr[0]=(U8)IPOcteto1;           // Local IP Address
	ip_config.IpAdr[1]=(U8)IPOcteto2;           // Local IP Address
	ip_config.IpAdr[2]=(U8)IPOcteto3;           // Local IP Address
	ip_config.IpAdr[3]=(U8)IPOcteto4;           // Local IP Address
	ip_config.DefGW[0]=(U8)GWOcteto1;           // Default GateWay
	ip_config.DefGW[1]=(U8)GWOcteto2;           // Default GateWay
	ip_config.DefGW[2]=(U8)GWOcteto3;           // Default GateWay
	ip_config.DefGW[3]=(U8)GWOcteto4;           // Default GateWay
	ip_config.NetMask[0]=(U8)MKOcteto1;         // Net Mask
	ip_config.NetMask[1]=(U8)MKOcteto2;         // Net Mask
	ip_config.NetMask[2]=(U8)MKOcteto3;         // Net Mask
	ip_config.NetMask[3]=(U8)MKOcteto4;         // Net Mask
	ip_config.PriDNS[0]=8;          // Primary DNS Server
	ip_config.PriDNS[1]=8;          // Primary DNS Server
	ip_config.PriDNS[2]=8;          // Primary DNS Server
	ip_config.PriDNS[3]=8;          // Primary DNS Server
	ip_config.SecDNS[0]=4;         // Secondary DNS Server
	ip_config.SecDNS[1]=4;         // Secondary DNS Server
	ip_config.SecDNS[2]=4;          // Secondary DNS Server
	ip_config.SecDNS[3]=4;          // Secondary DNS Server

	refresh_ip();

	srv_ip[0] = 10;
	srv_ip[1] = 10;
	srv_ip[2] = 1;
	srv_ip[3] = 7;

	for (i=0;i<20;i++)
		feriados[i]=0;
}

void SalvaParametrizacao()
{
	BYTE DataInFlash;
	char DadosSalvos=NAO;
	short i;
	BYTE const *pFlashByte;
	DWORD Addr;

	#ifndef REVISAO_D
	ConfigurePLL_18Mhz();
#endif

	EquipamentoParametrizado=SIM;

#if EQUIP==CM_EQUIP
	StatusFuncaoFinal[45]=EquipamentoCalibrado ;
#endif

	for (i=0;i<256;i++)
		BufferMovimentacao[i]=0xFF;

	BufferMovimentacao[MSB]=0xAB;
	BufferMovimentacao[LSB]=0xCD;

	MoveBytesBufferToBuffer((BYTE*)&relacaoTPpri,(BYTE*)&BufferMovimentacao[2],2);
	MoveBytesBufferToBuffer((BYTE*)&relacaoTPsec,(BYTE*)&BufferMovimentacao[4],2);
	MoveBytesBufferToBuffer((BYTE*)&relacaoTPfat,(BYTE*)&BufferMovimentacao[6],2);
	MoveBytesBufferToBuffer((BYTE*)&relacaoTCpri,(BYTE*)&BufferMovimentacao[8],2);
	MoveBytesBufferToBuffer((BYTE*)&relacaoTCsec,(BYTE*)&BufferMovimentacao[10],2);
	MoveBytesBufferToBuffer((BYTE*)&relacaoTCfat,(BYTE*)&BufferMovimentacao[12],2);
	MoveBytesBufferToBuffer((BYTE*)&hora_ponta_inicio1,(BYTE*)&BufferMovimentacao[14],100);

	MoveBytesBufferToBuffer((BYTE*)&MeuEnderecoMODBUS,(BYTE*)&BufferMovimentacao[120+2],5);
	MoveBytesBufferToBuffer((BYTE*)&IPOcteto1,(BYTE*)&BufferMovimentacao[120+2+5],14);

#if EQUIP!=CM_EQUIP
	MoveBytesBufferToBuffer((BYTE*)&hora_segunda1,(BYTE*)&BufferMovimentacao[120+2+5+14],64+12);  //incluindo as config de horario dos 3 reles

//	BufferMovimentacao[253]=(numeroSerieHexa>>8)&0xFF;//nserie_str[7]+nserie_str[6];
//	BufferMovimentacao[254]=numeroSerieHexa&0xFF;//nserie_str[4]+nserie_str[5];


	MoveBytesBufferToBuffer((BYTE*)&meuMAC,(BYTE*)&BufferMovimentacao[253],2);
#endif

#if EQUIP==CM_EQUIP
	MoveBytesBufferToBuffer((BYTE*)&StatusFuncaoFinal,(BYTE*)&BufferMovimentacao[120+2+5+14+64],64);
#endif





	Addr=(long int)SETOR_PARAMETRIZACAO_INICIO-(long int)SALTO_NO_SETOR;
	for (i=0;i<16;i++)
	{
		Addr=Addr+(long int)SALTO_NO_SETOR;
		pFlashByte=(const BYTE *)Addr;
		DataInFlash=*pFlashByte;

		if (DataInFlash==0xFF){
			toogleWDI();
			DataInFlash=program((void*)Addr,(unsigned int)&BufferMovimentacao[0],256);
			toogleWDI();
			DadosSalvos=SIM;
			break;
		}
	}

	if (DadosSalvos==NAO)
	{
		toogleWDI();
		erase((void*)SETOR_PARAMETRIZACAO_INICIO,(void*)SETOR_PARAMETRIZACAO_FIM);	  //apaga um setor de 4Kbytes
		toogleWDI();
		program ((void*)SETOR_PARAMETRIZACAO_INICIO,(unsigned int)&BufferMovimentacao[0],256);
		toogleWDI();
	}
	AtualizaParametrizacao();

#ifndef REVISAO_D
	ConfigurePLL_72Mhz();
#endif

	if(NroPorta_temp2!=NroPorta)
	{
#if (DEBUG_SEM_TCPIP!=SIM)
#if (MODELO!=SEM_ETHERNET_COM_RS485)
		refresh_ip();
#endif
#endif
	}


#if EQUIP==CM_EQUIP
	If_AtualizaParametros();
#endif
}

BYTE CalcLRCofDataHeader(FlashDataHeader Header)
{
	BYTE Lrc=0;

	Lrc=Header.TipoDeEvento+Lrc;
	Lrc=Header.HoraDaVolta.RTC_Year+Lrc;
	Lrc=Header.HoraDaVolta.RTC_Mon+Lrc;
	Lrc=Header.HoraDaVolta.RTC_Mday+Lrc;
	Lrc=Header.HoraDaVolta.RTC_Hour+Lrc;
	Lrc=Header.HoraDaVolta.RTC_Min+Lrc;
	Lrc=Header.HoraDaVolta.RTC_Sec+Lrc;
	Lrc=Header.HoraDaQueda.RTC_Year+Lrc;
	Lrc=Header.HoraDaQueda.RTC_Mon+Lrc;
	Lrc=Header.HoraDaQueda.RTC_Mday+Lrc;
	Lrc=Header.HoraDaQueda.RTC_Hour+Lrc;
	Lrc=Header.HoraDaQueda.RTC_Min+Lrc;
	Lrc=Header.HoraDaQueda.RTC_Sec+Lrc;
	Lrc=~Lrc+1;
	return(Lrc);
}

void PowerUp()
{
#define FORA_DO_MESMO_MES_MUITOS_MESES_APOS         1
#define FORA_DO_MESMO_MES_UM_MES_APOS 		        2
#define FORA_DO_DIA_NO_MESMO_MES 			        3
#define	NO_MESMO_INTEVALO_DE_15_MIN 		        4
#define	FORA_DO_INTEVALO_DE_15_MIN_NO_MESMO_DIA	 	5
#define	APOS_DOIS_INTEVALOS_DE_15_MIN_NO_MESMO_DIA 	6

	short i;
	short bloco_queda_valido_index=0xFF;  //default
	BYTE const  *pFlashByte;
	BYTE DataInFlash;
	BYTE PosicaoEncontrada=OFF;
	FlashDataHeader Header;
	unsigned char tempvari;
	DWORD TvoltaEmMin;
//	DWORD TquedaEmMin;
	DWORD acu;

	GravaNaBatteryRAM(REG_BATT_MEM_V);//registro de volta

	rtc_horario_volta=RTCGetTime();

	rtc_horario_volta.RTC_Year=rtc_horario_volta.RTC_Year&0xFF;
	MesDeHoje=rtc_horario_volta.RTC_Mon;
	DiaDeHoje=rtc_horario_volta.RTC_Mday;

	bloco_dados_index=0;

	for (i=0;i<4;i++)
	{
		pFlashByte=(const BYTE *)((long int)SETOR_DADOS1_INICIO+((long int)SALTO_NO_SETOR_DADOS*i));
		DataInFlash=*pFlashByte;

		if (DataInFlash==0xFF)
		{
			bloco_dados_index=i;  //proximo bloco onde ser� escrito os consumos e demandas...
			PosicaoEncontrada=ON;
			if (i==3)
			{
				erase((void *)SETOR_DADOS2_INICIO,(void *)SETOR_DADOS2_FIM);
			}
			break;
		}
		else
		{
			if (DataInFlash==QUEDA){
				bloco_queda_valido_index=i;
			}
		}
	}

	if (PosicaoEncontrada==OFF)
	{
		pFlashByte=(const BYTE *)SETOR_DADOS2_INICIO;
		for (i=0;i<4;i++)
		{
			pFlashByte=(const BYTE *)((long int)SETOR_DADOS2_INICIO+(long int)((long int)SALTO_NO_SETOR_DADOS*i));
			DataInFlash=*pFlashByte;

			if (DataInFlash==0xFF)
			{
				bloco_dados_index=0x80|i;
				PosicaoEncontrada=ON;
				if (i==3)
				{
					erase((void *)SETOR_DADOS1_INICIO,(void *)SETOR_DADOS1_FIM);
				}
				break;
			}
			else
			{
				if (DataInFlash==QUEDA){
					bloco_queda_valido_index=0x80|i;
				}
			}
		}
	}

	//agora que foi encontrado proximo bloco vago,
	//vamos restaurar os consumos e demandas
	if (bloco_queda_valido_index==0xFF)
	{
		//o bloco valido pode estar no SETOR_DADOS2, vamos buscar
		for (i=3;i>=0;i--)
		{
			pFlashByte=(const BYTE *)((long int)SETOR_DADOS2_INICIO+(long int)((long int)SALTO_NO_SETOR_DADOS*i));
			DataInFlash=*pFlashByte;
			if (DataInFlash==QUEDA){
				bloco_queda_valido_index=0x80|i;
				break;
			}
		}
	}

	if (bloco_queda_valido_index!=0xFF)
	{
		if ((bloco_queda_valido_index&0x80)==0x00) //DATA1
		{
			pFlashByte=(const BYTE *)(SETOR_DADOS1_INICIO+((long int)SALTO_NO_SETOR_DADOS*(bloco_queda_valido_index)));
		}
		else									   //DATA2
		{
			pFlashByte=(const BYTE *)(SETOR_DADOS2_INICIO+((long int)SALTO_NO_SETOR_DADOS*(bloco_queda_valido_index&0x7F)));
		}

		MoveFlashToBuffer(pFlashByte,&BufferMovimentacao[0],1024);

		Header.TipoDeEvento 		=BufferMovimentacao[0] ;
		Header.HoraDaVolta.RTC_Year =BufferMovimentacao[1] ;
		Header.HoraDaVolta.RTC_Mon	=BufferMovimentacao[2] ;
		Header.HoraDaVolta.RTC_Mday	=BufferMovimentacao[3] ;
		Header.HoraDaVolta.RTC_Hour =BufferMovimentacao[4] ;
		Header.HoraDaVolta.RTC_Min 	=BufferMovimentacao[5] ;
		Header.HoraDaVolta.RTC_Sec 	=BufferMovimentacao[6] ;

		Header.HoraDaQueda.RTC_Year =BufferMovimentacao[7] ;
		Header.HoraDaQueda.RTC_Mon  =BufferMovimentacao[8] ;
		Header.HoraDaQueda.RTC_Mday	=BufferMovimentacao[9] ;
		Header.HoraDaQueda.RTC_Hour	=BufferMovimentacao[10];
		Header.HoraDaQueda.RTC_Min	=BufferMovimentacao[11];
		Header.HoraDaQueda.RTC_Sec	=BufferMovimentacao[12];

		LeituraConcessionariaJaRealizadaEsteMes =   BufferMovimentacao[215]&0x0F;

		JaRegistrouNoIntervalode15Min			=  (BufferMovimentacao[215]&0xF0)>>4;
//#if (FIRST==NAO)
if (EquipVirgem==NAO)
{
		ultimaTelaExibida 						=  BufferMovimentacao[216];
		tela1 									=  (BufferMovimentacao[217]&0x7f);
		tela2									=  BufferMovimentacao[218];
		telaAnterior 							=  BufferMovimentacao[219];
		telaAtual 								=  BufferMovimentacao[220];
}
//#endif
		BloqueioTeclado 						=  (BufferMovimentacao[217]&0x80)>>7;
		ProximoIniciodeIntervalo				=  BufferMovimentacao[221]&0x7F;
		CiclarTelas 							=  BufferMovimentacao[222];
		TipoDeHorario							= (BufferMovimentacao[222]&0xF0)>>4;

		LeituraConcessionariaSolicitada 		=  BufferMovimentacao[223];

		MoveBytesBufferToBuffer((BYTE *)&BufferMovimentacao[13],(BYTE *)INICIO_BLOCO,DIFERENCA); //fonte,destino
		PotAtivPonta15min=ConsumoPonta15min;//
		PotAtivForaPonta15min=ConsumoForaPonta15min;//
		PotAtivReserv15min=ConsumoReserv15min;//
		PotReatPonta15min=EnergIndPonta15min-EnergCapPonta15min;//
		PotReatForaPonta15min=EnergIndForaPonta15min-EnergCapForaPonta15min;//
		PotReatReserv15min=EnergIndReserv15min-EnergCapReserv15min;//

	}

	for (i=0;i<1024;i++)
		BufferMovimentacao[i]=0xFF;

	//Testa se ainda estamos no intervalo de 15minutos,
	//Testa se ainda estamos no mesmo dia em que aconteceu a queda,
	//Testa se ainda estamos no mesmo mes em que aconteceu a queda,

	rtc_horario_queda.RTC_Year= Header.HoraDaQueda.RTC_Year;
	rtc_horario_queda.RTC_Mon=  Header.HoraDaQueda.RTC_Mon;
	rtc_horario_queda.RTC_Mday= Header.HoraDaQueda.RTC_Mday;
	rtc_horario_queda.RTC_Hour= Header.HoraDaQueda.RTC_Hour;
	rtc_horario_queda.RTC_Min=  Header.HoraDaQueda.RTC_Min ;
	rtc_horario_queda.RTC_Sec=  Header.HoraDaQueda.RTC_Sec;

	if (BateriaMorta ==SIM){
		rtc_horario_queda.RTC_Year= Header.HoraDaVolta.RTC_Year;
		rtc_horario_queda.RTC_Mon=  Header.HoraDaVolta.RTC_Mon;
		rtc_horario_queda.RTC_Mday= Header.HoraDaVolta.RTC_Mday;
		rtc_horario_queda.RTC_Hour= Header.HoraDaVolta.RTC_Hour;
		rtc_horario_queda.RTC_Min=  Header.HoraDaVolta.RTC_Min ;
		rtc_horario_queda.RTC_Sec=  Header.HoraDaVolta.RTC_Sec;
		ZeraEsteMesAteAgora();
		ZeraMesPassado();
		ZeraVariaveisDeHoje();
		Zera15min();
		Zera15minAcc();
		JaRegistrouNoIntervalode15Min=NAO;

	}
	acu=0;

	TvoltaEmMin = rtc_horario_volta.RTC_Hour*24+rtc_horario_volta.RTC_Min;

	if (rtc_horario_volta.RTC_Mday!=rtc_horario_queda.RTC_Mday)
	{
		while ((DWORD)acu<=(DWORD)TvoltaEmMin)
		{
			//acu = tMMgrandezas + acu;
			acu += tMMgrandezas + 2;
		}

		if (acu==TvoltaEmMin)
		{
			NumeroDeIntervalos1minParaProximoRegistro=tMMgrandezas;
		}

		if (acu>TvoltaEmMin)
		{
			NumeroDeIntervalos1minParaProximoRegistro=acu-TvoltaEmMin;
		}

	}
	else //no mesmo dia
	{

		if (tMMgrandezas==0)
				{tMMgrandezas=15;}

		while ((DWORD)acu<=(DWORD)TvoltaEmMin)
		{
			acu = tMMgrandezas + acu;
		}

		if (acu==TvoltaEmMin)
		{
			NumeroDeIntervalos1minParaProximoRegistro=tMMgrandezas;
		}

		if (acu>TvoltaEmMin)
		{
			NumeroDeIntervalos1minParaProximoRegistro=acu-TvoltaEmMin;
		}
	}

	tempvari=TestaMomento(rtc_horario_volta,rtc_horario_queda);

	switch (tempvari)
	{
		case FORA_DO_MESMO_MES_MUITOS_MESES_APOS:
			{

				ZeraEsteMesAteAgora();

				ZeraMesPassado();

				ZeraVariaveisDeHoje();

				Zera15min();

				Zera15minAcc();
				JaRegistrouNoIntervalode15Min=NAO;

				break;
			}

		case FORA_DO_MESMO_MES_UM_MES_APOS:
			{

				JaRegistrouNoIntervalode15Min=NAO;

				if (LeituraConcessionariaSolicitada==OFF)
				{
					TrocaDeMes();
					ZeraEsteMesAteAgora();
					ZeraVariaveisDeHoje();
					Zera15min();
					Zera15minAcc();


				}
				else
				{
					ZeraVariaveisDeHoje();
					Zera15min();
					Zera15minAcc();
					LeituraConcessionariaSolicitada=OFF;


				}
				break;
			}
		case FORA_DO_DIA_NO_MESMO_MES:
			{

				ZeraVariaveisDeHoje();
				Zera15min();
				Zera15minAcc();
				JaRegistrouNoIntervalode15Min=NAO;

				break;
			}
		case APOS_DOIS_INTEVALOS_DE_15_MIN_NO_MESMO_DIA:
			{
				Zera15min();
				Zera15minAcc();
				JaRegistrouNoIntervalode15Min=NAO;
				break;
			}

		case FORA_DO_INTEVALO_DE_15_MIN_NO_MESMO_DIA:
			{


				/*
					OBS: O que se espera se volto fora do intervalo de 15min (1 intervalo seguinte) .
					Se espera que os valores acumulados antes da queda sejam passados para os finais
					e os acumulados sejam zerados.
				*/
				ResgistrarIntervalo15minAgora();
				JaRegistrouNoIntervalode15Min=SIM;
				ProximoIniciodeIntervalo=rtc_horario_volta.RTC_Min+1;


				break;
			}


		case NO_MESMO_INTEVALO_DE_15_MIN: //OU SEJA NO MESMO DIA!
			{

				/*
				   O que se espera? Que continue acumulando, e final fica intacto.
				   se JaRegistrouNoIntervalode15Min=SIM; nao registra no minuto cheio,
				   pois ja o fez antes da queda
				 */



				break;
			}
		case 0:
		default://fora do intervalo de 15min, mas no mesmo dia.
			{
			}
	}

	//sairjameu:
	ip_config.IpAdr[0]=(U8)IPOcteto1;           // Local IP Address
	ip_config.IpAdr[1]=(U8)IPOcteto2;           // Local IP Address
	ip_config.IpAdr[2]=(U8)IPOcteto3;           // Local IP Address
	ip_config.IpAdr[3]=(U8)IPOcteto4;           // Local IP Address
	ip_config.DefGW[0 ]=(U8)GWOcteto1;           // Default GateWay
	ip_config.DefGW[1]=(U8)GWOcteto2;           // Default GateWay
	ip_config.DefGW[2]=(U8)GWOcteto3;           // Default GateWay
	ip_config.DefGW[3]=(U8)GWOcteto4;           // Default GateWay
	ip_config.NetMask[0]=(U8)MKOcteto1;         // Net Mask
	ip_config.NetMask[1]=(U8)MKOcteto2;         // Net Mask
	ip_config.NetMask[2]=(U8)MKOcteto3;         // Net Mask
	ip_config.NetMask[3]=(U8)MKOcteto4;         // Net Mask
	ip_config.PriDNS[0]=10;          // Primary DNS Server
	ip_config.PriDNS[1]=1;          // Primary DNS Server
	ip_config.PriDNS[2]=25;          // Primary DNS Server
	ip_config.PriDNS[3]=1;          // Primary DNS Server
	ip_config.SecDNS[0]=10;         // Secondary DNS Server
	ip_config.SecDNS[1]=1;         // Secondary DNS Server
	ip_config.SecDNS[2]=25;          // Secondary DNS Server
	ip_config.SecDNS[3]=1;          // Secondary DNS Server

//	Recupera os valores de Consumo e Energias salvos para o acumulador de int64
// Add by CCT
	EnergGerA_int64 = (unsigned long long) (EnergGerA * 1000);
	EnergGerB_int64 = (unsigned long long) (EnergGerB * 1000);
	EnergGerC_int64 = (unsigned long long) (EnergGerC * 1000);
	EnergGerT_int64 = (unsigned long long) (EnergGerT * 1000);

	ConsumoA_int64 = (unsigned long long) (ConsumoA * 1000);
	ConsumoB_int64 = (unsigned long long) (ConsumoB * 1000);
	ConsumoC_int64 = (unsigned long long) (ConsumoC * 1000);
	ConsumoT_int64 = (unsigned long long) (ConsumoT * 1000);

	EnergIndA_int64 = (unsigned long long) (EnergIndA * 1000);
	EnergIndB_int64 = (unsigned long long) (EnergIndB * 1000);
	EnergIndC_int64 = (unsigned long long) (EnergIndC * 1000);
	EnergIndT_int64 = (unsigned long long) (EnergIndT * 1000);

	EnergCapA_int64 = (unsigned long long) (EnergCapA * 1000);
	EnergCapB_int64 = (unsigned long long) (EnergCapB * 1000);
	EnergCapC_int64 = (unsigned long long) (EnergCapC * 1000);
	EnergCapT_int64 = (unsigned long long) (EnergCapT * 1000);

#if ((EQUIP_LINHA50 == CP_EQUIP))
		pulso_cp_1=EnergGerA;
		pulso_cp_2=ConsumoA;
		pulso_cp_3=EnergGerB;
		pulso_cp_4=ConsumoB;
		pulso_cp_5=EnergGerC;
		pulso_cp_6=ConsumoC;
	#else
		EnergGerA=EnergGerT-EnergGerB-EnergGerC;
		ConsumoA=ConsumoT-ConsumoB-ConsumoC;
	#endif

#ifdef MODELO_B
	BloqueioTeclado = OFF;
#endif


	rtc_horario_volta=RTCGetTime();




	ProximoIniciodeIntervalo1Min=rtc_horario_volta.RTC_Min+1;
	if (ProximoIniciodeIntervalo1Min>=60) {ProximoIniciodeIntervalo1Min=0;}

	if (rtc_horario_volta.RTC_Sec>30)
		ProximoIniciodeIntervalo1Min=ProximoIniciodeIntervalo1Min+1;


}

unsigned char TestaMomento(RTCTime hvolta,RTCTime hqueda)
{

	//#define FORA_DO_MESMO_MES_MUITOS_MESES_APOS  1
	//#define FORA_DO_MESMO_MES_UM_MES_APOS 		 2
	//#define FORA_DO_DIA_NO_MESMO_MES 			 3
	//#define	NO_MESMO_INTEVALO_DE_15_MIN 		 4
	char estado;

	estado=TestaMomento1(hvolta,hqueda);

	if (estado==1) {return (NO_MESMO_INTEVALO_DE_15_MIN);}
	if (estado==2) {return (FORA_DO_INTEVALO_DE_15_MIN_NO_MESMO_DIA);}
	if (estado==3)
	{
		if((hvolta.RTC_Mday==hqueda.RTC_Mday)&&(hvolta.RTC_Mon==hqueda.RTC_Mon)&&((hvolta.RTC_Year&0xFF)==(hqueda.RTC_Year&0xFF)))
		{
			return (APOS_DOIS_INTEVALOS_DE_15_MIN_NO_MESMO_DIA);
		}

		if((hvolta.RTC_Mon==hqueda.RTC_Mon)&&((hvolta.RTC_Year&0xFF)==(hqueda.RTC_Year&0xFF)))
		{
			return (FORA_DO_DIA_NO_MESMO_MES);
		}

		if((hvolta.RTC_Mon==(hqueda.RTC_Mon+1))&&((hvolta.RTC_Year&0xFF)==(hqueda.RTC_Year&0xFF)))
		{
			return (FORA_DO_MESMO_MES_UM_MES_APOS);
		}

		if ((hvolta.RTC_Mon==1)&&(hqueda.RTC_Mon==12)&&((hvolta.RTC_Year&0xFF)==((hqueda.RTC_Year&0xFF)+1)))
		{
			return (FORA_DO_MESMO_MES_UM_MES_APOS);
		}

		return(FORA_DO_MESMO_MES_MUITOS_MESES_APOS);

	}
	return(0);
}

unsigned char TestaMomento1(RTCTime hvolta,RTCTime hqueda)
{
	unsigned char a,b,c,d;
	//unsigned char ret=0;

	if (((hvolta.RTC_Year&0xFF)==(hqueda.RTC_Year&0xFF))&&(hvolta.RTC_Mon==hqueda.RTC_Mon)&&(hvolta.RTC_Mday==hqueda.RTC_Mday))
	{
		c=3;
		if(hqueda.RTC_Min<15){
			a=15; b=30; c=0;
		}
		if((hqueda.RTC_Min>=15)&&(hqueda.RTC_Min<30)){
			a=30; b=45; c=0;
		}
		if((hqueda.RTC_Min>=30)&&(hqueda.RTC_Min<45)){
			a=45; b=60; c=0;
		}
		if(hqueda.RTC_Min>=45){
			c=1;
		}
		if(c==0) {
			if((hvolta.RTC_Hour==hqueda.RTC_Hour)&&(hvolta.RTC_Min<a)&&(hvolta.RTC_Min>=hqueda.RTC_Min)) {
				d=1;//continua acumulando
				return(d);
			}
			if((hvolta.RTC_Hour==hqueda.RTC_Hour)&&(hvolta.RTC_Min<b)&&(hvolta.RTC_Min>=a))  {
				d=2;//retorna valor
				return(d);
			}
			else  {
				d=3;//retorna 0
				return(d);
			}
		}
		if(c==1) {
			if((hvolta.RTC_Hour==hqueda.RTC_Hour)&&(hvolta.RTC_Min<=59)&&(hvolta.RTC_Min>=45))	{
				d=1;//continua acumulando
				return(d);
			}
			if((hvolta.RTC_Hour==(hqueda.RTC_Hour+1))&&((hvolta.RTC_Min<15)&&(hvolta.RTC_Min>=0)))    {
				d=2;//retorna valor
				return(d);
			}
			else  {
				d=3;//retorna 0
				return(d);
			}
		}
	}
	else
	{
		d=3;
		return(d);
	}
	d=3;
	return(d);
}

void PowerDown()
{
	FlashDataHeader Header;
	short i;
	unsigned int save_VicInt;                // for saving of interrupt enable register



#ifdef ATUALIZ_VIA_ETH
	if (modo_escritaMM==0){
#endif
#ifdef LEGADO
   	inhibit_ethernet();
#endif

	SETpinoEmPorta(0, 0x00010000);

	//diminui o clock para nao dar problema na hora da gravacao
#ifndef REVISAO_D
	ConfigurePLL_48Mhz();
#endif

 	DisableAllInterrupts();

#if (EQUIP==CM_EQUIP)
	// desliga reles do CM
	EscreveReles(0x0000);
#endif

#if ((EQUIP_LINHA50 != MD_EQUIP))
	#include "main.h"
	  HAL_GPIO_WritePin(ALARM1_GPIO_Port,ALARM1_Pin, GPIO_PIN_RESET);
	  HAL_GPIO_WritePin(ALARM2_GPIO_Port,ALARM2_Pin, GPIO_PIN_RESET);
	  HAL_GPIO_WritePin(ALARM3_GPIO_Port,ALARM3_Pin, GPIO_PIN_RESET);
#endif
	  extern void SSD1306_OFF(void);
	  SSD1306_OFF();


	rtc_horario_queda=RTCGetTime();
	rtc_horario_queda.RTC_Year=rtc_horario_queda.RTC_Year&0xFF;

	Header.TipoDeEvento=QUEDA; //PowerDown...
	Header.HoraDaVolta=rtc_horario_volta;

	Header.HoraDaQueda.RTC_Year	=rtc_horario_queda.RTC_Year	;
	Header.HoraDaQueda.RTC_Mon	=rtc_horario_queda.RTC_Mon ;
	Header.HoraDaQueda.RTC_Mday	=rtc_horario_queda.RTC_Mday ;
	Header.HoraDaQueda.RTC_Hour	=rtc_horario_queda.RTC_Hour ;
	Header.HoraDaQueda.RTC_Min 	=rtc_horario_queda.RTC_Min  ;
	Header.HoraDaQueda.RTC_Sec 	=rtc_horario_queda.RTC_Sec  ;

	Header.LrcHeader=CalcLRCofDataHeader(Header);

	CalculaGrandezaMM();
	//	GravaNaBatteryRAM(REG_BATT_MEM_NORM_COM_RTC_ANTES_DE_QUEDA); //grava o valor m�dio at� o momento da queda!  ///comentado para evitar complica��es no servi�o do power
	GravaNaBatteryRAM(REG_BATT_MEM_Q); //registro de queda


	  //int cal=205-60-12;
	  int cal=205-60;
	  extern RTC_HandleTypeDef hrtc;
	  uint32_t cal_p, cal_m;

	  if (cal > 0) {
	      cal_p = RTC_SMOOTHCALIB_PLUSPULSES_SET;
	      cal_m = 512 - cal;
	  } else {
	      cal_p = RTC_SMOOTHCALIB_PLUSPULSES_RESET;
	      cal_m = -cal;
	  }
	  HAL_RTCEx_SetSmoothCalib(&hrtc, RTC_SMOOTHCALIB_PERIOD_32SEC, cal_p, cal_m);





	for (i=0;i<1024;i++)
		BufferMovimentacao[i]=0xFF;

	BufferMovimentacao[0]= Header.TipoDeEvento;
	BufferMovimentacao[1]= Header.HoraDaVolta.RTC_Year;
	BufferMovimentacao[2]= Header.HoraDaVolta.RTC_Mon;
	BufferMovimentacao[3]= Header.HoraDaVolta.RTC_Mday;
	BufferMovimentacao[4]= Header.HoraDaVolta.RTC_Hour;
	BufferMovimentacao[5]= Header.HoraDaVolta.RTC_Min;
	BufferMovimentacao[6]= Header.HoraDaVolta.RTC_Sec;

	BufferMovimentacao[7]= (Header.HoraDaQueda.RTC_Year&0xFF);
	BufferMovimentacao[8]= Header.HoraDaQueda.RTC_Mon;
	BufferMovimentacao[9]= Header.HoraDaQueda.RTC_Mday;
	BufferMovimentacao[10]=Header.HoraDaQueda.RTC_Hour;
	BufferMovimentacao[11]=Header.HoraDaQueda.RTC_Min;
	BufferMovimentacao[12]=Header.HoraDaQueda.RTC_Sec;

 

	
#if ((EQUIP_LINHA50 == CP_EQUIP))
	EnergGerA= pulso_cp_1;
	ConsumoA = pulso_cp_2;
	EnergGerB= pulso_cp_3;
	ConsumoB=  pulso_cp_4;
	EnergGerC= pulso_cp_5;
	ConsumoC=  pulso_cp_6;
	#endif


 
	MoveBytesBufferToBuffer((BYTE *)INICIO_BLOCO,&BufferMovimentacao[13],DIFERENCA); //fonte,destino

	if (estou_no_modo_de_programacao==SIM)
	{
		telaAtual=INICIO_TELAS_DE_EXIBICAO;
		tela1=FIM_TELAS_DE_EXIBICAO;
		tela2=INICIO_TELAS_DE_EXIBICAO;
	}

	BufferMovimentacao[215]=LeituraConcessionariaJaRealizadaEsteMes|(JaRegistrouNoIntervalode15Min<<4);
	BufferMovimentacao[216]=ultimaTelaExibida;
	//BufferMovimentacao[217]=(tela1&0x7f)||(BloqueioTeclado<<7); //alterar (tela1 >>8 )|tela para 23 junho 2008
	BufferMovimentacao[217]=(tela1&0x7f)||(BloqueioTeclado<<7); //alterar (tela1 >>8 )|tela para 23 junho 2008
	BufferMovimentacao[218]=tela2;  //alterar (tela1Anterior >>8 )|telaAtual para 23 junho 2008
	BufferMovimentacao[219]=telaAnterior;
	BufferMovimentacao[220]=telaAtual;
	// Teste com m�scara para ProximoIniciodeIntervalo
	BufferMovimentacao[221]=(ProximoIniciodeIntervalo&0x7f);
	BufferMovimentacao[222]=CiclarTelas|(TipoDeHorario<<4);
	BufferMovimentacao[223]=LeituraConcessionariaSolicitada;





	toogleWDI();

	if (((bloco_dados_index)&0x80)==0x80)
	{
		i=program((void*)((long int)SETOR_DADOS2_INICIO+((long int)SALTO_NO_SETOR_DADOS*(bloco_dados_index&0x7F))),(unsigned int)&BufferMovimentacao[0],1024);
	}
	else
	{
		i=program((void*)((long int)SETOR_DADOS1_INICIO+((long int)SALTO_NO_SETOR_DADOS* bloco_dados_index      )),(unsigned int)&BufferMovimentacao[0],1024);
	}
	toogleWDI();


	CLRpinoEmPorta(0,0x00010000);
	//SETpinoEmPorta(0, 0x00010000);

#if EQUIP!=CM_EQUIP
	while(1)
	{
		forceReset();
		//FIO0SET=LED_TX;
		//FIO3SET = 0x02000000;
		//for(i=0;i<100;i++);
		//WrLcdCom(OffDsp);
		//FIO0CLR=LED_TX;
		//for(i=0;i<100;i++);
	}
#endif
	//for�a a morte do equipamento

	//  VICIntEnable=save_VicInt;
#if EQUIP==CM_EQUIP
	Sys_SetDefault();
	toogleWDI();
#if REL_OE_EM_P1==ON

	SETpinoEmPorta(1,REL_OE);
#else

	SETpinoEmPorta(0,REL_OE);
#endif

	forceReset();  //for�a a morte
#endif
#ifdef ATUALIZ_VIA_ETH
	}
#endif
}

void AtualizaParametrizacao()
{
	relacaoTP=(float)relacaoTPfat*((float)relacaoTPpri/(float)relacaoTPsec);
	relacaoTC=(float)relacaoTCfat*((float)relacaoTCpri/(float)relacaoTCsec);

	if (zeraConsumos=='S')
	{
//Aqui � apagado o consumo
		ConsumoT=0;ConsumoA=0; ConsumoB=0;ConsumoC=0;
		EnergGerT=0;EnergGerA=0;EnergGerB=0;EnergGerC=0;
		EnergIndT=0;EnergIndA=0;EnergIndB=0;EnergIndC=0;
		EnergCapT=0; EnergCapA=0;EnergCapB=0;EnergCapC=0;
//Variaveis int64 de calc de Consumo e Energias s�o zeradas durante CMD REMOTO
// Add by CCT
		EnergGerT_int64=0; EnergGerA_int64=0; EnergGerB_int64=0; EnergGerC_int64=0;
		ConsumoT_int64=0;  ConsumoA_int64=0;  ConsumoB_int64=0;  ConsumoC_int64=0;
		EnergIndT_int64=0; EnergIndA_int64=0; EnergIndB_int64=0; EnergIndC_int64=0;
		EnergCapT_int64=0; EnergCapA_int64=0; EnergCapB_int64=0; EnergCapC_int64=0;

		zeraConsumos='n';
	}


}
