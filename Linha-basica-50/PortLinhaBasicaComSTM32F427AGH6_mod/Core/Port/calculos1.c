
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
extern short tabela[];
#endif

extern const short h[];

#define TAM_FILTRO (short)sizeof(h)/2

extern const short kernelCr[];
extern const short kernelSr[];
extern const short kernelCr50Hz[];
extern const short kernelSr50Hz[];

#define TAMANHO_DO_KERNEL_60Hz 64
#define TAMANHO_DO_KERNEL_50Hz 77

RTCTime LocalTime1;
short cont_200ms_for_rtc;

extern float DhtIA1;
extern float DhtIB1;
extern float DhtIC1;

/*********************************************************************/
void Calculos1(void)
{

	char tamanho_do_kernel;
	char capator_em_acao = ON;

	//short contador=0;
	short i, ind_kernel = 0;

#if (ENCHE_MM==SIM)
	char enche_mm = 0;
#endif

	float IAacc = 0;
	float IBacc = 0;
	float ICacc = 0;
	float VAacc = 0;
	float VBacc = 0;
	float VCacc = 0;

	float IAacc_ = 0;
	float IBacc_ = 0;
	float ICacc_ = 0;
	float VAacc_ = 0;
	float VBacc_ = 0;
	float VCacc_ = 0;

	float PAatacc = 0;
	float PBatacc = 0;
	float PCatacc = 0;
	float PAreatacc = 0;
	float PBreatacc = 0;
	float PCreatacc = 0;

	long int akimagVa = 0;
	long int akrealVa = 0;
	long int akimagVb = 0;
	long int akrealVb = 0;
	long int akimagVc = 0;
	long int akrealVc = 0;

	float akimagVaacc = 0;
	float akrealVaacc = 0;
	float akimagVbacc = 0;
	float akrealVbacc = 0;
	float akimagVcacc = 0;
	float akrealVcacc = 0;

	long int akimagIa = 0;
	long int akrealIa = 0;
	long int akimagIb = 0;
	long int akrealIb = 0;
	long int akimagIc = 0;
	long int akrealIc = 0;

	float akimagIaacc = 0;
	float akrealIaacc = 0;
	float akimagIbacc = 0;
	float akrealIbacc = 0;
	float akimagIcacc = 0;
	float akrealIcacc = 0;

	float PotAtivAmedida, PotReatAmedida;
	float PotAtivBmedida, PotReatBmedida;
	float PotAtivCmedida, PotReatCmedida;
	float poli, x;
	float cosfiVA, cosfiIA, sinfiVA, sinfiIA;
	float cosfiVB, cosfiIB, sinfiVB, sinfiIB;
	float cosfiVC, cosfiIC, sinfiVC, sinfiIC;

	long int VAm, VBm, VCm;
	long int IAm, IBm, ICm;
	float UA2, UB2, UC2;

#ifdef LEGADO
	if (Hab_LeituraMedios == 1)
	{
		VAm = 0;
		VBm = 0;
		VCm = 0;
		IAm = 0;
		IBm = 0;
		ICm = 0;
	}

#if (FREQ_FUNDAMENTAL == 50)
	tamanho_do_kernel = TAMANHO_DO_KERNEL_50Hz;
#else
	tamanho_do_kernel = TAMANHO_DO_KERNEL_60Hz;
#endif

	for (i = 0; i < TAM_BUFFER; i++)
	{
		if (Hab_LeituraMedios == 1)
		{
			VAm = VAm + (*pUAparaCalculo);
			VBm = VBm + (*pUBparaCalculo);
			VCm = VCm + (*pUCparaCalculo);
			IAm = IAm + (*pIAparaCalculo);
			IBm = IBm + (*pIBparaCalculo);
			ICm = ICm + (*pUCparaCalculo);
		}

		//   %outros calculos: tensao, corrente pot�ncias...
		VAacc_ = VAacc_ + (float) (((long int) *pUAparaCalculo) * ((long int) *pUAparaCalculo));
		VBacc_ = VBacc_ + (float) (((long int) *pUBparaCalculo) * ((long int) *pUBparaCalculo));
		VCacc_ = VCacc_ + (float) (((long int) *pUCparaCalculo) * ((long int) *pUCparaCalculo));

		IAacc_ = IAacc_ + (float) (((long int) *pIAparaCalculo) * ((long int) *pIAparaCalculo));
		IBacc_ = IBacc_ + (float) (((long int) *pIBparaCalculo) * ((long int) *pIBparaCalculo));
		ICacc_ = ICacc_ + (float) (((long int) *pICparaCalculo) * ((long int) *pICparaCalculo));

		#if (FP_COM_HARMONICAS==SIM)
			PAatacc = PAatacc +  (float) (((long int) *pIAparaCalculo) * ((long int) *pUAparaCalculo));
			PBatacc = PBatacc +  (float) (((long int) *pIBparaCalculo) * ((long int) *pUBparaCalculo));
			PCatacc = PCatacc +  (float) (((long int) *pICparaCalculo) * ((long int) *pUCparaCalculo));
		#endif


#if (FREQ_FUNDAMENTAL == 50)
				akrealVa = (long int) *pUAparaCalculo * kernelCr50Hz[ind_kernel] + akrealVa;
				akimagVa = (long int) *pUAparaCalculo * kernelSr50Hz[ind_kernel] + akimagVa;
				akrealVb = (long int) *pUBparaCalculo * kernelCr50Hz[ind_kernel] + akrealVb;
				akimagVb = (long int) *pUBparaCalculo * kernelSr50Hz[ind_kernel] + akimagVb;
				akrealVc = (long int) *pUCparaCalculo * kernelCr50Hz[ind_kernel] + akrealVc;
				akimagVc = (long int) *pUCparaCalculo * kernelSr50Hz[ind_kernel] + akimagVc;
				akrealIa = (long int) *pIAparaCalculo * kernelCr50Hz[ind_kernel] + akrealIa;
				akimagIa = (long int) *pIAparaCalculo * kernelSr50Hz[ind_kernel] + akimagIa;
				akrealIb = (long int) *pIBparaCalculo * kernelCr50Hz[ind_kernel] + akrealIb;
				akimagIb = (long int) *pIBparaCalculo * kernelSr50Hz[ind_kernel] + akimagIb;
				akrealIc = (long int) *pICparaCalculo * kernelCr50Hz[ind_kernel] + akrealIc;
				akimagIc = (long int) *pICparaCalculo * kernelSr50Hz[ind_kernel] + akimagIc;
#else
				akrealVa = (long int) *pUAparaCalculo * kernelCr[ind_kernel] + akrealVa;
				akimagVa = (long int) *pUAparaCalculo * kernelSr[ind_kernel] + akimagVa;
				akrealVb = (long int) *pUBparaCalculo * kernelCr[ind_kernel] + akrealVb;
				akimagVb = (long int) *pUBparaCalculo * kernelSr[ind_kernel] + akimagVb;
				akrealVc = (long int) *pUCparaCalculo * kernelCr[ind_kernel] + akrealVc;
				akimagVc = (long int) *pUCparaCalculo * kernelSr[ind_kernel] + akimagVc;
				akrealIa = (long int) *pIAparaCalculo * kernelCr[ind_kernel] + akrealIa;
				akimagIa = (long int) *pIAparaCalculo * kernelSr[ind_kernel] + akimagIa;
				akrealIb = (long int) *pIBparaCalculo * kernelCr[ind_kernel] + akrealIb;
				akimagIb = (long int) *pIBparaCalculo * kernelSr[ind_kernel] + akimagIb;
				akrealIc = (long int) *pICparaCalculo * kernelCr[ind_kernel] + akrealIc;
				akimagIc = (long int) *pICparaCalculo * kernelSr[ind_kernel] + akimagIc;
#endif

		ind_kernel++;

		if (ind_kernel == tamanho_do_kernel)
		{
			ind_kernel = 0;

#if (FREQ_FUNDAMENTAL == 50)
			akrealVaacc = 1.25 * (float) akrealVa + akrealVaacc;
			akimagVaacc = 1.25 * (float) akimagVa + akimagVaacc;
			akrealVbacc = 1.25 * (float) akrealVb + akrealVbacc;
			akimagVbacc = 1.25 * (float) akimagVb + akimagVbacc;
			akrealVcacc = 1.25 * (float) akrealVc + akrealVcacc;
			akimagVcacc = 1.25 * (float) akimagVc + akimagVcacc;
			akrealIaacc = 1.25 * (float) akrealIa + akrealIaacc;
			akimagIaacc = 1.25 * (float) akimagIa + akimagIaacc;
			akrealIbacc = 1.25 * (float) akrealIb + akrealIbacc;
			akimagIbacc = 1.25 * (float) akimagIb + akimagIbacc;
			akrealIcacc = 1.25 * (float) akrealIc + akrealIcacc;
			akimagIcacc = 1.25 * (float) akimagIc + akimagIcacc;
#else
			akrealVaacc = (float) akrealVa + akrealVaacc;
			akimagVaacc = (float) akimagVa + akimagVaacc;
			akrealVbacc = (float) akrealVb + akrealVbacc;
			akimagVbacc = (float) akimagVb + akimagVbacc;
			akrealVcacc = (float) akrealVc + akrealVcacc;
			akimagVcacc = (float) akimagVc + akimagVcacc;
			akrealIaacc = (float) akrealIa + akrealIaacc;
			akimagIaacc = (float) akimagIa + akimagIaacc;
			akrealIbacc = (float) akrealIb + akrealIbacc;
			akimagIbacc = (float) akimagIb + akimagIbacc;
			akrealIcacc = (float) akrealIc + akrealIcacc;
			akimagIcacc = (float) akimagIc + akimagIcacc;
#endif

			akrealVa = 0;
			akrealVb = 0;
			akrealVc = 0;
			akrealIa = 0;
			akrealIb = 0;
			akrealIc = 0;
			akimagVa = 0;
			akimagVb = 0;
			akimagVc = 0;
			akimagIa = 0;
			akimagIb = 0;
			akimagIc = 0;

			IAacc = IAacc + (akrealIaacc) * (akrealIaacc) + (akimagIaacc) * (akimagIaacc);
			IBacc = IBacc + (akrealIbacc) * (akrealIbacc) + (akimagIbacc) * (akimagIbacc);
			ICacc = ICacc + (akrealIcacc) * (akrealIcacc) + (akimagIcacc) * (akimagIcacc);

			VAacc = VAacc + (akrealVaacc) * (akrealVaacc) + (akimagVaacc) * (akimagVaacc);
			VBacc = VBacc + (akrealVbacc) * (akrealVbacc) + (akimagVbacc) * (akimagVbacc);
			VCacc = VCacc + (akrealVcacc) * (akrealVcacc) + (akimagVcacc) * (akimagVcacc);


		#if (FP_COM_HARMONICAS==NAO)
			//cos(a-b)= cos(a)*cos(b)+sin(a)*sin(b)
			PAatacc = PAatacc + (akrealVaacc) * (akrealIaacc) + (akimagVaacc) * (akimagIaacc);
			PBatacc = PBatacc + (akrealVbacc) * (akrealIbacc) + (akimagVbacc) * (akimagIbacc);
			PCatacc = PCatacc + (akrealVcacc) * (akrealIcacc) + (akimagVcacc) * (akimagIcacc);
		#endif
	
			//sin(a-b)= sin(a)*cos(b)-cos(a)*sin(b)
			PAreatacc = PAreatacc + (akimagVaacc) * (akrealIaacc) - (akrealVaacc) * (akimagIaacc);
			PBreatacc = PBreatacc + (akimagVbacc) * (akrealIbacc) - (akrealVbacc) * (akimagIbacc);
			PCreatacc = PCreatacc + (akimagVcacc) * (akrealIcacc) - (akrealVcacc) * (akimagIcacc);


		}



		pUAparaCalculo++;
		pUBparaCalculo++;
		pUCparaCalculo++;
		pIAparaCalculo++;
		pIBparaCalculo++;
		pICparaCalculo++;

		if (pUAparaCalculo == &Ua[TAM_BUFFER_CIRCULAR])
		{
			pUAparaCalculo = &Ua[0];
			pUBparaCalculo = &Ub[0];
			pUCparaCalculo = &Uc[0];
			pIAparaCalculo = &Ia[0];
			pIBparaCalculo = &Ib[0];
			pICparaCalculo = &Ic[0];
		}

	}

	//C�lculo final do valor m�dio
	if (Hab_LeituraMedios == 1)
	{
		UmedioA = fabs((float) VAm / TAM_BUFFER);
		UmedioB = fabs((float) VBm / TAM_BUFFER);
		UmedioC = fabs((float) VCm / TAM_BUFFER);
		ImedioA = fabs((float) IAm / TAM_BUFFER);
		ImedioB = fabs((float) IBm / TAM_BUFFER);
		ImedioC = fabs((float) ICm / TAM_BUFFER);
	}

	pUAparaCalculo = proximoInicioUa;
	pUBparaCalculo = proximoInicioUb;
	pUCparaCalculo = proximoInicioUc;
	pIAparaCalculo = proximoInicioIa;
	pIBparaCalculo = proximoInicioIb;
	pICparaCalculo = proximoInicioIc;

	toogleWDI();
#endif //LEGADO

	//**********Calculo de valores integrados*************
#define FS_DIGITAL (511.0/1.4142135623731)
#define FS_VOLT 300.0
#define FS_AMPER 5.0
#define MAX_ACUMUL 5
	FreqAt1 = FreqAt1 * (260.41666666666666666666666666667e-6) / 4687.0;
	FreqAt2 = FreqAt2 * (260.41666666666666666666666666667e-6) / 4687.0;
	FreqAcumul = FreqAcumul + (-2 + ContadorTimer0forFreq) * 260.41666666666666666666666666667e-6 + FreqAt1 + FreqAt2;
	ContadorTimer0forFreq = 0;
	EtapaMedirFreq = 1;
	FlagHabCalculoFreq = NAO;
	HABILITA_CALC_FREQ;


	ContadorIntegrados =  MAX_ACUMUL; //ContadorIntegrados++;
	if(1) //if (ContadorIntegrados == MAX_ACUMUL)
	{							//se devemos executar os c�lculos finais...

		FreqA = MAX_ACUMUL / (FreqAcumul);
		FreqA = FatorCalibFreq * FreqA / 2;

//#if FIRST==NAO
		if (EquipVirgem == NAO)
		{
			if ((FreqA < 60.5) && (FreqA > 59.5))
			{
				FreqA = 60.0;
			}
			if ((FreqA < 50.5) && (FreqA > 49.5))
			{
				FreqA = 50.0;
			}
		}
//#endif

		FreqAcumul = 0;

		if (ProximoCanal > 6)
		{
			ProximoCanal = 1;
		}

		//********************************************************************/
		//* CALCULOS 
		//********************************************************************/

		//C�lculo do sinal do Q, aten��o: somente o ultimo sinal do Q � o que importa... 
		if (PAreatacc < 0.0) // ALTERADO TFL
		//if ((atan(PAreatacc/PAatacc)-polinomioUA[3]) < 0.0)
		{
			SinalQA = 1.0;
		}
		else
		{
			SinalQA = -1.0;
		}
		if (PBreatacc < 0.0)	
//		if ((atan(PBreatacc/PBatacc)-polinomioUB[3]) < 0.0)
		{
			SinalQB = 1.0;
		}
		else
		{
			SinalQB = -1.0;		     
		}
		if (PCreatacc < 0.0)
//		if (atan(PCreatacc/PCatacc)-polinomioUC[3] < 0.0)
		{
			SinalQC = 1.0;
		}
		else
		{
			SinalQC = -1.0;
		}

	/*	FatorCalibUa_ = FatorCalibUa * 1.2488e+006;
		FatorCalibUb_ = FatorCalibUb * 1.2488e+006;
		FatorCalibUc_ = FatorCalibUc * 1.2488e+006;

		FatorCalibIa_ = FatorCalibIa * 1.248980728851894e+006;
		FatorCalibIb_ = FatorCalibIb * 1.248980728851894e+006;
		FatorCalibIc_ = FatorCalibIc * 1.248980728851894e+006;*/

		UrmsA = FatorCalibUa * sqrt(VAacc);
		UrmsB = FatorCalibUb * sqrt(VBacc);
		UrmsC = FatorCalibUc * sqrt(VCacc);

		UrmsA_ = FatorCalibUa_ * sqrt(VAacc_);	//o '_' indica o true-rms
		UrmsB_ = FatorCalibUb_ * sqrt(VBacc_);
		UrmsC_ = FatorCalibUc_ * sqrt(VCacc_);

		IrmsA = FatorCalibIa * sqrt(IAacc);
		IrmsB = FatorCalibIb * sqrt(IBacc);
		IrmsC = FatorCalibIc * sqrt(ICacc);

		IrmsA_ = FatorCalibIa_ * sqrt(IAacc_);
		IrmsB_ = FatorCalibIb_ * sqrt(IBacc_);
		IrmsC_ = FatorCalibIc_ * sqrt(ICacc_);


		//C�lculo de distor��es harmonicas
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
			/*
			   DhtUA=DhtUAtemp*.14;  //tive que fazer assim porque nao dava tempo de acertar as dhts... placa ruim? rotinas pesadas? falta de precisao do padrao?
			   DhtIA=DhtIAtemp*.2;
			   DhtUB=DhtUBtemp*.14;
			   DhtIB=DhtIBtemp*.2;
			   DhtUC=DhtUCtemp*.14;
			   DhtIC=DhtICtemp*.2; 
			 */
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


		//vamos linearizar o m�dulo da corrente, pois em baixas correntes ele fica ruim...	   

		if (UtilizaPolinomios == SIM)
		{
			// linearizacao de corrente
			// FASE A
			if (IrmsA < 1.00)
			{
				//polinomio para baixas correntes
				//linearizacao de fase
				x = (IrmsA);
				poli = x * polinomioIA[2] + polinomioIA[3];
				x = x * x;
				poli = x * polinomioIA[1] + poli;
				x = x * (IrmsA);
				poli = x * polinomioIA[0] + poli;
				cosfiIA = cos(poli);
				sinfiIA = sin(poli);
				//linearizacao de modulo
#if (COM_LINEARIZACAO_DE_MODULO_DE_CORREMTE==SIM)
				x = (IrmsA);
				poli = x * polinomioModuloIa[2] + polinomioModuloIa[3];
				x = x * x;
				poli = x * polinomioModuloIa[1] + poli;
				x = x * (IrmsA);
				IrmsA = x * polinomioModuloIa[0] + poli;
#endif
				//multiplicacao por relacao TC
				IrmsA = relacaoTC * IrmsA;
			}
			else
			{
				//polinomio para altas correntes
				x = (IrmsA);
				poli = x * polinomioIA[6] + polinomioIA[7];
				x = x * x;
				poli = x * polinomioIA[5] + poli;
				x = x * (IrmsA);
				poli = x * polinomioIA[4] + poli;
				cosfiIA = cos(poli);
				sinfiIA = sin(poli);
				//multiplicacao por relacao TC
				IrmsA = relacaoTC * IrmsA;
			}

			// FASE B
			if (IrmsB < 1.00)
			{
				//polinomio para baixas correntes
				//linearizacao de fase
				x = (IrmsB);
				poli = x * polinomioIB[2] + polinomioIB[3];
				x = x * x;
				poli = x * polinomioIB[1] + poli;
				x = x * (IrmsB);
				poli = x * polinomioIB[0] + poli;
				cosfiIB = cos(poli);
				sinfiIB = sin(poli);
				//linearizacao de modulo

#if (COM_LINEARIZACAO_DE_MODULO_DE_CORREMTE==SIM)
				x = (IrmsB);
				poli = x * polinomioModuloIb[2] + polinomioModuloIb[3];
				x = x * x;
				poli = x * polinomioModuloIb[1] + poli;
				x = x * (IrmsB);
				IrmsB = x * polinomioModuloIb[0] + poli;
				//multiplicacao por relacao TC
#endif
				IrmsB = relacaoTC * IrmsB;

			}
			else
			{
				//polinomio para altas correntes
				x = (IrmsB);
				poli = x * polinomioIB[6] + polinomioIB[7];
				x = x * x;
				poli = x * polinomioIB[5] + poli;
				x = x * (IrmsB);
				poli = x * polinomioIB[4] + poli;
				cosfiIB = cos(poli);
				sinfiIB = sin(poli);
				//multiplicacao por relacao TC
				IrmsB = relacaoTC * IrmsB;
			}

			// FASE C
			if (IrmsC < 1.00)
			{
				//polinomio para baixas correntes
				//linearizacao de fase
				x = (IrmsC);
				poli = x * polinomioIC[2] + polinomioIC[3];
				x = x * x;
				poli = x * polinomioIC[1] + poli;
				x = x * (IrmsC);
				poli = x * polinomioIC[0] + poli;
				cosfiIC = cos(poli);
				sinfiIC = sin(poli);
				//linearizacao de modulo
#if (COM_LINEARIZACAO_DE_MODULO_DE_CORREMTE==SIM)
				x = (IrmsC);
				poli = x * polinomioModuloIc[2] + polinomioModuloIc[3];
				x = x * x;
				poli = x * polinomioModuloIc[1] + poli;
				x = x * (IrmsC);
				IrmsC = x * polinomioModuloIc[0] + poli;
#endif
				//multiplicacao por relacao TC
				IrmsC = relacaoTC * IrmsC;

			}
			else
			{
				//polinomio para altas correntes
				x = (IrmsC);
				poli = x * polinomioIC[6] + polinomioIC[7];
				x = x * x;
				poli = x * polinomioIC[5] + poli;
				x = x * (IrmsC);
				poli = x * polinomioIC[4] + poli;
				cosfiIC = cos(poli);
				sinfiIC = sin(poli);
				//multiplicacao por relacao TC
				IrmsC = relacaoTC * IrmsC;
			}

			// linearizacao de tensao
			// linearizacao de tensao
#if (ENTRADAS_U!=DIVISOR_RESISTIVO)
			// FASE A
			x = (UrmsA);
			poli = x * polinomioUA[2] + polinomioUA[3];
			x = x * x;
			poli = x * polinomioUA[1] + poli;
			x = x * (UrmsA);
			poli = x * polinomioUA[0] + poli;
			cosfiVA = cos(poli);
			sinfiVA = sin(poli);
			UrmsA = relacaoTP * UrmsA;
			// FASE B
			x = (UrmsB);
			poli = x * polinomioUB[2] + polinomioUB[3];
			x = x * x;
			poli = x * polinomioUB[1] + poli;
			x = x * (UrmsB);
			poli = x * polinomioUB[0] + poli;
			cosfiVB = cos(poli);
			sinfiVB = sin(poli);
			UrmsB = relacaoTP * UrmsB;
			// FASE C
			x = (UrmsC);
			poli = x * polinomioUC[2] + polinomioUC[3];
			x = x * x;
			poli = x * polinomioUC[1] + poli;
			x = x * (UrmsC);
			poli = x * polinomioUC[0] + poli;
			cosfiVC = cos(poli);
			sinfiVC = sin(poli);
			UrmsC = relacaoTP * UrmsC;
#endif

#if (ENTRADAS_U==DIVISOR_RESISTIVO)
			cosfiVA = cos(polinomioUA[3]);	//cosfiVA=1;
			sinfiVA = sin(polinomioUA[3]);	//sinfiVA=0;
			UrmsA = relacaoTP * UrmsA;
			cosfiVB = cos(polinomioUB[3]);	//cosfiVA=1;
			sinfiVB = sin(polinomioUB[3]);	//sinfiVA=0;
			UrmsB = relacaoTP * UrmsB;
			cosfiVC = cos(polinomioUC[3]);	//cosfiVA=1;
			sinfiVC = sin(polinomioUC[3]);	//sinfiVA=0;
			UrmsC = relacaoTP * UrmsC;
#endif
		}

		//  goto fimzinho;

		//C�lculo final da pot�ncia Ativa
		//note qua a potencia ativa foi calculada sem levar em conta o erro de m�dulo da corrente!


		#if (FP_COM_HARMONICAS == SIM)
/*	   	PotAtivA =relacaoTC*relacaoTP*FatorCalibIa*FatorCalibUa*PAatacc*(FS_VOLT*FS_AMPER/(FS_DIGITAL*FS_DIGITAL)/(TAM_BUFFER*MAX_ACUMUL));
	   	PotAtivB =relacaoTC*relacaoTP*FatorCalibIb*FatorCalibUb*PBatacc*(FS_VOLT*FS_AMPER/(FS_DIGITAL*FS_DIGITAL)/(TAM_BUFFER*MAX_ACUMUL));
	   	PotAtivC =relacaoTC*relacaoTP*FatorCalibIc*FatorCalibUc*PCatacc*(FS_VOLT*FS_AMPER/(FS_DIGITAL*FS_DIGITAL)/(TAM_BUFFER*MAX_ACUMUL));*/

			PotAtivA =relacaoTC*relacaoTP*FatorCalibIa_*FatorCalibUa_*PAatacc;
			PotAtivB =relacaoTC*relacaoTP*FatorCalibIb_*FatorCalibUb_*PBatacc;
			PotAtivC =relacaoTC*relacaoTP*FatorCalibIc_*FatorCalibUc_*PCatacc;
		#else
			PotAtivA = relacaoTC * relacaoTP * FatorCalibIa * FatorCalibUa * PAatacc;
			PotAtivB = relacaoTC * relacaoTP * FatorCalibIb * FatorCalibUb * PBatacc;
			PotAtivC = relacaoTC * relacaoTP * FatorCalibIc * FatorCalibUc * PCatacc;
		#endif

		PotAtivAmedida = PotAtivA;
		PotAtivBmedida = PotAtivB;
		PotAtivCmedida = PotAtivC;

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
		if (UrmsA < (0.0023 * (float) relacaoTPfat * (float) relacaoTPpri))
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
		if (IrmsA < (0.002 * (float) relacaoTCfat * (float) relacaoTCpri))
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
#if (COM_LINEARIZACAO==SIM)
			if (PotAparA > PotAtivAmedida)
			{
				if (SinalQA<0) //para fp negativos
				{
				PotReatAmedida = SinalQA * relacaoTC * relacaoTP * FatorCalibIa * FatorCalibUa * PAreatacc;
				}
				else	//para fp positivos
				{
				PotReatAmedida = SinalQA * sqrt(PotAparA * PotAparA - PotAtivAmedida * PotAtivAmedida);
				}
			}
			else
			{
				//PotReatAmedida=SinalQA*PotAparA;//esta errado!!!!
				PotReatAmedida = 0.0;	//PotAtivAmedida=PotAparA;
			}

			if (LinearizaSoTP == SIM)
			{
				cosfiIA = 1.0;
				sinfiIA = 0.0;
			}
			//Calculo da Potencia Ativa e Reativa, corrigidas por tabela
			PotAtivA =
				PotAtivAmedida * (cosfiVA * cosfiIA - sinfiVA * sinfiIA) - PotReatAmedida * (sinfiVA * cosfiIA +
																							 cosfiVA * sinfiIA);
			if (PotAparA > PotAtivA)
			{
				PotReatA = SinalQA * sqrt(PotAparA * PotAparA - PotAtivA * PotAtivA);
			}
			else
			{
				//PotReatA =SinalQA*PotAparA;
				PotReatA = 0.0;
				PotAtivA = PotAparA;
			}

#endif

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
			FatPotA = SinalQA * fabs(PotAtivA) / PotAparA;
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
		if (UrmsB < (0.0023 * (float) relacaoTPfat * (float) relacaoTPpri))
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
		if (IrmsB < (0.002 * (float) relacaoTCfat * (float) relacaoTCpri))
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
#if (COM_LINEARIZACAO==SIM)
			if (PotAparB > PotAtivBmedida)
			{
				if (SinalQB<0) //para fp negativos
				{
			    PotReatBmedida = SinalQB * relacaoTC * relacaoTP * FatorCalibIb * FatorCalibUb * PBreatacc;
				}
				else	//para fp positivos
				{
				PotReatBmedida = SinalQB * sqrt(PotAparB * PotAparB - PotAtivBmedida * PotAtivBmedida);
				}



			}
			else
			{
//				PotReatBmedida = SinalQB * PotAparB;
				PotReatBmedida=0;

			}					//esta errado!!!!

			if (LinearizaSoTP == SIM)
			{
				cosfiIB = 1.0;
				sinfiIB = 0.0;
			}

			//Calculo da Potencia Ativa e Reativa, corrigidas por tabela
			PotAtivB =
				PotAtivBmedida * (cosfiVB * cosfiIB - sinfiVB * sinfiIB) - PotReatBmedida * (sinfiVB * cosfiIB +
																							 cosfiVB * sinfiIB);
			if (PotAparB > PotAtivB)
			{
				PotReatB = SinalQB * sqrt(PotAparB * PotAparB - PotAtivB * PotAtivB);
			}
			else
			{
				//PotReatB =SinalQB*PotAparB;
				PotReatB = 0.0;
				PotAtivB = PotAparB;
			}

#endif

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
			FatPotB = SinalQB * fabs(PotAtivB) / PotAparB;
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
		if (UrmsC < (0.0023 * (float) relacaoTPfat * (float) relacaoTPpri))
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
		if (IrmsC < (0.002 * (float) relacaoTCfat * (float) relacaoTCpri))
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
			PotAparC = (UrmsC * IrmsC);
			//C�lculo final da pot�ncia Reativa
#if (COM_LINEARIZACAO==SIM)
			if (PotAparC > PotAtivCmedida)
			{

				if (SinalQC<0) //para fp negativos
				{
				PotReatCmedida = SinalQC * relacaoTC * relacaoTP * FatorCalibIc * FatorCalibUc * PCreatacc;
				}
				else	//para fp positivos
				{
				PotReatCmedida = SinalQC * sqrt(PotAparC * PotAparC - PotAtivCmedida * PotAtivCmedida);
				}

			}
			else
			{
				//PotReatCmedida = SinalQC * PotAparC;
				PotReatCmedida=0;
			}					//esta errado!!!!

			if (LinearizaSoTP == SIM)
			{
				cosfiIC = 1.0;
				sinfiIC = 0.0;
			}
			//Calculo da Potencia Ativa e Reativa, corrigidas por tabela

			PotAtivC =
				PotAtivCmedida * (cosfiVC * cosfiIC - sinfiVC * sinfiIC) - PotReatCmedida * (sinfiVC * cosfiIC +
																							 cosfiVC * sinfiIC);
			if (PotAparC > PotAtivC)
			{
				PotReatC = SinalQC * sqrt(PotAparC * PotAparC - PotAtivC * PotAtivC);
			}
			else
			{
				//PotReatC =SinalQC*PotAparC;
				PotReatC = 0;
				PotAtivC = PotAparC;
			}

#endif

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
			FatPotC = SinalQC * fabs(PotAtivC) / PotAparC;
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

#if (SEMCAPATOR == NAO)
		if ((IrmsA < (0.018 * (float) relacaoTCfat * (float) relacaoTCpri)) && (DhtIA1 > 250.0))
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

		if ((IrmsB < (0.018 * (float) relacaoTCfat * (float) relacaoTCpri)) && (DhtIB1 > 250.0))
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
		if ((IrmsC < (0.018 * (float) relacaoTCfat * (float) relacaoTCpri)) && (DhtIC1 > 250.0))
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

		/* Adicionado por Gabriel */
		if(PotAtivA < 0)
			IrmsA = -IrmsA;

		if(PotAtivB < 0)
			IrmsB = -IrmsB;

		if(PotAtivC < 0)
			IrmsC = -IrmsC;

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
			cont_200ms_for_rtc++;

			if (cont_200ms_for_rtc == 3)
			{
				cont_200ms_for_rtc = 0;
				RTCStop();
				LocalTime1 = RTCGetTime();
				LocalTime1.RTC_Sec = 59;
				LocalTime1.RTC_Min = 14;
				JaRegistrouNoIntervalode15Min = NAO;
				RTCSetTime(LocalTime1);
				RTCStart();
			}
		}
//#endif
#endif

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

		/*
		Zerando os acumuladores parciais
		*/

		IAacc = 0;
		IBacc = 0;
		ICacc = 0;
		VAacc = 0;
		VBacc = 0;
		VCacc = 0;

		PAatacc = 0;
		PBatacc = 0;
		PCatacc = 0;
		PAreatacc = 0;
		PBreatacc = 0;
		PCreatacc = 0;

		akimagIaacc = 0;
		akrealIaacc = 0;
		akimagIbacc = 0;
		akrealIbacc = 0;
		akimagIcacc = 0;
		akrealIcacc = 0;

		akimagVaacc = 0;
		akrealVaacc = 0;
		akimagVbacc = 0;
		akrealVbacc = 0;
		akimagVcacc = 0;
		akrealVcacc = 0;

		VAacc_ = 0;
		VBacc_ = 0;
		VCacc_ = 0;
		IAacc_ = 0;
		IBacc_ = 0;
		ICacc_ = 0;

		//FIO0CLR = VAGO1_PIN; 

		////////////////////////// inicio das novas rotinas de calibracao
		RotinasDeCalibracao();
		////////////////////////// fim das novas rotinas de calibracao

	}
	else						//se ainda temos que acumular os valores...
	{

	}

}
