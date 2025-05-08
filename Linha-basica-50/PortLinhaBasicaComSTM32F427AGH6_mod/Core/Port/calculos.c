/*****************************************************************************
 *   principal.c:  Aqui se encontram as rotinas de c�lculo
 *
 *   Projeto MD2010-ARM
 *
 *   History
 *   2006.17.05  ver. codigo 1.00  Vers�o Preliminar.
 *
 *
 ******************************************************************************/
#define EXT extern
#include "global.h"




#if UTILIZAR_TABELA_DE_FORMA_DE_ONDA==1
short tabela[]={0,245,475,681,859,1007,1132,1240,1345,1452,1565,
	1687,1810,1924,2018,2080,2100,2080,2018,1924,1810,1687,1565,
	1452,1345,1240,1132,1007,859,681,475,245,2,-243,-473,-679,-857,
	-1005,-1130,-1238,-1343,-1450,-1563,-1685,-1808,-1922,-2016,-2078,
	-2100,-2078,-2016,-1922,-1808,-1685,-1563,-1450,-1343,-1238,-1130,
	-1005,-857,-679,-473,-243,0,245,475,681,859,1007,1132,1240,1345,
	1452,1565,1687,1810,1924,2018,2080,2100,2080,2018,1924,1810,
	1687,1565,1452,1345,1240,1132,1007,859,681,475,245,2,-243,-473,
	-679,-857,-1005,-1130,-1238,-1343,-1450,-1563,-1685,-1808,-1922,
	-2016,-2078,-2100,-2078,-2016,-1922,-1808,-1685,-1563,-1450,
	-1343,-1238,-1130,-1005,-857,-679,-473,-243,0,245,475,681,
	859,1007,1132,1240,1345,1452,1565,1687,1810,1924,2018,2080,
	2100,2080,2018,1924,1810,1687,1565,1452,1345,1240,1132,1007,
	859,681,475,245,2,-243,-473,-679,-857,-1005,-1130,-1238,-1343,
	-1450,-1563,-1685,-1808,-1922,-2016,-2078,-2100,-2078,-2016,
	-1922,-1808,-1685,-1563,-1450,-1343,-1238,-1130,-1005,-857,
	-679,-473,-243,0,245,475,681,859,1007,1132,1240,1345,1452,
	1565,1687,1810,1924,2018,2080,2100,2080,2018,1924,1810,1687,
	1565,1452,1345,1240,1132,1007,859,681,475,245,2,-243,-473,
	-679,-857,-1005,-1130,-1238,-1343,-1450,-1563,-1685,-1808,
	-1922,-2016,-2078,-2100,-2078,-2016,-1922,-1808,-1685,
	-1563,-1450,-1343,-1238,-1130,-1005,-857,-679,-473,-243,0,245,475,
	681,859,1007,1132,1240,1345,1452,1565,1687,1810,1924,2018,2080,
	2100,2080,2018,1924,1810,1687,1565,1452,1345,1240,1132,1007,859,
	681,475,245,2,-243,-473,-679,-857,-1005,-1130,-1238,-1343,-1450,
	-1563,-1685,-1808,-1922,-2016,-2078,-2100,-2078,-2016,-1922,-1808,
	-1685,-1563,-1450,-1343,-1238,-1130,-1005,-857,-679,-473,-243,
	0,245,475,681,859,1007,1132,1240,1345,1452,1565,1687,1810,1924,
	2018,2080,2100,2080,2018,1924,1810,1687,1565,1452,1345,1240,1132,
	1007,859,681,475,245,2,-243,-473,-679,-857,-1005,-1130,-1238,
	-1343,-1450,-1563,-1685,-1808,-1922,-2016,-2078,-2100,-2078,
	-2016,-1922,-1808,-1685,-1563,-1450,-1343,-1238,-1130,-1005,
	-857,-679,-473,-243,0,245,475,681,859,1007,1132,1240,1345,1452,
	1565,1687,18,10,1924,2018,2080,2100,2080,2018,1924,1810,1687,
	1565,1452,1345,1240,1132,1007,859,681,475,245,2,-243,-473,
	-679,-857,-1005,-1130,-1238,-1343,-1450,-1563,-1685,-1808,-1922,
	-2016,-2078,-2100,-2078,-2016,-1922,-1808,-1685,-1563,-1450,-1343,
	-1238,-1130,-1005,-857,-679,-473,-243,0,245,475,681,859,1007,1132,
	1240,1345,1452,1565,1687,1810,1924,2018,2080,2100,2080,2018,
	1924,1810,1687,1565,1452,1345,1240,1132,1007,859,681,475,245,2,
	-243,-473,-679,-857,-1005,-1130,-1238,-1343,-1450,-1563,-1685,
	-1808,-1922,-2016,-2078,-2100,-2078,-2016,-1922,-1808,-1685,
	-1563,-1450,-1343,-1238,-1130,-1005,-857,-679,-473,-243,0,245,
	475,681,859,1007,1132,1240,1345,1452,1565,1687,1810,1924,2018,
	2080,2100,2080,2018,1924,1810,1687,1565,1452,1345,1240,1132,1007,
	859,681,475,245,2,-243,-473,-679,-857,-1005,-1130,-1238,-1343,
	-1450,-1563,-1685,-1808,-1922,-2016,-2078,-2100,-2078,-2016,-1922,
	-1808,-1685,-1563,-1450,-1343,-1238,-1130,-1005,-857,-679,-473,
	-243,0,245,475,681,859,1007,1132,1240,1345,1452,1565,1687,1810,
	1924,2018,2080,2100,2080,2018,1924,1810,1687,1565,1452,1345,1240,
	1132,1007,859,681,475,245,2,-243,-473,-679,-857,-1005,-1130,
	-1238,-1343,-1450,-1563,-1685,-1808,-1922,-2016,-2078,-2100,
	-2078,-2016,-1922,-1808,-1685,-1563,-1450,-1343,-1238,-1130,
	-1005,-857,-679,-473,-243,0,245,475,681,859,1007,1132,1240,1345,
	1452,1565,1687,1810,1924,2018,2080,2100,2080,2018,1924,1810,1687,
	1565,1452,1345,1240,1132,1007,859,681,475,245,2,-243,-473,-679,
	-857,-1005,-1130,-1238,-1343,-1450,-1563,-1685,-1808,-1922,-2016,
	-2078,-2100,-2078,-2016,-1922,-1808,-1685,-1563,-1450,-1343,-1238,
	-1130,-1005,-857,-679,-473,-243,0,245,475,681,859,1007,1132,1240,1345,1452,1565,1687,
	1810,1924,2018,2080,2100,2080,2018,1924,1810,1687,1565,1452,1345,1240,1132,1007,859,681,
	475,245,2,-243,-473,-679,-857,-1005,-1130,-1238,-1343,-1450,-1563,-1685,-1808,-1922,-2016,
	-2078,-2100,-2078,-2016,-1922,-1808,-1685,-1563,-1450,-1343,-1238,-1130,-1005,-857,-679,
	-473,-243
};
#endif


const short h[]={
	-693,-604,-499,-375,-231,-67,120,329,560,813,1087,1383,1697,2028,2374,2732,3099,3471,
	3844,4213,4575,4924,5255,5563,5842,6088,6296,6460,6575,6638,6644,6590,6472,6289,6038,
	5719,5331,4875,4351,3764,3114,2407,1646,838,-12,-896,-1806,-2736,-3675,-4615,-5547,-6461,
	-7346,-8194,-8994,-9738,-10416,-11020,-11542,-11973,-12308,-12542,-12668,-12684,-12587,
	-12374,-12047,-11605,-11051,-10388,-9620,-8753,-7794,-6751,-5631,-4445,-3204,-1918,-599,741,
	2088,3431,4756,6051,7302,8499,9628,10680,11643,12507,13265,13909,14432,14829,15095,15230,
	15230,15095,14829,14432,13909,13265,12507,11643,10680,9628,8499,7302,6051,4756,3431,2088,
	741,-599,-1918,-3204,-4445,-5631,-6751,-7794,-8753,-9620,-10388,-11051,-11605,-12047,-12374,-12587,
	-12684,-12668,-12542,-12308,-11973,-11542,-11020,-10416,-9738,-8994,-8194,-7346,-6461,-5547,-4615,
	-3675,-2736,-1806,-896,-12,838,1646,2407,3114,3764,4351,4875,5331,5719,6038,6289,6472,6590,6644,
	6638,6575,6460,6296,6088,5842,5563,5255,4924,4575,4213,3844,3471,3099,2732,2374,2028,1697,
	1383,1087,813,560,329,120,-67,-231,-375,-499,-604,-693,
};
#define TAM_FILTRO (short)sizeof(h)/2


const short kernelCr[]={
	30000,29856,29424,28708,27716,26458,24944,23190,21213,19032,16667,14142,11481,8709,5853,2941,0,-2941,-5853,-8709,-11481,-14142,-16667,-19032,-21213,-23190,-24944,-26458,-27716,-28708,-29424,-29856,-30000,-29856,-29424,-28708,-27716,-26458,-24944,-23190,-21213,-19032,-16667,-14142,-11481,-8709,-5853,-2941,0,2941,5853,8709,11481,14142,16667,19032,21213,23190,24944,26458,27716,28708,29424,29856
};

const short kernelSr[]={
	0,2941,5853,8709,11481,14142,16667,19032,21213,23190,24944,26458,27716,28708,29424,29856,30000,29856,29424,28708,27716,26458,24944,23190,21213,19032,16667,14142,11481,8709,5853,2941,0,-2941,-5853,-8709,-11481,-14142,-16667,-19032,-21213,-23190,-24944,-26458,-27716,-28708,-29424,-29856,-30000,-29856,-29424,-28708,-27716,-26458,-24944,-23190,-21213,-19032,-16667,-14142,-11481,-8709,-5853,-2941
};

