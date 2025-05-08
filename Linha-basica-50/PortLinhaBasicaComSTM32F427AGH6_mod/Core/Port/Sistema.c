
#define EXT extern
#include "global.h"

#if EQUIP==CM_EQUIP
/*
   const unsigned char est_al_dht[]={1,1,1,1, 0,0,0,0, 1,1,1,1, 0,0,0,0};
   const unsigned char est_al_v[]  ={1,1,1,1, 1,1,1,1, 1,1,1,1, 0,0,0,0};
   const unsigned char est_al_i[]  ={0,0,0,0, 0,0,0,0, 0,0,1,1, 1,1,1,1};
   const unsigned char est_al_fp[] ={1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1};
   const unsigned char est_al_off[]={0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0};
 */

//atualmente para liberar o lote, fiz assim....
const unsigned char est_al_dht[]={1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1};
const unsigned char est_al_v[]  ={1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1};
const unsigned char est_al_i[]  ={1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1};
const unsigned char est_al_fp[] ={1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1};
const unsigned char est_al_off[]={1,1,1,1, 1,1,1,1, 1,1,1,1, 1,1,1,1};


void Sys_SetDefault()
{
	latch1atual=0xFF;
	latch2atual=0xFF;

#if REL_OE_EM_P1==ON   
	FIO1CLR = REL_OE; 
#else


	CLRpinoEmPorta(0,REL_OE);

#endif

	nPontos=0;
	Bancos.StatusAlvo=0x0;
	Bancos.StatusAtual=0;
	Bancos.Valor=0;
	Q_controlador=0;
	StatusAlarme=0;
	Sys_OperaSaidas();
	analizafase=0;
	FLAG_LIGOU_RECENTEMENTE=1;
	FLAG_ALTEREI_KVAR=0;
#if MD4040TI == 1
	menu_atual.prog=16;
	menu_atual.leitura=0;
#else
	menu_atual.prog=1;
	menu_atual.leitura=1;
#endif
	
	modoprog=0;
	FLAG_GERADOR=0;
	AtualizaDisplay=0;
	ConfiguracaoBancosIguais=0;
	FLAG_TC_INVERTIDO=0;
	FLAG_TCA_INVERTIDO=0;
	FLAG_TCB_INVERTIDO=0;
	FLAG_TCC_INVERTIDO=0;
	PiscarSimboloAlarme=0;
	Comando=NAO_ALTERA;
	naodapracorregir=0;
	ALTERACAO_MANUAL_FINALIZADA=1;
	ponteiroDeONs=0;
	ponteiroDeOFFs=0;
	Qn1=0; Qn2=0;
	FLAG_HORARIO_SEM_CONTROLE=OFF;
}


/********************************************************************************
Rotina: Sys_OperaSaidas()
Autor: Cesar Crovato
Comentarios: Escrevemos nos latchs de saidas e atualizamos o seu estado nas variaveis deles
Historico: Cria��o Set-2003
 ********************************************************************************/

