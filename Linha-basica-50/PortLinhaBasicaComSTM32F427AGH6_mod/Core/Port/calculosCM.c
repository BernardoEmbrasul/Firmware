
/**********************************************************************
  C�lculos Espec�ficos do CM4020 -
  Rotinas auxiliares tamb�m se encontram aqui
 **********************************************************************/
#define EXT extern
#include "global.h"

#if ((EQUIP==CM_EQUIP))

int numero_estagio(float estagio)
{
	int result;

	if(estagio < 1)
		result = 0;
	if(estagio > 332 && estagio < 334)
		result =  1;
	if(estagio > 499 && estagio < 501)
		result =  2;
	if(estagio > 832 && estagio < 834)
		result =  3;
	if(estagio > 999 && estagio < 1001)
		result =  4;
	if(estagio > 1499 && estagio < 1501)
		result =  5;
	if(estagio > 1999 && estagio < 2001)
		result =  6;
	if(estagio > 2499 && estagio < 2501)
		result =  7;
	if(estagio > 4999 && estagio < 5001)
		result =  8;
	if(estagio > 7499 && estagio < 7501)
		result =  9;
	if(estagio > 9999 && estagio < 10001)
		result =  10;
	if(estagio > 12499 && estagio < 12501)
		result =  11;
	if(estagio > 14999 && estagio < 15001)
		result =  12;
	if(estagio > 17499 && estagio < 17501)
		result =  13;
	if(estagio > 19999 && estagio < 20001)
		result =  14;
	if(estagio > 22499 && estagio < 22501)
		result =  15;
	if(estagio > 24999 && estagio < 25001)
		result =  16;
	if(estagio > 29999 && estagio < 30001)
		result =  17;
	if(estagio > 34999 && estagio < 35001)
		result =  18;
	if(estagio > 39999 && estagio < 40001)
		result =  19;
	if(estagio > 49999 && estagio < 50001)
		result =  20;
	if(estagio > 59999 && estagio < 60001)
		result =  21;
	if(estagio > 69999 && estagio < 70001)
		result =  22;
	if(estagio > 79999 && estagio < 80001)
		result =  23;
	if(estagio > 89999 && estagio < 90001)
		result =  24;
	if(estagio > 99999 && estagio < 100001)
		result =  25;
	if(estagio > 119999 && estagio < 120001)
		result =  26;
	if(estagio > 159999 && estagio < 160001)
		result =  27;
	if(estagio > 199999 && estagio < 200001)
		result =  28;
	if(estagio > 239999 && estagio < 240001)
		result =  29;

	return (result & 0x1F);		
}