const short kernelCr50Hz[]=
{
	30000 ,   29900,   29599,  29101,  28408,
	27525 ,   26458,   25213,  23801,  22229,
	20508 ,   18650,   16667,  14573,  12381,
	10107 ,    7765,    5371,   2941,    491,
	-1962 ,   -4402,   -6812,  -9177, -11481,
	-13707 ,  -15842,  -17871, -19780, -21557,
	-23190 ,  -24668,  -25981, -27120, -28077,
	-28847 ,  -29424,  -29803, -29984, -29964,
	-29743 ,  -29324,  -28708, -27901, -26906,
	-25732 ,  -24385,  -22876, -21213, -19409,
	-17474 ,  -15423,  -13269, -11025,  -8709,
	-6333 ,   -3916,   -1472,    982,   3429,
	5853 ,    8238,   10568,  12827,  15000,
	17073 ,   19032,   20863,  22555,  24096,
	25476 ,   26685,   27716,  28562,  29216,
	29675 ,   29936 };


const short kernelSr50Hz[]=
{          0,   2452,   4887,   7289,   9643,
	11932,  14142,  16257,  18263,  20147,
	21896,  23499,  24944,  26223,  27326,
	28246,  28978,  29515,  29856,  29996,
	29936,  29675,  29216,  28562,  27716,
	26685,  25476,  24096,  22555,  20863,
	19032,  17073,  15000,  12827,  10568,
	8238,   5853,   3429,    982,  -1472,
	-3916,  -6333,  -8709, -11025, -13269,
	-15423, -17474, -19409, -21213, -22876,
	-24385, -25732, -26906, -27901, -28708,
	-29324, -29743, -29964, -29984, -29803,
	-29424, -28847, -28077, -27120, -25981,
	-24668, -23190, -21557, -19780, -17871,
	-15842, -13707, -11481,  -9177,  -6812,
	-4402,  -1962 };

#define TAMANHO_DO_KERNEL_60Hz 64
#define TAMANHO_DO_KERNEL_50Hz 77

float DhtIA1;
float DhtIB1;
float DhtIC1;

float Sign(float numero)
{
	if (numero<0.0)
	{
		return(0.0);
	}
	else
	{
		return(numero);
	}
}

void AcumulaPotenciasNow(float Pot, float *GNowPos, float *GNowNeg)
{
	if (Pot>=0.0)
	{
		*GNowPos=fabs(Pot*0.000277777777777778);
		*GNowNeg=0.0;
	}
	else
	{
		*GNowPos=0.0;
		*GNowNeg=fabs(Pot*0.000277777777777778);
	}
}

/*****************************************************************************
 **                            End Of File
 *****************************************************************************/
#if UTILIZAR_TABELA_DE_FORMA_DE_ONDA==SIM
void CarregaBuffer(void)
{
	short n;

	//x1=round(seno(2000,0,N,f,fs));
	//x=x1+round(seno(0.08*2000,0,N,3*f,fs)+seno(0.1*2000,00,N,5*f,fs));
	FrequenciaNominal=60;
	// for(n=0;n<TAM_BUFFER;n++)
	for(n=0;n<TAM_BUFFER_CIRCULAR;n++)

	{
		/*
		   Ua[n]=tabela[n];//ceil(2000*sin(2.0*3.14159265358979*FrequenciaNominal*n/3840.0))+ceil(100*sin(2.0*3.14159265358979*FrequenciaNominal*5*n/3840.0));
		   Ub[n]=Ua[n];
		   Uc[n]=Ua[n];
		   Ia[n]=Ua[n];
		   Ib[n]=Ua[n];
		   Ic[n]=Ua[n];
		 */
		Ua[n]=ceil(511*sin(2.0*3.14159265358979*FrequenciaNominal*n/3840.0));
		Ub[n]=Ua[n];
		Uc[n]=Ua[n];
		Ia[n]=ceil(511*sin(2.0*3.14159265358979*FrequenciaNominal*n/3840.0+0.785398163397448));
		Ib[n]=ceil(511*sin(2.0*3.14159265358979*FrequenciaNominal*n/3840.0-0.785398163397448));
		Ic[n]=Ua[n];
	}


}
#endif

void ResgistrarIntervalo15minAgora()
{
	PotAtivPonta15min		= PotAtivPonta15minAcc			;
	PotAtivForaPonta15min	= PotAtivForaPonta15minAcc		;
	PotAtivReserv15min		= PotAtivReserv15minAcc			;
	PotReatPonta15min		= PotReatPonta15minAcc			;
	PotReatForaPonta15min	= PotReatForaPonta15minAcc		;
	PotReatReserv15min		= PotReatReserv15minAcc			;

	EnergGerPonta15min		= EnergGerPonta15minAcc		;
	EnergGerForaPonta15min	= EnergGerForaPonta15minAcc	;
	EnergGerReserv15min 	= EnergGerReserv15minAcc	;
	ConsumoPonta15min 		= ConsumoPonta15minAcc		;
	ConsumoForaPonta15min	= ConsumoForaPonta15minAcc	;
	ConsumoReserv15min 	= ConsumoReserv15minAcc			;

	EnergIndPonta15min		= EnergIndPonta15minAcc		;
	EnergIndForaPonta15min	= EnergIndForaPonta15minAcc	;
	EnergIndReserv15min 	= EnergIndReserv15minAcc 	;
	EnergCapPonta15min		= EnergCapPonta15minAcc		;
	EnergCapForaPonta15min	= EnergCapForaPonta15minAcc	;
	EnergCapReserv15min 	= EnergCapReserv15minAcc 	;

	switch (TipoDeHorario)
	{
		case HORARIO_PONTA:
			{
				if (PotAtivPonta15min>MaxPotAtivPontaEsteMesAteAgora)
					{MaxPotAtivPontaEsteMesAteAgora=PotAtivPonta15min;}
				if (PotReatPonta15min>MaxPotReatPontaEsteMesAteAgora)
					{MaxPotReatPontaEsteMesAteAgora=PotReatPonta15min;}
				if (PotAtivPonta15min>MaxPotAtivPonta)
					{MaxPotAtivPonta=PotAtivPonta15min;}
				if (PotReatPonta15min>MaxPotReatPonta)
					{MaxPotReatPonta=PotReatPonta15min;}
				if (PotAtivPonta15min>MaxPotAtivPontaHojeAteAgora)
					{MaxPotAtivPontaHojeAteAgora=PotAtivPonta15min;}
				if (PotReatPonta15min>MaxPotReatPontaHojeAteAgora)
					{MaxPotReatPontaHojeAteAgora=PotReatPonta15min;}

				if (PotAtivPonta15min>Lista1DeMaxPotAtivPontaNesteMesAteAgora[3])
				{
					Lista1DeMaxPotAtivPontaNesteMesAteAgora[3]=PotAtivPonta15min;
					RTCtoMesDiaHoraMin(&MesDiaLista1[3], &HoraMinLista1[3]);
					ReorganizaLista(&Lista1DeMaxPotAtivPontaNesteMesAteAgora[0], &MesDiaLista1[0], &HoraMinLista1[0]);
				}

				if (PotReatPonta15min>Lista4DeMaxPotReatPontaNesteMesAteAgora[3])
				{
					Lista4DeMaxPotReatPontaNesteMesAteAgora[3]=PotReatPonta15min;
					RTCtoMesDiaHoraMin(&MesDiaLista4[3], &HoraMinLista4[3]);
					ReorganizaLista(&Lista4DeMaxPotReatPontaNesteMesAteAgora[0], &MesDiaLista4[0], &HoraMinLista4[0]);
				}



				break;
			}
		case HORARIO_FORA_PONTA:
			{
				if (PotAtivForaPonta15min>MaxPotAtivForaPontaEsteMesAteAgora)
					{MaxPotAtivForaPontaEsteMesAteAgora=PotAtivForaPonta15min;}
				if (PotReatForaPonta15min>MaxPotReatForaPontaEsteMesAteAgora)
					{MaxPotReatForaPontaEsteMesAteAgora=PotReatForaPonta15min;}
				if (PotAtivForaPonta15min>MaxPotAtivForaPonta)
					{MaxPotAtivForaPonta=PotAtivForaPonta15min;}
				if (PotReatForaPonta15min>MaxPotReatForaPonta)
					{MaxPotReatForaPonta=PotReatForaPonta15min;}
				if (PotAtivForaPonta15min>MaxPotAtivForaPontaHojeAteAgora)
					{MaxPotAtivForaPontaHojeAteAgora=PotAtivForaPonta15min;}
				if (PotReatForaPonta15min>MaxPotReatForaPontaHojeAteAgora)
					{MaxPotReatForaPontaHojeAteAgora=PotReatForaPonta15min;}

				if (PotAtivForaPonta15min>Lista2DeMaxPotAtivForaPontaNesteMesAteAgora[3])
				{
					Lista2DeMaxPotAtivForaPontaNesteMesAteAgora[3]=PotAtivForaPonta15min;
					RTCtoMesDiaHoraMin(&MesDiaLista2[3], &HoraMinLista2[3]);
					ReorganizaLista(&Lista2DeMaxPotAtivForaPontaNesteMesAteAgora[0],&MesDiaLista2[0],&HoraMinLista2[0]);
				}

				if (PotReatForaPonta15min>Lista5DeMaxPotReatForaPontaNesteMesAteAgora[3])
				{
					Lista5DeMaxPotReatForaPontaNesteMesAteAgora[3]=PotReatForaPonta15min;
					RTCtoMesDiaHoraMin(&MesDiaLista5[3], &HoraMinLista5[3]);
					ReorganizaLista(&Lista5DeMaxPotReatForaPontaNesteMesAteAgora[0],&MesDiaLista5[0],&HoraMinLista5[0]);
				}

				break;
			}
		case HORARIO_RESERVADO:
			{
				if (PotAtivReserv15min>MaxPotAtivReservEsteMesAteAgora)
					{MaxPotAtivReservEsteMesAteAgora=PotAtivReserv15min;}
				if (PotReatReserv15min>MaxPotReatReservEsteMesAteAgora)
					{MaxPotReatReservEsteMesAteAgora=PotReatReserv15min;}
				if (PotAtivReserv15min>MaxPotAtivReserv)
					{MaxPotAtivReserv=PotAtivReserv15min;}
				if (PotReatReserv15min>MaxPotReatReserv)
					{MaxPotReatReserv=PotReatReserv15min;}
				if (PotAtivReserv15min>MaxPotAtivReservHojeAteAgora)
					{MaxPotAtivReservHojeAteAgora=PotAtivReserv15min;}
				if (PotReatReserv15min>MaxPotReatReservHojeAteAgora)
					{MaxPotReatReservHojeAteAgora=PotReatReserv15min;}

				if (PotAtivReserv15min>Lista3DeMaxPotAtivReservNesteMesAteAgora[3])
				{
					Lista3DeMaxPotAtivReservNesteMesAteAgora[3]=PotAtivReserv15min;
					RTCtoMesDiaHoraMin(&MesDiaLista3[3], &HoraMinLista3[3]);
					ReorganizaLista(&Lista3DeMaxPotAtivReservNesteMesAteAgora[0],&MesDiaLista3[0],&HoraMinLista3[0]);
				}

				if (PotReatReserv15min>Lista6DeMaxPotReatReservNesteMesAteAgora[3])
				{
					Lista6DeMaxPotReatReservNesteMesAteAgora[3]=PotReatReserv15min;
					RTCtoMesDiaHoraMin(&MesDiaLista6[3], &HoraMinLista6[3]);
					ReorganizaLista(&Lista6DeMaxPotReatReservNesteMesAteAgora[0],&MesDiaLista6[0],&HoraMinLista6[0]);
				}

				break;
			}
		case HORARIO_NULO:
			{

				break;
			}
	}

	Zera15minAcc();
}