void Sys_OperaSaidas()
{
	int i;
	union union2x {short u1int; char u1char[2];};
	union union2x union2;
	OPERANDO_SAIDAS=ON;
#ifdef SeisEstagios
	union2.u1int=(Bancos.StatusAtual<<6)|rele_alarme_ativado;
#else
	union2.u1int=(Bancos.StatusAtual|rele_alarme_ativado);
#endif

	/**********************************************************
	  ESCRITA NA PARTE BAIXA, RELES DO LATCH 1
	 **********************************************************/

#if BARRAMENTO_EM_P1==ON

	CLRpinoEmPorta(1,BARRAMENTO);
	SETpinoEmPorta(1,(union2.u1char[LSB])<<INICIO_BARRAMENTO);
#else


	CLRpinoEmPorta(2,BARRAMENTO);
	SETpinoEmPorta(2,(union2.u1char[LSB])<<INICIO_BARRAMENTO);


#endif

	if (union2.u1char[LSB]!=latch1atual)
	{
		latch1atual=union2.u1char[LSB];

#if REL1_CS_EM_P1==ON         
		FIO1SET = REL1_CS; 
#else

		SETpinoEmPorta(0,REL1_CS);
#endif
		//Aqui temos um delay para que o Latch engula os dados...
		for (i=0;i<10;i++);	 //10000 = delay 1.5ms!; 10=0.98us (aprox 1us!)	 ; sendo 'int i'
#if REL1_CS_EM_P1==ON         
		FIO1CLR = REL1_CS; 
#else
		CLRpinoEmPorta(0,REL1_CS);
#endif
	}
	/**********************************************************
	  ESCRITA NA PARTE ALTA, RELES DO LATCH 2
	 **********************************************************/

#if BARRAMENTO_EM_P1==ON
	FIO1CLR=BARRAMENTO;
	FIO1SET=((union2.u1char[MSB]))<<INICIO_BARRAMENTO;;
#else


	CLRpinoEmPorta(2,BARRAMENTO);
	SETpinoEmPorta(2,(union2.u1char[LSB])<<INICIO_BARRAMENTO);

#endif



	if (union2.u1char[MSB]!=latch2atual)
	{
		latch2atual=union2.u1char[MSB];

		//	#if REL_OE_EM_P1==ON         
		//		FIO1CLR = REL_OE; 
		//	#else
		//		FIO0CLR = REL_OE;	
		//	#endif

#if REL2_CS_EM_P1==ON         
		FIO1SET = REL2_CS; 
#else

		SETpinoEmPorta(0,REL2_CS);



#endif
		for (i=0;i<10;i++);
#if REL2_CS_EM_P1==ON         


		CLRpinoEmPorta(1,REL2_CS);

#else

		CLRpinoEmPorta(0,REL2_CS);
#endif

		//	#if REL_OE_EM_P1==ON         
		//		FIO1SET = REL_OE; 
		//	#else
		//		FIO0SET = REL_OE;	
		//	#endif

	}

	latchatual.c[MSB]=latch2atual;
	latchatual.c[LSB]=latch1atual;
	StatusDosReles=(latchatual.i&0xFFF);
	OPERANDO_SAIDAS=OFF;
	StatusAtual1=Bancos.StatusAtual;
}

