/*****************************************************************************
 *   uart.c:  UART API file for NXP LPC23xx/24xx Family Microprocessors
 *
 *   Copyright(C) 2006, NXP Semiconductor
 *   All rights reserved.
 *
 *   History
 *   2006.07.12  ver 1.00    Prelimnary version, first Release
 *
 ******************************************************************************/

#define EXT extern
#include "global.h"



//volatile DWORD UART0Status;
//volatile BYTE UART0TxEmpty = 1;
//volatile BYTE UART0Buffer[COMBUFSIZE];
//volatile DWORD UART0Count = 0;
void uart1_admite_nested_interrupt_srv(void);
extern void uart1_admite_nested_interrupt_irq(void);

void uart0_admite_nested_interrupt_srv(void);
extern void uart0_admite_nested_interrupt_irq(void);

/*****************************************************************************
 ** Function name:		UART0Handler
 **
 ** Descriptions:		UART0 interrupt handler
 **
 ** parameters:			None
 ** Returned value:		None
 **
 *****************************************************************************/
//void UART0Handler (void) __irq

void debug_gsm(char *index)
{
	int j;

	for(j = 0; j < COMBUFSIZE; j++)
	{
		UART1BufferQuectel[j] = *index;
	}

}

//void uart1_irq (void) __irq
void uart1_admite_nested_interrupt_srv(void)
{
#ifdef LEGADO
	BYTE IIRValue, LSRValue;
    BYTE Dummy;
	BYTE NovoDadoValido;
	static int i, j, cnt;
	static char start_record, end_record, state = 0;
	int start_buffer, end_buffer;
	BYTE DadoRecebido;

	NovoDadoValido = 0;
    IIRValue = U1IIR;
   	gsm_debug = 1;
    IIRValue >>= 1;            /* skip pending bit in IIR */
    IIRValue &= 0x07;         /* check bit 1~3, interrupt identification */
    if ( IIRValue == IIR_RLS )      /* Receive Line Status */
    {
      LSRValue = U1LSR;
      /* Receive Line Status */
      if ( LSRValue & (LSR_OE|LSR_PE|LSR_FE|LSR_RXFE|LSR_BI) )
      {

          /* There are errors or break interrupt */
          /* Read LSR will clear the interrupt */
          UART1Status = LSRValue;
          Dummy = U1RBR;      /* Dummy read on RX to clear
                        interrupt, then bail out */
          //IDISABLE;
          VICVectAddr = 0;      /* Acknowledge Interrupt */
          return;
      }
      if ( LSRValue & LSR_RDR )   /* Receive Data Ready */
      {
          /* If no error on RLS, normal ready, save into the data buffer. */
          /* Note: read RBR will clear the interrupt */
          NovoDadoValido = 1;
		  //UART1Buffer[UART1Count] = U1RBR;
          //UART1Count++;
          if ( UART1Count == BUFSIZE )
          {
            //UART1Count = 0;   //    buffer overflow
          }
      }
    }
    else if ( IIRValue == IIR_RDA )   /* Receive Data Available */
    {
      /* Receive Data Available */
	  NovoDadoValido = 1;

      //UART1Buffer[UART1Count] = U1RBR;

	  //UART1Count++;

      if ( UART1Count == BUFSIZE)
      {
          //UART1Count = 0;      /* buffer overflow */
      }
    }
    else if ( IIRValue == IIR_CTI )   /* Character timeout indicator */
    {
      /* Character Time-out indicator */
      UART1Status |= 0x100;      /* Bit 9 as the CTI error */
    }
    else if ( IIRValue == IIR_THRE )   /* THRE, transmit holding register empty */
    {
      /* THRE interrupt */
      LSRValue = U1LSR;      /* Check status in the LSR to see if
                        valid data in U0THR or not */
      if ( LSRValue & LSR_THRE )
      {
          UART1TxEmpty = 1;
      }
      else
      {
          UART1TxEmpty = 0;
      }
    }

// Adicionado por gabriel

	gsm_debug = 2;
	if(NovoDadoValido == 1)
	{
		if ( UART0Count >= COMBUFSIZE )
		{
			UART0Count = 0;		/* buffer overflow */
		}

		if(gsm_wait_for_modbus == TRUE)
			gsm_udp_connection_established = TRUE;
	}



	if(NovoDadoValido == 1)
	{
	   gsm_debug = 3;
		if(FlagChegouEnderecoMODBUS == FALSE && gsm_wait_for_modbus == TRUE)
		{  gsm_debug = 4;
			DadoRecebido = U1RBR;

			if (DadoRecebido == MeuEnderecoMODBUS)
			{	gsm_debug = 5;
				FlagChegouBroadCast = FALSE;
				FlagChegouEnderecoMODBUS = TRUE;
				FlagHouveSilencioMODBUS = FALSE;
			}

			if (DadoRecebido == 0x00)
			{
				gsm_debug = 6;
				FlagChegouBroadCast = TRUE;
				FlagChegouEnderecoMODBUS = TRUE;
				FlagHouveSilencioMODBUS = FALSE;
			}
		}
		else
		{
			gsm_debug = 7;
			if(gsm_wait_for_modbus == TRUE)
			{	gsm_debug = 8;
				//debug_gsm("a");
				if (FlagHouveSilencioMODBUS == FALSE)
				{	gsm_debug = 9;
					//debug_gsm("b");

				 	UART0Buffer[UART0Count] = U1RBR;
					UART0Count++;
				}
				//debug_gsm("c");
			}
			else
			{	gsm_debug = 10;
				UART1Buffer[UART1Count] = U1RBR;
				UART1Count++;

				if(UART1Count > BUFSIZE)
				{
					UART1Count = 0;
					gsm_uart_status = COMPLETE;
				}
			}
		}
	}

	CountSilenceTime = 0;
	silence = 0;
	ContSilencioMODBUS=0;
//	UART0TxEmpty = 1;
	T1TCR=1; //enable timer1

    //IDISABLE;
    VICVectAddr = 0;      /* Acknowledge Interrupt */
#endif
}