/*----------------------------------------------------------------*/
void Cal_Geratabela()
{
	unsigned short i,acumul=0;

	unsigned long KVAr_estagios_1_to_6;
	unsigned long KVAr_estagios_7_to_12;
	unsigned int aux;

	estagio1 =Cal_BancoKVARtoRealWorld(KVAr_estagio[1]);
	estagio2 =Cal_BancoKVARtoRealWorld(KVAr_estagio[2]);
	estagio3 =Cal_BancoKVARtoRealWorld(KVAr_estagio[3]);
	estagio4 =Cal_BancoKVARtoRealWorld(KVAr_estagio[4]);
	estagio5 =Cal_BancoKVARtoRealWorld(KVAr_estagio[5]);
	estagio6 =Cal_BancoKVARtoRealWorld(KVAr_estagio[6]);
	estagio7 =Cal_BancoKVARtoRealWorld(KVAr_estagio[7]);
	estagio8 =Cal_BancoKVARtoRealWorld(KVAr_estagio[8]);
	estagio9 =Cal_BancoKVARtoRealWorld(KVAr_estagio[9]);
	estagio10=Cal_BancoKVARtoRealWorld(KVAr_estagio[10]);
	estagio11=Cal_BancoKVARtoRealWorld(KVAr_estagio[11]);
	estagio12=Cal_BancoKVARtoRealWorld(KVAr_estagio[12]);


	KVAr_estagios_1_to_6 = 0;
	KVAr_estagios_7_to_12 = 0;
	
//	aux = 0;
//	aux = (numero_estagio(estagio6) << 5*5);
//	KVAr_estagios_1_to_6 =	206703687;
//	KVAr_estagios_1_to_6 = 	(numero_estagio(estagio1));
//	KVAr_estagios_1_to_6 =	KVAr_estagios_1_to_6 + (numero_estagio(estagio2) * (0x00000020));
//	KVAr_estagios_1_to_6 =	KVAr_estagios_1_to_6 + (numero_estagio(estagio4) * (0x00008000));
//	KVAr_estagios_1_to_6 =	KVAr_estagios_1_to_6 + (numero_estagio(estagio5) * (0x00100000));
//	KVAr_estagios_1_to_6 =	KVAr_estagios_1_to_6 + (numero_estagio(estagio6) * (0x02000000));

	KVAr_estagios_1_to_6 = 	(numero_estagio(estagio6) << 5*5) | (numero_estagio(estagio5) << 4*5) | (numero_estagio(estagio4) << 3*5) | 
							(numero_estagio(estagio3) << 2*5) | (numero_estagio(estagio2) << 1*5) | (numero_estagio(estagio1) << 0*5); 

	KVAr_estagios_7_to_12 = (numero_estagio(estagio12) << 5*5) | (numero_estagio(estagio11) << 4*5) | (numero_estagio(estagio10) << 3*5) | 
							(numero_estagio(estagio9)  << 2*5) | (numero_estagio(estagio8)  << 1*5) | (numero_estagio(estagio7) << 0*5);

#if EQUIP == CM_EQUIP 	
	statuscaps1 = KVAr_estagios_1_to_6;
	statuscaps2 = KVAr_estagios_7_to_12;
#endif



	//geratabela([1 10 20 20 30 30 30 40 40 40 40 40],12) no matlab
	ZeroKVAr=0x0;
	ncombinacoes=1;

	for (i=1;i<=12;i++)
	{
		if (KVAr_estagio[i]==0)
		{
			ZeroKVAr=ZeroKVAr|mask[i];
		}
		else
		{
			ncombinacoes=2*ncombinacoes;
		}
	}

	ncombinacoes=ncombinacoes-1;

	for (i=0;i<=0xFFF;i++)
	{
		if (i&0x0001) {acumul=KVAr_estagio[1];};
		if (i&0x0002) {acumul=acumul+KVAr_estagio[2];};
		if (i&0x0004) {acumul=acumul+KVAr_estagio[3];};
		if (i&0x0008) {acumul=acumul+KVAr_estagio[4];};
		if (i&0x0010) {acumul=acumul+KVAr_estagio[5];};
		if (i&0x0020) {acumul=acumul+KVAr_estagio[6];};
		if (i&0x0040) {acumul=acumul+KVAr_estagio[7];};
		if (i&0x0080) {acumul=acumul+KVAr_estagio[8];};
		if (i&0x0100) {acumul=acumul+KVAr_estagio[9];};
		if (i&0x0200) {acumul=acumul+KVAr_estagio[10];};
		if (i&0x0400) {acumul=acumul+KVAr_estagio[11];};
		if (i&0x0800) {acumul=acumul+KVAr_estagio[12];};
		tabela[i].KVAr=acumul;
		acumul=0;

	}

	// agora vamos verificar quais destes bancos tem valores iguais... 0KVAR nao conta.
	//sempre conta para o rodizio, os iguais menores, por exemplo, em maior quantidade
	// 10-10-30 30 30 30, no rodizio entram os 30
	// 12-15-30 30 30 30, no rodizio entram os 30
	// 5 -5- 5 -5 -30, no rodizio entram os 5
	// 10-10-30 30 , no rodizio entra 10
	// 10-10-5 -5 , no rodizio entra 5
	//refazer esta parte...  independente de onde eles se encontram...
	Cal_BuscaDeBancosIguais();

	DisplayInit();
	If_TelaApresentacao(menu_atual.leitura);
}
/*-----------------------------------------------------------------------*/
void Cal_BuscaDeBancosIguais()
{
	unsigned char i,j,ind;
	//gui0207 unsigned char igual=0;
	unsigned short  KVArIgual;
	unsigned char histogra[13];
	unsigned char FLAG=OFF;
	//unsigned int  KVArIgualMenor;
	unsigned char max=0;

	// agora vamos verificar quais destes bancos tem valores iguais... 0KVAR nao conta.
	// sempre conta para o rodizio, os iguais menores, por exemplo, em maior quantidade
	// 10-10-30 30 30 30, no rodizio entram os 30
	// 12-15-30 30 30 30, no rodizio entram os 30
	// 5 -5- 5 -5 -30, no rodizio entram os 5
	// 10-10-30 30 , no rodizio entra 10
	// 10-10-5 -5 , no rodizio entra 5
	// refazer esta parte...  independente de onde eles se encontram...

	//busca de algum igual a outro...
	for (i=1;i<=12;i++) {histogra[i]=0;}

	for (i=1;i<=12;i++)
	{
		for (j=1;j<=12;j++)
		{
			if (KVAr_estagio[i]==KVAr_estagio[j])
			{
				if (KVAr_estagio[i]!=0)
				{
					if (i!=j)
					{
						histogra[i]=histogra[i]+1;
					}
				}
			}
		}
	}
	//vamos buscar o pico maximo do histograma...
	for (i=1;i<=12;i++)
	{
		if ((max<=histogra[i])&&(histogra[i]!=0))
		{
			max=histogra[i];
			if (FLAG==OFF)
			{
				KVArIgual=KVAr_estagio[i];
				FLAG=ON;
			}
			else
			{
				if (KVAr_estagio[i]<KVArIgual)
				{
					KVArIgual=KVAr_estagio[i];
				}
			}
		}
	}



	ind=1;
	BancosIguais=0;
	NumeroBancosIguais=0;

	if (max!=0)
	{ //se  chegamos aqui, algum banco � igual a outro..
		//   KVArIgual=KVAr_estagio[max];

		for (i=1;i<=12;i++)
		{
			if (KVAr_estagio[i]==KVArIgual)
			{
				VetorBancosIguais[ind]=mask[i];
				ind++ ;
				BancosIguais=BancosIguais|mask[i];
			}

		}
		NumeroBancosIguais=Cal_ContaUns(BancosIguais);
	}


}
/*-----------------------------------------------------------------------*/
unsigned char Cal_ContaUns(unsigned short sequencia)
{
	//esta rotina conta quantos '1's tem uma sequencia. de 12 bits
	unsigned char acumul=0;
	if (sequencia&0x0001) {acumul++;};
	if (sequencia&0x0002) {acumul++;};
	if (sequencia&0x0004) {acumul++;};
	if (sequencia&0x0008) {acumul++;};
	if (sequencia&0x0010) {acumul++;};
	if (sequencia&0x0020) {acumul++;};
	if (sequencia&0x0040) {acumul++;};
	if (sequencia&0x0080) {acumul++;};
	if (sequencia&0x0100) {acumul++;};
	if (sequencia&0x0200) {acumul++;};
	if (sequencia&0x0400) {acumul++;};
	if (sequencia&0x0800) {acumul++;};
	return(acumul);
}
/*-----------------------------------------------------------------------*/
float Cal_BancoKVARtoRealWorld(unsigned short valordobanco)
{
	/*
	   float tempfloat;
	   Cal_LongIntToFloat(&tempfloat,valordobanco,0);
	//tempfloat=(float)tempfloat/0x10;//para transformar em Var
	tempfloat=(float)tempfloat/12;//para transformar em kVar
	tempfloat=(float)tempfloat*1000;//para transformar em Var
	return(tempfloat);
	 */
	return(((float)valordobanco)*83.333333333333333333333333333333);
}
/*-----------------------------------------------------------------------*/


