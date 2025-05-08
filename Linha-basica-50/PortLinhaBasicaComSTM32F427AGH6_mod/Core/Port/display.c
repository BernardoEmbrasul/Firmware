/*****************************************************************************
 *   display.c:
 *
 *   Projeto MD2010-ARM
 *
 *   History
 *
 ******************************************************************************/
#define EXT extern
#include "global.h"
 

#if EQUIP!=CM_EQUIP

DWORD const DPYMatrizCode[ ]={
	//c�digo     s�mbolo    elemento da matriz
	0x0000003f,       //0:       0
	0x00000006,       //1:       1
	0x0000005b,       //2:       2
	0x0000004f,       //3:       3
	0x00000066,       //4:       4
	0x0000006d,       //5:       5
	0x0000007d,       //6:       6
	0x00000007,       //7:       7
	0x0000007f,       //8:       8
	0x0000006f,       //9:       9
	0x00000077,       //A:       10
	0x0000007C,       //b:       11	 
	0x00000039,       //C:       12
	0x00000058,       //c:       13
	0x00000050,       //r:       14
	0x0000006e,       //Y:       15
	0x00000078,       //t:       16
	0x0000003f,       //O:       17
	0x0000005c,       //o:       18
	0x0000006D,       //S:       19
	0x0000003e,       //U:       20
	0x0000001c,       //u:       21
	0x0000005e,       //d:       22
	0x00000073,       //P:       23
	0x00000054,       //n:       24	 
	0x00000079,       //E:       25	    
	0x00000071,       //F:       26
	0x0000003d,       //G:       27
	0x00000038,       //L:       28
	0x00000040,       //-:       29
	0x00000053,       //?:       30
	0x00000076,       //H:       31
	0x00000033,       //M1: [    32
	0x00000027,       //M2: ]    33
	0x00000054,       //m1: {    34
	0x00000054,       //m2: }    35
	0x0000003c,       //W1: (    36
	0x0000001e,       //W2: )    37
	0x00000080,		  //'.'      38
	0x00000000, 	  //' '	     39
	0x00000006,		  //I		40	
	0x000000FF,		  //'x' =8.    41
	0x00000008,		  //'_'     42
	0x0000006E,		//'Y'		43	
	0x00000063,		//'@' grau	44
	0x00000044,		//-|		45
	0x00000000 	  //' '	     

} ;

char const DPYMatrizSymbol[ ]={
	'0',                // 0
	'1',                // 1
	'2',                // 2
	'3',                // 3
	'4',                // 4
	'5',                // 5
	'6',                // 6
	'7',                // 7
	'8',                // 8
	'9',                // 9
	'A',                // 10
	'b',                // 11
	'C',                // 12
	'c',                // 13
	'r',                // 14
	'Y',                // 15
	't',                // 16
	'O',                // 17
	'o',                // 18
	'S',                // 19
	'U',                // 20
	'u',                // 21
	'd',                // 22
	'P',                // 23
	'n',                // 24
	'E',                // 25
	'F',                // 26
	'G',                // 27
	'L',                // 28
	'-',                // 29
	'?',                // 30
	'H',                // 31
	'[',  //M1          // 32
	']',  //M2          // 33
	'{',  //m1          // 34
	'}',  //m2          // 35
	')',  //W1          // 36
	'(',  //W2          // 37
	'p',  //'.'         // 38
	' ',  				// 39 
	'I',	  				// 40 
	'x',				//8. //41
	'_',				//42
	'Y',				//43
	'@',				//44
	'&',				//45
	' '  				// 46 deixar este como ultimo sempre

};
//OBS. :ao acrescentar novos simbolos, atualizar a rotina: WriteChar

void DisplayInit()
{
#if EQUIP==MD_EQUIP
	int i;
	CurrentDpy=0;
	for (i=0;i<12;i++)
	{
		DisplayChar[i]=0x000000FF; //todos os leds acessos...
		//DisplayChar[i]=0x00000000; //todos os leds apagados
	}
	//reseta os shift-registers (sobe, desce e fica baixo...)

	SETpinoEmPorta(0,DPY_RST_PIN);
	CLRpinoEmPorta(0,DPY_RST_PIN);
#endif 

#if EQUIP==TR_EQUIP
	ResetLcd();
	InitLcd();
	WrLcdCom(OffDsp);
	WrLcdCom(OnDsp);
	WrLcdCom(OffCur);
	GeraSimbolos();        //gera os simbolos para o LCD
#endif 

}

