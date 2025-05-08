/*****************************************************************************
 *   principal.c:  Aqui se encontra a rotina main em C com lo la�o principal
 *
 *   Projeto CM4040-ARM
 *
 *   History
 *   2006.18.11  ver. c�digo 1.00  Vers�o Preliminar. Baseado no MD4000
 *
 ******************************************************************************/

#include <stdbool.h>
#include <string.h>


#define EXT extern
#include "global.h"
#include "lwip_mqtt.h"
/*
#undef EXT
#define EXT
#include "linhabasica_port.h"
regmodbus MapaModbus __attribute__ ((section ("MODBUS_MAPA"))) ={ 0 };


#include "timeouts.h"
#undef EXT
#define EXT
#include "global.h"	*/
extern void ResponderMODBUS(void);
extern void ResponderPR4000(void);
extern void Calculos1(void);
extern TIM_HandleTypeDef htim12;

char GsmGetStatus();
char SaveIPAddress();
void SendCommandToGSM(char *s);
char ProcessGsmMessage();
char ProcessGsmIpAddressMessage();
char ProcessGsmDataToCommandMode();
char GsmOpenTcpConnection();
char GsmStateMachine();
char GetAPN();




/* inicializar modem
char cmdbuf[30] = "AT+CPIN=";
  strcat(cmdbuf, pin);
  requestModem("AT", 1000, true, buf);
  requestModem("AT+IPR=19200", 1000, true, buf);
  requestModem("AT+CMEE=2", 1000, true, buf);
  requestModem(cmdbuf, 1000, true, buf); */



#define MCLK 72000000                         /* Master Clock 48 MHz         */
#define TCLK       10                         /* Timer Clock rate 10/s       */
#define TCNT (MCLK/TCLK/4)                    /* Timer Counts                */

BOOL dhcp_tick;
BOOL gettime_tick;
BOOL sent;
U32 delay;
U32 dhcp_tout;


U8 socket_tcp = 0;
U8 socket_udp = 0;

enum e_msg_socket modbus_msg_protocol;

U8 tcp_head[6];
U16 udp_callback(U8 soc, U8 *rip, U16 rport, U8 *buf, U16 len);


U16 tcp_callback(U8 *rip, U16 rport, U8 *ptr, U16 par);

U8 *sendbuf;

#define MY_IP localm[NETIF_ETH].IpAdr

extern void T0isr(void) __irq;
extern void timer_admite_nested_interrupt_srv(void);
extern void timer_admite_nested_interrupt_irq(void);

static void timer_poll(void);

U16 AD_in(U32 ch);

BOOL LEDrun;

U16 udp_callback(U8 soc, U8 *rip, U16 rport, U8 *buf, U16 len);
U8 *sendbuf;

#define MY_IP localm[NETIF_ETH].IpAdr
#define DHCP_TOUT   50
U8 Rem_IP[4];
short NroPortaRemota = 1001;
short modo_escritaMM=0;
long int etapa_escritaMM=0;
unsigned int pagina=3;



/*--------------------------- dhcp_check ------------------------------------*/




bool tcpip_not_initd = true;


#if COM_DHCP == OFF
U32 dhcp_config_enabled = 0;
#else
U32 dhcp_config_enabled = 1;
#endif


void refresh_ip(void)
{
#ifdef LEGADO
	if (tcpip_not_initd)
		return;

	if (dhcp_config_enabled)
	{
		tcpip_setup();
	}
	else
	{
		dhcp_disable();
		set_default_ip();
	}
#else
	extern void  change_ip(void);

	ip_config.IpAdr[0]=IPOcteto1;	// Local IP Address
	ip_config.IpAdr[1]=IPOcteto2;	// Local IP Address
	ip_config.IpAdr[2]=IPOcteto3;	// Local IP Address
	ip_config.IpAdr[3]=IPOcteto4;	// Local IP Address


	 ip_config.NetMask[0]=MKOcteto1;
	 ip_config.NetMask[1]=MKOcteto2;
	 ip_config.NetMask[2]=MKOcteto3;
	 ip_config.NetMask[3]=MKOcteto4;
	 ip_config.DefGW[0]=GWOcteto1;
	 ip_config.DefGW[1]=GWOcteto2;
	 ip_config.DefGW[2]=GWOcteto3;
	 ip_config.DefGW[3]=GWOcteto4;






	change_ip();
#endif

}