/*-----------------------------------------------------------------------*/
void Cal_CalculoGrandezas()
{
	RTCTime Get_Time;
	static short previous_min = 1;

	FLAG_TCA_INVERTIDO=0; 
	FLAG_TCB_INVERTIDO=0;
	FLAG_TCC_INVERTIDO=0;
	FLAG_TC_INVERTIDO=0;

	if (PotAtivA<0)
		FLAG_TCA_INVERTIDO=1;
	if (PotAtivB<0)
		FLAG_TCB_INVERTIDO=1;
	if (PotAtivC<0)
		FLAG_TCC_INVERTIDO=1;

	//if ((PotAtivA/(relacaoTP*relacaoTC)<10.0) && (fabs(PotReatA)/(relacaoTP*relacaoTC)<10.0))
	if ((PotAtivA/(relacaoTP*relacaoTC)<10.0) && (fabs(PotReatA)/(relacaoTP*relacaoTC)<10.0))
		FLAG_TCA_INVERTIDO=1;
	if ((PotAtivB/(relacaoTP*relacaoTC)<10.0) && (fabs(PotReatB)/(relacaoTP*relacaoTC)<10.0))
		FLAG_TCB_INVERTIDO=1;
	if ((PotAtivC/(relacaoTP*relacaoTC)<10.0) && (fabs(PotReatC)/(relacaoTP*relacaoTC)<10.0))
		FLAG_TCC_INVERTIDO=1;

	if (PotAtivA==0)
		FLAG_TCA_INVERTIDO=0;
	if (PotAtivB==0)
		FLAG_TCB_INVERTIDO=0;
	if (PotAtivC==0)
		FLAG_TCC_INVERTIDO=0;

	if (Bancos.StatusAtual != 0)
	{
		FLAG_TCA_INVERTIDO = OFF;
		FLAG_TCB_INVERTIDO = OFF;
		FLAG_TCC_INVERTIDO = OFF;
	}

	FLAG_TC_INVERTIDO = FLAG_TCA_INVERTIDO|FLAG_TCB_INVERTIDO|FLAG_TCC_INVERTIDO;

	if (FLAG_FP_FORA==1)
	{
		//acumula
		Pacumulada=Pacumulada+PotAtivT;
		Qacumulada=Qacumulada+PotReatT;
		nPontos++;

	}
	else
	{
		//zera acumulos
		Cal_ZeraAcumulos();
	}
	Qn1=0; Qn2=0;
}



