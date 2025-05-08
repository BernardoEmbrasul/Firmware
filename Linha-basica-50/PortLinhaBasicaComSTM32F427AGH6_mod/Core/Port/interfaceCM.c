#define EXT extern
#include "global.h"


#if EQUIP==CM_EQUIP
void FloatToStrForEnergy1(float numero, char *str);

const unsigned char valorTD00[]        = { " 5" } ;
const unsigned char valorTD01[]        = { "10" } ;
const unsigned char valorTD02[]        = { "15" } ;
const unsigned char valorTD03[]        = { "20" } ;
const unsigned char valorTD04[]        = { "30" } ;
const unsigned char valorTD05[]      	= { "40" } ;
const unsigned char valorTD06[]      	= { "50" } ;
const unsigned char valorTD07[]      	= { " 1"  } ;
const unsigned char valorTD08[]      	= { " 2" } ;
const unsigned char valorTD09[]      	= { " 3" } ;
const unsigned char valorTD10[]      	= { " 4" } ;
const unsigned char valorTD11[]      	= { " 5" } ;
const unsigned char valorTD12[]      	= { "10" } ;
const unsigned int  tab_valorTD[]    	= {5,10,15,20,30,40,50,60,120,180,240,300,600};
const unsigned char valorKVAr00[]    	= { "000.0" } ;
const unsigned char valorKVAr01[]    	= { "00.33" } ;
const unsigned char valorKVAr02[]    	= { "000.5" } ;
const unsigned char valorKVAr03[]    	= { "00.83" } ;
const unsigned char valorKVAr04[]    	= { "001.0" } ;
const unsigned char valorKVAr05[]    	= { "001.5" } ;
const unsigned char valorKVAr06[]    	= { "002.0" } ;
const unsigned char valorKVAr07[]    	= { "002.5" } ;
const unsigned char valorKVAr08[]    	= { "005.0" } ;
const unsigned char valorKVAr09[]    	= { "007.5" } ;
const unsigned char valorKVAr10[]    	= { "010.0" } ;
const unsigned char valorKVAr11[]    	= { "012.5" } ;
const unsigned char valorKVAr12[]    	= { "015.0" } ;
const unsigned char valorKVAr13[]    	= { "017.5" } ;
const unsigned char valorKVAr14[]    	= { "020.0" } ;
const unsigned char valorKVAr15[]    	= { "022.5" } ;
const unsigned char valorKVAr16[]    	= { "025.0" } ;
const unsigned char valorKVAr17[]    	= { "030.0" } ;
const unsigned char valorKVAr18[]    	= { "035.0" } ;
const unsigned char valorKVAr19[]    	= { "040.0" } ;
const unsigned char valorKVAr20[]    	= { "050.0" } ;
const unsigned char valorKVAr21[]    	= { "060.0" } ;
const unsigned char valorKVAr22[]    	= { "070.0" } ;
const unsigned char valorKVAr23[]    	= { "080.0" } ;
const unsigned char valorKVAr24[]    	= { "090.0" } ;
const unsigned char valorKVAr25[]    	= { "100.0" } ;
const unsigned char valorKVAr26[]    	= { "120.0" } ;
const unsigned char valorKVAr27[]    	= { "160.0" } ;
const unsigned char valorKVAr28[]    	= { "200.0" } ;
const unsigned char valorKVAr29[]    	= { "240.0" } ;
//multiplicado por 0x10
const unsigned short tab_valorKVAr[]   	= {
	0,4,6,10,12,18,24,30,60,
	90,120,150,180,210,240,270,300,360,420,480,600,720, 840, 960,
	1080,1200,1440,1920,2400,2880 } ;

#ifdef ingles
const unsigned char sTela_msg00[]    	= { "EMBRASUL FV:1.0S.NUM.:    " } ;
const unsigned char sTela_msg01[]    	= { "*** EMBRASUL ***Ind. Eletronica " } ;
const unsigned char sTela_msg02[]    	= { " ERROR IN POWER  FACTOR LIMITS. " } ;
const unsigned char sTela_msg03[]    	= { "ERROR! CONFLICTWITH CAP PROTECT." } ;
const unsigned char sTela_msg04[]    	= { "  SOFTw/HARDw   INCOMPATIBILITY!" } ;
const unsigned char sTela_msg05[]    	= { "HARDWARE ERROR!                 " } ;
const unsigned char sTela_msg06[]    	= { "  ILEGAL TP/TC    RELATIOSHIP   " } ;
const unsigned char sTela_msg07[]    	= { "  INCONSINTENT    PROGRAMATION  " } ;
const unsigned char sTela_CriandoCombinacoes[]    	= { "*** BUILDING *****COMBINATIONS** " } ;
const unsigned char sTela_msg09[]    	= { "ERRO, entrada decorr. A invertida" } ;
const unsigned char sTela_msg10[]    	= { "ERRO, entrada decorr. B invertida" } ;
const unsigned char sTela_msg11[]    	= { "ERRO, entrada decorr. C invertida" } ;

const unsigned char sTela_funcao1ao12a[] = { "  -CAPACITOR'S  " } ;
const unsigned char sTela_funcao1ao12b[] = { "POWER:      kvar" } ;
const unsigned char sTela_funcao13[]     	= { "13-PF INF. LIMIT" } ;
const unsigned char sTela_funcao14[]     	= { "14-PF SUP. LIMIT" } ;
const unsigned char sTela_funcao15a[]    	= { "15-TRIGGER TIME:" } ;
const unsigned char sTela_funcao15b[]    	= { "sec." } ;
const unsigned char sTela_funcao15c[]    	= { "min." } ;
const unsigned char sTela_funcao16[]     	= { "16-PT RATIO:    " } ;
const unsigned char sTela_funcao17[]     	= { "17-CT RATIO:    " } ;
const unsigned char sTela_funcao18[]     	= { "18-AL INF. LIMIT" } ;
const unsigned char sTela_funcao19[]     	= { "19-AL SUP. LIMIT" } ;
const unsigned char sTela_funcao20[]     	= { "20-CAP BLOKCADE " } ;
const unsigned char sTela_funcao21a[]    	= { "21-C ACTIONAMENT"};
const unsigned char sTela_funcao21b[]    	= { "ONE AT TIME     "} ;
const unsigned char sTela_funcao21c[]    	= { "ALL TOGETHER    "  } ;
const unsigned char sTela_funcao22[]     = { "22-CURRENT ALARM" };
const unsigned char sTela_funcao23[]     = { "23-VOLTAGE ALARMAT +/-" } ;
const unsigned char sTela_funcao24[]     = { "24-V ALARM MODE:" } ;
const unsigned char sTela_funcao25[]     = { "25-THD ALARM :  AT" } ;
const unsigned char sTela_funcao26[]     = { "26-THD ALRM MODE" } ;
const unsigned char sTela_funcao27[]     = { "27-ALARM TIME,  IN x(Td) " } ;
/*
   const unsigned char sTela_funcao28a[]    	= { "28-OP. MODE:    " };
   const unsigned char sTela_funcao28b[]    	= { "INST  CORRECTION" };
   const unsigned char sTela_funcao28c[]    	= { "MEDIA CORRECTION" };
 */
const unsigned char sTela_inativo[] 	  = { "INACTIVE" } ;
const unsigned char sTela_ativo[] 	  = { "ACTIVE  " } ;
const unsigned char sTela_so_alarme[]    = { " ALARM ONLY     " } ;
const unsigned char sTela_desl_banco[]   = { " CAP OFF        " } ;
const unsigned char sTela_nao_atua[]     = { " INACTIVE	 " } ;
const unsigned char sTela_funcao29[]   	= { "29-NRO NA REDE  " } ;
const unsigned char sTela_funcao30[]   	= { "30-VELOCIDADE   " } ;
const unsigned char sTela_funcao31a[]  	= { "31-PARID.STPBIT " } ;
const unsigned char sTela_funcao31b[]  	= { "SEM   2 STOP BIT" } ;
const unsigned char sTela_funcao31c[]  	= { "PAR   1 STOP BIT" } ;
const unsigned char sTela_funcao31d[]  	= { "IMPAR 1 STOP BIT" } ;
const unsigned char sTela_funcao32[]    	= { "32-MANUAL" };

#endif

#ifdef portugues
#if MODELO_DE_CONTROLADOR==CM4020
const unsigned char sTela_msg00[]    	= { "EMBRASUL  CM4040N.S.:           " } ;
#endif
#if MODELO_DE_CONTROLADOR==CM4040
	#if MD4040TI==1
			#if MD4060==1
					const unsigned char sTela_msg00[]    	= { "EMBRASUL MD4060 N.S.:           " } ;
			 #else
					const unsigned char sTela_msg00[]    	= { "EMBRASUL MD4060 N.S.:           " } ;
			 #endif


	#else
	const unsigned char sTela_msg00[]    	= { "EMBRASUL  CM4040N.S.:           " } ;
	#endif
#endif

const unsigned char sTela_msg01[]    	= { "*** EMBRASUL ***Ind. Eletronica " } ;
const unsigned char sTela_msg02[]    	= { " ERRO NOS LIM.  DO FATOR DE POT." } ;
const unsigned char sTela_msg03[]    	= { "ER! CONFLITO COM PROTEC.CAPACIT." } ;
const unsigned char sTela_msg04[]    	= { "  SOFTw/HARDw  INCOMPATIBILIDADE" } ;
const unsigned char sTela_msg05[]    	= { "ERRO DE HARDWARE!               " } ;
const unsigned char sTela_msg06[]    	= { "RELACAO TP/TC     INCORRETA     " } ;
const unsigned char sTela_msg07[]    	= { " PROGRAMA��O    INCONSINTENTE   " } ;
const unsigned char sTela_msg09[]    	= { "TC A INVERT." } ;
const unsigned char sTela_msg10[]    	= { "TC B INVERT." } ;
const unsigned char sTela_msg11[]    	= { "TC C INVERT." } ;
const unsigned char sTela_msg100[]   	= { "            " } ;
const unsigned char sTela_CriandoCombinacoes[]    	= { "*** CRIANDO *** **COMBINACOES** " } ;
//  const unsigned char sTela_msg09[]    	= { "ERRO, entrada decorr. A invertida" } ;
//  const unsigned char sTela_msg10[]    	= { "ERRO, entrada decorr. B invertida" } ;
//  const unsigned char sTela_msg11[]    	= { "ERRO, entrada decorr. C invertida" } ;

//const unsigned char sTela_funcao1ao12[]	= { "XX-CAPACITOR'S  POWER:000.00kvar" } ;

const unsigned char sTela_funcao1ao12a[] 	= { "  -POTENCIA DOS " } ;
const unsigned char sTela_funcao1ao12b[] 	= { "CAP. :      kvar" } ;
const unsigned char sTela_funcao13[]     	= { "13-LIMITE FP INF. " } ;
const unsigned char sTela_funcao14[]     	= { "14-LIMITE FP SUP. " } ;
const unsigned char sTela_funcao15a[]    	= { "15-T. DISPARO:" } ;
const unsigned char sTela_funcao15b[]    	= { "seg." } ;
const unsigned char sTela_funcao15c[]    	= { "min." } ;
const unsigned char sTela_funcao16[]     	= { "16-RELACAO TP:    " } ;
const unsigned char sTela_funcao17[]     	= { "17-RELACAO TC:    " } ;
const unsigned char sTela_funcao18[]     	= { "18-LIMITE AL INF." } ;
const unsigned char sTela_funcao19[]     	= { "19-LIMITE AL SUP." } ;
const unsigned char sTela_funcao20[]     	= { "20-BLOQUEIO CAP" } ;
const unsigned char sTela_funcao21a[]    	= { "21-MODO ACIONAMENTO "};
const unsigned char sTela_funcao21b[]    	= { "   UM POR VEZ  "} ;
const unsigned char sTela_funcao21c[]    	= { "  TODOS JUNTOS "  } ;
const unsigned char sTela_funcao22[]     	= { "22-AL. CORRENTE" };
const unsigned char sTela_funcao23[]     	= { "23-ALARME TENSAO    +/-" } ;
const unsigned char sTela_funcao24[]     	= { "24-MODO ALARME V:" } ;
const unsigned char sTela_funcao25[]    	= { "25-ALARME DHTV:      A" } ;
const unsigned char sTela_funcao26[]     	= { "26-MODO AL. DHTV: " } ;
const unsigned char sTela_funcao27[]     	= { "27-TEMPO ALARME,   EM x(Td) " } ;

const unsigned char sTela_inativo[] 	  	= { "    INATIVO     " } ;
const unsigned char sTela_ativo[] 	  	= { "     ATIVO      " } ;
const unsigned char sTela_so_alarme[]    	= { " SOMENTE ALARME " } ;
const unsigned char sTela_desl_banco[]   	= { "   DESLIGA CAP. " } ;
const unsigned char sTela_nao_atua[]     	= { " INATIVO	     " } ;
const unsigned char sTela_funcao29[]   	= { "29-NRO NA REDE  " } ;
const unsigned char sTela_funcao30[]   	= { "30-VELOCIDADE   " } ;
const unsigned char sTela_funcao31a[]  	= { "31-PARID.STPBIT " } ;
const unsigned char sTela_funcao31b[]  	= { "SEM   2 STOP BIT" } ;
const unsigned char sTela_funcao31c[]  	= { "IMPAR 1 STOP BIT" } ;
const unsigned char sTela_funcao31d[]  	= { " PAR  1 STOP BIT" } ;
const unsigned char sTela_funcao32[]    	= { "32-MANUAL" };
const unsigned char sTela_funcao33a[]    	= { "33-TIPO LIGACAO " };
const unsigned char sTela_funcao33b[]    	= { "FASE-NTRO-ESTREL" };
const unsigned char sTela_funcao33c[]    	= { "FASE-FASE-ESTREL" };
const unsigned char sTela_funcao33d[]    	= { "FASE-FASE-DELTA " };

#if (HABsangrado == 1)
const unsigned char sTela_funcao40a[]    	= { "40-DELTA SANGRAD" };
const unsigned char sTela_funcao40b[]    	= { "SIM" };
const unsigned char sTela_funcao40c[]    	= { "NAO" };
#endif //HABsangrado

#ifdef HABzeraconsumoCM
const unsigned char sTela_funcao39a[]    	= { "39-ZERAR CONSUMO" };
const unsigned char sTela_funcao39b[]    	= { "NAO" };
const unsigned char sTela_funcao39c[]    	= { "SIM" };
#endif

const unsigned char sTela_funcao42a[]    	= { "42-MEDICAO AUX " };
const unsigned char sTela_funcao42b[]    	= { "TEMP E HUMIDADE" };
const unsigned char sTela_funcao42c[]    	= { "2 TEMPERATURAS " };
const unsigned char sTela_funcao43a[]    	= { "43-TROCAR OPER." };
const unsigned char sTela_funcao43b[]    	= { "NAO" };
const unsigned char sTela_funcao43c[]    	= { "SIM" };

#endif
/*
#define ps8N2	0
#define ps8O1	1
#define ps8E1	2*/

#ifdef espanhol
const unsigned char sTela_msg00[]    	= { "EMBRASUL  CM4020N.S.:           " } ;
const unsigned char sTela_msg01[]    	= { "*** EMBRASUL ***Ind. Electronica" } ;
const unsigned char sTela_msg02[]    	= { " ERROR LIM. DE FACTOR DE POTENC." } ;
const unsigned char sTela_msg03[]    	= { "ER! CONFLICTO CON PROT. CAPACIT." } ;
const unsigned char sTela_msg04[]    	= { "  SOFTw/HARDw  INCOMPATIBILIDAD " } ;
const unsigned char sTela_msg05[]    	= { "ERROR DE HARDWARE!              " } ;
const unsigned char sTela_msg06[]    	= { "RELACION TP/TC     INCORRECTA   " } ;
const unsigned char sTela_msg07[]    	= { "PROGRAMACION    INCONSINTENTE   " } ;
const unsigned char sTela_CriandoCombinacoes[]    	= { "*** CREANDO *** **COMBINACOES** " } ;
const unsigned char sTela_funcao1ao12a[] 	= { "  -POTENCIA DE  " } ;
const unsigned char sTela_funcao1ao12b[] 	= { "CAP. :      kvar" } ;
const unsigned char sTela_funcao13[]     	= { "13-LIMITE FP INF. " } ;
const unsigned char sTela_funcao14[]     	= { "14-LIMITE FP SUP. " } ;
const unsigned char sTela_funcao15a[]    	= { "15-T. DISPARO:" } ;
const unsigned char sTela_funcao15b[]    	= { "seg." } ;
const unsigned char sTela_funcao15c[]    	= { "min." } ;
const unsigned char sTela_funcao16[]     	= { "16-RELACION TP:   " } ;
const unsigned char sTela_funcao17[]     	= { "17-RELACION TC:   " } ;
const unsigned char sTela_funcao18[]     	= { "18-LIMITE AL.INF." } ;
const unsigned char sTela_funcao19[]     	= { "19-LIMITE AL.SUP." } ;
const unsigned char sTela_funcao20[]     	= { "20-BLOQUEO  CAP" } ;
const unsigned char sTela_funcao21a[]    	= { "21-MODO ACCIONAMENTO"};
const unsigned char sTela_funcao21b[]    	= { "  UNO POR VEZ  "} ;
const unsigned char sTela_funcao21c[]    	= { "  TODOS JUNTOS "  } ;
const unsigned char sTela_funcao22[]     	= { "22-AL. CORRENTE" };
const unsigned char sTela_funcao23[]     	= { "23-ALARM TENSION    +/-" } ;
const unsigned char sTela_funcao24[]     	= { "24-MODO ALARMA V:" } ;
const unsigned char sTela_funcao25[]    	= { "25-ALARMA DHTV:      A" } ;
const unsigned char sTela_funcao26[]     	= { "26-MODO AL. DHTV: " } ;
const unsigned char sTela_funcao27[]     	= { "27-TIEMPO ALARMA,  EN x(Td) " } ;

const unsigned char sTela_inativo[] 	  	= { "   INACTIVO    " } ;
const unsigned char sTela_ativo[] 	  	= { "    ACTIVO     " } ;
const unsigned char sTela_so_alarme[]    	= { "SOLAMENTE ALARMA" } ;
const unsigned char sTela_desl_banco[]   	= { "   DESLIGA CAP. " } ;
const unsigned char sTela_nao_atua[]     	= { " INACTIVO	 " } ;
const unsigned char sTela_funcao29[]   	= { "29-NRO DE RED   " } ;
const unsigned char sTela_funcao30[]   	= { "30-VELOCIDAD    " } ;
const unsigned char sTela_funcao31a[]  	= { "31-PARID.STPBIT " } ;
const unsigned char sTela_funcao31b[]  	= { "SIN   2 STOP BIT" } ;
const unsigned char sTela_funcao31c[]  	= { "IMPAR 1 STOP BIT" } ;
const unsigned char sTela_funcao31d[]  	= { "PAR 1 STOP BIT  " } ;
const unsigned char sTela_funcao32[]    	= { "32-MANUAL" };
const unsigned char sTela_funcao33a[]    	= { "33-TIPO LIGACION" };
const unsigned char sTela_funcao33b[]    	= { "FASE-NTRO-ESTREL" };
const unsigned char sTela_funcao33c[]    	= { "FASE-FASE-ESTREL" };
const unsigned char sTela_funcao33d[]    	= { "FASE-FASE-DELTA " };
#endif

#define PROG_IP 		0
#define PROG_MASK 		1
#define PROG_GATEWAY 	2
#define CURSOR_TIME_ON 	120

#ifdef TECLADO_NOVO
void leTeclado(void)	  //le apenas a tecla P0.15
{
	DWORD leitura_p0;
	DWORD leitura_p1;

	leitura_p0=FIO0PIN&0x00000C23;
	leitura_p1=FIO1PIN&0x20000000;

	switch (leitura_p0)
	{
		case 0x00000C03:	//TCL1=0,TCL2=1,TCL3=1,TCL4=1,TCL5=1,TCL6=1
			{
				teclaAtual=TC_ESC;
				break;
			}
		case 0x00000C22:	//TCL1=1,TCL2=1,TCL3=0,TCL4=1,TCL5=1,TCL6=1
			{
				teclaAtual=TC_DOWN;
				break;
			}
		case 0x00000C21:	//TCL1=1,TCL2=1,TCL3=1,TCL4=0,TCL5=1,TCL6=1
			{
				teclaAtual=TC_UP;
				break;
			}
		case 0x00000823:	//TCL1=1,TCL2=1,TCL3=1,TCL4=1,TCL5=0,TCL6=1
			{
				teclaAtual=TC_RIGTH;
				//teclaAtual=TC_LEFT;
				break;
			}
		case 0x00000423:	//TCL1=1,TCL2=1,TCL3=1,TCL4=1,TCL5=1,TCL6=0
			{
				teclaAtual=TC_PRG;
				//	teclaAtual=TC_RIGTH;
				break;
			}
		default:
			{
				teclaAtual=TC_NULL;
				break;
			}
	}

	if(leitura_p1 == 0x00000000)
		teclaAtual = TC_LEFT;

#if MD4040TI==1 //remapeamento
	switch (teclaAtual)
	{
		case TC_LEFT:{teclaAtual=TC_ESC ; break;}
		case TC_RIGTH:{teclaAtual=TC_LEFT ; break;}
		case TC_ESC:{teclaAtual=TC_PRG ; break;}
		case TC_PRG	:{teclaAtual=TC_RIGTH ; break;}
	}

#endif

}

#else
void leTeclado(void)	  //le apenas a tecla P0.15
{
	DWORD leitura;


	leitura=LerPinosEmPorta(0,0x00000EE0);

	switch (leitura)
	{
		case 0x00000EC0:    //TCL1=0,TCL2=1,TCL3=1,TCL4=1,TCL5=1,TCL6=1
			{
				teclaAtual=TC_ESC;
				//teclaAtual=TC_PRG;
				break;
			}
		case 0x00000EA0:	//TCL1=1,TCL2=0,TCL3=1,TCL4=1,TCL5=1,TCL6=1
			{
				teclaAtual=TC_LEFT;
				//teclaAtual=TC_ESC;
				break;
			}
		case 0x00000E60:	//TCL1=1,TCL2=1,TCL3=0,TCL4=1,TCL5=1,TCL6=1
			{
				teclaAtual=TC_DOWN;
				break;
			}
		case 0x00000CE0:	//TCL1=1,TCL2=1,TCL3=1,TCL4=0,TCL5=1,TCL6=1
			{
				teclaAtual=TC_UP;
				break;
			}
		case 0x00000AE0:	//TCL1=1,TCL2=1,TCL3=1,TCL4=1,TCL5=0,TCL6=1
			{
				teclaAtual=TC_RIGTH;
				//teclaAtual=TC_LEFT;
				break;
			}
		case 0x000006E0:	//TCL1=1,TCL2=1,TCL3=1,TCL4=1,TCL5=1,TCL6=0
			{
				teclaAtual=TC_PRG;
				//	teclaAtual=TC_RIGTH;
				break;
			}
		default:
			{
				teclaAtual=TC_NULL;
				break;
			}
	}

	//if (teclaAtual!=TC_NULL) {CiclarTelas=OFF;}


#if MD4040TI==1 //remapeamento
	switch (teclaAtual)
	{
	 	case TC_LEFT:{teclaAtual=TC_ESC ; break;}
	 	case TC_RIGTH:{teclaAtual=TC_LEFT ; break;}
	 	case TC_ESC:{teclaAtual=TC_PRG ; break;}
	 	case TC_PRG	:{teclaAtual=TC_RIGTH ; break;}
	}

#endif

}
#endif

/**********************************************************
Rotina:
void EscreveReles(short Saidas)

ESCRITA NOS RELES DO LATCHS 1 E 2

Aten��o: Esta rotina estcreve temb�m no rele do Alarme!, assim que
cuidado ao utiliz�-la.

 **********************************************************/

void EscreveReles(short Saidas)
{
	int i;
	union union2x {short u1int; char u1char[2];};
	union union2x union2;
	union2.u1int=Saidas;
	/**********************************************************
	  ESCRITA NA PARTE BAIXA, RELES DO LATCH 1
	 **********************************************************/
	{

		CLRpinoEmPorta(2,BARRAMENTO);
		SETpinoEmPorta(2,(union2.u1char[LSB])<<INICIO_BARRAMENTO);
		SETpinoEmPorta(2,REL1_CS);


		//Aqui temos um delay para que o Latch engula os dados...
		for (i=0;i<10;i++);	 //10000 = delay 1.5ms!; 10=0.98us (aprox 1us!)	 ; sendo 'int i'
		CLRpinoEmPorta(0,REL1_CS);
	}
}

