#ifndef __BATT_RAM_H
#define __BATT_RAM_H

#include "rtc.h"
#include "stm32f4xx_hal.h"

//LEGADO aqui abaixo
#define RTC_RAM_BASE_ADDR   BKPSRAM_BASE
//#define BaseBattRam				(*(volatile unsigned long *)(RTC_RAM_BASE_ADDR + 0x000))

typedef struct _RegistroCabecalho2K1{
	unsigned long id;	//identificador do tipo de registro

} BaseBattRam1;

typedef struct _EstruturaBattRam2{
	int buffer[100];

} BaseBattRam2;

#define BattRam1 (*(volatile BaseBattRam1 *)(RTC_RAM_BASE_ADDR + 0x000))
#define BattRam2 (*(volatile BaseBattRam2 *)(RTC_RAM_BASE_ADDR + 0x9ff)) //A BATTRAM tem 4kbytes, estou "iniciando" a BattRam2 512 bytes acima do fim da região BattRam1





#define REG_BATT_MEM_ALT_CONFIG		0x0001
#define REG_BATT_MEM_NORM_COM_RTC		0x0002
#define REG_BATT_MEM_NORM_SEM_RTC		0x0003
#define REG_BATT_MEM_ALT_FLASH_ESCRITA	0x0004
#define REG_BATT_MEM_ATV_FLASH_LEITURA	0x0005
#define REG_BATT_MEM_ALT_RELES			0x0006
#define REG_BATT_MEM_Q 					0x0007
#define REG_BATT_MEM_V					0x0008
#define DEFAULT1						0x0009
#define REG_BATT_MEM_QPULSO				0x0010
#define REG_BATT_MEM_VPULSO				0x0011
#define REG_BATT_MEM_NORM_MD4040TI_3G	0x0012
#define REG_BATT_MEM_NORM_COM_RTC_ANTES_DE_QUEDA	0x000B
#define REG_BATT_MEM_ALERTA_BAT_MORTA	0x000C
#define REG_BATT_MEM_SHORT_COM_RTC		0x000E
#define REG_BATT_MEM_SHORT_SEM_RTC		0x000F

#define REG_BATT_MEM_INIT				DEFAULT1

//  RTCTime LocalTime;
void InitBatteryRam(void);
void MoveBatteryRamToFlash(void);
void ClearBatteryRam(void);
void EraseMMSector(unsigned long int Sector);
//void VerificaConsistencia(unsigned long int Sector);
void AtualizaLRCBloco2K(void);
void GravaNaBatteryRAM(short TipoDeRegistro);
void GravaNaBatteryRAM1(short TipoDeRegistro);

typedef struct _RegistroDeAlteracoesConfig {
	DWORD id; //identificador do tipo de registro//4bytes
	//	DWORD LastValidPosInFlashMM;
	RTCTime HorarioDaAlteracao;					//16bytes
	DWORD TempoDeIntegracaoGrandezas;			//4bytes

} RegistroDeAlteracoesConfig_;


typedef struct _RegistroNormalComRelogio{
	DWORD id; //identificador do tipo de registro	//4bytes
	RTCTime HorarioDoEvento;						//16bytes
	//U64	  Timestamp;
	float MMUa_;	//Ua								//4bytes
	float MMUb_;	//Ub								//4bytes
	float MMUc_;	//Uc								//4bytes
	float MMIa_;	//Ia								//4bytes
	float MMIb_;	//Ib								//4bytes
	float MMIc_;	//Ic								//4bytes
	float MMDemP_;	//Demanda 3F P					//4bytes
	float MMDemQ_;	//Demanda 3F R					//4bytes
	float MMFp_;		//FP 3F							//4bytes
	//float MMTemp;

} RegistroNormalComRelogio_;

