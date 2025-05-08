#undef EXT
#define EXT extern
#include "..\Port\global.h"			  /* Relativos a variaves globais*/
#include "main.h"


float32_t  pFFT[FFT_LEN];
float32_t  pAbsFFT[FFT_HALF_LEN];
float32_t  pAngleFFT[FFT_HALF_LEN];
float32_t arrayPotAtiv[5];

#define COM_FLEX NAO

#if COM_FLEX==SIM
	static float FATOR_FLEXa=-18.5;
	static float FATOR_FLEXb=-18.5;
	static float FATOR_FLEXc=-18.5;

#else
	static float FATOR_FLEXa=0;
	static float FATOR_FLEXb=0;
	static float FATOR_FLEXc=0;
#endif




	typedef struct
	{

		float freqA;
		float Ua;
		float Ub;
		float Uc;
		float Ia;
		float Ib;
		float Ic;
	    float Pa;
	    float Pb;
	    float Pc;
	    float Pt;


	    float Qa;
	    float Qb;
	    float Qc;
	    float Qt;
	    float Sa;
	    float Sb;
	    float Sc;
	    float St;


	    float fpa;
	    float fpb;
	    float fpc;
	    float fpt;
	    int Npontos;



	}
	grandezas_calculadas_t;

grandezas_calculadas_t  acumulados;


void add1y(RTCTime LocalTime1)
{


		LocalTime1.RTC_Year=LocalTime1.RTC_Year+1;
		RTCSetTime(LocalTime1);
}


void add1m(RTCTime LocalTime1)
{

	if (LocalTime1.RTC_Mon== 12)
	{
		LocalTime1.RTC_Mon=1;
		add1y(LocalTime1);
	}
	else
		LocalTime1.RTC_Mon=LocalTime1.RTC_Mon+1;
	RTCSetTime(LocalTime1);
}


void add1d(RTCTime LocalTime1)
{

	if (LocalTime1.RTC_Mday == 25) //para evitar fev. e meses com 30 e 31 dias só vamos até o dia 25
	{
		LocalTime1.RTC_Mday=1;
		add1m(LocalTime1);
	}
	else
		LocalTime1.RTC_Mday=LocalTime1.RTC_Mday+1;
	RTCSetTime(LocalTime1);
}


void add1h(RTCTime LocalTime1)
{

	if (LocalTime1.RTC_Hour == 23)
	{
		LocalTime1.RTC_Hour=0;
		add1d(LocalTime1);
	}
	else
		LocalTime1.RTC_Hour=LocalTime1.RTC_Hour+1;
	RTCSetTime(LocalTime1);
}

void add15min(RTCTime *LocalTime1)
{
	if (LocalTime1->RTC_Min == 0)
	{
		LocalTime1->RTC_Min = 14;
	}
	if (LocalTime1->RTC_Min == 15)
	{
		LocalTime1->RTC_Min = 29;
	}
	if (LocalTime1->RTC_Min == 30)
	{
		LocalTime1->RTC_Min = 44;
	}
	if (LocalTime1->RTC_Min == 45)
	{
		LocalTime1->RTC_Min = 59;
	}

}




float angle_norm(float x)
	{
		if (fabs(x) == M_PI)
			return x;
		else
		{
			x = fmod(x + M_PI, 2*M_PI);
			if (x < 0)
				x += 2*M_PI;
			return x - M_PI;
		}
	}

float phase_unwrap(float prev, float now)
	{
	    return prev + angle_norm(now - prev);
	}



/*função que soma um cosseno ao vetor de entrada y*/
void cosseno(float32_t  dc,	float32_t  Amp, 	float32_t  Fase,	float32_t  Freq, int Np,	float32_t  Fs, float32_t *y,	float32_t  *t)
{
    #define pi 3.141592653589793238462643383279

	float32_t  incremento=1/Fs;
	float32_t  tempo=0;


	for (int i=0;i<Np;i++)
	{
		if (t!=NULL)
			t[i]=tempo;

		y[i]=y[i]+dc+(Amp*cos(2*pi*Freq*tempo+Fase*pi/180));
		tempo=tempo+incremento;

	}


}

void CriandoSinalParaTestes(float32_t *pSinal, int Np)
{


const float  AmplitudesCorretas[4]  ={ 2000,    0,   0,  10};
//const float  FrequenciasCorretas[4] ={ f1,  f1*2, f1*3.1, f1*5 };
const float  FrequenciasCorretas[4] ={ 512,  00, 0, 300 };
const float  FasesCorretas[4] ={ 0,  0, 0, 10};




for (int k=0;k<Np;k++)
	pSinal[k]=0;

for (int k=0;k<4;k++)
      cosseno(0,AmplitudesCorretas[k], FasesCorretas[k],FrequenciasCorretas[k],  Np, FS,pSinal,NULL);


}

void CriandoSinalParaTestes1(uint16_t *buff_out, float32_t *pSinal, int Np)
{


	const float  AmplitudesCorretas[4]  ={ 899.2974,     0,   0,  00};   //sinal de tensão
	//const float  FrequenciasCorretas[4] ={ f1,  f1*2, f1*3.1, f1*5 };
	const float  FrequenciasCorretas[4] ={ 60,  180, 0, 0 };
	const float  FasesCorretas[4] ={ 0,  0, 00, 00};




for (int k=0;k<Np;k++)
	pSinal[k]=0;

for (int k=0;k<4;k++)
      cosseno(0,AmplitudesCorretas[k], FasesCorretas[k],FrequenciasCorretas[k],  Np, FS,pSinal,NULL);


for (int k=0;k<Np;k++)
	buff_out[k]=(uint16_t)(pSinal[k]+2048.0);


}

void CriandoSinalParaTestes2(uint16_t *buff_out, float32_t *pSinal, int Np)
{


	const float  AmplitudesCorretas[4]  ={ 581.8182,   0  ,   0,  00}; //sinal de corrente
	//const float  FrequenciasCorretas[4] ={ f1,  f1*2, f1*3.1, f1*5 };
	const float  FrequenciasCorretas[4] ={ 60,  300, 0, 0 };
	const float  FasesCorretas[4] ={ -45,  40, 00, 00};  //deixando positivo aqui, é indutivo.




for (int k=0;k<Np;k++)
	pSinal[k]=0;

for (int k=0;k<4;k++)
      cosseno(0,AmplitudesCorretas[k], FasesCorretas[k],FrequenciasCorretas[k],  Np, FS,pSinal,NULL);

	for (int k=0;k<Np;k++)
	{
		buff_out[k]=(uint16_t)(pSinal[k]+2048.0);
		//buff_out[k]=(uint16_t)(-pSinal[k]+2048.0); //emulamos o fato de na placa estar 180 graus invertido o canal de corrente..
  	}
}

void CriandoSinalBuffREF(uint16_t *buff_out , int Np)
{
for (int k=0;k<Np;k++)
	buff_out[k]=2048;
}

 void Calculos_detecta_picos(int *Saida, int *npSaida, bin_phasor_t *Entrada1, int npEntrada, int *MaiorPico, float limiar)
{

#define INDICE_INICIAL 0
float n1,n2,n3,n4;
short k = 0;
short index = 0;
float MaiorP=0;
//float limiar =1; //limiar mínimo default imutável
//&(Entrada1->Mag)=Entrada;


    n1 = Entrada1[INDICE_INICIAL+0].Mag;
    n2 = Entrada1[INDICE_INICIAL+1].Mag;
    n3 = Entrada1[INDICE_INICIAL+2].Mag;
    n4 = Entrada1[INDICE_INICIAL+3].Mag;

    for (k=(INDICE_INICIAL+3); k<npEntrada; k++)
    {
        n4 = Entrada1[k].Mag;
        if (n2>n1 && n2>n3 && n2>limiar)
//		if (n2>n1 && n2>n3 )
        {
            Saida[index++] = k-2;
            if (Entrada1[Saida[index-1]].Mag>MaiorP) {
                MaiorP=Entrada1[Saida[index-1]].Mag;
            }

        }
        if (n2>n1 && n2==n3 && n3>n4 && n2>limiar)
//		if (n2>n1 && n2==n3 && n3>n4 )
        {
            Saida[index++] = k-1;
            if (Entrada1[Saida[index-1]].Mag>MaiorP) {
                MaiorP=Entrada1[Saida[index-1]].Mag;
            }
        }
        n1=n2;
        n2=n3;
        n3=n4;
       if (index>=NPONTOS_ESPECTRAIS_INTERP) {
           break;
       }

    }

    *npSaida = index;
    *MaiorPico=MaiorP;
}

  int signum(float val)
{
    if (val > 0.0f)
        return  1;
    else
    {
        if (val < 0.0f)
            return -1;
        else
            return  0;
    }
}

//de http://toto-share.com/2012/07/cc-hanning-matlab-code/
 void hanning(float *w, int Np, short itype)
  {
	  #define N FFT_LEN
      int half, i, idx, n;
      //float *w;

    //  w = (float*) calloc(Np, sizeof(float));
      memset(w, 0, Np*sizeof(float));

      if(itype==1)    //periodic function
          n = Np-1;
      else
          n = Np;

      if(n%2==0)
      {
          half = n/2;
          for(i=0; i<half; i++) //CALC_HANNING   Calculates  window samples.
              w[i] = 0.5 * (1 - cos(2*PI*(i+1) / (n+1)));

          idx = half-1;
          for(i=half; i<n; i++) {
              w[i] = w[idx];
              idx--;
          }
      }
      else
      {
          half = (n+1)/2;
          for(i=0; i<half; i++) //CALC_HANNING   Calculates Hanning window samples.
              w[i] = 0.5 * (1 - cos(2*PI*(i+1) / (n+1)));

          idx = half-2;
          for(i=half; i<n; i++) {
              w[i] = w[idx];
              idx--;
          }
      }

      if(itype==1)    //periodic function
      {
          for(i=N-1; i>=1; i--)
              w[i] = w[i-1];
          w[0] = 0.0;
      }
      //return(w);
  }

 int Calculos_Interpola(bin_phasor_t *pIn, bin_phasor_interp_t *pOut)
{
   // #define PI  3.141592653589793f
    #define NUM_MAX_PICOS NPONTOS_ESPECTRAIS_INTERP     //delimitando o número picos.

    #ifdef JANELAMENTO_HANNING
    int sig_delta;
    float alfa,mod_delta;
    #endif

    int array_picos[NUM_MAX_PICOS];
    int num_picos_detectados;
    int maior_pico_detectado;



    int i,ii;
    int index;
    float f,Fs=FS;
    float Amp,Ang,delta;
#ifdef JANELAMENTO_RETANGULAR
    float delta1,delta2,abs_delta;
    float mod_ant,mod_pos,mod;
#endif

    	static float limiarX=2.0;


        Calculos_detecta_picos( &array_picos[0],
                                &num_picos_detectados,
                                &pIn[0],
                                NPONTOS_ESPECTRAIS_DFT,
                                &maior_pico_detectado,1);

        if (maior_pico_detectado>1000)
				limiarX= maior_pico_detectado*0.0025;
        else
        	    limiarX= maior_pico_detectado*0.0020;
        if (num_picos_detectados>10)
			limiarX= 20;

		if (limiarX<1.8)
			limiarX=1.8;
		if (limiarX>10.0)
			limiarX=10.0;

        Calculos_detecta_picos( &array_picos[0],
                                &num_picos_detectados,
                                &pIn[0],
                                NPONTOS_ESPECTRAIS_DFT,
                                &maior_pico_detectado,limiarX);

       if (num_picos_detectados>1)
       {
    	   limiarX=10.0;
       }

        ii=0;
        for (i=0; i< num_picos_detectados; i++)
        {
                index=array_picos[i];
                #ifdef JANELAMENTO_HANNING

                sig_delta=signum((pIn[index+1].Mag)-(pIn[index-1].Mag));
                alfa=(pIn[index].Mag) / (pIn[index+sig_delta].Mag);
                mod_delta=(2-alfa)/(1+alfa);
                delta=mod_delta*(float)sig_delta;

                if (alfa>1e10f)
                    delta=0.0f;

                f=index+delta;
                f=f*Fs/(NPONTOS_ESPECTRAIS_DFT*2);
                    if (delta==0.0f)
                    {
                        Amp=    (pIn[index].Mag);
                        Ang=    (pIn[index].Phase);  //em radianos
                    }
                    else
                    {
                        Amp=PI* (pIn[index].Mag)*delta*(1-(delta*delta))/sin(PI*delta);
                        Ang= (pIn[index].Phase)-delta*PI*index;  //em radianos

                    }
                #endif


    #ifdef JANELAMENTO_RETANGULAR
                mod_ant = (pIn[index-1].Mag);
                mod_pos = (pIn[index+1].Mag);
                mod = (pIn[index].Mag);

                delta1=(mod_pos+mod_ant)/(2.0*mod-mod_ant+mod_pos);
                delta2=(mod_pos)/(mod+mod_pos);
                delta = 0.5*(delta1+delta2);
                abs_delta = fabs(delta);
                if(mod_pos>=mod_ant)
                {
                    delta = -abs_delta;

                }
                else
                {
                    delta = abs_delta;
                }
                f=index-delta;
                f=f*Fs/(NPONTOS_ESPECTRAIS_DFT*2);

                if (abs_delta<=0.0000001f)
                {
                    Amp=(pIn[index].Mag);
                    Ang=    (pIn[index].Phase);  //em radianos
                }
                else
                {




                    Amp=PI*mod*delta/sin(PI*delta);

                    Ang= phase_unwrap(pIn[index-1].Phase, pIn[index+0].Phase);

#if 0 //a fase naõ precisa ser interpolada, porque as potencias são calculadas pela diferença entre as fases..

                    //para calculo da fase, se faz só uma interpolação linear, mas antes disso, fazer unwrap

                    //phase_unwrap(float prev, float now)

                    pIn[index+1].Phase= phase_unwrap(pIn[index-0].Phase, pIn[index+1].Phase);
                    pIn[index+0].Phase= phase_unwrap(pIn[index-1].Phase, pIn[index+0].Phase);
                    pIn[index-1].Phase= phase_unwrap(pIn[index-2].Phase, pIn[index-1].Phase);

                    if (delta>=0)
                    {
                    	if (pIn[index-1].Phase>pIn[index].Phase)
                    	{
                    		Ang=pIn[index].Phase-  (pIn[index].Phase-pIn[index-1].Phase) * delta;
                    	}
                    	else
                    	{
                    		Ang=pIn[index].Phase+  (pIn[index].Phase-pIn[index-1].Phase) * delta;
                    	}

                    }
                    else
                    {
                    	if (pIn[index-1].Phase>pIn[index].Phase)
                    	{
                    		Ang=pIn[index].Phase+  (pIn[index+1].Phase-pIn[index].Phase) * delta;

                    	}
                    	else
                    	{
                    		Ang=pIn[index].Phase-  (pIn[index+1].Phase-pIn[index].Phase) * delta;

                    	}


                    }


#endif

                }
     #endif  //do tipo de janela retangular



                //Amp=Amp/NPONTOS_ESPECTRAIS_DFT; //normalizamos as amplitudes só para depurar, não manter esta linha no código final

                pOut[ii].Mag = Amp;
                pOut[ii].Freq=f;
                pOut[ii].Phase= Ang*180/PI;






                if (ChannFund==1)
                {
                	//TODO: nem sempre o primeiro indice é o da fundamental
                	if (ii==0)
                	{
                		PhaseFund=pOut[ii].Phase;
                		FreqFund=pOut[ii].Freq;
                	}
                }

                if (f>48.5)
                	ii=ii+1;



         }
return (num_picos_detectados);
}