void Zera15min()
{
	PotAtivPonta15min		= 0;
	PotAtivForaPonta15min	= 0;
	PotAtivReserv15min		= 0;
	PotReatPonta15min		= 0;
	PotReatForaPonta15min	= 0;
	PotReatReserv15min		= 0;
	EnergGerPonta15min		= 0;
	EnergGerForaPonta15min	= 0;
	EnergGerReserv15min		= 0;
	ConsumoPonta15min		= 0;
	ConsumoForaPonta15min	= 0;
	ConsumoReserv15min		= 0;
	EnergIndPonta15min		= 0;
	EnergIndForaPonta15min	= 0;
	EnergIndReserv15min		= 0;
	EnergCapPonta15min		= 0;
	EnergCapForaPonta15min	= 0;
	EnergCapReserv15min		= 0;
}

void Zera15minAcc()
{
	nPontosMedia=0; //zera o contador de pontos para media.
	PotAtivPonta15minAcc		= 0;
	PotAtivForaPonta15minAcc	= 0;
	PotAtivReserv15minAcc		= 0;
	PotReatPonta15minAcc		= 0;
	PotReatForaPonta15minAcc	= 0;
	PotReatReserv15minAcc		= 0;
	EnergGerPonta15minAcc		= 0;
	EnergGerForaPonta15minAcc	= 0;
	EnergGerReserv15minAcc		= 0;
	ConsumoPonta15minAcc		= 0;
	ConsumoForaPonta15minAcc	= 0;
	ConsumoReserv15minAcc		= 0;
	EnergIndPonta15minAcc		= 0;
	EnergIndForaPonta15minAcc	= 0;
	EnergIndReserv15minAcc		= 0;
	EnergCapPonta15minAcc		= 0;
	EnergCapForaPonta15minAcc	= 0;
	EnergCapReserv15minAcc		= 0;
}

/*************************************************************************
  Rotina que calcula o proximo momento de avalia��o de intervalo de 1min
 **************************************************************************/
void MomentoDeAvaliacaoDeIntervalo1min()
{


	RTCTime LocalTime;

	AcumulaGrandezaMM();




#undef ACELERAR_FUNCIONA
//#define ACELERAR_FUNCIONA

	LocalTime=RTCGetTime();
#ifdef ACELERAR_FUNCIONA
	if (LocalTime.RTC_Sec>2)
		if (LocalTime.RTC_Sec<58)
		{
			LocalTime.RTC_Sec=58;
			RTCSetTime(LocalTime );

		}
#endif
	//Verificamos se estamos no minuto de avalia��o
#if ACELERAR_1SEG==NAO
	if (LocalTime.RTC_Min==ProximoIniciodeIntervalo1Min)
	{
		ProximoIniciodeIntervalo1Min=LocalTime.RTC_Min+1;

		if (ProximoIniciodeIntervalo1Min==60)
		{
			ProximoIniciodeIntervalo1Min=0;
		}
		Cnt1min++;

		if (NumeroDeIntervalos1minParaProximoRegistro==Cnt1min )
		{

			Cnt1min=0;
			NumeroDeIntervalos1minParaProximoRegistro=tMMgrandezas;

			CalculaGrandezaMM();

			if (RegistroCabecalho2K.FlagProximoRegistroSeraComRTC==SIM)
			{
#if (USAR_REGISTRO_SHORT==SIM)
				GravaNaBatteryRAM(REG_BATT_MEM_SHORT_COM_RTC);
#else
				GravaNaBatteryRAM(REG_BATT_MEM_NORM_COM_RTC);
#endif
				RegistroCabecalho2K.FlagProximoRegistroSeraComRTC=NAO;
			}
			else
			{
#if (USAR_REGISTRO_SHORT==SIM)
				GravaNaBatteryRAM(REG_BATT_MEM_SHORT_SEM_RTC);
#else
				GravaNaBatteryRAM(REG_BATT_MEM_NORM_SEM_RTC);
#endif
			}
		}
	}
#else
	CalculaGrandezaMM();

	if (RegistroCabecalho2K.FlagProximoRegistroSeraComRTC==SIM)
	{
#if (USAR_REGISTRO_SHORT==SIM)
		GravaNaBatteryRAM(REG_BATT_MEM_SHORT_COM_RTC);
#else
		GravaNaBatteryRAM(REG_BATT_MEM_NORM_COM_RTC);
#endif
		RegistroCabecalho2K.FlagProximoRegistroSeraComRTC=NAO;
	}
	else
	{
#if (USAR_REGISTRO_SHORT==SIM)
		GravaNaBatteryRAM(REG_BATT_MEM_SHORT_SEM_RTC);
#else
		GravaNaBatteryRAM(REG_BATT_MEM_NORM_SEM_RTC);
#endif
	}
#endif

}

/*************************************************************************
  Rotina que calcula o proximo momento de avalia��o de intervalo de 15min
 **************************************************************************/