void Cal_CalculoControl1()
{
	unsigned char caso=0;
	unsigned char caso_al=0;
	unsigned char FLAG_HAB_CONTADOR_AL_FP_FORA_temp;


	Sys_AtualizaValorDosBancos();
	Cal_TestFaltaCorrente();
	Cal_TestFaltaTensao();

	FLAG_DHT_FORA=0;
	if (DhtUA>DHTVlim) {FLAG_DHT_FORA=1;}
	if (DhtUB>DHTVlim) {FLAG_DHT_FORA=1;}
	if (DhtUC>DHTVlim) {FLAG_DHT_FORA=1;} 

	if (CF_inf<0)
	{
		caso=3;
	}
	else
	{
		if (CF_sup<0) {caso=2;} else {caso=1;}
	}

	if (CF_al_inf<0)
	{
		caso_al=3;
	}
	else
	{
		if (CF_al_sup<0) {caso_al=2;} else {caso_al=1;}
	}

	FLAG_FP_FORA=0;
	TendCmais=0; TendCmenos=0;


	switch (caso)
	{
		case 1:
			{
				if (FatPotT>0) //cos fi inst. indutivo
				{
					if (FatPotT>CF_sup) {TendCmenos=1; FLAG_FP_FORA=1;}
					if (FatPotT<CF_inf) {TendCmais=1; FLAG_FP_FORA=1;}
				}
				else        //cos fi inst capacitivo
				{
					TendCmenos=1; FLAG_FP_FORA=1;
				}
				break;
			}
		case 2:
			{             //CF_sup � negativo..
				if (FatPotT>0)  //cos fi inst. indutivo
				{
					if (FatPotT<CF_inf) {TendCmais=1; FLAG_FP_FORA=1;}
				}
				else        //cos fi inst capacitivo
				{
					if (FatPotT>CF_sup) {TendCmenos=1; FLAG_FP_FORA=1;} //ex -0.8>-0.92 ->tirar bancos...
				}
				break;
			}
		case 3:
			{
				if (FatPotT>0) //cos fi inst. indutivo
				{
					TendCmais=1; FLAG_FP_FORA=1;
				}
				else        //cos fi inst capacitivo
				{
					if (FatPotT>CF_sup) {TendCmenos=1; FLAG_FP_FORA=1;}
					if (FatPotT<CF_inf) {TendCmais=1; FLAG_FP_FORA=1;}
				}
				break;
			}
	}

	FLAG_HAB_CONTADOR_AL_FP_FORA_temp=0;

	switch (caso_al)
	{
		case 1:
			{
				if (FatPotT>0) //cos fi inst. indutivo
				{
					if (FatPotT>CF_al_sup) { FLAG_HAB_CONTADOR_AL_FP_FORA_temp=1;}
					if (FatPotT<CF_al_inf) { FLAG_HAB_CONTADOR_AL_FP_FORA_temp=1;}
				}
				else        //cos fi inst capacitivo
				{
					FLAG_HAB_CONTADOR_AL_FP_FORA_temp=1;
				}
				break;
			}
		case 2:
			{             //CF_sup � negativo..
				if (FatPotT>0)  //cos fi inst. indutivo
				{
					if (FatPotT<CF_al_inf) { FLAG_HAB_CONTADOR_AL_FP_FORA_temp=1;}
				}
				else        //cos fi inst capacitivo
				{
					if (FatPotT>CF_al_sup) { FLAG_HAB_CONTADOR_AL_FP_FORA_temp=1;}
				}
				break;
			}

		case 3:
			{
				if (FatPotT>0) //cos fi inst. indutivo
				{
					FLAG_HAB_CONTADOR_AL_FP_FORA_temp=1;
				}
				else        //cos fi inst capacitivo
				{
					if (FatPotT>CF_al_sup) { FLAG_HAB_CONTADOR_AL_FP_FORA_temp=1;}
					if (FatPotT<CF_al_inf) { FLAG_HAB_CONTADOR_AL_FP_FORA_temp=1;}
				}
				break;
			}
	}

	//if (Qt==0) {FLAG_FP_FORA=0; TendCmais=0; TendCmenos=0; FLAG_DESLIGATODOS=1;} //APOS DELIGAR TUDO, ZERAR A FLAG_DESLIGATODOS!!!


	//atualiza��o da habilita��o dos contadores, para sinalizacao dos alarmes

	FLAG_HAB_CONTADOR_AL_FP_FORA=FLAG_AL_FP_FORA; //modificada em 03/10/06
	FLAG_HAB_CONTADOR_FP_FORA=FLAG_FP_FORA;

	FLAG_HAB_CONTADOR_AL_FP_FORA=FLAG_HAB_CONTADOR_AL_FP_FORA_temp;
	if (StatusFuncaoFinal[22]!=3) {FLAG_HAB_CONTADOR_I_FORA  = FLAG_I_FORA;} else {FLAG_HAB_CONTADOR_I_FORA=0; 	FLAG_I_FORA=0;}
	if (StatusFuncaoFinal[24]!=3) {FLAG_HAB_CONTADOR_V_FORA  = FLAG_V_FORA;} else {FLAG_HAB_CONTADOR_V_FORA=0; 	FLAG_V_FORA=0;}
	if (StatusFuncaoFinal[26]!=3) {FLAG_HAB_CONTADOR_DHT_FORA= FLAG_DHT_FORA;} else {FLAG_HAB_CONTADOR_DHT_FORA=0; FLAG_DHT_FORA=0;}


	if (FLAG_Ct_CAPACITIVO)
	{
		if (FLAG_BLOQUEIOCAPACITIVO)
		{
			FLAG_DESLIGATODOS=1;

			Sys_EfetuaComando(); //antes estava antes do calculo de grandezas...
			contador2segundos=0;
			controleManualHabilitado=SIM;

		}
	}



	if (FLAG_FP_FORA==0) //e se o outros alarmes estiverem ativados???
	{
		//   Sys_ProgramaAlvo(Bancos.StatusAtual);
		//   Comando=NAO_ALTERA;
		contadorFPfora=0;
		TendCmais=0; TendCmenos=0;
		//   PiscarSimboloAlarme=0;
		//   Latch2=Latch2&(~Alarme);  //desliga o rele do alarme!
	}

	/* COMENTADO POR CESAR
	   if (FLAG_I_FORA==1) //se estamos sem corrente... desligamos tudo...
	   {
	   FLAG_DESLIGATODOS=1;
	   contadorFPfora=0;
	   TendCmais=0; TendCmenos=0;
	   } */


}