void uart0_admite_nested_interrupt_srv(void)
{
#ifdef LEGADO

	BYTE IIRValue, LSRValue;
	BYTE Dummy;
	BYTE NovoDadoValido;
	BYTE DadoRecebido;
	static char cnt_uart1 = 0;


	if(gsm_wait_for_modbus == TRUE)
		return;

	NovoDadoValido=NAO;   		/*Default � NAO*/
	//    IENABLE;				/* handles nested interrupt */
	IIRValue = U0IIR;

	IIRValue >>= 1;			/* skip pending bit in IIR */
	IIRValue &= 0x07;			/* check bit 1~3, interrupt identification */


 /*
	if(IIRValue == IIR_RLS)
	{
		LSRValue = U1LSR;
		string_return[cnt_uart1] = 't';//LSRValue;
		cnt_uart1++;
		if(cnt_uart1 >= 3)
			cnt_uart1 = 0;
	}
*/
	if ( IIRValue == IIR_RLS )		/* Receive Line Status */
	{
		LSRValue = U0LSR;
		/* Receive Line Status */
		if ( LSRValue & (LSR_OE|LSR_PE|LSR_FE|LSR_RXFE|LSR_BI) )
		{
			/* There are errors or break interrupt */
			/* Read LSR will clear the interrupt */
			UART0Status = LSRValue;
			Dummy = U0RBR;		/* Dummy read on RX to clear
								   interrupt, then bail out */

			//	IDISABLE;
			Dummy=0;
			T1TCR=1; //enable timer1
			VICVectAddr = Dummy;		/* Acknowledge Interrupt */
			return;
		}
		if ( LSRValue & LSR_RDR )	/* Receive Data Ready */
		{
			/* If no error on RLS, normal ready, save into the data buffer. */
			/* Note: read RBR will clear the interrupt */
			//	UART0Buffer[UART0Count] = U0RBR;
			//	UART0Count++;
			NovoDadoValido=SIM;
			if ( UART0Count == COMBUFSIZE )
			{
				UART0Count = 0;		/* buffer overflow */
			}
		}
	}
	else if ( IIRValue == IIR_RDA )	/* Receive Data Available */
	{
		/* Receive Data Available */
		//UART0Buffer[UART0Count] = U0RBR;
		//UART0Count++;
		NovoDadoValido=SIM;
		if ( UART0Count == COMBUFSIZE )
		{
			UART0Count = 0;		/* buffer overflow */
		}
	}
	else if ( IIRValue == IIR_CTI )	/* Character timeout indicator */
	{
		/* Character Time-out indicator */
		UART0Status |= 0x100;		/* Bit 9 as the CTI error */
		NovoDadoValido=SIM;
		FlagHouveSilencioMODBUS=SIM;
	}
	else if ( IIRValue == IIR_THRE )	/* THRE, transmit holding register empty */
	{
		/* THRE interrupt */
		LSRValue = U0LSR;		/* Check status in the LSR to see if
								   valid data in U0THR or not */
		if ( LSRValue & LSR_THRE )
		{
			UART0TxEmpty = 1;
		}
		else
		{
			UART0TxEmpty = 0;
		}
	}


	if (NovoDadoValido==SIM) //Se o dado n�o tem erro...
	{
		if (FlagChegouEnderecoMODBUS==NAO)
		{
			DadoRecebido=U0RBR;
			if (DadoRecebido==MeuEnderecoMODBUS)
			{
				FlagChegouBroadCast=NAO;
				FlagChegouEnderecoMODBUS=SIM;
				FlagHouveSilencioMODBUS=NAO;
#if EQUIP==TR_EQUIP
				FIO0CLR=LED_RX;
#endif
			}


			#ifdef  MODELO_EARHT
				if ((DadoRecebido==MeuEnderecoMODBUS+1) || (DadoRecebido==MeuEnderecoMODBUS+2))
				{
					FlagChegouBroadCast=NAO;
					FlagChegouEnderecoMODBUS=SIM;
					FlagChegouEnderecoMODBUSMestre=SIM;
					FlagHouveSilencioMODBUS=NAO;
				}
			#endif


			if (DadoRecebido==0x00)
			{
#if (EQUIP==TR4000)
				FIO0CLR=LED_RX;
#endif
				FlagChegouBroadCast=SIM; //sempre que chega broad cast, � poss�vel que chegue uma mensagem do PR4000
				FlagChegouEnderecoMODBUS=SIM;
				FlagHouveSilencioMODBUS=NAO;
			}
		}
		else
		{
			if (FlagHouveSilencioMODBUS==NAO)
			{
				UART0Buffer[UART0Count] = U0RBR; //Note que o endereco do escravo nao esta no buffer.
				UART0Count++;
			}

		}
	}

	ContSilencioMODBUS=0;
	//   IDISABLE;

	UART0TxEmpty = 1;
	T1TCR=1;				//enable timer1
	VICVectAddr = 0;		/* Acknowledge Interrupt */
#endif
}

