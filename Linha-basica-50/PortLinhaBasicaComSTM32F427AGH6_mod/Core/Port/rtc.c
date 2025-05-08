/*****************************************************************************
 *   rtc.c:  Realtime clock C file for Philips LPC214x Family Microprocessors
 *
 *   Copyright(C) 2006, Philips Semiconductor
 *   All rights reserved.
 *
 *   History
 *   2005.10.01  ver 1.00    Prelimnary version, first Release
 *
 *****************************************************************************/
#define EXT extern
#include "global.h"
#include "stm32f4xx_hal.h"
extern RTC_HandleTypeDef hrtc;


/*****************************************************************************
 ** Function name:		RTCInit
 **
 ** Descriptions:		Initialize RTC timer
 **
 ** parameters:			None
 ** Returned value:		None
 **
 *****************************************************************************/
void RTCInit( void )
{
    #ifdef LEGADO
	alarm_on = 0;

	/*--- Initialize registers ---*/
	RTC_AMR = 0;
	RTC_CIIR = 0;
	//CCR = 0;  //com clock interno
	RTC_CCR = 0x10;	//com cristal externo de 32768
	RTC_PREINT = PREINT_RTC;
	RTC_PREFRAC = PREFRAC_RTC;
	return;
	#endif
}


/*****************************************************************************
 ** Function name:		RTCStart
 **
 ** Descriptions:		Start RTC timer
 **
 ** parameters:			None
 ** Returned value:		None
 **
 *****************************************************************************/
void RTCStart( void )
{
    #ifdef LEGADO
	/*--- Start RTC counters ---*/
	RTC_CCR |=  CCR_CLKEN;
	RTC_ILR =   ILR_RTCCIF;
	return;
	#endif
}

/*****************************************************************************
 ** Function name:		RTCStop
 **
 ** Descriptions:		Stop RTC timer
 **
 ** parameters:			None
 ** Returned value:		None
 **
 *****************************************************************************/
void RTCStop( void )
{
    #ifdef LEGADO
	/*--- Stop RTC counters ---*/
	RTC_CCR &= ~ CCR_CLKEN;
	return;
	#endif
}

/*****************************************************************************
 ** Function name:		RTC_CTCReset
 **
 ** Descriptions:		Reset RTC clock tick counter
 **
 ** parameters:			None
 ** Returned value:		None
 **
 *****************************************************************************/
void RTC_CTCReset( void )
{
    #ifdef LEGADO
	/*--- Reset CTC ---*/
	RTC_CCR |= CCR_CTCRST;
	return;
	#endif
}

/*****************************************************************************
 ** Function name:		RTCSetTime
 **
 ** Descriptions:		Setup RTC timer value
 **
 ** parameters:			None
 ** Returned value:		None
 **
 *****************************************************************************/
void RTCSetTime( RTCTime Time )
{

	  RTC_TimeTypeDef sTime = {0};
	  RTC_DateTypeDef sDate = {0};

	  sTime.Hours = Time.RTC_Hour;
	  sTime.Minutes = Time.RTC_Min;
	  sTime.Seconds = Time.RTC_Sec;
	  sTime.DayLightSaving = RTC_DAYLIGHTSAVING_NONE;
	  sTime.StoreOperation = RTC_STOREOPERATION_RESET;
	  if (HAL_RTC_SetTime(&hrtc, &sTime, RTC_FORMAT_BIN) != HAL_OK)
	  {
	//    Error_Handler();
	  }
	  sDate.WeekDay = Time.RTC_Wday;
	  sDate.Month = Time.RTC_Mon;
	  sDate.Date = Time.RTC_Mday;
	  sDate.Year = Time.RTC_Year-2000;

	  if (HAL_RTC_SetDate(&hrtc, &sDate, RTC_FORMAT_BIN) != HAL_OK)
	  {
		//Error_Handler();
	  }

}

#define YEAR0                   1900
#define EPOCH_YR                1970
#define SECS_DAY                (24L * 60L * 60L)
#define LEAPYEAR(year)          (!((year) % 4) && (((year) % 100) || !((year) % 400)))
#define YEARSIZE(year)          (LEAPYEAR(year) ? 366 : 365)
#define FIRSTSUNDAY(timp)       (((timp)->tm_yday - (timp)->tm_wday + 420) % 7)
#define FIRSTDAYOF(timp)        (((timp)->tm_wday - (timp)->tm_yday + 420) % 7)

