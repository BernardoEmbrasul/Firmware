#define EXT extern
#include "global.h"


void InitBatteryRam(void)
{
	DWORD *pWD;

	if (RegistroCabecalho2K.id != REG_BATT_MEM_INIT)
	{
#ifndef REVISAO_D
		ConfigurePLL_18Mhz();
#endif

		ClearBatteryRam();
		RegistroCabecalho2K.id=REG_BATT_MEM_INIT;
		RegistroCabecalho2K.ProximoEnderecoAserEscritoNaFlash=SETOR_MM_INICIO;
		RegistroCabecalho2K.ProximoEnderecoAserApagadoNaFlash=SETOR_MM_INICIO;
		RegistroCabecalho2K.ProximoEnderecoAserEscritoNaBattRam=RTC_RAM_BASE_ADDR+((DWORD)&RegistroCabecalho2K.NextPos)-((DWORD)&RegistroCabecalho2K.id);
		RegistroCabecalho2K.FlagProximoRegistroSeraComRTC=SIM;
		RegistroCabecalho2K.TempoDeIntegracaoGrandezas=15;//default � 15min
		pWD=&(RegistroCabecalho2K.ProximoEnderecoAserEscritoNaBattRam);
		*pWD=0xFFFFFFFF;

		AtualizaLRCBloco2K();
		toogleWDI();

		erase((void*)SETOR_MM_INICIO,(void*)SETOR_MM_FIM);	  //apaga tudo o setor de "Memoria de Massa"
	//	erase((void*)SETOR_MM_INICIO,(void*)0x080BFFFF);	  //apaga tudo o setor de "Memoria de Massa"
	//	toogleWDI();
	//	erase((void*)0x080C0000,(void*)0x080DFFFF);	  //apaga tudo o setor de "Memoria de Massa"
	//	toogleWDI();
	//	erase((void*)0x080E0000,(void*)0x080FFFFF);	  //apaga tudo o setor de "Memoria de Massa"



		toogleWDI();
#ifndef REVISAO_D
		ConfigurePLL_72Mhz();
#endif
	}
}

// Apaga o conteudo da battery ram
void ClearBatteryRam(void)
{

	void* pdw = (void *)&RegistroCabecalho2K.id;
	memset(pdw, (unsigned char)0xff, 2048);

}