void VerificaNumeroDeSerie(void)
{

	BYTE const *pFlashByte;
	extern void get_calib_addr(void);
	get_calib_addr( );
	pFlashByte = (const BYTE*)(curr_calib_addr+ 0xe8);

	//pFlashByte = (const BYTE*) SETOR_CALIBRACAO_INICIO + 0xe8; //pFlashFloat;

	nserie_str[0] = *pFlashByte++;
	nserie_str[1] = *pFlashByte++;
	nserie_str[2] = *pFlashByte++;
	nserie_str[3] = *pFlashByte++;
	nserie_str[4] = *pFlashByte++;
	nserie_str[5] = *pFlashByte++;
	nserie_str[6] = *pFlashByte++;
	nserie_str[7] = *pFlashByte++;
	EquipVirgem = NAO;
	if      ((nserie_str[0] > 0x39) | (nserie_str[1] > 0x39) | (nserie_str[2] > 0x39) | (nserie_str[3] > 0x39) | (nserie_str[4] > 0x39) | (nserie_str[5] > 0x39)
			|(nserie_str[6] > 0x39) | (nserie_str[7] > 0x39) | (nserie_str[0] < 0x30) | (nserie_str[1] < 0x30) | (nserie_str[2] < 0x30) | (nserie_str[3] < 0x30)
			|(nserie_str[4] < 0x30) | (nserie_str[5] < 0x30) | (nserie_str[6] < 0x30) | (nserie_str[7] < 0x30))
	{
		nserie_str[0] = '1';
		nserie_str[1] = '2';
		nserie_str[2] = '3';
		nserie_str[3] = '4';
		nserie_str[4] = '5';
		nserie_str[5] = '6';
		nserie_str[6] = '7';
		nserie_str[7] = '8';
		EquipVirgem = SIM;
	}
	//EquipVirgem = NAO;
	//EquipVirgem = SIM;
}

#define SPI_AD_CONFIG_CH0 0x0000
#define SPI_AD_CONFIG_CH1 0x0800

/*
	Escreve valor no conversor A/D atrav�s da SPI
*/
void WriteAddrToAD(unsigned short addr)
{
#ifdef LEGADO
#if MD4040TI == 1
	while (SSP1SR & SSPSR_TNF)
	{
	   SSP1DR = addr;
	}
#else
	while (SSP0SR & SSPSR_TNF)
	{
	   SSP0DR = addr;
	}
#endif

#endif
}

/*
	L� valor do conversor A/D atrav�s da SPI
*/
float ReadValueFromAD()
{

	float value = 0;
#ifdef LEGADO
#if MD4040TI == 1
	while (SSP1SR & SSPSR_RNE)
	{
	   value = SSP1DR;
	}
#else
	while (SSP0SR & SSPSR_RNE)
	{
	   value = SSP0DR;
	}
#endif

#endif
	return (float)((int)value >> 2);
}