void WriteChar( WORD DpyNum, BYTE DPYchar,DWORD ponto)
{
	int i;

	for (i=0;i<46;i++)
	{
		if (DPYchar==DPYMatrizSymbol[i])
		{
			DisplayChar[DpyNum]=DPYMatrizCode[i]|ponto;
			break;
		}
	}

	/*if (DPYchar=='p')
	  {
	  DisplayChar[DpyNum]=ponto;
	  }*/

}



/*
   void WriteString(WORD posInicial, char str[])
   {
   int i,n;
   n=0;
   i=posInicial;
   while (i<12)
   {
   if (str[n]==0) 
   {
   break;
   } 
   else
   {
   if (str[n+1]=='*')  //se o proximo na string � o ponto, incluimos ele no desenho da tela 
   {
   WriteChar(i,str[n],COM_PONTO);
   n++; 
   }
   else
   {
   WriteChar(i,str[n],SEM_PONTO); 
   }
   n++;
   i++;	  
   }
   }
   }
 */
/*
   void WriteString(WORD posInicial, char *str,WORD tam)
   {
   WORD i,n;
   n=0;

   for (i=posInicial;i<tam;i++)
   {
   if (str[n]=='/') 
   {
   break;
   } 
   else
   {
   if (str[n+1]=='*')  //se o proximo na string � o ponto, incluimos ele no desenho da tela 
   {
   WriteChar(i,str[n],COM_PONTO);
   n++; 
   i--;	  
   }
   else
   {
   WriteChar(i,str[n],SEM_PONTO); 
   }
   n++;
   }
   }
   }
 */

void WriteBanner(BYTE posInicial, char str[])
{
	BYTE i;
	BannerPosition=posInicial;
	FlagHabBanner=OFF;
	BannerCharIndex=0;
	i=0;
	while (str[i]!=0) 
	{
		StrBanner[i]=str[i]; 
		i++;
	}	
	WriteString(posInicial,"    ");
	BannerSize=i;
	BannerCount=0;
	FlagHabBanner=ON;
}


void SkewBanner()
{
	BYTE i;
	char tstr[5];
	//char tstr[4];
	char *ptstr;


	tstr[4]=0;	//teste para solucionar o bug da ultima linha nas telas de programa��o.

	if (BannerCharIndex>(BannerSize))
	{
		BannerCharIndex=0;
	}

	for (i=0;i<4;i++)
	{	
		tstr[i]=StrBanner[i+BannerCharIndex];
		if ((i+BannerCharIndex)>=BannerSize)
		{
			tstr[i]=' ';
		}	
	}

	ptstr=&tstr[0];
	WriteString(BannerPosition,ptstr);
	BannerCharIndex++;
	FlagHabBanner=ON;
}


//char str[13]="01234567890/"; 
void WriteString(WORD posInicial, char *str)
{
	WORD i,n,i1=-1;
	n=0;

	//for (i=posInicial;i<tam;i++)
	for (i=posInicial;i<50;i++)
	{  
		i1++;
		if (str[n]==0) 
		{
			i1++;
			break;
		} 
		if ((i1+posInicial)>11) //se chegamos no ultimo display (11), sa�mos...
		{
			break;
		}

		else
		{
			if (str[n+1]=='.')  //se o proximo na string � o ponto, incluimos ele no desenho da tela 
			{
				WriteChar(i1+posInicial,str[n],COM_PONTO);
				n++; 		
			}
			else
			{
				WriteChar(i1+posInicial,str[n],SEM_PONTO); 
			}
			n++;
		}

	}
}