void Sys_OperaSaidas1()
{
	int i;
	union union2x {short u1int; char u1char[2];};
	union union2x union2;
	OPERANDO_SAIDAS=ON;
#ifdef SeisEstagios
	union2.u1int=(StatusAtual1<<6)|rele_alarme_ativado;
#else
	union2.u1int=(StatusAtual1|rele_alarme_ativado);
#endif

	/**********************************************************
	  ESCRITA NA PARTE BAIXA, RELES DO LATCH 1
	 **********************************************************/

#if BARRAMENTO_EM_P1==ON
	FIO1CLR=BARRAMENTO;			 
	FIO1SET=(union2.u1char[LSB])<<INICIO_BARRAMENTO;;
#else

	CLRpinoEmPorta(2,BARRAMENTO);
	SETpinoEmPorta(2,(union2.u1char[LSB])<<INICIO_BARRAMENTO);

#endif

	//if (union2.u1char[LSB]!=latch1atual)
	//{
	// latch1atual=union2.u1char[LSB];

#if REL1_CS_EM_P1==ON         
	FIO1SET = REL1_CS; 
#else
	SETpinoEmPorta(0,REL1_CS);
#endif
	//Aqui temos um delay para que o Latch engula os dados...
	for (i=0;i<10;i++);	 //10000 = delay 1.5ms!; 10=0.98us (aprox 1us!)	 ; sendo 'int i'
#if REL1_CS_EM_P1==ON         
	FIO1CLR = REL1_CS; 
#else

	CLRpinoEmPorta(0,REL1_CS);
#endif
	//}
	/**********************************************************
	  ESCRITA NA PARTE ALTA, RELES DO LATCH 2
	 **********************************************************/

#if BARRAMENTO_EM_P1==ON
	FIO1CLR=BARRAMENTO;
	FIO1SET=((union2.u1char[MSB]))<<INICIO_BARRAMENTO;;
#else


	CLRpinoEmPorta(2,BARRAMENTO);
	SETpinoEmPorta(2,(union2.u1char[LSB])<<INICIO_BARRAMENTO);

#endif



	//if (union2.u1char[MSB]!=latch2atual)
	//{
	//latch2atual=union2.u1char[MSB];

	//	#if REL_OE_EM_P1==ON         
	//		FIO1CLR = REL_OE; 
	//	#else
	//		FIO0CLR = REL_OE;	
	//	#endif

#if REL2_CS_EM_P1==ON         

	CLRpinoEmPorta(1,REL2_CS);
#else
	SETpinoEmPorta(0,REL2_CS);
#endif
	for (i=0;i<10;i++);
#if REL2_CS_EM_P1==ON         
	CLRpinoEmPorta(1,REL2_CS);
#else

	CLRpinoEmPorta(0,REL2_CS);

#endif

	//	#if REL_OE_EM_P1==ON         
	//		FIO1SET = REL_OE; 
	//	#else
	//		FIO0SET = REL_OE;	
	//	#endif

	//}

	latchatual.c[MSB]=latch2atual;
	latchatual.c[LSB]=latch1atual;
	StatusDosReles=(latchatual.i&0xFFF);
	OPERANDO_SAIDAS=OFF;

}
/*-----------------------------------------------------------------------*/
void Sys_AtualizaValorDosBancos()
{
	unsigned char i;

	Bancos.Valor=0;
	for (i=1;i<=12;i++)	 
	{
		if ((Bancos.StatusAtual&(mask[i]))!=0)
		{
			Bancos.Valor=Bancos.Valor+KVAr_estagio[i];
		}
	}
	Q_controlador=Cal_BancoKVARtoRealWorld(Bancos.Valor);
}

/*-----------------------------------------------------------------------*/
void Sys_ProgramaAlvo(unsigned short valor)
{
	Bancos.StatusAlvo=valor;
}
/*-----------------------------------------------------------------------*/
void Sys_Delay200Ms()
{
	unsigned char i;

	for (i=1;i<=150;i++)
		Atraso(t1Mili);
}
void Sys_Delay1Ms()
{
	Atraso(t1Mili);
}

/*-----------------------------------------------------------------------*/
void Sys_HexBcd(unsigned long int numero)
{
	char milhar; char centena; char dezena; char unidade;
	char dezmilesimo;char decimo; char milesimo;

	/*char unidade=0,dezena=0,centena=0,milhar=0,decimo=0,centesimo=0,milesimo=0;
	  long int centCemMil,dezDezMil,uniMil,decmCem,centmDez;

	  centena=(char)((long int)numero/100000);
	  centCemMil=(long int)centena*100000;

	  dezena=(char)((numero-centCemMil)/10000);
	  dezDezMil=(long int)dezena*10000;

	  unidade=(char)((numero-centCemMil-dezDezMil)/1000);
	  uniMil=(long int)unidade*1000;

	  decimo=(char)((numero-centCemMil-dezDezMil-uniMil)/100);
	  decmCem=(long int)decimo*100;

	  centesimo=(char)((numero-centCemMil-dezDezMil-uniMil-decmCem)/10);
	  centmDez=(long int)centesimo*10;

	  milesimo=(char)(numero-centCemMil-dezDezMil-uniMil-decmCem-centmDez);

	  Z[3]=milhar;
	  Z[2]=dezena|(centena<<4);
	  Z[1]=decimo|(unidade<<4);
	  Z[0]=milesimo|(centesimo<<4);
	 */


	milhar=  (char)((float)(numero/1000000));
	centena= (char)((float)(numero-(float)milhar*1000000)/100000);
	dezena=  (char)((float)(numero-(float)milhar*1000000-(float)centena*100000)/10000);
	unidade= (char)((float)(numero-(float)milhar*1000000-(float)centena*100000-(float)dezena*10000)/1000);
	decimo=  (char)((float)(numero-(float)milhar*1000000-(float)centena*100000-(float)dezena*10000-(float)unidade*1000)/100);
	milesimo=(char)((float)(numero-(float)milhar*1000000-(float)centena*100000-(float)dezena*10000-(float)unidade*1000-(float)decimo*100)/10);
	dezmilesimo=(char)((float)(numero-(float)milhar*1000000-(float)centena*100000-(float)dezena*10000-(float)unidade*1000-(float)decimo*100-(float)milesimo*10));

	Zaz[3]=milhar;
	Zaz[2]=dezena|(centena<<4);
	Zaz[1]=decimo|(unidade<<4);
	Zaz[0]=dezmilesimo|(milesimo<<4);
}