void MomentoDeAvaliacaoDeIntervalo15min()
{
unsigned int t;
//#undef ACELERA15MIN
//#define ACELERA15MIN ON
#define AceleradorTeste ACELERA15MIN


	RTCTime LocalTime;

	if(tMMgrandezas==15)
	{
		AcumulaGrandezaMM();
	}

	LocalTime=RTCGetTime();











	//Verificamos se estamos no minuto de avalia��o
#if (AceleradorTeste==ON)
	if ((LocalTime.RTC_Sec==0)||(LocalTime.RTC_Sec==15)||(LocalTime.RTC_Sec==30)||(LocalTime.RTC_Sec==45))
	{
		if (JaRegistrouNoIntervalode15Min==NAO)
		{
			FLAG_HORACHEIA=SIM;
			JaRegistrouNoIntervalode15Min=SIM;
			ProximoIniciodeIntervalo=LocalTime.RTC_Sec+2;
			ResgistrarIntervalo15minAgora();
		}
	}
	//Verificamos se estamos ja passamos o minuto de avalia��o
	if (LocalTime.RTC_Sec>ProximoIniciodeIntervalo)
	{
		JaRegistrouNoIntervalode15Min=NAO;
	}
	if(tMMgrandezas==15)
	{
		CalculaGrandezaMM( );

		if (RegistroCabecalho2K.FlagProximoRegistroSeraComRTC==SIM)
		{
#if (USAR_REGISTRO_SHORT==SIM)
			GravaNaBatteryRAM(REG_BATT_MEM_SHORT_COM_RTC);
#else
			GravaNaBatteryRAM(REG_BATT_MEM_NORM_COM_RTC);
#endif
			RegistroCabecalho2K.FlagProximoRegistroSeraComRTC=NAO;
		}
		else
		{
#if (USAR_REGISTRO_SHORT==SIM)
			GravaNaBatteryRAM(REG_BATT_MEM_SHORT_SEM_RTC);
#else
			GravaNaBatteryRAM(REG_BATT_MEM_NORM_SEM_RTC);
#endif
		}
	}
#else

	#if MD4040TI==1
	#ifdef MODELO_EARHT
	//faltando 1 minuto para a hora cheia de 15min, fazemos uma leitura no RHT
	if ((LocalTime.RTC_Min==59)||(LocalTime.RTC_Min==14)||(LocalTime.RTC_Min==29)||(LocalTime.RTC_Min==44))
	{

		if(StatusFuncaoFinal[1]==0)// StatusFuncao[1]=0 >>> temp e humidade ....  StatusFuncao[21]!=0 >>> 2 temperaturas
		{
			if (MMFp3Acc==0.0) //usando  	MMFp3Acc como um flag
			{
				//enviando pacote modbus master para o RHT
				short index=0,OldCrc=0xFFFF;
				MMFp = 0.0;
		/*
		pergunta
		01
		03
		00
		07
		00
		02
		crc
		crc
		*/
				FIO0SET=HABSER_PIN;		// (desabilita recepcao...)

				for (t=0;t<10000;t++);
				UART0Buffer[index]  =0;
				#ifdef  MODELO_S501
					UART0Buffer[index] =MeuEnderecoMODBUS+1; OldCrc=CalcCRC(OldCrc,UART0Buffer[index]); index++;
					UART0Buffer[index]	=3;	OldCrc=CalcCRC(OldCrc,UART0Buffer[index]); index++;
					UART0Buffer[index]	=0; OldCrc=CalcCRC(OldCrc,UART0Buffer[index]); index++;
					UART0Buffer[index]	=0; OldCrc=CalcCRC(OldCrc,UART0Buffer[index]); index++;
					UART0Buffer[index]	=0; OldCrc=CalcCRC(OldCrc,UART0Buffer[index]); index++;
					UART0Buffer[index]	=2; OldCrc=CalcCRC(OldCrc,UART0Buffer[index]); index++;
				#else
					UART0Buffer[index] =MeuEnderecoMODBUS+1; OldCrc=CalcCRC(OldCrc,UART0Buffer[index]); index++;
					UART0Buffer[index]	=3;	OldCrc=CalcCRC(OldCrc,UART0Buffer[index]); index++;
					UART0Buffer[index]	=0; OldCrc=CalcCRC(OldCrc,UART0Buffer[index]); index++;
					UART0Buffer[index]	=7; OldCrc=CalcCRC(OldCrc,UART0Buffer[index]); index++;
					UART0Buffer[index]	=0; OldCrc=CalcCRC(OldCrc,UART0Buffer[index]); index++;
					UART0Buffer[index]	=2; OldCrc=CalcCRC(OldCrc,UART0Buffer[index]); index++;
				#endif

					UART0Buffer[index] = ((OldCrc >> 8) & 0x00FF);	index++;
					UART0Buffer[index] = (OldCrc & 0x00FF);	index++;
					ContSilencioMODBUS=0;
					UARTSendOnly((BYTE *)&UART0Buffer,index);
					FIO0CLR=HABSER_PIN;  // (habilita recepcao...)
			}
		}
		else
		{
						//enviando pacote modbus master para o RHT
				if 	(MMFp3Acc==0.0) //usando  	MMFp3Acc como um flag
				{
					short index=0,OldCrc=0xFFFF;

					MMFp = 0.0;
					FIO0SET=HABSER_PIN;  // (desabilita recepcao...)

					for (t=0;t<10000;t++);
					UART0Buffer[index]  =0;
					#ifdef  MODELO_S501
						UART0Buffer[index]  =MeuEnderecoMODBUS+1; OldCrc=CalcCRC(OldCrc,UART0Buffer[index]); index++;
						UART0Buffer[index]	=3;	OldCrc=CalcCRC(OldCrc,UART0Buffer[index]); index++;
						UART0Buffer[index]	=0; OldCrc=CalcCRC(OldCrc,UART0Buffer[index]); index++;
						UART0Buffer[index]	=0; OldCrc=CalcCRC(OldCrc,UART0Buffer[index]); index++;
						UART0Buffer[index]	=0; OldCrc=CalcCRC(OldCrc,UART0Buffer[index]); index++;
						UART0Buffer[index]	=2; OldCrc=CalcCRC(OldCrc,UART0Buffer[index]); index++;
					#else
						UART0Buffer[index]  =MeuEnderecoMODBUS+1; OldCrc=CalcCRC(OldCrc,UART0Buffer[index]); index++;
						UART0Buffer[index]	=3;	OldCrc=CalcCRC(OldCrc,UART0Buffer[index]); index++;
						UART0Buffer[index]	=0; OldCrc=CalcCRC(OldCrc,UART0Buffer[index]); index++;
						UART0Buffer[index]	=7; OldCrc=CalcCRC(OldCrc,UART0Buffer[index]); index++;
						UART0Buffer[index]	=0; OldCrc=CalcCRC(OldCrc,UART0Buffer[index]); index++;
						UART0Buffer[index]	=2; OldCrc=CalcCRC(OldCrc,UART0Buffer[index]); index++;
					#endif

					UART0Buffer[index] = ((OldCrc >> 8) & 0x00FF);	index++;
					UART0Buffer[index] = (OldCrc & 0x00FF);	index++;

					ContSilencioMODBUS=0;
					UARTSendOnly((BYTE *)&UART0Buffer,index);

					FIO0CLR=HABSER_PIN;  // (habilita recepcao...)
				}
				else
				if (MMFp3Acc==1.00) //usando  	MMFp3Acc como um flag
				{

					short index=0,OldCrc=0xFFFF;

					for (t=0;t<10000;t++);
					FIO0SET=HABSER_PIN; // (desabilita recepcao...)

					for (t=0;t<10000;t++);
					UART0Buffer[index] =0;
					#ifdef  MODELO_S501
						UART0Buffer[index]  =MeuEnderecoMODBUS+2; OldCrc=CalcCRC(OldCrc,UART0Buffer[index]); index++;
						UART0Buffer[index]	=3;	OldCrc=CalcCRC(OldCrc,UART0Buffer[index]); index++;
						UART0Buffer[index]	=0; OldCrc=CalcCRC(OldCrc,UART0Buffer[index]); index++;
						UART0Buffer[index]	=0; OldCrc=CalcCRC(OldCrc,UART0Buffer[index]); index++;
						UART0Buffer[index]	=0; OldCrc=CalcCRC(OldCrc,UART0Buffer[index]); index++;
						UART0Buffer[index]	=2; OldCrc=CalcCRC(OldCrc,UART0Buffer[index]); index++;
					#else
						UART0Buffer[index]  =MeuEnderecoMODBUS+2; OldCrc=CalcCRC(OldCrc,UART0Buffer[index]); index++;
						UART0Buffer[index]	=3;	OldCrc=CalcCRC(OldCrc,UART0Buffer[index]); index++;
						UART0Buffer[index]	=0; OldCrc=CalcCRC(OldCrc,UART0Buffer[index]); index++;
						UART0Buffer[index]	=7; OldCrc=CalcCRC(OldCrc,UART0Buffer[index]); index++;
						UART0Buffer[index]	=0; OldCrc=CalcCRC(OldCrc,UART0Buffer[index]); index++;
						UART0Buffer[index]	=2; OldCrc=CalcCRC(OldCrc,UART0Buffer[index]); index++;
					#endif

					UART0Buffer[index] = ((OldCrc >> 8) & 0x00FF);	index++;
					UART0Buffer[index] = (OldCrc & 0x00FF);	index++;

					ContSilencioMODBUS=0;
					UARTSendOnly((BYTE *)&UART0Buffer,index);

					FIO0CLR=HABSER_PIN; // (habilita recepcao...)
				}
		}
	}
	#endif;
	#endif;

	if ((LocalTime.RTC_Min==0)||(LocalTime.RTC_Min==15)||(LocalTime.RTC_Min==30)||(LocalTime.RTC_Min==45))
	{
#if  MD4040TI==1
	#ifdef MODELO_EARHT
		MMFp3Acc=0.0;
		FIO0SET=HABSER_PIN;  // (desabilita recepcao...)
	#endif;
#endif;
		if (JaRegistrouNoIntervalode15Min==NAO)
		{
			if(tMMgrandezas==15)
			{
				CalculaGrandezaMM( );

				if (RegistroCabecalho2K.FlagProximoRegistroSeraComRTC==SIM)
				{
#if (USAR_REGISTRO_SHORT==SIM)
					GravaNaBatteryRAM(REG_BATT_MEM_SHORT_COM_RTC);
#else
					GravaNaBatteryRAM(REG_BATT_MEM_NORM_COM_RTC);
#endif
					RegistroCabecalho2K.FlagProximoRegistroSeraComRTC=NAO;
				}
				else
				{
#if (USAR_REGISTRO_SHORT==SIM)
					GravaNaBatteryRAM(REG_BATT_MEM_SHORT_SEM_RTC);
#else
					GravaNaBatteryRAM(REG_BATT_MEM_NORM_SEM_RTC);
#endif
				}
			}
			JaRegistrouNoIntervalode15Min=SIM;
			ProximoIniciodeIntervalo=LocalTime.RTC_Min+2;
			ResgistrarIntervalo15minAgora();
		}
	}
	//Verificamos se estamos ja passamos o minuto de avalia��o
	if (LocalTime.RTC_Min>ProximoIniciodeIntervalo)
	{
		JaRegistrouNoIntervalode15Min=NAO;
	}

#endif

	//vamos aproveitar e verificar se um novo dia esta come�ando...
	if (LocalTime.RTC_Mday!=DiaDeHoje) {
		DiaDeHoje=LocalTime.RTC_Mday;
		ZeraVariaveisDeHoje();
	}

	/*Troca de mes, for�adamente, pela fun��o diaHoraMedAtom�tica*/
	if (DiaHoraParaMedAutomatica==0x00)
	{
		/*Troca de mes... naturalmente pelo calend�rio*/
		if (LeituraConcessionariaSolicitada==NAO)
		{
			if (LocalTime.RTC_Mon!=MesDeHoje) {
				MesDeHoje=LocalTime.RTC_Mon;
				if (LeituraConcessionariaJaRealizadaEsteMes==NAO)
				{
					TrocaDeMes();  ZeraEsteMesAteAgora();
				}
				LeituraConcessionariaJaRealizadaEsteMes=NAO;
			}
		}
		/*Troca de mes... forcadamente pela funcao remota*/
		if (LeituraConcessionariaSolicitada==SIM)
		{
			LeituraConcessionariaSolicitada=NAO;
			if (LeituraConcessionariaJaRealizadaEsteMes==NAO)
			{
				TrocaDeMes();  ZeraEsteMesAteAgora();
				LeituraConcessionariaJaRealizadaEsteMes=SIM;
			}
		}
	}
	else
	{
		/*Troca de mes... naturalmente pelo calend�rio*/
		if (LocalTime.RTC_Mon!=MesDeHoje) {
			MesDeHoje=LocalTime.RTC_Mon;
			LeituraConcessionariaJaRealizadaEsteMes=NAO;
			LeituraConcessionariaSolicitada=NAO;
		}
		/*Troca de mes... forcadamente pela temporizacao*/
		if (LeituraConcessionariaJaRealizadaEsteMes==NAO)
		{
			if (DiaHoraParaMedAutomatica == RTCtoDataHora(LocalTime))
			{
				TrocaDeMes();  ZeraEsteMesAteAgora();
				LeituraConcessionariaJaRealizadaEsteMes=SIM;
			}
		}
	}
}

void ZeraVariaveisDeHoje()
{
	MaxPotAtivPontaHojeAteAgora			=0;
	MaxPotAtivForaPontaHojeAteAgora	   	=0;
	MaxPotAtivReservHojeAteAgora 	   	=0;
	MaxPotReatPontaHojeAteAgora		   	=0;
	MaxPotReatForaPontaHojeAteAgora	   	=0;
	MaxPotReatReservHojeAteAgora		=0;
	EnergGerPontaHojeAteAgora			=0;
	EnergGerForaPontaHojeAteAgora		=0;
	EnergGerReservHojeAteAgora 			=0;
	ConsumoPontaHojeAteAgora			=0;
	ConsumoForaPontaHojeAteAgora 		=0;
	ConsumoReservHojeAteAgora 			=0;
	EnergIndPontaHojeAteAgora			=0;
	EnergIndForaPontaHojeAteAgora		=0;
	EnergIndReservHojeAteAgora 			=0;
	EnergCapPontaHojeAteAgora			=0;
	EnergCapForaPontaHojeAteAgora		=0;
	EnergCapReservHojeAteAgora 			=0;
}