/*****************************************************************************
 ** Function name:		UARTInit
 **
 ** Descriptions:		Initialize UART0 port, setup pin select,
 **						clock, parity, stop bits, FIFO, etc.
 **
 ** parameters:			UART baudrate
 ** Returned value:		true or false, return false only if the
 **						interrupt handler can't be installed to the
 **						VIC table
 **
 *****************************************************************************/
DWORD UARTInit( DWORD baudrate, BYTE TipoParidadeStopsBits )
{
#ifdef LEGADO
	PINSEL0 = PINSEL0|0x00000050;       /* RxD0 and TxD0 */

	PINSEL0 = PINSEL0|0x00000050;	/* setup P0.2 for function TxD0 and P0.3 for function RxD0*/

	U0LCR = 0x83;					/* 8 bits, no Parity, 1 Stop bit */

	if (baudrate==BR115200)
	{
		U0DLM =0;
		U0DLL= 8;
		U0FDR =0x92;
	}
	if (baudrate==BR57600)
	{
		U0DLM =0;
		U0DLL= 11;
		U0FDR =0x97;
	}
	if (baudrate==BR56000)
	{
		U0DLM =0;
		U0DLL= 13;
		U0FDR =0xB6;
	}
	if (baudrate==BR38400)
	{
		U0DLM =0;
		U0DLL= 23;
		U0FDR =0xB3;
	}
	if (baudrate==BR19200)
	{
		U0DLM =0;
		U0DLL= 37;
		U0FDR =0xc7;
	}
	if (baudrate==BR14400)
	{
		U0DLM =0;
		U0DLL= 37;
		U0FDR =0x9a;
	}
	if (baudrate==BR9600)
	{
		U0DLM =0;
		U0DLL= 74;
		U0FDR =0xc7;
	}

	if (baudrate==BR4800)
	{
		U0DLM =0;
		U0DLL= 125;
		U0FDR =0x87;
	}

	U0LCR = 0x03;		/* DLAB = 0 */
	U0FCR = 0x07;		/* Enable and reset TX and RX FIFO. */
	U0LCR = 0x07;		//default  * DLAB = 0 */                    /* 8 bits, no Parity, 2 Stop bit    */


	if (TipoParidadeStopsBits==ps8N2)
	{
		U0LCR = 0x07;			/* 8 bits, no Parity, 2 Stop bit    */
	}
	if (TipoParidadeStopsBits==ps8E1)
	{
		U0LCR = 0x1B;			/* 8 bits, even Parity, 1 Stop bit    */
	}
	if (TipoParidadeStopsBits==ps8O1)
	{
		U0LCR = 0x0B;			/* 8 bits, odd Parity, 1 Stop bit    */
	}
	if (TipoParidadeStopsBits==ps8N1)
	{
		U0LCR = 0x03;			/* 8 bits, no Parity, 1 Stop bit    */
	}






	//if ( install_irq( UART0_INT, (void *)UART0Handler, LOWEST_PRIORITY) == FALSE )
	if ( install_irq( UART0_INT, (void *)(unsigned)uart0_admite_nested_interrupt_irq, LOWEST_PRIORITY) == FALSE )
	{
		return (FALSE);
	}

	U0IER = IER_RBR | IER_THRE | IER_RLS;	/* Enable UART0 interrupt */
#endif
	return (TRUE);
}

