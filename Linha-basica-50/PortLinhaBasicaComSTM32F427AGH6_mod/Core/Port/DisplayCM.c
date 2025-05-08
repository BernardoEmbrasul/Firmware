#define EXT extern 
#include "global.h"
#include "ssd1306.h"
 




const char TabelaCaracteresEspeciais[]=
{
	0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f, 0x1f,   //Tudo Preto
	0x04, 0x0e, 0x04, 0x20, 0x06, 0x08, 0x08, 0x06,   //C+
	0x20, 0x0e, 0x20, 0x20, 0x06, 0x08, 0x08, 0x06,   //C-
	0x01, 0x03, 0x07, 0x1f, 0x1f, 0x07, 0x03, 0x01,   //simbolo de ALARME
	0x1F, 0x1B, 0x15, 0x11, 0x15, 0x15, 0x1F, 0x1F,   //simbolo 'A' video inverso
	0x1F, 0x13, 0x15, 0x11, 0x15, 0x13, 0x1F, 0x1F,   //simbolo 'B' video inverso
	0x1F, 0x11, 0x17, 0x17, 0x17, 0x11, 0x1F, 0x1F,   //simbolo 'C' video inverso
	//0x1F, 0x1B, 0x15, 0x15, 0x15, 0x1B, 0x1F, 0x1F, //fi, video inverso
	//0x1F, 0x11, 0x1D, 0x11, 0x1D, 0x11, 0x1F, 0x1F, //3, video inverso
	0x1F, 0x04, 0x1F, 0x15, 0x15, 0x1F, 0x04, 0x1F,   //fi, grandao
	0};


/*
 ***Condicao inicial*********
 IMPORTANTE!!!
 LcdCS=0;              //preparamos o Enable para o pulso, colocar no main
 */
/*
 *************************************************************************
 Rotinas do Display
 *************************************************************************
 */




#define	CS	 			0x00080000 	//P0.19
#define	RS	 			0x00100000 	//P0.20



#define BARRAMENTO    		0x000000FF 	//Localizacao do barramento de dados, na porta, � entre o bit 0 ateh a 7
#define INICIO_BARRAMENTO	0     		// Localiza o inicio do barramento de dados
#define BARRAMENTO_EM_P2 	ON //seleciona porta 2 ou 0 .
#define RS_EM_P1 			OFF//seleciona porta 1 ou 0
#define CS_EM_P1 			OFF //seleciona porta 1 ou 0

void Atraso(int atra)
{
	int i;
	for(i=0;i<atra;i++);
}


void WrLcdChar(unsigned char dataout)
{
#ifdef LEGADO
	long int datasaida;
#if RS_EM_P1==ON         
	FIO1SET = RS; //select send Data ;  RS
#else


	SETpinoEmPorta(0,RS);//select send Data ; RS

#endif
	datasaida=dataout;      //put data into port
	datasaida<<=INICIO_BARRAMENTO;
#if BARRAMENTO_EM_P2==ON

	CLRpinoEmPorta(2,BARRAMENTO);
	SETpinoEmPorta(2,datasaida);

#else
	FIO0CLR=BARRAMENTO;
	FIO0SET=datasaida;
#endif
	PulseE();               //pulse the Enable line

#else
	unsigned char dataoutx[2];
	dataoutx[0]=dataout;
	dataoutx[1]=0;
    SSD1306_Puts (dataoutx, &Font_7x10, 1);

#endif
}

void WrLcdData(unsigned char dataout)
{
#ifdef LEGADO
	long int datasaida;
#if RS_EM_P1==ON        
	FIO1SET=RS;	   	   //select send Data ; RS
#else

	SETpinoEmPorta(0,RS);


#endif
	datasaida=dataout;		   //put data into port
	datasaida<<=INICIO_BARRAMENTO;				
#if BARRAMENTO_EM_P2==ON

	CLRpinoEmPorta(2,BARRAMENTO);
	SETpinoEmPorta(2,datasaida);



#else
	FIO0CLR=BARRAMENTO;
	FIO0SET=datasaida;
#endif
	PulseE();	               //pulse the Enable line

#else
	unsigned char dataoutx[2];
	dataoutx[0]=dataout;
	dataoutx[1]=0;
    SSD1306_Puts (dataoutx, &Font_7x10, 1);
#endif
}

/*-----------------------------------------------------------------------*/

void WrLcdCom(unsigned char inst)
{
#ifdef LEGADO

	long int datasaida;
#if RS_EM_P1==ON	       
	FIO1CLR=RS;		   //select send Command
#else

	CLRpinoEmPorta(0,RS); //select send Command



#endif
	datasaida=inst;			   //load command into port
	datasaida<<=INICIO_BARRAMENTO;				    
#if BARRAMENTO_EM_P2==ON


	CLRpinoEmPorta(2,BARRAMENTO);

	SETpinoEmPorta(2,datasaida);


#else
	FIO0CLR=BARRAMENTO;
	FIO0SET=datasaida;
#endif
	PulseE();				   //pulse the Enable line
#endif
}

/*-----------------------------------------------------------------------*/

void PulseE()
{
#ifdef LEGADO
	//5junho FIO0SET=LCD_SEL_PIN;
	//5junho Atraso(t75Micro);      //Substitui por um delay de 500ns Delay(ns20);
	//5junho FIO0CLR=LCD_SEL_PIN;

	Atraso(t75Micro);      //Substitui por um delay de 500ns Delay(ns20);
#if CS_EM_P1==ON
	FIO1SET=CS;	       // CS
#else

	SETpinoEmPorta(0,CS);



#endif
	Atraso(t75Micro);   //Delay(ns500);
#if CS_EM_P1==ON
	FIO1CLR=CS;	       // CS
#else


	CLRpinoEmPorta(0,CS);

#endif
	Atraso(t75Micro);
#endif
}