/*
 no codigo do MD
// ############## CALIBRACAO DE TEMPERATURA ##################
#define TEMPERATURA_DE_REFERENCIA	21.5	// Temperatura lida pelo sensor de referencia
#define TEMPERATURA_MEDIDA_SENSOR1	28.2	// Temperatura lida pelo canal 1 de temperatura do MD4060
#define TEMPERATURA_MEDIDA_SENSOR2	22.4	// Temperatura lida pelo canal 2 de temperatura do MD4060
// ###########################################################
#define A1     	0.1818724
#define B1    	35.586742 + (TEMPERATURA_DE_REFERENCIA - TEMPERATURA_MEDIDA_SENSOR1)
//#define A1     	0.1804479
//#define B1    	41.277773 + (TEMPERATURA_DE_REFERENCIA - TEMPERATURA_MEDIDA_SENSOR1)
#define A2     	0.1818724
#define B2    	35.586742 + (TEMPERATURA_DE_REFERENCIA - TEMPERATURA_MEDIDA_SENSOR2)

	Salva e calibra os valores de temperatura adquiridos do A/D via SPI.
	Obs: hold_function serve para o A/D ter tempo de escrever pela SPI.


no codigo do TR
// ############## CALIBRACAO DE TEMPERATURA ##################
#define TEMPERATURA_DE_REFERENCIA	30.1	// Temperatura lida pelo sensor de referencia
#define TEMPERATURA_MEDIDA_SENSOR1	34.4	// Temperatura lida pelo canal 1 de temperatura do MD4060
#define TEMPERATURA_MEDIDA_SENSOR2	33.8	// Temperatura lida pelo canal 2 de temperatura do MD4060
// ###########################################################
#define A1     	0.1804479
#define B1    	41.277773 + (TEMPERATURA_DE_REFERENCIA - TEMPERATURA_MEDIDA_SENSOR1)
#define A2     	0.1818724
#define B2    	35.586742 + (TEMPERATURA_DE_REFERENCIA - TEMPERATURA_MEDIDA_SENSOR2)

	Salva e calibra os valores de temperatura adquiridos do A/D via SPI.
	Obs: hold_function serve para o A/D ter tempo de escrever pela SPI.´

no codigo do CM
// ############## CALIBRACAO DE TEMPERATURA ##################
#define TEMPERATURA_DE_REFERENCIA	14.1	// Temperatura lida pelo sensor de referencia
#define TEMPERATURA_MEDIDA_SENSOR1	-10.5	// Temperatura lida pelo canal 1 de temperatura do MD4060
#define TEMPERATURA_MEDIDA_SENSOR2	-4.2// Temperatura lida pelo canal 2 de temperatura do MD4060
// ###########################################################
#define A1     	0.1804479
#define B1    	41.277773 + (TEMPERATURA_DE_REFERENCIA - TEMPERATURA_MEDIDA_SENSOR1)
#define A2     	0.1818724
#define B2    	35.586742 + (TEMPERATURA_DE_REFERENCIA - TEMPERATURA_MEDIDA_SENSOR2)


 */
#if MD4040TI == 1
	#define TEMPO_INTEGRACAO_TEMPERATURA 200
#else
	#define TEMPO_INTEGRACAO_TEMPERATURA 10