void If_Atualizacao()
{
	unsigned char i;
	unsigned char precisagravar=0;

	switch(teclaAtual)
	{
		default:
			{
				if (modoprog==0)
				{
					if (AtualizaDisplay==ON)
					{
						If_TelaApresentacao(menu_atual.leitura);// dou um refresh nas telas de apresenta��o
						AtualizaDisplay=OFF;
					}
				}

				if (programando==1)
				{
					If_TelaProgramacao(menu_atual.prog);
				}
				break;
			}
		case TC_ESC:
			{
				DisplayInit();
				AtualizaDisplay=ON;
				if (modoprog==1)
				{

				    zerar_consumo_cm=0;

					if (FLAG_PROG_F32==1)
					{
						if (programando==1)
						{
							ALTERACAO_MANUAL_FINALIZADA=1;
							//FLAG_DESLIGATODOS=1;
							Sys_ProgramaAlvo((Bancos.StatusAlvo&(~ZeroKVAr))&0xFFF); //com isto garantimos que os bancos em zero estao desligados...
							Comando=CONTROLE_NORMAL;
						}
					}

					//sair do modo de programa��o
					relacaoTCfat=relacaoTCfat_temp;
					relacaoTCpri=relacaoTCpri_temp;
					relacaoTCsec=relacaoTCsec_temp;
					relacaoTPfat=relacaoTPfat_temp;
					relacaoTPpri=relacaoTPpri_temp;
					relacaoTPsec=relacaoTPsec_temp;
					NroPorta=NroPorta_temp;
					NroPorta2=NroPorta_temp;

					modoprog=0;
					programando=0;
					//             FLAG_ALTEREI_KVAR=0;

							#if MD4040TI==1
					 			if (StatusFuncao[2]==1)
								PowerDown();
							#endif


					If_TelaApresentacao(menu_atual.leitura);

				}
				else
				{
					//volta ao menu inicial no modo leitura
					menu_atual.leitura=Tela_01;
					If_TelaApresentacao(menu_atual.leitura);
				}
				break;
			}
		case TC_PRG:
			{
				DisplayInit();
				AtualizaDisplay=ON;
				if (modoprog==1)
				{
					//sair do modo de programa�ao (gravando)
					if (zerar_consumo_cm==1)
					{

							ConsumoT=0;ConsumoA=0;ConsumoB=0;ConsumoC=0;
							EnergGerT=0;EnergGerA=0;EnergGerB=0;EnergGerC=0;
							EnergIndT=0;EnergIndA=0;EnergIndB=0;EnergIndC=0;
							EnergCapT=0; EnergCapA=0;EnergCapB=0;EnergCapC=0;
//Variaveis int64 de calc de Consumo e Energias s�o zeradas durante CMD ZERA CONSUMO na TELA
// Add by CCT
							EnergGerT_int64=0; EnergGerA_int64=0; EnergGerB_int64=0; EnergGerC_int64=0;
							ConsumoT_int64=0;  ConsumoA_int64=0;  ConsumoB_int64=0;  ConsumoC_int64=0;
							EnergIndT_int64=0; EnergIndA_int64=0; EnergIndB_int64=0; EnergIndC_int64=0;
							EnergCapT_int64=0; EnergCapA_int64=0; EnergCapB_int64=0; EnergCapC_int64=0;

							zerar_consumo_cm=0;
					}


					if (FLAG_PROG_F32==1)
					{
						if (programando==1)
						{
							ALTERACAO_MANUAL_FINALIZADA=1;
							Sys_ProgramaAlvo((Bancos.StatusAlvo&(~ZeroKVAr))&0xFFF); //com isto garantimos que os bancos em zero estao desligados...
							Comando=CONTROLE_NORMAL;
						}
					}
					//vamos verificar se precisamos gravar...
					//for (i=1;i<=44;i++)
					#if MD4040TI==1
					//StatusFuncao[2]=0;
					//StatusFuncaoFinal[2]=0;
				    #endif

					for (i=1;i<=50;i++)
					{
						if (i!=32)
						{
							if (StatusFuncao[i]!=StatusFuncaoFinal[i]) {precisagravar=1; break;}
						}
					}
					if (NroPorta!=NroPorta_temp) 	{precisagravar=1;}


					if (If_VerificaErros()==0)
					{
						programando=0;
						modoprog=0;
						//for (i=1;i<=44;i++)
						for (i=1;i<=50;i++)
							StatusFuncaoFinal[i]=StatusFuncao[i];

						if (precisagravar==1)
						{
							SalvaParametrizacao(); //salva e atualiza nova parametriza��o

							Sys_ProgramaAlvo((Bancos.StatusAlvo&(~ZeroKVAr))&0xFFF); //com isto garantimos que os bancos em zero estao desligados...
							Sys_OperaSaidas();//desliga logo os bancos em zero kvar...
						}
							#if MD4040TI==1
					 			if (StatusFuncao[2]==1)
								PowerDown();
							#endif

						If_TelaApresentacao(menu_atual.leitura);
						//            FLAG_ALTEREI_KVAR=0;

					}

				}
				else
				{
					//entra no modo de programa��o
					relacaoTCfat_temp=relacaoTCfat;
					relacaoTCpri_temp=relacaoTCpri;
					relacaoTCsec_temp=relacaoTCsec;
					relacaoTPfat_temp=relacaoTPfat;
					relacaoTPpri_temp=relacaoTPpri;
					relacaoTPsec_temp=relacaoTPsec;
					NroPorta_temp=NroPorta;



					modoprog = 1;
					#if MD4040TI==1
					StatusFuncao[2]=0;
					StatusFuncaoFinal[2]=0;
				    #endif
					for (i=1;i<=50;i++)
						StatusFuncao[i]=StatusFuncaoFinal[i];

					StatusFuncao[32]=1;//Manual, sempre ao entrar, vale 1.
#if (COM_SENHA==SIM)
					PrtLcd("Senha de acesso:          ",0,0);
					PrtLcd("                ",1,0);
					If_PedeSenha();
					DisplayInit();
					if (senhaOK==1)
					{
						#ifdef BLOQUEIA_TP_TC
							menu_atual.prog = 35;
						#endif
						If_TelaProgramacao(menu_atual.prog);
					}
					else
					{
						modoprog=0;
						programando=0;
						menu_atual.leitura=Tela_01;
						If_TelaApresentacao(menu_atual.leitura);
					}
#else
					If_TelaProgramacao(menu_atual.prog);
#endif
				}
				break;
			}
		case TC_RIGTH:
			{
				DisplayInit();

				AtualizaDisplay=ON;
				if (modoprog==1)
				{
					If_IncMenu(1);
					If_TelaProgramacao(menu_atual.prog);
				}
				else
				{
					If_IncMenu(0);
					If_TelaApresentacao(menu_atual.leitura);
				}
				break;
			}
		case TC_LEFT:
			{
				DisplayInit();
				AtualizaDisplay=ON;
				if (modoprog==1)
				{
					If_DecMenu(1);
					If_TelaProgramacao(menu_atual.prog);
				}
				else
				{
					If_DecMenu(0);
					If_TelaApresentacao(menu_atual.leitura);
				}
				break;
			}
		case TC_UP:
			{
				if (modoprog==1)
				{
					programando=1;
					If_IncDecParam(menu_atual.prog,1);
					AtualizaDisplay=ON;
					If_TelaProgramacao(menu_atual.prog);
				}

				break;
			}
		case TC_DOWN:
			{
				if (modoprog==1)
				{
					programando=1;
					If_IncDecParam(menu_atual.prog,0);
					AtualizaDisplay=ON;
					If_TelaProgramacao(menu_atual.prog);
				}
				break;
			}
	}//fim do swtich
}//fim do Atualizacao

#if 1

void If_NovaSenha()
{
	unsigned char algarismo=4; //vale 1(menos significativo),2,3 ou 4(mais significativo)
	unsigned char se1,se2,se3,se4;
	unsigned long int acumulatempo=0;
	se1=0;se2=0;se3=0;se4=0;
	senhalocal=0;
	senha.senha_c[1]=StatusFuncao[36];
	senha.senha_c[0]=StatusFuncao[35];
	teclaAtual=TC_NULL;
	ultimaTeclaExecutada=TC_ESC;

	while (teclaAtual!=TC_ESC)
	{
		toogleWDI();
		acumulatempo++;

		if (acumulatempo<60)
		{
			PosCur(1,0);
			PrtLcdBcdNibble(se4,0);
			PrtLcdBcdNibble(se3,0);
			PrtLcdBcdNibble(se2,0);
			PrtLcdBcdNibble(se1,0);
			PrtLcd("            ",1,4);
		}

		if (acumulatempo>60)
		{
			switch(algarismo)
			{
				case 1:
					{
						PosCur(1,0);
						PrtLcdBcdNibble(se4,0);
						PrtLcdBcdNibble(se3,0);
						PrtLcdBcdNibble(se2,0);
						WrLcdData(TudoPretoSYMB);
						PrtLcd("            ",1,4);
						break;
					}
				case 2:
					{
						PosCur(1,0);
						PrtLcdBcdNibble(se4,0);
						PrtLcdBcdNibble(se3,0);
						WrLcdData(TudoPretoSYMB);
						PrtLcdBcdNibble(se1,0);
						PrtLcd("            ",1,4);
						break;
					}
				case 3:
					{
						PosCur(1,0);
						PrtLcdBcdNibble(se4,0);
						WrLcdData(TudoPretoSYMB);
						PrtLcdBcdNibble(se2,0);
						PrtLcdBcdNibble(se1,0);
						PrtLcd("            ",1,4);
						break;
					}
				case 4:
					{
						PosCur(1,0);
						WrLcdData(TudoPretoSYMB);
						PrtLcdBcdNibble(se3,0);
						PrtLcdBcdNibble(se2,0);
						PrtLcdBcdNibble(se1,0);
						PrtLcd("            ",1,4);
						break;
					}
			}
		}
		if (acumulatempo> 120)
		{
			acumulatempo=0;
		}
		//entra no loop para identificacao da senha
		leTeclado();

		if (ultimaTeclaExecutada!=teclaAtual)
		{
			ultimaTeclaExecutada=teclaAtual;
			//plotagem na tela;
			if (teclaAtual==TC_DOWN)
			{
				if (algarismo==1) { if (se1!=0) {se1=se1-1;} else {se1=9;}}
				if (algarismo==2) { if (se2!=0) {se2=se2-1;} else {se2=9;}}
				if (algarismo==3) { if (se3!=0) {se3=se3-1;} else {se3=9;}}
				if (algarismo==4) { if (se4!=0) {se4=se4-1;} else {se4=9;}}
			}
			if (teclaAtual==TC_UP)
			{
				if (algarismo==1) { if (se1!=9) {se1=se1+1;} else {se1=0;}}
				if (algarismo==2) { if (se2!=9) {se2=se2+1;} else {se2=0;}}
				if (algarismo==3) { if (se3!=9) {se3=se3+1;} else {se3=0;}}
				if (algarismo==4) { if (se4!=9) {se4=se4+1;} else {se4=0;}}
			}
			if (teclaAtual==TC_LEFT)
			{
				if (algarismo!=4) {algarismo=algarismo+1;}
				else {algarismo=1;}
			}
			if (teclaAtual==TC_RIGTH)
			{
				if (algarismo!=1) {algarismo=algarismo-1; }
				else {algarismo=4; }
			}
			if (teclaAtual==TC_PRG)
			{
				senhalocal=se4;
				senhalocal=senhalocal<<4;
				senhalocal=senhalocal|se3;
				senhalocal=senhalocal<<4;
				senhalocal=senhalocal|se2;
				senhalocal=senhalocal<<4;
				senhalocal=senhalocal|se1;
				senha.senha_i=senhalocal;
				StatusFuncao[36]=senha.senha_c[1];
				StatusFuncao[35]=senha.senha_c[0];
				teclaAtual=TC_ESC;
			}

			PosCur(1,0);
			PrtLcdBcdNibble(se4,0);
			PrtLcdBcdNibble(se3,0);
			PrtLcdBcdNibble(se2,0);
			PrtLcdBcdNibble(se1,0);
			PrtLcd("            ",1,4);

		}
	}
}

void If_NovoNroPorta()
{
	unsigned char algarismo=4; //vale 1(menos significativo),2,3 ou 4(mais significativo)
	unsigned char se1,se2,se3,se4,se5;
	unsigned long int acumulatempo=0;

	senha.senha_c[1]=(NroPorta>>8)&0xFF;
	senha.senha_c[0]=NroPorta&0xFF;
	senhalocal=NroPorta;

	if (NroPorta<10000)
	{
		se5=0;
	}
	else
	{
	    se5=1;
		senhalocal=senhalocal-10000;

	}

    Sys_HexBcd(senhalocal);

	se4=(Zaz[1]>>4)&0x0F;
	se3=(Zaz[1])&0x0F;
	se2=(Zaz[0]>>4)&0x0F;
	se1=(Zaz[0])&0x0F;
	PosCur(1,0);
	PrtLcdBcdNibble(se5,0);
	PrtLcdBcdNibble(se4,0);
	PrtLcdBcdNibble(se3,0);
	PrtLcdBcdNibble(se2,0);
	PrtLcdBcdNibble(se1,0);
	PrtLcd("           ",1,5);

	teclaAtual=TC_NULL;
	ultimaTeclaExecutada=TC_ESC;

	while (teclaAtual!=TC_ESC)
	{
		toogleWDI();
		acumulatempo++;

		if (acumulatempo<60)
		{
			PosCur(1,0);
			PrtLcdBcdNibble(se5,0);
			PrtLcdBcdNibble(se4,0);
			PrtLcdBcdNibble(se3,0);
			PrtLcdBcdNibble(se2,0);
			PrtLcdBcdNibble(se1,0);
			PrtLcd("           ",1,5);
		}

		if (acumulatempo>60)
		{
			switch(algarismo)
			{
				case 1:
					{
						PosCur(1,0);
						PrtLcdBcdNibble(se5,0);
						PrtLcdBcdNibble(se4,0);
						PrtLcdBcdNibble(se3,0);
						PrtLcdBcdNibble(se2,0);
						WrLcdData(TudoPretoSYMB);
						PrtLcd("           ",1,5);
						break;
					}
				case 2:
					{
						PosCur(1,0);
						PrtLcdBcdNibble(se5,0);
						PrtLcdBcdNibble(se4,0);
						PrtLcdBcdNibble(se3,0);
						WrLcdData(TudoPretoSYMB);
						PrtLcdBcdNibble(se1,0);
						PrtLcd("           ",1,5);
						break;
					}
				case 3:
					{
						PosCur(1,0);
						PrtLcdBcdNibble(se5,0);
						PrtLcdBcdNibble(se4,0);
						WrLcdData(TudoPretoSYMB);
						PrtLcdBcdNibble(se2,0);
						PrtLcdBcdNibble(se1,0);
						PrtLcd("           ",1,5);
						break;
					}
				case 4:
					{
						PosCur(1,0);
						PrtLcdBcdNibble(se5,0);
						WrLcdData(TudoPretoSYMB);
						PrtLcdBcdNibble(se3,0);
						PrtLcdBcdNibble(se2,0);
						PrtLcdBcdNibble(se1,0);
						PrtLcd("           ",1,5);
						break;
					}
				case 5:
					{
						PosCur(1,0);
						WrLcdData(TudoPretoSYMB);
						PrtLcdBcdNibble(se4,0);
						PrtLcdBcdNibble(se3,0);
						PrtLcdBcdNibble(se2,0);
						PrtLcdBcdNibble(se1,0);
						PrtLcd("           ",1,5);
						break;
					}

			}
		}
		if (acumulatempo> 120)
		{
			acumulatempo=0;
		}

		//entra no loop para identificacao da senha
		leTeclado();

		if (ultimaTeclaExecutada != teclaAtual)
		{
			ultimaTeclaExecutada=teclaAtual;
			//plotagem na tela;
			if (teclaAtual==TC_DOWN)
			{
				if (algarismo==1) { if (se1!=0) {se1=se1-1;} else {se1=9;}}
				if (algarismo==2) { if (se2!=0) {se2=se2-1;} else {se2=9;}}
				if (algarismo==3) { if (se3!=0) {se3=se3-1;} else {se3=9;}}
				if (algarismo==4) { if (se4!=0) {se4=se4-1;} else {se4=9;}}
				if (algarismo==5) { if (se5!=0) {se5=se5-1;} else {se5=9;}}
			}
			if (teclaAtual==TC_UP)
			{
				if (algarismo==1) { if (se1!=9) {se1=se1+1;} else {se1=0;}}
				if (algarismo==2) { if (se2!=9) {se2=se2+1;} else {se2=0;}}
				if (algarismo==3) { if (se3!=9) {se3=se3+1;} else {se3=0;}}
				if (algarismo==4) { if (se4!=9) {se4=se4+1;} else {se4=0;}}
				if (algarismo==5) { if (se5!=9) {se5=se5+1;} else {se5=0;}}
			}
			if (teclaAtual==TC_LEFT)
			{
				if (algarismo!=5) {algarismo=algarismo+1;}
				else {algarismo=1;}
			}
			if (teclaAtual==TC_RIGTH)
			{
				if (algarismo!=1) {algarismo=algarismo-1; }
				else {algarismo=5; }
			}
			if (teclaAtual==TC_PRG)
			{
				senhalocal=se4;
				senhalocal=senhalocal<<4;
				senhalocal=senhalocal|se3;
				senhalocal=senhalocal<<4;
				senhalocal=senhalocal|se2;
				senhalocal=senhalocal<<4;
				senhalocal=senhalocal|se1;
				senha.senha_i=senhalocal;
				NroPorta2=se5*10000+se4*1000+se3*100+se2*10+se1;
				NroPorta=NroPorta2;
				SalvaParametrizacao();
				teclaAtual=TC_ESC;
			}

			PosCur(1,0);
			PrtLcdBcdNibble(se5,0);
			PrtLcdBcdNibble(se4,0);
			PrtLcdBcdNibble(se3,0);
			PrtLcdBcdNibble(se2,0);
			PrtLcdBcdNibble(se1,0);
			PrtLcd("            ",1,4);

		}
		/*else
		  {
		  Sys_Delay200Ms();
		  PosCur(1,4-algarismo);
		  WrLcdData(TudoPretoSYMB);
		  Sys_Delay200Ms();

		  }	*/
	}
}



void If_PedeSenha()  // "SENHA:"
{
	unsigned char algarismo=4; //vale 1(menos significativo),2,3 ou 4(mais significativo)
	unsigned char se1,se2,se3,se4;
	unsigned long int acumulatempo=0;
	se1=0;se2=0;se3=0;se4=0;
	senhalocal=0;
	senha.senha_c[1]=StatusFuncao[36];
	senha.senha_c[0]=StatusFuncao[35];
	senhaOK=0;
	teclaAtual=TC_NULL;
	ultimaTeclaExecutada=TC_PRG;

	while (teclaAtual!=TC_ESC)
	{
		acumulatempo++;
		toogleWDI();

		if (acumulatempo<60)
		{
			PosCur(1,0);
			PrtLcdBcdNibble(se4,0);
			PrtLcdBcdNibble(se3,0);
			PrtLcdBcdNibble(se2,0);
			PrtLcdBcdNibble(se1,0);
			PrtLcd("            ",1,4);
		}

		if (acumulatempo>60)
		{
			//    PosCur(1,4-algarismo);
			//WrLcdData(TudoPretoSYMB);
			switch(algarismo)
			{
				case 1:
					{
						PosCur(1,0);
						PrtLcdBcdNibble(se4,0);
						PrtLcdBcdNibble(se3,0);
						PrtLcdBcdNibble(se2,0);
						WrLcdData(TudoPretoSYMB);
						PrtLcd("            ",1,4);
						break;
					}
				case 2:
					{
						PosCur(1,0);
						PrtLcdBcdNibble(se4,0);
						PrtLcdBcdNibble(se3,0);
						WrLcdData(TudoPretoSYMB);
						PrtLcdBcdNibble(se1,0);
						PrtLcd("            ",1,4);
						break;
					}
				case 3:
					{
						PosCur(1,0);
						PrtLcdBcdNibble(se4,0);
						WrLcdData(TudoPretoSYMB);
						PrtLcdBcdNibble(se2,0);
						PrtLcdBcdNibble(se1,0);
						PrtLcd("            ",1,4);
						break;
					}
				case 4:
					{
						PosCur(1,0);
						WrLcdData(TudoPretoSYMB);
						PrtLcdBcdNibble(se3,0);
						PrtLcdBcdNibble(se2,0);
						PrtLcdBcdNibble(se1,0);
						PrtLcd("            ",1,4);
						break;
					}
			}
		}
		if (acumulatempo> 120)
		{
			acumulatempo=0;
		}


		//entra no loop para identificacao da senha

		leTeclado();

		if (ultimaTeclaExecutada!=teclaAtual)
		{
			ultimaTeclaExecutada=teclaAtual;
			//plotagem na tela;
			if (teclaAtual==TC_DOWN)
			{
				if (algarismo==1) { if (se1!=0) {se1=se1-1;} else {se1=9;}}
				if (algarismo==2) { if (se2!=0) {se2=se2-1;} else {se2=9;}}
				if (algarismo==3) { if (se3!=0) {se3=se3-1;} else {se3=9;}}
				if (algarismo==4) { if (se4!=0) {se4=se4-1;} else {se4=9;}}
			}
			if (teclaAtual==TC_UP)
			{
				if (algarismo==1) { if (se1!=9) {se1=se1+1;} else {se1=0;}}
				if (algarismo==2) { if (se2!=9) {se2=se2+1;} else {se2=0;}}
				if (algarismo==3) { if (se3!=9) {se3=se3+1;} else {se3=0;}}
				if (algarismo==4) { if (se4!=9) {se4=se4+1;} else {se4=0;}}
			}
			if (teclaAtual==TC_LEFT)
			{
				if (algarismo!=4) {algarismo=algarismo+1;}
				else {algarismo=1;}
			}
			if (teclaAtual==TC_RIGTH)
			{
				if (algarismo!=1) {algarismo=algarismo-1; }
				else {algarismo=4; }
			}
			if (teclaAtual==TC_PRG)
			{
				teclaAtual=TC_ESC;
				senhalocal=se4;
				senhalocal=senhalocal<<4;
				senhalocal=senhalocal|se3;
				senhalocal=senhalocal<<4;
				senhalocal=senhalocal|se2;
				senhalocal=senhalocal<<4;
				senhalocal=senhalocal|se1;
				senhaOK=0;
				if (senhalocal==senha.senha_i)
				{
					senhaOK=1;
				}//liberou!
				else
				{
					senhaOK=0; //nao deu...
					if (senhalocal==SenhaMestre.s_int)
					{
						senhaOK=1; //liberou!
					}
				}
			}

		}
	}

	//teclaAtual=TC_NULL;
	//ultimaTeclaExecutada=TC_NULL;
	//AtualizaDisplay=OFF;

}


#endif


