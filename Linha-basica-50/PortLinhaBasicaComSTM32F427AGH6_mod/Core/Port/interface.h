/*****************************************************************************
 *   e2prom.c:  Aqui se encontram as rotinas de interface com o usuário
 *
 *   Projeto MD2010-ARM
 *
 *   History
 *   2006.30.05  ver. codigo 1.00  Versão Preliminar. 
 *
 *
 ******************************************************************************/
#ifndef __INTERFACE_H 
#define __INTERFACE_H

 
#define TC_NULL	   0
#define TC_UP 	   1
#define TC_DOWN	   2
#define TC_LEFT	   3
#define TC_RIGTH   4
#define TC_ESC	   5
#define TC_PRG	   6


#define NENHUM_PISCANDO 0xFF

/*
   Funcoes executadas pelo teclado
 */
#define NONE                        0
#define GOTO_TELA1                  1
#define GOTO_TELA2                  2
#define ENTRA_MODO_PRG              3
#define SAIR_MODO_PRG_SEM_GRAVAR    4
#define SAIR_MODO_PRG_POSSIVELMENTE_GRAVANDO		5       
#define ALTERA_SIM_NAO_G		6       
#define INCREMENTA_ALGARISMO_INT	7
#define DECREMENTA_ALGARISMO_INT	8
#define GOTO_ALG_ANTERIOR_INT		9
#define GOTO_ALG_PROXIMO_INT		10
#define INCREMENTA_ALGARISMO_BYTE	11
#define DECREMENTA_ALGARISMO_BYTE	12
#define GOTO_ALG_ANTERIOR_BYTE		13
#define GOTO_ALG_PROXIMO_BYTE		14
#define INCREMENTA_PARIDADE_STOPS	15
#define DECREMENTA_PARIDADE_STOPS	16
#define INCREMENTA_BAUD_RATE		17				  
#define DECREMENTA_BAUD_RATE		18																												
#define ALTERA_SIM_NAO				19 				 
#define GOTO_TELA_APRESENTACAO      20	 			
#define GOTO_TELA_PROXIMA   		21			
#define GOTO_TELA_ANTERIOR  		22				   
#define GOTO_REL_TP_PRI_MOD   		23				   
#define GOTO_REL_TP_SEC_MOD 		24				   
#define GOTO_REL_TP_FAT_MOD  		25					   
#define GOTO_REL_TC_PRI_MOD 		26				   
#define GOTO_REL_TC_SEC_MOD 		27				   
#define GOTO_REL_TC_FAT_MOD 		28		   
#define GOTO_RESET_CONSUMO_MOD      29				   
#define GOTO_ESCRAVO_MODBUS_MOD     30				   
#define GOTO_BAUD_RATE_MOD		 	31	   
#define GOTO_PARIDADE_STOPS_MOD	32
#define GOTO_IP_OCTETO1_MOD		33
#define GOTO_IP_OCTETO2_MOD		34
#define GOTO_IP_OCTETO3_MOD		35
#define GOTO_IP_OCTETO4_MOD		36
#define GOTO_MK_OCTETO1_MOD		37
#define GOTO_MK_OCTETO2_MOD		38
#define GOTO_MK_OCTETO3_MOD		39
#define GOTO_MK_OCTETO4_MOD		40
#define GOTO_GW_OCTETO1_MOD		41
#define GOTO_GW_OCTETO2_MOD		42
#define GOTO_GW_OCTETO3_MOD		43
#define GOTO_GW_OCTETO4_MOD		44
#define GOTO_NRO_PORTA_MOD			45 
#define ABANDONA_PROG_REL_TP_PRI	46
#define ABANDONA_PROG_REL_TP_SEC	47
#define ABANDONA_PROG_REL_TP_FAT	48
#define ABANDONA_PROG_REL_TC_PRI	49	 
#define ABANDONA_PROG_REL_TC_SEC	50	 
#define ABANDONA_PROG_REL_TC_FAT		51
#define ABANDONA_PROG_RESET_CONSUMO		52 
#define ABANDONA_PROG_ESCRAVO_MODBUS	53 
#define ABANDONA_PROG_BAUD_RATE			54 
#define ABANDONA_PROG_PARIDADE_STOPS	55 
#define ABANDONA_PROG_IP_OCTETO1		56 
#define ABANDONA_PROG_IP_OCTETO2		57 
#define ABANDONA_PROG_IP_OCTETO3		58 
#define ABANDONA_PROG_IP_OCTETO4		59 
#define ABANDONA_PROG_MK_OCTETO1		60 
#define ABANDONA_PROG_MK_OCTETO2		61 
#define ABANDONA_PROG_MK_OCTETO3		62 
#define ABANDONA_PROG_MK_OCTETO4		63 
#define ABANDONA_PROG_GW_OCTETO1		64 
#define ABANDONA_PROG_GW_OCTETO2		65 
#define ABANDONA_PROG_GW_OCTETO3		66 
#define ABANDONA_PROG_GW_OCTETO4		67 
#define ABANDONA_PROG_NRO_PORTA			68 
#define GRAVA_PROG_REL_TP_PRI			69 
#define GRAVA_PROG_REL_TP_SEC			70 
#define GRAVA_PROG_REL_TP_FAT			71 
#define GRAVA_PROG_REL_TC_PRI			72 
#define GRAVA_PROG_REL_TC_SEC			73 
#define GRAVA_PROG_REL_TC_FAT			74 
#define GRAVA_PROG_RESET_CONSUMO		75 
#define GRAVA_PROG_ESCRAVO_MODBUS		76 
#define GRAVA_PROG_BAUD_RATE			77 
#define GRAVA_PROG_PARIDADE_STOPS		78 
#define GRAVA_PROG_IP_OCTETO1			79 
#define GRAVA_PROG_IP_OCTETO2			80 
#define GRAVA_PROG_IP_OCTETO3			81 
#define GRAVA_PROG_IP_OCTETO4			82 
#define GRAVA_PROG_MK_OCTETO1			83 
#define GRAVA_PROG_MK_OCTETO2			84 
#define GRAVA_PROG_MK_OCTETO3			85 
#define GRAVA_PROG_MK_OCTETO4			86 
#define GRAVA_PROG_GW_OCTETO1			87 
#define GRAVA_PROG_GW_OCTETO2			88 
#define GRAVA_PROG_GW_OCTETO3			89 
#define GRAVA_PROG_GW_OCTETO4			90 
#define GRAVA_PROG_NRO_PORTA			91  
#define GOTO_TELA_GRAVAR_SIM_NAO		92
#define VOLTA_AO_MODO_PROGRAMACAO		93


