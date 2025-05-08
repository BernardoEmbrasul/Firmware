/*****************************************************************************
 *   uart.h:  Header file for NXP LPC23xx Family Microprocessors
 *
 *   Copyright(C) 2006, NXP Semiconductor
 *   All rights reserved.
 *
 *   History
 *   2006.09.01  ver 1.00    Prelimnary version, first Release
 *
 ******************************************************************************/
#ifndef __UART_H 
#define __UART_H

#define IER_RBR		0x01
#define IER_THRE	0x02
#define IER_RLS		0x04

#define IIR_PEND	0x01
#define IIR_RLS		0x03
#define IIR_RDA		0x02
#define IIR_CTI		0x06
#define IIR_THRE	0x01

#define LSR_RDR		0x01
#define LSR_OE		0x02
#define LSR_PE		0x04
#define LSR_FE		0x08
#define LSR_BI		0x10
#define LSR_THRE	0x20
#define LSR_TEMT	0x40
#define LSR_RXFE	0x80

//#define BUFSIZE		0x10

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
#define ps8N1	3

#define	UART_CH_0	0x0
#define	UART_CH_1	0x1
#define	UART_CH_2	0x2
#define	UART_CH_3	0x4

typedef unsigned char  UNS_8;
typedef unsigned int   UNS_32;

#define UART_CLK 72000000/4

DWORD	UART1Init(UNS_32 baud, UNS_8 channel, UNS_8 location);
UNS_8	UARTIsDataReady(UNS_8 channel);
UNS_8	UARTReceiveByte(UNS_8 channel);
UNS_8	UARTWaitForByte(UNS_8 channel);
void	UARTTransmitByte(UNS_8 ch, UNS_8 channel);
void 	UARTTransmitString(UNS_8 *str, UNS_8 channel);
void 	_putc(int byte);


DWORD UARTInit( DWORD Baudrate ,BYTE TipoParidadeStopsBits );
void UARTSendOnly(BYTE *BufferPtr, DWORD Length );
void UART1SendOnly(BYTE *BufferPtr, DWORD Length );
void UART0Handler( void ) __irq;
//void UARTSend( BYTE *BufferPtr, DWORD Length );
void UARTSend(  BYTE *BufferPtr, DWORD Length );
void UART1Send(  BYTE *BufferPtr, DWORD Length );
#endif /* end __UART_H */
/*****************************************************************************
 **                            End Of File
 ******************************************************************************/