void TrocaDeMes()
{
	int i;

	ConsumoPontaMesPassado			=	ConsumoPontaEsteMesAteAgora		 ;
	ConsumoForaPontaMesPassado		=	ConsumoForaPontaEsteMesAteAgora	 ;
	ConsumoReservMesPassado 		=	ConsumoReservEsteMesAteAgora 	 ;
	EnergIndPontaMesPassado		=	EnergIndPontaEsteMesAteAgora	 ;
	EnergIndForaPontaMesPassado	=	EnergIndForaPontaEsteMesAteAgora ;
	EnergIndReservMesPassado 		=	EnergIndReservEsteMesAteAgora 	 ;
	EnergCapPontaMesPassado		=	EnergCapPontaEsteMesAteAgora	 ;
	EnergCapForaPontaMesPassado	=	EnergCapForaPontaEsteMesAteAgora ;
	EnergCapReservMesPassado 		=	EnergCapReservEsteMesAteAgora  	 ;
	MaxPotAtivPontaMesPassado		=	MaxPotAtivPontaEsteMesAteAgora	;
	MaxPotAtivForaPontaMesPassado	=	MaxPotAtivForaPontaEsteMesAteAgora;
	MaxPotAtivReservMesPassado		=	MaxPotAtivReservEsteMesAteAgora	  ;
	MaxPotReatPontaMesPassado		=	MaxPotReatPontaEsteMesAteAgora;
	MaxPotReatForaPontaMesPassado	=	MaxPotReatForaPontaEsteMesAteAgora	;
	MaxPotReatReservMesPassado 	=	MaxPotReatReservEsteMesAteAgora	;
	LeituraConcessionariaSolicitada=OFF;

	for (i=0;i<4;i++) {
		Lista7DeMaxPotAtivPontaMesPassado[i] =   Lista1DeMaxPotAtivPontaNesteMesAteAgora[i] ;
		Lista8DeMaxPotAtivForaPontaMesPassado[i]=  Lista2DeMaxPotAtivForaPontaNesteMesAteAgora[i] ;
		Lista9DeMaxPotAtivReservMesPassado[i]=	 Lista3DeMaxPotAtivReservNesteMesAteAgora[i] ;
		Lista10DeMaxPotReatPontaMesPassado[i]=     Lista4DeMaxPotReatPontaNesteMesAteAgora[i] ;
		Lista11DeMaxPotReatForaPontaMesPassado[i]= Lista5DeMaxPotReatForaPontaNesteMesAteAgora[i];
		Lista12DeMaxPotReatReservMesPassado[i]=	 Lista6DeMaxPotReatReservNesteMesAteAgora[i];
		MesDiaLista7[i]=MesDiaLista1[i];
		HoraMinLista7[i]=HoraMinLista1[i];
		MesDiaLista8[i]=MesDiaLista2[i];
		HoraMinLista8[i]=HoraMinLista2[i];
		MesDiaLista9[i]=MesDiaLista3[i];
		HoraMinLista9[i]=HoraMinLista3[i];
		MesDiaLista10[i]=MesDiaLista4[i];
		HoraMinLista10[i]=HoraMinLista4[i];
		MesDiaLista11[i]=MesDiaLista5[i];
		HoraMinLista11[i]=HoraMinLista5[i];
		MesDiaLista12[i]=MesDiaLista6[i];
		HoraMinLista12[i]=HoraMinLista6[i];
	}

}

void ZeraEsteMesAteAgora()
{
	int i;

//#if (FIRST == SIM)		 //#if ((EQUIP == CM_EQUIP)||(FIRST == SIM))
if (EquipVirgem==SIM)
{
	EnergGerPontaEsteMesAteAgora		=0;
	EnergGerForaPontaEsteMesAteAgora	=0;
	EnergGerReservEsteMesAteAgora		=0;
	ConsumoPontaEsteMesAteAgora			=0;
	ConsumoForaPontaEsteMesAteAgora		=0;
	ConsumoReservEsteMesAteAgora		=0;
	EnergIndPontaEsteMesAteAgora		=0;
	EnergIndForaPontaEsteMesAteAgora	=0;
	EnergIndReservEsteMesAteAgora		=0;
	EnergCapPontaEsteMesAteAgora		=0;
	EnergCapForaPontaEsteMesAteAgora	=0;
	EnergCapReservEsteMesAteAgora		=0;
}
//#endif

	MaxPotAtivPontaEsteMesAteAgora		=0;
	MaxPotAtivForaPontaEsteMesAteAgora	=0;
	MaxPotAtivReservEsteMesAteAgora		=0;
	MaxPotReatPontaEsteMesAteAgora		=0;
	MaxPotReatForaPontaEsteMesAteAgora	=0;
	MaxPotReatReservEsteMesAteAgora		=0;

	for (i=0;i<4;i++) {
		Lista1DeMaxPotAtivPontaNesteMesAteAgora[i]=0.0;
		Lista2DeMaxPotAtivForaPontaNesteMesAteAgora[i]=0.0;
		Lista3DeMaxPotAtivReservNesteMesAteAgora[i]=0.0;
		Lista4DeMaxPotReatPontaNesteMesAteAgora[i]=0.0;
		Lista5DeMaxPotReatForaPontaNesteMesAteAgora[i]=0.0;
		Lista6DeMaxPotReatReservNesteMesAteAgora[i]=0.0;
		MesDiaLista1[i]=0;
		HoraMinLista1[i]=0;
		MesDiaLista2[i]=0;
		HoraMinLista2[i]=0;
		MesDiaLista3[i]=0;
		HoraMinLista3[i]=0;
		MesDiaLista4[i]=0;
		HoraMinLista4[i]=0;
		MesDiaLista5[i]=0;
		HoraMinLista5[i]=0;
		MesDiaLista6[i]=0;
		HoraMinLista6[i]=0;
	}
}

void ZeraMesPassado()
{
	int i;

	EnergGerPontaMesPassado			=0;
	EnergGerForaPontaMesPassado		=0;
	EnergGerReservMesPassado		=0;
	ConsumoPontaMesPassado			=0;
	ConsumoForaPontaMesPassado		=0;
	ConsumoReservMesPassado			=0;
	EnergIndPontaMesPassado			=0;
	EnergIndForaPontaMesPassado		=0;
	EnergIndReservMesPassado		=0;
	EnergCapPontaMesPassado			=0;
	EnergCapForaPontaMesPassado		=0;
	EnergCapReservMesPassado		=0;
	MaxPotAtivPontaMesPassado		=0;
	MaxPotAtivForaPontaMesPassado	=0;
	MaxPotAtivReservMesPassado		=0;
	MaxPotReatPontaMesPassado		=0;
	MaxPotReatForaPontaMesPassado	=0;
	MaxPotReatReservMesPassado		=0;
	for (i=0;i<4;i++) {
		Lista7DeMaxPotAtivPontaMesPassado[i]=0.0;
		Lista8DeMaxPotAtivForaPontaMesPassado[i]=0.0;
		Lista9DeMaxPotAtivReservMesPassado[i]=0.0;
		Lista10DeMaxPotReatPontaMesPassado[i]=0.0;
		Lista11DeMaxPotReatForaPontaMesPassado[i]=0.0;
		Lista12DeMaxPotReatReservMesPassado[i]=0.0;
		MesDiaLista7[i]=0;
		HoraMinLista7[i]=0;
		MesDiaLista8[i]=0;
		HoraMinLista8[i]=0;
		MesDiaLista9[i]=0;
		HoraMinLista9[i]=0;
		MesDiaLista10[i]=0;
		HoraMinLista10[i]=0;
		MesDiaLista11[i]=0;
		HoraMinLista11[i]=0;
		MesDiaLista12[i]=0;
		HoraMinLista12[i]=0;

	}
}


void ZeraTotaisHorarios()
{
	EnergGerPonta			=0;
	EnergGerForaPonta		=0;
	EnergGerReserv			=0;
	ConsumoPonta			=0;
	ConsumoForaPonta		=0;
	ConsumoReserv			=0;
	EnergIndPonta			=0;
	EnergIndForaPonta		=0;
	EnergIndReserv			=0;
	EnergCapPonta			=0;
	EnergCapForaPonta		=0;
	EnergCapReserv			=0;
	MaxPotAtivPonta			=0;
	MaxPotAtivForaPonta		=0;
	MaxPotAtivReserv		=0;
	MaxPotReatPonta			=0;
	MaxPotReatForaPonta		=0;
	MaxPotReatReserv		=0;

}