#define INICIO_TELAS_DE_EXIBICAO    0
#define TELAS_DE_EXIBICAO	  	    INICIO_TELAS_DE_EXIBICAO
#define TELA_APRESENTACAO			TELAS_DE_EXIBICAO+0 
#define TELA_TENSOES_ABC			TELAS_DE_EXIBICAO+1
#define TELA_CORRENTES_ABC			TELAS_DE_EXIBICAO+2
#define TELA_FATORES_DE_POT_ABC 	TELAS_DE_EXIBICAO+3
#define TELA_POT_ATIVA_ABC			TELAS_DE_EXIBICAO+4
#define TELA_POT_REATIVA_ABC		TELAS_DE_EXIBICAO+5	
#define TELA_POT_APARENTE_ABC		TELAS_DE_EXIBICAO+6	
#define TELA_DHTU_ABC	 			TELAS_DE_EXIBICAO+7
#define TELA_DHTI_ABC				TELAS_DE_EXIBICAO+8
#define TELA_FREQ					TELAS_DE_EXIBICAO+9
#define TELA_FP_KW_KVAR				TELAS_DE_EXIBICAO+10
#define TELA_CONSUMO_TOTAL			TELAS_DE_EXIBICAO+11
#define TELA_GERADA_TOTAL			TELAS_DE_EXIBICAO+12
#define TELA_ENERGIA_IND_TOTAL		TELAS_DE_EXIBICAO+13
#define TELA_ENERGIA_CAP_TOTAL		TELAS_DE_EXIBICAO+14
#define TELA_U_I_FP_A				TELAS_DE_EXIBICAO+15
#define TELA_U_I_FP_B				TELAS_DE_EXIBICAO+16
#define TELA_U_I_FP_C				TELAS_DE_EXIBICAO+17
#define TELA_W_VAR_VA_A 			TELAS_DE_EXIBICAO+18
#define TELA_W_VAR_VA_B				TELAS_DE_EXIBICAO+19
#define TELA_W_VAR_VA_C				TELAS_DE_EXIBICAO+20
#define TELA_NSERIE					TELAS_DE_EXIBICAO+21