/*Nesta rotina, as energias sempre est�o em kilo!, o led kilo nao deve ser acesso apesar disso*/
void FloatToStrForEnergy(float numero, char *str )
{
	//a ideia � converter para BCD, e depois para string 
	unsigned long int numero_int;
	short milhar=0,centena=0,dezena=0,unidade=0,decimo=0,centesimo=0,milesimo=0,desmilesimo=0;
	short PosVirgula=0;
	float mul;
	//float numero2;


	//determina��o do sinal do n�mero.
	if (numero<0.0)
	{
		numero=-numero;
	}

	//determina��o da posicao da v�rgula e do fator de multiplicacao
	/////////////	
	if ((numero>0.0000001)&&((numero<=9.9999999)))
	{
		mul=1000.0; 
		PosVirgula=1;
	}
	/////////////	
	if ((numero>=1.0000000)&&((numero<=9.9999999)))
	{
		mul=1000.0; 
		PosVirgula=1;
	}
	/////////////	
	if ((numero>=10.000000)&&((numero<=99.999999)))
	{
		mul=100.0; 
		PosVirgula=2;
	}
	/////////////	
	if ((numero>=100.00000)&&((numero<=999.99999)))
	{
		mul=10.0; 
		PosVirgula=3;
	}
	/////////////	
	if ((numero>=1000.0000)&&((numero<=9999.9999)))
	{
		mul=1.0; 
		PosVirgula=4;
	}
	/////////////	
	if ((numero>=10000.000)&&((numero<=99999.999)))
	{
		mul=0.1; 
		PosVirgula=5;
	}
	/////////////	
	if ((numero>=100000.00)&&((numero<=999999.99)))
	{
		mul=0.01; 
		PosVirgula=6;

	}
	/////////////	
	if ((numero>=1000000.0)&&((numero<=9999999.9)))
	{
		mul=0.001; 
		PosVirgula=7;
	}
	/////////////	

	if (numero>10000000.0)
	{
		mul=0.0001; 
		PosVirgula=0;
		/**str='-'; str++; 
		 *str='-'; str++;
		 *str='-'; str++; 
		 *str='-'; str++;	
		 *str='-'; str++;	
		 *str='-'; str++;
		 *str='-'; str++;
		 *str='-';
		 return;	 */
	}

	numero_int=(unsigned long int)((mul*numero));
	milhar=numero_int/1000;
	centena=(numero_int-milhar*1000)/100;
	dezena= (numero_int-milhar*1000-centena*100)/10;
	unidade=(numero_int-milhar*1000-centena*100-dezena*10);

	numero_int=(unsigned long int)(((10000*numero)*mul-10000*(float)numero_int));
	//numero_int=(unsigned long int)((10000*(numero*mul-(float)numero_int)));
	decimo=(numero_int/1000);
	centesimo=(numero_int-decimo*1000)/100;
	milesimo=(numero_int-decimo*1000-centesimo*100)/10;
	desmilesimo=(numero_int-decimo*1000-centesimo*100-milesimo*10);


	//converte em 'char'

	if (PosVirgula==0) //NADA DE PONTO
	{ 
		*str=milhar+0x30; str++; 
		*str=centena+0x30; str++;
		*str=dezena+0x30; str++; 
		*str=unidade+0x30; str++;	
		*str=decimo+0x30; str++;
		*str=centesimo+0x30; str++;	
		*str=milesimo+0x30;	str++;
		*str=desmilesimo+0x30; str++;
	}
	if (PosVirgula==1)  
	{ 
		*str=milhar+0x30; str++; 
		*str='.'; str++; 
		*str=centena+0x30; str++;
		*str=dezena+0x30;  str++;
		*str=unidade+0x30;str++;	
		*str=decimo+0x30;str++;
		*str=centesimo+0x30; str++;	
		*str=milesimo+0x30;	str++;
		*str=desmilesimo+0x30; str++;

	}
	if (PosVirgula==2)  
	{ 
		*str=milhar+0x30; str++; 	    
		*str=centena+0x30; str++;
		*str='.'; str++; 
		*str=dezena+0x30;  str++;
		*str=unidade+0x30;	str++;
		*str=decimo+0x30;	str++;
		*str=centesimo+0x30; str++;
		*str=milesimo+0x30;	str++;
		*str=desmilesimo+0x30; str++;

	}
	if (PosVirgula==3)  
	{ 
		*str=milhar+0x30; str++; 
		*str=centena+0x30; str++;
		*str=dezena+0x30; str++;
		*str='.'; str++; 
		*str=unidade+0x30;str++;	
		*str=decimo+0x30;str++;	
		*str=centesimo+0x30; str++;
		*str=milesimo+0x30;	str++;
		*str=desmilesimo+0x30; str++;

	}

	if (PosVirgula==4)  
	{ 
		*str=milhar+0x30; str++; 
		*str=centena+0x30; str++;
		*str=dezena+0x30; str++;
		*str=unidade+0x30;str++;
		*str='.'; str++; 			
		*str=decimo+0x30;str++;
		*str=centesimo+0x30; str++;	
		*str=milesimo+0x30;	str++;
		*str=desmilesimo+0x30; str++;

	}

	if (PosVirgula==5)  
	{ 
		*str=milhar+0x30; str++; 
		*str=centena+0x30; str++;
		*str=dezena+0x30; str++;
		*str=unidade+0x30;str++;
		*str=decimo+0x30;str++;
		*str='.'; str++;
		*str=centesimo+0x30; str++;	
		*str=milesimo+0x30;	str++;
		*str=desmilesimo+0x30; str++;

	}

	if (PosVirgula==6)  
	{ 
		*str=milhar+0x30; str++; 
		*str=centena+0x30; str++;
		*str=dezena+0x30; str++;
		*str=unidade+0x30;str++;
		*str=decimo+0x30;str++;	
		*str=centesimo+0x30; str++;
		*str='.'; str++; 
		*str=milesimo+0x30;	str++;
		*str=desmilesimo+0x30; str++;

	}

	if (PosVirgula==7)  
	{ 
		*str=milhar+0x30; str++; 
		*str=centena+0x30; str++;
		*str=dezena+0x30; str++;
		*str=unidade+0x30;str++;
		*str=decimo+0x30;str++;
		*str=centesimo+0x30; str++;	
		*str=milesimo+0x30;	str++;
		*str='.'; str++; 
		*str=desmilesimo+0x30; str++;


	}

}