#endif
void GetTemperatureFromAD()
{
	static char var = 0;
	static char hold_function = 0;
	static float temp_ch0_acc = 0;
	static float temp_ch1_acc = 0;
	static int cnt_ch0 = 0;
	static int cnt_ch1 = 0;

	if(hold_function == 1)
	{
		hold_function = 0;
		return;
	}

	switch (var)
	{
		case 0:
			WriteAddrToAD(SPI_AD_CONFIG_CH0);
		break;

		case 1:
			temp_ch0_acc += ReadValueFromAD();
			cnt_ch0++;

			if(cnt_ch0 > TEMPO_INTEGRACAO_TEMPERATURA)
			{

				temperatura_ptc_ch0 = temp_ch0_acc/cnt_ch0;

				if(temperatura_ptc_ch0 > 1000)
				{
					temperatura_ptc_ch0 = 0;
				}
				else
				{
					#ifndef CAL_TEMPERATURA
					temperatura_ptc_ch0 = 0.00007*(temperatura_ptc_ch0*temperatura_ptc_ch0) + 0.9279*temperatura_ptc_ch0 + 6.6326;
					#endif
					// Metodo de calibra��o com coeficientes hardcode do Gabriel
					//temperatura_ptc_ch0 = temperatura_ptc_ch0 * A1 - B1;
					// Metodo que usa vari�veis do calibrador do C�sar
					temperatura_ptc_ch0 = temperatura_ptc_ch0 * TemperaturaCoefA_ch0 + TemperaturaCoefB_ch0;
				}
				// Metodo que usa vari�veis do calibrador do C�sar
				TemperaturaCh0 = temperatura_ptc_ch0;
				temp_ch0_acc = 0;
				cnt_ch0 = 0;

			}


		break;

		case 2:
			WriteAddrToAD(SPI_AD_CONFIG_CH1);
		break;

		case 3:
			temp_ch1_acc += ReadValueFromAD();
			cnt_ch1++;

			if(cnt_ch1 > TEMPO_INTEGRACAO_TEMPERATURA)
			{
				temperatura_ptc_ch1 = temp_ch1_acc/cnt_ch1;

				if(temperatura_ptc_ch1 > 1000)
				{
					temperatura_ptc_ch1 = 0;
				}
				else
				{
					#ifndef CAL_TEMPERATURA
					temperatura_ptc_ch1 = 0.00007*(temperatura_ptc_ch1*temperatura_ptc_ch1) + 0.9279*temperatura_ptc_ch1 + 6.6326;
					#endif
					// Metodo de calibra��o com coeficientes hardcode do Gabriel
					//temperatura_ptc_ch1 = temperatura_ptc_ch1 * A2 - B2;
					// Metodo que usa vari�veis do calibrador do C�sar
					temperatura_ptc_ch1 = temperatura_ptc_ch1 * TemperaturaCoefA_ch1 + TemperaturaCoefB_ch1;
				}
				// Metodo que usa vari�veis do calibrador do C�sar
				TemperaturaCh1 = temperatura_ptc_ch1;
				temp_ch1_acc = 0;
				cnt_ch1 = 0;
			}

		break;

		default:
			return;
	}

	var = (var + 1) % 4;

	hold_function = 1;
}


extern float swapFloat ( float var);