/*****************************************************************************
 ** Function name:		UARTSend
 **
 ** Descriptions:		Send a block of data to the UART 0 port based
 **				on the data length
 **
 ** parameters:			buffer pointer, and data length
 ** Returned value:		None
 **
 *****************************************************************************/
//void UARTSend(BYTE *BufferPtr, DWORD Length )
//{
//    while ( Length != 0 )
//    {
/* THRE status, contain valid data */
//		while ( UART0TxEmpty !=0 );
//	    UART0TxEmpty = 0;	/* not empty in the THR until it shifts out */
//		U0THR = *BufferPtr;
//		BufferPtr++;
//		Length--;
//    }
//    return;
//}
 #define THRE (1<<5)
void UART1Send(BYTE *BufferPtr, DWORD Length )
{
#ifdef LEGADO
    while ( Length != 0 )
    {
     // now we can write to the Tx FIFO

/* THRE status, contain valid data */
		while ( !(U1LSR & THRE ) ); // wait till the THR is empty
	    UART1TxEmpty = 0;	/* not empty in the THR until it shifts out */
		U1THR = *BufferPtr;
		BufferPtr++;
		Length--;
    }
    return;
#endif
}


void UARTSend(BYTE *BufferPtr, DWORD Length )
{

	DWORD tLength;
	short k=0;

	if(gsm_wait_for_modbus == TRUE)
	{
		UART1Send(BufferPtr,Length);
		return;
	}

	tLength=Length+1;
	UART0TxEmpty = 1;
#ifdef LEGADO
	for ( k = 0; k < (short)tLength; k++ )
	{
		while ( UART0TxEmpty == 0);
		UART0TxEmpty = 1;
		UART0TxEmpty = 1;
		UART0TxEmpty = 1;
		UART0TxEmpty = 0;

		U0THR = BufferPtr[k];

#if EQUIP==TR_EQUIP
		FIO0CLR=LED_TX;
#endif

	}
#endif
	//#endif

	//#if	FIRST==NAO
    extern void send_data(short len);
	send_data(Length);

	//#endif

	return;

}