void FloatToStrForPulso(float numero, char *str )
{
	//a ideia � converter para BCD, e depois para string 
	unsigned long int numero_int;
	short milhar=0,centena=0,dezena=0,unidade=0,decimo=0,centesimo=0,milesimo=0,desmilesimo=0;
	short PosVirgula=0;
	float mul;
	//float numero2;


	//determina��o do sinal do n�mero.
	if (numero<0.0)
	{
		numero=-numero;
	}

	//determina��o da posicao da v�rgula e do fator de multiplicacao
	/////////////	
	if ((numero>0.0000001)&&((numero<=9.9999999)))
	{
		mul=1000.0; 
		PosVirgula=1;
	}
	/////////////	
	if ((numero>=1.0000000)&&((numero<=9.9999999)))
	{
		mul=1000.0; 
		PosVirgula=1;
	}
	/////////////	
	if ((numero>=10.000000)&&((numero<=99.999999)))
	{
		mul=100.0; 
		PosVirgula=2;
	}
	/////////////	
	if ((numero>=100.00000)&&((numero<=999.99999)))
	{
		mul=10.0; 
		PosVirgula=3;
	}
	/////////////	
	if ((numero>=1000.0000)&&((numero<=9999.9999)))
	{
		mul=1.0; 
		PosVirgula=4;
	}
	/////////////	
	if ((numero>=10000.000)&&((numero<=99999.999)))
	{
		mul=0.1; 
		PosVirgula=5;
	}
	/////////////	
	if ((numero>=100000.00)&&((numero<=999999.99)))
	{
		mul=0.01; 
		PosVirgula=6;

	}
	/////////////	
	if ((numero>=1000000.0)&&((numero<=9999999.9)))
	{
		mul=0.001; 
		PosVirgula=7;
	}
	/////////////	

	if (numero>10000000.0)
	{
		mul=0.0001; 
		PosVirgula=0;
		/**str='-'; str++; 
		 *str='-'; str++;
		 *str='-'; str++; 
		 *str='-'; str++;	
		 *str='-'; str++;	
		 *str='-'; str++;
		 *str='-'; str++;
		 *str='-';
		 return;	 */
	}

	numero_int=(unsigned long int)((mul*numero));
	milhar=numero_int/1000;
	centena=(numero_int-milhar*1000)/100;
	dezena= (numero_int-milhar*1000-centena*100)/10;
	unidade=(numero_int-milhar*1000-centena*100-dezena*10);

	numero_int=(unsigned long int)(((10000*numero)*mul-10000*(float)numero_int));
	//numero_int=(unsigned long int)((10000*(numero*mul-(float)numero_int)));
	decimo=(numero_int/1000);
	centesimo=(numero_int-decimo*1000)/100;
	milesimo=(numero_int-decimo*1000-centesimo*100)/10;
	if(milesimo==9)
	{
		centesimo++;
	}
	desmilesimo=0;//=(numero_int-decimo*1000-centesimo*100-milesimo*10);
	milesimo=0;

	//converte em 'char'

	if (PosVirgula==0) //NADA DE PONTO
	{ 
		*str=milhar+0x30; str++; 
		*str=centena+0x30; str++;
		*str=dezena+0x30; str++; 
		*str=unidade+0x30; str++;	
		*str=decimo+0x30; str++;
		*str=centesimo+0x30; str++;	
		*str=milesimo+0x30;	str++;
		*str=desmilesimo+0x30; str++;
	}
	if (PosVirgula==1)  
	{ 
		*str=milhar+0x30; str++; 
		*str='.'; str++; 
		*str=centena+0x30; str++;
		*str=dezena+0x30;  str++;
		*str=unidade+0x30;str++;	
		*str=decimo+0x30;str++;
		*str=centesimo+0x30; str++;	
		*str=milesimo+0x30;	str++;
		*str=desmilesimo+0x30; str++;

	}
	if (PosVirgula==2)  
	{ 
		*str=milhar+0x30; str++; 	    
		*str=centena+0x30; str++;
		*str='.'; str++; 
		*str=dezena+0x30;  str++;
		*str=unidade+0x30;	str++;
		*str=decimo+0x30;	str++;
		*str=centesimo+0x30; str++;
		*str=milesimo+0x30;	str++;
		*str=desmilesimo+0x30; str++;

	}
	if (PosVirgula==3)  
	{ 
		*str=milhar+0x30; str++; 
		*str=centena+0x30; str++;
		*str=dezena+0x30; str++;
		*str='.'; str++; 
		*str=unidade+0x30;str++;	
		*str=decimo+0x30;str++;	
		*str=centesimo+0x30; str++;
		*str=milesimo+0x30;	str++;
		*str=desmilesimo+0x30; str++;

	}

	if (PosVirgula==4)  
	{ 
		*str=milhar+0x30; str++; 
		*str=centena+0x30; str++;
		*str=dezena+0x30; str++;
		*str=unidade+0x30;str++;
		*str='.'; str++; 			
		*str=decimo+0x30;str++;
		*str=centesimo+0x30; str++;	
		*str=milesimo+0x30;	str++;
		*str=desmilesimo+0x30; str++;

	}

	if (PosVirgula==5)  
	{ 
		*str=milhar+0x30; str++; 
		*str=centena+0x30; str++;
		*str=dezena+0x30; str++;
		*str=unidade+0x30;str++;
		*str=decimo+0x30;str++;
		*str='.'; str++;
		*str=centesimo+0x30; str++;	
		*str=milesimo+0x30;	str++;
		*str=desmilesimo+0x30; str++;

	}

	if (PosVirgula==6)  
	{ 
		*str=milhar+0x30; str++; 
		*str=centena+0x30; str++;
		*str=dezena+0x30; str++;
		*str=unidade+0x30;str++;
		*str=decimo+0x30;str++;	
		*str=centesimo+0x30; str++;
		*str='.'; str++; 
		*str=milesimo+0x30;	str++;
		*str=desmilesimo+0x30; str++;

	}

	if (PosVirgula==7)  
	{ 
		*str=milhar+0x30; str++; 
		*str=centena+0x30; str++;
		*str=dezena+0x30; str++;
		*str=unidade+0x30;str++;
		*str=decimo+0x30;str++;
		*str=centesimo+0x30; str++;	
		*str=milesimo+0x30;	str++;
		*str='.'; str++; 
		*str=desmilesimo+0x30; str++;


	}

}

