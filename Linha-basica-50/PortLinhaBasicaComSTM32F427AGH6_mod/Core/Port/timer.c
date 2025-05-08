/*****************************************************************************
 *   timer.c:  Timer C file for NXP LPC230x Family Microprocessors
 *
 *   Copyright(C) 2006, NXP Semiconductor
 *   All rights reserved.
 *
 *   History
 *   2006.09.01  ver 1.00    Prelimnary version, first Release
 *
 ******************************************************************************/
#define EXT extern
#include "global.h"
 

extern short tensaoIa;
extern short tensaoIb;
extern short tensaoIc;
extern short tensaoVa;
extern short tensaoVb;
extern short tensaoVc;
volatile DWORD timer_counter = 0;
void T0isr (void)	__irq;
void timer_admite_nested_interrupt_srv(void);
extern void timer_admite_nested_interrupt_irq(void);


/******************************************************************************
 ** Function name:		enable_timer
 **
 ** Descriptions:		Enable timer
 **
 ** parameters:			timer number: 0 or 1
 ** Returned value:		None
 **
 ******************************************************************************/
void enable_timer( BYTE timer_num )
{
    #ifdef LEGADO
	if ( timer_num == 0 )
	{
		T0TCR = 1;
		T0CTCR=0;
		T0CR0=0x51;
		T0CCR=0x6;
		DESABILITA_CALC_FREQ;
	}
	else
	{
		T1TCR = 1;
	}
	return;
		#endif
}

/******************************************************************************
 ** Function name:		disable_timer
 **
 ** Descriptions:		Disable timer
 **
 ** parameters:			timer number: 0 or 1
 ** Returned value:		None
 **
 ******************************************************************************/
void disable_timer( BYTE timer_num )
{
    #ifdef LEGADO
	if ( timer_num == 0 )
	{
		T0TCR = 0;
	}
	else
	{
		T1TCR = 0;
	}
	return;
	#endif
}

/******************************************************************************
 ** Function name:		reset_timer
 **
 ** Descriptions:		Reset timer
 **
 ** parameters:			timer number: 0 or 1
 ** Returned value:		None
 **
 ******************************************************************************/
void reset_timer( BYTE timer_num )
{
    #ifdef LEGADO
	DWORD regVal;

	if ( timer_num == 0 )
	{
		regVal = T0TCR;
		regVal |= 0x02;
		T0TCR = regVal;
	}
	else
	{
		regVal = T1TCR;
		regVal |= 0x02;
		T1TCR = regVal;
	}
	return;
	#endif
}

void disable_interrupt_timer1()
{
#ifdef LEGADO
	T1MCR = 4;		/* Stop on MR0 */
#endif
}

void enable_interrupt_timer1()
{
#ifdef LEGADO
	T1MCR = 3;		/* Interrupt and Reset on MR0 */
	T1TCR = 1;
#endif
}
/******************************************************************************
 ** Function name:		init_timer
 **
 ** Descriptions:		Initialize timer, set timer interval, reset timer,
 **						install timer interrupt handler
 **
 ** parameters:			None
 ** Returned value:		true or false, if the interrupt handler can't be
 **						installed, return false.
 **
 ******************************************************************************/
DWORD init_timer ( void )
{
#ifdef LEGADO
	T0PR 		= 0x0;										//Prescaler = 1
	T0TCR 		= 0x00000002;					//Reset counter and prescaler
	T0MCR 		= 0x00000003;					//On match reset the counter and generate an interrupt
	T0MR0		= 4687;//4687;//180000/2;					  //Set the cycle time
	//T0TCR 		= 0x00000001;					//enable timer
	VICVectAddr4 = (unsigned)T0isr;	//Set the timer ISR vector address
	VICVectCntl4 = 0x00000024;//0x00000024;			//Set channel
	VICIntEnable |= 0x00000010;			//Enable the interrupt
	T1PR 		= 0x0;										//Prescaler = 1
	T1TCR 		= 0x00000002;					//Reset counter and prescaler
	T1MCR 		= 0x00000003;					//On match reset the counter and generate an interrupt
	T1MR0		  = 15000;//30000;//30000;					  //Set the cycle time
	//T1TCR 		= 0x00000001;					//enable timer
	VICVectAddr5 = (unsigned)timer_admite_nested_interrupt_irq;
	VICVectCntl5 = 0x00000025;//0x00000025;			//Set channel
	VICIntEnable |= 0x00000020;			//Enable the interrupt
	return (TRUE);
#endif
}