void RotinasDeCalibracao()
{
	U8 tIP[4];
	U8 mac_adr[6];
	if (EtapaDeCalibracao!=0)
	{
		EquipamentoCalibrado=NAO;
		ModBusLiberado=SIM;
		HabCapator=OFF;
		relacaoTC=1.0; //temporariamente fica 1 pra 1
		relacaoTP=1.0; //temporariamente fica 1 pra 1
		relacaoTPpri=220;
		relacaoTPsec=220;
		relacaoTPfat=1;
		relacaoTCpri=5;
		relacaoTCsec=5;
		relacaoTCfat=1;

		switch (EtapaDeCalibracao)
		{

			case ETAPA00_MODO1_CAL_DC:
			case ETAPA00_MODO2_CAL_DC:
				{

					Hab_LeituraMedios=1;
					IniciaParametrosCalibracaoDefault();
					nivelDCUa=0;
					nivelDCUb=0;
					nivelDCUc=0;
					nivelDCIa=0;
					nivelDCIb=0;
					nivelDCIc=0;
					polinomioModuloIa[0]=polinomioMIa[0];
					polinomioModuloIa[1]=polinomioMIa[1];
					polinomioModuloIa[2]=polinomioMIa[2];

					polinomioModuloIb[0]=polinomioMIb[0];
					polinomioModuloIb[1]=polinomioMIb[1];
					polinomioModuloIb[2]=polinomioMIb[2];

					polinomioModuloIc[0]=polinomioMIc[0];
					polinomioModuloIc[1]=polinomioMIc[1];
					polinomioModuloIc[2]=polinomioMIc[2];

					EtapaDeCalibracao=EtapaDeCalibracao+100;
					break;
				}
				// sub-etapas
			case ETAPA00_MODO1_CAL_DC+100:
			case ETAPA00_MODO2_CAL_DC+100:
				{ EtapaDeCalibracao=EtapaDeCalibracao+1; break;}
			case ETAPA00_MODO1_CAL_DC+101:
			case ETAPA00_MODO2_CAL_DC+101:
				{
					Hab_LeituraMedios=0;
					nivelDCUa=(short)UmedioA;
					nivelDCUb=(short)UmedioB;
					nivelDCUc=(short)UmedioC;
					nivelDCIa=(short)ImedioA;
					nivelDCIb=(short)ImedioB;
					nivelDCIc=(short)ImedioC;
					EtapaDeCalibracao=0;
					break;
				}

			case ETAPA01_MODO1_CAL_V:
			case ETAPA01_MODO2_CAL_V:
				{

					FatorCalibUa=UrmsAforCalib/UrmsA;
					FatorCalibUb=UrmsAforCalib/UrmsB;
					FatorCalibUc=UrmsAforCalib/UrmsC;
					FatorCalibFreq=60.0/FreqA;
					EtapaDeCalibracao=0;
					break;
				}
			case ETAPA02_MODO1_CAL_DHTV		 :
			case ETAPA02_MODO2_CAL_DHTV		 :
				{
					/*
					   FatorCalibUa_=UrmsA*1.00008/UrmsA_;
					   FatorCalibUb_=UrmsB*1.00008/UrmsB_;
					   FatorCalibUc_=UrmsC*1.00008/UrmsC_;
					 */
					 //	FuncaoRemota1=ZERA_DHT_TENSOES; //Dispara o processo de calibracao da dht!
					  /* FatorCalibUa_=UrmsA*1.00008/UrmsA_;
					   FatorCalibUb_=UrmsB*1.00008/UrmsB_;
					   FatorCalibUc_=UrmsC*1.00008/UrmsC_;*/

						FatorCalibUa_=UrmsAforCalib/UrmsA_;
						FatorCalibUb_=UrmsBforCalib/UrmsB_;
						FatorCalibUc_=UrmsCforCalib/UrmsC_;
						FatorCalibIa_=IrmsAforCalib/IrmsA_;
						FatorCalibIb_=IrmsBforCalib/IrmsB_;
						FatorCalibIc_=IrmsCforCalib/IrmsC_;


					EtapaDeCalibracao=0;
					break;
				}
				///////////// Calibra��o no MODO 1 /////////////////
			case ETAPA03_MODO1_CAL_I_HIGH	 :
				{
					FatorCalibIa=IrmsAforCalib/IrmsA;
					//FatorCalibIb=IrmsBforCalib/IrmsB;//21 de novembro 2008 foi retirado isto e introduzido:
					//FatorCalibIc=IrmsCforCalib/IrmsC;
					FatorCalibIb=IrmsAforCalib/IrmsB;
					FatorCalibIc=IrmsAforCalib/IrmsC;

					EtapaDeCalibracao=0;
					break;
				}
			case ETAPA04_MODO1_CAL_FP_HIGH	 :
				{

					//erro = valor esperado(correto) - valor medido;

					polinomioUA[3]= -fabs(AnguloAforCalib-acos(FatPotA));
					polinomioUB[3]= -fabs(AnguloBforCalib-acos(FatPotB));
					polinomioUC[3]= -fabs(AnguloCforCalib-acos(FatPotC));
					EtapaDeCalibracao=0;
					break;
				}

			case ETAPA05_MODO1_CAL_DHTI:
				{
					/*			FatorCalibIa_=IrmsA*1.00008/IrmsA_;
								FatorCalibIb_=IrmsB*1.00008/IrmsB_;
								FatorCalibIc_=IrmsC*1.00008/IrmsC_;
Obs: ao disparar o processo de calibracao de tensao, o de corrente � automaticamente disparado.
					 */
					EtapaDeCalibracao=0;
					break;
				}
			case ETAPA06_MODO1_CAL_I_LOW:
				{
					polMa=IndiceDeModulo_IA;
					polMb=IndiceDeModulo_IB;
					polMc=IndiceDeModulo_IC;
					if (IndiceDeModulo_IA==0)
					{
						polinomioModuloIa[0]=0.0; polinomioModuloIa[1]=0.0;
						polinomioModuloIa[2]=1.0; polinomioModuloIa[3]=0.0;

					}
					if (IndiceDeModulo_IA==1)
					{
						polinomioModuloIa[0]=polinomioMIa[0];
						polinomioModuloIa[1]=polinomioMIa[1];
						polinomioModuloIa[2]=polinomioMIa[2];
						polinomioModuloIa[3]=polinomioMIa[3];
					}
					if (IndiceDeModulo_IA==2)
					{
						polinomioModuloIa[0]=polinomioMIb[0];
						polinomioModuloIa[1]=polinomioMIb[1];
						polinomioModuloIa[2]=polinomioMIb[2];
						polinomioModuloIa[3]=polinomioMIb[3];
					}
					if (IndiceDeModulo_IA==3)
					{
						polinomioModuloIa[0]=polinomioMIc[0];
						polinomioModuloIa[1]=polinomioMIc[1];
						polinomioModuloIa[2]=polinomioMIc[2];
						polinomioModuloIa[3]=polinomioMIc[3];
					}
					if (IndiceDeModulo_IB==0)
					{
						polinomioModuloIb[0]=0.0; polinomioModuloIb[1]=0.0;
						polinomioModuloIb[2]=1.0; polinomioModuloIb[3]=0.0;
					}
					if (IndiceDeModulo_IB==1)
					{
						polinomioModuloIb[0]=polinomioMIa[0];
						polinomioModuloIb[1]=polinomioMIa[1];
						polinomioModuloIb[2]=polinomioMIa[2];
						polinomioModuloIb[3]=polinomioMIa[3];
					}
					if (IndiceDeModulo_IB==2)
					{
						polinomioModuloIb[0]=polinomioMIb[0];
						polinomioModuloIb[1]=polinomioMIb[1];
						polinomioModuloIb[2]=polinomioMIb[2];
						polinomioModuloIb[3]=polinomioMIb[3];
					}
					if (IndiceDeModulo_IB==3)
					{
						polinomioModuloIb[0]=polinomioMIc[0];
						polinomioModuloIb[1]=polinomioMIc[1];
						polinomioModuloIb[2]=polinomioMIc[2];
						polinomioModuloIb[3]=polinomioMIc[3];
					}
					if (IndiceDeModulo_IC==0)
					{
						polinomioModuloIc[0]=0.0; polinomioModuloIc[1]=0.0;
						polinomioModuloIc[2]=1.0; polinomioModuloIc[3]=0.0;
					}
					if (IndiceDeModulo_IC==1)
					{
						polinomioModuloIc[0]=polinomioMIa[0];
						polinomioModuloIc[1]=polinomioMIa[1];
						polinomioModuloIc[2]=polinomioMIa[2];
						polinomioModuloIc[3]=polinomioMIa[3];
					}
					if (IndiceDeModulo_IC==2)
					{
						polinomioModuloIc[0]=polinomioMIb[0];
						polinomioModuloIc[1]=polinomioMIb[1];
						polinomioModuloIc[2]=polinomioMIb[2];
						polinomioModuloIc[3]=polinomioMIb[3];
					}
					if (IndiceDeModulo_IC==3)
					{
						polinomioModuloIc[0]=polinomioMIc[0];
						polinomioModuloIc[1]=polinomioMIc[1];
						polinomioModuloIc[2]=polinomioMIc[2];
						polinomioModuloIc[3]=polinomioMIc[3];
					}
					EtapaDeCalibracao=0;
					break;
				}

			case ETAPA07_MODO1_CAL_FP_LOW:
				{	  //erro = valor esperado(correto) - valor medido;
					polinomioIA[3]= -fabs(AnguloAforCalib-acos(FatPotA));
					polinomioIB[3]= -fabs(AnguloBforCalib-acos(FatPotB));
					polinomioIC[3]= -fabs(AnguloCforCalib-acos(FatPotC));
					EtapaDeCalibracao=0;
					break;
				}
				///////////// Calibra��o no MODO 2 /////////////////
			case ETAPA03_MODO2_CAL_IA_HIGH:
				{
					FatorCalibIa=IrmsAforCalib/IrmsA;
					EtapaDeCalibracao=0;

					break;
				}
			case ETAPA04_MODO2_CAL_FPA_HIGH:
				{
					polinomioUA[3]=-fabs(AnguloAforCalib-acos(FatPotA));
					EtapaDeCalibracao=0;
					break;
				}
			case ETAPA05_MODO2_CAL_DHTIA:
				{
					FatorCalibIa_=IrmsA*1.00008/IrmsA_;
					EtapaDeCalibracao=0;
					break;
				}
			case ETAPA06_MODO2_CAL_IB_HIGH:
				{
					FatorCalibIb=IrmsBforCalib/IrmsB;
					EtapaDeCalibracao=0;
					break;
				}
			case ETAPA07_MODO2_CAL_FPB_HIGH:
				{
					polinomioUB[3]= -fabs(AnguloBforCalib-acos(FatPotB));
					EtapaDeCalibracao=0;
					break;
				}
			case ETAPA08_MODO2_CAL_DHTIB:
				{
					FatorCalibIb_=IrmsB*1.00008/IrmsB_;
					EtapaDeCalibracao=0;
					break;
				}
			case ETAPA09_MODO2_CAL_IC_HIGH:
				{
					FatorCalibIc=IrmsCforCalib/IrmsC;
					EtapaDeCalibracao=0;
					break;
				}
			case ETAPA10_MODO2_CAL_FPC_HIGH:
				{
					polinomioUC[3]=-fabs(AnguloCforCalib-acos(FatPotC));
					EtapaDeCalibracao=0;
					break;
				}
			case ETAPA11_MODO2_CAL_DHTIC:
				{
					FatorCalibIc_=IrmsC*1.00008/IrmsC_;
					EtapaDeCalibracao=0;
					break;
				}

			case ETAPA12_MODO2_CAL_IA_LOW:
				{
					IndiceDeModulo_IA=1;//for�a a ser o tipo 1
					polMa=IndiceDeModulo_IA;

					if (IndiceDeModulo_IA==0)
					{
						polinomioModuloIa[0]=0.0; polinomioModuloIa[1]=0.0;
						polinomioModuloIa[2]=1.0; polinomioModuloIa[3]=0.0;
					}
					if (IndiceDeModulo_IA==1)
					{
						polinomioModuloIa[0]=polinomioMIa[0];
						polinomioModuloIa[1]=polinomioMIa[1];
						polinomioModuloIa[2]=polinomioMIa[2];
						polinomioModuloIa[3]=polinomioMIa[3];
					}
					if (IndiceDeModulo_IA==2)
					{
						polinomioModuloIa[0]=polinomioMIb[0];
						polinomioModuloIa[1]=polinomioMIb[1];
						polinomioModuloIa[2]=polinomioMIb[2];
						polinomioModuloIa[3]=polinomioMIb[3];
					}
					if (IndiceDeModulo_IA==3)
					{
						polinomioModuloIa[0]=polinomioMIc[0];
						polinomioModuloIa[1]=polinomioMIc[1];
						polinomioModuloIa[2]=polinomioMIc[2];
						polinomioModuloIa[3]=polinomioMIc[3];
					}
					EtapaDeCalibracao=0;
					break;
				}

			case ETAPA13_MODO2_CAL_FPA_LOW:
				{
					polinomioIA[3]=-fabs(AnguloAforCalib-acos(FatPotA));
					EtapaDeCalibracao=0;
					break;
				}

			case ETAPA14_MODO2_CAL_IB_LOW:
				{
					IndiceDeModulo_IB=1;//for�a a ser o tipo 1
					polMb=IndiceDeModulo_IB;

					if (IndiceDeModulo_IB==0)
					{
						polinomioModuloIb[0]=0.0; polinomioModuloIb[1]=0.0;
						polinomioModuloIb[2]=1.0; polinomioModuloIb[3]=0.0;
					}
					if (IndiceDeModulo_IB==1)
					{
						polinomioModuloIb[0]=polinomioMIa[0];
						polinomioModuloIb[1]=polinomioMIa[1];
						polinomioModuloIb[2]=polinomioMIa[2];
						polinomioModuloIb[3]=polinomioMIa[3];
					}
					if (IndiceDeModulo_IB==2)
					{
						polinomioModuloIb[0]=polinomioMIb[0];
						polinomioModuloIb[1]=polinomioMIb[1];
						polinomioModuloIb[2]=polinomioMIb[2];
						polinomioModuloIb[3]=polinomioMIb[3];
					}
					if (IndiceDeModulo_IB==3)
					{
						polinomioModuloIb[0]=polinomioMIc[0];
						polinomioModuloIb[1]=polinomioMIc[1];
						polinomioModuloIb[2]=polinomioMIc[2];
						polinomioModuloIb[3]=polinomioMIc[3];
					}

					EtapaDeCalibracao=0;

					break;
				}
			case ETAPA15_MODO2_CAL_FPB_LOW:
				{
					polinomioIB[3]=-fabs(AnguloBforCalib-acos(FatPotB));
					EtapaDeCalibracao=0;
					break;
				}

			case ETAPA16_MODO2_CAL_IC_LOW:
				{
					IndiceDeModulo_IC=1;//for�a a ser o tipo 1
					polMc=IndiceDeModulo_IC;

					if (IndiceDeModulo_IC==0)
					{
						polinomioModuloIc[0]=0.0; polinomioModuloIc[1]=0.0;
						polinomioModuloIc[2]=1.0; polinomioModuloIc[3]=0.0;
					}
					if (IndiceDeModulo_IC==1)
					{
						polinomioModuloIc[0]=polinomioMIa[0];
						polinomioModuloIc[1]=polinomioMIa[1];
						polinomioModuloIc[2]=polinomioMIa[2];
						polinomioModuloIc[3]=polinomioMIa[3];
					}
					if (IndiceDeModulo_IC==2)
					{
						polinomioModuloIc[0]=polinomioMIb[0];
						polinomioModuloIc[1]=polinomioMIb[1];
						polinomioModuloIc[2]=polinomioMIb[2];
						polinomioModuloIc[3]=polinomioMIb[3];
					}
					if (IndiceDeModulo_IC==3)
					{
						polinomioModuloIc[0]=polinomioMIc[0];
						polinomioModuloIc[1]=polinomioMIc[1];
						polinomioModuloIc[2]=polinomioMIc[2];
						polinomioModuloIc[3]=polinomioMIc[3];
					}
					EtapaDeCalibracao=0;

					break;
				}
			case ETAPA17_MODO2_CAL_FPC_LOW:
				{
					polinomioIC[3]=-fabs(AnguloCforCalib-acos(FatPotC));
					EtapaDeCalibracao=0;
					break;
				}

			case ETAPA_PREPARA_CALIB_V:
				{
					FatorCalibFreq=1.0;
					FatorCalibUa=1.0;
					FatorCalibUb=1.0;
					FatorCalibUc=1.0;
					EtapaDeCalibracao=0;
					break;
				}
			case ETAPA_PREPARA_CALIB_I:
				{
					FatorCalibIa=1.0;
					FatorCalibIb=1.0;
					FatorCalibIc=1.0;
					EtapaDeCalibracao=0;
					break;
				}
			case ETAPA_PREPARA_CALIB_DHTV:
				{
					FatorCalibUa_=1.0;
					FatorCalibUb_=1.0;
					FatorCalibUc_=1.0;
					EtapaDeCalibracao=0;
					break;
				}

			case ETAPA_PREPARA_CALIB_DHTI:
				{
					FatorCalibIa_=1.0;
					FatorCalibIb_=1.0;
					FatorCalibIc_=1.0;
					EtapaDeCalibracao=0;
					break;
				}
			case ETAPA_PREPARA_CALIB_FP_HIGH:
				{
					polinomioIA[3]=0.0;
					polinomioIB[3]=0.0;
					polinomioIC[3]=0.0;
					polinomioUA[3]=0.0;
					polinomioUB[3]=0.0;
					polinomioUC[3]=0.0;
					EtapaDeCalibracao=0;
					break;
				}
			case ETAPA_PREPARA_CAL_FP_LOW:
				{
					polinomioIA[3]=0.0;
					polinomioIB[3]=0.0;
					polinomioIC[3]=0.0;
					EtapaDeCalibracao=0;
					break;
				}
			case ETAPA_PREPARA_CALIB_IA:
				{
					FatorCalibIa=1.0;
					EtapaDeCalibracao=0;
					break;
				}
			case ETAPA_PREPARA_CALIB_IB:
				{
					FatorCalibIb=1.0;
					EtapaDeCalibracao=0;
					break;
				}
			case ETAPA_PREPARA_CALIB_IC:
				{
					FatorCalibIc=1.0;
					EtapaDeCalibracao=0;
					break;
				}
			case ETAPA_PREPARA_CALIB_DHTVA:
				{
					FatorCalibUa_=1.0;
					EtapaDeCalibracao=0;
					break;
				}
			case ETAPA_PREPARA_CALIB_DHTVB:
				{
					FatorCalibUb_=1.0;
					EtapaDeCalibracao=0;
					break;
				}
			case ETAPA_PREPARA_CALIB_DHTVC:
				{
					FatorCalibUc_=1.0;
					EtapaDeCalibracao=0;
					break;
				}
			case ETAPA_PREPARA_CALIB_DHTIA:
				{
					FatorCalibIa_=1.0;
					EtapaDeCalibracao=0;
					break;
				}
			case ETAPA_PREPARA_CALIB_DHTIB:
				{
					FatorCalibIb_=1.0;
					EtapaDeCalibracao=0;
					break;
				}
			case ETAPA_PREPARA_CALIB_DHTIC:
				{
					FatorCalibIc_=1.0;
					EtapaDeCalibracao=0;
					break;
				}
			case ETAPA_PREPARA_CALIB_FP_HIGHA:
				{
					polinomioIA[3]=0.0;
					polinomioUA[3]=0.0;
					EtapaDeCalibracao=0;
					break;
				}
			case ETAPA_PREPARA_CALIB_FP_HIGHB:
				{
					polinomioIB[3]=0.0;
					polinomioUB[3]=0.0;
					EtapaDeCalibracao=0;
					break;
				}
			case ETAPA_PREPARA_CALIB_FP_HIGHC:
				{
					polinomioIC[3]=0.0;
					polinomioUC[3]=0.0;
					EtapaDeCalibracao=0;
					break;
				}
			case ETAPA_PREPARA_CAL_FP_LOWA:
				{
					polinomioIA[3]=0.0;
					EtapaDeCalibracao=0;
					break;
				}
			case ETAPA_PREPARA_CAL_FP_LOWB:
				{
					polinomioIB[3]=0.0;
					EtapaDeCalibracao=0;
					break;
				}
			case ETAPA_PREPARA_CAL_FP_LOWC:
				{
					polinomioIC[3]=0.0;
					EtapaDeCalibracao=0;
					break;
				}

			case ETAPA_GRAVAR_SETOR_CALIBRACAO:
				{

					TemperaturaCoefA_ch0=TemperaturaCoefA_ch0forCalib;
					TemperaturaCoefB_ch0=TemperaturaCoefB_ch0forCalib;
					TemperaturaCoefA_ch1=TemperaturaCoefA_ch1forCalib;
					TemperaturaCoefB_ch1=TemperaturaCoefB_ch1forCalib;


					EquipamentoCalibrado=SIM;

					HabCapator = ON;
					#if ((EQUIP_LINHA50== CA_EQUIP)||((EQUIP_LINHA50== CT_EQUIP)))
						HabCapator=OFF;
					#endif

					toogleWDI();
#ifndef REVISAO_D
					ConfigurePLL_18Mhz();
#endif
					erase((void*)SETOR_CALIBRACAO_INICIO,(void*)SETOR_CALIBRACAO_FIM);	  //apaga um setor de 4Kbytes
					toogleWDI();
					program((void*)SETOR_CALIBRACAO_INICIO,(unsigned int) &FatorCalibUa,256);
					toogleWDI();
					//SalvaParametrizacao();//Chama para gravar o parametro 'EquipamentoCalibrado'
					ZeraGrandezaMM();
					tMMgrandezas=15;//
					tIP[0]=(U8)IPOcteto1;
					tIP[1]=(U8)IPOcteto2;
					tIP[2]=(U8)IPOcteto3;
					tIP[3]=(U8)IPOcteto4;
					RegistroDeAlteracoesConfig.TempoDeIntegracaoGrandezas=15; //
					GravaNaBatteryRAM(REG_BATT_MEM_ALT_CONFIG);
					RestauraParametrizacaoDefault();

					ip_config.IpAdr[0]=tIP[0];	// Local IP Address
					ip_config.IpAdr[1]=tIP[1];	// Local IP Address
					ip_config.IpAdr[2]=tIP[2];	// Local IP Address
					ip_config.IpAdr[3]=tIP[3];	// Local IP Address
					IPOcteto1=tIP[0];
					IPOcteto2=tIP[1];
					IPOcteto3=tIP[2];
					IPOcteto4=tIP[3];



					numeroSerieHexa=(nserie_str[4]-0x30)*1000+(nserie_str[5]-0x30)*100+(nserie_str[6]-0x30)*10+(nserie_str[7]-0x30)*1;
					mac_adr[0]=0x1E;//
					mac_adr[1]=0x30;//
					mac_adr[2]=0x6C;//
				#if EQUIP==CM_EQUIP
					mac_adr[3]=0xA3;//
				#endif
				#if EQUIP==TR_EQUIP
					mac_adr[3]=0xA2;//
				#endif
				#if EQUIP==MD_EQUIP
					mac_adr[3]=0xA1;//
				#endif
					mac_adr[4]=(numeroSerieHexa>>8)&0x00FF;
					mac_adr[5]=numeroSerieHexa&0x00FF;
					#ifdef LEGADO
					mem_copy (own_hw_adr, mac_adr, 6);
					#endif





					refresh_ip();





					EquipamentoCalibrado=SIM;

#if EQUIP==CM_EQUIP
					StatusFuncaoFinal[45]=SIM;
#endif
					SalvaParametrizacao();
					EtapaDeCalibracao=0; //evita que se fa�a mais alguma etapa....
					//Battram
					//ConfigurePLL_60Mhz();

					Zera15min();
					Zera15minAcc();
					ZeraVariaveisDeHoje();
					ZeraMesPassado();
					ZeraEsteMesAteAgora();
					ZeraTotaisHorarios();
					JaRegistrouNoIntervalode15Min=NAO;
					ConsumoT=0; ConsumoA=0; ConsumoB=0; ConsumoC=0;
					EnergGerT=0; EnergGerA=0; EnergGerB=0; EnergGerC=0;
					EnergIndT=0; EnergIndA=0; EnergIndB=0; EnergIndC=0;
					EnergCapT=0; EnergCapA=0; EnergCapB=0; EnergCapC=0;

//Variaveis int64 de calc de Consumo e Energias s�o zeradas durante calibr
// Add by CCT
					ConsumoT_int64=0; ConsumoA_int64=0; ConsumoB_int64=0; ConsumoC_int64=0;
					EnergGerT_int64=0; EnergGerA_int64=0; EnergGerB_int64=0; EnergGerC_int64=0;
					EnergIndT_int64=0; EnergIndA_int64=0; EnergIndB_int64=0; EnergIndC_int64=0;
					EnergCapT_int64=0; EnergCapA_int64=0; EnergCapB_int64=0; EnergCapC_int64=0;

					ClearBatteryRam();
					RegistroCabecalho2K.id=REG_BATT_MEM_INIT;
					RegistroCabecalho2K.ProximoEnderecoAserEscritoNaFlash=SETOR_MM_INICIO;
					RegistroCabecalho2K.ProximoEnderecoAserApagadoNaFlash=SETOR_MM_INICIO;
					//RegistroCabecalho2K.ProximoEnderecoAserEscritoNaBattRam=(DWORD)&RegistroCabecalho2K.NextPos;
					RegistroCabecalho2K.ProximoEnderecoAserEscritoNaBattRam=RTC_RAM_BASE_ADDR+((DWORD)&RegistroCabecalho2K.NextPos)-((DWORD)&RegistroCabecalho2K.id);
					RegistroCabecalho2K.FlagProximoRegistroSeraComRTC=SIM;
					toogleWDI();
					erase((void*)SETOR_MM_INICIO,(void*)0x080BFFFF);//apaga tudo o setor de "Memoria de Masa"
					 toogleWDI();
					 erase((void*)0x080C0000,(void*)0x080DFFFF);//apaga tudo o setor de "Memoria de Masa"
				 toogleWDI();
				   erase((void*)0x080E0000,(void*)SETOR_MM_FIM);//apaga tudo o setor de "Memoria de Masa"



					toogleWDI();
#ifndef REVISAO_D
					ConfigurePLL_72Mhz();
#endif
					break;
				}
				case ETAPA_CALIB_TEMPERATURA:
				{

					TemperaturaCoefA_ch0=TemperaturaCoefA_ch0forCalib;
					TemperaturaCoefB_ch0=TemperaturaCoefB_ch0forCalib;
					TemperaturaCoefA_ch1=TemperaturaCoefA_ch1forCalib;
					TemperaturaCoefB_ch1=TemperaturaCoefB_ch1forCalib;
					EtapaDeCalibracao=ETAPA_GRAVAR_SETOR_CALIBRACAO;
				break;
				}

		}
	}
}