// Move o bloco de 2k para o setor da Flash disponível
void MoveBatteryRamToFlash(void)
{
	DWORD i;
//	unsigned long* pdw;
	U8 *myByte;

	//se a batram se perde ao ponto de querer sobre-escrever o código .hex então nesse caso melhor limpar a batram e toda a região de dados da flash, e resetar o equipamento.
	//if ((RegistroCabecalho2K.ProximoEnderecoAserEscritoNaFlash < SETOR_MM_INICIO) || (RegistroCabecalho2K.ProximoEnderecoAserEscritoNaFlash > SETOR_PARAMETRIZACAO_FIM))
	if ((RegistroCabecalho2K.ProximoEnderecoAserEscritoNaFlash < SETOR_MM_INICIO) || (RegistroCabecalho2K.ProximoEnderecoAserEscritoNaFlash > SETOR_MM_FIM))


	{
		toogleWDI();
		erase((void*)SETOR_DADOS1_INICIO,(void*)SETOR_DADOS1_FIM);
		toogleWDI();
	    erase((void*)SETOR_DADOS2_INICIO,(void*)SETOR_DADOS2_FIM);
		RegistroCabecalho2K.id = ~REG_BATT_MEM_INIT;
		InitBatteryRam();
		forceReset();
	}

	if (RegistroCabecalho2K.ProximoEnderecoAserEscritoNaFlash == RegistroCabecalho2K.ProximoEnderecoAserApagadoNaFlash)
	{
		toogleWDI();
		//apago o setor que será escrito logo em seguida
		EraseMMSector(RegistroCabecalho2K.ProximoEnderecoAserApagadoNaFlash);
		toogleWDI();
		//o proximo setor a ser apagado...
		if ((RegistroCabecalho2K.ProximoEnderecoAserApagadoNaFlash+SALTO_ENTRE_SETORES_MM)>=SETOR_MM_FIM)
		{
			RegistroCabecalho2K.ProximoEnderecoAserApagadoNaFlash=SETOR_MM_INICIO;
		}
		else
		{
			RegistroCabecalho2K.ProximoEnderecoAserApagadoNaFlash=RegistroCabecalho2K.ProximoEnderecoAserApagadoNaFlash+SALTO_ENTRE_SETORES_MM;
		}
	}
	/*
	este trecho de c�digo era muito perigoso! deve ser eliminado da linha b�sica!
	for (i = RegistroCabecalho2K.ProximoEnderecoAserEscritoNaBattRam; i < 512; i++)  //512 long words na battery ram
	{
		*pdw=0xFFFFFFFF;
		pdw++;
	} */

	GravaNaBatteryRAM1(REG_BATT_MEM_ALT_FLASH_ESCRITA);
	AtualizaLRCBloco2K();
#ifndef REVISAO_D
	ConfigurePLL_18Mhz();
#endif
	//programo um setor da MM com o conteudo da BattRam (2K)
	toogleWDI();
	MoveBytesBufferToBuffer((BYTE *) &RegistroCabecalho2K.id, (BYTE*)&BufferMovimentacao,1024);
	program((void*) RegistroCabecalho2K.ProximoEnderecoAserEscritoNaFlash,(unsigned long int)&BufferMovimentacao,1024);
	toogleWDI();

	MoveBytesBufferToBuffer((BYTE *)(&RegistroCabecalho2KPlus1024), (BYTE*)&BufferMovimentacao,1024);
	program((void*)(RegistroCabecalho2K.ProximoEnderecoAserEscritoNaFlash+1024), (unsigned long int)&BufferMovimentacao,1024);
	toogleWDI();
	//Configuramos o proximo setor a ser escrito...
#ifndef REVISAO_D
	ConfigurePLL_72Mhz();
#endif
	if (RegistroCabecalho2K.ProximoEnderecoAserEscritoNaFlash+SALTO_NO_SETOR_MM>=SETOR_MM_FIM)
	{
		RegistroCabecalho2K.ProximoEnderecoAserEscritoNaFlash=SETOR_MM_INICIO;
		RegistroCabecalho2K.ProximoEnderecoAserApagadoNaFlash=SETOR_MM_INICIO;
	}
	else
	{
		RegistroCabecalho2K.ProximoEnderecoAserEscritoNaFlash=RegistroCabecalho2K.ProximoEnderecoAserEscritoNaFlash+SALTO_NO_SETOR_MM;
	}

	RegistroCabecalho2K.ProximoEnderecoAserEscritoNaBattRam=RTC_RAM_BASE_ADDR+((DWORD)&RegistroCabecalho2K.NextPos)-((DWORD)&RegistroCabecalho2K.id);

	//agora 'zeramos' os dados da ram de 2K!
	//as duas linhas a seguir n�o faziam o menor sentido...
	//i=(RTC_RAM_BASE_ADDR+((DWORD)&RegistroCabecalho2K.NextPos)-((DWORD)&RegistroCabecalho2K.id));
	//pdw =(DWORD *)i;

	//myByte=(U8*)&RegistroCabecalho2K.NextPos;
	myByte=(U8*)RegistroCabecalho2K.ProximoEnderecoAserEscritoNaBattRam;
	for (i = RegistroCabecalho2K.ProximoEnderecoAserEscritoNaBattRam; i < (RTC_RAM_BASE_ADDR+2048); i++)
	{
		*myByte=0xFF;
		 myByte++;
	}


	RegistroCabecalho2K.FlagProximoRegistroSeraComRTC=SIM;
}

// Apaga tudo o setor de "Memoria de Massa"
void EraseMMSector(unsigned long int Sector)
{
#ifndef REVISAO_D
	ConfigurePLL_18Mhz();
#endif
toogleWDI();
	erase((void*)Sector,(void*)(Sector+0x00007FFF));
	toogleWDI();
#ifndef REVISAO_D
	ConfigurePLL_72Mhz();
#endif
}