/*-----------------------------------------------------------------------*/
/*-------      CONTROLE!   ----------------------------------------------*/
/*-----------------------------------------------------------------------*/
void Cal_CalControleCM4020m()
{
	float Prede;
	float Qrede;
	float QredeSemNenhumBanco; //� o que o CM4020 mediria na rede, sem o efeito de nenhum banco ligado
	unsigned char COMBINACAO_ENCONTRADA;

	naodapracorregirJaTentei=0;

	if (FatPotT<0) {FLAG_Ct_CAPACITIVO=1;} else {FLAG_Ct_CAPACITIVO=0;}

	Sys_AtualizaValorDosBancos();

	if (TendCmais==1) {TendenciaCalculada=MAIS_BANCOS;}
	if (TendCmenos==1) {TendenciaCalculada=MENOS_BANCOS;}

	if ((TendCmais==1)&&(Bancos.StatusAtual==(0xFFF&(~ZeroKVAr))))
	{//se a tendencia � ligar tudo, e ja esta tudo o que da ligado...
		Sys_MudaEstadoDoAlarme(3);//em teste no CM4040, comentado por cesar
		naodapracorregir=1;
		naodapracorregirJaTentei=1;
		Cal_ZeraAcumulos();
		contadorFPfora=0;
	}
	else
	{

		if ((FLAG_Ct_CAPACITIVO==1)&&(TendCmenos==1)&&(fabs(FatPotT)<0.75))
		{
			//se a tendencia � desligar tudo, e Fp e cap. acima de um ponto, delig tudo rapido
			FLAG_DESLIGATODOS=1;
			naodapracorregir=1;
			Cal_ZeraAcumulos();
			contadorFPfora=0;
		}
		else
		{
			Qrede=(Qacumulada/(float)nPontos);
			QredeSemNenhumBanco=Qrede+Q_controlador; // QredeSemNenhumBanco=Qrede+al_BancoKVARtoRealWorld(Bancos.Valor);
			Prede=(Pacumulada/(float)nPontos);
			Qn1=QredeSemNenhumBanco-Prede*tan(acos(CF_sup));   //tan(acos(FP_SUPERIOR))=0.291666  //Pot reativa que a rede deve ter para alcancar 0.96
			Qn2=QredeSemNenhumBanco-Prede*tan(acos(CF_inf));   //tan(acos(FP_INFERIOR))=0.425998  //Pot reativa que a rede deve ter para alcancar 0.92
			COMBINACAO_ENCONTRADA=Cal_EncontraCombinacao();
			if (COMBINACAO_ENCONTRADA==ON)
			{
				/********************************************************************/
				/*   Se entramos aqui, � porque e encontramos solucao pra faixa     */
				/********************************************************************/
				Sys_ProgramaAlvo(CombinacaoOtima);
				Cal_VerifiaRodizio();
				contadorFPfora=0;    //obrigatoriamente o controle s� � efetuado a cada Td
				Cal_ZeraAcumulos();  //sempre apos o controle, zeramos os acumulos...
				Comando=CONTROLE_NORMAL;
				naodapracorregir=0;
			}
			else
			{
				naodapracorregir=1;
				/*******************************************************************
				  Se entramos aqui, � porque e nao encontramos solucao pra faixa
				  vamos criar outra faixa ainda admissivel..., proximo ao FP unitario
				 *******************************************************************/
				Qn1=QredeSemNenhumBanco-Prede*tan(acos(0.99));
				Qn2=Q_controlador+300.0;
				if (TendCmenos==1)
				{
					Qn2=Q_controlador-300.0;
				}

				COMBINACAO_ENCONTRADA=Cal_EncontraCombinacao();
				if (COMBINACAO_ENCONTRADA==ON)
				{
					Sys_ProgramaAlvo(CombinacaoOtima);
					Cal_VerifiaRodizio();
					//Sys_MudaEstadoDoAlarme(3);//em teste no CM4040, comentado por cesar
					//testezinho contadorFPfora=(unsigned short)0.95*Td;	 		   
					Cal_ZeraAcumulos();  //sempre apos o controle, zeramos os acumulos...
					Comando=CONTROLE_NORMAL;
				}
				else
				{
					/*******************************************************************
					  Se entramos aqui, � porque e nao encontramos solucao pra faixa nem
					  para a faixa acima criada, agora  pelo menos vamos ver se conseguimos pelo
					  menos aproximar um pouquinho o FP da unidade...
					 *******************************************************************/
					Qn1=QredeSemNenhumBanco-Prede*tan(acos(CF_sup));
					Qn2=Q_controlador+300.0;
					if (TendCmenos==1)
					{
						Qn2=Q_controlador-300.0;
					}

					COMBINACAO_ENCONTRADA=Cal_EncontraCombinacao();

					//ativa o alarme por fator de potencia!!
					//Sys_MudaEstadoDoAlarme(3);//em teste no CM4040, comentado por cesar

					if (COMBINACAO_ENCONTRADA==ON)
					{
						Sys_ProgramaAlvo(CombinacaoOtima);
						Cal_VerifiaRodizio();
						//Sys_MudaEstadoDoAlarme(3);//em teste no CM4040, comentado por cesar
						//testezinho contadorFPfora=(unsigned short)0.95*Td;
						Cal_ZeraAcumulos();  //sempre apos o controle, zeramos os acumulos...
						Comando=CONTROLE_NORMAL;
					}
					else
					{
						//ativa o alarme por fator de potencia!!
						//Sys_MudaEstadoDoAlarme(3);//em teste no CM4040, comentado por cesar

						if (nPontos>10)
						{
							Cal_ZeraAcumulos();  //sempre apos o controle, zeramos os acumulos...
						}

						if (CF_sup>0) //se o limite superior � positivo
						{
							if (FLAG_Ct_CAPACITIVO==1) //se o coseno fi � negativo
							{
								//aqui vamos deligar o menor banco ligado
								Sys_ProgramaAlvo(0);
								Cal_VerifiaRodizio();
								Cal_OFFmenor();
								Sys_ProgramaAlvo(Bancos.StatusAtual);
							}
						}
					}
				}
			}
		}
	}
}//da rotina...