#if EQUIP==CM_EQUIP 
#define TELA_TESTE					TELAS_DE_EXIBICAO+22   //última tela de exibição
#else

#define TELA_U_AB					TELAS_DE_EXIBICAO+22   
#define TELA_U_BC					TELAS_DE_EXIBICAO+23   
#define TELA_U_CA					TELAS_DE_EXIBICAO+24   
#define TELA_CONSUMO_PONTA			TELAS_DE_EXIBICAO+25
#define TELA_CONSUMO_FORAPONTA		TELAS_DE_EXIBICAO+26
#define TELA_CONSUMO_RESERVADO		TELAS_DE_EXIBICAO+27
#define TELA_DEMANDA_PONTA			TELAS_DE_EXIBICAO+28
#define TELA_DEMANDA_FORAPONTA		TELAS_DE_EXIBICAO+29
#define TELA_DEMANDA_RESERVADO		TELAS_DE_EXIBICAO+30
#define TELA_TESTE					TELAS_DE_EXIBICAO+31   //última tela de exibição

	#ifdef MODELO_D
		#define TELA_TESTE1					TELAS_DE_EXIBICAO+32   //última tela de exibição
		#define TELA_TESTE2					TELAS_DE_EXIBICAO+33   //última tela de exibição
		#define FIM_TELAS_DE_EXIBICAO    	TELA_TESTE2
	#else
		#define FIM_TELAS_DE_EXIBICAO    	TELA_TESTE
	#endif


/*	#ifdef MODELO_DURACAO_PULSO

			#undef FIM_TELAS_DE_EXIBICAO
			#define FIM_TELAS_DE_EXIBICAO    	TELA_TESTE1

	#endif
*/


#endif

#if EQUIP==CM_EQUIP 
#define FIM_TELAS_DE_EXIBICAO    	TELA_TESTE
#endif


#define INICIO_TELAS_DE_PROGRAMACAO	     	FIM_TELAS_DE_EXIBICAO+1 