void UARTSendOnly(BYTE *BufferPtr, DWORD Length )
{
    #ifdef LEGADO
	DWORD tLength;
	short k=0;
	tLength=Length+1;
	UART0TxEmpty = 1;

	if(gsm_wait_for_modbus == TRUE)
	{
		UART1Send(BufferPtr,Length);
		return;
	}

	for ( k = 0; k < (short)tLength; k++ )
	{
		ContSilencioMODBUS=0;
		while ( UART0TxEmpty == 0);
		UART0TxEmpty = 1;
		UART0TxEmpty = 1;
		UART0TxEmpty = 1;
		UART0TxEmpty = 0;
		ContSilencioMODBUS=0;
		U0THR =BufferPtr[k];
	}
	#endif
}

void UART1SendOnly(BYTE *BufferPtr, DWORD Length )
{
#ifdef LEGADO
	short k = 0;
	UART1TxEmpty = 1;

	for ( k = 0; k < Length; k++ )
	{
//		ContSilencioMODBUS=0;
		while ( UART1TxEmpty == 0);
//		UART1TxEmpty = 1;
//		UART1TxEmpty = 1;
//		UART1TxEmpty = 1;
//		UART1TxEmpty = 0;
//		ContSilencioMODBUS=0;
		U1THR = BufferPtr[k];
	}
#endif
}

/******************************************************************************
 **                            Rotinas UART genericas
 ******************************************************************************/

DWORD UART1Init(UNS_32 baud, UNS_8 channel, UNS_8 location)
{
#ifdef LEGADO
    UNS_32  div_l, div_h;
	unsigned short div;

    switch (channel)
	{
		case UART_CH_0:
			PCLKSEL0 &= ~(0x3<<6);

			break;

		case UART_CH_1:
			PCLKSEL0 &= ~(0x3<<8);
			break;

/*		case UART_CH_2:
			PCLKSEL0 &= ~(0x3<<48);
			break;

		case UART_CH_3:
			PCLKSEL0 &= ~(0x3<<50);
			break;
*/
		default:
			return;
	}


	div_h = ((UART_CLK/baud) >> 12) & 0xff;
	div_l = ((UART_CLK/baud+8) >> 4) & 0xff;

	div = UART_CLK/(16*baud);

	switch (channel)
	{
		case UART_CH_0:
			PINSEL0 &= ~(0x00000050);
			PINSEL0 |= 0x00000050;
			PCONP |= 0x1<<3;
			U0LCR = 0x83;   /* 8 bits, no Parity, 1 Stop bit */
			U0DLM = div_h;
			U0DLL = div_l;
			U0LCR = 0x03;   /* DLAB = 0 */
			U0FCR = 0x07;   /* Enable and reset TX and RX FIFO. */
			break;

		case UART_CH_1:
			switch (location)
			{
				case 0:
					PINSEL0 &= ~(0xC0000000);
					PINSEL0 |= 0x40000000;
					PINSEL1 |= 0x00000001;
					PINSEL1 &= ~(0x30000000);
					break;

				case 1:
					PINSEL4 &= ~(0x0000000F);
					PINSEL4 |= 0x00000000A;
					break;

				case 2:
					PINSEL7 |= 0x0000000F;
					break;
			}
			PCONP |= 0x1<<4;
			U1LCR = 0x83;   /* 8 bits, no Parity, 1 Stop bit */
			U1DLM = 0;//div_h;
			U1DLL = 3;//div_l;	   // 18Mhz / ((16 * 115200) * (1+9/4)) -> o 9/4 vem de 0x49
			U1FDR = 0x49;
			U1LCR = 0x03;   /* DLAB = 0 */
			U1FCR = 0x07;   /* Enable and reset TX and RX FIFO. */
			break;

		case UART_CH_2:
			switch (location)
			{
				case 0:
					PINSEL0 &= ~(0x00F00000);
					PINSEL0 |=   0x00500000;
					break;

				case 1:
					PINSEL4 &= ~(0x000F0000);
					PINSEL4 |=   0x000A0000;
					break;

				case 2:
					PINSEL9 &= ~(0x0000F000);
					PINSEL9 |=   0x0000A000;
					break;
			}
			PCONP |= 0x1<<24;
			U2LCR = 0x83;   /* 8 bits, no Parity, 1 Stop bit */
			U2DLM = div_h;
			U2DLL = div_l;
			U2LCR = 0x03;   /* DLAB = 0 */
			U2FCR = 0x07;   /* Enable and reset TX and RX FIFO. */
			break;

		case UART_CH_3:
			switch (location)
			{
				case 0:
					PINSEL0 &= ~(0x0000000F);
					PINSEL0 |=   0x0000000A;
					break;

				case 1:
					PINSEL1 |=   0x003C0000;
					break;

				case 2:

					PINSEL9 |=   0x0F000000;
					break;
			}
			PCONP |= 0x1<<25;
			U3LCR = 0x83;   /* 8 bits, no Parity, 1 Stop bit */
			U3DLM = div_h;
			U3DLL = div_l;
			U3LCR = 0x03;   /* DLAB = 0 */
			U3FCR = 0x07;   /* Enable and reset TX and RX FIFO. */
			break;
	}

	//if ( install_irq( UART1_INT, (void *)(unsigned)uart_admite_nested_interrupt_irq, HIGHEST_PRIORITY) == FALSE )
	if ( install_irq( UART1_INT, (void *)(unsigned)uart1_admite_nested_interrupt_irq, HIGHEST_PRIORITY) == FALSE )
	{
		return (FALSE);
	}

	U1IER = IER_RBR | IER_THRE | IER_RLS;	// Enable UART1 interrupt
#endif
	return (TRUE);
}