void EspectroAcumulado_reinit()
 {
	for (int ch=0;ch< NUM_CHANNELS ;ch++)
	{
			 for (int i=0;i<NPONTOS_ESPECTRAIS_INTERP;i++)
				  {
				  pEspectroDisplay[ch][i].Mag=pEspectroAcumulado[ch][i].Mag;
				  pEspectroDisplay[ch][i].Phase=pEspectroAcumulado[ch][i].Phase;
				  pEspectroDisplay[ch][i].Freq=pEspectroAcumulado[ch][i].Freq;


				  pEspectroAcumulado[ch][i].Mag=0;
				  pEspectroAcumulado[ch][i].Phase=0;
				  pEspectroAcumulado[ch][i].Freq=0;
				  }
			 cont_espectros=0;
	}

	 acumulados.Pa=0;
	 acumulados.Pb=0;
	 acumulados.Pc=0;
	 acumulados.Qa=0;
	 acumulados.Qb=0;
	 acumulados.Qc=0;
	 /*
	 acumulados.Ua=0;
	 acumulados.Ub=0;
	 acumulados.Uc=0;
	 acumulados.Ia=0;
	 acumulados.Ib=0;
	 acumulados.Ic=0;
	 */
	 acumulados.Npontos=0;

 }

void MyFFT_Init()
{
	  /*

	CMSIS-DSP library:
	https://www.keil.com/pack/doc/CMSIS/DSP/html/index.html
	https://github.com/ARM-software/CMSIS
	https://raw.githubusercontent.com/ARM-software/CMSIS/master/CMSIS/Include/arm_math.h   <<baixar
	https://github.com/ARM-software/CMSIS/tree/master/CMSIS/Lib/GCC
	https://github.com/ARM-software/CMSIS/blob/master/CMSIS/Lib/GCC/libarm_cortexM4lf_math.a  <<baixar
	como incluir arquivos de cabeçalho:
	https://www.youtube.com/watch?v=MUZj4YwKVac
	como 'importar' o CMSIS-DSP para dentro do CubeIDE
	https://www.youtube.com/watch?v=vCcALaGNlyw

	*/

	//inicializando a instância de FFT
	 arm_rfft_fast_init_f32	(&MyFFT,FFT_LEN); //Supported FFT Lengths are 128, 512, 2048

	 /*
	  *
	  	  //criando uma sinal de teste
	  CriandoSinalParaTestes (&pSinal[0],N);



	  * */

 EspectroAcumulado_reinit();

}

void AcumulaEspectroBackup(bin_phasor_interp_t *pEspectro,int num_compoentes,int ch)
{
#define DELTA_FREQ_EM_F1 1.5

#define FATOR_X ((f1+DELTA_FREQ_EM_F1)/f1)
#define FATOR_PERTENCIMENTO 1.01   //até 1% de variação entre o atual e o anterior espectro, se considera da mesma banda...


	float32_t fator,Diff,minDiff=1e6,ind_minDiff=10000;
	int k,i,m,primeiro_espectro=1;

	//buscamos no espectro anterior, quem se repete e quem aparece pela primeira vez.
	for (i=0;i<NPONTOS_ESPECTRAIS_INTERP;i++)
	{
		if (pEspectroAcumulado[ch][i].Freq!=0)
		{
			primeiro_espectro=0;
			minDiff=1e6;
			ind_minDiff=10000;
			for (k=0;k<NPONTOS_ESPECTRAIS_INTERP;k++)
			{
				if ((pEspectro[k].Freq!=0)&&(pEspectro[k].Mag!=0))
				{
					Diff=fabs(pEspectroAcumulado[ch][i].Freq-pEspectro[k].Freq);
					if (Diff<minDiff)
					{
						minDiff=Diff;
						ind_minDiff=k;
					}
				}
			}

			if (ind_minDiff!=10000)
			{
					//aqui vamos ver o grau de semelhança...
				k=ind_minDiff;
					if (pEspectroAcumulado[ch][i].Freq>=pEspectro[k].Freq)
						fator=(pEspectroAcumulado[ch][i].Freq/pEspectro[k].Freq);
					else
						fator=(pEspectro[k].Freq/pEspectroAcumulado[ch][i].Freq);


					if (fator<FATOR_PERTENCIMENTO)
					{
						//pertence, então, fazer a 'média'
						//atan2f(imag,real);
						float imAcc=pEspectroAcumulado[ch][i].Mag*sin(pEspectroAcumulado[ch][i].Phase*PI/180);
						float reAcc=pEspectroAcumulado[ch][i].Mag*cos(pEspectroAcumulado[ch][i].Phase*PI/180);
						float im=pEspectro[k].Mag*sin(pEspectro[k].Phase*PI/180);
						float re= pEspectro[k].Mag*cos(pEspectro[k].Phase*PI/180);
						re=re/FFTs_PER_SEC+reAcc;
						im=im/FFTs_PER_SEC+imAcc;
						 pEspectroAcumulado[ch][i].Phase=180*atan2f(im,re)/PI;

						//pEspectroAcumulado[ch][i].Phase=phase_unwrap(pEspectroAcumulado[ch][i].Phase*PI/180,atan2f(im,re))*180/PI;

						pEspectroAcumulado[ch][i].Mag=sqrt(re*re+im*im);

						//pEspectroAcumulado[ch][i].Phase=(pEspectroAcumulado[ch][i].Phase+pEspectro[k].Phase)/2;
						//pEspectroAcumulado[ch][i].Mag=(pEspectroAcumulado[ch][i].Mag	+pEspectro[k].Mag)/2;
						pEspectroAcumulado[ch][i].Freq=(pEspectroAcumulado[ch][i].Freq+pEspectro[k].Freq)/2;
					}
					else
					{
						//não pertence, logo usar um outro bin
						for (m=0;m<NPONTOS_ESPECTRAIS_INTERP;m++)
							if (pEspectroAcumulado[ch][m].Freq==0)
							{
								pEspectroAcumulado[ch][m].Phase=	(pEspectro[k].Phase);
								pEspectroAcumulado[ch][m].Mag=		(pEspectro[k].Mag/FFTs_PER_SEC);
								pEspectroAcumulado[ch][m].Freq=		(pEspectro[k].Freq);
								break;
							}
					}
					//marcamos como já usado este bin.
					pEspectro[k].Phase=0;
					pEspectro[k].Mag=0;
					pEspectro[k].Freq=0;
			}
		}
	}
	if (primeiro_espectro==1)
		for (m=0;m<NPONTOS_ESPECTRAIS_INTERP;m++)
			{
				pEspectroAcumulado[ch][m].Phase=	(pEspectro[m].Phase);
				pEspectroAcumulado[ch][m].Mag=		(pEspectro[m].Mag/FFTs_PER_SEC);
				pEspectroAcumulado[ch][m].Freq=		(pEspectro[m].Freq);
			}



	cont_espectros++;

}


void AcumulaEspectro(bin_phasor_interp_t *pEspectro,int num_compoentes,int ch)
{
#define DELTA_FREQ_EM_F1 1.5

#define FATOR_X ((f1+DELTA_FREQ_EM_F1)/f1)
#define FATOR_PERTENCIMENTO 1.01   //até 1% de variação entre o atual e o anterior espectro, se considera da mesma banda...


	float32_t fator,Diff,minDiff=1e6,ind_minDiff=10000;
	int k,i,m,primeiro_espectro=1;

	//buscamos no espectro anterior, quem se repete e quem aparece pela primeira vez.
	for (i=0;i<NPONTOS_ESPECTRAIS_INTERP;i++)
	{
		if (pEspectroAcumulado[ch][i].Freq!=0)
		{
			primeiro_espectro=0;
			minDiff=1e6;
			ind_minDiff=10000;
			for (k=0;k<NPONTOS_ESPECTRAIS_INTERP;k++)
			{
				if ((pEspectro[k].Freq!=0)&&(pEspectro[k].Mag!=0))
				{
					Diff=fabs(pEspectroAcumulado[ch][i].Freq-pEspectro[k].Freq);
					if (Diff<minDiff)
					{
						minDiff=Diff;
						ind_minDiff=k;
					}
				}
			}

			if (ind_minDiff!=10000)
			{
					//aqui vamos ver o grau de semelhança...
				k=ind_minDiff;
					if (pEspectroAcumulado[ch][i].Freq>=pEspectro[k].Freq)
						fator=(pEspectroAcumulado[ch][i].Freq/pEspectro[k].Freq);
					else
						fator=(pEspectro[k].Freq/pEspectroAcumulado[ch][i].Freq);


					if (fator<FATOR_PERTENCIMENTO)
					{
						//pertence, então, fazer a 'média'
						//mas antes, referenciar o frame ao frame anterior
//						 double fractpart,intpart;
//						  fractpart = modf((pEspectroAcumulado[ch][i].Freq/((float)FFTs_PER_SEC)*cont_espectros), &intpart);
//						  pEspectro[k].Phase=pEspectro[k].Phase-360*fractpart;



						//atan2f(imag,real);
						float imAcc=pEspectroAcumulado[ch][i].Mag*sin(pEspectroAcumulado[ch][i].Phase*PI/180);
						float reAcc=pEspectroAcumulado[ch][i].Mag*cos(pEspectroAcumulado[ch][i].Phase*PI/180);
						float im=pEspectro[k].Mag*sin(pEspectro[k].Phase*PI/180);
						float re= pEspectro[k].Mag*cos(pEspectro[k].Phase*PI/180);
						re=re/FFTs_PER_SEC+reAcc;
						im=im/FFTs_PER_SEC+imAcc;

						pEspectroAcumulado[ch][i].Phase=180*atan2f(im,re)/PI;

						//pEspectroAcumulado[ch][i].Phase=phase_unwrap(pEspectroAcumulado[ch][i].Phase*PI/180,pEspectro[k].Phase*PI/180)*180/PI;

						//pEspectroAcumulado[ch][i].Phase= pEspectro[k].Phase;

						pEspectroAcumulado[ch][i].Mag=sqrt(re*re+im*im);

						//pEspectroAcumulado[ch][i].Phase=(pEspectroAcumulado[ch][i].Phase+pEspectro[k].Phase)/2;
						//pEspectroAcumulado[ch][i].Mag=(pEspectroAcumulado[ch][i].Mag	+pEspectro[k].Mag)/2;
						pEspectroAcumulado[ch][i].Freq=(pEspectroAcumulado[ch][i].Freq+pEspectro[k].Freq)/2;
					}
					else
					{
						//não pertence, logo usar um outro bin
						for (m=0;m<NPONTOS_ESPECTRAIS_INTERP;m++)
							if (pEspectroAcumulado[ch][m].Freq==0)
							{
								pEspectroAcumulado[ch][m].Phase=	(pEspectro[k].Phase);
								pEspectroAcumulado[ch][m].Mag=		(pEspectro[k].Mag/FFTs_PER_SEC);
								pEspectroAcumulado[ch][m].Freq=		(pEspectro[k].Freq);
								break;
							}
					}
					//marcamos como já usado este bin.
					pEspectro[k].Phase=0;
					pEspectro[k].Mag=0;
					pEspectro[k].Freq=0;
			}
		}
	}
	if (primeiro_espectro==1)
		for (m=0;m<NPONTOS_ESPECTRAIS_INTERP;m++)
			{
				pEspectroAcumulado[ch][m].Phase=	(pEspectro[m].Phase);
				pEspectroAcumulado[ch][m].Mag=		(pEspectro[m].Mag/FFTs_PER_SEC);
				pEspectroAcumulado[ch][m].Freq=		(pEspectro[m].Freq);
			}



	cont_espectros++;

}



void MyFFT_Execute1(float32_t *pSinal,int ch)
{



	//agora vamos criar o janelamento e aplicar se necessário
		#ifdef JANELAMENTO_HANNING
		//float32_t  *janela;
		//  janela=hanning(FFT_LEN,1);

		   for (int i = 0; i < FFT_LEN; i++) {
			   pSinal[i] = 2*janela[i] * pSinal[i];
			}
		 //free(janela);
		#endif


	//calculando a fft
	 arm_rfft_fast_f32(&MyFFT,pSinal,pFFT,0);


	 //calculando o módulo ao quadrado
	  arm_cmplx_mag_squared_f32(pFFT,pAbsFFT,FFT_HALF_LEN);

	 //calculando o módulo normalizado e a fase (tratamento especial para DC)
	  pAbsFFT[0]=sqrt(pAbsFFT[0])/FFT_LEN;
	  pAngleFFT[0]=0;

	//calculando o módulo normalizado e a fase
	  for (int i=1;i<FFT_HALF_LEN;i++)
	  {
		//		 if (((i * 2) + 1)>=FFT_LEN)
		//		 break;

	     pAbsFFT[i]=sqrt(pAbsFFT[i])*2/FFT_LEN;
	     pAngleFFT[i] =  atan2f(pFFT[(i * 2) + 1], pFFT[i*2]);
	  }




	//neste ponto vamos calcular os sinais interpolados da DFT
	  bin_phasor_t pIn[FFT_HALF_LEN];
	  bin_phasor_interp_t pOut[NPONTOS_ESPECTRAIS_INTERP];


	  for (int i=1;i<FFT_HALF_LEN;i++)
	  {
		  pIn[i].Mag= (pAbsFFT[i]);
		  pIn[i].Phase= (pAngleFFT[i]);
	  }
	  for (int i=0;i<NPONTOS_ESPECTRAIS_INTERP;i++)
	  	  {
		  pOut[i].Mag=0;
		  pOut[i].Phase=0;
		  pOut[i].Freq=0;
	  	  }
	  int num_compoentes=Calculos_Interpola(pIn,pOut);
	  AcumulaEspectro(pOut,num_compoentes,ch);
	  if (ch==0)
	  {
		  for (int i=0;i<NPONTOS_ESPECTRAIS_INTERP;i++)
		  pOutTemporario[i]=pOut[i];

	  }



}

void MyFFT_Execute(float32_t *pSinal,int ch)
{
	 //HAL_Delay(10);

	extern void MX_LWIP_Process( );
	 MX_LWIP_Process( );
	// cont_espectros=cont_espectros+1;
	  MyFFT_Execute1(pSinal,ch);

}



int bestindex(bin_phasor_interp_t mybin, bin_phasor_interp_t *mybins, int num_componentes)
{
#define FATOR_DE_PERTENCIMENTO 1.01
	int i,bi=10000,ind_minDiff=10000;

	float32_t fator=10000,Diff,minDiff=1e6;
	for (i=0;i<num_componentes;i++)
	{
		if ((mybin.Mag!=0) && (mybins[i].Mag!=0))
		{
			Diff=abs(mybin.Freq-mybins[i].Freq);
			if (Diff<minDiff)
			{
				minDiff=Diff;
				ind_minDiff=i;
			}
		}

	}


	if ((minDiff!=10000) &&(minDiff!=1e6))
	{
		if (mybin.Freq>=mybins[ind_minDiff].Freq)
		{
			if (mybins[ind_minDiff].Freq!=0)
			{
			fator=mybin.Freq/mybins[ind_minDiff].Freq;
			}
		}
		else
		{
			if (mybin.Freq!=0)
			{
				fator=mybins[ind_minDiff].Freq/mybin.Freq;
			}
			else
			{


			}
		}
	}

	if (fator<FATOR_DE_PERTENCIMENTO)
	{//encontramos o melhor indice para a componente espectral

		bi=ind_minDiff;

	}
	else
	{


	}


return bi;
}

float sinalfp(float P, float Q)  //https://www.se.com/br/pt/faqs/FA283279/
{
	float s=1.0;
	Q=-Q; //em teste

	if (P>=0)
	{
		if (Q>=0)
			s=-1.0;
	}
	else
	{
		if (Q<0)
			s=-1.0;
	}

return s;
}