/*-----------------------------------------------------------------------*/
unsigned char Cal_EncontraCombinacao()
{
	unsigned short i;
	unsigned char NchaveamentoOtimo;
	float acumul,QnProximoDeQn1,QnProximoDeQn2;
	unsigned char COMBINACAO_ENCONTRADA=OFF;

	if (Qn1<0) {Qn1=0;}
	if (Qn2<=0) {
		Qn2=0;
		if (Qn1==0)
		{
			COMBINACAO_ENCONTRADA=ON;
			CombinacaoOtima=0;
			return(COMBINACAO_ENCONTRADA);
		}
		else
		{
			if (TendCmais==1)
			{
				naodapracorregir=1;
			}
		}
	}

	if (Qn1<Qn2) {acumul=Qn1; Qn1=Qn2; Qn2=acumul;} //Qn1 sempre deve ser maior que Qn2
	acumul=0;

	if (naodapracorregir==0)
	{
		if (TendCmais==1)
		{
			if (Q_controlador>Qn2)
			{
				if (Q_controlador<Qn1)
				{
					Qn2=Q_controlador;
					naodapracorregir=1;
				}
			}
		}
	}
	else
	{
		if (TendCmais==1)
		{
			if (Qn1>Cal_BancoKVARtoRealWorld(tabela[0x0FFF].KVAr))
			{
				COMBINACAO_ENCONTRADA=ON;
				CombinacaoOtima=0xFFF&(~ZeroKVAr);
				return(COMBINACAO_ENCONTRADA);
			}
		}
	}

	for (i=0;i<=0xFFF;i++)
	{


		if (programando==1) { COMBINACAO_ENCONTRADA=OFF; break;}

		if ((ZeroKVAr&i)==0) //se na combincao nao existe bancos zerados...
		{
			acumul=Cal_BancoKVARtoRealWorld(tabela[i].KVAr);

			if (acumul>Qn2)
			{
				if (acumul<=Qn1)
				{
					if (COMBINACAO_ENCONTRADA==OFF)
					{
						QnProximoDeQn2=acumul;
						QnProximoDeQn1=acumul;
						CombinacaoOtima=i;
						NchaveamentoOtimo=Cal_CalcChaveamentos(CombinacaoOtima);
						if (tabela[CombinacaoOtima].KVAr!=tabela[Bancos.StatusAtual].KVAr)
						{
							if (acumul!=Q_controlador) {COMBINACAO_ENCONTRADA=ON;}
						}
					}
					else
					{
						if (naodapracorregir==1)
						{
							if (FatPotT>0)
							{
								if (QnProximoDeQn1<acumul)
								{
									QnProximoDeQn1=acumul;
									CombinacaoOtima=i;
									NchaveamentoOtimo=Cal_CalcChaveamentos(CombinacaoOtima);
								}
								if (QnProximoDeQn1==acumul)
								{
									if (NchaveamentoOtimo>Cal_CalcChaveamentos(i))
									{
										CombinacaoOtima=i;
										NchaveamentoOtimo=Cal_CalcChaveamentos(CombinacaoOtima);
									}
								}
							}
							else //se CF capacitivo...
							{
								if (QnProximoDeQn2>acumul)
								{
									QnProximoDeQn2=acumul;
									CombinacaoOtima=i;
									NchaveamentoOtimo=Cal_CalcChaveamentos(CombinacaoOtima);
								}
								if (QnProximoDeQn2==acumul)
								{
									if (NchaveamentoOtimo>Cal_CalcChaveamentos(i))
									{
										CombinacaoOtima=i;
										NchaveamentoOtimo=Cal_CalcChaveamentos(CombinacaoOtima);
									}
								}
							}

						}
						else
						{
							if (Cal_CalcChaveamentos(i)<NchaveamentoOtimo)
							{
								NchaveamentoOtimo=Cal_CalcChaveamentos(i);
								CombinacaoOtima=i;
							}
						}
					}
				}
			}
		} //do if zero.
	}   //do for


	//verificacao final
	/* if (Cal_BancoKVARtoRealWorld(tabela[CombinacaoOtima].KVAr)==Q_controlador)
	   {
	   COMBINACAO_ENCONTRADA=OFF;
	   }
	   if (tabela[CombinacaoOtima].KVAr==tabela[Bancos.StatusAtual].KVAr)
	   {
	   COMBINACAO_ENCONTRADA=OFF;
	   }
	 */


	return (COMBINACAO_ENCONTRADA);

} //da rotina
//no caso de de modo=1por vez: (o quem sabe sempre...)
//se tiver C+: Tira o menor KVAr e no mesmo instante coloca o de maior KVAr
//se tiver C-: Tira o maior KVAr e no mesmo instante coloca o de menor KVAr