void If_IncDecParam(unsigned char menu,char inc)
{
	switch(menu)
	{
		case 1:
		case 2:
		case 3:
		case 4:
		case 5:
		case 6:
		case 7:
		case 8:
		case 9:
		case 10:
		case 11:
		case 12:
			{
				//kvar dos bancos.
				if (inc) {If_IncDecAux(menu,29,0,1);} else {If_IncDecAux(menu,0,29,-1);}
				FLAG_ALTEREI_KVAR=1;	FLAG_LIGOU_RECENTEMENTE=0;

				break;
			}
		case 13:
		case 14:
			//limite inferior da faixa do FP
			//limite superior da faixa do FP
			{
				if (inc) {If_IncDecAux(menu,120,120,1);} else {If_IncDecAux(menu,80,80,-1);}
				break;
			}
		case 15:
			//Tempo de disparo
			{
				if (inc) {If_IncDecAux(menu,12,0,1);} else {If_IncDecAux(menu,0,12,-1);}
				break;
			}
		case 16:
			//antiga rela�ao TP, agora � ESTRELA=0, DELTA=1
			{
				//		if (inc) {If_IncDecAux(menu,29,1,1);} else {If_IncDecAux(menu,1,29,-1);}
				break;
			}
		case 17:
			//rela�ao TC
			{
				//		if (inc) {If_IncDecAux(menu,40,1,1);} else {If_IncDecAux(menu,1,40,-1);}
				break;
			}
		case 18:
		case 19:
			//limite inferior da faixa do alarme
			//limite superior da faixa do alarme
			{
				if (inc) {If_IncDecAux(menu,130,130,1);} else {If_IncDecAux(menu,70,70,-1);}
				break;
			}
		case 20:
		case 21:
		case 28:
			//protecao capacitiva
			//modo de acionamento
			//modo de opera��o
			//tipo de ligacao, FN=0 FF=1;
			{
				if(StatusFuncao[menu]==1) {StatusFuncao[menu]=0;}
				else {StatusFuncao[menu]=1;}
				break;
			}
		case 23:
		case 22:
		case 24:
		case 26:
			//    case 33:
			//limite de alarme de sub-sobretensao
			//modo de atuacao do alarme de corrente
			//modo de atuacao do alarme tensao
			//modo de atuacao do alarme DHT
			{
				if (inc) {If_IncDecAux(menu,3,1,1);} else {If_IncDecAux(menu,1,3,-1);}
				break;
			}

			/*
#define BR4800   0
#define BR9600   1			 0
#define BR14400  2			 1
#define BR19200  3			 2
#define BR38400  4			 3
#define BR56000  5
#define BR57600  6
#define BR115200 7
			 */
		case 30:
			//velocidade de comunica��o
			{
				if (inc) {If_IncDecAux(menu,8,1,1);} else {If_IncDecAux(menu,1,8,-1);}
				break;
			}
		case 31:
			//paridade stop bits
			{
				if (inc) {If_IncDecAux(menu,3,1,1);} else {If_IncDecAux(menu,1,3,-1);}
				break;
			}
		case 25:
			//limite alarme DHT
			{
				if (inc) {If_IncDecAux(menu,25,3,1);} else {If_IncDecAux(menu,3,25,-1);}
				break;
			}



		case 27:
			//tempo para consideracao do alarme
			{
				if (inc) {If_IncDecAux(menu,99,0,1);} else {If_IncDecAux(menu,0,99,-1);}
				break;
			}
		case 29:
			//numero de escravo na rede
			{
				if (inc) {If_IncDecAux(menu,255,255,1);} else {If_IncDecAux(menu,1,1,-1);}
				break;
			}
		case 33:
			//tipo de liga��o
			{
				if(StatusFuncao[menu]==2) {StatusFuncao[menu]=1;}
				else {StatusFuncao[menu]=2;}
				break;
			}

		case 32:
			{
				//funcao Manual
				if (controleManualHabilitado==SIM){
					if (inc) {If_IncDecAux(menu,13,13,1);} else {If_IncDecAux(menu,0,0,-1);}
				}
				break;
			}
		case 35:
		case 36:
		case 37:
			{

				//funcoes com RTC no CM4040
				break;
			}


		case 39:
			{
				if (zerar_consumo_cm==0) {zerar_consumo_cm=1;} else {zerar_consumo_cm=0;}
				break;
			}

#ifdef HABsangrado
		case 40:
			{

				if((0x80&StatusFuncao[21])==0x80) {StatusFuncao[21]=StatusFuncao[21]&0x7F;}
				else {StatusFuncao[21]=0x80|StatusFuncao[21];}

				break;
			}
#endif
		case 42:
			{


				if(StatusFuncao[1]!=0) {StatusFuncao[1]=0;}
				else {StatusFuncao[1]=1;}
				MMFp3Acc=0.0;
				break;
			}
		case 43:
			{


				if(StatusFuncao[2]==0) {StatusFuncao[2]=1;}

				break;
			}

	}
}


void If_IncDecAux(unsigned char menu,unsigned char a,unsigned char b,unsigned char c)
{
	if(StatusFuncao[menu]==a)
	{
		StatusFuncao[menu]=b;
	}
	else
	{
		StatusFuncao[menu]=StatusFuncao[menu]+c;
	}
	//printf("StatusFuncao[%i]=%i\n",0x00,menu,0x00,StatusFuncao[menu]);
}


void If_DecMenu(char prog)
{
	int none;
#if MODELO_DE_CONTROLADOR==CM4020
	#if (COM_SENHA==1)
		#ifdef  HABzeraconsumoCM
				#define ULTIMO_MENU 39 //guilherme 120209 era 34
		#else
			#if(DEBUG_SEM_TCPIP==NAO)
				#define ULTIMO_MENU 38 //guilherme 120209 era 34
			#else
			#define ULTIMO_MENU 35 //guilherme 120209 era 34
			#endif
		#endif
	#else
		#define ULTIMO_MENU 33
	#endif
#endif

#if MODELO_DE_CONTROLADOR==CM4040
	#if MD4040TI==1
		#define ULTIMO_MENU 43
	#else
		#define ULTIMO_MENU 37
	#endif
#endif

	if (prog)
	{
		//EXISTE 29,30,31 S� ComComunicacao
		menu_atual.prog--;
#if MD4040TI==1
	goto MD4040TI__;
#endif

		//#if (MONO_TRI==TRIFASICO) Guilherme 11/05/09 Comentei pois temporariamente somente utilizaremos liga��o Fase-Neutro.
		if (menu_atual.prog==33)
			menu_atual.prog=32;
#ifdef HABzeraconsumoCM
#if (MODELO==SEM_ETHERNET_SEM_RS485)
		if (menu_atual.prog==38)
			menu_atual.prog=34;
#endif
#if (MODELO==SEM_ETHERNET_COM_RS485)
		if (menu_atual.prog==38)
			menu_atual.prog=34;
#endif
#endif
		//#endif

#if (ComComunicacaoRS485==SIM)
		if (menu_atual.prog==28)
			menu_atual.prog=27;
	#ifdef SeisEstagios
		if (menu_atual.prog==12)
			menu_atual.prog=6;
	#endif
		if (menu_atual.prog==0)
			menu_atual.prog=ULTIMO_MENU;
#else
		if (menu_atual.prog==31)
			menu_atual.prog=27;
#ifdef SeisEstagios
		if (menu_atual.prog==12)
			menu_atual.prog=6;
#endif
		if (menu_atual.prog==0)
			menu_atual.prog=ULTIMO_MENU;
#endif

MD4040TI__:
#if MD4040TI==1
		if (menu_atual.prog==0)
			menu_atual.prog=ULTIMO_MENU;

		switch (menu_atual.prog)
		{
		case 	1:
		case 	2:
		case 	3:
		case 	4:
		case 	5:
		case 	6:
		case 	7:
		case 	8:
		case 	9:
		case 	10:
		case 	11:
		case 	12:
		case 	13:
		case 	14:
		case 	15:
				{
					menu_atual.prog=ULTIMO_MENU;
					break;
				}

		case 	33:
		{
			 menu_atual.prog=43;
			 break;
		}

		case 	34:

		case 35:
		{
					#ifdef BLOQUEIA_TP_TC
						menu_atual.prog=34;
					#else
						menu_atual.prog=17;
					#endif
					break;
			}

		case 	40:
			{
					menu_atual.prog=39;
					break;
			}
		/*case 	41:
			{
					menu_atual.prog=40;
					break;
			} */
		//#if MD4060==1
		case 	42:
			{
					menu_atual.prog=41;
					break;
			}
		// #endif


		}

#endif
		none=0;
	}
	else
	{
		menu_atual.leitura--;

#if (MONO_TRI==MONOFASICO)
		if (menu_atual.leitura==2)
			menu_atual.leitura=1;
		if (menu_atual.leitura==5)
			menu_atual.leitura=3;
		if (menu_atual.leitura==9)
			menu_atual.leitura=7;
#endif
#if MODELO_DE_CONTROLADOR==CM4020
#if (MODELO==SEM_ETHERNET_COM_RS485)
		if (menu_atual.leitura==0xFF)
			menu_atual.leitura=14; //guilherme 120209 era 10 mudei pra 12 //guilherme 281009 era 11 mudei pra 14
		if (menu_atual.leitura==12)
			menu_atual.leitura=11;
#endif
#if (MODELO==COM_ETHERNET_COM_RS485)
		if (menu_atual.leitura==0xFF)
			menu_atual.leitura=16; //guilherme 120209 era 10 mudei pra 12 //guilherme 281009 era 12 mudei pra 15
#endif
#if (MODELO==COM_ETHERNET_SEM_RS485)
		if (menu_atual.leitura==0xFF)
			menu_atual.leitura=16; //guilherme 120209 era 10 mudei pra 12 //guilherme 281009 era 12 mudei pra 15
#endif
#if (MODELO==SEM_ETHERNET_SEM_RS485)
		if (menu_atual.leitura==0xFF)
			menu_atual.leitura=14; //guilherme 120209 era 10 mudei pra 12 //guilherme 281009 era 11 mudei pra 14
		if (menu_atual.leitura==12)
			menu_atual.leitura=11;
#endif
#endif
#if MODELO_DE_CONTROLADOR==CM4040
		#ifdef MEDE_TEMPERATURA
		if (menu_atual.leitura==0xFF)
			menu_atual.leitura=16;
		#else
		if (menu_atual.leitura==0xFF)
			menu_atual.leitura=15;
		#endif
#endif

	 if (menu_atual.leitura==17)
		menu_atual.leitura=16;
#if  MD4040TI==1
		if (menu_atual.leitura==9)
			menu_atual.leitura=6;
#endif


	}
}

void If_IncMenu(char prog)
{
int none;
#if MODELO_DE_CONTROLADOR==CM4020
	#if (COM_SENHA==1)
		#ifdef HABzeraconsumoCM
			#define ULTIMO_MENU 39 //guilherme 120209 era 34
		#else
			#if(DEBUG_SEM_TCPIP==NAO)
				#define ULTIMO_MENU 38 //guilherme 120209 era 34
			#else
				#define ULTIMO_MENU 35 //guilherme 120209 era 34
			#endif
		#endif
	#else
		#define ULTIMO_MENU 33
	#endif
#endif

#if MODELO_DE_CONTROLADOR==CM4040
	#if MD4040TI==1
		#define ULTIMO_MENU 43
	#else
		#define ULTIMO_MENU 37
	#endif
#endif

	if (prog)
	{

		menu_atual.prog++;
#if MD4040TI==1
	goto MD4040TI_;
#endif
		//#if (MONO_TRI==TRIFASICO) Guilherme 11/05/09 Comentei pois temporariamente somente utilizaremos liga��o Fase-Neutro.
		if (menu_atual.prog==33)
			menu_atual.prog=34;

#ifdef HABzeraconsumoCM
#if (MODELO==SEM_ETHERNET_SEM_RS485)
		if (menu_atual.prog==35)
			menu_atual.prog=39;
#endif
#if (MODELO==SEM_ETHERNET_COM_RS485)
		if (menu_atual.prog==35)
			menu_atual.prog=39;
#endif

#endif
		//#endif

#if (ComComunicacaoRS485==SIM)
		if (menu_atual.prog==28)
			menu_atual.prog=29;
#ifdef SeisEstagios
		if (menu_atual.prog==7)
			menu_atual.prog=13;
#endif
		if (menu_atual.prog==(ULTIMO_MENU+1))
			menu_atual.prog=1;
#else
		if (menu_atual.prog==28)
			menu_atual.prog=32;
#ifdef SeisEstagios
		if (menu_atual.prog==7)
			menu_atual.prog=13;
#endif

		if (menu_atual.prog==(ULTIMO_MENU+1))
			menu_atual.prog=1;
#endif



MD4040TI_:
#if MD4040TI==1
		if (menu_atual.prog==(ULTIMO_MENU+1))
			menu_atual.prog=1;


		switch (menu_atual.prog)
		{
		case 	1:
		case 	2:
		case 	3:
		case 	4:
		case 	5:
		case 	6:
		case 	7:
		case 	8:
		case 	9:
		case 	10:
		case 	11:
		case 	12:
		case 	13:
		case 	14:
		case 	15:
				{
				#ifdef BLOQUEIA_TP_TC
					menu_atual.prog=34;
				#else
					menu_atual.prog=16;
				#endif
					break;
				}
		case 	18:
			{
					menu_atual.prog=34;
					break;
			}
		case 	40:
			{
					menu_atual.prog=41;
					break;
			}
		//#if MD4060==1
		case 	42:
			{
					menu_atual.prog=43;
					break;
			}
		 //#endif
		}
#endif



		none=0;
	}
	else
	{
		menu_atual.leitura++;
#if (MONO_TRI==MONOFASICO)
		if (menu_atual.leitura==2)
			menu_atual.leitura=3;
		if (menu_atual.leitura==4)
			menu_atual.leitura=6;
		if (menu_atual.leitura==8)
			menu_atual.leitura=10;
#endif

#if MODELO_DE_CONTROLADOR==CM4020
#if (MODELO==SEM_ETHERNET_COM_RS485)
		if (menu_atual.leitura==15)
			menu_atual.leitura=0; //guilherme 120209 era 11 mudei pra 12 //guilherme 281009 era 12 mudei pra 15
		if (menu_atual.leitura==12)
			menu_atual.leitura=13;
#endif
#if (MODELO==COM_ETHERNET_COM_RS485)
		if (menu_atual.leitura==16)
			menu_atual.leitura=0; //guilherme 120209 era 11 mudei pra 13 //guilherme 281009 era 13 mudei pra 16
#endif
#if (MODELO==COM_ETHERNET_SEM_RS485)


		#ifdef MEDE_TEMPERATURA
			if (menu_atual.leitura==17)
				menu_atual.leitura=0; //guilherme 120209 era 11 mudei pra 13 //guilherme 281009 era 13 mudei pra 16
		#else
			if (menu_atual.leitura==16)
				menu_atual.leitura=0;
		#endif
#endif
#if (MODELO==SEM_ETHERNET_SEM_RS485)
		if (menu_atual.leitura==15)
			menu_atual.leitura=0;
		if (menu_atual.leitura==12)
			menu_atual.leitura=13;
#endif
#endif
#if MODELO_DE_CONTROLADOR==CM4040

		#ifdef MEDE_TEMPERATURA
			if (menu_atual.leitura==18)
				menu_atual.leitura=0;
		#else
			if (menu_atual.leitura==16)
				menu_atual.leitura=0;
		#endif

#endif
	if (menu_atual.leitura==17)
		menu_atual.leitura=0;

	}

#if  MD4040TI==1
		if (menu_atual.leitura==7)
			menu_atual.leitura=10;
#endif


}


//rotina que exibe a Tela NTela, o seu contexto e os valores correspondentes
void If_TelaApresentacao(unsigned char NTela)
{
	WrLcdCom(ClrDsp);   //testezinho...
	PosCur(0,0); PosCur(0,0); PosCur(0,0);
	PosCur(0,0);

	FLAG_PROG_F32=0;
	switch(NTela)
	{

		case 0: { If_GeraTela00();break;}
		case 1: { If_GeraTela01();break;}
		case 2: { If_GeraTela02();break;}
		case 3: { If_GeraTela03();break;}
		case 4: { If_GeraTela04();break;}
		case 5: { If_GeraTela05();break;}
		case 6: { If_GeraTela06();break;}
		case 7: { If_GeraTela07();break;}
		case 8: { If_GeraTela08();break;}
		case 9: { If_GeraTela09();break;}
		case 10:{ If_GeraTela10();break;}
		case 11:{ If_GeraTela11();break;} //RTC
		case 12:{ If_GeraTela12();break;} //IP
		case 13:{ If_GeraTela13();break;}
		case 14:{ If_GeraTela14();break;}
		case 15:{ If_GeraTela15();break;}
		case 16:{ If_GeraTela16();break;}
		case 17:{ If_GeraTela17();break;}
		default:{ If_GeraTela00();break;}
	}
}
void If_TelaProgramacao(unsigned char NTela)
{
	/*somente entramos nesta rotina quando alguem tecla algo...*/
	WrLcdCom(ClrDsp);   //testezinho...
	PosCur(0,0); PosCur(0,0); PosCur(0,0); 	  //testezinho...
	PosCur(0,0); //testezinho...
	FLAG_PROG_F32=0;

	switch(NTela)
	{
		case 1:
		case 2:
		case 3:
		case 4:
		case 5:
		case 6:
		case 7:
		case 8:
		case 9:
		case 10:
		case 11:
		case 12: { If_GeraFunc1ao12(NTela); break;}
		case 13: { If_GeraFunc13(); break;}
		case 14: { If_GeraFunc14(); break;}
		case 15: { If_GeraFunc15(); break;}
		case 16: { If_GeraFunc16(); break;}
		case 17: { If_GeraFunc17(); break;}
		case 18: { If_GeraFunc18(); break;}
		case 19: { If_GeraFunc19(); break;}
		case 20: { If_GeraFunc20(); break;}
		case 21: { If_GeraFunc21(); break;}
		case 22: { If_GeraFunc22(); break;}
		case 23: { If_GeraFunc23(); break;}
		case 24: { If_GeraFunc24(); break;}
		case 25: { If_GeraFunc25(); break;}
		case 26: { If_GeraFunc26(); break;}
		case 27: { If_GeraFunc27(); break;}
		case 29: { If_GeraFunc29(); break;}
		case 30: { If_GeraFunc30(); break;}
		case 31: { If_GeraFunc31(); break;}
		case 32: { FLAG_PROG_F32=1; If_GeraFunc32(); break;}
		case 33: { If_GeraFunc33(); break;}
		case 34: { If_GeraFunc34(); break;}
		case 35: { If_GeraFunc35(); break;}
		case 36: { If_GeraFunc36(); break;}
		case 37: { If_GeraFunc37(); break;}
		case 38: { If_GeraFunc38(); break;}
 		case 39: { If_GeraFunc39(); break;}

#if (HABsangrado == 1)

		case 40: { If_GeraFunc40(); break;}	//enquanto nao esta 100% testado, fazer assim.
#endif
		case 41: { If_GeraFunc41(); break;}	//enquanto nao esta 100% testado, fazer assim.
		case 42: { If_GeraFunc42(); break;}
	    case 43: { If_GeraFunc43(); break;}
		default: { If_GeraFunc1ao12(NTela); break;}
	}
}

void If_TelaMensagens(unsigned char NTela)
{
	switch(NTela)
	{

		case 0: { PrtLcd((unsigned char *)sTela_msg00,0,0); break;}
		case 1: { PrtLcd((unsigned char *)sTela_msg01,0,0); break;}
		case 2: { PrtLcd((unsigned char *)sTela_msg02,0,0); break;}
		case 3: { PrtLcd((unsigned char *)sTela_msg03,0,0); break;}
		case 4: { PrtLcd((unsigned char *)sTela_msg04,0,0); break;}
		case 5: { PrtLcd((unsigned char *)sTela_msg05,0,0); break;}
		case 6: { PrtLcd((unsigned char *)sTela_msg06,0,0); break;}
		case 7: { PrtLcd((unsigned char *)sTela_msg07,0,0); break;}
		case 8: { PrtLcd((unsigned char *)sTela_CriandoCombinacoes,0,0); break;}
				//case 9: { PrtLcd(sTela_msg09,1,0); break;}
	}


}

////////////////////////Tela DE EXIBICAO//////////////////////////////////

void If_GeraTela00()
{
	PosCur(0,0);
	PosCur(0,0);
	PosCur(0,0);
	PosCur(0,0);
	PrtLcd((unsigned char *)sTela_msg00,0,0);//numero de serie, vers�o
	PosCur(1,8);
	PrtLcdBcdNibble((nserie_str[0]),0);
	PrtLcdBcdNibble((nserie_str[1]),0);
	PrtLcdBcdNibble((nserie_str[2]),0);
	PrtLcdBcdNibble((nserie_str[3]),0);
	PrtLcdBcdNibble((nserie_str[4]),0);
	PrtLcdBcdNibble((nserie_str[5]),0);
	PrtLcdBcdNibble((nserie_str[6]),0);
	PrtLcdBcdNibble((nserie_str[7]),0);
}

void If_GeraTela01()
{
#if MD4040TI==0
	PosCur(0,0);
	PosCur(0,0);
	PosCur(0,0);
	PosCur(0,0);
	If_PutCosFi(FatPotT);
	PosCur(1,0);
	If_PutQ(Q_controlador); //If_PutInt(tecla);
	If_SimbolosDoCantoEsquerdo();
#else
	unsigned long int tempi;
//	PrtLcd(" FREQ:",0,0);


	PosCur(1,0);
	//FreqA = gsm_debug;
	//FreqA = service_debug;
	tempi=(unsigned long int)((float)FreqA*100);
	//tempi=(unsigned long int)((float)temperatura_ptc_ch0*100);
	Sys_HexBcd(tempi);
	PrtLcdBcdNibble(Zaz[2],1);
	PrtLcdBcdNibble(Zaz[2],0);
   	PrtLcdBcdNibble(Zaz[1],1);
	PrtLcdBcdNibble(Zaz[1],0);
	WrLcdData('.');
	PrtLcdBcdNibble(Zaz[0],1);
	WrLcdData(' ');
	WrLcdData('H');
	WrLcdData('z');
#endif

}

void If_PutInt(unsigned int v)
{
	Sys_HexBcd(v);
	//PrtLcdBcdNumber(Zaz[2]);
	PrtLcdBcdNumber2(Zaz[1]);
	PrtLcdBcdNumber(Zaz[0]);
}


void If_GeraTela02()
{


#if MODELO_DE_CONTROLADOR==CM4040
	PosCur(0,0);
	PosCur(0,0);
	PosCur(0,0);
	PosCur(0,0);
	WrLcdData(A_SYMB);
	If_PutCosFi(FatPotA);
	PosCur(1,0);
	WrLcdData(B_SYMB);
	If_PutCosFi(FatPotB);
	PosCur(1,9);
	WrLcdData(C_SYMB);
	If_PutCosFi(FatPotC);

#else
	PosCur(0,0);
	PosCur(0,0);
	PosCur(0,0);
	PosCur(0,0);
	If_PutCosFi(FatPotA);
	PosCur(1,0);
	If_PutCosFi(FatPotB);
	PosCur(1,9);
	If_PutCosFi(FatPotC);
	if (AtualizaDisplay==1){PrtLcd("FPDAS3F",0,9);}
#endif

}

extern float caraca;
extern U16 watchdog_tcp;
void If_GeraTela03()
{
#if MODELO_DE_CONTROLADOR==CM4040
	PosCur(0,0);
	PosCur(0,0);
	PosCur(0,0);
	PosCur(0,0);
	If_PutV(UrmsA);
//	If_PutV((float)watchdog_tcp);
	PosCur(0,9);
	If_PutCosFi(FatPotA);
	PosCur(1,0);

	If_PutI(IrmsA);
//	If_PutV(caraca);
	PosCur(1,9);
	If_PutP(PotAtivA);
	if (AtualizaDisplay==1){
		PosCur(0,15);
		WrLcdData(A_SYMB);
	}
#else

	PosCur(0,0);
	PosCur(0,0);
	PosCur(0,0);
	PosCur(0,0);
#if (MONO_TRI==TRIFASICO)
	If_PutV(UrmsA);
#endif
#if (MONO_TRI==MONOFASICO)
	if (StatusFuncaoFinal[33]==2)
	{
		If_PutV(UrmsAB);
	}
	else
	{
		If_PutV(UrmsA);
	}
#endif

	PosCur(0,8);
	If_PutCosFi(FatPotA);
	PosCur(1,0);
	If_PutI(IrmsA);
	PosCur(1,9);
	If_PutP(PotAtivA);
#if (MONO_TRI==TRIFASICO)
	if (AtualizaDisplay==1) {PrtLcd("FA",0,14);}
#endif
#if (MONO_TRI==MONOFASICO)
	if (AtualizaDisplay==1) {PrtLcd("  ",0,14);}
#endif


#endif


}
void If_GeraTela04()
{

#if MODELO_DE_CONTROLADOR==CM4040
	PosCur(0,0);
	PosCur(0,0);
	PosCur(0,0);
	PosCur(0,0);
	If_PutV(UrmsB);
	PosCur(0,9);
	If_PutCosFi(FatPotB);
	PosCur(1,0);
	If_PutI(IrmsB);
	PosCur(1,9);
	If_PutP(PotAtivB);
	if (AtualizaDisplay==1){
		PosCur(0,15);
		WrLcdData(B_SYMB);
	}
#else
	PosCur(0,0);
	PosCur(0,0);
	PosCur(0,0);
	PosCur(0,0);
	If_PutV(UrmsB);
	PosCur(0,8);
	If_PutCosFi(FatPotB);
	PosCur(1,0);
	If_PutI(IrmsB);
	PosCur(1,9);
	If_PutP(PotAtivB);
	if (AtualizaDisplay==1) {PrtLcd("FB",0,14);}
#endif


}
void If_GeraTela05()
{
#if MODELO_DE_CONTROLADOR==CM4040
	PosCur(0,0);
	PosCur(0,0);
	PosCur(0,0);
	PosCur(0,0);
	If_PutV(UrmsC);
	PosCur(0,9);
	If_PutCosFi(FatPotC);
	PosCur(1,0);
	If_PutI(IrmsC);
	PosCur(1,9);
	If_PutP(PotAtivC);
	if (AtualizaDisplay==1){
		PosCur(0,15);
		WrLcdData(C_SYMB);
	}
#else
	PosCur(0,0);
	PosCur(0,0);
	PosCur(0,0);
	PosCur(0,0);
	If_PutV(UrmsC);
	PosCur(0,8);
	If_PutCosFi(FatPotC);
	PosCur(1,0);
	If_PutI(IrmsC);
	PosCur(1,9);
	If_PutP(PotAtivC);
	if (AtualizaDisplay==1) {PrtLcd("FC",0,14);}
#endif

}

