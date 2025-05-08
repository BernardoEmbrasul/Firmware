/*****************************************************************************
 *   timer.h:  Header file for NXP LPC23xx/24xx Family Microprocessors
 *
 *   Copyright(C) 2006, NXP Semiconductor
 *   All rights reserved.
 *
 *   History
 *   2006.07.13  ver 1.00    Prelimnary version, first Release
 *
 ******************************************************************************/
#ifndef __TIMER_H
#define __TIMER_H

#define TIME_INTERVAL	Fpclk_72Mhz/100 - 1

#define HABILITA_CALC_FREQ   T0CCR=T0CCR|0x00000004
#define DESABILITA_CALC_FREQ T0CCR=T0CCR&0xFFFFFFFB

#define INTERVAL_10MS	149999			/* 10mSec = 150000-1 counts */
#define INTERVAL_260uS	4687
#define INTERVAL_1_6666mS  30000//20000//25000//47999mudei dia 07/12//25000  //0.0016667seg. aprox. 600Hz, aprovado por Tiago!
/* depending on the CCLK and PCLK setting, CCLK = 60Mhz, PCLK = 1/4 CCLK
   10mSec = 150.000-1 counts */
#define UMSEGUNDO 600

extern DWORD init_timer( void );
extern void enable_timer( BYTE timer_num );
extern void disable_timer( BYTE timer_num );
extern void reset_timer( BYTE timer_num );

#endif /* end __TIMER_H */
/*****************************************************************************
 **                            End Of File
 ******************************************************************************/