//#define DELAY_CP 		1 	 // 1 = 260us	   
#define DEBOUCING_CP 	19	 // 19 = 5ms
#if ((EQUIP_LINHA50== CP_EQUIP)||( EQUIP_LINHA50== CD_EQUIP))
void conta_pulsos()
{
	static char state_cp_01_ON = 0;
	static char state_cp_01_OFF = 0;

	static char state_cp_02_ON = 0;
	static char state_cp_02_OFF = 0;

	static char state_cp_03_ON = 0;
	static char state_cp_03_OFF = 0;

	static char state_cp_04_ON = 0;
	static char state_cp_04_OFF = 0;

	static char state_cp_05_ON = 0;
	static char state_cp_05_OFF = 0;

	static char state_cp_06_ON = 0;
	static char state_cp_06_OFF = 0;

	static char wait_cp_01_ON = 0;
	static char wait_cp_01_OFF = 0;

	static char wait_cp_02_ON = 0;
	static char wait_cp_02_OFF = 0;

	static char wait_cp_03_ON = 0;
	static char wait_cp_03_OFF = 0;

	static char wait_cp_04_ON = 0;
	static char wait_cp_04_OFF = 0;

	static char wait_cp_05_ON = 0;
	static char wait_cp_05_OFF = 0;

	static char wait_cp_06_ON = 0;
	static char wait_cp_06_OFF = 0;
		
	static char statusChange_cp_1 = 0;		
	static char statusChange_cp_2 = 0;		
	static char statusChange_cp_3 = 0;
	static char statusChange_cp_4 = 0;
	static char statusChange_cp_5 = 0;
	static char statusChange_cp_6 = 0;

	static float ChangedPort = 0;
/*
	if(toggle_led == 0)
	{
		toggle_led = 1;
		FIO0SET = LED_ONOFF_PIN;
	}
	else
	{
		toggle_led = 0;
		FIO0CLR = LED_ONOFF_PIN;	
	}
*/

	timer_pulso = 0;
	
    statusChange_cp_1 = 0;
	statusChange_cp_2 = 0;
	statusChange_cp_3 = 0;
	statusChange_cp_4 = 0;
	statusChange_cp_5 = 0;
	statusChange_cp_6 = 0;


// Segue abaixo contadores para placa com 6 entradas	
	// ENTRADA 1
	if ((LerPinosEmPorta(0,0x00800000)) != 0x00000000)	   //if((FIO0PIN & 0x00800000) == 0x00000000)
	{	 
		if(wait_cp_01_OFF >= DEBOUCING_CP)
		{
			//FIO0CLR = LED_ONOFF_PIN;	
#if EQUIP_LINHA50== CD_EQUIP

			pulso_cp_1 = 0;		// 1.18

			if(state_cp_01_ON == 1)
			{
				//pulso_cp_1 = 0;
				statusChange_cp_1 = 1;
			}
#endif
			state_cp_01_OFF = 1;
			state_cp_01_ON = 0;	

			
					 
				
						
		}
		else
		{
			//FIO0SET = LED_ONOFF_PIN;
			wait_cp_01_OFF++;
		}
		
		wait_cp_01_ON = 0;		
	}
	else			
	{	
		//FIO0CLR = LED_ONOFF_PIN;			
		if(wait_cp_01_ON >= DEBOUCING_CP)
		{	
			#if EQUIP_LINHA50== CD_EQUIP
				pulso_cp_1 = 1; // 1.18
			#endif

			if(state_cp_01_OFF == 1)
			{
					#if EQUIP_LINHA50== CD_EQUIP
						//pulso_cp_1=1;
						statusChange_cp_1 = 1;	
					#else
						pulso_cp_1++;
					#endif
			}
			state_cp_01_ON = 1;
			state_cp_01_OFF = 0;
		}
		else
		{
			wait_cp_01_ON++;	
		}
		wait_cp_01_OFF = 0;
	}

	// ENTRADA 2
	if ((LerPinosEmPorta(0,0x01000000)) != 0x00000000)  //if((FIO0PIN & 0x01000000) == 0x00000000)
	{
		
		if(wait_cp_02_OFF >= DEBOUCING_CP)
		{
#if EQUIP_LINHA50== CD_EQUIP

			pulso_cp_2 = 0;

			if(state_cp_02_ON == 1)
			{
				//pulso_cp_2 = 0;
				statusChange_cp_2 = 1;
			}
#endif
			state_cp_02_OFF = 1;
			state_cp_02_ON = 0;	
			
			 
			
		}
		else
		{
			wait_cp_02_OFF++;
		}

		wait_cp_02_ON = 0;		
	}
	else			
	{				
		if(wait_cp_02_ON >= DEBOUCING_CP)
		{

			#if EQUIP_LINHA50== CD_EQUIP
				pulso_cp_2 = 1; // 1.18
			#endif

			if(state_cp_02_OFF == 1)
			{
				#if EQUIP_LINHA50== CD_EQUIP
					//pulso_cp_2=1;
					statusChange_cp_2 = 1;
				#else
					pulso_cp_2++;
				#endif
			}
			state_cp_02_ON = 1;
			state_cp_02_OFF = 0;
			
		}
		else
		{
			wait_cp_02_ON++;	
		}
		wait_cp_02_OFF = 0;
	}


#include "main.h"
	if (HAL_GPIO_ReadPin(ADC3P_GPIO_Port, ADC3P_Pin )!=0)
	{

	 	DisablePoweDownInterrupt();
	}


	// ENTRADA 3

	if ((LerPinosEmPorta(0, 0x02000000)) != 0x00000000) //if((FIO0PIN & 0x02000000) == 0x00000000)
	{
		
		if(wait_cp_03_OFF >= DEBOUCING_CP)
		{
#if EQUIP_LINHA50== CD_EQUIP

			pulso_cp_3 = 0;

			if(state_cp_03_ON == 1)
			{
				//pulso_cp_3 = 0;
				statusChange_cp_3 = 1;
			}
#endif
			state_cp_03_OFF = 1;
			state_cp_03_ON = 0;	


 

		}
		else
		{
			wait_cp_03_OFF++;
		}

		wait_cp_03_ON = 0;		
	}
	else			
	{


		if(wait_cp_03_ON >= DEBOUCING_CP)
		{

			#if EQUIP_LINHA50== CD_EQUIP
				pulso_cp_3 = 1; // 1.18
			#endif

			if(state_cp_03_OFF == 1)
			{
				#if EQUIP_LINHA50== CD_EQUIP
					//pulso_cp_3=1;
					statusChange_cp_3 = 1;
				#else
					pulso_cp_3++;
				#endif
			}
			state_cp_03_ON = 1;
			state_cp_03_OFF = 0;
		}
		else
		{
			wait_cp_03_ON++;	
		}
		wait_cp_03_OFF = 0;
	}

	// ENTRADA 4
	if ((LerPinosEmPorta(0, 0x04000000)) != 0x00000000)//if((FIO0PIN & 0x04000000) == 0x00000000)
	{
		
		if(wait_cp_04_OFF >= DEBOUCING_CP)
		{
#if EQUIP_LINHA50== CD_EQUIP

			pulso_cp_4 = 0;

			if(state_cp_04_ON == 1)
			{
				//pulso_cp_4 = 0;
				statusChange_cp_4 = 1;
			}
#endif
			state_cp_04_OFF = 1;
			state_cp_04_ON = 0;	

		}
		else
		{
			wait_cp_04_OFF++;
		}

		wait_cp_04_ON = 0;		
	}
	else			
	{				
		if(wait_cp_04_ON >= DEBOUCING_CP)
		{

			#if EQUIP_LINHA50== CD_EQUIP
				pulso_cp_4 = 1;		// 1.18
			#endif

			if(state_cp_04_OFF == 1)
			{
			#if EQUIP_LINHA50== CD_EQUIP
				//pulso_cp_4=1;
				statusChange_cp_4 = 1;
			#else
				pulso_cp_4++;
			#endif
			}
			state_cp_04_ON = 1;
			state_cp_04_OFF = 0;
		}
		else
		{
			wait_cp_04_ON++;	
		}
		wait_cp_04_OFF = 0;
	}

	// ENTRADA 5
	if ((LerPinosEmPorta(1,0x40000000)) != 0x00000000)  //if((FIO1PIN & 0x40000000) == 0x00000000)
	{
		
		if(wait_cp_05_OFF >= DEBOUCING_CP)
		{
#if EQUIP_LINHA50== CD_EQUIP

			pulso_cp_5 = 0;

			if(state_cp_05_ON == 1)
			{
				//pulso_cp_5 = 0;
				statusChange_cp_5 = 1;
			}
#endif
			state_cp_05_OFF = 1;
			state_cp_05_ON = 0;	
 

		}
		else
		{
			wait_cp_05_OFF++;
		}

		wait_cp_05_ON = 0;		
	}
	else			
	{				
		if(wait_cp_05_ON >= DEBOUCING_CP)
		{

			#if EQUIP_LINHA50== CD_EQUIP
				pulso_cp_5 = 1;		// 1.18
			#endif

			if(state_cp_05_OFF == 1)
			{
			#if EQUIP_LINHA50== CD_EQUIP
				//pulso_cp_5=1;
				statusChange_cp_5 = 1;
			#else
				pulso_cp_5++;
			#endif
			}
			state_cp_05_ON = 1;
			state_cp_05_OFF = 0;
		}
		else
		{
			wait_cp_05_ON++;	
		}
		wait_cp_05_OFF = 0;
	}

	// ENTRADA 6
	if ((LerPinosEmPorta(1,0x80000000)) != 0x00000000)  //if((FIO1PIN & 0x80000000) == 0x00000000)
	{
		
		if(wait_cp_06_OFF >= DEBOUCING_CP)
		{
#if EQUIP_LINHA50== CD_EQUIP

			pulso_cp_6 = 0;

			if(state_cp_06_ON == 1)
			{
				//pulso_cp_6 = 0;
				statusChange_cp_6 = 1;
			}
#endif
			state_cp_06_OFF = 1;
			state_cp_06_ON = 0;	

		}
		else
		{
			wait_cp_06_OFF++;
		}

		wait_cp_06_ON = 0;		
	}
	else			
	{				
		if(wait_cp_06_ON >= DEBOUCING_CP)
		{

			#if EQUIP_LINHA50== CD_EQUIP
				pulso_cp_6 = 1;		// 1.18
			#endif


			if(state_cp_06_OFF == 1)
			{
			#if EQUIP_LINHA50== CD_EQUIP
				//pulso_cp_6=1;
				statusChange_cp_6 = 1;
			#else
				pulso_cp_6++;
			#endif
			}
			state_cp_06_ON = 1;
			state_cp_06_OFF = 0;
		}
		else
		{
			wait_cp_06_ON++;	
		}
		wait_cp_06_OFF = 0;
	}

#if EQUIP_LINHA50== CD_EQUIP
	if((statusChange_cp_1 != 0) || (statusChange_cp_2 != 0)|| (statusChange_cp_3 != 0)|| (statusChange_cp_4 != 0)|| (statusChange_cp_5 != 0)|| (statusChange_cp_6 != 0))
	{
		/*if(statusChange_cp_1 == 1 && statusChange_cp_2 == 0)
			ChangedPort = 1;
		if(statusChange_cp_1 == 0 && statusChange_cp_2 == 1)
			ChangedPort = 2;		
		if(statusChange_cp_1 == 1 && statusChange_cp_2 == 1)
			ChangedPort = 3;*/

		//pulso_cp_3 = ChangedPort;

 		GravaNaBatteryRAM(REG_BATT_MEM_NORM_MD4040TI_3G);
	}
#endif
	UrmsA = pulso_cp_1;
	UrmsB = pulso_cp_2;
	UrmsC = pulso_cp_3;
	IrmsA = pulso_cp_4;
	IrmsB = pulso_cp_5;
	IrmsC = pulso_cp_6;
}
#endif

