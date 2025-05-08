/*****************************************************************************
 *   wdt.c:  Watchdog C file for NXP LPC23xx/24xx Family Microprocessors
 *
 *   Copyright(C) 2006, NXP Semiconductor
 *   All rights reserved.
 *
 *   History
 *   2006.07.20  ver 1.00    Prelimnary version, first Release
 *
 *****************************************************************************/
#define EXT extern
#include "global.h"
#include "main.h"
 

volatile DWORD wdt_counter;

/*****************************************************************************
 ** Function name:		WDTHandler
 **
 ** Descriptions:		Watchdog timer interrupt handler
 **
 ** parameters:			None
 ** Returned value:		None
 ** 
 *****************************************************************************/
void WDTHandler(void) __irq 
{
#ifdef LEGADO
	WDMOD &= ~WDTOF;		/* clear the time-out terrupt flag */
	IENABLE;			/* handles nested interrupt */
	wdt_counter++;
	IDISABLE;
	VICVectAddr = 0;		/* Acknowledge Interrupt */
#endif
}

/*****************************************************************************
 ** Function name:		WDTInit
 **
 ** Descriptions:		Initialize watchdog timer, install the
 **				watchdog timer interrupt handler
 **
 ** parameters:			None
 ** Returned value:		true or false, return false if the VIC table
 **				is full and WDT interrupt handler can be
 **				installed.
 ** 
 *****************************************************************************/
DWORD WDTInit( void )
{

	/*
     Watchdog freq. is 32 kHz
     Prescaler: Min_Value = 4 and Max_Value = 256
     Reload: Min_Data = 0 and Max_Data = 4096
     TimeOut in seconds = (Reload * Prescaler) / Freq.
     MinTimeOut = (4 * 1) / 32000 = 0.000125 seconds (125 microseconds)
     MaxTimeOut = (256 * 4096) / 32000 = 32.768 seconds

     Tempo escolhido = (16 * 4095) / 32000 = 2.0475 segundos
*/

#if 0
	  hiwdg.Instance = IWDG;
	  hiwdg.Init.Prescaler = IWDG_PRESCALER_16;
	  hiwdg.Init.Reload = 4095;
	  if (HAL_IWDG_Init(&hiwdg) != HAL_OK)
	  {
	    Error_Handler();
	  }



      HAL_IWDG_Start(&hiwdg);

#endif

}

/*****************************************************************************
 ** Function name:		WDTFeed
 **
 ** Descriptions:		Feed watchdog timer to prevent it from timeout
 **
 ** parameters:			None
 ** Returned value:		None
 **
 *****************************************************************************/
void WDTFeed( void )
{
extern IWDG_HandleTypeDef hiwdg;
	 // SETpinoEmPorta(0,WDI_PIN);
	 // CLRpinoEmPorta(0,WDI_PIN);
	  HAL_IWDG_Refresh(&hiwdg);

	return;
}






void toogleWDI()
{
	//HAL_GPIO_WritePin( WDI_GPIO_Port, WDI_Pin, GPIO_PIN_SET) ;
	//HAL_GPIO_WritePin( WDI_GPIO_Port, WDI_Pin, GPIO_PIN_RESET) ;
	HAL_GPIO_TogglePin( WDI_GPIO_Port, WDI_Pin) ;

	//SETpinoEmPorta(0,WDI_PIN);
	//CLRpinoEmPorta(0,WDI_PIN);
	WDTFeed();


}


void forceReset(void)
{
	while(1){

		  HAL_Delay(100);


	      HAL_GPIO_TogglePin( LED_PWR_GPIO_Port,LED_PWR_Pin);  //led POWER
	      HAL_GPIO_WritePin(  AUXOUT3_GPIO_Port,AUXOUT3_Pin,GPIO_PIN_SET);


		  HAL_Delay(100);


	}
}



/******************************************************************************
 **                            End Of File
 ******************************************************************************/