int main1()
{

	short cont200ms = 0;

	short tmpcontador = 0;


	BYTE tt = 1;
	short t = 1;
	short NTelaTR = 1;


	NroPortaRemota = 1001;


	WDTInit();
	TargetInit();
	GPIOResetInit();

	EquipVirgem = NAO;

	VerificaNumeroDeSerie();

	//EquipVirgem = NAO;  //forçadamente, em teste
	//EquipamentoCalibrado=SIM; //forçadamente, em teste


	if (EquipVirgem == SIM)
		RegistroCabecalho2K.id = ~RegistroCabecalho2K.id;

	InitBatteryRam();
	for(int x = 0; x < 10; x++)toogleWDI();

	if (EquipVirgem == NAO)
		TesteBateria();


	if ((RegistroCabecalho2K.ProximoEnderecoAserEscritoNaFlash < SETOR_MM_INICIO)
//	|| (RegistroCabecalho2K.ProximoEnderecoAserEscritoNaFlash > SETOR_PARAMETRIZACAO_FIM))
	|| (RegistroCabecalho2K.ProximoEnderecoAserEscritoNaFlash > SETOR_MM_FIM))  //aqui houve uma alteracao em relacao ao LEGADO
	{
		//se a batram se perde ao ponto de querer sobre-escrever o c�digo .hex ent�o nesse caso melhor limpar a batram e toda a regi�o de dados da flash, e resetar o equipamento.
		toogleWDI();
		for(int x = 0; x < 10; x++)toogleWDI();
		erase((void*) SETOR_DADOS1_INICIO, (void*) SETOR_DADOS1_FIM);
		toogleWDI();
		for(int x = 0; x < 10; x++)toogleWDI();

		erase((void*) SETOR_DADOS2_INICIO, (void*) SETOR_DADOS2_FIM);
		toogleWDI();
		for(int x = 0; x < 10; x++)toogleWDI();

		RegistroCabecalho2K.id = ~REG_BATT_MEM_INIT;
		InitBatteryRam();
		for(int x = 0; x < 10; x++)toogleWDI();
	}

	HAL_TIM_Base_Stop(&htim12);
	//	RegistroCabecalho2K.id = 0xDEAD;
	//	InitBatteryRam();



	DisplayInit();
	TecladoInit();





	if (EquipVirgem == SIM)
		RestauraParametrizacaoDefault();
	else
		RestauraParametrizacao();

 	RestauraCalibracao();

	 if (EquipVirgem == NAO)PowerUp();
	 else{
		 PowerUp();
	 }

	init_timer();
	enable_timer(1);
	enable_timer(0);

//FlagWDIDentroDoTimer = SIM;



	localm[NETIF_ETH].IpAdr[0] = ip_config.IpAdr[0];
	localm[NETIF_ETH].IpAdr[1] = ip_config.IpAdr[1];
	localm[NETIF_ETH].IpAdr[2] = ip_config.IpAdr[2];
	localm[NETIF_ETH].IpAdr[3] = ip_config.IpAdr[3];
	localm[NETIF_ETH].DefGW[0] = ip_config.DefGW[0];
	localm[NETIF_ETH].DefGW[1] = ip_config.DefGW[1];
	localm[NETIF_ETH].DefGW[2] = ip_config.DefGW[2];
	localm[NETIF_ETH].DefGW[3] = ip_config.DefGW[3];
	localm[NETIF_ETH].NetMask[0] = ip_config.NetMask[0];
	localm[NETIF_ETH].NetMask[1] = ip_config.NetMask[1];
	localm[NETIF_ETH].NetMask[2] = ip_config.NetMask[2];
	localm[NETIF_ETH].NetMask[3] = ip_config.NetMask[3];

	ADCInit(ADC_CLK);
	ComMODBUSInit();
//UARTInit(BaudRatex, ParidadeStops);
	RTCInit();
	RTCStart();
	EINTInit();

	DisablePoweDownInterrupt();


//    UARTInit(BR115200, ps8N1);


	NTelaTR = ultimaTelaExibida;

	while (1)
	{

		//EquipVirgem = NAO;  //forçadamente, em teste
		//EquipamentoCalibrado=SIM; //forçadamente, em teste

		CiclarTelas = OFF;
		if (timer_counter0 >= 384) //384=aprox 100ms
		{
			tt++;
			if (tt == OnOffPulseRate)
			{
				tt = 0;

				SETpinoEmPorta(0,LED_ONOFF_PIN);
			}
			else
			{

				CLRpinoEmPorta(0,LED_ONOFF_PIN);
				SETpinoEmPorta(0,LED_TX);
				SETpinoEmPorta(0,LED_RX);

			}
			timer_counter0 = 0;


		}

		if (1) //nesta condição se garante velocidade do ping!
			timer_poll ();


		if (cont200ms == 5)
		{
			//contEstouVivo=contEstouVivo+1;
			//if (contEstouVivo>10)
				estouvivo1 = SIM;







				#if ((EQUIP_LINHA50 == CP_EQUIP)||(EQUIP_LINHA50 == CD_EQUIP)||(EQUIP_LINHA50 == CA_EQUIP)||(EQUIP_LINHA50 == CT_EQUIP))
					#include "main.h"
				  	  HAL_GPIO_TogglePin( AUXOUT3_GPIO_Port,AUXOUT3_Pin);  //LED Da placa CORELB50
				  	  HAL_GPIO_TogglePin( LED_PWR_GPIO_Port,LED_PWR_Pin);  //led POWER
				#endif

				TelaTR1(NTelaTR);


				Releportempo2();



				//if (como_remota_GDE == NAO)
				if (1)
				{
					if (inicio_hora_atua_rele1_ini == 0xFF)
						AvaliaRele(Rele1_, 1); //chamados de segundo em segundo...

					if (inicio_hora_atua_rele2_ini == 0xFF)
						AvaliaRele(Rele2_, 2);

					if (inicio_hora_atua_rele3_ini == 0xFF)
						AvaliaRele(Rele3_, 3);
				}

				#if ((EQUIP_LINHA50 == CP_EQUIP)||(EQUIP_LINHA50 == CD_EQUIP))
				if (tMMgrandezas == 15)
				{
					MomentoDeAvaliacaoDeIntervalo15min();
				}
				else
				{

					MomentoDeAvaliacaoDeIntervalo1min();	//tempo m�nimo de observacao...
					MomentoDeAvaliacaoDeIntervalo15min();
				}
				#endif






			cont200ms = 0;
/*
			//a cada 200ms testo se houve conexao com broker.
			if (conectou_broker==0)
			{

				extern mqtt_client_t *client;

				  if(client != NULL) {
					   char temp_string[20];
						sprintf(temp_string,"12345678/perguntas");
					  	temp_string[0]=nserie_str[0];
					  	temp_string[1]=nserie_str[1];
					  	temp_string[2]=nserie_str[2];
					  	temp_string[3]=nserie_str[3];
					  	temp_string[4]=nserie_str[4];
					  	temp_string[5]=nserie_str[5];
					  	temp_string[6]=nserie_str[6];
					  	temp_string[7]=nserie_str[7];
					    example_do_connect(client, temp_string);
					    //send_mqtt(temp_string, 8);
				  }


			}
*/
		}



		toogleWDI();

		if (timer_counter1 >= 10) //aumentar para 100
		{
			tmpcontador++;

			if (tmpcontador == 20) //40//80//originalmente 20
			{
				t = ~t;
				tmpcontador = 0;
				if (CiclarTelas == ON)
				{
					if (t == 1)
					{
						 NTelaTR++;
					}
				}
			}

			//if (BloqueioTeclado == OFF)	// foi tirado para o MD50 do STM32


				//leTeclado(); //atualiza a vari�vel 'teclaAtual'
				extern short newLeTeclado(short NTelaTR);
				NTelaTR=newLeTeclado(NTelaTR);




			timer_counter1 = 0;
		}

		//Atende � pergunta MODBUS, se houver uma...
		if (HabResponder == ON)
		{
			if (estouvivo == 1) //s� responde se completou um ciclo de leitura, isso para manter coerencia com o relogio!
			{
				ResponderMODBUS();

				HabResponder = OFF;
			}
		}


		if (HabCalculos == 1)
		{
			timer_poll (); //

			if (estouvivo1 == SIM)
			{


		#if EQUIP_LINHA50 == MD_EQUIP
				 newCalc();
		#endif
		#if ((EQUIP_LINHA50 == CA_EQUIP)||(EQUIP_LINHA50 == CT_EQUIP))
				 extern void newCalcDC(void);
				 newCalcDC();

		#endif

				EnablePoweDownInterrupt(); //habilitar interrupcao de power down
			}
			#if ((EQUIP_LINHA50 == CP_EQUIP)||(EQUIP_LINHA50 == CD_EQUIP))
				HabCalculos = 0;



			#endif
			cont200ms++;

		}




	} //do while(1)

	return 0;
}

 void modbus_message_received(U8 *buf, int len)
{
	short k;
	{
		///// Aqui agora, vou chamar o Modbus, carregar o Buffer da UART0
		for (k = 0; k < len-1; k++)
			UART0Buffer[k] = buf[k + 1]; //+1 � por causa que o endereco do escravo nao deve estar no buffer da uart

		//se chega uma mensagem via Eth, para meu IP, � porque � pra mim, portanto o byte buf[0] s� vai me ajudar a identificar o tipo de protocolo que
		//devo utilizar para responder � pergunta
		if (buf[0] == 3)
		{
			modelo_3g = SIM;
			MeuEnderecoMODBUS = 3;
			ns7 = nserie_str[7];
			ns6 = nserie_str[6];
			ns5 = nserie_str[5];
			ns4 = nserie_str[4];
			ns3 = nserie_str[3];
			ns2 = nserie_str[2];
			ns1 = nserie_str[1];
			ns0 = nserie_str[0];
		}
		else
		{
			modelo_3g = NAO;

			MeuEnderecoMODBUS = 1;
#ifdef MODELO_PADRAO
			MeuEnderecoMODBUS=2;
#endif
		}

		if (buf[0] == MeuEnderecoMODBUS)
		{
			if (modelo_3g == SIM)
			{
				if ((ns0 == buf[1]) && (ns1 == buf[2]) && (ns2 == buf[3]) && (ns3 == buf[4]) && (ns4 == buf[5]) && (ns5 == buf[6]) && (ns6 == buf[7])
						&& (ns7 == buf[8]))
				{

					FlagChegouBroadCast = NAO;
					FlagChegouEnderecoMODBUS = SIM; //simula que chegou uma mensagem para o meu numero de escravo
					FlagHouveSilencioMODBUS = NAO;
#if EQUIP==TR_EQUIP

					CLRpinoEmPorta(0,LED_RX);
#endif

					for (k = 8; k < len; k++)
						UART0Buffer[k - 8] = buf[k + 1]; //+1 � por causa que o endereco do escravo nao deve estar no buffer
				}
			}
			else
			{
				FlagChegouBroadCast = NAO;
				FlagChegouEnderecoMODBUS = SIM; //simula que chegou uma mensagem para o meu numero de escravo
				FlagHouveSilencioMODBUS = NAO;
#if EQUIP==TR_EQUIP

				CLRpinoEmPorta(0,LED_RX);
#endif
			}
		}
		if (buf[0] == 0x00)
		{
#if EQUIP==TR_EQUIP
			CLRpinoEmPorta(0,LED_RX);
#endif
			FlagChegouBroadCast = SIM; //sempre que chega broad cast, � poss�vel que chegue uma mensagem do PR4000
			FlagChegouEnderecoMODBUS = SIM;
			FlagHouveSilencioMODBUS = NAO;
		}
		ContSilencioMODBUS = TAB_SIL_CARGA[BaudRatex] + 1;
		//da proxima vez que entrar no timer vai avaliar o buffer.
	}
    extern char recebido_mqtt;
	if (recebido_mqtt==1)
	{
		modelo_3g=NAO;
		MeuEnderecoMODBUS = 1;
		FlagChegouEnderecoMODBUS = SIM;
		FlagHouveSilencioMODBUS = SIM;
	}

	return;
}