void If_GeraTela06()
{
	PosCur(0,0);
	PosCur(0,0);
	PosCur(0,0);
	PosCur(0,0);
	If_PutP(PotAtivT);//If_PutP(Ptexibe);
	PosCur(1,0);
	If_PutQ(PotReatT);//If_PutQ(Qtexibe);
	PosCur(1,10);
	If_PutCosFi(FatPotT);//If_PutCosFi(CF_texibe);

#if MODELO_DE_CONTROLADOR==CM4040
	if (AtualizaDisplay==1){
		PosCur(0,14);
		WrLcdData('3');
		WrLcdData(FI_SYMB);
	}
#else

	PrtLcd("POT3F",0,11);


#endif



}
void If_GeraTela07()
{
	//if (AtualizaDisplay==1){PrtLcd("DHT[%]  Fase A  (V-I)",0,1);}
	PosCur(0,0);
	PosCur(0,0);
	PosCur(0,0);
	PosCur(0,0);
#if (MONO_TRI==TRIFASICO)
	PrtLcd("DHT[%]  Fase A",0,0);
#endif
#if (MONO_TRI==MONOFASICO)
	PrtLcd("DHT[%]        ",0,0);
#endif

	PrtLcd("(V-I)",1,0);
	PosCur(1,7);
	If_PutDht(DhtUA);
	PosCur(1,12);
	If_PutDht(DhtIA);
}

void If_GeraTela08()
{
	//if (AtualizaDisplay==1){PrtLcd("DHT[%]  Fase B  (V-I)",0,1);}
	PosCur(0,0);
	PosCur(0,0);
	PosCur(0,0);
	PosCur(0,0);
	PrtLcd("DHT[%]  Fase B",0,0);
	PrtLcd("(V-I)",1,0);
	PosCur(1,7);
	If_PutDht(DhtUB);
	PosCur(1,12);
	If_PutDht(DhtIB);
}

void If_GeraTela09()
{
	//if (AtualizaDisplay==1){PrtLcd("DHT[%]  Fase C  (V-I)",0,1);}
	PosCur(0,0);
	PosCur(0,0);
	PosCur(0,0);
	PosCur(0,0);
	PrtLcd("DHT[%]  Fase C",0,0);
	PrtLcd("(V-I)",1,0);
	PosCur(1,7);
	If_PutDht(DhtUC);
	PosCur(1,12);
	If_PutDht(DhtIC);
}

extern short modo_escritaMM;
extern long int etapa_escritaMM;
void If_GeraTela10()
{
	PosCur(0,0);
	PosCur(0,0);
	PosCur(0,0);
	PosCur(0,0);
	PrtLcd("V.F.: ",0,0);
	PrtLcdBcdNibble(versao_str[0],0);
	WrLcdData('.');
	PrtLcdBcdNibble(versao_str[1],0);
	PrtLcdBcdNibble(versao_str[2],0);
	If_SimbolosDoCantoEsquerdo();

	if (FLAG_TCC_INVERTIDO==1)
	{
		//FLAG_TCC_INVERTIDO..
		PosCur(1,0);
		PrtLcd((unsigned char *)sTela_msg11,1,0);
	}
	if (FLAG_TCB_INVERTIDO==1)
	{
		//FLAG_TCB_INVERTIDO..
		PosCur(1,0);
		PrtLcd((unsigned char *)sTela_msg10,1,0);
	}
	if (FLAG_TCA_INVERTIDO==1)
	{
		//FLAG_TCA_INVERTIDO..
		PosCur(1,0);
		PrtLcd((unsigned char *)sTela_msg09,1,0);
	}

	if ((FLAG_TCA_INVERTIDO==0)&&(FLAG_TCB_INVERTIDO==0)&&(FLAG_TCC_INVERTIDO==0))
	{
		PosCur(1,0);
		PrtLcd((unsigned char *)sTela_msg100,1,0);

	}

			   	#ifdef ATUALIZ_VIA_ETH
				if (modo_escritaMM==1){
					PosCur(1,0);
				 	If_PutI( (float)etapa_escritaMM);
				}
				#endif


}

void If_GeraTela11()
{

	RTCTime LocalTime;
	LocalTime=RTCGetTime();
	PosCur(0,0);
	PosCur(0,0);
	PosCur(0,0);
	PosCur(0,0);
	Sys_HexBcd(LocalTime.RTC_Mday);
	PrtLcdBcdNumber(Zaz[0]);
	WrLcdData('/');
	Sys_HexBcd(LocalTime.RTC_Mon);
	PrtLcdBcdNumber(Zaz[0]);
	WrLcdData('/');
	Sys_HexBcd(LocalTime.RTC_Year);
	PrtLcdBcdNumber(Zaz[0]);
	PosCur(1,0);
	Sys_HexBcd(LocalTime.RTC_Hour);
	PrtLcdBcdNumber(Zaz[0]);
	WrLcdData(':');
	Sys_HexBcd(LocalTime.RTC_Min);
	PrtLcdBcdNumber(Zaz[0]);
	WrLcdData(':');
	Sys_HexBcd(LocalTime.RTC_Sec);
	PrtLcdBcdNumber(Zaz[0]);

	if (FLAG_HORARIO_SEM_CONTROLE==ON)
	{
		PrtLcd("SEM",  0,10);
		PrtLcd("ATUAR",1,10);
	}
	else
	{
		PrtLcd("   ",  0,10);
		PrtLcd("     ",1,10);
	}
}

void If_GeraTela12()
{
	//RTCTime LocalTime;
	//LocalTime=RTCGetTime();
	PosCur(0,0);
	PosCur(0,0);
	PosCur(0,0);
	PosCur(0,0);
	PrtLcd("ENDERECO IP: ",0,0);
	PosCur(1,0);
	If_PutInt((unsigned int)ip_config.IpAdr[0]);
	WrLcdData('.');
	PosCur(1,4);
	If_PutInt((unsigned int)ip_config.IpAdr[1]);
	WrLcdData('.');
	PosCur(1,8);
	If_PutInt((unsigned int)ip_config.IpAdr[2]);
	WrLcdData('.');
	PosCur(1,12);
	If_PutInt((unsigned int)ip_config.IpAdr[3]);
	//Sys_HexBcd((short)ip_config.IpAdr[3]);
	//PrtLcdBcdNumber2(Zaz[3]);


	//PosCur(1,0);
	//Sys_HexBcd(LocalTime.RTC_Mday);
	//PrtLcdBcdNumber(Zaz[0]);
	//WrLcdData('.');
	//PrtLcdBcdNibble(IPOcteto2,0);
	//PrtLcdBcdNibble(IPOcteto3,0);
}

void If_GeraTela13()
{

	char strE[12];
	PrtLcd("T               ",0,0);
	FloatToStrForEnergy1(ConsumoT*0.001,&strE[0]);	//mudar algoritmo para permitir mais algaritmos
	PrtLcd(strE,0,2);
	PrtLcd("      ",0,10);
	PrtLcd("T",0,0);
	PrtLcd("Consumo    [KWh]",1,0);

}

void If_GeraTela14()
{
	char strE[12];
	PrtLcd("T               ",0,0);
	FloatToStrForEnergy1(EnergIndT*0.001,&strE[0]);	//mudar algoritmo para permitir mais algaritmos
	PrtLcd(strE,0,2);
	PrtLcd("      ",0,10);
	PrtLcd("T",0,0);
	PrtLcd("indutiv. [KVArh]",1,0);

/*
	int i = 0 , j = 0;

	for(i = 0; i < 16; i++)
	{
		j = i + 32;
		if(UART1BufferQuectel[j] == 10 || UART1BufferQuectel[j] == 13)
			UART1BufferQuectel[j] = 0;
		PrtLcd(&UART1BufferQuectel[j],0,i);
	}

	for(i = 0; i < 16; i++)
	{
		j = i + 48;
		if(UART1BufferQuectel[j] == 10 || UART1BufferQuectel[j] == 13)
			UART1BufferQuectel[j] = 0;
		PrtLcd(&UART1BufferQuectel[j],1,i);
	}
*/
}
void If_GeraTela15()
{
	char strE[12];
	PrtLcd("T               ",0,0);
	FloatToStrForEnergy1(EnergCapT*0.001,&strE[0]);  //mudar algoritmo para permitir mais algaritmos
	PrtLcd(strE,0,2);
	PrtLcd("      ",0,10);
	PrtLcd("T",0,0);
	PrtLcd("capacit. [KVArh]",1,0);
}
void If_GeraTela16()
{
	unsigned long int temp0;
	unsigned long int temp1;

	//temperatura_ptc_ch0 = 111.1;
	//temperatura_ptc_ch1 = 222.2;

	if(temperatura_ptc_ch0 < 0)
	{
		temperatura_ptc_ch0 = -temperatura_ptc_ch0;
		PrtLcd("-",0,7);
	}

	if(temperatura_ptc_ch1 < 0)
	{
		temperatura_ptc_ch1 = -temperatura_ptc_ch1;
		PrtLcd("-",1,7);
	}

	PrtLcd("TEMP1: ",0,0);
	PosCur(0,8);
	temp0=(unsigned long int)((float)temperatura_ptc_ch0*100);
	Sys_HexBcd(temp0);
	PrtLcdBcdNibble(Zaz[2],1);
	PrtLcdBcdNibble(Zaz[2],0);
   	PrtLcdBcdNibble(Zaz[1],1);
	PrtLcdBcdNibble(Zaz[1],0);
	WrLcdData('.');
	PrtLcdBcdNibble(Zaz[0],1);
	WrLcdData(223);
	WrLcdData('C');

	PrtLcd("TEMP2: ",1,0);
	PosCur(1,8);

	temp1=(unsigned long int)((float)temperatura_ptc_ch1*100);
	Sys_HexBcd(temp1);
	PrtLcdBcdNibble(Zaz[2],1);
	PrtLcdBcdNibble(Zaz[2],0);
   	PrtLcdBcdNibble(Zaz[1],1);
	PrtLcdBcdNibble(Zaz[1],0);
	/*
	WrLcdData('-');
	WrLcdData('-');
	WrLcdData('-');
	WrLcdData('-');
	WrLcdData('-');*/
	WrLcdData('.');
	PrtLcdBcdNibble(Zaz[0],1);
	WrLcdData(223);
	WrLcdData('C');
}

void If_GeraTela17()
{
	int i = 0 , j = 0;

	//if(gsm_uart_status == COMPLETE && gsm_ip_is_ready != 1)
	//{
		for(i = 0; i < 16; i++)
		{
			j = i;
			PrtLcd(&UART1BufferQuectel[j],0,i);
		}

		for(i = 0; i < 16; i++)
		{
			j = i + 16;
			PrtLcd(&UART1BufferQuectel[j],1,i);
		}
//	}

	if(gsm_ip_is_ready == 1)
	{
		PrtLcd("GSM (CONNECTED) ",0,0);

		for(i = 0; i < 16; i++)
		{
			if(UART1BufferIP[i] == 10 || UART1BufferIP[i] == 13)
				UART1BufferIP[i] = 0;
			PrtLcd(&UART1BufferIP[i],1,i);
		}
	}
}

void If_GeraFunc35()
{
	RTCTime LocalTime;
	PosCur(0,0);
	PosCur(0,0);
	PosCur(0,0);
	PosCur(0,0);
	PrtLcd("35-ALT. RELOGIO:",0,0);
	LocalTime=RTCGetTime();
	Sys_HexBcd(LocalTime.RTC_Mday);
	PosCur(1,0);
	PrtLcdBcdNumber(Zaz[0]);
	WrLcdData('/');
	Sys_HexBcd(LocalTime.RTC_Mon);
	PrtLcdBcdNumber(Zaz[0]);
	WrLcdData('/');
	Sys_HexBcd(LocalTime.RTC_Year);
	PrtLcdBcdNumber(Zaz[0]);
	WrLcdData(' ');
	Sys_HexBcd(LocalTime.RTC_Hour);
	PrtLcdBcdNumber(Zaz[0]);
	WrLcdData(':');
	Sys_HexBcd(LocalTime.RTC_Min);
	PrtLcdBcdNumber(Zaz[0]);
	// WrLcdData(' ');   WrLcdData(' ');
	leTeclado();

	switch (teclaAtual)
	{
		case TC_DOWN:
		case TC_UP:
			{
				If_NovoRTC();
				break;
			}
	}
}

void If_GeraFunc36()
{
//	RTCTime LocalTime;
	PosCur(0,0);
	PosCur(0,0);
	PosCur(0,0);
	PosCur(0,0);
	PrtLcd("36-ALTERAR IP:",0,0);
	//  LocalTime=RTCGetTime();
	PosCur(1,0);
	If_PutInt((unsigned int)ip_config.IpAdr[0]);
	WrLcdData('.');
	PosCur(1,4);
	If_PutInt((unsigned int)ip_config.IpAdr[1]);
	WrLcdData('.');
	PosCur(1,8);
	If_PutInt((unsigned int)ip_config.IpAdr[2]);
	WrLcdData('.');
	PosCur(1,12);
	If_PutInt((unsigned int)ip_config.IpAdr[3]);
	// WrLcdData(' ');   WrLcdData(' ');
	leTeclado();

	switch (teclaAtual)
	{
		case TC_DOWN:
		case TC_UP:
			{
				If_NovoEnderecoDeRede(PROG_IP);
				break;
			}
	}
}

void If_GeraFunc37()
{
//	RTCTime LocalTime;
	PosCur(0,0);
	PosCur(0,0);
	PosCur(0,0);
	PosCur(0,0);
	PrtLcd("37-ALTERAR MASK:",0,0);
	//  LocalTime=RTCGetTime();
	PosCur(1,0);
	If_PutInt((unsigned int)ip_config.NetMask[0]);
	WrLcdData('.');
	PosCur(1,4);
	If_PutInt((unsigned int)ip_config.NetMask[1]);
	WrLcdData('.');
	PosCur(1,8);
	If_PutInt((unsigned int)ip_config.NetMask[2]);
	WrLcdData('.');
	PosCur(1,12);
	If_PutInt((unsigned int)ip_config.NetMask[3]);
	// WrLcdData(' ');   WrLcdData(' ');
	leTeclado();

	switch (teclaAtual)
	{
		case TC_DOWN:
		case TC_UP:
			{
				If_NovoEnderecoDeRede(PROG_MASK);
				break;
			}
	}
}

void If_GeraFunc38()
{
//	RTCTime LocalTime;
	PosCur(0,0);
	PosCur(0,0);
	PosCur(0,0);
	PosCur(0,0);
	PrtLcd("38-MUDAR GTEWAY:",0,0);
	//  LocalTime=RTCGetTime();
	PosCur(1,0);
	If_PutInt((unsigned int)ip_config.DefGW[0]);
	WrLcdData('.');
	PosCur(1,4);
	If_PutInt((unsigned int)ip_config.DefGW[1]);
	WrLcdData('.');
	PosCur(1,8);
	If_PutInt((unsigned int)ip_config.DefGW[2]);
	WrLcdData('.');
	PosCur(1,12);
	If_PutInt((unsigned int)ip_config.DefGW[3]);
	// WrLcdData(' ');   WrLcdData(' ');
	leTeclado();

	switch (teclaAtual)
	{
		case TC_DOWN:
		case TC_UP:
			{
				If_NovoEnderecoDeRede(PROG_GATEWAY);
				break;
			}
	}
}

/*
   void If_GeraFunc37()
   {
   PrtLcd("36-SEM ATUACAO  ",0,0);
   PrtLcd("INICIO:         ",1,0);
   PosCur(1,8);

   PrtLcdBcdNumber(StatusFuncao[46]);
   WrLcdData(':');
   PrtLcdBcdNumber(StatusFuncao[47]);

   leTeclado();

   switch (teclaAtual)
   {
   case TC_DOWN:
   case TC_UP:
   {
   If_NovoSemControleInicio();
   break;
   }
   }
   }

   void If_GeraFunc38()
   {
   PrtLcd("37-SEM ATUACAO  ",0,0);
   PrtLcd("FIM:            ",1,0);
   PosCur(1,8);

   PrtLcdBcdNumber(StatusFuncao[48]);
   WrLcdData(':');
   PrtLcdBcdNumber(StatusFuncao[49]);

   leTeclado();

   switch (teclaAtual)
   {
   case TC_DOWN:
   case TC_UP:
   {
   If_NovoSemControleFim();
   break;
   }
   }
   }
 */

void If_NovoSemControleInicio()
{
	//xx/yy/zz 00:00
	unsigned char CurrentPos=1;
	unsigned long int acumulatempo=0;
	unsigned char HoraMSB,HoraLSB,MinMSB,MinLSB;
	//unsigned char EntrandoNaRotina=ON;


	HoraMSB=0x0F&(StatusFuncao[46]>>4);
	HoraLSB=0x0F&(StatusFuncao[46]);
	MinMSB=0x0F&(StatusFuncao[47]>>4);
	MinLSB=0x0F&(StatusFuncao[47]);

	Sys_Delay200Ms();
	Sys_Delay200Ms();

	teclaAtual=TC_NULL;
	ultimaTeclaExecutada=TC_ESC;

	while (teclaAtual!=TC_ESC)
	{
		toogleWDI();
		acumulatempo++;

		if (acumulatempo<120)
		{
			PosCur(1,8);
			PrtLcdBcdNibble(HoraMSB,0);
			PrtLcdBcdNibble(HoraLSB,0);
			WrLcdData(':');
			PrtLcdBcdNibble(MinMSB,0);
			PrtLcdBcdNibble(MinLSB,0);
		}

		if (acumulatempo>120)
		{
			switch(CurrentPos)
			{
				case 1:
					{
						PosCur(1,8);
						WrLcdData(TudoPretoSYMB);
						PrtLcdBcdNibble(HoraLSB,0);
						WrLcdData(':');
						PrtLcdBcdNibble(MinMSB,0);
						PrtLcdBcdNibble(MinLSB,0);

						break;
					}
				case 2:
					{
						PosCur(1,8);
						PrtLcdBcdNibble(HoraMSB,0);
						WrLcdData(TudoPretoSYMB);//PrtLcdBcdNibble(HoraLSB,0);
						WrLcdData(':');
						PrtLcdBcdNibble(MinMSB,0);
						PrtLcdBcdNibble(MinLSB,0);

						break;
					}
				case 3:
					{
						PosCur(1,8);
						PrtLcdBcdNibble(HoraMSB,0);
						PrtLcdBcdNibble(HoraLSB,0);
						WrLcdData(':');
						WrLcdData(TudoPretoSYMB);//PrtLcdBcdNibble(MinMSB,0);
						PrtLcdBcdNibble(MinLSB,0);

						break;
					}
				case 4:
					{
						PosCur(1,8);
						PrtLcdBcdNibble(HoraMSB,0);
						PrtLcdBcdNibble(HoraLSB,0);
						WrLcdData(':');
						PrtLcdBcdNibble(MinMSB,0);
						WrLcdData(TudoPretoSYMB);//PrtLcdBcdNibble(MinLSB,0);

						break;
					}
			}
		}
		if (acumulatempo> 240)
		{
			acumulatempo=0;
		}



		leTeclado();



		if (ultimaTeclaExecutada!=teclaAtual)
		{
			ultimaTeclaExecutada=teclaAtual;
			//plotagem na tela;
			if (teclaAtual==TC_DOWN)
			{

				if (CurrentPos==1) {
					if (HoraLSB>3)
					{
						If_IncDecAux1(&HoraMSB,1,0,-1);
					}
					else
					{
						If_IncDecAux1(&HoraMSB,2,0,-1);
					}
				}
				if (CurrentPos==2) {
					if (HoraMSB==2)
					{
						If_IncDecAux1(&HoraLSB,3,0,-1);
					}
					else
					{
						If_IncDecAux1(&HoraLSB,9,0,-1);
					}
				}
				if (CurrentPos==3) { if (MinMSB!=0) {MinMSB=MinMSB-1;} else {MinMSB=5;}}
				if (CurrentPos==4) { if (MinLSB!=0) {MinLSB=MinLSB-1;} else {MinLSB=9;}}

				/*
				   if (CurrentPos==1) { if (HoraMSB!=0) {HoraMSB=HoraMSB-1;} else {HoraMSB=9;}}
				   if (CurrentPos==2) { if (HoraLSB!=0) {HoraLSB=HoraLSB-1;} else {HoraLSB=9;}}
				   if (CurrentPos==3) { if (MinMSB!=0) {MinMSB=MinMSB-1;} else {MinMSB=9;}}
				   if (CurrentPos==4) { if (MinLSB!=0) {MinLSB=MinLSB-1;} else {MinLSB=9;}}
				 */
			}
			if (teclaAtual==TC_UP)
			{

				if (CurrentPos==1) {
					if (HoraLSB>3)
					{
						If_IncDecAux1(&HoraMSB,1,0,1);
					}
					else
					{
						If_IncDecAux1(&HoraMSB,2,0,1);
					}
				}
				if (CurrentPos==2) {
					if (HoraMSB==2)
					{
						If_IncDecAux1(&HoraLSB,3,0,1);
					}
					else
					{
						If_IncDecAux1(&HoraLSB,9,0,1);
					}
				}

				if (CurrentPos==3) { if (MinMSB!=5) {MinMSB=MinMSB+1;} else {MinMSB=0;}}
				if (CurrentPos==4){ if (MinLSB!=9) {MinLSB=MinLSB+1;} else {MinLSB=0;}}

				/*   if (CurrentPos==1) { if (HoraMSB!=9){HoraMSB=HoraMSB+1;} else {HoraMSB=0;}}
					 if (CurrentPos==2) { if (HoraLSB!=9){HoraLSB=HoraLSB+1;} else {HoraLSB=0;}}
					 if (CurrentPos==3) { if (MinMSB!=9) {MinMSB=MinMSB+1;} else {MinMSB=0;}}
					 if (CurrentPos==4){ if (MinLSB!=9) {MinLSB=MinLSB+1;} else {MinLSB=0;}}
				 */
			}
			if (teclaAtual==TC_RIGTH)
			{
				if (CurrentPos!=4) {CurrentPos=CurrentPos+1;}
				else {CurrentPos=1;}
			}
			if (teclaAtual==TC_LEFT)
			{
				if (CurrentPos!=1) {CurrentPos=CurrentPos-1;}
				else {CurrentPos=4;}
			}
			if (teclaAtual==TC_PRG)
			{
				StatusFuncao[46]	 =HoraMSB*0x10+HoraLSB;
				StatusFuncao[47]	 =MinMSB*0x10+ MinLSB;
				teclaAtual=TC_ESC;
			}

			PosCur(1,8);
			PrtLcdBcdNibble(HoraMSB,0);
			PrtLcdBcdNibble(HoraLSB,0);
			WrLcdData(':');
			PrtLcdBcdNibble(MinMSB,0);
			PrtLcdBcdNibble(MinLSB,0);

		}
	}
}