void CalculaGrandezas1(float32_t *pSinalUa,float32_t *pSinalIa, float32_t *pSinalUb, float32_t *pSinalIb, float32_t *pSinalUc, float32_t *pSinalIc, float32_t f0)
{
	static int cont_pot;
	grandezas_calculadas_t gc;
	gc.Pa=0;
	gc.Pb=0;
	gc.Pc=0;
	gc.Ua=0;
	gc.Ub=0;
	gc.Uc=0;
	gc.Ia=0;
	gc.Ib=0;
	gc.Ic=0;
	if ((f0<10)||(f0>70))
		f0=60.0;
	float32_t ppc=FS/f0;
	float32_t nciclos=FFT_LEN/ppc;
	int N360=(int)round(nciclos*ppc);
	int N90a,N90b,N90c;
	if (N360>FFT_LEN)
		N360=FFT_LEN;



	if (N360!=1024)
	{
		N360= FFT_LEN;
	}

	float32_t dc;
	 dc=0;
	 for (int i=0;i<N360;i++)  dc=pSinalUa[i]+dc;
	 dc=dc/N360;
	 for (int i=0;i<N360;i++)  pSinalUa[i]=pSinalUa[i]-dc;
	 dc=0;
	 for (int i=0;i<N360;i++)  dc=pSinalUb[i]+dc;
	 dc=dc/N360;
	 for (int i=0;i<N360;i++)  pSinalUb[i]=pSinalUb[i]-dc;
	 dc=0;
	 for (int i=0;i<N360;i++)  dc=pSinalUc[i]+dc;
	 dc=dc/N360;
	 for (int i=0;i<N360;i++)  pSinalUc[i]=pSinalUc[i]-dc;
	 dc=0;
	 for (int i=0;i<N360;i++)  dc=pSinalIa[i]+dc;
	 dc=dc/N360;
	 for (int i=0;i<N360;i++)  pSinalIa[i]= (pSinalIa[i]-dc);
	 dc=0;
	 for (int i=0;i<N360;i++)  dc=pSinalIb[i]+dc;
	 dc=dc/N360;
	 for (int i=0;i<N360;i++)  pSinalIb[i]= (pSinalIb[i]-dc);
	 dc=0;
	 for (int i=0;i<N360;i++)  dc=pSinalIc[i]+dc;
	 dc=dc/N360;
	 for (int i=0;i<N360;i++)  pSinalIc[i]= (pSinalIc[i]-dc);



 for (int i=0;i<N360;i++)
 {
	 gc.Pa=gc.Pa+pSinalUa[i]*pSinalIa[i];
	 gc.Pb=gc.Pb+pSinalUb[i]*pSinalIb[i];
	 gc.Pc=gc.Pc+pSinalUc[i]*pSinalIc[i];


	/* gc.Ua=gc.Ua+pSinalUa[i]*pSinalUa[i];
	 gc.Ub=gc.Ub+pSinalUb[i]*pSinalUb[i];
	 gc.Uc=gc.Uc+pSinalUc[i]*pSinalUc[i];
	 gc.Ia=gc.Ia+pSinalIa[i]*pSinalIa[i];
	 gc.Ib=gc.Ib+pSinalIb[i]*pSinalIb[i];
	 gc.Ic=gc.Ic+pSinalIc[i]*pSinalIc[i];
	 */

 }




 N90a=((int)((((float)N360)*(FATOR_FLEXa+polinomioUA[3]*180/PI))/360.0)  ) >>2;
 N90b=((int)((((float)N360)*(FATOR_FLEXb+polinomioUB[3]*180/PI))/360.0)  ) >>2;
 N90c=((int)((((float)N360)*(FATOR_FLEXc+polinomioUC[3]*180/PI))/360.0)  ) >>2;

 for (int i=0;i<(int)(N360/2);i++)   //método ruidementar de cálculo de Q, apenas para pegar o sinal do Q.
 {
	 gc.Qa=gc.Qa+pSinalUa[i]*pSinalIa[i+N90a];  //integral de v*i_defasado_90graus
	 gc.Qb=gc.Qb+pSinalUb[i]*pSinalIb[i+N90b];
	 gc.Qc=gc.Qc+pSinalUc[i]*pSinalIc[i+N90c];
 }


 if (cont_pot % 2!=0)
 {
 acumulados.Pa=acumulados.Pa+gc.Pa;
 acumulados.Pb=acumulados.Pb+gc.Pb;
 acumulados.Pc=acumulados.Pc+gc.Pc;
 acumulados.Qa=acumulados.Qa+gc.Qa;
 acumulados.Qb=acumulados.Qb+gc.Qb;
 acumulados.Qc=acumulados.Qc+gc.Qc;
 acumulados.Npontos=acumulados.Npontos+N360;

 /*
 acumulados.Ua=acumulados.Ua+gc.Ua;
 acumulados.Ub=acumulados.Ub+gc.Ub;
 acumulados.Uc=acumulados.Uc+gc.Uc;
 acumulados.Ia=acumulados.Ia+gc.Ia;
 acumulados.Ib=acumulados.Ib+gc.Ib;
 acumulados.Ic=acumulados.Ic+gc.Ic;
 */
 }
 cont_pot=cont_pot+1;

}