void PrtLcd(char string[],char linha,char coluna)
{
int i=0;
#ifdef LEGADO

	char seguintelinha=0;

	PosCur(linha,coluna);

	while(string[i]!=0)
	{
		WrLcdData(string[i]);
		i++;
		if (i==16)
		{
			seguintelinha=1;
			break;
		}
	}

	if (seguintelinha)
	{
		PosCur(2,0);
		while(string[i]!=0)
		{
			WrLcdData(string[i]);
			i++;
		}
	}
#else

//displpay 128x64
	SSD1306_GotoXY (coluna*7,(linha+1)*10);
	SSD1306_Puts (string, &Font_7x10, 1);
    SSD1306_UpdateScreen(); //display


#endif
}

void PrtLcd2( char string[],char linha,char coluna, FontDef_t* fonte)
{
int i=0;
#ifdef LEGADO

	char seguintelinha=0;

	PosCur(linha,coluna);

	while(string[i]!=0)
	{
		WrLcdData(string[i]);
		i++;
		if (i==16)
		{
			seguintelinha=1;
			break;
		}
	}

	if (seguintelinha)
	{
		PosCur(2,0);
		while(string[i]!=0)
		{
			WrLcdData(string[i]);
			i++;
		}
	}
#else

//displpay 128x64

	//SSD1306_GotoXY (coluna*7,(linha+1)*10);
	SSD1306_GotoXY(coluna, linha);

	// evita mostrar "  -0.000", substitui por "   0.000"
	// é importante para questões visuais das potências reativas
	if (!(strcmp( (char *)string, "  -0.000"))){ string[2] = ' '; }

	// eivtar o problema do 'nan'
	uint32_t size = strlen(string);
	if( string[size-1] == 'n' && string[size-2] == 'a' && string[size-3] == 'n' ){
		SSD1306_GotoXY(coluna-4, linha);
		string[size-1] = '-';
		string[size-2] = '-';
		string[size-3] = '-';
	}

	SSD1306_Puts(string, fonte, 1);
    SSD1306_UpdateScreen(); //display

#endif
}


/*-----------------------------------------------------------------------*/
#if EQUIP==CM_EQUIP
void DisplayInit()
{
	ResetLcd();
	InitLcd();
	WrLcdCom(OffDsp);
	WrLcdCom(OnDsp);
	WrLcdCom(OffCur);
	GeraSimbolos();        //gera os simbolos para o LCD
}
#endif

void InitLcd()
{
	WrLcdCom(Config);    //Function Set - 2 lines 5x7 fontsWrLcdCom(OffCur); //display ON
	WrLcdCom(EntryMode); //set Entry Mode;
	WrLcdCom(ClrDsp);    //clear display, home Cursor
}

/*-----------------------------------------------------------------------*/

void ResetLcd()
{
	WrLcdCom(Step);     // step1
	Atraso(t4Mili); // Delay4Ms();
	WrLcdCom(Step);     // step2
	Atraso(t1Mili); // Delay1Ms();
	WrLcdCom(Step);     // step3
	Atraso(t1Mili); //Delay1Ms();                                                                                                                                                                                                                                                                                                                       
	WrLcdCom(Config);   //FUNCTION SET
	WrLcdCom(ClrDsp);   //clear display, home Cursor
	WrLcdCom(EntryMode);//set ENTRY MODE; increment Cursor, do not shift display
}
/*-----------------------------------------------------------------------*/
#if EQUIP==CM_EQUIP
void PrtLcdBcdNumber(char number)
{
	PrtLcdBcdNibble(number,1);
	PrtLcdBcdNibble(number,0);
}

void PrtLcdBcdNumber2(char number)
{
	//PrtLcdBcdNibble(number,2);
	//PrtLcdBcdNibble(number,1);
	PrtLcdBcdNibble(number,0);
}
#endif
/*-----------------------------------------------------------------------*/

void PrtLcdBcdNibble(char number ,char nibble)
{
	unsigned char temp;
	if (nibble==0) //nibble inferior
	{
		temp=number&0x0F;
	}
	else
	{
		temp=number&0xF0;

		temp=temp>>4;
	}
	WrLcdChar(temp+0x30);//converto em ASCII
}

/*-----------------------------------------------------------------------*/

void PosCur(char linha,char coluna)
{
#ifdef LEGADO
	if (linha==0)  // linha1
	{
		WrLcdCom(coluna+0x80);





	}
	else           // linha2
	{
		WrLcdCom(coluna+0xC0);
	}
#else
	SSD1306_GotoXY (coluna*7,(linha+1)*10);
#endif
}

/********************************************************************************
Rotina: Sys_GeraSymbol()
Autor: Cesar Crovato
Comentarios: Programa os simbolos especiais para o LCD
Historico: Cria��o Nov-2006 
 ********************************************************************************/
void GeraSimbolos()
{
#ifdef LEGADO
	int i=0;

	WrLcdCom(CaracteresEspeciais);
	while(TabelaCaracteresEspeciais[i]!=0)
	{
		WrLcdData(TabelaCaracteresEspeciais[i]);
		i++;
	}
	WrLcdCom(ModoNormal);
#endif
}