/*-----------------------------------------------------------------------*/

/*************************UTILITARIOS*************************************/

float Cal_DigitalWorldToRealWord_P(float flo)
{
#ifndef FRANK
#define const_p (float)(Smax3f*2/Smaxd3f)
#else
#define const_p (float)(Smax3f*fatorP/Smaxd3f)
#endif

	return(flo*relacaoTP*relacaoTC*const_p);
}
/*-----------------------------------------------------------------------*/
float Cal_DigitalWorldToRealWord_I(float flo)
{
#ifndef FRANK
#define const_i (float)(Imax*2/Imaxd)
#else
#define const_i (float)(Imax*fatorI/Imaxd)
#endif

	return(flo*relacaoTC*const_i);
}
/*-----------------------------------------------------------------------*/
float Cal_DigitalWorldToRealWord_V(float flo)
{
#ifndef FRANK
#define const_v (float)(Vmax*2/Vmaxd)
#else
#define const_v (float)(Vmax*fatorV/Vmaxd)
#endif



	return(flo*relacaoTP*const_v);
}


/*-----------------------------------------------------------------------*/
void Cal_LongIntToFloat(float *f,long int i,char m)
{
	unsigned char x;
	float fa=1;
	for (x=1;x<=m;x++)
	{
		fa=(float)fa*1000;
	}
	*f=(float)fa*i;
}

unsigned char Cal_CalcChaveamentos(unsigned short Statusfinal)
{
	//esta rotina devolve o numero de chaveamentos que sao realizados
	//para partir de uma estado dos bancos para outro definido por "Statusfinal"
	//o resultado varia de 0 a 12.
	return(Cal_ContaUns(Cal_Xor(Bancos.StatusAtual,Statusfinal)));
}
/*-----------------------------------------------------------------------*/

unsigned short Cal_Xor(unsigned short in1,unsigned short in2)
{
	return(((~in1)&in2)|(in1&(~in2)));
}

/*-----------------------------------------------------------------------
  ROTINAS ESPECIFICAS PARA ROTA�AO DE ESTAGIOS,
  -----------------------------------------------------------------------*/
void Cal_VerifiaRodizio() //aqui decido qual do rodizio devo selecionar...
{
	unsigned short t;
	unsigned char mudou=OFF;
	unsigned short BancosIguaisAtual,BancosIguaisAlvo,BancosIguaisAtualOutrosAlvo;
	unsigned char nAlvo,nAtual,i;

	t=Bancos.StatusAlvo; //guardo num lugar seguro...

	BancosIguaisAtual= Bancos.StatusAtual&BancosIguais;
	BancosIguaisAlvo=  Bancos.StatusAlvo &BancosIguais;
	nAlvo=Cal_ContaUns(BancosIguaisAlvo);
	nAtual=Cal_ContaUns(BancosIguaisAtual);

	BancosIguaisAtualOutrosAlvo=((Bancos.StatusAlvo&(~BancosIguais))|BancosIguaisAtual)&0xFFF;

	if (nAtual>nAlvo) //existe desligamento
	{
		mudou=ON;
		for (i=1;i<=(nAtual-nAlvo);i++)
		{
			ponteiroDeOFFs++;
			if (ponteiroDeOFFs>NumeroBancosIguais)
			{
				ponteiroDeOFFs=1;
			}
			Bancos.StatusAlvo=~VetorBancosIguais[ponteiroDeOFFs];
			Bancos.StatusAlvo=(BancosIguaisAtualOutrosAlvo&Bancos.StatusAlvo)&0xFFF;
			BancosIguaisAtualOutrosAlvo=Bancos.StatusAlvo;
		}
	}
	if (nAtual<nAlvo) //existe ligamento
	{
		mudou=ON;
		for (i=1;i<=(nAlvo-nAtual);i++)
		{
			ponteiroDeONs++;
			if (ponteiroDeONs>NumeroBancosIguais)
			{
				ponteiroDeONs=1;
			}
			Bancos.StatusAlvo=BancosIguaisAtualOutrosAlvo|(VetorBancosIguais[ponteiroDeONs]);
			BancosIguaisAtualOutrosAlvo=Bancos.StatusAlvo;
		}
	}

	//teste de consistencia
	if (mudou==ON)
	{
		if (Cal_ContaUns(t)!=Cal_ContaUns(Bancos.StatusAlvo))
		{
			Bancos.StatusAlvo=t;
		}
	}


}


/*-----------------------------------------------------------------------*/
void Cal_CalcRmsI(float *val1 ,long int val2)
{
	float tempfloat;
	Cal_LongIntToFloat(&tempfloat,val2,0);
	*val1=Cal_DigitalWorldToRealWord_I(sqrt((float)(tempfloat)/nAMOSTRAS));
}
/*-----------------------------------------------------------------------*/
void Cal_CalcRmsV(float *val1 ,long int val2)
{
	float tempfloat;
	Cal_LongIntToFloat(&tempfloat,val2,0);
	*val1=Cal_DigitalWorldToRealWord_V(sqrt((float)(tempfloat)/nAMOSTRAS));
}