grandezas_calculadas_t CalculaGrandezas(int num_componentes)
{
  int bi;


	grandezas_calculadas_t gc,gc1;

	gc.Ua=0;
	gc.Ub=0;
	gc.Uc=0;
	gc.Ia=0;
	gc.Ib=0;
	gc.Ic=0;
	gc.Pa=0;
	gc.Pb=0;
	gc.Pc=0;
	gc.Qa=0;
	gc.Qb=0;
	gc.Qc=0;



#define canalUa 0
#define canalUb 1
#define canalUc 2
#define canalIa 3
#define canalIb 4
#define canalIc 5

	gc.freqA=pEspectroDisplay[canalUa][0].Freq;

	#if   COM_FLEX==SIM
	  if ((EquipamentoCalibrado == NAO))
	  {
		  FATOR_FLEXa=16.9; // +IrmsA*IrmsA* + IrmsA*;
		  FATOR_FLEXb=16.9;
		  FATOR_FLEXc=16.9;
	  }
	  else
	  {
		  FATOR_FLEXa=16.9;
		  FATOR_FLEXb=16.9;
		  FATOR_FLEXc=16.9;
	  }
	#endif


	if ( 0)
		 for (int i=0;i<num_componentes;i++)
		 {
			 pEspectroDisplay[canalUa][i].Phase= pEspectroDisplay[canalUa][i].Phase+polinomioUA[3]*180/PI;
			 pEspectroDisplay[canalUb][i].Phase= pEspectroDisplay[canalUb][i].Phase+polinomioUB[3]*180/PI;
			 pEspectroDisplay[canalUc][i].Phase= pEspectroDisplay[canalUc][i].Phase+polinomioUC[3]*180/PI;
		 }



	 for (int i=0;i<1;i++)
	 {

			gc.Ua=gc.Ua + pEspectroDisplay[canalUa][i].Mag*pEspectroDisplay[canalUa][i].Mag  ;
		    gc.Ub=gc.Ub + pEspectroDisplay[canalUb][i].Mag*pEspectroDisplay[canalUb][i].Mag ;
			gc.Uc=gc.Uc + pEspectroDisplay[canalUc][i].Mag*pEspectroDisplay[canalUc][i].Mag  ;

			gc.Ia=gc.Ia + pEspectroDisplay[canalIa][i].Mag*pEspectroDisplay[canalIa][i].Mag ;
		    gc.Ib=gc.Ib + pEspectroDisplay[canalIb][i].Mag*pEspectroDisplay[canalIb][i].Mag ;
			gc.Ic=gc.Ic + pEspectroDisplay[canalIc][i].Mag*pEspectroDisplay[canalIc][i].Mag  ;


			bi=bestindex(pEspectroDisplay[canalUa][i],pEspectroDisplay[canalIa],num_componentes);
			if (bi<num_componentes)
			{   //vou deixar esse canal, tal qual estava na calibração do toroide.
				gc.Pa=gc.Pa+ pEspectroDisplay[canalUa][i].Mag*pEspectroDisplay[canalIa][bi].Mag*cos((pEspectroDisplay[canalUa][i].Phase-pEspectroDisplay[canalIa][bi].Phase+FATOR_FLEXa+polinomioUA[3]*180/PI)*PI/180);
				gc.Qa=gc.Qa- pEspectroDisplay[canalUa][i].Mag*pEspectroDisplay[canalIa][bi].Mag*sin((pEspectroDisplay[canalUa][i].Phase-pEspectroDisplay[canalIa][bi].Phase+FATOR_FLEXa+polinomioUA[3]*180/PI)*PI/180);
			}
			bi=bestindex(pEspectroDisplay[canalUb][i],pEspectroDisplay[canalIb],num_componentes);
			if (bi<num_componentes)
			{

				gc.Pb=gc.Pb+ pEspectroDisplay[canalUb][i].Mag*pEspectroDisplay[canalIb][bi].Mag*cos((pEspectroDisplay[canalUb][i].Phase-pEspectroDisplay[canalIb][bi].Phase+FATOR_FLEXb +polinomioUB[3]*180/PI)*PI/180);
				gc.Qb=gc.Qb- pEspectroDisplay[canalUb][i].Mag*pEspectroDisplay[canalIb][bi].Mag*sin((pEspectroDisplay[canalUb][i].Phase-pEspectroDisplay[canalIb][bi].Phase+FATOR_FLEXb +polinomioUB[3]*180/PI)*PI/180);
			}
			bi=bestindex(pEspectroDisplay[canalUc][i],pEspectroDisplay[canalIc],num_componentes);
			if (bi<num_componentes)
			{
				gc.Pc=gc.Pc+ pEspectroDisplay[canalUc][i].Mag*pEspectroDisplay[canalIc][bi].Mag*cos((pEspectroDisplay[canalUc][i].Phase-pEspectroDisplay[canalIc][bi].Phase+FATOR_FLEXc+polinomioUC[3]*180/PI)*PI/180);
				gc.Qc=gc.Qc- pEspectroDisplay[canalUc][i].Mag*pEspectroDisplay[canalIc][bi].Mag*sin((pEspectroDisplay[canalUc][i].Phase-pEspectroDisplay[canalIc][bi].Phase+FATOR_FLEXc+polinomioUC[3]*180/PI)*PI/180);
			}
	 }






	 if (gc.Qa==0)
	 {gc.Qa=0;}

	 if (num_componentes>1)
	 {
		 gc1=gc;
		 for (int i=1;i<num_componentes;i++)
		 {
			 	//aqui devem existir as tabelas de correção de módulo e fase da corrente


				gc.Ua=gc.Ua + pEspectroDisplay[canalUa][i].Mag*pEspectroDisplay[canalUa][i].Mag ;
				gc.Ub=gc.Ub + pEspectroDisplay[canalUb][i].Mag*pEspectroDisplay[canalUb][i].Mag ;
				gc.Uc=gc.Uc + pEspectroDisplay[canalUc][i].Mag*pEspectroDisplay[canalUc][i].Mag  ;

				gc.Ia=gc.Ia + pEspectroDisplay[canalIa][i].Mag*pEspectroDisplay[canalIa][i].Mag  ;
				gc.Ib=gc.Ib + pEspectroDisplay[canalIb][i].Mag*pEspectroDisplay[canalIb][i].Mag ;
				gc.Ic=gc.Ic + pEspectroDisplay[canalIc][i].Mag*pEspectroDisplay[canalIc][i].Mag  ;


				bi=bestindex(pEspectroDisplay[canalUa][i],pEspectroDisplay[canalIa],num_componentes);
				if (bi<num_componentes)
				{
					gc.Pa=gc.Pa+ pEspectroDisplay[canalUa][i].Mag*pEspectroDisplay[canalIa][bi].Mag*cos((FATOR_FLEXa+pEspectroDisplay[canalUa][i].Phase-pEspectroDisplay[canalIa][bi].Phase+(polinomioUA[3] )*180/PI)*PI/180);
					gc.Qa=gc.Qa- pEspectroDisplay[canalUa][i].Mag*pEspectroDisplay[canalIa][bi].Mag*sin((FATOR_FLEXa+pEspectroDisplay[canalUa][i].Phase-pEspectroDisplay[canalIa][bi].Phase+(polinomioUA[3] )*180/PI)*PI/180);
				}
				bi=bestindex(pEspectroDisplay[canalUb][i],pEspectroDisplay[canalIb],num_componentes);
				if (bi<num_componentes)
				{
					gc.Pb=gc.Pb+ pEspectroDisplay[canalUb][i].Mag*pEspectroDisplay[canalIb][bi].Mag*cos((FATOR_FLEXb+pEspectroDisplay[canalUb][i].Phase-pEspectroDisplay[canalIb][bi].Phase+(polinomioUB[3] )*180/PI)*PI/180);
					gc.Qb=gc.Qb- pEspectroDisplay[canalUb][i].Mag*pEspectroDisplay[canalIb][bi].Mag*sin((FATOR_FLEXb+pEspectroDisplay[canalUb][i].Phase-pEspectroDisplay[canalIb][bi].Phase+(polinomioUB[3] )*180/PI)*PI/180);
				}
				bi=bestindex(pEspectroDisplay[canalUc][i],pEspectroDisplay[canalIc],num_componentes);
				if (bi<num_componentes)
				{
					gc.Pc=gc.Pc+ pEspectroDisplay[canalUc][i].Mag*pEspectroDisplay[canalIc][bi].Mag*cos((FATOR_FLEXc+pEspectroDisplay[canalUc][i].Phase-pEspectroDisplay[canalIc][bi].Phase+(polinomioUC[3] )*180/PI)*PI/180);
					gc.Qc=gc.Qc- pEspectroDisplay[canalUc][i].Mag*pEspectroDisplay[canalIc][bi].Mag*sin((FATOR_FLEXc+pEspectroDisplay[canalUc][i].Phase-pEspectroDisplay[canalIc][bi].Phase+(polinomioUC[3] )*180/PI)*PI/180);
				}
		 }

		 if (gc.Qa==0)
		 {gc.Qa=0;}

		 gc.Ua=gc.Ua*0.5;
		 gc.Ub=gc.Ub*0.5;
		 gc.Uc=gc.Uc*0.5;
		 gc.Ia=gc.Ia*0.5;
		 gc.Ib=gc.Ib*0.5;
		 gc.Ic=gc.Ic*0.5;
		 gc.Pa=gc.Pa*0.5;
		 gc.Pb=gc.Pb*0.5;
		 gc.Pc=gc.Pc*0.5;
		 gc.Qa=gc.Qa*0.5;
		 gc.Qb=gc.Qb*0.5;
		 gc.Qc=gc.Qc*0.5;
		 gc1.Ua=gc1.Ua*0.5;
		 gc1.Ub=gc1.Ub*0.5;
		 gc1.Uc=gc1.Uc*0.5;
		 gc1.Ia=gc1.Ia*0.5;
		 gc1.Ib=gc1.Ib*0.5;
		 gc1.Ic=gc1.Ic*0.5;




		if ((gc1.Ua!=0)&&(gc.Ua>gc1.Ua))
		{
			DhtUA = ((100.0 * sqrt(gc.Ua   - gc1.Ua )) / sqrt(gc1.Ua));  //aqui os valores U e I estão ao quadrado...
		}
		else DhtUA =0;



		if ((gc1.Ub!=0)&&(gc.Ub>gc1.Ub))
		{
			DhtUB = ((100.0 * sqrt(gc.Ub   - gc1.Ub )) / sqrt(gc1.Ub));
		}
		else DhtUB =0;

		if ((gc1.Uc!=0)&&(gc.Uc>gc1.Uc))
		{
			DhtUC = ((100.0 * sqrt(gc.Uc   - gc1.Uc )) / sqrt(gc1.Uc));
		}
		else DhtUC =0;

		if ((gc1.Ia!=0)&&(gc.Ia>gc1.Ia))
		{
			DhtIA = ((100.0 * sqrt(gc.Ia   - gc1.Ia )) / sqrt(gc1.Ia));  //aqIi os valores I e I estão ao qIadrado...
		}
		else DhtIA =0;
		if ((gc1.Ib!=0)&&(gc.Ib>gc1.Ib))
		{
			DhtIB = ((100.0 * sqrt(gc.Ib   - gc1.Ib )) / sqrt(gc1.Ib));
		}
		else DhtIB =0;

		if ((gc1.Ic!=0)&&(gc.Ic>gc1.Ic))
		{
			DhtIC = ((100.0 * sqrt(gc.Ic   - gc1.Ic )) / sqrt(gc1.Ic));
		}
		else DhtIC =0;
	 }


#if 1  //em teste, criado só para não entrar dentro
if (num_componentes==1 )
		{


			if (acumulados.Npontos!=0)
			{

			gc.Pa=2*acumulados.Pa/acumulados.Npontos;
			gc.Pb=2*acumulados.Pb/acumulados.Npontos;
			gc.Pc=2*acumulados.Pc/acumulados.Npontos;
			//gc.Qa=acumulados.Qa;   //NÃO faz senteido dividir por  acumulados.Npontos já que o valor só será usado para pegar o sinal!
			//gc.Qb=acumulados.Qb;
			//gc.Qc=acumulados.Qc;

		/*	gc.Ua=acumulados.Ua/acumulados.Npontos;
			gc.Ub=acumulados.Ub/acumulados.Npontos;
			gc.Uc=acumulados.Uc/acumulados.Npontos;
			gc.Ia=acumulados.Ia/acumulados.Npontos;
			gc.Ib=acumulados.Ib/acumulados.Npontos;
			gc.Ic=acumulados.Ic/acumulados.Npontos;
*/


				 acumulados.Pa=0;
				 acumulados.Pb=0;
				 acumulados.Pc=0;
				 acumulados.Qa=0;
				 acumulados.Qb=0;
				 acumulados.Qc=0;
				 /*
				 acumulados.Ua=0;
				 acumulados.Ub=0;
				 acumulados.Uc=0;
				 acumulados.Ia=0;
				 acumulados.Ib=0;
				 acumulados.Ic=0;
				 */
				 acumulados.Npontos=0;







			}
		}

#endif

	gc.Ua=sqrt(gc.Ua);
	gc.Ub=sqrt(gc.Ub);
	gc.Uc=sqrt(gc.Uc);



	gc.Ia=sqrt(gc.Ia);
	gc.Ib=sqrt(gc.Ib);
	gc.Ic=sqrt(gc.Ic);




	//vamos linearizar o m�dulo da corrente, pois em baixas correntes ele fica ruim...
#if 1
	 float poli,x,cosfiIA=1,sinfiIA=0, cosfiIB=1,sinfiIB=0, cosfiIC=1,sinfiIC=0;
	 static float fatorIa=1,fatorIb=1,fatorIc=1;



#if  0 //COM_FLEX==SIM
	#if (COM_LINEARIZACAO_DE_MODULO_DE_CORREMTE==SIM)
	  ///if ((EquipamentoCalibrado== SIM))
	 if ( FatorCalibIa!=1.0)

	  {

	  x=gc.Ia;
	  gc.Ia = gc.Ia *gc.Ia*FatorCalibIa*FatorCalibIa * -3.78208312485555e-06	+gc.Ia*FatorCalibIa* 1.02126355194155 -2.03548780054373;
	  gc.Ia=gc.Ia/FatorCalibIa;
	  fatorIa=gc.Ia/x;

	  x=gc.Ib;
	  gc.Ib = gc.Ib *gc.Ib*FatorCalibIb*FatorCalibIb * -3.78208312485555e-06	+gc.Ib*FatorCalibIb* 1.02126355194155 -2.03548780054373;
	  gc.Ib=gc.Ib/FatorCalibIb;
	  fatorIb=gc.Ib/x;

	  x=gc.Ic;
	  gc.Ic = gc.Ic *gc.Ic*FatorCalibIc*FatorCalibIc * -3.78208312485555e-06	+gc.Ic*FatorCalibIc* 1.02126355194155 -2.03548780054373;
	  gc.Ic=gc.Ic/FatorCalibIc;
	  fatorIc=gc.Ic/x;

	  }
	#endif
#endif


#if 0
	if (UtilizaPolinomios == SIM)
	{
		// linearizacao de corrente
		// FASE A
		if (gc.Ia*FatorCalibIa < 0.120)
		{
			//polinomio para baixas correntes
			//linearizacao de fase

			x = (gc.Ia);
			poli = x * polinomioIA[2] + polinomioIA[3];
			x = x * x;
			poli = x * polinomioIA[1] + poli;
			x = x * (gc.Ia);
			poli = x * polinomioIA[0] + poli;
			cosfiIA = cos(poli);
			sinfiIA = sin(poli);

			//linearizacao de modulo

			polinomioModuloIa[0]=-92.5609    ;//-0.0176;
	        polinomioModuloIa[1]= 19.7286    ; //   0.0284;
	        polinomioModuloIa[2]=  -0.3649  ; //   0.9906  ;
	        polinomioModuloIa[3]=  0.0288;// -0.0016;

#if (COM_LINEARIZACAO_DE_MODULO_DE_CORREMTE==SIM)
			x = (gc.Ia*FatorCalibIa);
			poli = x * polinomioModuloIa[2] + polinomioModuloIa[3];
			x = x * x;
			poli = x * polinomioModuloIa[1] + poli;
			x = x * (gc.Ia*FatorCalibIa);
			gc.Ia = x * polinomioModuloIa[0] + poli;
			gc.Ia =gc.Ia /FatorCalibIa;
#endif

		}



	if (gc.Ib*FatorCalibIb < 0.120)
	{
		//polinomio para baixas correntes
		//linearizacao de fase

		x = (gc.Ib);
		poli = x * polinomioIB[2] + polinomioIB[3];
		x = x * x;
		poli = x * polinomioIB[1] + poli;
		x = x * (gc.Ib);
		poli = x * polinomioIB[0] + poli;
		cosfiIB = cos(poli);
		sinfiIB = sin(poli);

		//linearizacao de modulo

		polinomioModuloIb[0]=-92.5609    ;//-0.0176;
        polinomioModuloIb[1]= 19.7286    ; //   0.0284;
        polinomioModuloIb[2]=  -0.3649  ; //   0.9906  ;
        polinomioModuloIb[3]=  0.0288;// -0.0016;

#if (COM_LINEARIZACAO_DE_MODULO_DE_CORREMTE==SIM)
		x = (gc.Ib*FatorCalibIb);
		poli = x * polinomioModuloIb[2] + polinomioModuloIb[3];
		x = x * x;
		poli = x * polinomioModuloIb[1] + poli;
		x = x * (gc.Ib*FatorCalibIb);
		gc.Ib = x * polinomioModuloIb[0] + poli;
		gc.Ib =gc.Ib /FatorCalibIb;
#endif

	}


if (gc.Ic*FatorCalibIc < 0.120)
{
	//polinomio para baixas correntes
	//linearizacao de fase

	x = (gc.Ic);
	poli = x * polinomioIC[2] + polinomioIC[3];
	x = x * x;
	poli = x * polinomioIC[1] + poli;
	x = x * (gc.Ic);
	poli = x * polinomioIC[0] + poli;
	cosfiIC = cos(poli);
	sinfiIC = sin(poli);

	//linearizacao de modulo

	polinomioModuloIc[0]=-92.5609    ;//-0.0176;
    polinomioModuloIc[1]= 19.7286    ; //   0.0284;
    polinomioModuloIc[2]=  -0.3649  ; //   0.9906  ;
    polinomioModuloIc[3]=  0.0288;// -0.0016;

#if (COM_LINEARIZACAO_DE_MODULO_DE_CORREMTE==SIM)
	x = (gc.Ic*FatorCalibIc);
	poli = x * polinomioModuloIc[2] + polinomioModuloIc[3];
	x = x * x;
	poli = x * polinomioModuloIc[1] + poli;
	x = x * (gc.Ic*FatorCalibIc);
	gc.Ic = x * polinomioModuloIc[0] + poli;
	gc.Ic =gc.Ic /FatorCalibIc;
#endif

	}
}

#endif

#endif

  if (num_componentes==1 )
   {
	gc.Sa=gc.Ua*gc.Ia;
	gc.Sb=gc.Ub*gc.Ib;
	gc.Sc=gc.Uc*gc.Ic;






	float sinal_Qa=-(float)signum(gc.Qa);
	float sinal_Qb=-(float)signum(gc.Qb);
	float sinal_Qc=-(float)signum(gc.Qc);

	gc.Qa=sinal_Qa*sqrt(gc.Sa*gc.Sa-gc.Pa*gc.Pa);
	gc.Qb=sinal_Qb*sqrt(gc.Sb*gc.Sb-gc.Pb*gc.Pb);
	gc.Qc=sinal_Qc*sqrt(gc.Sc*gc.Sc-gc.Pc*gc.Pc);
	if (gc.Sa>gc.Pa)
	{
		gc.Qa=sinal_Qa*sqrt(gc.Sa*gc.Sa-gc.Pa*gc.Pa);
	}
	else
	{
		gc.Pa=gc.Sa;
		gc.Qa=0;
		//sinal_Qa=1.0;
	}
	if (gc.Sb>gc.Pb)
	{
		gc.Qb=sinal_Qb*sqrt(gc.Sb*gc.Sb-gc.Pb*gc.Pb);
	}
	else
	{
		gc.Pb=gc.Sb;
		gc.Qb=0;
		//sinal_Qa=1.0;
	}
	if (gc.Sc>gc.Pc)
	{
		gc.Qc=sinal_Qc*sqrt(gc.Sc*gc.Sc-gc.Pc*gc.Pc);
	}
	else
	{
		gc.Pc=gc.Sc;
		gc.Qc=0;
		//sinal_Qa=1.0;
	}

#if COM_FLEX == SIM
		{
	//	 gc.Qa=-gc.Qa;
	//	 gc.Qb=-gc.Qb;
	//	 gc.Qc=-gc.Qc;
		}
#endif

#if 1 //aqui se faz a calibração das potencias...
	if (num_componentes==1)
	{


#if 0  //COM_FLEX == SIM
	#define cosfiVA   cos((-polinomioUA[3]+1.0*FATOR_FLEXa*PI/180)*sinal_Qa)
	#define sinfiVA   sin((-polinomioUA[3]+1.0*FATOR_FLEXa*PI/180)*sinal_Qa)
	#define cosfiVB   cos((-polinomioUB[3]+1.0*FATOR_FLEXb*PI/180)*sinal_Qb)
	#define sinfiVB   sin((-polinomioUB[3]+1.0*FATOR_FLEXb*PI/180)*sinal_Qb)
	#define cosfiVC   cos((-polinomioUC[3]+1.0*FATOR_FLEXc*PI/180)*sinal_Qc)
	#define sinfiVC   sin((-polinomioUC[3]+1.0*FATOR_FLEXc*PI/180)*sinal_Qc)
#else

	#define cosfiVA   cos((-polinomioUA[3]+1.0*FATOR_FLEXa*PI/180) )
	#define sinfiVA   sin((-polinomioUA[3]+1.0*FATOR_FLEXa*PI/180) )
	#define cosfiVB   cos((-polinomioUB[3]+1.0*FATOR_FLEXb*PI/180) )
	#define sinfiVB   sin((-polinomioUB[3]+1.0*FATOR_FLEXb*PI/180) )
	#define cosfiVC   cos((-polinomioUC[3]+1.0*FATOR_FLEXc*PI/180) )
	#define sinfiVC   sin((-polinomioUC[3]+1.0*FATOR_FLEXc*PI/180) )
#endif

		//if (acumulados.Npontos!=0)
		{

		 	gc.Pa = fatorIa*gc.Pa * (cosfiVA * cosfiIA - sinfiVA * sinfiIA) - gc.Qa * (sinfiVA * cosfiIA + cosfiVA * sinfiIA);
		 	gc.Pb = fatorIb*gc.Pb * (cosfiVB * cosfiIB - sinfiVB * sinfiIB) - gc.Qb * (sinfiVB * cosfiIB + cosfiVB * sinfiIB);
		 	gc.Pc = fatorIc*gc.Pc * (cosfiVC * cosfiIC - sinfiVC * sinfiIC) - gc.Qc * (sinfiVC * cosfiIC + cosfiVC * sinfiIC);




			gc.Qa=sinal_Qa*sqrt(gc.Sa*gc.Sa-gc.Pa*gc.Pa);
			gc.Qb=sinal_Qb*sqrt(gc.Sb*gc.Sb-gc.Pb*gc.Pb);
			gc.Qc=sinal_Qc*sqrt(gc.Sc*gc.Sc-gc.Pc*gc.Pc);

			/* acumulados.Pa=0;
			 acumulados.Pb=0;
			 acumulados.Pc=0;
			 acumulados.Ua=0;
			 acumulados.Ub=0;
			 acumulados.Uc=0;
			 acumulados.Ia=0;
			 acumulados.Ib=0;
			 acumulados.Ic=0;
			 acumulados.Npontos=0;*/
		}

	}

#endif



	if ((gc.Sa==0)||(gc.Pa==0)||(gc.Pa>gc.Sa))
	{
		gc.fpa=1.0;
		gc.Qa=0;
		gc.Pa=gc.Sa;
	}
	else
		gc.fpa=sinalfp(gc.Pa,gc.Qa)*fabs(gc.Pa)/gc.Sa;
	if ((gc.Sb==0)||(gc.Pb==0)||(gc.Pb>gc.Sb))
	{
		gc.fpb=1.0;
		gc.Qb=0;
		gc.Pb=gc.Sb;
	}
	else
		gc.fpb=sinalfp(gc.Pb,gc.Qb)*fabs(gc.Pb)/gc.Sb;

	if ((gc.Sc==0)||(gc.Pc==0)||(gc.Pc>gc.Sc))
	{
		gc.fpc=1.0;
		gc.Qc=0;
		gc.Pc=gc.Sc;
	}
	else
		gc.fpc=sinalfp(gc.Pc,gc.Qc)*fabs(gc.Pc)/gc.Sc;


	if (gc.fpa<=-0.9999) gc.fpa=1.0;
	if (gc.fpb<=-0.9999) gc.fpb=1.0;
	if (gc.fpc<=-0.9999) gc.fpc=1.0;

	float sinal_Pa= signum(gc.Pa);
	float sinal_Pb= signum(gc.Pb);
	float sinal_Pc= signum(gc.Pc);


    gc.Pa=sinal_Pa*gc.Sa*fabs(gc.fpa);
 	gc.Pb=sinal_Pb*gc.Sb*fabs(gc.fpb);
  	gc.Pc=sinal_Pc*gc.Sc*fabs(gc.fpc);

	gc.Qa=sinal_Qa*sqrt(gc.Sa*gc.Sa-gc.Pa*gc.Pa);
	gc.Qb=sinal_Qb*sqrt(gc.Sb*gc.Sb-gc.Pb*gc.Pb);
	gc.Qc=sinal_Qc*sqrt(gc.Sc*gc.Sc-gc.Pc*gc.Pc);


	gc.Pt= gc.Pa+gc.Pb+gc.Pc;

	gc.Qt= gc.Qa+gc.Qb+gc.Qc;

	gc.St=sqrt(gc.Qt*gc.Qt+gc.Pt*gc.Pt);






	if ((gc.St==0)||(gc.Pt==0)||(gc.Pt>gc.St)) //||(gc.fpt<=-1.0)
	{
		gc.fpt=1.0;
		gc.Qt=0;
		gc.Pt=gc.St;
	}
	else
		gc.fpt=sinalfp(gc.Pt,gc.Qt)*fabs(gc.Pt)/gc.St;




	if (gc.fpt<=-0.9999) gc.fpt=1.0;

   }

return gc;

}