#define TELA_PROG_REL_TP_PRI     		 	INICIO_TELAS_DE_PROGRAMACAO
#define TELA_PROG_REL_TP_SEC			 	INICIO_TELAS_DE_PROGRAMACAO+1
#define TELA_PROG_REL_TP_FAT			 	INICIO_TELAS_DE_PROGRAMACAO+2
#define TELA_PROG_REL_TC_PRI			 	INICIO_TELAS_DE_PROGRAMACAO+3
#define TELA_PROG_REL_TC_SEC			 	INICIO_TELAS_DE_PROGRAMACAO+4
#define TELA_PROG_REL_TC_FAT			 	INICIO_TELAS_DE_PROGRAMACAO+5
#define TELA_PROG_RESET_CONSUMO		 	INICIO_TELAS_DE_PROGRAMACAO+6
#define TELA_PROG_ESCRAVO_MODBUS		 	INICIO_TELAS_DE_PROGRAMACAO+7
#define TELA_PROG_BAUD_RATE		   	 	INICIO_TELAS_DE_PROGRAMACAO+8
#define TELA_PROG_PARIDADE_STOPS		 	INICIO_TELAS_DE_PROGRAMACAO+9
#define TELA_PROG_IP_OCTETO1	 	 		INICIO_TELAS_DE_PROGRAMACAO+10
#define TELA_PROG_IP_OCTETO2	  	 		INICIO_TELAS_DE_PROGRAMACAO+11
#define TELA_PROG_IP_OCTETO3	  	 		INICIO_TELAS_DE_PROGRAMACAO+12
#define TELA_PROG_IP_OCTETO4	 	 		INICIO_TELAS_DE_PROGRAMACAO+13
#define TELA_PROG_MK_OCTETO1	 	 		INICIO_TELAS_DE_PROGRAMACAO+14
#define TELA_PROG_MK_OCTETO2	  	 		INICIO_TELAS_DE_PROGRAMACAO+15
#define TELA_PROG_MK_OCTETO3	  	 		INICIO_TELAS_DE_PROGRAMACAO+16
#define TELA_PROG_MK_OCTETO4	 	 		INICIO_TELAS_DE_PROGRAMACAO+17
#define TELA_PROG_GW_OCTETO1	 	 		INICIO_TELAS_DE_PROGRAMACAO+18
#define TELA_PROG_GW_OCTETO2	  	 		INICIO_TELAS_DE_PROGRAMACAO+19
#define TELA_PROG_GW_OCTETO3	  	 		INICIO_TELAS_DE_PROGRAMACAO+20
#define TELA_PROG_GW_OCTETO4	 	 		INICIO_TELAS_DE_PROGRAMACAO+21
#define TELA_PROG_NRO_PORTA 			 	INICIO_TELAS_DE_PROGRAMACAO+22
#define TELA_PROG_REL_TP_PRI_MOD  		 	INICIO_TELAS_DE_PROGRAMACAO+23
#define TELA_PROG_REL_TP_SEC_MOD		 	INICIO_TELAS_DE_PROGRAMACAO+24
#define TELA_PROG_REL_TP_FAT_MOD		 	INICIO_TELAS_DE_PROGRAMACAO+25
#define TELA_PROG_REL_TC_PRI_MOD		 	INICIO_TELAS_DE_PROGRAMACAO+26
#define TELA_PROG_REL_TC_SEC_MOD		 	INICIO_TELAS_DE_PROGRAMACAO+27
#define TELA_PROG_REL_TC_FAT_MOD		 	INICIO_TELAS_DE_PROGRAMACAO+28
#define TELA_PROG_RESET_CONSUMO_MOD	 	INICIO_TELAS_DE_PROGRAMACAO+29
#define TELA_PROG_ESCRAVO_MODBUS_MOD	 	INICIO_TELAS_DE_PROGRAMACAO+30
#define TELA_PROG_BAUD_RATE_MOD		 	INICIO_TELAS_DE_PROGRAMACAO+31
#define TELA_PROG_PARIDADE_STOPS_MOD	 	INICIO_TELAS_DE_PROGRAMACAO+32
#define TELA_PROG_IP_OCTETO1_MOD	 		INICIO_TELAS_DE_PROGRAMACAO+33
#define TELA_PROG_IP_OCTETO2_MOD	 		INICIO_TELAS_DE_PROGRAMACAO+34
#define TELA_PROG_IP_OCTETO3_MOD	 		INICIO_TELAS_DE_PROGRAMACAO+35
#define TELA_PROG_IP_OCTETO4_MOD	 		INICIO_TELAS_DE_PROGRAMACAO+36
#define TELA_PROG_MK_OCTETO1_MOD	 		INICIO_TELAS_DE_PROGRAMACAO+37
#define TELA_PROG_MK_OCTETO2_MOD	 		INICIO_TELAS_DE_PROGRAMACAO+38
#define TELA_PROG_MK_OCTETO3_MOD	 		INICIO_TELAS_DE_PROGRAMACAO+39
#define TELA_PROG_MK_OCTETO4_MOD	 		INICIO_TELAS_DE_PROGRAMACAO+40
#define TELA_PROG_GW_OCTETO1_MOD	 		INICIO_TELAS_DE_PROGRAMACAO+41
#define TELA_PROG_GW_OCTETO2_MOD	 		INICIO_TELAS_DE_PROGRAMACAO+42
#define TELA_PROG_GW_OCTETO3_MOD	 		INICIO_TELAS_DE_PROGRAMACAO+43
#define TELA_PROG_GW_OCTETO4_MOD	 		INICIO_TELAS_DE_PROGRAMACAO+44
#define TELA_PROG_NRO_PORTA_MOD 	 		INICIO_TELAS_DE_PROGRAMACAO+45
#define TELA_PROG_GRAVAR_SIM_NAO_MOD 		INICIO_TELAS_DE_PROGRAMACAO+46

#define FIM_TELAS_DE_PROGRAMACAO TELA_PROG_NRO_PORTA 

#if  EQUIP==CM_EQUIP  
#define NUMERO_DE_TELAS FIM_TELAS_DE_PROGRAMACAO+1
#else
#define NUMERO_DE_TELAS TELA_PROG_GRAVAR_SIM_NAO_MOD+1
#endif