void GravaNaBatteryRAM1(short TipoDeRegistro)
{
	short i;
	DWORD * pDW1;
	DWORD * pDW2;

	if (TipoDeRegistro == REG_BATT_MEM_ALT_FLASH_ESCRITA )
	{
		RegistroDeAlteracoesFlash.id = REG_BATT_MEM_ALT_FLASH_ESCRITA;
		RegistroDeAlteracoesFlash.HorarioDaAlteracao = RTCGetTime();
		RegistroDeAlteracoesFlash.EnderecoInicial = RegistroCabecalho2K.ProximoEnderecoAserEscritoNaFlash;
		RegistroDeAlteracoesFlash.EnderecoFinal = RegistroDeAlteracoesFlash.EnderecoInicial + 0x7FF;
		RegistroCabecalho2K.HorarioDaEscritaNoCabecalho = RegistroDeAlteracoesFlash.HorarioDaAlteracao;
		pDW1 = (DWORD*)RegistroCabecalho2K.ProximoEnderecoAserEscritoNaBattRam;
		pDW2 = (DWORD*)&RegistroDeAlteracoesFlash.id;

		for (i = 0; i < (sizeof(RegistroDeAlteracoesFlash)/4); i++)
		{
			*pDW1 = *pDW2;
			pDW1++;
			pDW2++;
		}
		RegistroCabecalho2K.ProximoEnderecoAserEscritoNaBattRam=(DWORD)pDW1;

		*pDW1 = 0xFFFFFFFF; //garante que o serviço do power, e o EA não se percam ao ler MM.
	}
	AtualizaLRCBloco2K(); //incluido para atualizar LRC
}