/*-----------------------------------------------------------------------*/
void Sys_ModoDeOperacao(unsigned char modo,unsigned char alarme)
{
	switch(modo)
	{
		case 1:  //so alarme (SIM alarme)
			{
				Sys_MudaEstadoDoAlarme(alarme); //do RELE de Alarme
				break;
			}
		case 2:  //desl banco
			{
				Sys_MudaEstadoDoAlarme(alarme); //do RELE de Alarme
				FLAG_DESLIGATODOS=1;
				break;
			}
		case 3: //nao atua
			{PiscarSimboloAlarme=0; break;}	 
	}
}
/*-----------------------------------------------------------------------*/
void Sys_MudaEstadoDoAlarme(unsigned char alarme)
{
	short StatusDosRelestemp;
#define AL_FP   0x8000
#define AL_V    0x4000
#define AL_I   	0x2000
#define AL_DHT  0x1000
	StatusAlarme++;	 //a variavel StatusAlarme, indica em que posicao
	//dos arrays estamos. Que arrays? R: est_al_xxx[]

	PiscarSimboloAlarme=0;
	if (StatusAlarme==16) {StatusAlarme=0;}

	latchatual.c[MSB]=latch2atual;
	latchatual.c[LSB]=latch1atual;

	StatusDosRelestemp=(latchatual.i&0xFFF);

	/*
StatusDosReles:	 ( somente leitura )
x  x  x  x - FFF(12 reles)
|  |  |	 |  
|  |  |	 |  
|  |  |	 |_________________________Alarme DHTv
|  |  |____________________________Alarme I
|__________________________________Alarme V
|__________________________________Alarme fp
	 */



	switch(alarme)
	{
		case 0:
			{
				if (est_al_dht[StatusAlarme]==1) {		
					// EscreveReles(latchatual.i|MascaraAlarme);
					StatusDosRelestemp=(latchatual.i&0xFFF)|AL_DHT;
					PiscarSimboloAlarme=1;		 
				}
				else
				{
					//    EscreveReles(latchatual.i);		
				}
				break;
			}
		case 1:
			{
				if (est_al_v[StatusAlarme]==1) {
					// EscreveReles(latchatual.i|MascaraAlarme);
					StatusDosRelestemp=(latchatual.i&0xFFF)|AL_V;
					PiscarSimboloAlarme=1;		 
				}
				else
				{
					//   EscreveReles(latchatual.i);		
				}
				break;
			}
		case 2:
			{
				if (est_al_i[StatusAlarme]==1) {
					// EscreveReles(latchatual.i|MascaraAlarme);
					StatusDosRelestemp=(latchatual.i&0xFFF)|AL_I;
					PiscarSimboloAlarme=1;		 
				}
				else
				{
					//        EscreveReles(latchatual.i);		
				}
				break;
			}
		case 3:
			{
				// EscreveReles(latchatual.i|MascaraAlarme);
				StatusDosRelestemp=(latchatual.i&0xFFF)|AL_FP;
				PiscarSimboloAlarme=1;		 
				/*	if (est_al_fp[StatusAlarme]==1) {
					EscreveReles(latchatual.i|MascaraAlarme);
					PiscarSimboloAlarme=1;		 
					}
					else
					{
					EscreveReles(latchatual.i);		
					} 
					break;*/
			}
	}
	StatusDosReles = StatusDosRelestemp;
	StatusDosRelesToMM = StatusDosReles;
	if (PiscarSimboloAlarme==1) {AtualizaDisplay=1;}


	// Sys_EfetuaComando(); //antes estava antes do calculo de grandezas...
	// contador2segundos=0;

}
/*-----------------------------------------------------------------------*/