void IntToStr(short numero, char *str)
{
	//a ideia � converter para BCD, e depois para string 
	short milhar,centena,dezena,unidade;
	milhar=numero/1000;
	centena=(numero-milhar*1000)/100;
	dezena=(numero-milhar*1000-centena*100)/10;
	unidade=(numero-milhar*1000-centena*100-dezena*10);
	*str=milhar+0x30; str++; 
	*str=centena+0x30;str++;
	*str=dezena+0x30; str++; 
	*str=unidade+0x30;	
}

void IntToStr1(unsigned int numero, char *str)
{
	//a ideia � converter para BCD, e depois para string
	long int cemmilhar,dezmilhar, milhar,centena,dezena,unidade;

	cemmilhar=numero/100000;
	dezmilhar=(numero-cemmilhar*100000)/10000;
	milhar   =(numero-cemmilhar*100000-dezmilhar*10000)/1000;

	centena=(numero-cemmilhar*100000-dezmilhar*10000-milhar*1000)/100;
	dezena= (numero-cemmilhar*100000-dezmilhar*10000-milhar*1000-centena*100)/10;
	unidade=(numero-cemmilhar*100000-dezmilhar*10000-milhar*1000-centena*100-dezena*10);
	*str=cemmilhar+0x30; str++;
	*str=dezmilhar+0x30; str++;
	*str=milhar+0x30; str++;
	*str=centena+0x30;str++;
	*str=dezena+0x30; str++;
	*str=unidade+0x30;  str++;
	*str=0;
}