void CalculaPotencias()
{
	float tempfloat;
     grandezas_calculadas_t gc,gc1;

/*
					FatorCalibUa_=150.0/630.0;
					FatorCalibUb_=150.0/629.0;
					FatorCalibUc_=150.0/630.0;
     				FatorCalibIa_=2.5/141.0;
					FatorCalibIb_=2.5/141.0;
					FatorCalibIc_=2.5/141.0;


					FatorCalibUa=150.0/630.0;
					FatorCalibUb=150.0/629.0;
				    FatorCalibUc=150.0/631.0;
     				FatorCalibIa=2.5/141.0;
					FatorCalibIb=2.5/141.0;
					FatorCalibIc=2.5/141.0;
					relacaoTP=1.0;
					relacaoTC=1.0;
*/


#if  (EQUIP_LINHA50==MD_EQUIP)

     gc =CalculaGrandezas(NPONTOS_ESPECTRAIS_INTERP);
     extern void MX_LWIP_Process( );
     //MX_LWIP_Process( );

     gc1=CalculaGrandezas(1); //calculos com a fundamental
     //gc=gc1;
     extern void MX_LWIP_Process( );
    // MX_LWIP_Process( );

     static short contEstouVivo = 0;
     static float zerado=0.0;
     contEstouVivo=contEstouVivo+1;
     if (contEstouVivo>3)
	 	 zerado=1.0;

	UrmsA = FatorCalibUa*zerado* relacaoTP  * gc1.Ua;
	UrmsB = FatorCalibUb*zerado * relacaoTP  * gc1.Ub;
	UrmsC = FatorCalibUc*zerado * relacaoTP  * gc1.Uc;

	UrmsA_ = FatorCalibUa_ *zerado* relacaoTP * gc.Ua;	//o '_' indica o true-rms
	UrmsB_ = FatorCalibUb_ *zerado* relacaoTP * gc.Ub;
	UrmsC_ = FatorCalibUc_ *zerado* relacaoTP * gc.Uc;

	IrmsA = FatorCalibIa *zerado* relacaoTC * gc1.Ia;
	IrmsB = FatorCalibIb *zerado* relacaoTC * gc1.Ib;
	IrmsC = FatorCalibIc *zerado* relacaoTC * gc1.Ic;

	IrmsA_ = FatorCalibIa_ *zerado* relacaoTC * gc.Ia;
	IrmsB_ = FatorCalibIb_ *zerado* relacaoTC * gc.Ib;
	IrmsC_ = FatorCalibIc_ *zerado * relacaoTC * gc.Ic;

	FreqA=gc1.freqA;




	//float DhtIA1;
	//float DhtIB1;
	//float DhtIC1;



#if (FP_COM_HARMONICAS == SIM)
	PotAtivA = gc.Pa* FatorCalibUa_ *FatorCalibIa_ *relacaoTP * relacaoTC ;
	PotAtivB = gc.Pb* FatorCalibUa_ *FatorCalibIa_ *relacaoTP * relacaoTC ;
	PotAtivC = gc.Pc* FatorCalibUa_ *FatorCalibIa_ *relacaoTP * relacaoTC ;
	PotAtivT = gc.Pt* FatorCalibUa_ *FatorCalibIa_ *relacaoTP * relacaoTC ;
	PotReatA = gc.Qa* FatorCalibUa_ *FatorCalibIa_ *relacaoTP * relacaoTC ;
	PotReatB = gc.Qb* FatorCalibUa_ *FatorCalibIa_ *relacaoTP * relacaoTC ;
	PotReatC = gc.Qc* FatorCalibUa_ *FatorCalibIa_ *relacaoTP * relacaoTC ;
	PotReatT = gc.Qt* FatorCalibUa_ *FatorCalibIa_ *relacaoTP * relacaoTC ;
	PotAparA = gc.Sa* FatorCalibUa_ *FatorCalibIa_ *relacaoTP * relacaoTC ;
	PotAparB = gc.Sb* FatorCalibUa_ *FatorCalibIa_ *relacaoTP * relacaoTC ;
	PotAparC = gc.Sc* FatorCalibUa_ *FatorCalibIa_ *relacaoTP * relacaoTC ;
	PotAparT = gc.St* FatorCalibUa_ *FatorCalibIa_ *relacaoTP * relacaoTC ;
	FatPotA	=gc.fpa;
	FatPotB	=gc.fpb;
	FatPotC	=gc.fpc;
	FatPotT =gc.fpt;
#else

#include <math.h>

	tempfloat = gc1.Pa* FatorCalibUa *FatorCalibIa *relacaoTP * relacaoTC ;
	if (isnan(tempfloat)==0)
		PotAtivA=tempfloat;

	tempfloat = gc1.Pb* FatorCalibUa *FatorCalibIa *relacaoTP * relacaoTC ;
	if (isnan(tempfloat)==0)
		PotAtivB=tempfloat;

	tempfloat = gc1.Pc* FatorCalibUa *FatorCalibIa *relacaoTP * relacaoTC ;
	if (isnan(tempfloat)==0)
		PotAtivC=tempfloat;

	//tempfloat = gc1.Pt* FatorCalibUa *FatorCalibIa *relacaoTP * relacaoTC ;
	//if (isnan(tempfloat)==0)
	//	PotAtivT=tempfloat;
	PotAtivT=PotAtivA+PotAtivB+PotAtivC;

	tempfloat = gc1.Qa* FatorCalibUa *FatorCalibIa *relacaoTP * relacaoTC ;
	if (isnan(tempfloat)==0)
		PotReatA=tempfloat;

	tempfloat = gc1.Qb* FatorCalibUa *FatorCalibIa *relacaoTP * relacaoTC ;
	if (isnan(tempfloat)==0)
		PotReatB=tempfloat;

	tempfloat = gc1.Qc* FatorCalibUa *FatorCalibIa *relacaoTP * relacaoTC ;
	if (isnan(tempfloat)==0)
		PotReatC=tempfloat;

	//tempfloat = gc1.Qt* FatorCalibUa *FatorCalibIa *relacaoTP * relacaoTC ;
	//if (isnan(tempfloat)==0)
	//	PotReatT=tempfloat;
	PotReatT=PotReatA+PotReatB+PotReatC;

	tempfloat = gc1.Sa* FatorCalibUa *FatorCalibIa *relacaoTP * relacaoTC ;
	if (isnan(tempfloat)==0)
		PotAparA=tempfloat;

	tempfloat = gc1.Sb* FatorCalibUa *FatorCalibIa *relacaoTP * relacaoTC ;
	if (isnan(tempfloat)==0)
		PotAparB=tempfloat;

	tempfloat = gc1.Sc* FatorCalibUa *FatorCalibIa *relacaoTP * relacaoTC ;
	if (isnan(tempfloat)==0)
		PotAparC=tempfloat;

	tempfloat = gc1.St* FatorCalibUa *FatorCalibIa *relacaoTP * relacaoTC ;
	if (isnan(tempfloat)==0)
		PotAparT=tempfloat;


	if (isnan(gc1.fpa)==0)
		FatPotA=gc1.fpa;

	if (isnan(gc1.fpb)==0)
		FatPotB=gc1.fpb;


	if (isnan(gc1.fpc)==0)
		FatPotC=gc1.fpc;


	if (isnan(gc1.fpt)==0)
		FatPotT =gc1.fpt;
#endif


#endif



	float UA2, UB2, UC2;
 	char capator_em_acao = ON;
	#if ((EQUIP_LINHA50== CA_EQUIP)||((EQUIP_LINHA50== CT_EQUIP)))
 		 capator_em_acao = OFF;
	#endif

	//C�lculo de distor��es harmonicas

//	DhtUA = ((100.0 * sqrt(gc.Ua * gc.Ua - gc1.Ua * gc1.Ua)) / gc1.Ua);
//	DhtUB = ((100.0 * sqrt(gc.Ub * gc.Ub - gc1.Ub * gc1.Ub)) / gc1.Ub);
//	DhtUC = ((100.0 * sqrt(gc.Uc * gc.Uc - gc1.Uc * gc1.Uc)) / gc1.Uc);

/*
			if (UrmsA != 0.0)
			{
				if (UrmsA_ >= UrmsA)
				{
					DhtUAmedia = ((100.0 * sqrt(UrmsA_ * UrmsA_ - UrmsA * UrmsA)) / UrmsA);
					DhtUAtemp = DhtUAtemp + DhtUAmedia;
				}
				else
				{
					DhtUAtemp = DhtUAtemp + DhtUAmedia;
				}
			}
			else
			{
				DhtUA = 0.0;
				UrmsA = UrmsA_;
			}

			if (UrmsB != 0.0)
			{
				if (UrmsB_ >= UrmsB)
				{
					DhtUBmedia = ((100.0 * sqrt(UrmsB_ * UrmsB_ - UrmsB * UrmsB)) / UrmsB);
					DhtUBtemp = DhtUBtemp + DhtUBmedia;
				}
				else
				{
					DhtUBtemp = DhtUBtemp + DhtUBmedia;
				}
			}
			else
			{
				DhtUB = 0.0;
				UrmsB = UrmsB_;
			}

			if (UrmsC != 0.0)
			{
				if (UrmsC_ >= UrmsC)
				{
					DhtUCmedia = ((100.0 * sqrt(UrmsC_ * UrmsC_ - UrmsC * UrmsC)) / UrmsC);
					DhtUCtemp = DhtUCtemp + DhtUCmedia;
				}
				else
				{
					DhtUCtemp = DhtUCtemp + DhtUCmedia;
				}
			}
			else
			{
				DhtUC = 0.0;
				UrmsC = UrmsC_;
			}

			if (IrmsA != 0.0)
			{
				if (IrmsA_ >= IrmsA)
				{
					DhtIAmedia = ((100.0 * sqrt(IrmsA_ * IrmsA_ - IrmsA * IrmsA)) / IrmsA);
					DhtIAtemp = DhtIAtemp + DhtIAmedia;
				}
				else
				{
					DhtIAtemp = DhtIAtemp + DhtIAmedia;
				}
			}
			else
			{
				DhtIA = 0.0;
				IrmsA = IrmsA_;
			}

			if (IrmsB != 0.0)
			{
				if (IrmsB_ >= IrmsB)
				{
					DhtIBmedia = ((100.0 * sqrt(IrmsB_ * IrmsB_ - IrmsB * IrmsB)) / IrmsB);
					DhtIBtemp = DhtIBtemp + DhtIBmedia;
				}
				else
				{
					DhtIBtemp = DhtIBtemp + DhtIBmedia;
				}
			}
			else
			{
				DhtIB = 0.0;
				IrmsB = IrmsB_;
			}

			if (IrmsC != 0.0)
			{
				if (IrmsC_ >= IrmsC)
				{
					DhtICmedia = ((100.0 * sqrt(IrmsC_ * IrmsC_ - IrmsC * IrmsC)) / IrmsC);
					DhtICtemp = DhtICtemp + DhtICmedia;
				}
				else
				{
					DhtICtemp = DhtICtemp + DhtICmedia;
				}
			}
			else
			{
				DhtIC = 0.0;
				IrmsC = IrmsC_;
			}

			contadht++;

			if (contadht == 5)
			{

				DhtUA = DhtUAtemp / 5;
				DhtIA = DhtIAtemp / 5;
				DhtUB = DhtUBtemp / 5;
				DhtIB = DhtIBtemp / 5;
				DhtUC = DhtUCtemp / 5;
				DhtIC = DhtICtemp / 5;

				DhtUAtemp = 0.0;
				DhtIAtemp = 0.0;
				DhtUBtemp = 0.0;
				DhtIBtemp = 0.0;
				DhtUCtemp = 0.0;
				DhtICtemp = 0.0;
				//DhtIAmedia=0;
				//DhtUAmedia=0;
				contadht = 0;
			}
*/



			//Calculos de valores rms, entre  fases

			UA2 = UrmsA * UrmsA;
			UB2 = UrmsB * UrmsB;
			UC2 = UrmsC * UrmsC;
			UrmsAB = sqrt(UA2 + UB2 + UrmsA * UrmsB);
			UrmsBC = sqrt(UB2 + UC2 + UrmsB * UrmsC);
			UrmsCA = sqrt(UC2 + UA2 + UrmsC * UrmsA);

			if (UrmsAB < (0.05 * (float) relacaoTPfat * (float) relacaoTPpri))
			{
				if (HabCapator == ON)
				{
					UrmsAB = 0.0;
				}
			}
			if (UrmsBC < (0.05 * (float) relacaoTPfat * (float) relacaoTPpri))
			{
				if (HabCapator == ON)
				{
					UrmsBC = 0.0;
				}
			}
			if (UrmsCA < (0.05 * (float) relacaoTPfat * (float) relacaoTPpri))
			{
				if (HabCapator == ON)
				{
					UrmsCA = 0.0;
				}
			}

			capator_em_acao = OFF;
	#if (SEMCAPATOR == NAO)
			if (UrmsA < (5.0 * (float) relacaoTP  ))
			{
				if (HabCapator == ON)
				{
					UrmsA = 0;
					DhtUA = 0;
					FreqA = 0;
					capator_em_acao = ON;
				}
			}
	#if (CAPATOR100MA==SIM)
			//  if (IrmsA<(0.018*(float)relacaoTCfat*(float)relacaoTCpri)) {if (HabCapator==ON) {IrmsA=0;  capator_em_acao=ON;}}
			if (IrmsA < (CAPATOR_VALOR_Amp * (float) relacaoTC  ))
			{
				if (HabCapator == ON)
				{
					IrmsA = 0;
					DhtIA = 0;
					capator_em_acao = ON;
				}
			}
	#else
			if (IrmsA < (0.001 * (float) relacaoTCfat * (float) relacaoTCpri))
			{
				if (HabCapator == ON)
				{
					IrmsA = 0;
					DhtIA = 0;
					capator_em_acao = ON;
				}
			}
	#endif
			//  if (DhtIA>90.0)  {if (HabCapator==ON) {IrmsA=0; capator_em_acao=ON;}}
	#endif
			if (capator_em_acao == ON)
			{
				FatPotA = 1.0;
				PotReatA = 0.0;
				PotAparA = 0.0;
				PotAtivA = 0.0;
				EnergGerAnow = 0.0;
				ConsumoAnow = 0.0;
				EnergCapAnow = 0.0;
				EnergIndAnow = 0.0;
			}
			else
			{
				//C�lculo final da pot�ncia Aparente

	#if (FP_COM_HARMONICAS == SIM)
			UrmsA=UrmsA_; //o '_' indica o true-rms
			IrmsA=IrmsA_;
	#endif
				PotAparA = (UrmsA * IrmsA);

				//C�lculo final da pot�ncia Reativa


	#if (COM_LINEARIZACAO==NAO)
				if (PotAparA > PotAtivA)
				{
					PotReatA = SinalQA * sqrt(PotAparA * PotAparA - PotAtivA * PotAtivA);
				}
				else
				{
					PotReatA = 0.0;
				}
				//Calculo da Potencia Ativa e Reativa, corrigidas por tabela
				if (PotAparA > PotAtivA)
				{
					PotReatA = SinalQA * sqrt(PotAparA * PotAparA - PotAtivA * PotAtivA);
				}
				else
				{
					PotReatA = 0.0;
				}
	#endif

				//C�lculo final da fator de Pot�ncia
	#if MD4060==0
	#if EQUIP==CM_EQUIP
	#if (MONO_TRI==MONOFASICO)

				if (StatusFuncaoFinal[33] == 2)	//F-F
				{
					UrmsAB = UrmsA;
					UrmsA = UrmsA * 0.577350269189626;	//1/sqrt(3)
					FatPotA = SinalQA * fabs(PotAtivA) / PotAparA;
					if (FatPotA <= 0.6)
					{
						FatPotA = -SinalQA * cos(acos(FatPotA) + 1.5707963267949);	//
						PotAtivA = UrmsA * IrmsA * FatPotA;
						PotAparA = UrmsA * IrmsA;
						PotReatA = SinalQA * PotAparA * sin(acos(FatPotA));
					}
					else
					{
						FatPotA = SinalQA * cos(acos(FatPotA) + 1.5707963267949 + 0.07);	//
						PotAtivA = UrmsA * IrmsA * FatPotA;
						PotAparA = UrmsA * IrmsA;
						PotReatA = SinalQA * PotAparA * abs(sin(acos(FatPotA)));

					}
				}

				if (StatusFuncaoFinal[33] == 1)	//F-N
				{

					PotAtivA = PotAtivA;
					PotAparA = PotAparA;
					PotReatA = PotReatA;
					FatPotA = SinalQA * fabs(PotAtivA) / PotAparA;

	#if (HABsangrado == 1)
					if (FLAG_MODO_DELTA_SANGRADO == SIM)
					{				//ainda em fase de testes!!! n�o est� ok 100%
						PotAtivA = PotAtivA * 1.1547005383792515290182975610039 * 0.33333333333333333333333333333333;	//sqrt(4/3)
						PotReatA = PotReatA * 1.1547005383792515290182975610039 * 0.33333333333333333333333333333333;	//por sqrt(4/3)
						PotAparA = sqrt(PotReatA * PotReatA + PotAtivA * PotAtivA);
						FatPotA = SinalQA * fabs(PotAtivA) / PotAparA;
						//  FatPotA=SinalQA*fabs(cos(acos(FatPotA)-253.6617e-003));

					}
	#endif
				}
	#endif
	#endif

	#if (MONO_TRI==TRIFASICO)
			 //	FatPotA = SinalQA * fabs(PotAtivA) / PotAparA;
	#endif
	#else
				FatPotA = SinalQA * fabs(PotAtivA) / PotAparA;
	#endif
	//Calcs de Energs e Consumo s�o POT * (1/3600) que � unidade por segundo
	// Acumula��o � realizado em int64 para preservar somas de grandezas muito menores q o ACC.
				//C�lculo das Energias Geradas
				EnergGerAnow = (Sign(PotAtivA * -0.000277777777777778));	//  1/3600.0
				EnergGerA_int64 += (unsigned long long) (EnergGerAnow * 1000);
				EnergGerA = (float) (EnergGerA_int64 / 1000);
				//C�lculo dos Consumos
				ConsumoAnow = (Sign(PotAtivA * 0.000277777777777778));
				ConsumoA_int64 += (unsigned long long) (ConsumoAnow * 1000);
				ConsumoA = (float) (ConsumoA_int64 / 1000);
				//C�lculo das Energias Reativas Indutivas
				EnergIndAnow = (Sign(PotReatA * 0.000277777777777778));
				EnergIndA_int64 += (unsigned long long) (EnergIndAnow * 1000);
				EnergIndA = (float) (EnergIndA_int64 / 1000);
				//C�lculo das Energias Reativas Capacitivas
				EnergCapAnow = (Sign(PotReatA * -0.000277777777777778));
				EnergCapA_int64 += (unsigned long long) (EnergCapAnow * 1000);
				EnergCapA = (float) (EnergCapA_int64 / 1000);
			}

			capator_em_acao = OFF;

	#if (SEMCAPATOR == NAO)
			if (UrmsB < (5.0 * (float) relacaoTP  ))
			{
				if (HabCapator == ON)
				{
					UrmsB = 0;
					DhtUB = 0;
					capator_em_acao = ON;
				}
			}
	#if (CAPATOR100MA==SIM)
			//if (IrmsB<(0.018*(float)relacaoTCfat*(float)relacaoTCpri)) {if (HabCapator==ON) {IrmsB=0;  capator_em_acao=ON;}}
			if (IrmsB < (CAPATOR_VALOR_Amp * (float) relacaoTC  ))
			{
				if (HabCapator == ON)
				{
					IrmsB = 0;
					DhtIB = 0;
					capator_em_acao = ON;
				}
			}
	#else
			if (IrmsB < (0.001 * (float) relacaoTCfat * (float) relacaoTCpri))
			{
				if (HabCapator == ON)
				{
					IrmsB = 0;
					DhtIB = 0;
					capator_em_acao = ON;
				}
			}
	#endif
			//  if (DhtIB>90.0)  {if (HabCapator==ON) {IrmsB=0.0;  capator_em_acao=ON;}}
	#endif
			if (capator_em_acao == ON)
			{
				PotAtivB = 0.0;
				PotAparB = 0.0;
				PotReatB = 0.0;
				FatPotB = 1.0;
				EnergGerBnow = 0.0;
				ConsumoBnow = 0.0;
				EnergCapBnow = 0.0;
				EnergIndBnow = 0.0;
			}
			else
			{

	#if (FP_COM_HARMONICAS == SIM)
			UrmsB=UrmsB_; //o '_' indica o true-rms
			IrmsB=IrmsB_;
	#endif
				//C�lculo final da pot�ncia Aparente
				PotAparB = (UrmsB * IrmsB);

				//C�lculo final da pot�ncia Reativa

	#if (COM_LINEARIZACAO==NAO)
				//C�lculo final da pot�ncia Reativa
				if (PotAparB > PotAtivB)
				{
					PotReatB = SinalQB * sqrt(PotAparB * PotAparB - PotAtivB * PotAtivB);
				}
				else
				{
					PotReatB = SinalQB * PotAparB;
				}
	#endif
				//C�lculo final da fator de Pot�ncia
	#if MD4060==0
	#if EQUIP==CM_EQUIP
	#if (MONO_TRI==MONOFASICO)

				if (StatusFuncaoFinal[33] == 2)	//F-F
				{
					UrmsB = UrmsB * 0.577350269189626;	//1/sqrt(3)
					FatPotB = SinalQB * fabs(PotAtivB) / PotAparB;
					FatPotB = -SinalQB * cos(acos(FatPotB) + 1.5707963267949);
					PotAtivB = UrmsB * IrmsB * FatPotB;
					PotAparB = UrmsB * IrmsB;
					PotReatB = SinalQB * PotAparB * sin(acos(FatPotB));
				}
				if (StatusFuncaoFinal[33] == 1)	//F-N
				{
					PotAtivB = PotAtivB;
					PotAparB = PotAparB;
					PotReatB = PotReatB;
					FatPotB = SinalQB * fabs(PotAtivB) / PotAparB;
				}
	#endif
	#endif

	#if (MONO_TRI==TRIFASICO)
				//FatPotB = SinalQB * fabs(PotAtivB) / PotAparB;
	#endif
	#else
				FatPotB = SinalQB * fabs(PotAtivB) / PotAparB;
	#endif
	//Calcs de Energs e Consumo s�o POT * (1/3600) que � unidade por segundo
	// Acumula��o � realizado em int64 para preservar somas de grandezas muito menores q o ACC.
				//C�lculo das Energias Geradas
				EnergGerBnow = (Sign(PotAtivB * -0.000277777777777778));
				EnergGerB_int64 += (unsigned long long) (EnergGerBnow * 1000);
				EnergGerB = (float) (EnergGerB_int64 / 1000);
				//C�lculo dos Consumos
				ConsumoBnow = (Sign(PotAtivB * 0.000277777777777778));
				ConsumoB_int64 += (unsigned long long) (ConsumoBnow * 1000);
				ConsumoB = (float) (ConsumoB_int64 / 1000);
				//C�lculo das Energias Reativas Indutivas
				EnergIndBnow = (Sign(PotReatB * 0.000277777777777778));
				EnergIndB_int64 += (unsigned long long) (EnergIndBnow * 1000);
				EnergIndB = (float) (EnergIndB_int64 / 1000);
				//C�lculo das Energias Reativas Capacitivas
				EnergCapBnow = (Sign(PotReatB * -0.000277777777777778));
				EnergCapB_int64 += (unsigned long long) (EnergCapBnow * 1000);
				EnergCapB = (float) (EnergCapB_int64 / 1000);
			}

			capator_em_acao = OFF;
	#if (SEMCAPATOR == NAO)
			if (UrmsC < (5.0 * (float) relacaoTP  ))
			{
				if (HabCapator == ON)
				{
					UrmsC = 0;
					DhtUC = 0;
					capator_em_acao = ON;
				}
			}
	#if (CAPATOR100MA==SIM)
			//if (IrmsC<(0.018*(float)relacaoTCfat*(float)relacaoTCpri)) {if (HabCapator==ON) {IrmsC=0;  capator_em_acao=ON;}}
			if (IrmsC < (CAPATOR_VALOR_Amp * (float) relacaoTC))
			{
				if (HabCapator == ON)
				{
					IrmsC = 0;
					DhtIC = 0;
					capator_em_acao = ON;
				}
			}
	#else
			if (IrmsC < (0.001 * (float) relacaoTCfat * (float) relacaoTCpri))
			{
				if (HabCapator == ON)
				{
					IrmsC = 0;
					DhtIC = 0;
					capator_em_acao = ON;
				}
			}
	#endif
			//  if (DhtIC>90.0)  {if (HabCapator==ON) {IrmsC=0.0;  capator_em_acao=ON;}}
	#endif
			if (capator_em_acao == ON)
			{
				PotAtivC = 0.0;
				PotAparC = 0.0;
				PotReatC = 0.0;
				FatPotC = 1;
				EnergGerCnow = 0;
				ConsumoCnow = 0;
				EnergCapCnow = 0;
				EnergIndCnow = 0;
			}
			else
			{

	#if (FP_COM_HARMONICAS == SIM)
			UrmsC=UrmsC_; //o '_' indica o true-rms
			IrmsC=IrmsC_;
	#endif

				//C�lculo final da pot�ncia Aparente
				//PotAparC = (UrmsC * IrmsC);
				//C�lculo final da pot�ncia Reativa


	#if (COM_LINEARIZACAO==NAO)
				//C�lculo final da pot�ncia Reativa
				if (PotAparC > PotAtivC)
				{
					PotReatC = SinalQC * sqrt(PotAparC * PotAparC - PotAtivC * PotAtivC);
				}
				else
				{
					PotReatC = SinalQC * PotAparC;
				}
	#endif
				//C�lculo final da fator de Pot�ncia
	#if MD4060==0
	#if EQUIP==CM_EQUIP
	#if (MONO_TRI==MONOFASICO)
				if (StatusFuncaoFinal[33] == 2)	//F-F
				{
					UrmsC = UrmsC * 0.577350269189626;	//1/sqrt(3)
					FatPotC = SinalQC * fabs(PotAtivC) / PotAparC;
					FatPotC = -SinalQC * cos(acos(FatPotC) + 1.5707963267949);
					PotAtivC = UrmsB * IrmsC * FatPotC;
					PotAparC = UrmsB * IrmsC;
					PotReatC = SinalQC * PotAparC * sin(acos(FatPotC));
				}
				if (StatusFuncaoFinal[33] == 1)	//F-N
				{
					PotAtivC = PotAtivC;
					PotAparC = PotAparC;
					PotReatC = PotReatC;
					FatPotC = SinalQC * fabs(PotAtivC) / PotAparC;
				}
	#endif
	#endif

	#if (MONO_TRI==TRIFASICO)
				//FatPotC = SinalQC * fabs(PotAtivC) / PotAparC;
	#endif
	#else
				FatPotC = SinalQC * fabs(PotAtivC) / PotAparC;
	#endif
	//Calcs de Energs e Consumo s�o POT * (1/3600) que � unidade por segundo
	// Acumula��o � realizado em int64 para preservar somas de grandezas muito menores q o ACC.
				//C�lculo das Energias Geradas
				EnergGerCnow = (Sign(PotAtivC * -0.000277777777777778));
				EnergGerC_int64 += (unsigned long long) (EnergGerCnow * 1000);
				EnergGerC = (float) (EnergGerC_int64 / 1000);
				//C�lculo dos Consumos
				ConsumoCnow = (Sign(PotAtivC * 0.000277777777777778));
				ConsumoC_int64 += (unsigned long long) (ConsumoCnow * 1000);
				ConsumoC = (float) (ConsumoC_int64 / 1000);
				//C�lculo das Energias Reativas Indutivas
				EnergIndCnow = (Sign(PotReatC * 0.000277777777777778));
				EnergIndC_int64 += (unsigned long long) (EnergIndCnow * 1000);
				EnergIndC = (float) (EnergIndC_int64 / 1000);
				//C�lculo das Energias Reativas Capacitivas
				EnergCapCnow = (Sign(PotReatC * -0.000277777777777778));
				EnergCapC_int64 += (unsigned long long) (EnergCapCnow * 1000);
				EnergCapC = (float) (EnergCapC_int64 / 1000);
			}
#if (EQUIP_LINHA50 != CT_EQUIP)
	#if (SEMCAPATOR == NAO)
			if ((IrmsA < (0.018 * (float) relacaoTCfat * (float) relacaoTCpri)) && (DhtIA  > 250.0))
			{
				IrmsA = 0.0;
				DhtIA = 0.0;
				PotAtivA = 0.0;
				PotAparA = 0.0;
				PotReatA = 0.0;
				FatPotA = 1.0;
				EnergGerAnow = 0.0;
				ConsumoAnow = 0.0;
				EnergCapAnow = 0.0;
				EnergIndAnow = 0.0;
			}

			if ((IrmsB < (0.018 * (float) relacaoTCfat * (float) relacaoTCpri)) && (DhtIB  > 250.0))
			{
				IrmsB = 0.0;
				DhtIB = 0.0;
				PotAtivB = 0.0;
				PotAparB = 0.0;
				PotReatB = 0.0;
				FatPotB = 1.0;
				EnergGerBnow = 0.0;
				ConsumoBnow = 0.0;
				EnergCapBnow = 0.0;
				EnergIndBnow = 0.0;
			}
			if ((IrmsC < (0.018 * (float) relacaoTCfat * (float) relacaoTCpri)) && (DhtIC  > 250.0))
			{
				IrmsC = 0.0;
				DhtIC = 0.0;
				PotAtivC = 0.0;
				PotAparC = 0.0;
				PotReatC = 0.0;
				FatPotC = 1.0;
				EnergGerCnow = 0.0;
				ConsumoCnow = 0.0;
				EnergCapCnow = 0.0;
				EnergIndCnow = 0.0;
			}
	#endif
#endif
	//Calcs Totais s�o realizados com soma dos valores instantaneos
	//Acumula��o � realizado em int64 para preservar somas de grandezas muito menores q o ACC.

			EnergGerTnow = EnergGerAnow;
			EnergGerTnow += EnergGerBnow;
			EnergGerTnow += EnergGerCnow;
			EnergGerT_int64 += (unsigned long long) (EnergGerTnow * 1000);

			ConsumoTnow = ConsumoAnow;
			ConsumoTnow += ConsumoBnow;
			ConsumoTnow += ConsumoCnow;
			ConsumoT_int64 += (unsigned long long) (ConsumoTnow * 1000);

			EnergIndTnow = EnergIndAnow;
			EnergIndTnow += EnergIndBnow;
			EnergIndTnow += EnergIndCnow;
			EnergIndT_int64 += (unsigned long long) (EnergIndTnow * 1000);

			EnergCapTnow = EnergCapAnow;
			EnergCapTnow += EnergCapBnow;
			EnergCapTnow += EnergCapCnow;
			EnergCapT_int64 += (unsigned long long) (EnergCapTnow * 1000);

			ProximoCanal = ProximoCanal & 0x7F;

			DisablePoweDownInterrupt();	//desabilitar interrupcao de powerdown , mas ela volta a ser habilitada no loop main


			EnergGerT =	(float)(EnergGerT_int64 / 1000);
			ConsumoT  = (float)( ConsumoT_int64 / 1000);
			EnergIndT = (float)(EnergIndT_int64 / 1000);
			EnergCapT = (float)(EnergCapT_int64 / 1000);

			PotReatT = PotReatA + PotReatB + PotReatC;
			PotAtivT = PotAtivA + PotAtivB + PotAtivC;
			PotAparT = sqrt(PotReatT * PotReatT + PotAtivT * PotAtivT);
			SinalQT = PotReatT / fabs(PotReatT);

			if (PotAparT == 0.0)
			{
				FatPotT = 1.0;
			}
			else
			{
				FatPotT = SinalQT * fabs(PotAtivT) / PotAparT;
				if (FatPotT == 0.0)
				{
					FatPotT = 1.0;
				}
			}

#if (EQUIP_LINHA50 != CT_EQUIP)
			/* Adicionado por Gabriel */
			if(PotAtivA < 0)
				IrmsA = -IrmsA;

			if(PotAtivB < 0)
				IrmsB = -IrmsB;

			if(PotAtivC < 0)
				IrmsC = -IrmsC;
#endif
			MMFp_copy = ((float)(((unsigned int)((temperatura_ptc_ch0)*10))*10000 + (unsigned int)((temperatura_ptc_ch1)*100)))/10;

			/*
				Apartir de agora ser�o calculadas as demandas e consumos mensais
			*/
			//Feriados,s�bado e domingo �: HORARIO_FORA_PONTA

			///////////////////////////////////
			///////avalia��o a cada 1min
			///////////////////////////////////





	#if  (ENCHE_MM == SIM)
			MMUa = 0.00;
			MMUb = 0.00;
			MMUc = 0.00;
			MMIa = 0.00;
			MMIb = 0.0;
			MMIc = 0.0;
			MMDemP = 0.0;
			MMDemQ = 0.0;
			MMFp = 0.0;

			if (enche_mm == 0)
			{
				for (i = 0; i < 800; i++)
	#if (USAR_REGISTRO_SHORT==SIM)
					GravaNaBatteryRAM(REG_BATT_MEM_SHORT_SEM_RTC);
	#else
					GravaNaBatteryRAM(REG_BATT_MEM_NORM_SEM_RTC);
	#endif
				enche_mm = 1;
			}
	#endif

	#if ACELERA_RELOGIO == SIM
	//#if FIRST==NAO
			if (EquipVirgem == NAO)
			{
				static int cont_200ms_for_rtc=0;
				RTCTime LocalTime1;
				cont_200ms_for_rtc++;

				if (cont_200ms_for_rtc == 5)
				{
					cont_200ms_for_rtc = 0;
					RTCStop();
					LocalTime1 = RTCGetTime();
					add15min(&LocalTime1);
					LocalTime1.RTC_Sec = 58;

					JaRegistrouNoIntervalode15Min = NAO;
					RTCSetTime(LocalTime1);
					RTCStart();
				}
			}
	//#endif
	#endif

			//minuto=minuto+1;

			if (tMMgrandezas == 15)
			{
				MomentoDeAvaliacaoDeIntervalo15min();
			}
			else
			{
				MomentoDeAvaliacaoDeIntervalo1min();	//tempo m�nimo de observacao...

				///////////////////////////////////
				///////avalia��o a cada 15min
				///////////////////////////////////
				//veja que a vari�vel 'TipoDeHorario' tem o tipo de horario dos 15 min anteriores
				MomentoDeAvaliacaoDeIntervalo15min();
			}

			nPontosMedia++;			//incrementa o n�mero de pontos para o c�lculo das
			//pot�ncias medias

			//s� agora, depois de registrar os acumulados durante os 15min anteriores,
			//vou ler o tipo de hor�rio atual.
			TipoDeHorario = GETtipoDeHorario();
			#include <math.h>
			if (isnan(EnergGerTnow)!=0)
				EnergGerTnow=0;


			switch (TipoDeHorario)
			{
			case HORARIO_PONTA:
				{
					PotAtivPonta15minAcc += PotAtivT;
					PotReatPonta15minAcc += PotReatT;
					EnergGerPonta15minAcc += EnergGerTnow;
					ConsumoPonta15minAcc += ConsumoTnow;
					EnergIndPonta15minAcc += EnergIndTnow;
					EnergCapPonta15minAcc += EnergCapTnow;

					EnergGerPonta += EnergGerTnow;
					ConsumoPonta += ConsumoTnow;
					EnergIndPonta += EnergIndTnow;
					EnergCapPonta += EnergCapTnow;

					EnergGerPontaHojeAteAgora += EnergGerTnow;
					ConsumoPontaHojeAteAgora += ConsumoTnow;
					EnergIndPontaHojeAteAgora += EnergIndTnow;
					EnergCapPontaHojeAteAgora += EnergCapTnow;

					EnergGerPontaEsteMesAteAgora += EnergGerTnow;
					ConsumoPontaEsteMesAteAgora += ConsumoTnow;
					EnergIndPontaEsteMesAteAgora += EnergIndTnow;
					EnergCapPontaEsteMesAteAgora += EnergCapTnow;

					break;
				}
			case HORARIO_FORA_PONTA:
				{
					PotAtivForaPonta15minAcc += PotAtivT;
					PotReatForaPonta15minAcc += PotReatT;
					EnergGerForaPonta15minAcc += EnergGerTnow;
					ConsumoForaPonta15minAcc += ConsumoTnow;
					EnergIndForaPonta15minAcc += EnergIndTnow;
					EnergCapForaPonta15minAcc += EnergCapTnow;

					EnergGerForaPonta += EnergGerTnow;
					ConsumoForaPonta += ConsumoTnow;
					EnergIndForaPonta += EnergIndTnow;
					EnergCapForaPonta += EnergCapTnow;

					EnergGerForaPontaHojeAteAgora += EnergGerTnow;
					ConsumoForaPontaHojeAteAgora += ConsumoTnow;
					EnergIndForaPontaHojeAteAgora += EnergIndTnow;
					EnergCapForaPontaHojeAteAgora += EnergCapTnow;

					EnergGerForaPontaEsteMesAteAgora += EnergGerTnow;
					ConsumoForaPontaEsteMesAteAgora += ConsumoTnow;
					EnergIndForaPontaEsteMesAteAgora += EnergIndTnow;
					EnergCapForaPontaEsteMesAteAgora += EnergCapTnow;

					break;
				}
			case HORARIO_RESERVADO:
				{
					PotAtivReserv15minAcc += PotAtivT;
					PotReatReserv15minAcc += PotReatT;
					EnergGerReserv15minAcc += EnergGerTnow;
					ConsumoReserv15minAcc += ConsumoTnow;
					EnergIndReserv15minAcc += EnergIndTnow;
					EnergCapReserv15minAcc += EnergCapTnow;

					EnergGerReserv += EnergGerTnow;
					ConsumoReserv += ConsumoTnow;
					EnergIndReserv += EnergIndTnow;
					EnergCapReserv += EnergCapTnow;

					EnergGerReservHojeAteAgora += EnergGerTnow;
					ConsumoReservHojeAteAgora += ConsumoTnow;
					EnergIndReservHojeAteAgora += EnergIndTnow;
					EnergCapReservHojeAteAgora += EnergCapTnow;

					EnergGerReservEsteMesAteAgora += EnergGerTnow;
					ConsumoReservEsteMesAteAgora += ConsumoTnow;
					EnergIndReservEsteMesAteAgora += EnergIndTnow;
					EnergCapReservEsteMesAteAgora += EnergCapTnow;

					break;
				}
			case HORARIO_NULO:
				{

					break;
				}
			}

	//fimzinho:
			ContadorIntegrados = 0;
			AtualizaDisplay = ON;
			estouvivo = SIM;


			//FIO0CLR = VAGO1_PIN;

			////////////////////////// inicio das novas rotinas de calibracao
			RotinasDeCalibracao();
			////////////////////////// fim das novas rotinas de calibracao











	// extern void Calculos1(void);
	// Calculos1();
}