void ReorganizaLista(float *Lista,short *MesDiaLista_ ,short *HoraMinLista_)
{
	//A fun��o desta rotina � organizar em ordem decresente as listas contendo
	//datas e horas de registro de m�ximas demandas.
	float ListaAux[4];
	float Lista1[4];
	int i,ii,i_max;
	float Maximo;
	short MesDiaListaAux[4];
	short HoraMinListaAux[4];
	short MesDiaLista1_[4];
	short HoraMinLista1_[4];

	for (ii=0;ii<4;ii++)
	{
		Lista1[ii]=*Lista; Lista++;
		HoraMinLista1_[ii]=*HoraMinLista_; HoraMinLista_++;
		MesDiaLista1_[ii]= *MesDiaLista_;	 MesDiaLista_++;
	}

	for (ii=0;ii<4;ii++)
	{
		Lista--;
		HoraMinLista_--;
		MesDiaLista_--;

		Maximo=-1.0;
		i_max=0;
		for (i=0;i<4;i++)
		{
			if (Lista1[i]> Maximo )
			{
				Maximo=Lista1[i];
				i_max=i;
			}
		}

		ListaAux[ii]	=Maximo;
		MesDiaListaAux[ii] =MesDiaLista1_[i_max];
		HoraMinListaAux[ii]=HoraMinLista1_[i_max];
		Lista1[i_max]=0;
		HoraMinLista1_[i_max]=0;
		MesDiaLista1_[i_max]=0;
	}

	for (ii=0;ii<4;ii++)
	{
		*Lista 		   = ListaAux[ii];
		*MesDiaLista_   = MesDiaListaAux[ii] ;
		*HoraMinLista_  = HoraMinListaAux[ii];
		Lista++; HoraMinLista_++; MesDiaLista_++;
	}
}