void If_NovoSemControleFim()
{
	//xx/yy/zz 00:00
	unsigned char CurrentPos=1;
	unsigned long int acumulatempo=0;
	unsigned char HoraMSB,HoraLSB,MinMSB,MinLSB;


	HoraMSB=0x0F&(StatusFuncao[48]>>4);
	HoraLSB=0x0F&(StatusFuncao[48]);
	MinMSB=0x0F&(StatusFuncao[49]>>4);
	MinLSB=0x0F&(StatusFuncao[49]);

	Sys_Delay200Ms();
	Sys_Delay200Ms();

	teclaAtual=TC_NULL;
	ultimaTeclaExecutada=TC_ESC;

	while (teclaAtual!=TC_ESC)
	{
		toogleWDI();
		acumulatempo++;

		if (acumulatempo<120)
		{
			PosCur(1,8);
			PrtLcdBcdNibble(HoraMSB,0);
			PrtLcdBcdNibble(HoraLSB,0);
			WrLcdData(':');
			PrtLcdBcdNibble(MinMSB,0);
			PrtLcdBcdNibble(MinLSB,0);
		}

		if (acumulatempo>120)
		{
			switch(CurrentPos)
			{
				case 1:
					{
						PosCur(1,8);
						WrLcdData(TudoPretoSYMB);
						PrtLcdBcdNibble(HoraLSB,0);
						WrLcdData(':');
						PrtLcdBcdNibble(MinMSB,0);
						PrtLcdBcdNibble(MinLSB,0);

						break;
					}
				case 2:
					{
						PosCur(1,8);
						PrtLcdBcdNibble(HoraMSB,0);
						WrLcdData(TudoPretoSYMB);//PrtLcdBcdNibble(HoraLSB,0);
						WrLcdData(':');
						PrtLcdBcdNibble(MinMSB,0);
						PrtLcdBcdNibble(MinLSB,0);

						break;
					}
				case 3:
					{
						PosCur(1,8);
						PrtLcdBcdNibble(HoraMSB,0);
						PrtLcdBcdNibble(HoraLSB,0);
						WrLcdData(':');
						WrLcdData(TudoPretoSYMB);//PrtLcdBcdNibble(MinMSB,0);
						PrtLcdBcdNibble(MinLSB,0);

						break;
					}
				case 4:
					{
						PosCur(1,8);
						PrtLcdBcdNibble(HoraMSB,0);
						PrtLcdBcdNibble(HoraLSB,0);
						WrLcdData(':');
						PrtLcdBcdNibble(MinMSB,0);
						WrLcdData(TudoPretoSYMB);//PrtLcdBcdNibble(MinLSB,0);

						break;
					}
			}
		}
		if (acumulatempo> 240)
		{
			acumulatempo=0;
		}



		leTeclado();

		if (ultimaTeclaExecutada!=teclaAtual)
		{
			ultimaTeclaExecutada=teclaAtual;
			//plotagem na tela;
			if (teclaAtual==TC_DOWN)
			{
				if (CurrentPos==1) {
					if (HoraLSB>3)
					{
						If_IncDecAux1(&HoraMSB,1,0,-1);
					}
					else
					{
						If_IncDecAux1(&HoraMSB,2,0,-1);
					}
				}
				if (CurrentPos==2)
				{
					if (HoraMSB==2)
					{
						If_IncDecAux1(&HoraLSB,3,0,-1);
					}
					else
					{
						If_IncDecAux1(&HoraLSB,9,0,-1);
					}
				}

				/*     if (CurrentPos==1) { if (HoraMSB!=0) {HoraMSB=HoraMSB-1;} else {HoraMSB=9;}}
					   if (CurrentPos==2) { if (HoraLSB!=0) {HoraLSB=HoraLSB-1;} else {HoraLSB=9;}}
				 */
				if (CurrentPos==3) { if (MinMSB!=0) {MinMSB=MinMSB-1;} else {MinMSB=9;}}
				if (CurrentPos==4) { if (MinLSB!=0) {MinLSB=MinLSB-1;} else {MinLSB=9;}}
			}
			if (teclaAtual==TC_UP)
			{
				if (CurrentPos==1)
				{
					if (HoraLSB>3)
					{
						If_IncDecAux1(&HoraMSB,1,0,1);
					}
					else
					{
						If_IncDecAux1(&HoraMSB,2,0,1);
					}
				}
				if (CurrentPos==2)
				{
					if (HoraMSB==2)
					{
						If_IncDecAux1(&HoraLSB,3,0,1);
					}
					else
					{
						If_IncDecAux1(&HoraLSB,9,0,1);
					}
				}

				/*
				   if (CurrentPos==1) { if (HoraMSB!=9){HoraMSB=HoraMSB+1;} else {HoraMSB=0;}}
				   if (CurrentPos==2) { if (HoraLSB!=9){HoraLSB=HoraLSB+1;} else {HoraLSB=0;}}
				 */

				if (CurrentPos==3) { if (MinMSB!=9) {MinMSB=MinMSB+1;} else {MinMSB=0;}}
				if (CurrentPos==4){ if (MinLSB!=9) {MinLSB=MinLSB+1;} else {MinLSB=0;}}

			}
			if (teclaAtual==TC_RIGTH)
			{
				if (CurrentPos!=4) {CurrentPos=CurrentPos+1;}
				else {CurrentPos=1;}
			}
			if (teclaAtual==TC_LEFT)
			{
				if (CurrentPos!=1) {CurrentPos=CurrentPos-1;}
				else {CurrentPos=4;}
			}
			if (teclaAtual==TC_PRG)
			{
				StatusFuncao[48]	 =HoraMSB*0x10+HoraLSB;
				StatusFuncao[49]	 =MinMSB*0x10+ MinLSB;
				teclaAtual=TC_ESC;
			}

			PosCur(1,8);
			PrtLcdBcdNibble(HoraMSB,0);
			PrtLcdBcdNibble(HoraLSB,0);
			WrLcdData(':');
			PrtLcdBcdNibble(MinMSB,0);
			PrtLcdBcdNibble(MinLSB,0);
		}
	}
}
////////////////////////Tela DE FUNCOES//////////////////////////////////
void If_GeraFunc1ao12(unsigned char Nfunc) //KVAR dos bancos
{
	unsigned char stat;
	stat=StatusFuncao[Nfunc];
	Sys_HexBcd(0x00000000|Nfunc);
	PosCur(0,0);
	PosCur(0,0);
	PosCur(0,0);
	PosCur(0,0);
	PrtLcd((unsigned char *)sTela_funcao1ao12a,0,0);
	PosCur(0,0);
	PrtLcdBcdNumber(Zaz[0]);
	PrtLcd((unsigned char *)sTela_funcao1ao12b,1,0);

	switch (stat)
	{
		case 0:  {PrtLcd((unsigned char *)valorKVAr00,1,6); break;}
		case 1:  {PrtLcd((unsigned char *)valorKVAr01,1,6); break;}
		case 2:  {PrtLcd((unsigned char *)valorKVAr02,1,6); break;}
		case 3:  {PrtLcd((unsigned char *)valorKVAr03,1,6); break;}
		case 4:  {PrtLcd((unsigned char *)valorKVAr04,1,6); break;}
		case 5:  {PrtLcd((unsigned char *)valorKVAr05,1,6); break;}
		case 6:  {PrtLcd((unsigned char *)valorKVAr06,1,6); break;}
		case 7:  {PrtLcd((unsigned char *)valorKVAr07,1,6); break;}
		case 8:  {PrtLcd((unsigned char *)valorKVAr08,1,6); break;}
		case 9:  {PrtLcd((unsigned char *)valorKVAr09,1,6); break;}
		case 10: {PrtLcd((unsigned char *)valorKVAr10,1,6); break;}
		case 11: {PrtLcd((unsigned char *)valorKVAr11,1,6); break;}
		case 12: {PrtLcd((unsigned char *)valorKVAr12,1,6); break;}
		case 13: {PrtLcd((unsigned char *)valorKVAr13,1,6); break;}
		case 14: {PrtLcd((unsigned char *)valorKVAr14,1,6); break;}
		case 15: {PrtLcd((unsigned char *)valorKVAr15,1,6); break;}
		case 16: {PrtLcd((unsigned char *)valorKVAr16,1,6); break;}
		case 17: {PrtLcd((unsigned char *)valorKVAr17,1,6); break;}
		case 18: {PrtLcd((unsigned char *)valorKVAr18,1,6); break;}
		case 19: {PrtLcd((unsigned char *)valorKVAr19,1,6); break;}
		case 20: {PrtLcd((unsigned char *)valorKVAr20,1,6); break;}
		case 21: {PrtLcd((unsigned char *)valorKVAr21,1,6); break;}
		case 22: {PrtLcd((unsigned char *)valorKVAr22,1,6); break;}
		case 23: {PrtLcd((unsigned char *)valorKVAr23,1,6); break;}
		case 24: {PrtLcd((unsigned char *)valorKVAr24,1,6); break;}
		case 25: {PrtLcd((unsigned char *)valorKVAr25,1,6); break;}
		case 26: {PrtLcd((unsigned char *)valorKVAr26,1,6); break;}
		case 27: {PrtLcd((unsigned char *)valorKVAr27,1,6); break;}
		case 28: {PrtLcd((unsigned char *)valorKVAr28,1,6); break;}
		case 29: {PrtLcd((unsigned char *)valorKVAr29,1,6); break;}
	}
}


void If_GeraFunc13()  // "13-PF INF. LIMIT"
{
	StatusDaFuncaoA=StatusFuncao[13];
	StatusDaFuncaoB=StatusFuncao[14];
	PosCur(0,0);
	PosCur(0,0);
	PosCur(0,0);
	PosCur(0,0);
	PrtLcd((unsigned char *)sTela_funcao13,0,0);
	If_GeraFunc13ao14();
}

void If_GeraFunc14()  // "14-PF SUP. LIMIT"
{
	StatusDaFuncaoA=StatusFuncao[13];
	StatusDaFuncaoB=StatusFuncao[14];
	PosCur(0,0);
	PosCur(0,0);
	PosCur(0,0);
	PosCur(0,0);
	PrtLcd((unsigned char *)sTela_funcao14,0,0);
	If_GeraFunc13ao14();
}

void If_GeraFunc13ao14()
{
	char sinal13=0,sinal14=0;
	unsigned char stat13,stat14;
	PosCur(0,0);
	PosCur(0,0);
	PosCur(0,0);
	PosCur(0,0);
	PosCur(1,0);
	stat13=StatusDaFuncaoA;
	stat14=StatusDaFuncaoB;
	if (StatusDaFuncaoA>100) {sinal13=1; stat13=200-StatusDaFuncaoA;}
	if (StatusDaFuncaoB>100) {sinal14=1; stat14=200-StatusDaFuncaoB;}
	if (sinal13) {WrLcdData('-');} else {WrLcdData(' ');}
	Sys_HexBcd(0x00000000|stat13);
	PrtLcdBcdNibble(Zaz[1],0);
	WrLcdData('.');
	PrtLcdBcdNumber(Zaz[0]);
	PrtLcd("     ",1,5);
	if (sinal14) {WrLcdData('-');} else {WrLcdData(' ');}
	Sys_HexBcd(0x00000000|stat14);
	PrtLcdBcdNibble(Zaz[1],0);
	WrLcdData('.');
	PrtLcdBcdNumber(Zaz[0]);
	WrLcdData(' ');
}


void If_GeraFunc15()	// "15-TRIGGER TIME"
{
	PosCur(0,0);
	PosCur(0,0);
	PosCur(0,0);
	PosCur(0,0);
	PrtLcd((unsigned char *)sTela_funcao15a,0,0);
	PrtLcd("     ",1,0);
	switch (StatusFuncao[15])
	{
		case 0:  {PrtLcd((unsigned char *)valorTD00,1,3); break;}
		case 1:  {PrtLcd((unsigned char *)valorTD01,1,3); break;}
		case 2:  {PrtLcd((unsigned char *)valorTD02,1,3); break;}
		case 3:  {PrtLcd((unsigned char *)valorTD03,1,3); break;}
		case 4:  {PrtLcd((unsigned char *)valorTD04,1,3); break;}
		case 5:  {PrtLcd((unsigned char *)valorTD05,1,3); break;}
		case 6:  {PrtLcd((unsigned char *)valorTD06,1,4); break;}
		case 7:  {PrtLcd((unsigned char *)valorTD07,1,4); break;}

		case 8:  {PrtLcd((unsigned char *)valorTD08,1,4); break;}
		case 9:  {PrtLcd((unsigned char *)valorTD09,1,4); break;}
		case 10: {PrtLcd((unsigned char *)valorTD10,1,4); break;}
		case 11: {PrtLcd((unsigned char *)valorTD11,1,3); break;}
		case 12: {PrtLcd((unsigned char *)valorTD12,1,3); break;}
	}

	WrLcdData(' ');
	WrLcdData(' ');
	if (StatusFuncao[15]>6)
	{
		PrtLcd((unsigned char *)sTela_funcao15c,1,8);
	}
	else
	{
		PrtLcd((unsigned char *)sTela_funcao15b,1,8);
	}
	PrtLcd("       ",1,11);
}



void If_GeraFunc16()   //"16-PT RATIO:    "
{
	PosCur(0,0);
	PosCur(0,0);
	PosCur(0,0);
	PosCur(0,0);
	PrtLcd((unsigned char *)sTela_funcao16,0,0);
	//If_MostraRel(PrimarioTP,SecundarioTP);
	If_MostraRel(relacaoTPpri*relacaoTPfat,relacaoTPsec);
	leTeclado();
	switch (teclaAtual)
	{
		case TC_DOWN:
			{
				If_NovaRel(R_TP);
				break;
			}
		case TC_UP:
			{
				If_NovaRel(R_TP);
				break;
			}
	}
}



void If_GeraFunc17()   //"17-CT RATIO:    "
{
	PosCur(0,0);
	PosCur(0,0);
	PosCur(0,0);
	PosCur(0,0);
	PrtLcd((unsigned char *)sTela_funcao17,0,0);
	If_MostraRel(relacaoTCpri,relacaoTCsec);
	leTeclado();
	switch (teclaAtual)
	{
		case TC_DOWN:
			{
				If_NovaRel(R_TC);
				break;
			}
		case TC_UP:
			{
				If_NovaRel(R_TC);
				break;
			}
	}
}



void If_MostraRel(unsigned int pri,unsigned int sec)
{
	Sys_HexBcd(pri);
	PosCur(1,3);
	PrtLcdBcdNibble(Zaz[2],0);
	PrtLcdBcdNumber(Zaz[1]);
	PrtLcdBcdNumber(Zaz[0]);
	WrLcdData('/');
	Sys_HexBcd(sec);
	PrtLcdBcdNibble(Zaz[1],0);
	PrtLcdBcdNumber(Zaz[0]);
	PosCur(1,12);
	WrLcdData(' ');
	WrLcdData(' ');
	WrLcdData(' ');
	WrLcdData(' ');

}

/*
   void If_NovaRel(unsigned char tipo)
   {
   unsigned char algarismo=9; //vale 1(menos significativo),2,3... ou 8(mais significativo)
   unsigned char se1,se2,se3,se4,se5,se6,se7,se8;

   if (tipo==R_TP)
   {
//SecundarioLocal=SecundarioTP;
//PrimarioLocal=PrimarioTP;
PrimarioLocal=	 (short)(relacaoTPpri*relacaoTPfat);
SecundarioLocal=(short)(relacaoTPsec);
}

if (tipo==R_TC)
{
// SecundarioLocal=SecundarioTC;
//PrimarioLocal=PrimarioTC;
PrimarioLocal=	 (short)((float)relacaoTCpri*relacaoTCfat);
SecundarioLocal=(short)(relacaoTCsec);
}

Sys_HexBcd(SecundarioLocal);
se1=Z[0]&0xF;
se2=((Z[0]&0xF0)>>4);
se3=Z[1]&0xF;
Sys_HexBcd(PrimarioLocal);
se4=Z[0]&0xF;
se5=((Z[0]&0xF0)>>4);
se6=Z[1]&0xF;
se7=((Z[1]&0xF0)>>4);
se8=Z[2]&0xF;

while (teclaAtual!=TC_ESC)
{
toogleWDI();
PosCur(1,12-algarismo);
Sys_Delay200Ms();
toogleWDI();
WrLcdData(TudoPretoSYMB);
Sys_Delay200Ms();
//plotagem na tela;
If_MostraRel(PrimarioLocal,SecundarioLocal);
teclaAtual=TC_NULL;
leTeclado();

if (teclaAtual==TC_DOWN)
{
if (algarismo==1)  { if (se1!=0) {se1=se1-1;} else {se1=9;}}
if (algarismo==2)  { if (se2!=0) {se2=se2-1;} else {se2=9;}}
if (algarismo==3)  { if (se3!=0) {se3=se3-1;} else {se3=9;}}
if (algarismo==5)  { if (se4!=0) {se4=se4-1;} else {se4=9;}}
if (algarismo==6)  { if (se5!=0) {se5=se5-1;} else {se5=9;}}
if (algarismo==7)  { if (se6!=0) {se6=se6-1;} else {se6=9;}}
if (algarismo==8)  { if (se7!=0) {se7=se7-1;} else {se7=9;}}
if (algarismo==9)  { if (se8!=0) {se8=se8-1;} else {se8=1;}}

SecundarioLocal=se1+(unsigned int)se2*10+(unsigned int)se3*100;
PrimarioLocal=  se4+(unsigned int)se5*10+(unsigned int)se6*100+(unsigned int)se7*1000+(unsigned int)se8*10000;

}
if (teclaAtual==TC_UP)
{
if (algarismo==1)  { if (se1!=9) {se1=se1+1;} else {se1=0;}}
if (algarismo==2)  { if (se2!=9) {se2=se2+1;} else {se2=0;}}
if (algarismo==3)  { if (se3!=9) {se3=se3+1;} else {se3=0;}}
if (algarismo==5)  { if (se4!=9) {se4=se4+1;} else {se4=0;}}
if (algarismo==6)  { if (se5!=9) {se5=se5+1;} else {se5=0;}}
if (algarismo==7)  { if (se6!=9) {se6=se6+1;} else {se6=0;}}
if (algarismo==8)  { if (se7!=9) {se7=se7+1;} else {se7=0;}}
if (algarismo==9)  { if (se8!=1) {se8=se8+1;} else {se8=0;}}

SecundarioLocal=se1+(unsigned int)se2*10+(unsigned int)se3*100;
PrimarioLocal=  se4+(unsigned int)se5*10+(unsigned int)se6*100+(unsigned int)se7*1000+(unsigned int)se8*10000;
}
if (PrimarioLocal==0){se4=1; PrimarioLocal=1;}
if (SecundarioLocal==0){se1=1; SecundarioLocal=1;}


if (teclaAtual==TC_LEFT)
{
	algarismo=algarismo+1;
	if (algarismo==4) {algarismo=5;}
	if (algarismo==10) {algarismo=1;}
}
if (teclaAtual==TC_RIGTH)
{
	algarismo=algarismo-1;
	if (algarismo==4) {algarismo=3;}
	if (algarismo==0) {algarismo=9;}
}
if (teclaAtual==TC_PRG)
{
	SecundarioLocal=se1+(unsigned int)se2*10+(unsigned int)se3*100;
	PrimarioLocal=  se4+(unsigned int)se5*10+(unsigned int)se6*100+(unsigned int)se7*1000+(unsigned int)se8*10000;
	tptc.tptc_i=PrimarioLocal;
	StatusFuncao[38+tipo]=tptc.tptc_c[1];
	StatusFuncao[37+tipo]=tptc.tptc_c[0];
	tptc.tptc_i=SecundarioLocal;
	StatusFuncao[40+tipo]=tptc.tptc_c[1];
	StatusFuncao[39+tipo]=tptc.tptc_c[0];
	teclaAtual=TC_ESC;
	if (tipo==R_TP) {
		//PrimarioTP=PrimarioLocal; SecundarioTP=SecundarioLocal;
		relacaoTPfat=1;
		relacaoTPpri=PrimarioLocal;
		relacaoTPsec=SecundarioLocal;
	}
	if (tipo==R_TC) {
		//PrimarioTC=PrimarioLocal; SecundarioTC=SecundarioLocal;
		relacaoTCfat=1;
		relacaoTCpri=PrimarioLocal;
		relacaoTCsec=SecundarioLocal;
	}
}
}
}
*/

void If_NovaRel(unsigned char tipo)
{
	unsigned char algarismo=9; //vale 1(menos significativo),2,3... ou 8(mais significativo)
	unsigned char se1,se2,se3,se4,se5,se6,se7,se8;
	unsigned long int acumulatempo=0;


	if (tipo==R_TP)
	{
		PrimarioLocal=	 (short)(relacaoTPpri*relacaoTPfat);
		SecundarioLocal=(short)(relacaoTPsec);
	}

	if (tipo==R_TC)
	{
		PrimarioLocal=	 (short)((float)relacaoTCpri*relacaoTCfat);
		SecundarioLocal=(short)(relacaoTCsec);
	}

	Sys_HexBcd(SecundarioLocal);
	se1=Zaz[0]&0xF;
	se2=((Zaz[0]&0xF0)>>4);
	se3=Zaz[1]&0xF;
	Sys_HexBcd(PrimarioLocal);
	se4=Zaz[0]&0xF;
	se5=((Zaz[0]&0xF0)>>4);
	se6=Zaz[1]&0xF;
	se7=((Zaz[1]&0xF0)>>4);
	se8=Zaz[2]&0xF;
	If_MostraRel(PrimarioLocal,SecundarioLocal);

	teclaAtual=TC_NULL;
	ultimaTeclaExecutada=TC_ESC;
	Sys_Delay200Ms();
	Sys_Delay200Ms();
	while (teclaAtual!=TC_ESC)
	{
		toogleWDI();
		acumulatempo++;

		if (acumulatempo<240)
		{
			If_MostraRel(PrimarioLocal,SecundarioLocal);
		}

		if (acumulatempo>240)
		{
			//If_MostraRel(PrimarioLocal,SecundarioLocal); //comentado por cesar
			PosCur(1,12-algarismo);
			WrLcdData(TudoPretoSYMB);
		}

		if (acumulatempo>480)
		{
			acumulatempo=0;
		}

		leTeclado();

		if (ultimaTeclaExecutada!=teclaAtual)
		{
			ultimaTeclaExecutada=teclaAtual;
			//plotagem na tela;
			if (teclaAtual==TC_DOWN)
			{
				if (algarismo==1)  { if (se1!=0) {se1=se1-1;} else {se1=9;}}
				if (algarismo==2)  { if (se2!=0) {se2=se2-1;} else {se2=9;}}
				if (algarismo==3)  { if (se3!=0) {se3=se3-1;} else {se3=9;}}
				if (algarismo==5)  { if (se4!=0) {se4=se4-1;} else {se4=9;}}
				if (algarismo==6)  { if (se5!=0) {se5=se5-1;} else {se5=9;}}
				if (algarismo==7)  { if (se6!=0) {se6=se6-1;} else {se6=9;}}
				if (algarismo==8)  { if (se7!=0) {se7=se7-1;} else {se7=9;}}
				if (algarismo==9)  { if (se8!=0) {se8=se8-1;} else {se8=1;}}

				SecundarioLocal=se1+(unsigned int)se2*10+(unsigned int)se3*100;
				PrimarioLocal=  se4+(unsigned int)se5*10+(unsigned int)se6*100+(unsigned int)se7*1000+(unsigned int)se8*10000;

			}
			if (teclaAtual==TC_UP)
			{
				if (algarismo==1)  { if (se1!=9) {se1=se1+1;} else {se1=0;}}
				if (algarismo==2)  { if (se2!=9) {se2=se2+1;} else {se2=0;}}
				if (algarismo==3)  { if (se3!=9) {se3=se3+1;} else {se3=0;}}
				if (algarismo==5)  { if (se4!=9) {se4=se4+1;} else {se4=0;}}
				if (algarismo==6)  { if (se5!=9) {se5=se5+1;} else {se5=0;}}
				if (algarismo==7)  { if (se6!=9) {se6=se6+1;} else {se6=0;}}
				if (algarismo==8)  { if (se7!=9) {se7=se7+1;} else {se7=0;}}
				if (algarismo==9)  { if (se8!=1) {se8=se8+1;} else {se8=0;}}

				SecundarioLocal=se1+(unsigned int)se2*10+(unsigned int)se3*100;
				PrimarioLocal=  se4+(unsigned int)se5*10+(unsigned int)se6*100+(unsigned int)se7*1000+(unsigned int)se8*10000;
			}

			if (PrimarioLocal==0){se4=1; PrimarioLocal=1;}
			if (SecundarioLocal==0){se1=1; SecundarioLocal=1;}


			if (teclaAtual==TC_LEFT)
			{
				algarismo=algarismo+1;
				if (algarismo==4) {algarismo=5;}
				if (algarismo==10) {algarismo=1;}
			}
			if (teclaAtual==TC_RIGTH)
			{
				algarismo=algarismo-1;
				if (algarismo==4) {algarismo=3;}
				if (algarismo==0) {algarismo=9;}
			}
			if (teclaAtual==TC_PRG)
			{
				SecundarioLocal=se1+(unsigned int)se2*10+(unsigned int)se3*100;
				PrimarioLocal=  se4+(unsigned int)se5*10+(unsigned int)se6*100+(unsigned int)se7*1000+(unsigned int)se8*10000;
				tptc.tptc_i=PrimarioLocal;
				StatusFuncao[38+tipo]=tptc.tptc_c[1];
				StatusFuncao[37+tipo]=tptc.tptc_c[0];
				tptc.tptc_i=SecundarioLocal;
				StatusFuncao[40+tipo]=tptc.tptc_c[1];
				StatusFuncao[39+tipo]=tptc.tptc_c[0];
				teclaAtual=TC_ESC;
				if (tipo==R_TP) {
					//PrimarioTP=PrimarioLocal; SecundarioTP=SecundarioLocal;

					relacaoTPfat =1;
					relacaoTPpri =PrimarioLocal;
					relacaoTPsec =SecundarioLocal;
				}
				if (tipo==R_TC) {
					//PrimarioTC=PrimarioLocal; SecundarioTC=SecundarioLocal;
					relacaoTCfat =1;
					relacaoTCpri =PrimarioLocal;
					relacaoTCsec =SecundarioLocal;
				}
			}
		}
	}
}