/*--------------------------- UDP socket ------------------------------------*/

U16 udp_callback(U8 soc, U8 *rip, U16 rport, U8 *buf, U16 len)
{
	modbus_msg_protocol = THRU_UDP;

	NroPortaRemota = rport;

	Rem_IP[0] = rip[0];
	Rem_IP[1] = rip[1];
	Rem_IP[2] = rip[2];
	Rem_IP[3] = rip[3];

	modbus_message_received(buf, len);
	return 0;
}

U16 tcp_callback(U8 *rip, U16 rport, U8 *ptr, U16 par)
{
    #ifdef LEGADO
	/* This function is called by the TCP module on TCP event */
	/* Check the 'Net_Config.h' for possible events.          */

	if (soc != socket_tcp)
	{
		return (0);
	}

	switch (evt)
	{
	case TCP_EVT_DATA:
		/* TCP data frame has arrived, data is located at *par1, */
		/* data length is par2. Allocate buffer to send reply.   */
		modbus_msg_protocol = THRU_TCP;
		tcp_head[0] = ptr[0];
		tcp_head[1] = ptr[1];
		tcp_head[2] = ptr[2];
		tcp_head[3] = ptr[3];
		tcp_head[4] = ptr[4];
		tcp_head[5] = ptr[5];
		modbus_message_received(ptr + 6, par - 6);
		break;

	case TCP_EVT_CONREQ:
		/* Remote peer requested connect, accept it */
		return (1);

	case TCP_EVT_CONNECT:
		/* The TCP socket is connected */
		return (1);

	case TCP_EVT_ABORT:
		return (1);

	case TCP_EVT_CLOSE:
		return (1);
	}
	#else

	#endif // LEGADO


	NroPortaRemota = rport;

	Rem_IP[0] = rip[0];
	Rem_IP[1] = rip[1];
	Rem_IP[2] = rip[2];
	Rem_IP[3] = rip[3];


	modbus_msg_protocol = THRU_TCP;
	tcp_head[0] = ptr[0];
	tcp_head[1] = ptr[1];
	tcp_head[2] = ptr[2];
	tcp_head[3] = ptr[3];
	tcp_head[4] = ptr[4];
	tcp_head[5] = ptr[5];
	modbus_message_received(ptr + 6, par - 6);
	return (0);
}

