/*****************************************************************************
 *   extint.c:  External interrupt API C file for NXP LPC23xx/24xx 
 *   Family Microprocessors
 *
 *   Copyright(C) 2006, NXP Semiconductor
 *   All rights reserved.
 *
 *   History
 *   2006.07.13  ver 1.00    Prelimnary version, first Release
 *
 *****************************************************************************/
#define EXT extern
#include "global.h"
 

volatile DWORD eint0_counter;

/*****************************************************************************
 ** Function name:		EINT0_Handler
 **
 ** Descriptions:		external INT handler
 **
 ** parameters:			None
 ** Returned value:		None
 ** 
 *****************************************************************************/
//
//void EINT0_Handler (void) __irq 
//{
//    EXTINT = EINT0;		/* clear interrupt */
//		
//   IENABLE;			/* handles nested interrupt */
//   eint0_counter++;
//   if ( eint0_counter & 0x01 )	/* alternate the LED display */
//   {
//		FIO2SET = 0x0000000F;	/* turn off P2.0~3 */	
//		FIO2CLR = 0x000000F0;	/* turn on P2.4~7 */
//    }
//    else
//    {
//		FIO2SET = 0x000000F0;	/* turn on P2.0~3 */	
//		FIO2CLR = 0x0000000F;	/* turn off P2.4~7 */
//    }
//    IDISABLE;
//	    VICVectAddr = 0;		/* Acknowledge Interrupt */
//}

void EINT2_Handler (void) __irq 
{

	//	CONTPOWERDOWN++;
#if 1
	if (estouvivo==SIM)
		//	if(CONTPOWERDOWN==100){
	{    	
	    //FIO0CLR=0x00010000;
		PowerDown();
		//while(1){toogleWDI();}
		forceReset();

	}
#endif


}
/*****************************************************************************
 ** Function name:		EINTInit
 **
 ** Descriptions:		Initialize external interrupt pin and
 **				install interrupt handler
 **
 ** parameters:			None
 ** Returned value:		true or false, return false if the interrupt
 **				handler can't be installed to the VIC table.
 ** 
 *****************************************************************************/
DWORD EINTInit( void )
{
#ifdef LEGADO
	PINSEL4 = 0x01000000;
	IO2_INT_EN_F = 0x1000;	
	EXTMODE = EINT2_EDGE;	/* INT2 edge trigger */
	EXTPOLAR = 0;			/* INT0 is falling edge by default */

	if ( install_irq( EINT2_INT, (void *)EINT2_Handler, HIGHEST_PRIORITY ) == FALSE )
	{
		return (FALSE);
	}
#endif
	return( TRUE );
}

/******************************************************************************
 **                            End Of File
 ******************************************************************************/