void GravaNaBatteryRAM(short TipoDeRegistro)
{
	short testMod=0;
	short i;
	DWORD * pDW1;
	DWORD * pDW2;
#if EQUIP_LINHA50==CD_EQUIP
	static U64 lastTimeStamp = 0;
#endif
#ifdef MODELO_EA
	testMod=1;
#endif
#ifdef MODELO_RA
	testMod=2;
#endif
#ifdef MODELO_REA
	testMod=3;
#endif
	if (BateriaMorta == SIM)
		return;
//TipoDeRegistro = REG_BATT_MEM_NORM_COM_RTC; //adicionado por Gabriel
	if (testMod!=0){

		if (TipoDeRegistro == REG_BATT_MEM_ALERTA_BAT_MORTA )
		{
			RegistroDeAlteracoesConfig.id=REG_BATT_MEM_ALERTA_BAT_MORTA;
			RegistroDeAlteracoesConfig.HorarioDaAlteracao=RTCGetTime();
			RegistroDeAlteracoesConfig.TempoDeIntegracaoGrandezas=tMMgrandezas;
			//atualiz. do cabecalho de 2k
			RegistroCabecalho2K.TempoDeIntegracaoGrandezas=RegistroDeAlteracoesConfig.TempoDeIntegracaoGrandezas;
			RegistroCabecalho2K.HorarioDaEscritaNoCabecalho=RegistroDeAlteracoesConfig.HorarioDaAlteracao;
			RegistroCabecalho2K.FlagProximoRegistroSeraComRTC=SIM;

			pDW1=(DWORD*)RegistroCabecalho2K.ProximoEnderecoAserEscritoNaBattRam;
			pDW2=(DWORD*)&RegistroDeAlteracoesConfig.id;
			for (i = 0; i < (sizeof(RegistroDeAlteracoesConfig)/4); i++)
			{
				*pDW1=*pDW2;
				pDW1++;
				pDW2++;
			}
			RegistroCabecalho2K.ProximoEnderecoAserEscritoNaBattRam=(DWORD)pDW1;
			*pDW1=0xFFFFFFFF; //garante que o serviço do power, e o EA não se percam ao ler MM.
		}

		if (TipoDeRegistro == REG_BATT_MEM_ALT_CONFIG)
		{

			RegistroDeAlteracoesConfig.id=REG_BATT_MEM_ALT_CONFIG;
			RegistroDeAlteracoesConfig.HorarioDaAlteracao=RTCGetTime();
			RegistroDeAlteracoesConfig.TempoDeIntegracaoGrandezas=tMMgrandezas;
			//atualiz. do cabecalho de 2k
			RegistroCabecalho2K.TempoDeIntegracaoGrandezas=RegistroDeAlteracoesConfig.TempoDeIntegracaoGrandezas;
			RegistroCabecalho2K.HorarioDaEscritaNoCabecalho=RegistroDeAlteracoesConfig.HorarioDaAlteracao;
			RegistroCabecalho2K.FlagProximoRegistroSeraComRTC=SIM;

			pDW1=(DWORD*)RegistroCabecalho2K.ProximoEnderecoAserEscritoNaBattRam;
			pDW2=(DWORD*)&RegistroDeAlteracoesConfig.id;
			for (i=0;i<(sizeof(RegistroDeAlteracoesConfig)/4);i++)
			{
				*pDW1=*pDW2;
				pDW1++;
				pDW2++;
			}
			RegistroCabecalho2K.ProximoEnderecoAserEscritoNaBattRam=(DWORD)pDW1;
			*pDW1=0xFFFFFFFF; //garante que o serviço do power, e o EA não se percam ao ler MM.

			ProximoIniciodeIntervalo1Min=RegistroDeAlteracoesConfig.HorarioDaAlteracao.RTC_Min+1;
			if (RegistroDeAlteracoesConfig.HorarioDaAlteracao.RTC_Min==60) {ProximoIniciodeIntervalo1Min=0;}
			Cnt1min=0;
		}
		#ifndef MEMORIA_DE_MASSA_NOVA
		if ((TipoDeRegistro == REG_BATT_MEM_NORM_COM_RTC ) || (TipoDeRegistro == REG_BATT_MEM_NORM_COM_RTC_ANTES_DE_QUEDA))
		{
			RegistroNormalComRelogio.id = TipoDeRegistro;
			RegistroCabecalho2K.HorarioDaEscritaNoCabecalho = RTCGetTime();
			RegistroNormalComRelogio.MMUa_ = MMUa;
			RegistroNormalComRelogio.MMUb_ = MMUb;
			RegistroNormalComRelogio.MMUc_ = MMUc;
			RegistroNormalComRelogio.MMIa_ = MMIa;
			RegistroNormalComRelogio.MMIb_ = MMIb;
			RegistroNormalComRelogio.MMIc_ = MMIc;
			RegistroNormalComRelogio.MMDemP_ = MMDemP; // PotAtivForaPonta15min + PotAtivPonta15min + PotAtivReserv15min;
			RegistroNormalComRelogio.MMDemQ_ = MMDemQ; // PotReatForaPonta15min + PotReatPonta15min + PotReatReserv15min;
			RegistroNormalComRelogio.MMFp_ = MMFp;

			RegistroNormalComRelogio.HorarioDoEvento = (RegistroCabecalho2K.HorarioDaEscritaNoCabecalho);
			pDW1=(DWORD*)RegistroCabecalho2K.ProximoEnderecoAserEscritoNaBattRam;
			pDW2=(DWORD*)&RegistroNormalComRelogio.id;

			for (i=0;i<(sizeof(RegistroNormalComRelogio)/4);i++)
			{
				*pDW1 = *pDW2;
				pDW1++;
				pDW2++;
			}
			RegistroCabecalho2K.ProximoEnderecoAserEscritoNaBattRam=(DWORD)pDW1;
			*pDW1=0xFFFFFFFF; //garante que o serviço do power, e o EA não se percam ao ler MM.
		}
		#else

		if ((TipoDeRegistro== REG_BATT_MEM_NORM_SEM_RTC ) || (TipoDeRegistro == REG_BATT_MEM_NORM_COM_RTC))
		{
			TipoDeRegistro = REG_BATT_MEM_NORM_MD4040TI_3G;
		}

		if ((TipoDeRegistro == REG_BATT_MEM_NORM_MD4040TI_3G )||(TipoDeRegistro == REG_BATT_MEM_NORM_COM_RTC_ANTES_DE_QUEDA))
		{
			RegistroMD4040TI_3G.id = TipoDeRegistro;
			RegistroCabecalho2K.HorarioDaEscritaNoCabecalho = RTCGetTime();
			#if EQUIP == CD_EQUIP
			RegistroMD4040TI_3G.MMUa_ = pulso_cp_1;
			RegistroMD4040TI_3G.MMUb_ = pulso_cp_2;
			RegistroMD4040TI_3G.MMUc_ = pulso_cp_3;
			RegistroMD4040TI_3G.MMIa_ = pulso_cp_4;
			RegistroMD4040TI_3G.MMIb_ = pulso_cp_5;
			RegistroMD4040TI_3G.MMIc_ = pulso_cp_6;
			#else

			RegistroMD4040TI_3G.MMUa_ = MMUa;
			RegistroMD4040TI_3G.MMUb_ = MMUb;
			RegistroMD4040TI_3G.MMUc_ = MMUc;
			RegistroMD4040TI_3G.MMIa_ = MMIa;
			RegistroMD4040TI_3G.MMIb_ = MMIb;
			RegistroMD4040TI_3G.MMIc_ = MMIc;
			#endif
			RegistroMD4040TI_3G.MMDemP_ = MMDemP;
			RegistroMD4040TI_3G.MMDemQ_ = MMDemQ;
			RegistroMD4040TI_3G.MMTemp_ = MMTemp;
			RegistroMD4040TI_3G.MMTemp2_ = MMTemp2;
			#if EQUIP == CM_EQUIP
			RegistroMD4040TI_3G.MMPulso1 = *(unsigned int*)(&statuscaps1);
			RegistroMD4040TI_3G.MMPulso2 = *(unsigned int*)(&statuscaps2);
			#else
			RegistroMD4040TI_3G.MMPulso1 = pulso_cp_1;
			RegistroMD4040TI_3G.MMPulso2 = pulso_cp_2;
			#endif

			RegistroMD4040TI_3G.MMStatusDosReles = *(int*)(&StatusDosRelesToMM);

#if EQUIP_LINHA50==CD_EQUIP
			RegistroMD4040TI_3G.Timestamp = DateToTimestamp(RTCGetTime(), 0);
			if(RegistroMD4040TI_3G.Timestamp == lastTimeStamp)
						RegistroMD4040TI_3G.Timestamp = RegistroMD4040TI_3G.Timestamp + 1;

					lastTimeStamp = RegistroMD4040TI_3G.Timestamp;

#else

			if (TipoDeRegistro == REG_BATT_MEM_NORM_COM_RTC_ANTES_DE_QUEDA)
			{
				RegistroMD4040TI_3G.Timestamp = DateToTimestamp(RegistroCabecalho2K.HorarioDaEscritaNoCabecalho,0);
				//RegistroMD4040TI_3G.Timestamp = (RegistroCabecalho2K.HorarioDaEscritaNoCabecalho);
			}
			else
			{
				RegistroMD4040TI_3G.Timestamp = DateToTimestamp(RegistroCabecalho2K.HorarioDaEscritaNoCabecalho,1);
			}
#endif
			pDW1=(DWORD*)RegistroCabecalho2K.ProximoEnderecoAserEscritoNaBattRam;
			pDW2=(DWORD*)&RegistroMD4040TI_3G.id;

			for (i=0;i<(sizeof(RegistroMD4040TI_3G)/4);i++)
			{
				*pDW1=*pDW2;
				pDW1++;
				pDW2++;
			}
			RegistroCabecalho2K.ProximoEnderecoAserEscritoNaBattRam=(DWORD)pDW1;
			*pDW1=0xFFFFFFFF; //garante que o serviço do power, e o EA não se percam ao ler MM.
		}
		#endif
		if (TipoDeRegistro== REG_BATT_MEM_NORM_SEM_RTC )
		{
			RegistroNormalSemRelogio.id=REG_BATT_MEM_NORM_SEM_RTC;
			RegistroNormalSemRelogio.MMUa_  =MMUa  ;
			RegistroNormalSemRelogio.MMUb_  =MMUb  ;
			RegistroNormalSemRelogio.MMUc_  =MMUc  ;
			RegistroNormalSemRelogio.MMIa_  =MMIa  ;
			RegistroNormalSemRelogio.MMIb_  =MMIb  ;
			RegistroNormalSemRelogio.MMIc_  =MMIc  ;
			RegistroNormalSemRelogio.MMDemP_=  MMDemP; // PotAtivForaPonta15min + PotAtivPonta15min + PotAtivReserv15min;
			RegistroNormalSemRelogio.MMDemQ_=  MMDemQ; // PotReatForaPonta15min + PotReatPonta15min + PotReatReserv15min;
			RegistroNormalSemRelogio.MMFp_  =MMFp ;
			RegistroCabecalho2K.HorarioDaEscritaNoCabecalho=RTCGetTime();

			pDW1=(DWORD*)RegistroCabecalho2K.ProximoEnderecoAserEscritoNaBattRam;
			pDW2=(DWORD*)&RegistroNormalSemRelogio.id;

			for (i=0;i<(sizeof(RegistroNormalSemRelogio)/4);i++)
			{
				*pDW1=*pDW2;
				pDW1++;
				pDW2++;
			}
			RegistroCabecalho2K.ProximoEnderecoAserEscritoNaBattRam=(DWORD)pDW1;
			*pDW1=0xFFFFFFFF; //garante que o serviço do power, e o EA não se percam ao ler MM.
		}

#if (USAR_REGISTRO_SHORT==SIM)
		if ((TipoDeRegistro==REG_BATT_MEM_SHORT_COM_RTC ) )
		{
			RegistroShortComRelogio.id=REG_BATT_MEM_SHORT_COM_RTC;
			RegistroCabecalho2K.HorarioDaEscritaNoCabecalho=RTCGetTime();
			RegistroShortComRelogio.MMUa_  =MMUa  ;
			RegistroShortComRelogio.MMIa_  =MMIa  ;
			RegistroShortComRelogio.MMDemP_=  MMDemP;//PotAtivForaPonta15min+PotAtivPonta15min+PotAtivReserv15min; //
			RegistroShortComRelogio.MMDemQ_=  MMDemQ;//PotReatForaPonta15min+PotReatPonta15min+PotReatReserv15min;   //

			RegistroShortComRelogio.HorarioDoEvento=RegistroCabecalho2K.HorarioDaEscritaNoCabecalho;
			pDW1=(DWORD*)RegistroCabecalho2K.ProximoEnderecoAserEscritoNaBattRam;
			pDW2=(DWORD*)&RegistroShortComRelogio.id;

			for (i = 0; i < (sizeof(RegistroShortComRelogio)/4); i++)
			{
				*pDW1=*pDW2;
				pDW1++;
				pDW2++;
			}
			RegistroCabecalho2K.ProximoEnderecoAserEscritoNaBattRam=(DWORD)pDW1;
			*pDW1=0xFFFFFFFF; //garante que o serviço do power, e o EA não se percam ao ler MM.
		}

		if (TipoDeRegistro== REG_BATT_MEM_SHORT_SEM_RTC )
		{
			RegistroShortSemRelogio.id=REG_BATT_MEM_SHORT_SEM_RTC;
			RegistroShortSemRelogio.MMUa_  =MMUa  ;
			RegistroShortSemRelogio.MMIa_  =MMIa  ;
			RegistroShortSemRelogio.MMDemP_=  MMDemP;//PotAtivForaPonta15min+PotAtivPonta15min+PotAtivReserv15min; //MMDemP;
			RegistroShortSemRelogio.MMDemQ_=  MMDemQ;//PotReatForaPonta15min+PotReatPonta15min+PotReatReserv15min; //MMDemQ;
			RegistroCabecalho2K.HorarioDaEscritaNoCabecalho=RTCGetTime();

			pDW1=(DWORD*)RegistroCabecalho2K.ProximoEnderecoAserEscritoNaBattRam;
			pDW2=(DWORD*)&RegistroShortSemRelogio.id;

			for (i=0;i<(sizeof(RegistroShortSemRelogio)/4);i++)
			{
				*pDW1=*pDW2;
				pDW1++;
				pDW2++;
			}
			RegistroCabecalho2K.ProximoEnderecoAserEscritoNaBattRam=(DWORD)pDW1;
			*pDW1=0xFFFFFFFF; //garante que o serviço do power, e o EA não se percam ao ler MM.
		}
#endif

		if (TipoDeRegistro== REG_BATT_MEM_ATV_FLASH_LEITURA )
		{
			RegistroDeLeituraFlash.id=REG_BATT_MEM_ATV_FLASH_LEITURA;
			RegistroDeLeituraFlash.HorarioDaLeitura=RTCGetTime();

			RegistroCabecalho2K.HorarioDaEscritaNoCabecalho=RegistroDeLeituraFlash.HorarioDaLeitura;
			pDW1=(DWORD*)RegistroCabecalho2K.ProximoEnderecoAserEscritoNaBattRam;
			pDW2=(DWORD*)&RegistroDeLeituraFlash.id;

			for (i=0;i<(sizeof(RegistroDeAlteracoesFlash)/4);i++)
			{
				*pDW1=*pDW2;
				pDW1++;
				pDW2++;
			}
			RegistroCabecalho2K.ProximoEnderecoAserEscritoNaBattRam=(DWORD)pDW1;
			*pDW1=0xFFFFFFFF; //garante que o serviço do power, e o EA não se percam ao ler MM.
		}

		if (TipoDeRegistro== REG_BATT_MEM_ALT_RELES )
		{
			RegistroDeAlteracoesReles.id=REG_BATT_MEM_ALT_RELES;
			RegistroDeAlteracoesReles.HorarioDaAlteracao=RTCGetTime();
			RegistroDeAlteracoesReles.StatusReles=(DWORD)StatusDeTodosOsReles;
			pDW1=(DWORD*)RegistroCabecalho2K.ProximoEnderecoAserEscritoNaBattRam;
			pDW2=(DWORD*)&RegistroDeAlteracoesReles.id;

			RegistroCabecalho2K.HorarioDaEscritaNoCabecalho=RegistroDeAlteracoesReles.HorarioDaAlteracao;

			for (i=0;i<(sizeof(RegistroDeAlteracoesReles)/4);i++)
			{
				*pDW1=*pDW2;
				pDW1++;
				pDW2++;
			}
			RegistroCabecalho2K.ProximoEnderecoAserEscritoNaBattRam=(DWORD)pDW1;
			*pDW1=0xFFFFFFFF; //garante que o serviço do power, e o EA não se percam ao ler MM.
		}

		if (TipoDeRegistro== REG_BATT_MEM_Q )
		{
			RegistroDeQuedas_e_Voltas.id=REG_BATT_MEM_Q ; //identificador do tipo de registro (x: quedas y:voltas )
			RegistroDeQuedas_e_Voltas.HorarioDoEvento=RTCGetTime();
			RegistroCabecalho2K.HorarioDaEscritaNoCabecalho=RegistroDeQuedas_e_Voltas.HorarioDoEvento;
			RegistroCabecalho2K.HorarioDaUltimaQueda=RegistroDeQuedas_e_Voltas.HorarioDoEvento;
			RegistroCabecalho2K.FlagProximoRegistroSeraComRTC=SIM;

			pDW1=(DWORD*)RegistroCabecalho2K.ProximoEnderecoAserEscritoNaBattRam;
			pDW2=(DWORD*)&RegistroDeQuedas_e_Voltas.id;

			for (i=0;i<(sizeof(RegistroDeQuedas_e_Voltas)/4);i++)
			{
				*pDW1=*pDW2;
				pDW1++;
				pDW2++;
			}
			RegistroCabecalho2K.ProximoEnderecoAserEscritoNaBattRam=(DWORD)pDW1;
			*pDW1=0xFFFFFFFF; //garante que o serviço do power, e o EA não se percam ao ler MM.
		}

		if (TipoDeRegistro== REG_BATT_MEM_V )
		{
			RegistroDeQuedas_e_Voltas.id=REG_BATT_MEM_V; //identificador do tipo de registro (x: quedas y:voltas )
			RegistroDeQuedas_e_Voltas.HorarioDoEvento=RTCGetTime();
			RegistroCabecalho2K.HorarioDaEscritaNoCabecalho=RegistroDeQuedas_e_Voltas.HorarioDoEvento;
			RegistroCabecalho2K.HorarioDaUltimaVolta=RegistroDeQuedas_e_Voltas.HorarioDoEvento;

			RegistroCabecalho2K.FlagProximoRegistroSeraComRTC=SIM;

			pDW1=(DWORD*)RegistroCabecalho2K.ProximoEnderecoAserEscritoNaBattRam;
			pDW2=(DWORD*)&RegistroDeQuedas_e_Voltas.id;

			for (i=0;i<(sizeof(RegistroDeQuedas_e_Voltas)/4);i++)
			{
				*pDW1=*pDW2;
				pDW1++;
				pDW2++;
			}
			RegistroCabecalho2K.ProximoEnderecoAserEscritoNaBattRam=(DWORD)pDW1;
			*pDW1=0xFFFFFFFF; //garante que o serviço do power, e o EA não se percam ao ler MM.
		}

#ifdef MODELO_DURACAO_PULSO
		if (TipoDeRegistro== REG_BATT_MEM_VPULSO )	   //vamos usar a mesma estrutura de RegistroAlteracoesReles
		{
			RegistroDeAlteracoesReles.id=REG_BATT_MEM_VPULSO;
			RegistroDeAlteracoesReles.HorarioDaAlteracao=RTCGetTime();
			RegistroDeAlteracoesReles.StatusReles=(DWORD)StatusDeTodosOsReles;
			pDW1=(DWORD*)RegistroCabecalho2K.ProximoEnderecoAserEscritoNaBattRam;
			pDW2=(DWORD*)&RegistroDeAlteracoesReles.id;

			RegistroCabecalho2K.HorarioDaEscritaNoCabecalho=RegistroDeAlteracoesReles.HorarioDaAlteracao;

			for (i=0;i<(sizeof(RegistroDeAlteracoesReles)/4);i++)
			{
				*pDW1=*pDW2;
				pDW1++;
				pDW2++;
			}
			RegistroCabecalho2K.ProximoEnderecoAserEscritoNaBattRam=(DWORD)pDW1;
			*pDW1=0xFFFFFFFF; //garante que o serviço do power, e o EA não se percam ao ler MM.
		}

		if (TipoDeRegistro== REG_BATT_MEM_QPULSO )	   //vamos usar a mesma estrutura de RegistroAlteracoesReles
		{
			RegistroDeAlteracoesReles.id=REG_BATT_MEM_QPULSO;
			RegistroDeAlteracoesReles.HorarioDaAlteracao=RTCGetTime();
			RegistroDeAlteracoesReles.StatusReles=(DWORD)StatusDeTodosOsReles;
			pDW1=(DWORD*)RegistroCabecalho2K.ProximoEnderecoAserEscritoNaBattRam;
			pDW2=(DWORD*)&RegistroDeAlteracoesReles.id;

			RegistroCabecalho2K.HorarioDaEscritaNoCabecalho=RegistroDeAlteracoesReles.HorarioDaAlteracao;

			for (i=0;i<(sizeof(RegistroDeAlteracoesReles)/4);i++)
			{
				*pDW1=*pDW2;
				pDW1++;
				pDW2++;
			}
			RegistroCabecalho2K.ProximoEnderecoAserEscritoNaBattRam=(DWORD)pDW1;
			*pDW1=0xFFFFFFFF; //garante que o serviço do power, e o EA não se percam ao ler MM.
		}
#endif

		AtualizaLRCBloco2K();
		//se falta pouco para encher os 2k de batt ram, mandamos escrever na Flash
		if ((DWORD)((DWORD)RegistroCabecalho2K.ProximoEnderecoAserEscritoNaBattRam-(DWORD)RTC_RAM_BASE_ADDR)>(DWORD)(2048-200))
			MoveBatteryRamToFlash(); //move o bloco de 2k para o setor da Flash disponível.
	}
}

void AtualizaLRCBloco2K()
{
	DWORD i;
	unsigned long* pdw;
	DWORD tLRC=0;
	RegistroCabecalho2K.LRC=0;

	pdw =(unsigned long *)&RegistroCabecalho2K.id;
	for (i=0;i<512;i++)
	{
		tLRC=tLRC+*pdw;
		pdw++;
	}
	tLRC=~tLRC+1;
	RegistroCabecalho2K.LRC=tLRC;
}