void Sys_AlarmeVerificacao()
{
	PiscarSimboloAlarme=0;

	if (contadorDHTfora>Talarme)   //mais alta prioridade no alarme
	{
		Sys_ModoDeOperacao(modo_de_operacao_AL_DHT,0);

		return;
	}

	if (contadorVfora>Talarme)
	{
		Sys_ModoDeOperacao(modo_de_operacao_AL_TENS,1);

		return;
	}

	if (contadorIfora>Talarme)
	{
		Sys_ModoDeOperacao(modo_de_operacao_AL_CORR,2);

		return;
	}

	if (contadorALFPfora>Talarme)
	{
		Sys_MudaEstadoDoAlarme(3);
	}

	if (naodapracorregirJaTentei==1)
	{
		Sys_MudaEstadoDoAlarme(3);
	}
}

void Sys_VericaHorario()
{
	//convertemos o tempo de agora em minutos, e vemos se estamos 
	//no intervalo de nao-controle.
//	unsigned short HoraMSB,HoraLSB,MinMSB,MinLSB;
	unsigned int Tinicio,Tfim,Tagora;
	RTCTime LocalTime;

	Tinicio=((HorarioSemAtuarInicio>>8)&0xFF)*60+(HorarioSemAtuarInicio&0xFF);
	Tfim   =((HorarioSemAtuarFim>>8)&0xFF)*60+(HorarioSemAtuarFim&0xFF);

	//HorarioSemAtuarInicio=((short)StatusFuncaoFinal[47]<<8)|StatusFuncaoFinal[46]	;
	//HorarioSemAtuarFim=   ((short)StatusFuncaoFinal[49]<<8)|StatusFuncaoFinal[48]	;

	FLAG_HORARIO_SEM_CONTROLE=OFF;

	LocalTime=RTCGetTime(); 

	Tagora=LocalTime.RTC_Hour*60+LocalTime.RTC_Min;

	if (Tfim<Tinicio)  //ex. 23:30=inicio, 06:00=fim 
	{//atravesa 2 dias...
		if ((Tagora>=Tinicio)||(Tagora<=Tfim))
		{
			FLAG_HORARIO_SEM_CONTROLE=ON;
			//FLAG_DESLIGATODOS=1; 
		}
	}
	else  			    //ex. 00:00=inicio, 06:30=fim
	{//num mesmo dia
		if ((Tagora>=Tinicio)&&(Tagora<=Tfim))
		{
			FLAG_HORARIO_SEM_CONTROLE=ON;
			//FLAG_DESLIGATODOS=1; 
		}
	}


}