extern TIM_HandleTypeDef htim5;
#define htimCLK htim5



void CT50_leitura_dos_dados(void)
{
#define CNT_NUMBER 300
/*
	static float acc_UrmsA = 0;
	static float acc_UrmsB = 0;
	static float acc_UrmsC = 0;
	static float acc_IrmsA = 0;
	static float acc_IrmsB = 0;
	static float acc_IrmsC = 0;
		static int cnt_acc = 0;
*/
	static float UrmsA_aux = 0;
	static float UrmsB_aux = 0;
	static float UrmsC_aux = 0;

	static float IrmsA_aux = 0;
	static float IrmsB_aux = 0;
	static float IrmsC_aux = 0;



	static float a, b, Rt, R0, LEITURA_AD, A, B, t;

	a = 0.0671784;//0.0554801;
	b = 94.561127;//96.859842;

	A = 3.98083e-3;
	B = -5.755e-7;
	/*
	acc_UrmsA += (float)(*pUa);
	acc_UrmsB += (float)(*pUb);
	acc_UrmsC += (float)(*pUc);

	acc_IrmsA += (float)(*pIa);
	acc_IrmsB += (float)(*pIb);
	acc_IrmsC += (float)(*pIc);

	cnt_acc++;

	if(cnt_acc > CNT_NUMBER)
	{
		UrmsA_aux = acc_UrmsA/(float)cnt_acc;
		UrmsB_aux = acc_UrmsB/(float)cnt_acc;
		UrmsC_aux = acc_UrmsC/(float)cnt_acc;

		IrmsA_aux = acc_IrmsA/(float)cnt_acc;
		IrmsB_aux = acc_IrmsB/(float)cnt_acc;
		IrmsC_aux = acc_IrmsC/(float)cnt_acc;

		acc_UrmsA = 0;
		acc_UrmsB = 0;
		acc_UrmsC = 0;

		acc_IrmsA = 0;
		acc_IrmsB = 0;
		acc_IrmsC = 0;
		cnt_acc =  0;
		*/

	UrmsA_aux=UrmsA;
	UrmsB_aux=UrmsB;
	UrmsC_aux=UrmsC;
	IrmsA_aux=IrmsA;
	IrmsB_aux=IrmsB;
	IrmsC_aux=IrmsC;

		if (EtapaDeCalibracao != 0)
		{


			EtapaDeCalibracao = ETAPA_GRAVAR_SETOR_CALIBRACAO;
			RotinasDeCalibracao();

			EtapaDeCalibracao = 0;
		}

		//CANAL 1
		LEITURA_AD = UrmsA_aux;
		a=FatorCalibUa*6/50000;
		b=FatorCalibUa_;
		R0 = 100;
//		LEITURA_AD=101;
		Rt = a*LEITURA_AD + b;
		t =(-R0*A + sqrt((R0*A)*(R0*A) - 4*(R0*B)*(R0-Rt) ) )/(2*R0*B);
		UrmsA = t;

		//CANAL 2
		LEITURA_AD = UrmsB_aux;
		a=FatorCalibUb*6/50000;
		b=FatorCalibUb_;
		R0 = 100;
		Rt = a*LEITURA_AD + b;
		t =(-R0*A + sqrt((R0*A)*(R0*A) - 4*(R0*B)*(R0-Rt) ) )/(2*R0*B);
		UrmsB = t;

		//CANAL 3
		LEITURA_AD = UrmsC_aux;
		a=FatorCalibUc*6/50000;
		b=FatorCalibUc_;
		R0 = 100;
		Rt = a*LEITURA_AD + b;
		t =(-R0*A + sqrt((R0*A)*(R0*A) - 4*(R0*B)*(R0-Rt) ) )/(2*R0*B);
		UrmsC = t;

		//CANAL 4
		LEITURA_AD = IrmsA_aux;
		a=FatorCalibIa*6/50000;
		b=FatorCalibIa_;
		R0 = 100;
		Rt = a*LEITURA_AD + b;
		t =(-R0*A + sqrt((R0*A)*(R0*A) - 4*(R0*B)*(R0-Rt) ) )/(2*R0*B);
		IrmsA = t;

		//CANAL5
		LEITURA_AD = IrmsB_aux;
		a=FatorCalibIb*6/50000;
		b=FatorCalibIb_;
		R0 = 100;
		Rt = a*LEITURA_AD + b;
		t =(-R0*A + sqrt((R0*A)*(R0*A) - 4*(R0*B)*(R0-Rt) ) )/(2*R0*B);
		IrmsB = t;

		//CANAL6
		LEITURA_AD = IrmsC_aux;
		a=FatorCalibIc*6/50000;
		b=FatorCalibIc_;
		R0 = 100;
		Rt = a*LEITURA_AD + b;
		t =(-R0*A + sqrt((R0*A)*(R0*A) - 4*(R0*B)*(R0-Rt) ) )/(2*R0*B);
		IrmsC = t;
	//}
}