typedef struct _RegistroMD4040TI{
	DWORD id;			//identificador do tipo de registro 4
	DWORD dummy;		//4
	U64	  Timestamp;	//8
	float MMUa_;			//Ua 10x4
	float MMUb_;			//Ub
	float MMUc_;			//Uc
	float MMIa_;			//Ia
	float MMIb_;			//Ib
	float MMIc_;			//Ic
	float MMDemP_;		//Demanda 3F  P
	float MMDemQ_;		//Demanda 3F  R
	float MMTemp_;
	float MMTemp2_;
	float MMPulso1;
	float MMPulso2;
	float MMStatusDosReles;
} RegistroMD4040TI_;

typedef struct _RegistroNormalSemRelogio {
	DWORD id;			//identificador do tipo de registro
	float MMUa_;			//Ua
	float MMUb_;			//Ub
	float MMUc_;			//Uc
	float MMIa_;			//Ia
	float MMIb_;			//Ib
	float MMIc_;			//Ic
	float MMDemP_;		//Demanda 3F P
	float MMDemQ_;		//Demanda 3F R
	float MMFp_;			//FP 3F
} RegistroNormalSemRelogio_;

#if (USAR_REGISTRO_SHORT==SIM)
typedef struct _RegistroShortComRelogio{
	DWORD id;			//identificador do tipo de registro
	RTCTime HorarioDoEvento;
	float MMUa_;			//Ua
	float MMIa_;			//Ia
	float MMDemP_;		//Demanda 3F  P
	float MMDemQ_;		//Demanda 3F  R
} RegistroShortComRelogio_;

typedef struct _RegistroShortSemRelogio {
	DWORD id;			//identificador do tipo de registro
	float MMUa_;			//Ua
	float MMIa_;			//Ia
	float MMDemP_;		//Demanda 3F  P
	float MMDemQ_;		//Demanda 3F  R
} RegistroShortSemRelogio_;
#endif

typedef struct _RegistroDeAlteracoesFlash {
	DWORD id; //identificador do tipo de registro (0:leitura 1:escrita)		//4bytes
	RTCTime HorarioDaAlteracao;												//16bytes
	DWORD EnderecoInicial;													//4bytes
	DWORD EnderecoFinal;													//4bytes
} RegistroDeAlteracoesFlash_;

typedef struct _RegistroDeLeituraFlash {
	DWORD id; //identificador do tipo de registro (0:leitura 1:escrita)		//4bytes
	RTCTime HorarioDaLeitura;												//16bytes
	DWORD EnderecoInicial;													//4bytes
	//	DWORD EnderecoFinal;
} RegistroDeLeituraFlash_;

typedef struct _RegistroDeAlteracoesReles {
	DWORD id; //identificador do tipo de registro (0:desligado 1:ligado)	//4bytes
	RTCTime HorarioDaAlteracao;												//16bytes
	DWORD StatusReles;														//4bytes
} RegistroDeAlteracoesReles_;


typedef struct _RegistroDeQuedas_e_Voltas {
	DWORD id; //identificador do tipo de registro (x: quedas y:voltas )		//4bytes
	RTCTime HorarioDoEvento;												//16bytes
} RegistroDeQuedas_e_Voltas_;

typedef struct _RegistroCabecalho2K{
	DWORD   id; //identificador do tipo de registro
	RTCTime HorarioDaEscritaNoCabecalho;
	RTCTime HorarioDaUltimaQueda;
	RTCTime HorarioDaUltimaVolta;
	DWORD   ProximoEnderecoAserEscritoNaFlash;
	DWORD   ProximoEnderecoAserApagadoNaFlash;
	DWORD   ProximoEnderecoAserEscritoNaBattRam;
	DWORD   TempoDeIntegracaoGrandezas;
	DWORD   FlagProximoRegistroSeraComRTC;
	DWORD   LRC; //lrc dos dados do bloco de 2K
	DWORD   NextPos;
} BaseBattRam;



#if (DEBUG_SEM_BLOCO2K_EM_BATTRAM==NAO)

#define RegistroCabecalho2K (*(volatile BaseBattRam *)(RTC_RAM_BASE_ADDR + 0x000))
#define RegistroCabecalho2KPlus1024 (*(volatile BaseBattRam *)(RTC_RAM_BASE_ADDR + 0x400))
#endif

#endif