/*-----------------------------------------------------------------------*/
void Cal_TestFaltaCorrente()
{
	FLAG_I_FORA=0;
	SemCorr=0;
	if (HabCapator==ON){
		if ((IrmsA/relacaoTC)<0.10) {FLAG_I_FORA=1; Cal_ZeraGrandezas(1); FLAG_TCA_INVERTIDO=0; IrmsA=0; SemCorr=0x1;         DhtIA=0;}
		if ((IrmsB/relacaoTC)<0.10) {FLAG_I_FORA=1; Cal_ZeraGrandezas(2); FLAG_TCB_INVERTIDO=0; IrmsB=0; SemCorr=0x2|SemCorr; DhtIB=0;}
		if ((IrmsC/relacaoTC)<0.10) {FLAG_I_FORA=1; Cal_ZeraGrandezas(3); FLAG_TCC_INVERTIDO=0; IrmsC=0; SemCorr=0x4|SemCorr; DhtIC=0;}
		/*se os FP das 3 fases s�o iguais a 1, logo o total tambem o ser�*/
		if (SemCorr==7) //se nao tem corrente em nenhuma fase... tal vez tenha algum banco ligado... e o FP esteja baixo
		{  //mas marcando 1, nesse caso vamos a colocar o FatPotT=1 somente se Bancos.Valor=0...
			Cal_ZeraGrandezas(4);
			if (Bancos.Valor==0)
			{
				FatPotT=1; PotReatT=0;
			}
		}
	}
}

/*-----------------------------------------------------------------------*/
void Cal_TestFaltaTensao()
{
	FLAG_V_FORA=0;
	if (HabCapator==ON){
		if ((float)(UrmsA/relacaoTP)<20.0) { Cal_ZeraGrandezas(1); UrmsA=0; DhtUA=0; }
		if (UrmsA<Vlim_inf) {FLAG_V_FORA=1;}
		if (UrmsA>Vlim_sup) {FLAG_V_FORA=1;}
		if ((float)(UrmsB/relacaoTP)<20.0) { Cal_ZeraGrandezas(2); UrmsB=0; DhtUB=0; }
		if (UrmsB<Vlim_inf) {FLAG_V_FORA=1;}
		if (UrmsB>Vlim_sup) {FLAG_V_FORA=1;}
		if ((float)(UrmsC/relacaoTP)<20.0) { Cal_ZeraGrandezas(3); UrmsC=0; DhtUC=0; }
		if (UrmsC<Vlim_inf) {FLAG_V_FORA=1;}
		if (UrmsC>Vlim_sup) {FLAG_V_FORA=1;}
	}
}
/*-----------------------------------------------------------------------*/
void Cal_ZeraGrandezas(char fase)
{
	if (HabCapator==ON){
		if (fase==1) {PotAtivA=0; PotReatA=0; FatPotA=1.0;}
		if (fase==2) {PotAtivB=0; PotReatB=0; FatPotB=1.0;}
		if (fase==3) {PotAtivC=0; PotReatC=0; FatPotC=1.0;}
		if (fase==4) {
			PotAtivT=0; PotReatT=0; FatPotT=1.0;  
			FLAG_DESLIGATODOS=1;
			contadorFPfora=0;
			TendCmais=0; TendCmenos=0; }
	}
}



void Cal_ZeraAcumulos()
{
	// Qacumulada=0;
	// Pacumulada=0.0001;  //nao fica zerado porque, fp=atan(0/0)=#NAN
	// nPontos=0;
	Qacumulada=PotReatT;
	Pacumulada=PotAtivT;  //nao fica zerado porque, fp=atan(0/0)=#NAN
	nPontos=1;
	FLAG_LIGOU_RECENTEMENTE=1;

}
/*
   void Cal_Integra()
   {
   unsigned char i;

   Vintegrado[Indice]=Vrmsa;
   Iintegrado[Indice]=Irmsa;
   Vfintegrado[Indice]=VrmsaFundamental;
   Ifintegrado[Indice]=IrmsaFundamental;


//Paintegrado[Indice]=Pa;
//Qaintegrado[Indice]=Qa;
Indice++;

if (Indice>5) {Indice=1; FLAG_PODE_INTEGRAR=ON;}

if (FLAG_PODE_INTEGRAR==ON)
{
Vrmsa=0;
Irmsa=0;
VrmsaFundamental=0;
IrmsaFundamental=0;

//  Pa=0;
//  Qa=0;
for (i=1;i<=5;i++)
{
Vrmsa=Vintegrado[i]+Vrmsa;
Irmsa=Iintegrado[i]+Irmsa;
VrmsaFundamental=Vfintegrado[i]+VrmsaFundamental;
IrmsaFundamental=Ifintegrado[i]+IrmsaFundamental;
//    Pa=Paintegrado[i]+Pa;
//    Qa=Qaintegrado[i]+Qa;
}
Vrmsa=Vrmsa/5;
Irmsa=Irmsa/5;
VrmsaFundamental=VrmsaFundamental/5;
IrmsaFundamental=IrmsaFundamental/5;

//   Pa=Pa/5;
//   Qa=Qa/5;

//  if (Pa!=0)
//  {
//  CF_a=((CF_a)/fabs(CF_a))*cos(atan(Qa/Pa));
//  FatPotT=CF_a;
//  }
//  Pt=Pa*3;
//  Qt=Qa*3;
//    Cal_PreCalculos2();
}
}
 */

#endif