void CT50_leitura_dos_dados_old(void)
{
#define CNT_NUMBER 300
/*
	static float acc_UrmsA = 0;
	static float acc_UrmsB = 0;
	static float acc_UrmsC = 0;
	static float acc_IrmsA = 0;
	static float acc_IrmsB = 0;
	static float acc_IrmsC = 0;
		static int cnt_acc = 0;
*/
	static float UrmsA_aux = 0;
	static float UrmsB_aux = 0;
	static float UrmsC_aux = 0;

	static float IrmsA_aux = 0;
	static float IrmsB_aux = 0;
	static float IrmsC_aux = 0;



	static float a, b, Rt, R0, LEITURA_AD, A, B, t;

	a = 0.0671784;//0.0554801;
	b = 94.561127;//96.859842;

	A = 3.98083e-3;
	B = -5.755e-7;
	/*
	acc_UrmsA += (float)(*pUa);
	acc_UrmsB += (float)(*pUb);
	acc_UrmsC += (float)(*pUc);

	acc_IrmsA += (float)(*pIa);
	acc_IrmsB += (float)(*pIb);
	acc_IrmsC += (float)(*pIc);

	cnt_acc++;

	if(cnt_acc > CNT_NUMBER)
	{
		UrmsA_aux = acc_UrmsA/(float)cnt_acc;
		UrmsB_aux = acc_UrmsB/(float)cnt_acc;
		UrmsC_aux = acc_UrmsC/(float)cnt_acc;

		IrmsA_aux = acc_IrmsA/(float)cnt_acc;
		IrmsB_aux = acc_IrmsB/(float)cnt_acc;
		IrmsC_aux = acc_IrmsC/(float)cnt_acc;

		acc_UrmsA = 0;
		acc_UrmsB = 0;
		acc_UrmsC = 0;

		acc_IrmsA = 0;
		acc_IrmsB = 0;
		acc_IrmsC = 0;
		cnt_acc =  0;
		*/

	UrmsA_aux=UrmsA;
	UrmsB_aux=UrmsB;
	UrmsC_aux=UrmsC;
	IrmsA_aux=IrmsA;
	IrmsB_aux=IrmsB;
	IrmsC_aux=IrmsC;

		if (EtapaDeCalibracao != 0)
		{
			t = UrmsAforCalib;
		    LEITURA_AD = UrmsA_aux;
		    // Calculo de Rt
		    Rt = a*LEITURA_AD + b;
		    // Calculo de R0
		    R0 = Rt / (1 + A*t + B*(t*t));
			FatorCalibUa = R0;

			t = UrmsBforCalib;
		    LEITURA_AD = UrmsB_aux;
		    // Calculo de Rt
		    Rt = a*LEITURA_AD + b;
		    // Calculo de R0
		    R0 = Rt / (1 + A*t + B*(t*t));
			FatorCalibUb = R0;

			t = UrmsCforCalib;
		    LEITURA_AD = UrmsC_aux;
		    // Calculo de Rt
		    Rt = a*LEITURA_AD + b;
		    // Calculo de R0
		    R0 = Rt / (1 + A*t + B*(t*t));
			FatorCalibUc = R0;

			t = IrmsAforCalib;
		    LEITURA_AD = IrmsA_aux;
		    // Calculo de Rt
		    Rt = a*LEITURA_AD + b;
		    // Calculo de R0
		    R0 = Rt / (1 + A*t + B*(t*t));
			FatorCalibIa = R0;

			t = IrmsBforCalib;
		    LEITURA_AD = IrmsB_aux;
		    // Calculo de Rt
		    Rt = a*LEITURA_AD + b;
		    // Calculo de R0
		    R0 = Rt / (1 + A*t + B*(t*t));
			FatorCalibIb = R0;

			t = IrmsCforCalib;
		    LEITURA_AD = IrmsC_aux;
		    // Calculo de Rt
		    Rt = a*LEITURA_AD + b;
		    // Calculo de R0
		    R0 = Rt / (1 + A*t + B*(t*t));
			FatorCalibIc = R0;

			EtapaDeCalibracao = ETAPA_GRAVAR_SETOR_CALIBRACAO;
			RotinasDeCalibracao();

			EtapaDeCalibracao = 0;
		}

		//CANAL 1
		LEITURA_AD = UrmsA_aux;
		R0 = FatorCalibUa;
		Rt = a*LEITURA_AD + b;
		t =(-R0*A + sqrt((R0*A)*(R0*A) - 4*(R0*B)*(R0-Rt) ) )/(2*R0*B);
		UrmsA = t;

		//CANAL 2
		LEITURA_AD = UrmsB_aux;
		R0 = FatorCalibUb;
		Rt = a*LEITURA_AD + b;
		t =(-R0*A + sqrt((R0*A)*(R0*A) - 4*(R0*B)*(R0-Rt) ) )/(2*R0*B);
		UrmsB = t;

		//CANAL 3
		LEITURA_AD = UrmsC_aux;
		R0 = FatorCalibUc;
		Rt = a*LEITURA_AD + b;
		t =(-R0*A + sqrt((R0*A)*(R0*A) - 4*(R0*B)*(R0-Rt) ) )/(2*R0*B);
		UrmsC = t;

		//CANAL 4
		LEITURA_AD = IrmsA_aux;
		R0 = FatorCalibIa;
		Rt = a*LEITURA_AD + b;
		t =(-R0*A + sqrt((R0*A)*(R0*A) - 4*(R0*B)*(R0-Rt) ) )/(2*R0*B);
		IrmsA = t;

		LEITURA_AD = IrmsB_aux;
		R0 = FatorCalibIb;
		Rt = a*LEITURA_AD + b;
		t =(-R0*A + sqrt((R0*A)*(R0*A) - 4*(R0*B)*(R0-Rt) ) )/(2*R0*B);
		IrmsB = t;

		//CANAL5
		LEITURA_AD = IrmsC_aux;
		R0 = FatorCalibIc;
		Rt = a*LEITURA_AD + b;
		t =(-R0*A + sqrt((R0*A)*(R0*A) - 4*(R0*B)*(R0-Rt) ) )/(2*R0*B);
		IrmsC = t;
	//}
}