//posição dos leds frontais
#define LED_Kwh   	0x00000001		 //1
#define LED_Kvarh  	0x00000002		 //2
#define LED_MinC 	0x00000004		 //3
#define LED_MinB  	0x00000008		 //4
#define LED_DhtU  	0x00000010		 //5
#define LED_DhtI 	0x00000020		 //6
#define LED_Freq   	0x00000040		 //7
#define LED_Trif   	0x00000080		 //8

#define LED_Var    	0x00000100		 //9
#define LED_FaseA  	0x00000200		 //10
#define LED_KiloA  	0x00000400		 //11
#define LED_FaseB  	0x00000800		 //12
#define LED_KiloB  	0x00001000		 //13
#define LED_FaseC  	0x00002000		 //14
#define LED_KiloC  	0x00004000		 //15
#define LED_Va   	0x00008000		 //16

#define LED_Volt   	0x00010000		 //17
#define LED_Amp    	0x00020000		 //18
#define LED_Fp     	0x00040000		 //19
#define LED_Watt   	0x00080000		 //20
#define LED_MinA   	0x00100000		 //21
#define REL_1	   	0x00200000		  
#define REL_2		0x00400000		 
#define REL_3		0x00800000		 


#define dpyLINHA1		0
#define dpyLINHA2		4
#define dpyLINHA3		8

#define UNIDADE	11
#define DEZENA	10
#define CENTENA	 9
#define MILHAR	 8								 

#define ON 			1
#define OFF			0

#if  EQUIP!=CM_EQUIP 
#define COMPARACAO_TIPO1  1
#define COMPARACAO_TIPO2  2
#define COMPARACAO_TIPO3  3
#define COMPARACAO_TIPO4  4
#define COMPARACAO_TIPO5  5
#define COMPARACAO_TIPO6  6
#define COMPARACAO_TIPO7  7

typedef struct _RelesStruct{
	//endereco modbus das grandezas que serao comparadas com os setpoints
	short eRgrandeza1;
	short eRgrandeza2;
	short eRgrandeza3;
	//setpoints
	short Rsetpoint1;
	short Rsetpoint2;
	short Rsetpoint3;
	//setpoints
	short RtempoObservacao;	//se 'infinito' nunca liga o RELE!
	//tipo de comparaçao
	short RtipoDeComparacao;	
} RelesStruct;

/*
   exemplo, para teste da RelesStruct

   00
   44
   00
   46
   00
   48
   00
   03
   00
   03
   00
   03
   00
   01
   00
   01

 */
#endif
/* rotinas */
#if  EQUIP!=CM_EQUIP 
EXT void atualizaDevName(void);
void TelaTR1(int NTela);
#endif
void inicializa_funcao_teclas(int tela);
void proximaTela(int tela);
void executaFuncao(int funcao);
void inicializaTela(int tela);
void gerenciaTelas(void);
void runningLEDs (unsigned int rounds);
void leTeclado(void);
void clrLED (DWORD led);
void setLED (DWORD led);
void TelaValoresTrifasicos(float grandeza1,float grandeza2,float grandeza3);
extern void  TecladoInit(void);
void WriteFloatString(float f,char canal);
void WriteIntString(short ii,char canal);
extern void clrALL_LEDs(void);
extern void setAll_LEDs(void);
void InttoBCD(unsigned short numero, char *milhar, char *centena, char *dezena, char *unidade);
unsigned short BCDtoInt(char milhar, char centena, char dezena, char unidade);
void AtualizaParametrizacao(void);
extern void FloatToStrForEnergy(float numero, char *str);
#if  EQUIP!=CM_EQUIP 

extern void FloatToStrForPulso(float numero, char *str);
short AvaliaRele(RelesStruct ReleX, short QualRele);
void OperaRele(short QualRele,short OnOff);
void PrtLcdBcdNumber(char number);
void PrtLcdBcdNumber2(char number);
void Sys_HexBcd(unsigned long int numero);