//*************************************************************************
//  Rotinas do Saidas tipos Rel�s, LEDs
//**************************************************************************/
void Sys_EfetuaComando()
{

	if ((FLAG_DESLIGATODOS==1)||(FLAG_HORARIO_SEM_CONTROLE==1)) 
	{
		Sys_ProgramaAlvo(0); 
		Cal_VerifiaRodizio(); 
		Comando=DESLIGA_TODOS;
	}
	if (Bancos.StatusAtual==0) {FLAG_DESLIGATODOS=0; }
	if ((Comando!=OPERA_MANUAL)&&(Comando!=DESLIGA_TODOS))
	{
		if (Bancos.StatusAtual==Bancos.StatusAlvo) {Comando=NAO_ALTERA;}

		if  (TendCmais==0)
		{
			if  (TendCmenos==0)
			{
				Comando=NAO_ALTERA;
				Sys_ProgramaAlvo(Bancos.StatusAtual); //se durante o percurso entramos na faixa, nao vamos mexer mais...
			}
		}

		if  (TendCmais==1)
		{
			if (TendenciaCalculada==MENOS_BANCOS)
			{
				Comando=NAO_ALTERA;
				Sys_ProgramaAlvo(Bancos.StatusAtual);
				TendenciaCalculada=NAO_DEFINIDA;
			}
		}
		if  (TendCmenos==1)
		{
			if (TendenciaCalculada==MAIS_BANCOS)
			{
				Comando=NAO_ALTERA;
				Sys_ProgramaAlvo(Bancos.StatusAtual);
				TendenciaCalculada=NAO_DEFINIDA;
			}
		}


	}

	switch(Comando)
	{
		case CONTROLE_NORMAL:
			{
				if  (TendCmais==1)
				{
					Cal_ONmaior();
					Cal_OFFmenor();
					if (FLAG_MODO_ACCIONA_TODOS==0) //se estamos no modo 1 por vez.. devemos
					{
						contadorFPfora=0;
						Sys_ProgramaAlvo(Bancos.StatusAtual);
					}
				}

				if  (TendCmenos==1)
				{
					Cal_ONmenor();
					Cal_OFFmaior();
					if (FLAG_MODO_ACCIONA_TODOS==0) //se estamos no modo 1 por vez.. devemos
					{
						contadorFPfora=0;
						Sys_ProgramaAlvo(Bancos.StatusAtual);
					}
				}


				break;

			}
		case OPERA_MANUAL:
			//  case DESLIGA_TODOS:
			{
				Cal_ONmaior();
				Cal_OFFmaior();
				//           if (FLAG_MODO_ACCIONA_TODOS==0) //se estamos no modo 1 por vez.. devemos
				//           {
				//            contadorFPfora=0;
				//            Sys_ProgramaAlvo(Bancos.StatusAtual);
				//           }
				break;
			}

		case DESLIGA_TODOS:
			{

				Cal_OFFmaior();
				/*	    Cal_OFFmaior();
						Cal_OFFmaior();
						Cal_OFFmaior();
						Cal_OFFmaior();
						Cal_OFFmaior();
						Cal_OFFmaior();
						Cal_OFFmaior();
						Cal_OFFmaior();
						Cal_OFFmaior();
						Cal_OFFmaior();
						Cal_OFFmaior();
						EscreveReles(0x0000); */

				break;
			}

		case NAO_ALTERA:
			{

				break;
			}
	}

	Sys_OperaSaidas(); //necessario colocar por causa dos alarmes, e outros pinos do latch
}

void Cal_ONmenor()
{
	unsigned char i;
	unsigned char iMenor;
	unsigned char kvarMenor;
	unsigned char TemBancoAligar=0;
	//primeiro vamos ver se temos bancos a ligar
	//depois vamos ligar aquele que apresenta menor kvar
	for (i=1;i<=12;i++)
	{
		if ((Bancos.StatusAtual&mask[i])==0)
		{
			if ((Bancos.StatusAlvo&mask[i])==mask[i])
			{
				if (TemBancoAligar==0) {iMenor=i; kvarMenor=KVAr_estagio[i]; TemBancoAligar=1;}
				else
				{
					if (kvarMenor>KVAr_estagio[i])
					{
						kvarMenor=KVAr_estagio[i];
						iMenor=i;
					}
				}
			}
		}

	}
	if (TemBancoAligar==1) {
		Bancos.StatusAtual=(Bancos.StatusAtual|mask[iMenor]);
		Sys_AtualizaValorDosBancos();
		Sys_OperaSaidas();
		for (i=1;i<=250;i++)
			Sys_Delay1Ms();
	}

}
/*-----------------------------------------------------------------------*/