static const int _ytab[2][12] = {
		{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
		{31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
	};

void RTCSetTimeFromEpoch(unsigned int time)
{

	RTCTime br_time;
	register RTCTime *timep = &br_time;
	int year = EPOCH_YR;

	register unsigned long dayclock, dayno;

	dayclock = (unsigned long) time % SECS_DAY;
	dayno = (unsigned long) time / SECS_DAY;

	timep->RTC_Sec = dayclock % 60;
	timep->RTC_Min = (dayclock % 3600) / 60;
	timep->RTC_Hour = dayclock / 3600;
	timep->RTC_Wday = (dayno + 4) % 7; /* day 0 was a thursday */
	while (dayno >= YEARSIZE(year))
	{
		dayno -= YEARSIZE(year);
		year++;
	}
	timep->RTC_Year = year;
	timep->RTC_Yday = dayno;
	timep->RTC_Mon = 0;
	while (dayno >= _ytab[LEAPYEAR(year)][timep->RTC_Mon])
	{
		dayno -= _ytab[LEAPYEAR(year)][timep->RTC_Mon];
		timep->RTC_Mon++;
	}

	timep->RTC_Mon++;
	timep->RTC_Mday = dayno + 1;

	RTCSetTime(br_time);

}


/*****************************************************************************
 ** Function name:		RTCGetTime
 **
 ** Descriptions:		Get RTC timer value
 **
 ** parameters:			None
 ** Returned value:		The data structure of the RTC time table
 **
 *****************************************************************************/
RTCTime RTCGetTime( void )
{

	RTCTime LocalTime;


	   RTC_TimeTypeDef time_rtc; //Time structure parameter
	   RTC_DateTypeDef date_rtc; //date structure parameter

		HAL_RTC_GetTime(&hrtc, &time_rtc, RTC_FORMAT_BIN);
		HAL_RTC_GetDate(&hrtc, &date_rtc, RTC_FORMAT_BIN);
		/*
	  extern short minuto ;
	  static short hora=0,dia=1,mes=1,ano=2021;
		static last_min;

	    LocalTime.RTC_Sec = 0;
	    if (last_min==minuto)
	    {
	      if (minuto % 60==0)
	    	  hora=hora-1;
	    }

		LocalTime.RTC_Min= minuto % 60;
		if (minuto % 60==0)
			hora=(hora+1)%24;
		if (hora==0)
			dia=(dia+1)%30;
		if (dia==0)
			{dia=1;
			mes=(mes+1)%12;}
		if (mes==0)
			{
				mes=1;
				ano=ano+1;
			}
		minuto=LocalTime.RTC_Min;
		last_min=minuto;

		LocalTime.RTC_Hour = hora;
		LocalTime.RTC_Mday = dia;
		LocalTime.RTC_Mon  = mes;
		LocalTime.RTC_Year = ano;

*/
	LocalTime.RTC_Sec = (short) time_rtc.Seconds;
	LocalTime.RTC_Min = (short) time_rtc.Minutes;
	LocalTime.RTC_Hour =(short) time_rtc.Hours;
	LocalTime.RTC_Mday = (short)date_rtc.Date;
	LocalTime.RTC_Wday = (short)date_rtc.WeekDay;
	LocalTime.RTC_Yday = (short)0;
	LocalTime.RTC_Mon = (short) date_rtc.Month;
	LocalTime.RTC_Year = (short)date_rtc.Year+2000;

	return LocalTime;
}



void TesteBateria(void)
{

	RTCTime Time;
	//if (RTCGetTime().RTC_Year <9)
	if (RegistroCabecalho2K.id != REG_BATT_MEM_INIT)
	{

		Time.RTC_Sec=0;
		Time.RTC_Min=0;
		Time.RTC_Hour=0;
		Time.RTC_Mday=1;
		Time.RTC_Wday=4;
		Time.RTC_Yday=1;
		Time.RTC_Mon=1;
		Time.RTC_Year=2021;

		RTCSetTime( Time );
		RegistroCabecalho2K.id=~RegistroCabecalho2K.id;
		InitBatteryRam();
		//GravaNaBatteryRAM(REG_BATT_MEM_ALERTA_BAT_MORTA);
		BateriaMorta=SIM;
	}

}


static unsigned short days[4][12] =
{
    {   0,  31,  60,  91, 121, 152, 182, 213, 244, 274, 305, 335},
    { 366, 397, 425, 456, 486, 517, 547, 578, 609, 639, 670, 700},
    { 731, 762, 790, 821, 851, 882, 912, 943, 974,1004,1035,1065},
    {1096,1127,1155,1186,1216,1247,1277,1308,1339,1369,1400,1430},
};

/* Converte data (dia, mes, ano, hora, minuto e segundo) em timestamp (formato Unix) */
unsigned long long DateToTimestamp(RTCTime time,int i)
{

/*
	short RTC_Year;     Year value - [0,4095]
	short RTC_Mon;      Month value - [1,12]
	short RTC_Yday;     Day of year value - [1,365]
	short RTC_Wday;     Day of week value - [0,6]
	short RTC_Mday;     Day of the month value - [1,31]
	short RTC_Hour;     Hour value - [0,23]
	short RTC_Min;      Minute value - [0,59]
	short RTC_Sec;      Second value - [0,59]
*/

	unsigned short second = time.RTC_Sec;			// 0-59
	unsigned short minute = time.RTC_Min;			// 0-59
	unsigned short hour   = time.RTC_Hour;			// 0-23
	unsigned short day    = time.RTC_Mday-1;		// 0-30
	unsigned short month  = time.RTC_Mon-1;			// 0-11
	unsigned short year   = time.RTC_Year-1970;		// 0-99



	if (i==0) // normal
	{
	    second = time.RTC_Sec;  			// 0-59
	}
	else  //arredonda os segundo para zero, e idealmente deveria se certificar que o minuto seja multiplo de 15 ... quais s�o as implica��es disso?	 deixar para depois
	{
		 second = 0;
		 /*if (minute==1)  {minute=0; hour=hour-1; .... e se ....}
		 if (minute==16) minute=15;
		 if (minute==31) minute=30;
		 if (minute==46) minute=45;*/
	}

	return (((year/4*(365*4+1)+days[year%4][month]+day)*24+hour)*60+minute)*60+second;
}

/////////////////////////////////////////////////////////
char GETtipoDeHorario()
{


	DWORD agora;
	DWORD foraponta=0;
	DWORD ponta=0;
	DWORD reservado=0;
	char tipo=HORARIO_NULO; //default
	char i;
	union union3x {short s; char c[2];};
	union union3x u3;
	char hoje_e_feriado=NAO;
	short Minimo1index;
	short Minimo2index;

	RTCTime tempRTC;
	tempRTC= RTCGetTime();
	//#define RTC_HOUR tempRTC.RTC_Hour
	//#define RTC_SEC tempRTC.RTC_Sec
	 #define RTC_MONTH tempRTC.RTC_Mon
	 #define RTC_MIN tempRTC.RTC_Min
	 #define RTC_DOW tempRTC.RTC_Wday
	 #define RTC_DOM tempRTC.RTC_Mday


	//transfoma tudo em segundos
	agora=(DWORD)tempRTC.RTC_Hour*3600+(DWORD)tempRTC.RTC_Min*60+(DWORD)tempRTC.RTC_Sec;

	///INICIOS 1
	if (hora_ponta_inicio1!=-1)
	{
		ponta=hora_ponta_inicio1*3600+min_ponta_inicio1*60;
	} else {ponta=0xFFFFFFFF;
	}

	if (hora_fora_ponta_inicio1!=-1)
	{
		foraponta=hora_fora_ponta_inicio1*3600+min_fora_ponta_inicio1*60;
	} else {foraponta=0xFFFFFFFF;
	}

	if (hora_reserv_inicio1!=-1)
	{
		reservado=hora_reserv_inicio1*3600+min_reserv_inicio1*60;
	} else {reservado=0xFFFFFFFF;
	}

	tabelinha[0].tempo=ponta;
	tabelinha[1].tempo=foraponta;
	tabelinha[2].tempo=reservado;
	tabelinha[0].tipo=HORARIO_PONTA;
	tabelinha[1].tipo=HORARIO_FORA_PONTA;
	tabelinha[2].tipo=HORARIO_RESERVADO;

	///INICIOS 2
	if (hora_ponta_inicio2!=-1)
	{
		ponta=hora_ponta_inicio2*3600+min_ponta_inicio2*60;
	} else {ponta=0xFFFFFFFF;
	}

	if (hora_fora_ponta_inicio2!=-1)
	{
		foraponta=hora_fora_ponta_inicio2*3600+min_fora_ponta_inicio2*60;
	} else {foraponta=0xFFFFFFFF;
	}

	if (hora_reserv_inicio2!=-1)
	{
		reservado=hora_reserv_inicio2*3600+min_reserv_inicio2*60;
	} else {reservado=0xFFFFFFFF;
	}

	tabelinha[3].tempo=ponta;
	tabelinha[4].tempo=foraponta;
	tabelinha[5].tempo=reservado;
	tabelinha[3].tipo=HORARIO_PONTA;
	tabelinha[4].tipo=HORARIO_FORA_PONTA;
	tabelinha[5].tipo=HORARIO_RESERVADO;

	///INICIOS 3
	if (hora_ponta_inicio3!=-1)
	{
		ponta=hora_ponta_inicio3*3600+min_ponta_inicio3*60;
	} else {ponta=0xFFFFFFFF;}

	if (hora_fora_ponta_inicio3!=-1)
	{
		foraponta=hora_fora_ponta_inicio3*3600+min_fora_ponta_inicio3*60;
	} else {foraponta=0xFFFFFFFF;}

	if (hora_reserv_inicio3!=-1)
	{
		reservado=hora_reserv_inicio3*3600+min_reserv_inicio3*60;
	} else {reservado=0xFFFFFFFF;}

	tabelinha[6].tempo=ponta;
	tabelinha[7].tempo=foraponta;
	tabelinha[8].tempo=reservado;
	tabelinha[6].tipo=HORARIO_PONTA;
	tabelinha[7].tipo=HORARIO_FORA_PONTA;
	tabelinha[8].tipo=HORARIO_RESERVADO;

	///INICIOS 4
	if (hora_ponta_inicio4!=-1)
	{
		ponta=hora_ponta_inicio4*3600+min_ponta_inicio4*60;
	} else {ponta=0xFFFFFFFF;}

	if (hora_fora_ponta_inicio4!=-1)
	{
		foraponta=hora_fora_ponta_inicio4*3600+min_fora_ponta_inicio4*60;
	} else {foraponta=0xFFFFFFFF;}

	if (hora_reserv_inicio4!=-1)
	{
		reservado=hora_reserv_inicio4*3600+min_reserv_inicio4*60;
	} else {reservado=0xFFFFFFFF;}

	tabelinha[9].tempo =ponta;
	tabelinha[10].tempo=foraponta;
	tabelinha[11].tempo=reservado;
	tabelinha[9].tipo =HORARIO_PONTA;
	tabelinha[10].tipo=HORARIO_FORA_PONTA;
	tabelinha[11].tipo=HORARIO_RESERVADO;

	tabelinha[12].tempo =24*3600; //24hs...	  ???
	tabelinha[12].tipo=HORARIO_NULO;

	//Minimo1index=tabelinha[Minimo1index].tempo

	Minimo1index=BuscaNovoMinimo(-1);	 //busca o m�nimo, imediato superiro a -1
	Minimo2index=BuscaNovoMinimo(tabelinha[Minimo1index].tempo);

	if ((agora>=tabelinha[Minimo1index].tempo)&&(agora<tabelinha[Minimo2index].tempo)){
		tipo=tabelinha[Minimo1index].tipo;
	}
	else
	{
		for (i=0;i<10;i++)
		{
			Minimo1index=Minimo2index;
			if (Minimo1index==12) {break;}//situa��o que hipot�ticamente, nunca acontece
			Minimo2index=BuscaNovoMinimo(tabelinha[Minimo1index].tempo);

			if ((agora>=tabelinha[Minimo1index].tempo)&&(agora<tabelinha[Minimo2index].tempo)){
				tipo=tabelinha[Minimo1index].tipo;
				break;
			}
		}
	}



	for(i=0;i<20;i++)

	{
		u3.s=feriados[i];
		if ((u3.c[MSB]==RTC_DOM)&&(u3.c[LSB]==RTC_MONTH))
		{
			hoje_e_feriado=SIM;
			break;
		}
	}

	if (hoje_e_feriado)       {tipo=HORARIO_FORA_PONTA;}		  //feriado
	if (( RTC_DOW==0)||( RTC_DOW==6)) {tipo=HORARIO_FORA_PONTA;}	  //domingo ou sab.



	return(tipo);
}




void Releportempo2(void)
{
#if EQUIP!=CM_EQUIP
#ifndef MODELO_D
#ifndef MODELO_B
#ifndef MODELO_R
#ifndef MODELO_E
#ifndef TR_INVERSOR
	unsigned char hora;
	unsigned char minuto;

	RTCTime tempRTC;
	tempRTC= RTCGetTime();
	#define RTC_HOUR tempRTC.RTC_Hour
	#define RTC_MIN tempRTC.RTC_Min


	hora=(unsigned char)RTC_HOUR;
	minuto=(unsigned char)RTC_MIN;


	//primeiro vamos verificar se estamos na faixa programada do rele 1
	if (inicio_hora_atua_rele1_ini==0xFF)
	{
		//////////////////	clrLED(REL_1);
		goto rel2;
	}

	//'hora' deve estar entre inicio_hora_atua_rele1_ini, e inicio_hora_atua_rele1_fim
	//   inicio_hora_atua_rele1_ini < 'hora' < inicio_hora_atua_rele1_fim
	//   inicio_minuto_atua_rele1_ini < 'minuto' < inicio_minuto_atua_rele1_fim
rel1:
	if ((hora>=inicio_hora_atua_rele1_ini) && (hora<=inicio_hora_atua_rele1_fim))
	{
		if ((minuto>=inicio_minuto_atua_rele1_ini) && (minuto<=inicio_minuto_atua_rele1_fim))
		{
			//setLED(REL_1);
			OperaRele(1,ON);
		}
		else
		{ 	//clrLED(REL_1);
			OperaRele(1,OFF);
		}
	}
	else
	{
		//	clrLED(REL_1);
		OperaRele(1,OFF);
	}

rel2:
	if (inicio_hora_atua_rele2_ini==0xFF)
	{
		///////////////   clrLED(REL_2);
		goto rel3;
	}



	if ((hora>=inicio_hora_atua_rele2_ini) && (hora<=inicio_hora_atua_rele2_fim))
	{
		if ((minuto>=inicio_minuto_atua_rele2_ini) && (minuto<=inicio_minuto_atua_rele2_fim))
		{
			//setLED(REL_2);
			OperaRele(2,ON);
		}
		else
		{ 	//clrLED(REL_2);
			OperaRele(2,OFF);
		}
	}
	else
	{
		//clrLED(REL_2);
		OperaRele(2,OFF);
	}


rel3:
	if (inicio_hora_atua_rele3_ini==0xFF)
	{
		////////////////////    clrLED(REL_3);
		//goto sairnow;
		return;
	}

	if ((hora>=inicio_hora_atua_rele3_ini) && (hora<=inicio_hora_atua_rele3_fim))
	{
		if ((minuto>=inicio_minuto_atua_rele3_ini) && (minuto<=inicio_minuto_atua_rele3_fim))
		{
			//		setLED(REL_3);
			OperaRele(3,ON);
		} else
		{
			//clrLED(REL_3);
			OperaRele(3,OFF);
		}
	}
	else
	{
		//clrLED(REL_3);
		OperaRele(3,OFF);
	}
//sairnow:
#endif
#endif
#endif
#endif
#endif
#endif
}

#if EQUIP!=CM_EQUIP
#ifndef TR_INVERSOR
void Releportempo(void)
{
	unsigned char hora;
	unsigned char minuto;
	int i;
	union union3x {short s; char c[2];};
	union union3x u3;
	char hoje_e_feriado=NAO;
	char ontem_foi_feriado=NAO;



RTCTime tempRTC = RTCGetTime();
#define RTC_HOUR tempRTC.RTC_Hour
#define RTC_MONTH tempRTC.RTC_Mon
#define RTC_MIN tempRTC.RTC_Min
#define RTC_DOW tempRTC.RTC_Wday
#define RTC_DOM tempRTC.RTC_Mday




	hora=(unsigned char)RTC_HOUR;
	minuto=(unsigned char)RTC_MIN;

	for(i=0;i<20;i++)
	{
		u3.s=feriados[i];
		if ((u3.c[MSB]==RTC_DOM)&&(u3.c[LSB]==RTC_MONTH))
		{
			hoje_e_feriado=SIM;
			break;
		}
	}


	if (hoje_e_feriado)
	{
		if(hora_feriados1!=0xFF)
		{
			if((hora>hora_feriados1)&&(hora<hora_feriados2))
			{
				setLED(REL_1);
#if EQUIP==TR_EQUIP
				SETpinoEmPorta(0,0x00010000);
#endif
			}
			if((hora==hora_feriados1)&&(minuto>=min_feriados1))
			{
				setLED(REL_1);
#if EQUIP==TR_EQUIP
				SETpinoEmPorta(0,0x00010000);
#endif
			}
		}
		if(hora_feriados2!=0xFF)
		{
			if((hora>hora_feriados2)&&(hora<hora_feriados3))
			{
				clrLED(REL_1);
#if EQUIP==TR_EQUIP

				CLRpinoEmPorta(0,0x00010000);

#endif
			}
			if((hora==hora_feriados2)&&(minuto>=min_feriados2))
			{
				clrLED(REL_1);
#if EQUIP==TR_EQUIP
				CLRpinoEmPorta(0,0x00010000);
#endif
			}
		}
		if(hora_feriados3!=0xFF)
		{
			if((hora>hora_feriados3)&&(hora<hora_feriados4))
			{
				setLED(REL_1);
#if EQUIP==TR_EQUIP

				SETpinoEmPorta(0,0x00010000);
#endif
			}
			if((hora==hora_feriados3)&&(minuto>=min_feriados3))
			{
				setLED(REL_1);
#if EQUIP==TR_EQUIP
				SETpinoEmPorta(0,0x00010000);
#endif
			}
		}
		if(hora_feriados4!=0xFF)
		{
			if((hora>hora_feriados4))
			{
				clrLED(REL_1);
#if EQUIP==TR_EQUIP
				CLRpinoEmPorta(0,0x00010000);
#endif
			}
			if((hora==hora_feriados4)&&(minuto>=min_feriados4))
			{
				clrLED(REL_1);
#if EQUIP==TR_EQUIP
				CLRpinoEmPorta(0,0x00010000);
#endif
			}
		}
	}

	else
	{
		if(RTC_DOW==1)
		{
			if(hora_segunda1!=0xFF)
			{
				if((hora>hora_segunda1)&&(hora<hora_segunda2))
				{
					setLED(REL_1);
#if EQUIP==TR_EQUIP
					SETpinoEmPorta(0,0x00010000);
#endif
				}
				if((hora==hora_segunda1)&&(minuto>=min_segunda1))
				{
					setLED(REL_1);
#if EQUIP==TR_EQUIP
					SETpinoEmPorta(0,0x00010000);
#endif
				}
			}
			if(hora_segunda2!=0xFF)
			{
				if((hora>hora_segunda2)&&(hora<hora_segunda3))
				{
					clrLED(REL_1);
#if EQUIP==TR_EQUIP
					CLRpinoEmPorta(0,0x00010000);
#endif
				}
				if((hora==hora_segunda2)&&(minuto>=min_segunda2))
				{
					clrLED(REL_1);
#if EQUIP==TR_EQUIP
					CLRpinoEmPorta(0,0x00010000);
#endif
				}
			}
			if(hora_segunda3!=0xFF)
			{
				if((hora>hora_segunda3)&&(hora<hora_segunda4))
				{
					setLED(REL_1);
#if EQUIP==TR_EQUIP
					SETpinoEmPorta(0,0x00010000);
#endif
				}
				if((hora==hora_segunda3)&&(minuto>=min_segunda3))
				{
					setLED(REL_1);
#if EQUIP==TR_EQUIP
					SETpinoEmPorta(0,0x00010000);
#endif
				}
			}
			if(hora_segunda4!=0xFF)
			{
				if((hora>hora_segunda4))
				{
					clrLED(REL_1);
#if EQUIP==TR_EQUIP
					CLRpinoEmPorta(0,0x00010000);
#endif
				}
				if((hora==hora_segunda4)&&(minuto>=min_segunda4))
				{
					clrLED(REL_1);
#if EQUIP==TR_EQUIP
					CLRpinoEmPorta(0,0x00010000);
#endif
				}
			}
		}
		if(RTC_DOW==2)
		{
			if(hora_terca1!=0xFF)
			{
				if((hora>hora_terca1)&&(hora<hora_terca2))
				{
					setLED(REL_1);
#if EQUIP==TR_EQUIP
					SETpinoEmPorta(0,0x00010000);
#endif
				}
				if((hora==hora_terca1)&&(minuto>=min_terca1))
				{
					setLED(REL_1);
#if EQUIP==TR_EQUIP
					SETpinoEmPorta(0,0x00010000);
#endif
				}
			}
			if(hora_terca2!=0xFF)
			{
				if((hora>hora_terca2)&&(hora<hora_terca3))
				{
					clrLED(REL_1);
#if EQUIP==TR_EQUIP
					CLRpinoEmPorta(0,0x00010000);
#endif
				}
				if((hora==hora_terca2)&&(minuto>=min_terca2))
				{
					clrLED(REL_1);
#if EQUIP==TR_EQUIP
					CLRpinoEmPorta(0,0x00010000);
#endif
				}
			}
			if(hora_terca3!=0xFF)
			{
				if((hora>hora_terca3)&&(hora<hora_terca4))
				{
					setLED(REL_1);
#if EQUIP==TR_EQUIP
					SETpinoEmPorta(0,0x00010000);
#endif
				}
				if((hora==hora_terca3)&&(minuto>=min_terca3))
				{
					setLED(REL_1);
#if EQUIP==TR_EQUIP
					SETpinoEmPorta(0,0x00010000);
#endif
				}
			}
			if(hora_terca4!=0xFF)
			{
				if((hora>hora_terca4))
				{
					clrLED(REL_1);
#if EQUIP==TR_EQUIP
					CLRpinoEmPorta(0,0x00010000);
#endif
				}
				if((hora==hora_terca4)&&(minuto>=min_terca4))
				{
					clrLED(REL_1);
#if EQUIP==TR_EQUIP
					CLRpinoEmPorta(0,0x00010000);;
#endif
				}
			}
		}
		if(RTC_DOW==3)
		{
			if(hora_quarta1!=0xFF)
			{
				if((hora>hora_quarta1)&&(hora<hora_quarta2))
				{
					setLED(REL_1);
#if EQUIP==TR_EQUIP
					SETpinoEmPorta(0,0x00010000);
#endif
				}
				if((hora==hora_quarta1)&&(minuto>=min_quarta1))
				{
					setLED(REL_1);
#if EQUIP==TR_EQUIP
					SETpinoEmPorta(0,0x00010000);
#endif
				}
			}
			if(hora_quarta2!=0xFF)
			{
				if((hora>hora_quarta2)&&(hora<hora_quarta3))
				{
					clrLED(REL_1);
#if EQUIP==TR_EQUIP
					CLRpinoEmPorta(0,0x00010000);
#endif
				}
				if((hora==hora_quarta2)&&(minuto>=min_quarta2))
				{
					clrLED(REL_1);
#if EQUIP==TR_EQUIP
					CLRpinoEmPorta(0,0x00010000);
#endif
				}
			}
			if(hora_quarta3!=0xFF)
			{
				if((hora>hora_quarta3)&&(hora<hora_quarta4))
				{
					setLED(REL_1);
#if EQUIP==TR_EQUIP
					SETpinoEmPorta(0,0x00010000);
#endif
				}
				if((hora==hora_quarta3)&&(minuto>=min_quarta3))
				{
					setLED(REL_1);
#if EQUIP==TR_EQUIP
					SETpinoEmPorta(0,0x00010000);
#endif
				}
			}
			if(hora_quarta4!=0xFF)
			{
				if((hora>hora_quarta4))
				{
					clrLED(REL_1);
#if EQUIP==TR_EQUIP
					CLRpinoEmPorta(0,0x00010000);
#endif
				}
				if((hora==hora_quarta4)&&(minuto>=min_quarta4))
				{
					clrLED(REL_1);
#if EQUIP==TR_EQUIP
					CLRpinoEmPorta(0,0x00010000);
#endif
				}
			}
		}
		if(RTC_DOW==4)
		{
			if(hora_quinta1!=0xFF)
			{
				if((hora>hora_quinta1)&&(hora<hora_quinta2))
				{
					setLED(REL_1);
#if EQUIP==TR_EQUIP
					SETpinoEmPorta(0,0x00010000);
#endif
				}
				if((hora==hora_quinta1)&&(minuto>=min_quinta1))
				{
					setLED(REL_1);
#if EQUIP==TR_EQUIP
					SETpinoEmPorta(0,0x00010000);
#endif
				}
			}
			if(hora_quinta2!=0xFF)
			{
				if((hora>hora_quinta2)&&(hora<hora_quinta3))
				{
					clrLED(REL_1);
#if EQUIP==TR_EQUIP
					CLRpinoEmPorta(0,0x00010000);
#endif
				}
				if((hora==hora_quinta2)&&(minuto>=min_quinta2))
				{
					clrLED(REL_1);
#if EQUIP==TR_EQUIP
					CLRpinoEmPorta(0,0x00010000);
#endif
				}
			}
			if(hora_quinta3!=0xFF)
			{
				if((hora>hora_quinta3)&&(hora<hora_quinta4))
				{
					setLED(REL_1);
#if EQUIP==TR_EQUIP
					SETpinoEmPorta(0,0x00010000);
#endif
				}
				if((hora==hora_quinta3)&&(minuto>=min_quinta3))
				{
					setLED(REL_1);
#if EQUIP==TR_EQUIP
					SETpinoEmPorta(0,0x00010000);
#endif
				}
			}
			if(hora_quinta4!=0xFF)
			{
				if((hora>hora_quinta4))
				{
					clrLED(REL_1);
#if EQUIP==TR_EQUIP
					CLRpinoEmPorta(0,0x00010000);
#endif
				}
				if((hora==hora_quinta4)&&(minuto>=min_quinta4))
				{
					clrLED(REL_1);
#if EQUIP==TR_EQUIP
					CLRpinoEmPorta(0,0x00010000);
#endif
				}
			}
		}
		if(RTC_DOW==5)
		{
			if(hora_sexta1!=0xFF)
			{
				if((hora>hora_sexta1)&&(hora<hora_sexta2))
				{
					setLED(REL_1);
#if EQUIP==TR_EQUIP
					SETpinoEmPorta(0,0x00010000);
#endif
				}
				if((hora==hora_sexta1)&&(minuto>=min_sexta1))
				{
					setLED(REL_1);
#if EQUIP==TR_EQUIP
					SETpinoEmPorta(0,0x00010000);
#endif
				}
			}
			if(hora_sexta2!=0xFF)
			{
				if((hora>hora_sexta2)&&(hora<hora_sexta3))
				{
					clrLED(REL_1);
#if EQUIP==TR_EQUIP
					CLRpinoEmPorta(0,0x00010000);
#endif
				}
				if((hora==hora_sexta2)&&(minuto>=min_sexta2))
				{
					clrLED(REL_1);
#if EQUIP==TR_EQUIP
					CLRpinoEmPorta(0,0x00010000);
#endif
				}
			}
			if(hora_sexta3!=0xFF)
			{
				if((hora>hora_sexta3)&&(hora<hora_sexta4))
				{
					setLED(REL_1);
#if EQUIP==TR_EQUIP
					SETpinoEmPorta(0,0x00010000);
#endif
				}
				if((hora==hora_sexta3)&&(minuto>=min_sexta3))
				{
					setLED(REL_1);
#if EQUIP==TR_EQUIP
					SETpinoEmPorta(0,0x00010000);
#endif
				}
			}
			if(hora_sexta4!=0xFF)
			{
				if((hora>hora_sexta4))
				{
					clrLED(REL_1);
#if EQUIP==TR_EQUIP
					CLRpinoEmPorta(0,0x00010000);
#endif
				}
				if((hora==hora_sexta4)&&(minuto>=min_sexta4))
				{
					clrLED(REL_1);
#if EQUIP==TR_EQUIP
					CLRpinoEmPorta(0,0x00010000);
#endif
				}
			}
		}
		if(RTC_DOW==6)
		{
			if(hora_sabado1!=0xFF)
			{
				if((hora>hora_sabado1)&&(hora<hora_sabado2))
				{
					setLED(REL_1);
#if EQUIP==TR_EQUIP
					SETpinoEmPorta(0,0x00010000);
#endif
				}
				if((hora==hora_sabado1)&&(minuto>=min_sabado1))
				{
					setLED(REL_1);
#if EQUIP==TR_EQUIP
					SETpinoEmPorta(0,0x00010000);
#endif
				}
			}
			if(hora_sabado2!=0xFF)
			{
				if((hora>hora_sabado2)&&(hora<hora_sabado3))
				{
					clrLED(REL_1);
#if EQUIP==TR_EQUIP
					CLRpinoEmPorta(0,0x00010000);
#endif
				}
				if((hora==hora_sabado2)&&(minuto>=min_sabado2))
				{
					clrLED(REL_1);
#if EQUIP==TR_EQUIP
					CLRpinoEmPorta(0,0x00010000);
#endif
				}
			}
			if(hora_sabado3!=0xFF)
			{
				if((hora>hora_sabado3)&&(hora<hora_sabado4))
				{
					setLED(REL_1);
#if EQUIP==TR_EQUIP
					SETpinoEmPorta(0,0x00010000);
#endif
				}
				if((hora==hora_sabado3)&&(minuto>=min_sabado3))
				{
					setLED(REL_1);
#if EQUIP==TR_EQUIP
					SETpinoEmPorta(0,0x00010000);
#endif
				}
			}
			if(hora_sabado4!=0xFF)
			{
				if((hora>hora_sabado4))
				{
					clrLED(REL_1);
#if EQUIP==TR_EQUIP
					CLRpinoEmPorta(0,0x00010000);
#endif
				}
				if((hora==hora_sabado4)&&(minuto>=min_sabado4))
				{
					clrLED(REL_1);
#if EQUIP==TR_EQUIP
					CLRpinoEmPorta(0,0x00010000);
#endif
				}
			}
		}
		if(RTC_DOW==0)
		{
			if(hora_domingo1!=0xFF)
			{
				if((hora>hora_domingo1)&&(hora<hora_domingo2))
				{
					setLED(REL_1);
#if EQUIP==TR_EQUIP
					SETpinoEmPorta(0,0x00010000);
#endif
				}
				if((hora==hora_domingo1)&&(minuto>=min_domingo1))
				{
					setLED(REL_1);
#if EQUIP==TR_EQUIP
					SETpinoEmPorta(0,0x00010000);
#endif
				}
			}
			if(hora_domingo2!=0xFF)
			{
				if((hora>hora_domingo2)&&(hora<hora_domingo3))
				{
					clrLED(REL_1);
#if EQUIP==TR_EQUIP
					CLRpinoEmPorta(0,0x00010000);
#endif
				}
				if((hora==hora_domingo2)&&(minuto>=min_domingo2))
				{
					clrLED(REL_1);
#if EQUIP==TR_EQUIP
					CLRpinoEmPorta(0,0x00010000);
#endif
				}
			}
			if(hora_domingo3!=0xFF)
			{
				if((hora>hora_domingo3)&&(hora<hora_domingo4))
				{
					setLED(REL_1);
#if EQUIP==TR_EQUIP
					SETpinoEmPorta(0,0x00010000);
#endif
				}
				if((hora==hora_domingo3)&&(minuto>=min_domingo3))
				{
					setLED(REL_1);
#if EQUIP==TR_EQUIP
					SETpinoEmPorta(0,0x00010000);
#endif
				}
			}
			if(hora_domingo4!=0xFF)
			{
				if((hora>hora_domingo4))
				{
					clrLED(REL_1);
#if EQUIP==TR_EQUIP
					CLRpinoEmPorta(0,0x00010000);
#endif
				}
				if((hora==hora_domingo4)&&(minuto>=min_domingo4))
				{
					clrLED(REL_1);
#if EQUIP==TR_EQUIP
					CLRpinoEmPorta(0,0x00010000);
#endif
				}
			}
		}
	}
}
#endif
#endif


/*****************************************************************************
 **                            End Of File
 ******************************************************************************/

/*
   A rotina: BuscaNovoMinimo
   Retorna o indice da tabela de hor�rios,
   que aponta para o valor minimo
   imediato superior ao m�nimo atual informado
 */

short BuscaNovoMinimo(long int MinimoAtual)
{
	short n,i,ii,out;
	long int Mintemp;

	i=12;	//�ltimo elemento da tabela, default
	for (n=0;n<12;n++)
	{
		if (tabelinha[n].tempo!=-1)
		{
			if (tabelinha[n].tempo>MinimoAtual)
			{
				Mintemp=tabelinha[n].tempo; //encontrou algum elemento maior que o minimo atual
				i=n;
				break;
			}
		}
	}

	for (ii=i;ii<12;ii++)
	{
		for (n=i;n<12;n++)
		{
			if (tabelinha[n].tempo!=-1)
			{
				if(
						(long int)((long int)tabelinha[n].tempo>(long int)MinimoAtual)
						&&((long int)tabelinha[n].tempo<(long int)Mintemp)
				  )
				{
					Mintemp=tabelinha[n].tempo;
					i=n;
					break;
				}
			}
		}
	}


	out=i;

	return(out);
}

short RTCtoDataHora(RTCTime Tempo)
{
	return(Tempo.RTC_Hour|(Tempo.RTC_Mday<<8));
}

void RTCtoMesDiaHoraMin(short *MesDia, short *HoraMin)
{



	RTCTime tempRTC=RTCGetTime();

	*MesDia=(short)((tempRTC.RTC_Mon<<8)|(tempRTC.RTC_Mday));
	*HoraMin=(short)((tempRTC.RTC_Hour<<8)|(tempRTC.RTC_Min));
}