void AcumulaGrandezaMM()
{
#if ((EQUIP_LINHA50 == CP_EQUIP)||(EQUIP_LINHA50 == CD_EQUIP))
	MMUaAcc		= UrmsA;
	MMUbAcc		= UrmsB;
	MMUcAcc		= UrmsC;
	MMIaAcc		= IrmsA;
	MMIbAcc		= IrmsB;
	MMIcAcc		= IrmsC;
	MMDemPAcc	= PotAtivT;
	MMDemQAcc	= PotReatT;
	MMTempAcc	= temperatura_ptc_ch0;
	MMNpontosGrandezas=1;

#else
	MMUaAcc		= MMUaAcc	+ UrmsA;
	MMUbAcc		= MMUbAcc	+ UrmsB;
	MMUcAcc		= MMUcAcc	+ UrmsC;
	MMIaAcc		= MMIaAcc	+ IrmsA;
	MMIbAcc		= MMIbAcc	+ IrmsB;
	MMIcAcc		= MMIcAcc	+ IrmsC;
	MMDemPAcc	= MMDemPAcc	+ PotAtivT;
	MMDemQAcc	= MMDemQAcc	+ PotReatT;
	MMTempAcc	= MMTempAcc	+ temperatura_ptc_ch0;
	MMNpontosGrandezas++;
#endif
}

void CalculaGrandezaMM()
{
	float tflo;
	if (MMNpontosGrandezas==0)
		MMNpontosGrandezas = 1;
	MMUa	= MMUaAcc/MMNpontosGrandezas;
	MMUb	= MMUbAcc/MMNpontosGrandezas;
	MMUc	= MMUcAcc/MMNpontosGrandezas;
	MMIa	= MMIaAcc/MMNpontosGrandezas;
	MMIb	= MMIbAcc/MMNpontosGrandezas;
	MMIc	= MMIcAcc/MMNpontosGrandezas;
	MMDemP	= MMDemPAcc/MMNpontosGrandezas;
	MMDemQ	= MMDemQAcc/MMNpontosGrandezas;

	//MMTemp		= MMTempAcc/MMNpontosGrandezas;
	//MMTemp = ((float)(((unsigned int)((temperatura_ptc_ch0)*10))*10000 + (unsigned int)((temperatura_ptc_ch1)*100)))/10;;
	MMTemp = temperatura_ptc_ch0;
	MMTemp2 = temperatura_ptc_ch1;

	#ifndef MEDE_TEMPERATURA
	tflo 	= sqrt(MMDemP*MMDemP+MMDemQ*MMDemQ);
		#ifndef MODELO_EARHT
		if (tflo==0.0 || MMDemP==0.0)
			MMFp = 1.0;
		else
			MMFp = MMDemP/tflo;
		#endif
	#endif
	ZeraGrandezaMMAcc();
}

void ZeraGrandezaMMAcc()
{
	MMUaAcc		=0;
	MMUbAcc		=0;
	MMUcAcc		=0;
	MMIaAcc		=0;
	MMIbAcc		=0;
	MMIcAcc		=0;
	MMDemPAcc	=0;
	MMDemQAcc	=0;
	MMTempAcc	=0;
	MMNpontosGrandezas	=0;
}

void ZeraGrandezaMM()
{
	MMUa		=0;
	MMUb		=0;
	MMUc		=0;
	MMIa		=0;
	MMIb		=0;
	MMIc		=0;
	MMDemP		=0;
	MMDemQ		=0;
	MMTemp		=0;
	MMFp		=0;
	MMNpontosGrandezas	=0;
	ZeraGrandezaMMAcc();
}