void Cal_OFFmenor()
{
	unsigned char i;
	unsigned char iMenor;
	unsigned char kvarMenor;
	unsigned char TemBancoDesligar=0;
	//primeiro vamos ver se temos bancos a desligar
	//depois vamos desligar aquele que apresenta menor kvar
	for (i=1;i<=12;i++)
	{
		if ((Bancos.StatusAtual&mask[i])==mask[i])
		{
			if ((Bancos.StatusAlvo&mask[i])==0)
			{
				if (TemBancoDesligar==0) {iMenor=i; kvarMenor=KVAr_estagio[i];  TemBancoDesligar=1;}
				else
				{
					if (kvarMenor>KVAr_estagio[i])
					{
						kvarMenor=KVAr_estagio[i];
						iMenor=i;
					}
				}
			}
		}

	}
	if (TemBancoDesligar==1) {
		Bancos.StatusAtual=((Bancos.StatusAtual&(~mask[iMenor]))&0xFFF);
		Sys_AtualizaValorDosBancos();
		Sys_OperaSaidas();
		for (i=1;i<=250;i++)
			Sys_Delay1Ms();
	}

}
/*-----------------------------------------------------------------------*/
void Cal_ONmaior()
{
	unsigned char i;
	unsigned char iMaior;
	unsigned char kvarMaior;
	unsigned char TemBancoAligar=0;
	//primeiro vamos ver se temos bancos a ligar
	//depois vamos ligar aquele que apresenta maior kvar
	for (i=1;i<=12;i++)
	{
		if ((Bancos.StatusAtual&mask[i])==0)
		{
			if ((Bancos.StatusAlvo&mask[i])==mask[i])
			{
				if (TemBancoAligar==0) {iMaior=i; kvarMaior=KVAr_estagio[i]; TemBancoAligar=1;}
				else
				{
					if (kvarMaior<KVAr_estagio[i])
					{
						kvarMaior=KVAr_estagio[i];
						iMaior=i;
					}
				}
			}
		}

	}
	if (TemBancoAligar==1) {
		Bancos.StatusAtual=(Bancos.StatusAtual|(mask[iMaior]));
		Sys_AtualizaValorDosBancos();
		Sys_OperaSaidas();
		for (i=1;i<=250;i++)
			Sys_Delay1Ms(); //gui30/06
	}
}
/*-----------------------------------------------------------------------*/
void Cal_OFFmaior()
{
	unsigned char i;
	unsigned char iMaior;
	unsigned char kvarMaior;
	unsigned char TemBancoDesligar=0;
	//primeiro vamos ver se temos bancos a desligar
	//depois vamos desligar aquele que apresenta maior kvar


	for (i=1;i<=12;i++)
	{
		if ((Bancos.StatusAtual&mask[i])==mask[i])
		{
			if ((Bancos.StatusAlvo&mask[i])==0)
			{
				if (TemBancoDesligar==0) {iMaior=i; kvarMaior=KVAr_estagio[i];  TemBancoDesligar=1;}
				else
				{
					if (kvarMaior<KVAr_estagio[i])
					{
						kvarMaior=KVAr_estagio[i];
						iMaior=i;
					}
				}
			}
		}

	}
	if (TemBancoDesligar==1) {
		Bancos.StatusAtual=((Bancos.StatusAtual&(~mask[iMaior]))&0xFFF);
		Sys_AtualizaValorDosBancos();
		//Bancos.Valor=Bancos.Valor-KVAr_estagio[iMaior];
		//Q_controlador=Cal_BancoKVARtoRealWorld(Bancos.Valor);
		Sys_OperaSaidas();
		for (i=1;i<=250;i++)
			Sys_Delay1Ms(); //gui30/06 
	}



}

#endif