void newCalcDC(void)
{
#undef FFT_LEN
#define FFT_LEN 128
	int i;
	  if (flag_hab_processa_half1==1 && flag_hab_processa_half2==1)
	  {
		  //CalculaGrandezas1(ch0_buffer, ch3_buffer, ch1_buffer,ch4_buffer,ch2_buffer,ch5_buffer,FreqA);

			 flag_processando_half1= 1;
			 flag_processando_half2= 1;

			 float acc=0;
			 for (i=0;i<FFT_LEN;i++) {acc=acc+ch0_buffer[i]+2048.0  ;}
			 //acc=acc-13257;
			 //acc=acc-6200.0;
			 #if (EQUIP_LINHA50 == CT_EQUIP)
			 UrmsA = acc*  relacaoTP; acc=0;

			 #else
			 UrmsA = acc* FatorCalibUa * relacaoTP; acc=0;

			 #endif

			 for (i=0;i<FFT_LEN;i++) {acc=acc+ch1_buffer[i]+2048.0 ;}
			 //acc=acc- 6344;
			 // acc=acc-10971;
			#if (EQUIP_LINHA50 == CT_EQUIP)
			 UrmsB = acc* relacaoTP; acc=0;
			#else
			 UrmsB = acc* FatorCalibUb * relacaoTP; acc=0;
			#endif

			 for (i=0;i<FFT_LEN;i++) {acc=acc+ch2_buffer[i]+2048.0 ;}
			 //acc=acc-14625;
			#if (EQUIP_LINHA50 == CT_EQUIP)
			 UrmsC = acc*  relacaoTP; acc=0 ;
			#else
			 UrmsC = acc* FatorCalibUc * relacaoTP; acc=0 ;
			#endif

			 for (i=0;i<FFT_LEN;i++) {acc=acc+ch3_buffer[i]+2048.0;}
			 //acc=acc-8943;
			#if (EQUIP_LINHA50 == CT_EQUIP)
			 IrmsA = acc * relacaoTC; acc=0;
			#else
			 IrmsA = acc* FatorCalibIa * relacaoTC; acc=0;
			#endif

			 for (i=0;i<FFT_LEN;i++) {acc=acc+ch4_buffer[i]+2048.0;}
			 //acc=acc-8943;
			#if (EQUIP_LINHA50 == CT_EQUIP)
			 IrmsB = acc * relacaoTC; acc=0;
			#else
			 IrmsB = 0;
			#endif
			 for (i=0;i<FFT_LEN;i++) {acc=acc+ch5_buffer[i]+2048.0;}
			 //acc=acc-8943;
			#if (EQUIP_LINHA50 == CT_EQUIP)
			 IrmsC = acc * relacaoTC; acc=0;
			#else
			 IrmsC = 0;
			#endif
			 FreqA= 0;

			 cont_espectros=cont_espectros+6;


			 flag_processando_half1= 0;
			 flag_processando_half2= 0;
			 flag_hab_processa_half1=0;
			 flag_hab_processa_half2=0;
			 HabCalculos = 0;

	  }

	  if (flag_hab_processa_full1==1 && flag_hab_processa_full2==1)
	 	  {
	 		   flag_processando_full1= 1;
	 		     flag_processando_full2= 1;

				 float acc=0;
				 for (i=0;i<FFT_LEN;i++) {acc=acc+ch0_buffer[i]+2048.0  ;}
			 	// acc=acc-13257;
				 //acc=acc-6200.0;
				#if (EQUIP_LINHA50 == CT_EQUIP)
				 UrmsA= acc*  relacaoTP; acc=0;
				#else
				 UrmsA = acc* FatorCalibUa * relacaoTP; acc=0;
				#endif
				 for (i=0;i<FFT_LEN;i++) {acc=acc+ch1_buffer[i]+2048.0 ;}
				// acc=acc- 6344;
				 // acc=acc-10971;;
				#if (EQUIP_LINHA50 == CT_EQUIP)
				 UrmsB = acc* relacaoTP; acc=0;
				#else
				 UrmsB = acc* FatorCalibUb * relacaoTP; acc=0;
				#endif


				 for (i=0;i<FFT_LEN;i++) {acc=acc+ch2_buffer[i]+2048.0 ;}
				// acc=acc-14625;
				#if (EQUIP_LINHA50 == CT_EQUIP)
				 UrmsC = acc * relacaoTP; acc=0;
				#else
				 UrmsC = acc* FatorCalibUc * relacaoTP; acc=0;
				#endif


				 for (i=0;i<FFT_LEN;i++) {acc=acc+ch3_buffer[i]+2048.0;}
				/// acc=acc-8943;
				#if (EQUIP_LINHA50 == CT_EQUIP)
				 IrmsA = acc*  relacaoTC; acc=0;
				#else
				 IrmsA = acc* FatorCalibIa * relacaoTC; acc=0;
				 #endif

				 for (i=0;i<FFT_LEN;i++) {acc=acc+ch4_buffer[i]+2048.0;}
				/// acc=acc-8943;
				#if (EQUIP_LINHA50 == CT_EQUIP)
				 IrmsB = acc*  relacaoTC; acc=0;
				#else
				 IrmsB =  0;
				 #endif

				 for (i=0;i<FFT_LEN;i++) {acc=acc+ch5_buffer[i]+2048.0;}
				/// acc=acc-8943;
				#if (EQUIP_LINHA50 == CT_EQUIP)
				 IrmsC = acc*  relacaoTC; acc=0;
				#else
				 IrmsC =  0;
				 #endif

				 FreqA= 0;


	 		      flag_processando_full1= 0;
	 		      flag_processando_full2= 0;
	              flag_hab_processa_full1=0;
	              flag_hab_processa_full2=0;
	         	 cont_espectros=cont_espectros+6;
	         	 HabCalculos = 0;
	 	  }


	 	  if (flag_acavalou==1)
	 		 {
	 			 flag_acavalou=0;

	 		 }


//HAL_GPIO_TogglePin( AUXOUT3_GPIO_Port,AUXOUT3_Pin);  //LED Da placa CORELB50
//HAL_GPIO_TogglePin( LED_PWR_GPIO_Port,LED_PWR_Pin);  //led POWER

#undef FFT_LEN
#define FFT_LEN 1024

#if EQUIP_LINHA50== CT_EQUIP
	CT50_leitura_dos_dados( );
#endif

if (cont_espectros>=CONTAGEM_1SEG)
{


	CalculaPotencias();
}
extern void MX_LWIP_Process(void);
MX_LWIP_Process( );

}
void newCalc(void)
{


	/*
	  if (flag_hab_processa_half1==1)
	 		 		 {
	 		 			 flag_processando_half1= 1;
	 		 			 ChannFund=1;
	 		 		 	 MyFFT_Execute(ch0_buffer,0);
	 		 			 ChannFund=0;

	 		 			  MyFFT_Execute(ch1_buffer,1);
	 		 			//	cont_espectros++;
	 		 			// cont_espectros++;
	 		 			  MyFFT_Execute(ch2_buffer,2);
	 		 			 flag_processando_half1 =0;
	 		 			 flag_hab_processa_half1=0;
	 		 			flag_processado_half1=1;

	 		 		 }
	  if (flag_hab_processa_half2==1)
	 		 		 {
	 		 			 flag_processando_half2= 1;
	 		 		 	 MyFFT_Execute(ch3_buffer,3);

     		 		 	 MyFFT_Execute(ch4_buffer,4);
	 		 		 	//cont_espectros++;
     		 		 	//cont_espectros++;
	 		 		 	 MyFFT_Execute(ch5_buffer,5);
	 		 			 flag_processando_half2 =0;
	 		 			 flag_hab_processa_half2=0;
	 		 			flag_processado_half2=1;



	 		 		 }


		  if (flag_hab_processa_full1==1)
		 		 		 {
		 		 			 flag_processando_full1= 1;
		 		 			 ChannFund=1;
		 		 			 //elpased_millis = HAL_GetTick();
		 		 		 	 MyFFT_Execute(ch0_buffer,0);  //20ms aprox. (ou até menos)
		 		 		 	 //lpased_millis1=HAL_GetTick()-elpased_millis;

		 		 			 ChannFund=0;
 		 		 			MyFFT_Execute(ch1_buffer,1);
	     		 			MyFFT_Execute(ch2_buffer,2);
	     		 			//cont_espectros++;
	     		 			//cont_espectros++;
		 		 			 flag_processando_full1 =0;
		 		 			 flag_hab_processa_full1=0;
		 		 			flag_processado_full1=1;



		 		 		 }
		  if (flag_hab_processa_full2==1)
		 		 		 {
		 		 			 flag_processando_full2= 1;
		 		 		 	 MyFFT_Execute(ch3_buffer,3);
		 		 			  MyFFT_Execute(ch4_buffer,4);
		 		 		  MyFFT_Execute(ch5_buffer,5);
		 		 			//cont_espectros++;
		 		 			//cont_espectros++;
		 		 			 flag_processando_full2 =0;
		 		 			 flag_hab_processa_full2=0;
		 		 			flag_processado_full2=1;




		 		 		 }*/


	  if (flag_hab_processa_half1==1 && flag_hab_processa_half2==1)
	  {
		  CalculaGrandezas1(ch0_buffer, ch3_buffer, ch1_buffer,ch4_buffer,ch2_buffer,ch5_buffer,FreqA);

			 flag_processando_half1= 1;
			 flag_processando_half2= 1;
			  ChannFund=1;
		 	  MyFFT_Execute(ch0_buffer,0);
			 ChannFund=0;
			  MyFFT_Execute(ch1_buffer,1);
			 MyFFT_Execute(ch2_buffer,2);

			  MyFFT_Execute(ch3_buffer,3);
			 MyFFT_Execute(ch4_buffer,4);
			 MyFFT_Execute(ch5_buffer,5);

			 flag_processando_half1= 0;
			 flag_processando_half2= 0;
			 flag_hab_processa_half1=0;
			 flag_hab_processa_half2=0;

			 HabCalculos = 0;

	  }


	  if (flag_hab_processa_full1==1 && flag_hab_processa_full2==1)
	  {
		  CalculaGrandezas1(ch0_buffer, ch3_buffer, ch1_buffer,ch4_buffer,ch2_buffer,ch5_buffer,FreqA);
		     flag_processando_full1= 1;
		     flag_processando_full2= 1;

			 ChannFund=1;
		 	 MyFFT_Execute(ch0_buffer,0);
			 ChannFund=0;
			 MyFFT_Execute(ch1_buffer,1);
			 MyFFT_Execute(ch2_buffer,2);
	 		 MyFFT_Execute(ch3_buffer,3);
             MyFFT_Execute(ch4_buffer,4);
             MyFFT_Execute(ch5_buffer,5);


		     flag_processando_full1= 0;
		     flag_processando_full2= 0;
             flag_hab_processa_full1=0;
             flag_hab_processa_full2=0;

             HabCalculos = 0;
	  }


	  if (flag_acavalou==1)
		 {
			 flag_acavalou=0;

		 }


		extern void MX_LWIP_Process(void);
	 		    MX_LWIP_Process( );

	if (cont_espectros>=CONTAGEM_1SEG)
	 		 		 {




	 		 			//Todo...
		  HAL_GPIO_TogglePin( AUXOUT3_GPIO_Port,AUXOUT3_Pin);  //LED Da placa CORELB50
	      HAL_GPIO_TogglePin( LED_PWR_GPIO_Port,LED_PWR_Pin);  //led POWER


				 		static int cont_X=0;
				 		cont_X=cont_X+1;
				//if ( (elapsed_cicles/180e6)<2)  {
					if (1)  {
			 	  CalculaPotencias();
			 	  /*
					 extern ADC_HandleTypeDef hadc1;
					 extern ADC_HandleTypeDef hadc2;
					  int tamanho_do_buffer_ADC=ADC1_BUF_LEN;
					  HAL_ADC_Stop_DMA(&hadc1);
					  HAL_ADC_Start_DMA(&hadc1, (uint32_t*) adc1_data_buffer, tamanho_do_buffer_ADC);

					  HAL_ADC_Stop_DMA(&hadc2);
					      tamanho_do_buffer_ADC=ADC2_BUF_LEN;
					  HAL_ADC_Start_DMA(&hadc2, (uint32_t*) adc2_data_buffer, tamanho_do_buffer_ADC);
					  //start_cicles= DWT->CYCCNT;
*/

				}
				else
				{


				}




					 EspectroAcumulado_reinit();
	 		 		 }
		else
		{
			extern volatile long int   start_cicles;
			extern volatile long int  elapsed_cicles;
			extern void MX_LWIP_Process(void);
			         //start_cicles= DWT->CYCCNT;
 		 			 MX_LWIP_Process( );
 		 			 //elapsed_cicles= DWT->CYCCNT-start_cicles;


					//neste ponto há que colocar as variáveis acumuladas em globais para poder analisar no "Live Expressions"  pEspectroDisplay


		}

}


//SOS=   [ 1	1	0	1	-0.917586183770848	0]

//G = [0.0412069081145760   1]
/*
void myfilter(float *b, int Nb,float *a, int Na,float *x, int N)
{
	for n=0:N-1
    sumb=0;
    for m=0:Nb-1
        if (n-m)>=0
            sumb=sumb+b(m+1)*x(n-m+1);
        end
    end
    suma=0;
    for m=0:Na-1
        if (n-m)>=0
            suma=suma+a(m+1)*y(n-m+1);
        end
    end
    y(n+1)=(1/a(1))*(sumb-suma);

}

*/