void T0isr (void)	__irq					//10ms
{
static short timer_pulsox=0;

//MD50 e CT50 nunca entram aqui, porque o Timer não é disparado no MD50 e CT50.

#if ((EQUIP_LINHA50== CP_EQUIP)||( EQUIP_LINHA50== CD_EQUIP)) //na falta de uma rotina de cálculo
	if (timer_pulsox==1400)
	{
			timer_pulsox=0;
			HabCalculos=1;
			estouvivo = 1;
	}
	timer_pulsox++;

#endif


	timer_pulso++;
#if ((EQUIP_LINHA50== CP_EQUIP)||( EQUIP_LINHA50== CD_EQUIP))
	conta_pulsos();
#endif

#if 0

	short i;
	DWORD T0IRtemp;
	DWORD tT0CR0;

	if ((ContadorTimer0forFreq!=0)&&(EtapaMedirFreq!=1))
	{
		ContadorTimer0forFreq++;
	}
	if ((((T0IRtemp&0x10)==0x10))&&(FlagHabCalculoFreq==NAO))
	{
#ifdef LEGADO
		T0IR=T0IR|0x10;
#endif
		EtapaMedirFreq=-EtapaMedirFreq;
		if (EtapaMedirFreq==1)
		{
			FreqAt2=(float)tT0CR0;
			DESABILITA_CALC_FREQ;
			FlagHabCalculoFreq=SIM;
		}
		else
		{
#ifdef LEGADO
			FreqAt1=(float)(T0MR0-tT0CR0);
#endif
			ContadorTimer0forFreq++;
		}
	}
	else
		//if (FreqAt==0) //nao executa nada...
	{


		timer_counter0++;

#if (DEBUG_SEM_AD==0)

#if EQUIP == CM_EQUIP
		*pUa=ADC0Read(0);
		for (i=0;i<=25;i++);
		*pUb=ADC0Read(1);
		for (i=0;i<=25;i++);
		*pUc=ADC0Read(2);
		for (i=0;i<=25;i++);
		*pIa=ADC0Read(3);

		for (i=0;i<=25;i++);
		*pIb=ADC0Read(4);
		for (i=0;i<=25;i++);
		*pIc=ADC0Read(5);

		*pUa=(short) (*pUa-nivelDCUa);
#if (MONO_TRI==TRIFASICO)
		*pUb=(short) (*pUb-nivelDCUb);
		*pUc=(short) (*pUc-nivelDCUc);
#endif
#if (MONO_TRI==MONOFASICO)
		*pUb=*pUa;
		*pUc=*pUa;
#endif


#if (MONO_TRI==TRIFASICO)
		*pIa=(short) (*pIa-nivelDCIa);
		*pIb=(short) (*pIb-nivelDCIb);
		*pIc=(short) (*pIc-nivelDCIc);
#endif
#if (MONO_TRI==MONOFASICO)
		*pIa=(short) (*pIc-nivelDCIc);
		*pIb=*pIa;
		*pIc=*pIa;
#endif

#else
#ifdef LEGADO
		*pUa=ADC0Read(0);
		for (i=0;i<=25;i++);
		*pUb=ADC0Read(1);
		for (i=0;i<=25;i++);
		*pUc=ADC0Read(2);
		for (i=0;i<=25;i++);
		*pIa=ADC0Read(3);
#if EQUIP==TR_EQUIP
		for (i=0;i<=25;i++);
		*pIb=ADC0Read(5);
#else
		for (i=0;i<=25;i++);
		*pIb=ADC0Read(4);
#endif
#if EQUIP==TR_EQUIP
		for (i=0;i<=25;i++);
		*pIc=ADC0Read(4);
#else
		for (i=0;i<=25;i++);
		*pIc=ADC0Read(5);
#endif
#endif
#if EQUIP!=CM_EQUIP

#if CP40==0
		if(((LerPinosEmPorta(2,0x00000200)))==0x00000000)
		{
			flag1pulso=SIM;
		}
		if(((LerPinosEmPorta(2,0x00000100)))==0x00000000)
		{
			flag2pulso=SIM;
		}
#else
		if((LerPinosEmPorta(2,0x000200))==0x00000000)
		{
			flag2pulso=SIM;
		}
		if((LerPinosEmPorta(2,0x000100))==0x00000000)
		{
			flag1pulso=SIM;
		}
		if((LerPinosEmPorta(0,0x00010000))==0x00000000)
		{
			flag3pulso=SIM;
		}
		if((LerPinosEmPorta(0,0x00020000))==0x00000000)
		{
			flag4pulso=SIM;
		}
#endif


#endif

		*pUa=(short) (*pUa-nivelDCUa);
		*pUb=(short) (*pUb-nivelDCUb);
		*pUc=(short) (*pUc-nivelDCUc);
		*pIa=(short) (*pIa-nivelDCIa);
		*pIb=(short) (*pIb-nivelDCIb);
		*pIc=(short) (*pIc-nivelDCIc);

#endif
		Namostras++; //incrementamos o contador de amostragens feitas
#ifdef LEGADO
		/*Neste ponto todas as amostragem dos 6 AD est�o conclu�das*/

		/*No seguinte 'if' ser� availiado se estamos na ultima possi��o do buffer circular*/
		if (pUa==&Ua[TAM_BUFFER_CIRCULAR-1]) //OBS:TAM_BUFFER_CIRCULAR-1 � a ultima possi��o do buffer, uma vez que o mesmo inicia em zero!
		{
			pUa=&Ua[0];pUb=&Ub[0];pUc=&Uc[0];
			pIa=&Ia[0];pIb=&Ib[0];pIc=&Ic[0];
		}
		else {
			/*incrementamos os ponteiros dos buffers, para a seguinte possi��o*/
			pUa++;pUb++;pUc++;pIa++;pIb++;pIc++;
		}
#endif
		if (Namostras==350  ) //TAM_BUFFER
		{
			HabCalculos=1;
			proximoInicioUa=pUa;
			proximoInicioUb=pUb;
			proximoInicioUc=pUc;
			proximoInicioIa=pIa;
			proximoInicioIb=pIb;
			proximoInicioIc=pIc;
			Namostras=0;
		}



#endif

	}

#endif

}