/*
	Coloca na tela os digitos (buffer com 12 digitos) no formato XXX.XXX.XXX.XXX
*/
void print_endereco_rede(unsigned short *digito, unsigned char posicao_cursor, unsigned char printar_cursor)
{
	char cnt = 0;
	char i;

	PosCur(1,0);
	for(i = 1; i <= 15; i++)
	{
		if(i == 4 || i == 8 || i == 12)
		{
			WrLcdData('.');
		}
		else
		{
			cnt++;

			if(cnt == posicao_cursor && printar_cursor == 1)
				WrLcdData(TudoPretoSYMB);
			else
				PrtLcdBcdNibble((char)digito[cnt],0);

		}
	}
}

/*
	Salva enderecos de rede (IP, Mask, Gateway)
*/
void salva_enderecos_de_rede(U8 *endereco, unsigned short *digito)
{
	unsigned short endereco_aux[4];
	unsigned char i;

	endereco_aux[0] = digito[1] 	* 100 + digito[2] 	* 10 + digito[3];
	endereco_aux[1] = digito[4] 	* 100 + digito[5] 	* 10 + digito[6];
	endereco_aux[2] = digito[7] 	* 100 + digito[8] 	* 10 + digito[9];
	endereco_aux[3] = digito[10] 	* 100 + digito[11] 	* 10 + digito[12];

	for(i = 0; i < 4; i++)
	{
		if(endereco_aux[i] > 255)
			endereco[i] = 255;
		else
			endereco[i] = endereco_aux[i];
	}

	IPOcteto1 = ip_config.IpAdr[0];           // Local IP Address
	IPOcteto2 = ip_config.IpAdr[1];           // Local IP Address
	IPOcteto3 = ip_config.IpAdr[2];           // Local IP Address
	IPOcteto4 = ip_config.IpAdr[3];           // Local IP Address
	GWOcteto1 = ip_config.DefGW[0];           // Default GateWay
	GWOcteto2 = ip_config.DefGW[1];           // Default GateWay
	GWOcteto3 = ip_config.DefGW[2];           // Default GateWay
	GWOcteto4 = ip_config.DefGW[3];           // Default GateWay
	MKOcteto1 = ip_config.NetMask[0];         // Net Mask
	MKOcteto2 = ip_config.NetMask[1];         // Net Mask
	MKOcteto3 = ip_config.NetMask[2];         // Net Mask
	MKOcteto4 = ip_config.NetMask[3];         // Net Mask
}

/*
  	Decomposi��o do endere�o de rede em digitos separados
*/
void transforma_endereco_de_rede_em_digitos(U8 *endereco, unsigned short *digito, RTCTime LocalTime)
{
	Sys_HexBcd((unsigned long int)endereco[0]);
	digito[2] = (unsigned short)(0x0F & (Zaz[0] >> 4));
	digito[3] = (unsigned short)(0x0F & (Zaz[0]));
	digito[1] = (unsigned short)(0x0F & (Zaz[1]));
	Sys_HexBcd((unsigned long int)endereco[1]);
	digito[5] = (unsigned short)(0x0F & (Zaz[0] >> 4));
	digito[6] = (unsigned short)(0x0F & (Zaz[0]));
	digito[4] = (unsigned short)(0x0F & (Zaz[1]));
	Sys_HexBcd((unsigned long int)endereco[2]);
	digito[8] = (unsigned short)(0x0F & (Zaz[0] >> 4));
	digito[9] = (unsigned short)(0x0F & (Zaz[0]));
	digito[7] = (unsigned short)(0x0F & (Zaz[1]));
	Sys_HexBcd((unsigned long int)endereco[3]);
	digito[11] = (unsigned short)(0x0F & (Zaz[0] >> 4));
	digito[12] = (unsigned short)(0x0F & (Zaz[0]));
	digito[10] = (unsigned short)(0x0F & (Zaz[1]));
	Sys_HexBcd(LocalTime.RTC_Min);
}

void If_NovoEnderecoDeRede(char tipo_de_endereco)
{
	RTCTime LocalTime;
	unsigned char CurrentPos = 1;
	unsigned short digito[13];
	unsigned long int cnt = 0;
	U8 *endereco;

	LocalTime = RTCGetTime();

	if(tipo_de_endereco == PROG_IP)
	{
		endereco = &ip_config.IpAdr[0];
		PrtLcd("36-ALTERAR IP:",0,0);
	}
	if(tipo_de_endereco == PROG_MASK)
	{
		endereco = &ip_config.NetMask[0];
		PrtLcd("37-ALTERAR MASK:",0,0);
	}
	if(tipo_de_endereco == PROG_GATEWAY)
	{
		endereco = &ip_config.DefGW[0];
		PrtLcd("38-MUDAR GTEWAY:",0,0);
	}

	transforma_endereco_de_rede_em_digitos(endereco, &digito[0], LocalTime);

	Sys_Delay200Ms();

	teclaAtual = TC_NULL;
	ultimaTeclaExecutada = TC_ESC;

	while (teclaAtual != TC_ESC)
	{
		toogleWDI();

		cnt = (cnt + 1) % CURSOR_TIME_ON;

		if (cnt < CURSOR_TIME_ON / 2)
			print_endereco_rede(&digito[0], NULL, NULL);
		else
			print_endereco_rede(&digito[0], CurrentPos, 1);

		leTeclado();

		if (ultimaTeclaExecutada != teclaAtual)
		{
			ultimaTeclaExecutada = teclaAtual;

			switch (teclaAtual)
			{
				case TC_DOWN:
					if(digito[CurrentPos] == 0)
					{
						if(CurrentPos == 1 || CurrentPos == 4 || CurrentPos == 7 || CurrentPos == 10)
							digito[CurrentPos] = 2;
						else
							digito[CurrentPos] = 9;
					}
					else
						digito[CurrentPos]--;
				break;

				case TC_UP:
					digito[CurrentPos]++;

					if(CurrentPos == 1 || CurrentPos == 4 || CurrentPos == 7 || CurrentPos == 10)
					{
						if (digito[CurrentPos] > 2)
							digito[CurrentPos] = 0;
					}
					else
					{
						if (digito[CurrentPos] > 9)
							digito[CurrentPos] = 0;
					}
				break;

				case TC_RIGTH:
					if (CurrentPos != 12)
						CurrentPos = CurrentPos + 1;
					else
						CurrentPos = 1;
				break;

				case TC_LEFT:
					if (CurrentPos != 1)
						CurrentPos = CurrentPos - 1;
					else
						CurrentPos = 12;
				break;

				case TC_PRG:
					salva_enderecos_de_rede(endereco, &digito[0]);

					SalvaParametrizacao();
					teclaAtual=TC_ESC;
				break;
			}

			print_endereco_rede(&digito[0], NULL, NULL);
		}
	}
}

void If_NovoRTC()
{
	//xx/yy/zz 00:00
	RTCTime LocalTime;
	unsigned char CurrentPos=1;
	unsigned long int acumulatempo=0;
	unsigned char HoraMSB,HoraLSB,MinMSB,MinLSB;
	unsigned char DiaMSB,DiaLSB,MesMSB,MesLSB,AnoMSB,AnoLSB;
	LocalTime=RTCGetTime();

	Sys_HexBcd(LocalTime.RTC_Year);
	AnoMSB=0x0F&(Zaz[0]>>4);
	AnoLSB=0x0F&(Zaz[0]);
	Sys_HexBcd(LocalTime.RTC_Mon);
	MesMSB=0x0F&(Zaz[0]>>4);
	MesLSB=0x0F&(Zaz[0]);
	Sys_HexBcd(LocalTime.RTC_Mday);
	DiaMSB=0x0F&(Zaz[0]>>4);
	DiaLSB=0x0F&(Zaz[0]);
	Sys_HexBcd(LocalTime.RTC_Hour);
	HoraMSB=0x0F&(Zaz[0]>>4);
	HoraLSB=0x0F&(Zaz[0]);
	Sys_HexBcd(LocalTime.RTC_Min);
	MinMSB=0x0F&(Zaz[0]>>4);
	MinLSB=0x0F&(Zaz[0]);

	Sys_Delay200Ms();
	Sys_Delay200Ms();

	teclaAtual=TC_NULL;
	ultimaTeclaExecutada=TC_ESC;
	PrtLcd("35-ALT. RELOGIO:",0,0);

	while (teclaAtual!=TC_ESC)
	{
		toogleWDI();
		acumulatempo++;

		if (acumulatempo<60)
		{
			PosCur(1,0);
			PrtLcdBcdNibble(DiaMSB,0);
			PrtLcdBcdNibble(DiaLSB,0);
			WrLcdData('/');
			PrtLcdBcdNibble(MesMSB,0);
			PrtLcdBcdNibble(MesLSB,0);
			WrLcdData('/');
			PrtLcdBcdNibble(AnoMSB,0);
			PrtLcdBcdNibble(AnoLSB,0);
			WrLcdData(' ');
			PrtLcdBcdNibble(HoraMSB,0);
			PrtLcdBcdNibble(HoraLSB,0);
			WrLcdData(':');
			PrtLcdBcdNibble(MinMSB,0);
			PrtLcdBcdNibble(MinLSB,0);
		}

		if (acumulatempo>60)
		{
			switch(CurrentPos)
			{
				case 1:
					{
						PosCur(1,0);
						WrLcdData(TudoPretoSYMB);//PrtLcdBcdNibble(DiaMSB,0);
						PrtLcdBcdNibble(DiaLSB,0);
						WrLcdData('/');
						PrtLcdBcdNibble(MesMSB,0);
						PrtLcdBcdNibble(MesLSB,0);
						WrLcdData('/');
						PrtLcdBcdNibble(AnoMSB,0);
						PrtLcdBcdNibble(AnoLSB,0);
						WrLcdData(' ');
						PrtLcdBcdNibble(HoraMSB,0);
						PrtLcdBcdNibble(HoraLSB,0);
						WrLcdData(':');
						PrtLcdBcdNibble(MinMSB,0);
						PrtLcdBcdNibble(MinLSB,0);

						break;
					}
				case 2:
					{
						PosCur(1,0);
						PrtLcdBcdNibble(DiaMSB,0);
						WrLcdData(TudoPretoSYMB);//PrtLcdBcdNibble(DiaLSB,0);
						WrLcdData('/');
						PrtLcdBcdNibble(MesMSB,0);
						PrtLcdBcdNibble(MesLSB,0);
						WrLcdData('/');
						PrtLcdBcdNibble(AnoMSB,0);
						PrtLcdBcdNibble(AnoLSB,0);
						WrLcdData(' ');
						PrtLcdBcdNibble(HoraMSB,0);
						PrtLcdBcdNibble(HoraLSB,0);
						WrLcdData(':');
						PrtLcdBcdNibble(MinMSB,0);
						PrtLcdBcdNibble(MinLSB,0);

						break;
					}
				case 3:
					{
						PosCur(1,0);
						PrtLcdBcdNibble(DiaMSB,0);
						PrtLcdBcdNibble(DiaLSB,0);
						WrLcdData('/');
						WrLcdData(TudoPretoSYMB);//PrtLcdBcdNibble(MesMSB,0);
						PrtLcdBcdNibble(MesLSB,0);
						WrLcdData('/');
						PrtLcdBcdNibble(AnoMSB,0);
						PrtLcdBcdNibble(AnoLSB,0);
						WrLcdData(' ');
						PrtLcdBcdNibble(HoraMSB,0);
						PrtLcdBcdNibble(HoraLSB,0);
						WrLcdData(':');
						PrtLcdBcdNibble(MinMSB,0);
						PrtLcdBcdNibble(MinLSB,0);

						break;
					}
				case 4:
					{
						PosCur(1,0);
						PrtLcdBcdNibble(DiaMSB,0);
						PrtLcdBcdNibble(DiaLSB,0);
						WrLcdData('/');
						PrtLcdBcdNibble(MesMSB,0);
						WrLcdData(TudoPretoSYMB);//PrtLcdBcdNibble(MesLSB,0);
						WrLcdData('/');
						PrtLcdBcdNibble(AnoMSB,0);
						PrtLcdBcdNibble(AnoLSB,0);
						WrLcdData(' ');
						PrtLcdBcdNibble(HoraMSB,0);
						PrtLcdBcdNibble(HoraLSB,0);
						WrLcdData(':');
						PrtLcdBcdNibble(MinMSB,0);
						PrtLcdBcdNibble(MinLSB,0);

						break;
					}
				case 5:
					{
						PosCur(1,0);
						PrtLcdBcdNibble(DiaMSB,0);
						PrtLcdBcdNibble(DiaLSB,0);
						WrLcdData('/');
						PrtLcdBcdNibble(MesMSB,0);
						PrtLcdBcdNibble(MesLSB,0);
						WrLcdData('/');
						WrLcdData(TudoPretoSYMB);//PrtLcdBcdNibble(AnoMSB,0);
						PrtLcdBcdNibble(AnoLSB,0);
						WrLcdData(' ');
						PrtLcdBcdNibble(HoraMSB,0);
						PrtLcdBcdNibble(HoraLSB,0);
						WrLcdData(':');
						PrtLcdBcdNibble(MinMSB,0);
						PrtLcdBcdNibble(MinLSB,0);

						break;
					}
				case 6:
					{
						PosCur(1,0);
						PrtLcdBcdNibble(DiaMSB,0);
						PrtLcdBcdNibble(DiaLSB,0);
						WrLcdData('/');
						PrtLcdBcdNibble(MesMSB,0);
						PrtLcdBcdNibble(MesLSB,0);
						WrLcdData('/');
						PrtLcdBcdNibble(AnoMSB,0);
						WrLcdData(TudoPretoSYMB);//PrtLcdBcdNibble(AnoLSB,0);
						WrLcdData(' ');
						PrtLcdBcdNibble(HoraMSB,0);
						PrtLcdBcdNibble(HoraLSB,0);
						WrLcdData(':');
						PrtLcdBcdNibble(MinMSB,0);
						PrtLcdBcdNibble(MinLSB,0);

						break;
					}
				case 7:
					{
						PosCur(1,0);
						PrtLcdBcdNibble(DiaMSB,0);
						PrtLcdBcdNibble(DiaLSB,0);
						WrLcdData('/');
						PrtLcdBcdNibble(MesMSB,0);
						PrtLcdBcdNibble(MesLSB,0);
						WrLcdData('/');
						PrtLcdBcdNibble(AnoMSB,0);
						PrtLcdBcdNibble(AnoLSB,0);
						WrLcdData(' ');
						WrLcdData(TudoPretoSYMB);//PrtLcdBcdNibble(HoraMSB,0);
						PrtLcdBcdNibble(HoraLSB,0);
						WrLcdData(':');
						PrtLcdBcdNibble(MinMSB,0);
						PrtLcdBcdNibble(MinLSB,0);

						break;
					}
				case 8:
					{
						PosCur(1,0);
						PrtLcdBcdNibble(DiaMSB,0);
						PrtLcdBcdNibble(DiaLSB,0);
						WrLcdData('/');
						PrtLcdBcdNibble(MesMSB,0);
						PrtLcdBcdNibble(MesLSB,0);
						WrLcdData('/');
						PrtLcdBcdNibble(AnoMSB,0);
						PrtLcdBcdNibble(AnoLSB,0);
						WrLcdData(' ');
						PrtLcdBcdNibble(HoraMSB,0);
						WrLcdData(TudoPretoSYMB);//PrtLcdBcdNibble(HoraLSB,0);
						WrLcdData(':');
						PrtLcdBcdNibble(MinMSB,0);
						PrtLcdBcdNibble(MinLSB,0);

						break;
					}
				case 9:
					{
						PosCur(1,0);
						PrtLcdBcdNibble(DiaMSB,0);
						PrtLcdBcdNibble(DiaLSB,0);
						WrLcdData('/');
						PrtLcdBcdNibble(MesMSB,0);
						PrtLcdBcdNibble(MesLSB,0);
						WrLcdData('/');
						PrtLcdBcdNibble(AnoMSB,0);
						PrtLcdBcdNibble(AnoLSB,0);
						WrLcdData(' ');
						PrtLcdBcdNibble(HoraMSB,0);
						PrtLcdBcdNibble(HoraLSB,0);
						WrLcdData(':');
						WrLcdData(TudoPretoSYMB);//PrtLcdBcdNibble(MinMSB,0);
						PrtLcdBcdNibble(MinLSB,0);

						break;
					}
				case 10:
					{
						PosCur(1,0);
						PrtLcdBcdNibble(DiaMSB,0);
						PrtLcdBcdNibble(DiaLSB,0);
						WrLcdData('/');
						PrtLcdBcdNibble(MesMSB,0);
						PrtLcdBcdNibble(MesLSB,0);
						WrLcdData('/');
						PrtLcdBcdNibble(AnoMSB,0);
						PrtLcdBcdNibble(AnoLSB,0);
						WrLcdData(' ');
						PrtLcdBcdNibble(HoraMSB,0);
						PrtLcdBcdNibble(HoraLSB,0);
						WrLcdData(':');
						PrtLcdBcdNibble(MinMSB,0);
						WrLcdData(TudoPretoSYMB);//PrtLcdBcdNibble(MinLSB,0);

						break;
					}



			}
		}
		if (acumulatempo> 120)
		{
			acumulatempo=0;
		}



		leTeclado();

		if (ultimaTeclaExecutada!=teclaAtual)
		{
			ultimaTeclaExecutada=teclaAtual;
			//plotagem na tela;
			if (teclaAtual==TC_DOWN)
			{
				if (CurrentPos==1)
				{
					if (DiaLSB>2) {
						//DiaMSB=DiaMSB-1;} else {DiaMSB=3;}
						If_IncDecAux1(&DiaMSB,2,0,-1);
				}
				else
				{
					If_IncDecAux1(&DiaMSB,3,0,-1);
				}
			}
			if (CurrentPos==2) {

				if (DiaMSB==3) {
					If_IncDecAux1(&DiaLSB,1,0,-1);
				}
				else
				{
					If_IncDecAux1(&DiaLSB,9,0,-1);
				}

			}
			if (CurrentPos==3) {

				if (MesLSB<=2) {
					If_IncDecAux1(&MesMSB,1,0,-1);
				}
				else
				{
					If_IncDecAux1(&MesMSB,0,0,-1);
				}

			}
			if (CurrentPos==4) {
				if (MesMSB==1) {
					If_IncDecAux1(&MesLSB,2,0,-1);
				}
				else
				{
					If_IncDecAux1(&MesLSB,9,0,-1);
				}
			}

			if (CurrentPos==5) { if (AnoMSB!=0) {AnoMSB=AnoMSB-1;} else {AnoMSB=9;}}
			if (CurrentPos==6) { if (AnoLSB!=0) {AnoLSB=AnoLSB-1;} else {AnoLSB=9;}}
			if (CurrentPos==7) {
				if (HoraLSB>3) {
					If_IncDecAux1(&HoraMSB,1,0,-1);
				}
				else
				{
					If_IncDecAux1(&HoraMSB,2,0,-1);
				}
			}
			if (CurrentPos==8) {
				if (HoraMSB==2) {
					If_IncDecAux1(&HoraLSB,3,0,-1);
				}
				else
				{
					If_IncDecAux1(&HoraLSB,9,0,-1);
				}
			}
			if (CurrentPos==9) { if (MinMSB!=0) {MinMSB=MinMSB-1;} else {MinMSB=5;}}
			if (CurrentPos==10){ if (MinLSB!=0) {MinLSB=MinLSB-1;} else {MinLSB=9;}}
			/*
			   if (CurrentPos==2) { if (DiaLSB!=0) {DiaLSB=DiaLSB-1;} else {DiaLSB=9;}}
			   if (CurrentPos==3) { if (MesMSB!=0) {MesMSB=MesMSB-1;} else {MesMSB=9;}}
			   if (CurrentPos==4) { if (MesLSB!=0) {MesLSB=MesLSB-1;} else {MesLSB=9;}}
			   if (CurrentPos==5) { if (AnoMSB!=0) {AnoMSB=AnoMSB-1;} else {AnoMSB=9;}}
			   if (CurrentPos==6) { if (AnoLSB!=0) {AnoLSB=AnoLSB-1;} else {AnoLSB=9;}}
			   if (CurrentPos==7) { if (HoraMSB!=0) {HoraMSB=HoraMSB-1;} else {HoraMSB=9;}}
			   if (CurrentPos==8) { if (HoraLSB!=0) {HoraLSB=HoraLSB-1;} else {HoraLSB=9;}}
			   if (CurrentPos==9) { if (MinMSB!=0) {MinMSB=MinMSB-1;} else {MinMSB=9;}}
			   if (CurrentPos==10){ if (MinLSB!=0) {MinLSB=MinLSB-1;} else {MinLSB=9;}}
			 */
		}
		if (teclaAtual==TC_UP)
		{

			if (CurrentPos==1)
			{
				if (DiaLSB>2) {
					//DiaMSB=DiaMSB-1;} else {DiaMSB=3;}
					If_IncDecAux1(&DiaMSB,2,0,1);
			}
			else
			{
				If_IncDecAux1(&DiaMSB,3,0,1);
			}
		}
		if (CurrentPos==2) {

			if (DiaMSB==3) {
				If_IncDecAux1(&DiaLSB,1,0,1);
			}
			else
			{
				If_IncDecAux1(&DiaLSB,9,0,1);
			}

		}
		if (CurrentPos==3) {

			if (MesLSB<=2) {
				If_IncDecAux1(&MesMSB,1,0,1);
			}
			else
			{
				If_IncDecAux1(&MesMSB,0,0,1);
			}

		}
		if (CurrentPos==4) {
			if (MesMSB==1) {
				If_IncDecAux1(&MesLSB,2,0,1);
			}
			else
			{
				If_IncDecAux1(&MesLSB,9,0,1);
			}
		}

		if (CurrentPos==5) { if (AnoMSB!=9) {AnoMSB=AnoMSB+1;} else {AnoMSB=0;}}
		if (CurrentPos==6) { if (AnoLSB!=9) {AnoLSB=AnoLSB+1;} else {AnoLSB=0;}}
		if (CurrentPos==7) {
			if (HoraLSB>3) {
				If_IncDecAux1(&HoraMSB,1,0,1);
			}
			else
			{
				If_IncDecAux1(&HoraMSB,2,0,1);
			}
		}
		if (CurrentPos==8) {
			if (HoraMSB==2) {
				If_IncDecAux1(&HoraLSB,3,0,1);
			}
			else
			{
				If_IncDecAux1(&HoraLSB,9,0,1);
			}
		}
		if (CurrentPos==9) { if (MinMSB!=5) {MinMSB=MinMSB+1;} else {MinMSB=0;}}
		if (CurrentPos==10){ if (MinLSB!=9) {MinLSB=MinLSB+1;} else {MinLSB=0;}}


		/*
		   if (CurrentPos==1) { if (DiaMSB!=9) {DiaMSB=DiaMSB+1;} else {DiaMSB=0;}}
		   if (CurrentPos==2) { if (DiaLSB!=9) {DiaLSB=DiaLSB+1;} else {DiaLSB=0;}}
		   if (CurrentPos==3) { if (MesMSB!=9) {MesMSB=MesMSB+1;} else {MesMSB=0;}}
		   if (CurrentPos==4) { if (MesLSB!=9) {MesLSB=MesLSB+1;} else {MesLSB=0;}}
		   if (CurrentPos==5) { if (AnoMSB!=9) {AnoMSB=AnoMSB+1;} else {AnoMSB=0;}}
		   if (CurrentPos==6) { if (AnoLSB!=9) {AnoLSB=AnoLSB+1;} else {AnoLSB=0;}}
		   if (CurrentPos==7) { if (HoraMSB!=9){HoraMSB=HoraMSB+1;} else {HoraMSB=0;}}
		   if (CurrentPos==8) { if (HoraLSB!=9){HoraLSB=HoraLSB+1;} else {HoraLSB=0;}}
		   if (CurrentPos==9) { if (MinMSB!=9) {MinMSB=MinMSB+1;} else {MinMSB=0;}}
		   if (CurrentPos==10){ if (MinLSB!=9) {MinLSB=MinLSB+1;} else {MinLSB=0;}}
		 */
	}
	if (teclaAtual==TC_RIGTH)
	{
		if (CurrentPos!=10) {CurrentPos=CurrentPos+1;}
		else {CurrentPos=1;}

	}
	if (teclaAtual==TC_LEFT)
	{
		if (CurrentPos!=1) {CurrentPos=CurrentPos-1;}
		else {CurrentPos=10;}

	}

	if ((DiaMSB==0)&&(DiaLSB==0)){DiaLSB=1;}
	if ((MesMSB==0)&&(MesLSB==0)){MesLSB=1;}

	if (teclaAtual==TC_PRG)
	{
		LocalTime.RTC_Year= 2000+AnoMSB*10+AnoLSB;
		LocalTime.RTC_Mon= MesMSB*10+MesLSB;
		LocalTime.RTC_Mday=DiaMSB*10+DiaLSB;
		if (LocalTime.RTC_Mon==0){LocalTime.RTC_Mon=1;}
		if (LocalTime.RTC_Mday==0){LocalTime.RTC_Mday=1;}
		LocalTime.RTC_Hour=HoraMSB*10+HoraLSB;
		LocalTime.RTC_Min=MinMSB*10+ MinLSB;
		RTCSetTime(LocalTime);
		teclaAtual=TC_ESC;

		//ao alterar o rel�gio, tudo o conte�do da MM e batram � apagado!
					toogleWDI();
					ClearBatteryRam();
					RegistroCabecalho2K.id=REG_BATT_MEM_INIT;
					RegistroCabecalho2K.ProximoEnderecoAserEscritoNaFlash=SETOR_MM_INICIO;
					RegistroCabecalho2K.ProximoEnderecoAserApagadoNaFlash=SETOR_MM_INICIO;
					RegistroCabecalho2K.ProximoEnderecoAserEscritoNaBattRam=RTC_RAM_BASE_ADDR+((DWORD)&RegistroCabecalho2K.NextPos)-((DWORD)&RegistroCabecalho2K.id);
					RegistroCabecalho2K.FlagProximoRegistroSeraComRTC=SIM;
					toogleWDI();

					erase((void*)SETOR_MM_INICIO,(void*)0x080BFFFF);//apaga tudo o setor de "Memoria de Masa"
					 toogleWDI();
					 erase((void*)0x080C0000,(void*)0x080DFFFF);//apaga tudo o setor de "Memoria de Masa"
				 toogleWDI();
				   erase((void*)0x080E0000,(void*)SETOR_MM_FIM);//apaga tudo o setor de "Memoria de Masa"

					toogleWDI();







	}

	PosCur(1,0);
	PrtLcdBcdNibble(DiaMSB,0);
	PrtLcdBcdNibble(DiaLSB,0);
	WrLcdData('/');
	PrtLcdBcdNibble(MesMSB,0);
	PrtLcdBcdNibble(MesLSB,0);
	WrLcdData('/');
	PrtLcdBcdNibble(AnoMSB,0);
	PrtLcdBcdNibble(AnoLSB,0);
	WrLcdData(' ');
	PrtLcdBcdNibble(HoraMSB,0);
	PrtLcdBcdNibble(HoraLSB,0);
	WrLcdData(':');
	PrtLcdBcdNibble(MinMSB,0);
	PrtLcdBcdNibble(MinLSB,0);

}
}
}