void FloatToStr(float numero, char *str, int *FlagKilo,int *FlagMenos)
{
	//a ideia � converter para BCD, e depois para string 
	WORD numero_int,milhar=0,centena=0,dezena=0,unidade=0;
	WORD mul=1, PosVirgula=0;
	*FlagKilo=0;

	memset(str, 0, 12);  //atenção: limpamos o buffer, que deve ter tamanho 12.


	if (numero<0)
	{
		*FlagMenos=1; 
		numero=-numero;
	}
	else
	{
		*FlagMenos=0;
	}

	if (numero>1000.0)
	{
		numero=numero/1000.0;
		*FlagKilo=1;
	}	 

	FlagEstouro=OFF;

	if (numero>=10000.0)	 //prever esta situa��o!!!
	{
		*str='-'; str++; 
		*str='-'; str++;
		*str='-'; str++; 
		*str='-';
		FlagEstouro=ON;
		return;
	}	


	if (numero>1.000)
	{
		if (numero<=9.999)
		{
			mul=1000; //formato X.XXX
			PosVirgula=1;
		}
	}
	else
	{		
		//formato de fator de potencia, ou miliamperes 0.XXX ou 1.000	 
		PosVirgula=1;
		if (numero<=1.000)
		{
			mul=1000;
		}
		//	 if (numero<1.000)
		//mul=1000;
	}

	if (numero>10.00)
	{
		if (numero<=99.99)
		{
			mul=100; //formato XX.XX
			PosVirgula=2;
		}
	}

	if (numero>100.0)
	{
		if (numero<=999.9)
		{
			mul=10; //formato XXX.X
			PosVirgula=3;
		}
	}

	if (numero>1000.0)
	{
		if (numero<=9999.0)
		{
			mul=1; //formato XXXX
			PosVirgula=0; //sem virgula;
		}

	}

	numero_int=(WORD)(mul*numero);
	milhar=numero_int/1000;
	centena=(numero_int-milhar*1000)/100;
	dezena=(numero_int-milhar*1000-centena*100)/10;
	unidade=(numero_int-milhar*1000-centena*100-dezena*10);

	//converte em 'char'

	if (PosVirgula==0) //NADA DE PONTO
	{ 
		*str=milhar+0x30; str++; 
		*str=centena+0x30; str++;
		*str=dezena+0x30; str++; 
		*str=unidade+0x30;	
	}
	if (PosVirgula==1)  
	{ 
		*str=milhar+0x30; str++; 
		*str='.'; str++; 
		*str=centena+0x30; str++;
		*str=dezena+0x30;  str++;
		*str=unidade+0x30;	
	}
	if (PosVirgula==2)  
	{ 
		*str=milhar+0x30; str++; 	    
		*str=centena+0x30; str++;
		*str='.'; str++; 
		*str=dezena+0x30;  str++;
		*str=unidade+0x30;	
	}
	if (PosVirgula==3)  
	{ 
		*str=milhar+0x30; str++; 
		*str=centena+0x30; str++;
		*str=dezena+0x30; str++;
		*str='.'; str++; 
		*str=unidade+0x30;	
	}
}

void setDpyPiscante(char PrimeiroDpyPiscante_, char UltimoDpyPiscante_)
{
	PrimeiroDpyPiscante=PrimeiroDpyPiscante_;
	UltimoDpyPiscante=UltimoDpyPiscante_;
	DpyPiscante=PrimeiroDpyPiscante;
}

#endif