#endif
void EscreveReles(short Saidas);
void If_Atualizacao(void);
void If_GeraTela11(void);
void If_GeraTela12(void);
void If_GeraTela13(void);
void If_GeraTela14(void);
void If_GeraTela15(void);
void If_GeraTela16(void);
void If_GeraTela17(void);
void If_GeraFunc35(void);
void If_GeraFunc36(void);
void If_GeraFunc37(void);
void If_GeraFunc38(void);
#ifdef HABsangrado
void If_GeraFunc40(void);
#endif
void If_GeraFunc39(void);
void If_GeraFunc41(void);
void If_GeraFunc42(void);
void If_GeraFunc43(void);
void If_NovoRTC(void);
void If_NovoEnderecoDeRede(char tipo_de_endereco);
void If_NovoSemControleFim(void);
void If_NovoSemControleInicio(void);

void If_PedeSenha(void);
void If_NovaSenha(void);
void If_Interfacear(void);
void If_Escalona(float tfloat);
void If_PutIP(float tfloat);
void If_GeraTela00(void);
void If_GeraTela01(void);
void If_GeraTela02(void);
void If_GeraTela03(void);
void If_GeraTela04(void);
void If_GeraTela05(void);
void If_GeraTela06(void);
void If_GeraTela07(void);
void If_GeraTela08(void);
void If_GeraTela09(void);
void If_GeraTela10(void);
void If_GeraFunc1ao12(unsigned char Nfunc);
//void If_GeraFunc1ao12(unsigned char Nfunc,unsigned char stat);
void If_GeraFunc13ao14(void);
void If_GeraFunc13(void);
void If_PutInt(unsigned int v);
void If_GeraFunc14(void);
void If_GeraFunc15(void);
void If_GeraFunc16(void);
void If_GeraFunc17(void);
void If_GeraFunc18(void);
void If_GeraFunc19(void);
void If_GeraFunc20(void);
void If_GeraFunc21(void);
void If_GeraFunc22(void);
void If_GeraFunc23(void);
void If_GeraFunc24(void);
void If_GeraFunc25(void);
void If_GeraFunc26(void);
void If_GeraFunc27(void);
void If_GeraFunc28(void);
void If_GeraFunc29(void);
void If_GeraFunc30(void);
void If_GeraFunc31(void);
void If_GeraFunc32(void);
void If_GeraFunc33(void);
void If_GeraFunc34(void);
void If_GeraFunc_Duas_Opcoes(unsigned char Tela[],unsigned char op0[],unsigned char op1[],unsigned char Nfuncao);
void If_GeraFunc_Tres_Opcoes(unsigned char Tela[],unsigned char op1[],unsigned char op2[],unsigned char op3[],unsigned char Nfuncao);
void If_GeraFunc_Quatro_Opcoes (unsigned char Tela[],unsigned char op1[],unsigned char op2[],unsigned char op3[],unsigned char op4[],unsigned char Nfuncao);
void If_DecParam(unsigned char menu);
void If_IncParam(unsigned char menu);
void If_IncDecAux(unsigned char menu,unsigned char a,unsigned char b,unsigned char c);
void If_IncDecParam(unsigned char menu,char inc);
void If_IncMenu(char prog);
void If_DecMenu(char prog);
void If_MostraRel(unsigned int pri,unsigned int sec);
void If_NovaRel(unsigned char tipo);
//void If_Tela(unsigned char NTela);
void If_TelaMensagens(unsigned char NTela);
void If_TelaProgramacao(unsigned char NTela);
void If_TelaApresentacao(unsigned char NTela);
void If_Atualizacao(void);
void If_SimbolosDoCantoEsquerdo(void);
void If_PutDht(float Dht);
void If_PutQ(float Q);
void If_PutP(float P);
void If_PutI(float Irms);
void If_PutV(float Vrms);
void If_PutCosFi(float cosfi);
void If_PutTemperatura(void);
void If_AtualizaParametros(void);
char If_VerificaErros(void);
void If_GeraFunc_Duas_Opcoes1(unsigned char Tela[],unsigned char op0[],unsigned char op1[],unsigned char Nfuncao);
void If_IncDecAux1(unsigned char* var,unsigned char limitesup,unsigned char limiteinf,unsigned char incremento);

#define Tela_00 0
#define Tela_01 1
#define Tela_02 2
#define Tela_03 3
#define Tela_04 4
#define Tela_05 5
#define Tela_06 6
#define Tela_07 7
#define Tela_08 8
#define Tela_09 9
#define Tela_10 10