void If_GeraFunc18ao19()
{
	char sinal18=0,sinal19=0;
	unsigned char stat18,stat19;
	PosCur(0,0);
	PosCur(0,0);
	PosCur(0,0);
	PosCur(0,0);
	PosCur(1,0);
	stat18=StatusDaFuncaoA;
	stat19=StatusDaFuncaoB;
	if (StatusDaFuncaoA>100) {sinal18=1; stat18=200-StatusDaFuncaoA;}
	if (StatusDaFuncaoB>100) {sinal19=1; stat19=200-StatusDaFuncaoB;}
	if (sinal18) {WrLcdData('-');} else {WrLcdData(' ');}
	Sys_HexBcd(0x00000000|stat18);
	PrtLcdBcdNibble(Zaz[1],0);
	WrLcdData('.');
	PrtLcdBcdNumber(Zaz[0]);
	PrtLcd("     ",2,5);
	if (sinal19) {WrLcdData('-');} else {WrLcdData(' ');}
	Sys_HexBcd(0x00000000|stat19);
	PrtLcdBcdNibble(Zaz[1],0);
	WrLcdData('.');
	PrtLcdBcdNumber(Zaz[0]);
	WrLcdData(' ');
}

void If_GeraFunc18()
{
	StatusDaFuncaoA=StatusFuncao[18];
	StatusDaFuncaoB=StatusFuncao[19];
	PosCur(0,0);
	PosCur(0,0);
	PosCur(0,0);
	PosCur(0,0);
	PrtLcd((unsigned char *)sTela_funcao18,0,0);
	If_GeraFunc18ao19();
}

void If_GeraFunc19()
{
	StatusDaFuncaoA=StatusFuncao[18];
	StatusDaFuncaoB=StatusFuncao[19];
	PosCur(0,0);
	PosCur(0,0);
	PosCur(0,0);
	PosCur(0,0);
	PrtLcd((unsigned char *)sTela_funcao19,0,0);
	If_GeraFunc18ao19();
}

void If_GeraFunc20()
{
	StatusDaFuncaoA=StatusFuncao[20];
	PosCur(0,0);
	PosCur(0,0);
	PosCur(0,0);
	PosCur(0,0);
	If_GeraFunc_Duas_Opcoes((unsigned char *)sTela_funcao20,(unsigned char *)sTela_inativo,(unsigned char *)sTela_ativo,20);
}


void If_GeraFunc21()
{
#if (HABsangrado == 1)
	StatusDaFuncaoA=StatusFuncao[21]&0x80;
#else
	StatusDaFuncaoA=StatusFuncao[21];
#endif
	PosCur(0,0);
	PosCur(0,0);
	PosCur(0,0);
	PosCur(0,0);
	If_GeraFunc_Duas_Opcoes((unsigned char *)sTela_funcao21a,(unsigned char *)sTela_funcao21b,(unsigned char *)sTela_funcao21c,21);
}


void If_GeraFunc22()
{
	StatusDaFuncaoA=StatusFuncao[22];
	//If_GeraFunc_Duas_Opcoes(sTela_funcao22,sTela_inativo,sTela_ativo,22);
	PosCur(0,0);
	PosCur(0,0);
	PosCur(0,0);
	PosCur(0,0);
	If_GeraFunc_Tres_Opcoes((unsigned char *)sTela_funcao22,(unsigned char *)sTela_so_alarme,(unsigned char *)sTela_desl_banco,(unsigned char *)sTela_inativo,22);
}

void If_GeraFunc23()
{
	PosCur(0,0);
	PosCur(0,0);
	PosCur(0,0);
	PosCur(0,0);
	PrtLcd((unsigned char *)sTela_funcao23,0,0);
	switch(StatusFuncao[23])
	{
		case 1:{PrtLcd("5%  ",2,8);break;}
		case 2:{PrtLcd("10% ",2,8);break;}
		case 3:{PrtLcd("15% ",2,8);break;}
	}
}

void If_GeraFunc24()
{
	StatusDaFuncaoA=StatusFuncao[24];
	PosCur(0,0);
	PosCur(0,0);
	PosCur(0,0);
	PosCur(0,0);
	If_GeraFunc_Tres_Opcoes((unsigned char *)sTela_funcao24,(unsigned char *)sTela_so_alarme,(unsigned char *)sTela_desl_banco,(unsigned char *)sTela_inativo,24);
}


void If_GeraFunc25()
{
	PosCur(0,0);
	PosCur(0,0);
	PosCur(0,0);
	PosCur(0,0);
	PrtLcd((unsigned char *)sTela_funcao25,0,0);
	Sys_HexBcd(StatusFuncao[25]);
	PosCur(1,8);
	PrtLcdBcdNumber(Zaz[0]);
	WrLcdData('%');
}

void If_GeraFunc26()
{
	StatusDaFuncaoA=StatusFuncao[26];
	PosCur(0,0);
	PosCur(0,0);
	PosCur(0,0);
	PosCur(0,0);
	If_GeraFunc_Tres_Opcoes((unsigned char *)sTela_funcao26,(unsigned char *)sTela_so_alarme,(unsigned char *)sTela_desl_banco,(unsigned char *)sTela_inativo,26);
}


void If_GeraFunc27()
{
	PosCur(0,0);
	PosCur(0,0);
	PosCur(0,0);
	PosCur(0,0);
	PrtLcd((unsigned char *)sTela_funcao27,0,0);
	Sys_HexBcd(StatusFuncao[27]);
	PosCur(1,11);
	PrtLcdBcdNumber(Zaz[0]);
}



void If_GeraFunc29()
{
	//numero de escravo
	PosCur(0,0);
	PosCur(0,0);
	PosCur(0,0);
	PosCur(0,0);
	PrtLcd((unsigned char *)sTela_funcao29,0,0);
	Sys_HexBcd(StatusFuncao[29]);
	PosCur(1,6);
	PrtLcdBcdNumber(Zaz[1]);
	PrtLcdBcdNumber(Zaz[0]);

}

void If_GeraFunc30()
{
	//velocidade
	PosCur(0,0);
	PosCur(0,0);
	PosCur(0,0);
	PosCur(0,0);
	StatusDaFuncaoA=StatusFuncao[30];
	PrtLcd((unsigned char *)sTela_funcao30,0,0);
	Sys_HexBcd(baudrates[StatusDaFuncaoA]);
	PrtLcd("          ",1,0);
	PosCur(1,1);
	PrtLcdBcdNumber(Zaz[2]);
	PrtLcdBcdNumber(Zaz[1]);
	PrtLcdBcdNumber(Zaz[0]);
}

void If_GeraFunc31()
{
	//paridade.stopbits.
	//If_GeraFunc_Tres_Opcoes(sTela_funcao31a,sTela_funcao31b,sTela_funcao31c,sTela_funcao31d,31);
	StatusDaFuncaoA=StatusFuncao[31];
	//If_GeraFunc_Quatro_Opcoes(sTela_funcao31a,sTela_funcao31b,sTela_funcao31c,sTela_funcao31d,"AUTO",31);
	/*
#define ps8N2	0
#define ps8O1	1
#define ps8E1	2*/
	PosCur(0,0);
	PosCur(0,0);
	PosCur(0,0);
	PosCur(0,0);

	If_GeraFunc_Tres_Opcoes((unsigned char *)sTela_funcao31a,(unsigned char *)sTela_funcao31c,(unsigned char *)sTela_funcao31d,(unsigned char *)sTela_funcao31b,31);
}

void If_GeraFunc32()
{
	unsigned char statfunc;
	int combinacaoescolhida;
	//unsigned int i;
	//Manual
	statfunc=StatusFuncao[32];
	//StatusDaFuncaoA=StatusFuncao[32];
	if (SemCorr==7)
	{ FatPotT=1; }
	PosCur(0,0);
	PosCur(0,0);
	PosCur(0,0);
	PosCur(0,0);
	PrtLcd((unsigned char *)sTela_funcao32,0,0);

	// if (programando==1)
	{
		PosCur(0,10);
		If_PutCosFi(FatPotT);
		if (Comando!=OPERA_MANUAL) {Comando=NAO_ALTERA;}

	}


	if (controleManualHabilitado==SIM)
	{
		//contador2segundos=0;
		if (teclaAtual==TC_UP)  {
			controleManualHabilitado=NAO;
			/*        if (comecouaprogramar==0)
					  {proximoligado=1; proximodesligado=1; comecouaprogramar=1;}
			 */
			FLAG_DESLIGATODOS=0;
			combinacaoescolhida=mask[statfunc-1]|Bancos.StatusAtual;
			Comando=OPERA_MANUAL;
			//       Cal_TestBancosIguais(&combinacaoescolhida);
			Sys_ProgramaAlvo(combinacaoescolhida);
		}
		if (teclaAtual==TC_DOWN)  {
			controleManualHabilitado=NAO;
			if ((Bancos.StatusAtual&mask[statfunc+1])==mask[statfunc+1])
			{
				FLAG_DESLIGATODOS=0;
				Comando=OPERA_MANUAL;
				combinacaoescolhida=Cal_Xor(mask[statfunc+1],Bancos.StatusAtual);
				//       Cal_TestBancosIguais(&combinacaoescolhida);
				Sys_ProgramaAlvo(combinacaoescolhida);
			}
		}

#ifdef DozeEstagios
		if (statfunc>=13) {StatusFuncao[32]=12;}
		if (statfunc<=0) {StatusFuncao[32]=1;}
#endif
#ifdef SeisEstagios
		if (statfunc>=7) {StatusFuncao[32]=6;}
		if (statfunc<=0) {StatusFuncao[32]=1;}
#endif
	}
	if ((statfunc!=0)&&(statfunc!=13))
	{
		Sys_HexBcd(statfunc);
		PosCur(1,1);
		PrtLcdBcdNumber(Zaz[0]);
	}

	PosCur(1,8);
	If_PutQ(Q_controlador);
	//If_PutQ(KVAr_estagio[1]);
}

void If_GeraFunc33()
{
	StatusDaFuncaoA=StatusFuncao[33];
	PosCur(0,0);
	PosCur(0,0);
	PosCur(0,0);
	PosCur(0,0);
	If_GeraFunc_Duas_Opcoes1((unsigned char *)sTela_funcao33a,(unsigned char *)sTela_funcao33b,(unsigned char *)sTela_funcao33c,33);
	FLAG_MUDEI_FUNCAO33=ON;
}


/*
   void If_GeraFunc33()
   {
   StatusDaFuncaoA=StatusFuncao[33];
   If_GeraFunc_Tres_Opcoes(sTela_funcao33a,sTela_funcao33b,sTela_funcao33c,sTela_funcao33d,33);
   FLAG_MUDEI_FUNCAO33=ON;
   } */


void If_GeraFunc34()
{
	PosCur(0,0);
	PosCur(0,0);
	PosCur(0,0);
	PosCur(0,0);
	PrtLcd("34-NOVA SENHA:  ",0,0);
	PrtLcd("0000            ",1,0);
	PrtLcd("0000            ",1,0);
	leTeclado();
	switch (teclaAtual)
	{
		case TC_DOWN:
			{
				If_NovaSenha();
				menu_atual.prog=35;
				If_GeraFunc1ao12(1);
				break;
			}
		case TC_UP:
			{
				If_NovaSenha();
				menu_atual.prog=35;
				If_GeraFunc1ao12(1);
				break;
			}
	}
}


//zerar consumo sim ou n�o
void If_GeraFunc39()
{

	PosCur(0,0);
	PosCur(0,0);

	PrtLcd((unsigned char *)sTela_funcao39a,0,0);




	if(zerar_consumo_cm==0)
	{
		PrtLcd((unsigned char *)sTela_funcao39b,1,0);
	}
	else
	{
		PrtLcd((unsigned char *)sTela_funcao39c,1,0);
	}

}

#if (HABsangrado == 1)
void If_GeraFunc40()
{

	PosCur(0,0);
	PosCur(0,0);

	PrtLcd((unsigned char *)sTela_funcao40a,0,0);


	if((0x80&StatusFuncao[21])==0x80)
	{
		PrtLcd((unsigned char *)sTela_funcao40b,1,0);
	}
	else
	{
		PrtLcd((unsigned char *)sTela_funcao40c,1,0);
	}


	/*
	   leTeclado();
	   switch (teclaAtual)
	   {
	   case TC_DOWN:
	   {
	   PrtLcd((unsigned char *)sTela_funcao39b,1,0);
	   break;
	   }
	   case TC_UP:
	   {
	   PrtLcd((unsigned char *)sTela_funcao39c,1,0);
	   break;
	   }
	   }
	 */
}
#endif



void If_GeraFunc42()
{

	PosCur(0,0);
	PosCur(0,0);

	PrtLcd((unsigned char *)sTela_funcao42a,0,0);


	if(StatusFuncao[1]==0)
	{
		PrtLcd((unsigned char *)sTela_funcao42b,1,0);
	}
	else
	{
		PrtLcd((unsigned char *)sTela_funcao42c,1,0);
	}

}
void If_GeraFunc43()
{

	PosCur(0,0);
	PosCur(0,0);

	PrtLcd((unsigned char *)sTela_funcao43a,0,0);


	if(StatusFuncao[2]==0)
	{
		PrtLcd((unsigned char *)sTela_funcao43b,1,0);
	}
	else
	{
		PrtLcd((unsigned char *)sTela_funcao43c,1,0);
#ifdef LEGADO
		inhibit_ethernet();
#endif

	}

}



void If_GeraFunc41()
{
	PosCur(0,0);
	PosCur(0,0);
	PosCur(0,0);
	PosCur(0,0);
	PrtLcd("41-PORTA:       ",0,0);


    if (NroPorta>10000)
	{
	Sys_HexBcd(NroPorta-10000);
	PosCur(1,0);
	PrtLcdBcdNibble(1,0);
	}
	else
	{
	Sys_HexBcd(NroPorta);
	PosCur(1,0);
	}



	PrtLcdBcdNumber(Zaz[1]);
	PrtLcdBcdNumber(Zaz[0]);
	PrtLcd("            ",1,5);





	leTeclado();
	switch (teclaAtual)
	{
		case TC_DOWN:
			{
				If_NovoNroPorta();
				menu_atual.prog=16;
				break;
			}
		case TC_UP:
			{
				If_NovoNroPorta();
				menu_atual.prog=16;
				break;
			}
	}
}


void If_GeraFunc_Duas_Opcoes(unsigned char Tela[],unsigned char op0[],unsigned char op1[],unsigned char Nfuncao)
{
	PosCur(0,0);
	PosCur(0,0);
	PosCur(0,0);
	PosCur(0,0);
	PrtLcd(Tela,0,0);
	switch (StatusFuncao[Nfuncao])
	{
		case 0:  {PrtLcd(op0,1,0); break;}
		case 1:  {PrtLcd(op1,1,0); break;}
	}
}

void If_GeraFunc_Duas_Opcoes1(unsigned char Tela[],unsigned char op0[],unsigned char op1[],unsigned char Nfuncao)
{
	PosCur(0,0);
	PosCur(0,0);
	PosCur(0,0);
	PosCur(0,0);
	PrtLcd(Tela,0,0);
	switch (StatusFuncao[Nfuncao])
	{
		case 1:  {PrtLcd(op0,1,0); break;}
		case 2:  {PrtLcd(op1,1,0); break;}
	}
}

void If_GeraFunc_Tres_Opcoes(unsigned char Tela[],unsigned char op1[],unsigned char op2[],unsigned char op3[],unsigned char Nfuncao)
{
	PosCur(0,0);
	PosCur(0,0);
	PosCur(0,0);
	PosCur(0,0);
	PrtLcd(Tela,0,0);
	//Nfuncao=1; //temporariamente
	//	switch (StatusFuncao[Nfuncao])
	switch (StatusDaFuncaoA)
	{
		case 1:  {PrtLcd(op1,1,0); break;}
		case 2:  {PrtLcd(op2,1,0); break;}
		case 3:  {PrtLcd(op3,1,0); break;}
	}
}

void If_GeraFunc_Quatro_Opcoes (unsigned char Tela[],unsigned char op1[],unsigned char op2[],unsigned char op3[],unsigned char op4[],unsigned char Nfuncao)
{
	PosCur(0,0);
	PosCur(0,0);
	PosCur(0,0);
	PosCur(0,0);
	PrtLcd(Tela,0,0);
	//Nfuncao=1; //temporariamente
	//	switch (StatusFuncao[Nfuncao])
	switch (StatusDaFuncaoA)
	{
		case 1:  {PrtLcd(op1,1,0); break;}
		case 2:  {PrtLcd(op2,1,0); break;}
		case 3:  {PrtLcd(op3,1,0); break;}
		case 4:  {PrtLcd(op4,1,0); break;}
	}
}



void If_testeAlarme()
{
	short algum_alarme_ligado=NAO;

	if (FLAG_DHT_FORA)
	{
		algum_alarme_ligado=SIM;
	}
	else
	{
		if (FLAG_V_FORA)
		{
			algum_alarme_ligado=SIM;
		}
		else
		{
			if (FLAG_I_FORA)
			{
				algum_alarme_ligado=SIM;
			}
		}
	}

	if (algum_alarme_ligado==NAO)
	{
		if (FLAG_FP_FORA==OFF)
		{
			PiscarSimboloAlarme=NAO;
		}
	}

	if (PiscarSimboloAlarme)
	{
		////EscreveReles(latchatual.i|MascaraAlarme);
		rele_alarme_ativado=0x1000;
	}
	else
	{
		////EscreveReles(latchatual.i&0xFFF);
		rele_alarme_ativado=NAO;
	}

}


void If_SimbolosDoCantoEsquerdo()
{
	short algum_alarme_ligado=NAO;
	PosCur(1,12);
	/*
	   if (naodapracorregir==1)
	   {PrtLcd("IMP",1,10);}
	   else
	   {PrtLcd("   ",1,10);}
	 */
	if (FLAG_DHT_FORA)
	{
		WrLcdData('h');
		algum_alarme_ligado=SIM;
	}
	else
	{
		if (FLAG_V_FORA)
		{
			WrLcdData('v');
			algum_alarme_ligado=SIM;
		}
		else
		{
			if (FLAG_I_FORA)
			{
				WrLcdData('i');
				algum_alarme_ligado=SIM;
			}
			else
			{
				WrLcdData(' ');
			}
		}
	}

	if (algum_alarme_ligado==NAO)
	{
		if (FLAG_FP_FORA==OFF)
		{
			PiscarSimboloAlarme=NAO;
		}
	}

	if (PiscarSimboloAlarme)
	{
		WrLcdData(AlarmeSYMB);
	}
	else
	{
		WrLcdData(' ');
	}


	if (TendCmais)
	{
		WrLcdData(CmaisSYMB);
	}
	else
	{
		if (TendCmenos)
		{
			WrLcdData(CmenosSYMB);
		}
		else
		{
			WrLcdData(' ');
		}
	}
}

#ifndef telafixa

void If_PutCosFi(float cosfi)
{
	//coloca o cosfi formatado onde esta o cursor
	int tempi;
	tempi=(int)((float)cosfi*1000);
	if ((int)tempi<0) {WrLcdData('-'); tempi=-tempi;} else {WrLcdData(' ');}
	Sys_HexBcd(tempi);
	PrtLcdBcdNibble(Zaz[1],1);
	WrLcdData('.');
	PrtLcdBcdNibble(Zaz[1],0);
	PrtLcdBcdNumber(Zaz[0]);
}

void If_PutV(float Vrms)
{
	unsigned long int tempi;
	tempi=(unsigned long int)((float)Vrms*10);
	Sys_HexBcd(tempi);
	//colocar aqui um "      " na tela para apagar anterior....(?)
	If_Escalona(Vrms);
	WrLcdData('V');
	WrLcdData(' ');
}

void If_PutI(float Irms)
{
	unsigned long int tempi;

	if (Irms < 0)
	{
		WrLcdData('-');
		Irms=-Irms;
	}

	tempi=(unsigned long int)((float)Irms*10);
	Sys_HexBcd(tempi);
	If_Escalona(Irms);
	WrLcdData('A');
	WrLcdData(' ');
}

void If_PutP (float P)
{
	unsigned long int tempi;
	if (P<0) {WrLcdData('-'); P=-P;}
	//if (FLAG_GERADOR==0)
	// {
	tempi=(unsigned long int)((float)P*10);
	Sys_HexBcd(tempi);
	If_Escalona(P);
	WrLcdData('W');
	WrLcdData(' ');//para teste
	WrLcdData(' ');//para teste
	// }
	// else
	// {
	// PrtLcd(sTela_msg09,1,0);
	// }
}