void send_data(short len)
{
    extern char recebido_mqtt;
    extern void send_mqtt(uint8_t *buf, int len);
	if (recebido_mqtt==1)
	{
    recebido_mqtt=0;
    send_mqtt(UART0Buffer,len);
	goto saindo;
	}


	if (modbus_msg_protocol == THRU_UDP)
	{
#ifdef LEGADO
		U8 *sendbuf;
		short k;
		sendbuf = udp_get_buf(len);
		for (k = 0; k < len; k++)
			sendbuf[k] = UART0Buffer[k];

		udp_send(socket_udp, Rem_IP, NroPortaRemota, sendbuf, len);
#endif
		extern void udp_send1(uint8_t *Rem_IP, uint16_t NroPortaRemota, uint8_t *sendbuf, uint16_t len);
		udp_send1(Rem_IP, NroPortaRemota, UART0Buffer, len);


	}
	else if (modbus_msg_protocol == THRU_TCP)
	{
#ifdef LEGADO
		switch (tcp_get_state(socket_tcp))
		{
		default:
			if (tcp_check_send(socket_tcp))
			{
				if (len > 0)
				{
					short k;
					U8 *sendbuf;

					sendbuf = tcp_get_buf(len + 6 - 2);

					tcp_head[5] = len - 2;

					for (k = 0; k < 6; k++)
						sendbuf[k] = tcp_head[k];

					for (k = 0; k < (len - 2); k++)
						sendbuf[k + 6] = UART0Buffer[k];

					tcp_send(socket_tcp, sendbuf, len + 6 - 2);
				}
			}
			break;
		}
#else
		U8 *sendbuf;
		short k;
		sendbuf=(U8*)malloc(len + 6 - 2);

		tcp_head[5] = len - 2;

		for (k = 0; k < 6; k++)
			sendbuf[k] = tcp_head[k];

		for (k = 0; k < (len - 2); k++)
			sendbuf[k + 6] = UART0Buffer[k];



		extern void tcp_send1(uint8_t *Rem_IP, uint16_t NroPortaRemota, uint8_t *sendbuf, uint16_t len);
		tcp_send1(Rem_IP, NroPortaRemota, sendbuf, len + 6 - 2);
		free(sendbuf);

#endif //LEGADO
	}

saindo:
	modbus_msg_protocol = THRU_NONE;

}

#include <netif.h>

static void timer_poll()
{
	//extern void sys_check_timeouts(void);
	//sys_check_timeouts();
	   //extern struct netif gnetif;
	   //extern  void ethernetif_input(struct netif *netif);
	  // ethernetif_input(&gnetif);
	 //  sys_check_timeouts();
	extern void MX_LWIP_Process(void);
   MX_LWIP_Process( );



}