#define Tela_funcao01 1
#define Tela_funcao02 2
#define Tela_funcao03 3
#define Tela_funcao04 4
#define Tela_funcao05 5
#define Tela_funcao06 6
#define Tela_funcao07 7
#define Tela_funcao08 8
#define Tela_funcao09 9
#define Tela_funcao10 10
#define Tela_funcao11 11
#define Tela_funcao12 12
#define Tela_funcao13 13
#define Tela_funcao14 14
#define Tela_funcao15 15
#define Tela_funcao16 16
#define Tela_funcao17 17
#define Tela_funcao18 18
#define Tela_funcao19 19
#define Tela_funcao20 20
#define Tela_funcao21 21
#define Tela_funcao22 22
#define Tela_funcao23 23
#define Tela_funcao24 24
#define Tela_funcao25 25
#define Tela_funcao26 26
#define Tela_funcao27 27
#define Tela_funcao28 28
#define Tela_funcao29 29
#define Tela_funcao30 30
#define Tela_funcao31 31
#define Tela_funcao32 32
#define Tela_msg00 0
#define Tela_msg01 1
#define Tela_msg02 2
#define Tela_msg03 3
#define Tela_msg04 4
#define Tela_msg05 5
#define Tela_msg06 6
#define Tela_msg07 7
#define Tela_msg08 8
#define Tela_msg09 9
#define Tela_msg10 10

#define TudoPretoSYMB 0x8
#define CmaisSYMB     0x1
#define CmenosSYMB    0x2
#define AlarmeSYMB    0x3
#define A_SYMB        0x4
#define B_SYMB        0x5
#define C_SYMB        0x6
#define FI_SYMB       0x7





#define R_TP 0
#define R_TC 4



extern  const unsigned char sTela_msg00[];    
extern  const unsigned char sTela_msg01[];    
extern  const unsigned char sTela_msg02[];    
extern  const unsigned char sTela_msg03[];    
extern  const unsigned char sTela_msg04[];    
extern  const unsigned char sTela_msg05[];    
extern  const unsigned char sTela_msg06[];    
extern  const unsigned char sTela_msg07[];    
extern   const unsigned char sTela_CriandoCombinacoes[];
extern   const unsigned char sTela_funcao1ao12a[]; 								 
extern   const unsigned char sTela_funcao1ao12b[]; 
extern   const unsigned char sTela_funcao13[];
extern   const unsigned char sTela_funcao14[];  
extern   const unsigned char sTela_funcao15a[]; 
extern   const unsigned char sTela_funcao15b[]; 
extern   const unsigned char sTela_funcao15c[]; 
extern   const unsigned char sTela_funcao16[];  
extern   const unsigned char sTela_funcao17[];  
extern   const unsigned char sTela_funcao18[];  
extern   const unsigned char sTela_funcao19[];  
extern   const unsigned char sTela_funcao20[];  
extern   const unsigned char sTela_funcao21a[]; 
extern   const unsigned char sTela_funcao21b[]; 
extern   const unsigned char sTela_funcao21c[]; 
extern   const unsigned char sTela_funcao22[]; 
extern   const unsigned char sTela_funcao23[];  
extern   const unsigned char sTela_funcao24[];  
extern   const unsigned char sTela_funcao25[];  
extern   const unsigned char sTela_funcao26[];  
extern   const unsigned char sTela_funcao27[];
extern   const unsigned char sTela_inativo[]; 	
extern   const unsigned char sTela_ativo[]; 	
extern   const unsigned char sTela_so_alarme[];
extern   const unsigned char sTela_desl_banco[];
extern   const unsigned char sTela_nao_atua[];  
extern   const unsigned char sTela_funcao29[];  
extern   const unsigned char sTela_funcao30[];  
extern   const unsigned char sTela_funcao31a[]; 
extern   const unsigned char sTela_funcao31b[]; 
extern   const unsigned char sTela_funcao31c[]; 
extern   const unsigned char sTela_funcao31d[]; 
extern   const unsigned char sTela_funcao32[]; 
extern   const unsigned char sTela_funcao33a[]; 
extern   const unsigned char sTela_funcao33b[]; 
extern   const unsigned char sTela_funcao33c[]; 
extern   const unsigned char sTela_funcao33d[]; 

#endif