void If_PutQ(float Q)
{
	unsigned long int tempi;
	if (Q<0) {WrLcdData('-'); Q=-Q;}
	tempi=(unsigned long int)((float)Q*10);
	Sys_HexBcd(tempi);
	If_Escalona(Q);
	WrLcdData('V');
	WrLcdData('A');
	WrLcdData('r');
	WrLcdData(' ');
}

void If_PutDht(float Dht)
{
	unsigned int tempi;
	tempi=(unsigned int)((float)Dht*100);
	Sys_HexBcd(tempi);
	if ((Zaz[1]&0xF0)!=0)
	{
		PrtLcdBcdNumber(Zaz[1]);
	}
	else
	{
		PrtLcdBcdNibble(Zaz[1],0);
	}
	WrLcdData('.');
	PrtLcdBcdNibble(Zaz[0],1);
}

#endif

void If_Escalona(float tfloat)
{
	float tfloat1;
	if (tfloat>=1000) //antes -> if (tfloat>1000)
	{
		if (tfloat<10000) //Vrms entre 1k e 10k
		{
			PrtLcdBcdNibble(Zaz[2],0);
			WrLcdData('.');
			PrtLcdBcdNumber(Zaz[1]);
			WrLcdData('K');
		}
		else            //Vrms maior que 10k
		{
			if (tfloat<100000)   //Vrms entre 10k e 100k
			{
				PrtLcdBcdNumber(Zaz[2]);
				WrLcdData('.');
				PrtLcdBcdNumber(Zaz[1]);
				WrLcdData('K');
			}
			else	          //Vrms maior que 100k
			{
				/* if (tfloat>=100000)
				   {
				   PrtLcdBcdNumber(Z[3]);
				   PrtLcdBcdNumber(Z[2]);
				   WrLcdData('K');
				   }
				   else
				   {*/
				PrtLcdBcdNibble(Zaz[3],0);
				PrtLcdBcdNumber(Zaz[2]);
				WrLcdData('.');
				PrtLcdBcdNibble(Zaz[1],1);
				WrLcdData('K');
				//}
			}
		}
	}
	else             //Vrms menor que 1k
	{
		if (tfloat<100)   //Vrms menor que 100
		{
			if (tfloat<10)//menor que 10//
			{
				if (tfloat==0)
				{
					WrLcdData(' ');
					PrtLcdBcdNibble(Zaz[0],1);
					WrLcdData('.');
					PrtLcdBcdNibble(Zaz[0],0);
					PrtLcdBcdNibble(Zaz[0],0);
				}
				else
				{
					tfloat1=tfloat*100; //testezinho...
					Sys_HexBcd((unsigned long int)tfloat1);
					WrLcdData(' ');
					PrtLcdBcdNibble(Zaz[1],0);
					WrLcdData('.');
					PrtLcdBcdNumber(Zaz[0]);
					/* WrLcdData(' ');
					   WrLcdData(' ');
					   PrtLcdBcdNibble(Z[0],1);
					   WrLcdData('.');
					   PrtLcdBcdNibble(Z[0],0);   */
				}
			}
			else          //Vrms menor que 100 e maior que 10
			{
				PrtLcdBcdNibble(Zaz[1],0);
				PrtLcdBcdNibble(Zaz[0],1);
				WrLcdData('.');
				PrtLcdBcdNibble(Zaz[0],0);
			}
		}
		else            //Vrms entre 100 e 1k
		{
			PrtLcdBcdNumber(Zaz[1]);
			PrtLcdBcdNibble(Zaz[0],1);
			WrLcdData('.');
			PrtLcdBcdNibble(Zaz[0],0);
		}
	}
}

void If_PutIP(float tfloat)
{
	float tfloat1;
	//Vrms menor que 1k
	if (tfloat<100)   //Vrms menor que 100
	{
		if (tfloat<10)//menor que 10//
		{
			if (tfloat==0)
			{
				WrLcdData(' ');
				PrtLcdBcdNibble(Zaz[0],1);
				WrLcdData('.');
				PrtLcdBcdNibble(Zaz[0],0);
				PrtLcdBcdNibble(Zaz[0],0);
			}
			else
			{
				tfloat1=tfloat*100; //testezinho...
				Sys_HexBcd((unsigned long int)tfloat1);
				WrLcdData(' ');
				PrtLcdBcdNibble(Zaz[1],0);
				WrLcdData('.');
				PrtLcdBcdNumber(Zaz[0]);
				/* WrLcdData(' ');
				   WrLcdData(' ');
				   PrtLcdBcdNibble(Z[0],1);
				   WrLcdData('.');
				   PrtLcdBcdNibble(Z[0],0);   */
			}
		}
		else          //Vrms menor que 100 e maior que 10
		{
			PrtLcdBcdNibble(Zaz[1],0);
			PrtLcdBcdNibble(Zaz[0],1);
			WrLcdData('.');
			PrtLcdBcdNibble(Zaz[0],0);
		}
	}
	else            //Vrms entre 100 e 1k
	{
		PrtLcdBcdNumber(Zaz[1]);
		PrtLcdBcdNibble(Zaz[0],1);
		WrLcdData('.');
		PrtLcdBcdNibble(Zaz[0],0);
	}
}




char If_VerificaErros()
{
	//unsigned char n;
	char tempbit=0;

#if MD4040TI == 1
	return 0;
#endif

	for (;;)
	{
		//1o Testo os coerencia nos limites da faixa...
		if (StatusFuncao[13]>StatusFuncao[14]) {If_TelaMensagens(Tela_msg02); tempbit=1; break;}
		//2o Testo os coerencia nos limites da faixa de alarme...
		if (StatusFuncao[18]>StatusFuncao[19]) {If_TelaMensagens(Tela_msg02); tempbit=1; break;}
		//3o Testo se a faixa de alarme engloba a faixa de cosfi
		if ((StatusFuncao[18]>StatusFuncao[13])||(StatusFuncao[19]<StatusFuncao[14])) {If_TelaMensagens(Tela_msg02); tempbit=1; break;}
		//4o Testo se o bloqueio capacitivo esta ativado e se a faixa de cosfi e tb capacitiva
		//  if (StatusFuncao[20]==1) { if ((StatusFuncao[14]>100)||(StatusFuncao[19]>100)) {If_TelaMensagens(Tela_msg03); tempbit=1; break;} }
		if (StatusFuncao[20]==1) { if (StatusFuncao[14]>100) {If_TelaMensagens(Tela_msg03); tempbit=1; break;} }
		break ;
	}
	return(tempbit);
}

/*----------------------------------------------------------------------------------------*/
void If_AtualizaParametros()
{
	short tParametrizacaoCM;

#define BLOQCAP	     	0x0001
#define ACIONATODOS	 	0x0002
#define ALARME_I_ON	 	0x0004
#define DESLIG_AL_I_ON	0x0008
#define ALARME_V_ON	 	0x0010
#define DESLIG_AL_V_ON	0x0020
#define ALARME_D_ON	 	0x0040
#define DESLIG_AL_D_ON  0x0080
#define LIG_TRIF_ESTR	0x0100
	tParametrizacaoCM=0;

	KVAr_estagio[1]=tab_valorKVAr[StatusFuncaoFinal[1]];
	KVAr_estagio[2]=tab_valorKVAr[StatusFuncaoFinal[2]];
	KVAr_estagio[3]=tab_valorKVAr[StatusFuncaoFinal[3]];
	KVAr_estagio[4]=tab_valorKVAr[StatusFuncaoFinal[4]];
	KVAr_estagio[5]=tab_valorKVAr[StatusFuncaoFinal[5]];
	KVAr_estagio[6]=tab_valorKVAr[StatusFuncaoFinal[6]];
	KVAr_estagio[7]=tab_valorKVAr[StatusFuncaoFinal[7]];
	KVAr_estagio[8]=tab_valorKVAr[StatusFuncaoFinal[8]];
	KVAr_estagio[9]=tab_valorKVAr[StatusFuncaoFinal[9]];
	KVAr_estagio[10]=tab_valorKVAr[StatusFuncaoFinal[10]];
	KVAr_estagio[11]=tab_valorKVAr[StatusFuncaoFinal[11]];
	KVAr_estagio[12]=tab_valorKVAr[StatusFuncaoFinal[12]];


	Sys_AtualizaValorDosBancos();
	FLAG_CF_supCAPACITIVO=0;
	FLAG_CF_infCAPACITIVO=0;
	if (StatusFuncaoFinal[13]>100) {CF_inf=-((float)(200-StatusFuncaoFinal[13]))/100;  FLAG_CF_infCAPACITIVO=1; } else {CF_inf=((float)(StatusFuncaoFinal[13]))/100;}
	if (StatusFuncaoFinal[14]>100) {CF_sup=-((float)(200-StatusFuncaoFinal[14]))/100;  FLAG_CF_supCAPACITIVO=1;} else {CF_sup=((float)(StatusFuncaoFinal[14]))/100;}


	//comentado por cesar TipoDeLigacao=StatusFuncaoFinal[33]; //1:FNestrela 2:FFestrela 3:FFdelta
	tParametrizacaoCM=LIG_TRIF_ESTR|tParametrizacaoCM; //comentado por cesar

	Tdisparo=tab_valorTD[StatusFuncaoFinal[15]];
	Td=(float)Tdisparo;
	FLAG_CF_al_supCAPACITIVO=0;
	FLAG_CF_al_infCAPACITIVO=0;
	if (StatusFuncaoFinal[18]>100) {CF_al_inf=-((float)(200-StatusFuncaoFinal[18]))/100; FLAG_CF_al_infCAPACITIVO=1;} else {CF_al_inf=((float)(StatusFuncaoFinal[18]))/100;}
	if (StatusFuncaoFinal[19]>100) {CF_al_sup=-((float)(200-StatusFuncaoFinal[19]))/100; FLAG_CF_al_supCAPACITIVO=1;} else {CF_al_sup=((float)(StatusFuncaoFinal[19]))/100;}

	FLAG_BLOQUEIOCAPACITIVO=StatusFuncaoFinal[20]&0x01;
	if (FLAG_BLOQUEIOCAPACITIVO==ON) {tParametrizacaoCM= BLOQCAP|tParametrizacaoCM;}
	FLAG_MODO_ACCIONA_TODOS=StatusFuncaoFinal[21]&0x01;

#if (HABsangrado == 1)
	if((0x80&StatusFuncaoFinal[21])==0x80) {FLAG_MODO_DELTA_SANGRADO=SIM;} else
	{FLAG_MODO_DELTA_SANGRADO=NAO;};
#endif

	if (FLAG_MODO_ACCIONA_TODOS==ON) {tParametrizacaoCM= ACIONATODOS|tParametrizacaoCM;}
	modo_de_operacao_AL_CORR=StatusFuncaoFinal[22];
	if (modo_de_operacao_AL_CORR==1) {tParametrizacaoCM= ALARME_I_ON|tParametrizacaoCM;}
	if (modo_de_operacao_AL_CORR==2) {tParametrizacaoCM= ALARME_I_ON|DESLIG_AL_I_ON|tParametrizacaoCM;}
	modo_de_operacao_AL_TENS=StatusFuncaoFinal[24];
	if (modo_de_operacao_AL_TENS==1) {tParametrizacaoCM= ALARME_V_ON|tParametrizacaoCM;}
	if (modo_de_operacao_AL_TENS==2) {tParametrizacaoCM= ALARME_V_ON|DESLIG_AL_V_ON|tParametrizacaoCM;}
	DHTVlim=StatusFuncaoFinal[25];
	modo_de_operacao_AL_DHT=StatusFuncaoFinal[26];
	if (modo_de_operacao_AL_DHT==1) {tParametrizacaoCM= ALARME_D_ON|tParametrizacaoCM;}
	if (modo_de_operacao_AL_DHT==2) {tParametrizacaoCM= ALARME_D_ON|DESLIG_AL_D_ON|tParametrizacaoCM;}

	Talarme=(float)Td*(float)StatusFuncaoFinal[27];
	FLAG_MODO_DE_FUNCIONAMENTO=StatusFuncaoFinal[28]&0x01; //se 0==> inst corr.

	tptc.tptc_c[1]=StatusFuncaoFinal[38];
	tptc.tptc_c[0]=StatusFuncaoFinal[37];
	//PrimarioTP=tptc.tptc_i;
	relacaoTPpri=tptc.tptc_i;
	tptc.tptc_c[1]=StatusFuncaoFinal[40];
	tptc.tptc_c[0]=StatusFuncaoFinal[39];
	//SecundarioTP=tptc.tptc_i;
	relacaoTPsec=tptc.tptc_i;
	tptc.tptc_c[1]=StatusFuncaoFinal[42];
	tptc.tptc_c[0]=StatusFuncaoFinal[41];
	//PrimarioTC=tptc.tptc_i;
	relacaoTCpri=tptc.tptc_i;
	tptc.tptc_c[1]=StatusFuncaoFinal[44];
	tptc.tptc_c[0]=StatusFuncaoFinal[43];
	//SecundarioTC=tptc.tptc_i;
	relacaoTCsec=tptc.tptc_i;
	/*
	   relacaoTP=(float)PrimarioTP/(float)SecundarioTP;  //(float)tab_rel_TP[StatusFuncaoFinal[16]];
	   relacaoTC=(float)PrimarioTC/(float)SecundarioTC; //(float)tab_rel_TC[StatusFuncaoFinal[17]];
	   relacaoTPpri=PrimarioTP;
	   relacaoTPsec=SecundarioTP;
	   relacaoTPfat=1;
	   relacaoTCpri=PrimarioTC;
	   relacaoTCsec=SecundarioTC;
	   relacaoTCfat=1;  */

	relacaoTPfat=1;
	relacaoTCfat=1;
	relacaoTP=(float)relacaoTPpri/(float)relacaoTPsec;  //(float)tab_rel_TP[StatusFuncaoFinal[16]];
	relacaoTC=(float)relacaoTCpri/(float)relacaoTCsec; //(float)tab_rel_TC[StatusFuncaoFinal[17]];

	Vlim_sup=(float)(relacaoTPpri*((float)StatusFuncaoFinal[23]*0.05+1));     //Vlim_sup=(float)(tab_primario_TP[StatusFuncaoFinal[16]]*((float)StatusFuncaoFinal[23]*0.05+1)); // bug corregido , antes multiplicava por 0.01!!
	Vlim_inf=(float)(relacaoTPpri*(float)(1-(float)StatusFuncaoFinal[23]*0.05)); //Vlim_inf=(float)(tab_primario_TP[StatusFuncaoFinal[16]]*(float)(1-(float)StatusFuncaoFinal[23]*0.05)); // bug corregido , antes multiplicava por 0.01!!



	if (FLAG_LIGOU_RECENTEMENTE==0)
	{
		if (FLAG_ALTEREI_KVAR==1)
		{

			FLAG_ALTEREI_KVAR=0;
			PrtLcd((unsigned char *)sTela_CriandoCombinacoes,0,0);
			AtualizaDisplay=OFF;
			Cal_Geratabela();	//gera as posiveis combina��es de bancos
			PowerDown();
		}
	}

	/*
#define BR4800   0
#define BR9600   1
#define BR14400  2
#define BR19200  3
#define BR38400  4
#define BR56000  5
#define BR57600  6
#define BR115200 7

#define ps8N2	0
#define ps8O1	1
#define ps8E1	2
	 */

#if MD4040TI==1
	BaudRate=BR19200;
	ParidadeStops=ps8O1;
	StatusFuncaoFinal[29]=1;
	StatusFuncaoFinal[30]=BaudRate;
    StatusFuncaoFinal[31]=ParidadeStops;
#endif;



	MeuEnderecoMODBUS=StatusFuncaoFinal[29];
	BaudRatex =StatusFuncaoFinal[30];
    ParidadeStops=StatusFuncaoFinal[31];
	UARTInit(StatusFuncaoFinal[30],StatusFuncaoFinal[31]);

	/*
										short ParametrizacaoCM;

										11	11 10  9 8	7  6  5  4	3  2  1	 0
										x   x  x  x	 x  x  x  x  x  x  x  x  x
										| 	|  |  |	 |  |  |  |  |  |  |  |  |
										| 	|  |  |	 |  |  |  |  |  |  |  |  |_BloQCapativo    			 (ON,OFF)
										| 	|  |  |	 |  |  |  |  | 	|  |  |____ModoAcionaTodos 			 (ON,OFF)
										| 	|  |  |	 |  |  |  |  | 	|  |_______Alarme Falta Corrente 	 (ON,OFF)
										| 	|  |  |	 |  |  |  |  | 	|__________Modo Al. Corrente, Desliga(ON,OFF)
										| 	|  |  |	 |  |  |  |  |_____________Alarme SUB-SOBRE Tens�o 	 (ON,OFF)
										| 	|  |  |	 |  |  |  |________________Modo Al. Tens�o, Desliga  (ON,OFF)
										| 	|  |  |	 |  |  |___________________Alarme DHTv  	 		 (ON,OFF)
										| 	|  |  |	 |  |______________________Modo Al. DHTv,Desliga     (ON,OFF)
										| 	|  |  |	 |_________________________Ligacao trif�sica Estrela
										| 	|  |  |____________________________Ligacao trif�sica Delta (?)
										| 	|  |_______________________________Ligacao mono F-N	estrela
										|	|__________________________________Ligacao mono F-F estrela
										|______________________________________Ligacao mono F-F delta
	 */
	ParametrizacaoCM=tParametrizacaoCM;
	Cal_BuscaDeBancosIguais();
	FLAG_LIGOU_RECENTEMENTE=0;
}


void If_IncDecAux1(unsigned char* var,unsigned char limitesup,unsigned char limiteinf,unsigned char incremento)
{
	if (incremento>0)
	{
		*var=*var+incremento;
		if(*var>=limitesup)
		{
			*var=limitesup;
		}
	}
	else
	{			//note que incremento � negativo.
		*var=*var+incremento;
		if(*var<=limiteinf)
		{
			*var=limiteinf;
		}
	}

}

void atualizaDevName(void)
{
	//lhost_name[1]=dev_name[0];
	//lhost_name[0]=dev_name[1];
	//lhost_name[3]=dev_name[2];
	//lhost_name[2]=dev_name[3];
	//lhost_name[5]=dev_name[4];
	//lhost_name[4]=dev_name[5];
	//lhost_name[7]=dev_name[6];
	//lhost_name[6]=dev_name[7];
	//lhost_name[9]=dev_name[8];
	//lhost_name[8]=dev_name[9];
	//lhost_name[11]=dev_name[10];
	//lhost_name[10]=dev_name[11];
	//lhost_name[13]=dev_name[12];
	//lhost_name[12]=dev_name[13];
	//lhost_name[15]=dev_name[14];
	//lhost_name[14]=dev_name[15];
}
void FloatToStrForEnergy1(float numero, char *str )
{
	//a ideia � converter para BCD, e depois para string
	unsigned long int numero_int;
	short milhar=0,centena=0,dezena=0,unidade=0,decimo=0,centesimo=0,milesimo=0,desmilesimo=0;
	short PosVirgula=0;
	float mul;


	//determina��o do sinal do n�mero.
	if (numero<0)
	{
		numero=-numero;
	}

	//determina��o da posicao da v�rgula e do fator de multiplicacao
	/////////////
	if ((numero>0.0000001)&&((numero<=9.9999999)))
	{
		mul=1000.0;
		PosVirgula=1;
	}
	/////////////
	if ((numero>1.0000000)&&((numero<=9.9999999)))
	{
		mul=1000.0;
		PosVirgula=1;
	}
	/////////////
	if ((numero>10.000000)&&((numero<=99.999999)))
	{
		mul=100.0;
		PosVirgula=2;
	}
	/////////////
	if ((numero>100.00000)&&((numero<=999.99999)))
	{
		mul=10.0;
		PosVirgula=3;
	}
	/////////////
	if ((numero>1000.0000)&&((numero<=9999.9999)))
	{
		mul=1.0;
		PosVirgula=4;
	}
	/////////////
	if ((numero>10000.000)&&((numero<=99999.999)))
	{
		mul=0.1;
		PosVirgula=5;
	}
	/////////////
	if ((numero>100000.00)&&((numero<=999999.99)))
	{
		mul=0.01;
		PosVirgula=6;
	}
	/////////////
	if ((numero>1000000.0)&&((numero<=9999999.9)))
	{
		mul=0.001;
		PosVirgula=7;
	}
	/////////////

	if (numero>10000000.0)
	{
		mul=0.0001;
		PosVirgula=0;
		/**str='-'; str++;
		 *str='-'; str++;
		 *str='-'; str++;
		 *str='-'; str++;
		 *str='-'; str++;
		 *str='-'; str++;
		 *str='-'; str++;
		 *str='-';
		 return;	 */
	}

	numero_int=(unsigned long int)(mul*numero);
	milhar=  numero_int/1000;
	centena=(numero_int-milhar*1000)/100;
	dezena= (numero_int-milhar*1000-centena*100)/10;
	unidade=(numero_int-milhar*1000-centena*100-dezena*10);

	numero_int=(unsigned long int)(10000*(mul*numero-(float)numero_int));
	decimo=	  numero_int/1000;
	centesimo=(numero_int-decimo*1000)/100;
	milesimo= (numero_int-decimo*1000-centesimo*100)/10;
	desmilesimo= (numero_int-decimo*1000-centesimo*100-milesimo*10);

	//converte em 'char'

	if (PosVirgula==0) //NADA DE PONTO
	{
		*str=milhar+0x30; str++;
		*str=centena+0x30; str++;
		*str=dezena+0x30; str++;
		*str=unidade+0x30; str++;
		*str=decimo+0x30; str++;
		*str=milesimo+0x30;	str++;
		*str=desmilesimo+0x30; str++;
		*str=0x30;


	}
	if (PosVirgula==1)
	{
		*str=milhar+0x30; str++;
		*str='.'; str++;
		*str=centena+0x30; str++;
		*str=dezena+0x30;  str++;
		*str=unidade+0x30;str++;
		*str=decimo+0x30;str++;
		*str=milesimo+0x30;	str++;
		*str=desmilesimo+0x30; str++;
		*str=0x30;
	}
	if (PosVirgula==2)
	{
		*str=milhar+0x30; str++;
		*str=centena+0x30; str++;
		*str='.'; str++;
		*str=dezena+0x30;  str++;
		*str=unidade+0x30;	str++;
		*str=decimo+0x30;	str++;
		*str=milesimo+0x30;	str++;
		*str=desmilesimo+0x30; str++;
		*str=0x30;
	}
	if (PosVirgula==3)
	{
		*str=milhar+0x30; str++;
		*str=centena+0x30; str++;
		*str=dezena+0x30; str++;
		*str='.'; str++;
		*str=unidade+0x30;str++;
		*str=decimo+0x30;str++;
		*str=milesimo+0x30;	str++;
		*str=desmilesimo+0x30; str++;
		*str=0x30;
	}

	if (PosVirgula==4)
	{
		*str=milhar+0x30; str++;
		*str=centena+0x30; str++;
		*str=dezena+0x30; str++;
		*str=unidade+0x30;str++;
		*str='.'; str++;
		*str=decimo+0x30;str++;
		*str=milesimo+0x30;	str++;
		*str=desmilesimo+0x30; str++;
		*str=0x30;
	}

	if (PosVirgula==5)
	{
		*str=milhar+0x30; str++;
		*str=centena+0x30; str++;
		*str=dezena+0x30; str++;
		*str=unidade+0x30;str++;
		*str=decimo+0x30;str++;
		*str='.'; str++;
		*str=milesimo+0x30;	str++;
		*str=desmilesimo+0x30; str++;
		*str=0x30;
	}

	if (PosVirgula==6)
	{
		*str=milhar+0x30; str++;
		*str=centena+0x30; str++;
		*str=dezena+0x30; str++;
		*str=unidade+0x30;str++;
		*str=decimo+0x30;str++;
		*str=milesimo+0x30;	str++;
		*str='.'; str++;
		*str=desmilesimo+0x30; str++;
		*str=0x30;
	}

	if (PosVirgula==7)
	{
		*str=milhar+0x30; str++;
		*str=centena+0x30; str++;
		*str=dezena+0x30; str++;
		*str=unidade+0x30;str++;
		*str=decimo+0x30;str++;
		*str=milesimo+0x30;	str++;
		*str=desmilesimo+0x30; str++;
		*str='.'; str++;
		*str=0x30;
	}
}

#endif