//void T1isr (void)	__irq					//10ms
void timer_admite_nested_interrupt_srv()
{
	int j;

#define ATRASO1 1//15  //20
#define ATRASO2 1//75	//100
#if EQUIP==MD_EQUIP
	DWORD t;
#endif
	timer_counter1++;
#ifdef LEGADO
	T1IR 		|= 0x00000001;					//Clear match 0 interrupt



	if (FlagWDIDentroDoTimer==SIM)
	{
		toogleWDI();
	}



#if EQUIP != CM_EQUIP

	if (FlagHabBanner==ON)
	{
		BannerCount++;
		if (BannerCount>=300) //200
		{
			SkewBanner();
			BannerCount=0;
		}
	}


#if EQUIP==MD_EQUIP

	if (CurrentDpy==9) //temos que mudar para o segundo shift-register
	{
		//reseta os shift-registers (sobe, desce e fica baixo...)
		SETpinoEmPorta(0, DPY_RST_PIN) ;
		for (t=0;t<ATRASO1;t++);
		CLRpinoEmPorta(0, DPY_RST_PIN) ;
		//muda o enable para o segundo shift-register
		SETpinoEmPorta(0, DPY_ENA_PIN) ;
		for (t=0;t<ATRASO2;t++);
	}

	if (CurrentDpy==13)
	{


		SETpinoEmPorta(2,LatchLED_1);
		CLRpinoEmPorta(2,~LatchLED_1);



	}
	if (CurrentDpy==14)
	{

		SETpinoEmPorta(2,LatchLED_2);
		CLRpinoEmPorta(2,~LatchLED_2);

	}
	if (CurrentDpy==15)
	{
		SETpinoEmPorta(2,LatchLED_3);
		CLRpinoEmPorta(2,~LatchLED_3);
	}

	if (CurrentDpy==15) //temos que voltar ao primeiro shift-register
	{
		//reseta os shift-registers (sobe, desce e fica baixo...)
		SETpinoEmPorta(0, DPY_RST_PIN) ;
		for (t=0;t<ATRASO1;t++);
		CLRpinoEmPorta(0, DPY_RST_PIN) ;
		//muda o enable para o primeiro shift-register
		CLRpinoEmPorta(0, DPY_ENA_PIN) ;
		for (t=0;t<ATRASO2;t++); //atraso2
		CurrentDpy=0;//aqui trancava
	}


	if (CurrentDpy<=12)
	{
		PiscarCount++;
		if (PiscarCount>=500)//400 //500
		{
			PiscarCount=0;
		}

		if (PiscarCount>=250)//150 //250	  //provoca o efeito de piscar...
		{
			if (CurrentDpy==DpyPiscante){
				//aqui, fazer piscar + de 1 dpy!!
				DpyPiscante++;
				if (DpyPiscante>UltimoDpyPiscante) {DpyPiscante=PrimeiroDpyPiscante;}
				SETpinoEmPorta(2,0);//  0x00080000; //DisplayChar[CurrentDpy];
				CLRpinoEmPorta(2,0);// ~0x00080000; //DisplayChar[CurrentDpy];
			}
			else
			{
				SETpinoEmPorta(2,DisplayChar[CurrentDpy]);
				CLRpinoEmPorta(2,DisplayChar[CurrentDpy]);
			}
			for (t=0;t<ATRASO1;t++);//for (t=0;t<ATRASO1;t++);
			SETpinoEmPorta(0,WR7SEG_PIN);
			for (t=0;t<ATRASO2;t++);
			CLRpinoEmPorta(0,WR7SEG_PIN);
		}
		else
		{


			SETpinoEmPorta(2,DisplayChar[CurrentDpy]);
			CLRpinoEmPorta(2,DisplayChar[CurrentDpy]);
			for (t=0;t<ATRASO1;t++);
			SETpinoEmPorta(0,WR7SEG_PIN);
			for (t=0;t<ATRASO2;t++);
			CLRpinoEmPorta(0,WR7SEG_PIN);
		}
	}

	//muda o clock para engolir o dado ...
	SETpinoEmPorta(0,DPY_CLK_PIN);
	for (t=0;t<ATRASO1;t++);
	CLRpinoEmPorta(0,DPY_CLK_PIN);


	CLRpinoEmPorta(2,0xFFFFFFFF); //zera o barramento para impedir escritas espurias, no momento do shift do latch.



	//programamos para o seguinte display
	CurrentDpy++;
#endif


#endif

#endif //LEGADO

	CountSilenceTime++;

	if(CountSilenceTime > 100 && silence == 0 && gsm_wait_for_modbus == FALSE)
	{
		for(j = 0; j < BUFSIZE; j++)
		{
			UART1BufferQuectel[j] = UART1Buffer[j];
			UART1Buffer[j] = 0;
		}
		gsm_uart_status = COMPLETE;

		UART1Count = 0;	
		silence = 1;
	}
	else if(CountSilenceTime > 100 && silence == 0 && gsm_wait_for_modbus == TRUE)
	{
	 	for(j = 0; j < BUFSIZE; j++)
		{
			UART1BufferQuectel[j] = UART0Buffer[j];
			UART1Buffer[j] = 0;
		}
		gsm_uart_status = COMPLETE;
		silence = 1;	
	}

	if(CountSilenceTime > 100)
		CountSilenceTime = 200;

	if(gsm_wait_for_modbus == TRUE)
		TAB_SIL_CARGA[BaudRatex] = 100;


	ContSilencioMODBUS++;

	if ((gsm_wait_for_modbus == FALSE && ContSilencioMODBUS >= TAB_SIL_CARGA[BaudRatex]) || (gsm_wait_for_modbus == TRUE && CountSilenceTime > 2))
	{
		//	pisca2();
		if (FlagChegouEnderecoMODBUS == SIM)
		{	CountSilenceTime = 0;
			//	pisca3();
#if HABSERFIXO==NAO
			SETpinoEmPorta(0,HABSER_PIN);  // (desabilita recepcao...)
#endif
			gsm_uart_status = COMPLETE;
			FlagHouveSilencioMODBUS=SIM;
			FlagChegouEnderecoMODBUS=NAO;
			ContSilencioMODBUS=0;
			UART0Count=0;
#if (EQUIP == CM_EQUIP)&&(MD4040TI==0)
			AnalizaBufferMODBUS();//HabResponder=ON;
#else
			if (FlagChegouBroadCast==SIM)
			{
				FlagChegouBroadCast=NAO;
				AnalizaBufferPR4000();//HabResponder=ON;
			}
			else
			{
			    #ifdef MODELO_EARHT
					if (FlagChegouEnderecoMODBUSMestre==SIM)
					{		

							AnalizaBufferMODBUS_MASTER(); //incluido para quando houver resposta do escravao RHT
							FlagChegouEnderecoMODBUSMestre=NAO;
				    }
					else
					{
					AnalizaBufferMODBUS();//HabResponder=ON;
					}

				#else
					AnalizaBufferMODBUS();//HabResponder=ON;
				#endif
			}

#endif
		}
		FlagHouveSilencioMODBUS=SIM;
	}
#if EQUIP == CM_EQUIP
	contadorSeg++;

	if (contadorSeg>=UMSEGUNDO)
	{
		contadorSeg=0;
		if (FLAG_HAB_CONTADOR_FP_FORA==1)      {contadorFPfora++;}    else {contadorFPfora=ZERADO;}
		if (FLAG_HAB_CONTADOR_DHT_FORA==1)     {contadorDHTfora++;}  else {contadorDHTfora=ZERADO;}
		if (FLAG_HAB_CONTADOR_V_FORA==1)       {contadorVfora++;}    else {contadorVfora=ZERADO;}
		if (FLAG_HAB_CONTADOR_I_FORA==1)       {contadorIfora++;}    else {contadorIfora=ZERADO;}
		if (FLAG_HAB_CONTADOR_AL_FP_FORA==1)   {contadorALFPfora++;} else {contadorALFPfora=ZERADO;}
		if (OPERANDO_SAIDAS==NAO)
		{
			if (FLAG_PROG_F32==NAO)
			{
				Sys_AlarmeVerificacao();
			}
		}
	}
#endif


}



/******************************************************************************
 **                            End Of File
 ******************************************************************************/