UNS_8	UARTIsDataReady(UNS_8 channel)
{
    #ifdef LEGADO
	switch (channel)
	{
		case UART_CH_0:
			if (U0LSR & 0x01) return TRUE;
				else return FALSE;

		case UART_CH_1:
			if (U1LSR & 0x01) return TRUE;
				else return FALSE;

		case UART_CH_2:
			if (U2LSR & 0x01) return TRUE;
				else return FALSE;

		case UART_CH_3:
			if (U3LSR & 0x01) return TRUE;
				else return FALSE;

		default:
			return FALSE;
	}
#endif
}
UNS_8	UARTWaitForByte(UNS_8 channel)
{
#ifdef LEGADO
	switch (channel)
	{
		case UART_CH_0:
			while((U0LSR & 0x01)==0);
			return U0RBR;

		case UART_CH_1:
			while((U1LSR & 0x01)==0);
			return U1RBR;

		case UART_CH_2:
			while((U2LSR & 0x01)==0);
			return U2RBR;

		case UART_CH_3:
			while((U3LSR & 0x01)==0);
			return U3RBR;

		default:
			return FALSE;
	}
#endif
}

UNS_8	UARTReceiveByte(UNS_8 channel)
{
 #ifdef LEGADO
	switch (channel)
	{
		case UART_CH_0:
			return U0RBR;

		case UART_CH_1:
			return U1RBR;

		case UART_CH_2:
			return U2RBR;

		case UART_CH_3:
			return U3RBR;

		default:
			return FALSE;
	}
	#endif
}

void	UARTTransmitByte(UNS_8 ch, UNS_8 channel)
{
    #ifdef LEGADO
	switch (channel)
	{
		case UART_CH_0:
			while (!(U0LSR & 0x20));
			U0THR = ch;
			break;

		case UART_CH_1:
			while (!(U1LSR & 0x20));
			U1THR = ch;
			break;

		case UART_CH_2:
			while (!(U1LSR & 0x20));
			U2THR = ch;
			break;

		case UART_CH_3:
			while (!(U1LSR & 0x20));
			U3THR = ch;
			break;

		default:
			break;
	}
#endif
}

void UARTTransmitString(UNS_8 *str, UNS_8 channel)
{
	while(*str) UARTTransmitByte(*str++, channel);
}

void _es_putc_retarget(int byte)
{
	UARTTransmitByte((UNS_8)byte, UART_CH_0);
}


/******************************************************************************
 **                            End Of File
 ******************************************************************************/
