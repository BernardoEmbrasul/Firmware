#ifndef __FLASH_H
#define __FLASH_H

#define FORA_DO_MESMO_MES_MUITOS_MESES_APOS         1
#define FORA_DO_MESMO_MES_UM_MES_APOS 		        2
#define FORA_DO_DIA_NO_MESMO_MES 			        3
#define	NO_MESMO_INTEVALO_DE_15_MIN 		        4
#define	FORA_DO_INTEVALO_DE_15_MIN_NO_MESMO_DIA	 	5
#define	APOS_DOIS_INTEVALOS_DE_15_MIN_NO_MESMO_DIA 	6


/*
#define SETOR0_INICIO 	0x00000000	  //4kbytes
#define SETOR0_FIM		0X00000FFF	  //
#define SETOR1_INICIO 	0x00001000	  //4kbytes
#define SETOR1_FIM		0X00001FFF	  //
#define SETOR2_INICIO 	0x00002000	  //4kbytes
#define SETOR2_FIM		0X00002FFF	  //
#define SETOR3_INICIO 	0x00003000	  //4kbytes
#define SETOR3_FIM		0X00003FFF	  //
#define SETOR4_INICIO 	0x00004000	  //4kbytes
#define SETOR4_FIM		0X00004FFF	  //
#define SETOR5_INICIO 	0x00005000	  //4kbytes
#define SETOR5_FIM		0X00005FFF	  //
#define SETOR6_INICIO 	0x00006000	  //4kbytes
#define SETOR6_FIM		0X00006FFF	  //
#define SETOR7_INICIO 	0x00007000	  //4kbytes
#define SETOR7_FIM		0X00007FFF	  //      	..ate aqui 32K
#define SETOR8_INICIO 	0x00008000	  //32kbytes
#define SETOR8_FIM		0X0000FFFF	  //
#define SETOR9_INICIO 	0x00010000	  //32kbytes
#define SETOR9_FIM		0X00017FFF	  //
#define SETOR10_INICIO 	0x00018000	  //32kbytes
#define SETOR10_FIM		0X0001FFFF	  //
#define SETOR11_INICIO 	0x00020000	  //32kbytes
#define SETOR11_FIM		0X00027FFF	  //
#define SETOR12_INICIO 	0x00028000	  //32kbytes
#define SETOR12_FIM		0X0002FFFF	  //       ...at� aqui 192k
#define SETOR13_INICIO 	0x00030000	  //32kbytes  ......
#define SETOR13_FIM		0X00037FFF	  //32kbytes
#define SETOR14_INICIO 	0x00038000	  //32kbytes
#define SETOR14_FIM		0X0003FFFF	  //32kbytes
#define SETOR15_INICIO 	0x00040000	  //32kbytes  ......
#define SETOR15_FIM		0X00047FFF	  //32kbytes
#define SETOR16_INICIO 	0x00048000	  //32kbytes
#define SETOR16_FIM		0X0004FFFF	  //32kbytes
#define SETOR17_INICIO 	0x00050000	  //32kbytes  ......
#define SETOR17_FIM		0X00057FFF	  //32kbytes
#define SETOR18_INICIO 	0x00058000	  //32kbytes
#define SETOR18_FIM		0X0005FFFF	  //32kbytes
#define SETOR19_INICIO 	0x00060000	  //32kbytes  ......
#define SETOR19_FIM		0X00067FFF	  //32kbytes
#define SETOR20_INICIO 	0x00068000	  //32kbytes
#define SETOR20_FIM		0X0006FFFF	  //32kbytes
#define SETOR21_INICIO 	0x00070000	  //32kbytes  ......
#define SETOR21_FIM		0X00077FFF	  //32kbytes
#define SETOR22_INICIO 	0x00078000	  //4kbytes
#define SETOR22_FIM		0X00078FFF	  //4kbytes
#define SETOR23_INICIO 	0x00079000	  //4kbytes
#define SETOR23_FIM		0X00079FFF	  //4kbytes
#define SETOR24_INICIO 	0x0007A000	  //4kbytes
#define SETOR24_FIM		0X0007AFFF	  //4kbytes
#define SETOR25_INICIO 	0x0007B000	  //4kbytes
#define SETOR25_FIM		0X0007BFFF	  //4kbytes
#define SETOR26_INICIO 	0x0007C000	  //4kbytes
#define SETOR26_FIM		0X0007CFFF	  //4kbytes





#define SETOR_MM_INICIO 	SETOR13_INICIO	  //32kbytes por setor
#define SETOR_MM_FIM		SETOR21_FIM	  	  //32kbytes por setor

#define SETOR_CALIBRACAO_INICIO			SETOR23_INICIO
#define SETOR_CALIBRACAO_FIM			SETOR23_FIM
#define SETOR_PARAMETRIZACAO_INICIO		SETOR24_INICIO
#define SETOR_PARAMETRIZACAO_FIM		SETOR24_FIM
#define SETOR_DADOS1_INICIO				SETOR25_INICIO
#define SETOR_DADOS1_FIM				SETOR25_FIM
#define SETOR_DADOS2_INICIO				SETOR26_INICIO
#define SETOR_DADOS2_FIM				SETOR26_FIM



#define ADDR_FLASH_SECTOR_0     ((uint32_t)0x08000000)  Base address of Sector 0, 16 Kbytes
#define ADDR_FLASH_SECTOR_1     ((uint32_t)0x08004000)  Base address of Sector 1, 16 Kbytes
#define ADDR_FLASH_SECTOR_2     ((uint32_t)0x08008000)  Base address of Sector 2, 16 Kbytes
#define ADDR_FLASH_SECTOR_3     ((uint32_t)0x0800C000)  Base address of Sector 3, 16 Kbytes
#define ADDR_FLASH_SECTOR_4     ((uint32_t)0x08010000)  Base address of Sector 4, 64 Kbytes
#define ADDR_FLASH_SECTOR_5     ((uint32_t)0x08020000)  Base address of Sector 5, 128 Kbytes
#define ADDR_FLASH_SECTOR_6     ((uint32_t)0x08040000)  Base address of Sector 6, 128 Kbytes
#define ADDR_FLASH_SECTOR_7     ((uint32_t)0x08060000)  Base address of Sector 7, 128 Kbytes
#define ADDR_FLASH_SECTOR_8     ((uint32_t)0x08080000)  Base address of Sector 8, 128 Kbytes
#define ADDR_FLASH_SECTOR_9     ((uint32_t)0x080A0000)  Base address of Sector 9, 128 Kbytes
#define ADDR_FLASH_SECTOR_10    ((uint32_t)0x080C0000)  Base address of Sector 10, 128 Kbytes
#define ADDR_FLASH_SECTOR_11    ((uint32_t)0x080E0000)  Base address of Sector 11, 128 Kbytes


  RAM    (xrw)    : ORIGIN = 0x20000000,   LENGTH = 320K
  FLASH_CALIBRACAO    		(rx)    : ORIGIN = 0x08000000,   LENGTH = 16K
  FLASH_PARAMETRIZACAO	    (rx)    : ORIGIN = 0x08004000,   LENGTH = 16K
  FLASH_DADOS1    			(rx)    : ORIGIN = 0x08008000,   LENGTH = 16K
  FLASH_DADOS2    			(rx)    : ORIGIN = 0x0800c000,   LENGTH = 16K
  FLASH_BOOTLOADER   	    (rx)    : ORIGIN = 0x08010000,   LENGTH = 64K
  FLASH       				(rx)    : ORIGIN = 0x08020000,   LENGTH = 640K
  FLASH_MM    				(rx)    : ORIGIN = 0x080c0000,   LENGTH = 256K



*/


 #define  FLASH_CALIBRACAO    	0x08000000  //atenção, nos primeiors 1500bytes se encontra o firstjump, depois disso começam os coef. de calibração //0x08000000
 #define  FLASH_PARAMETRIZACAO	0x08004000
 #define  FLASH_DADOS1    		0x08008000
 #define  FLASH_DADOS2    		0x0800c000
 #define  FLASH_BOOTLOADER   	0x08010000
 #define  FLASH_CODIGO          0x08020000
 #define  FLASH_MM    			0x080A0000


#define SETOR_MM_INICIO 	FLASH_MM
#define SETOR_MM_FIM		(FLASH_MM+384*1024-1)  //(FLASH_MM+256*1024-1)


#define SETOR_MM_BASE0 SETOR_MM_INICIO
#define SETOR_MM_BASE1 (SETOR_MM_INICIO+(32*1024*4*1))
#define SETOR_MM_BASE2 (SETOR_MM_INICIO+(32*1024*4*2))
#define SETOR_MM_BASE3 (SETOR_MM_INICIO+(32*1024*4*3))
#define SETOR_MM_BASE4 (SETOR_MM_INICIO+(32*1024*4*4))




#define SETOR_CALIBRACAO_INICIO			FLASH_CALIBRACAO
#define SETOR_CALIBRACAO_FIM			(FLASH_CALIBRACAO+16*1024-1)

#define SETOR_PARAMETRIZACAO_INICIO		FLASH_PARAMETRIZACAO
#define SETOR_PARAMETRIZACAO_FIM		(FLASH_PARAMETRIZACAO+16*1024-1)
#define SETOR_DADOS1_INICIO				FLASH_DADOS1
#define SETOR_DADOS1_FIM				(FLASH_DADOS1+16*1024-1)
#define SETOR_DADOS2_INICIO				FLASH_DADOS2
#define SETOR_DADOS2_FIM				(FLASH_DADOS2+16*1024-1)



#define SALTO_NO_SETOR 256
#define SALTO_NO_SETOR_DADOS 1024
#define SALTO_NO_SETOR_MM 2048
#if LEGADO
#define SALTO_ENTRE_SETORES_MM 0x8000
#else
#define SALTO_ENTRE_SETORES_MM 0x20000  //cada setor da MM possui 128kbytes
#endif


// 	TipoDeEVENTO
#define BLANK 							0xFF  //proximos 512bytes=blank
#define QUEDA							1
#define RE_PROGRAMACOES_VIA_TECLADO		2
#define RE_PROGRAMACAO_DO_RELOGIO		3
#define REGISTRO_ANTERIOR_INVALIDO		4
#define REGISTRO_DO_INICIO_DO_DIA		5
#define REGISTRO_DE_DADOS_NORMAL		6

typedef struct {
	short TipoDeEvento;
	RTCTime HoraDaVolta;
	RTCTime HoraDaQueda;
	short LrcHeader;
} FlashDataHeader;

typedef struct
{
	BYTE SectorStatus;
	BYTE SectorID;
	BYTE GravCount0;
	BYTE GravCount1;
} CabecalhoRodape;
//#pragma __arm
extern void RestauraCalibracao(void);
extern void IniciaParametrosCalibracaoDefault(void);
extern void MoveFlashToBuffer( BYTE const* pToflash, BYTE *pToBuffer, unsigned int NumberOfBytes);
extern void MoveRamToBuffer(BYTE *pToRam, BYTE *pToBuffer, unsigned int NumberOfBytes);
extern void MoveBufferToRam(BYTE *pToBuffer,BYTE *pToRam, unsigned int NumberOfBytes);
extern void MoveBytesBufferToBuffer(BYTE *pBufferSource,BYTE *pToBufferDest, short NumberOfBytes);
extern void AtualizaParametrizacaoNaFlash(void);
extern void AvaliaFuncaoRemota(void);
EXT void PowerDown(void);
EXT void PowerUp(void);
extern void RestauraParametrizacao(void)   ;
extern void SalvaParametrizacao(void);
extern void FindNextDataBlock(void);
extern BYTE CalcLRCofDataHeader(FlashDataHeader Header);
extern void  AtualizaPolinomios(void);
extern void RestauraParametrizacaoDefault(void);

unsigned char BuscaSetorAtualMM(void);
unsigned char TestaMomento(RTCTime hvolta,RTCTime hqueda);
unsigned char TestaMomento1(RTCTime hvolta,RTCTime hqueda);

//
#define SETOR_VAZIO		0xFF
#define SETOR_OCUPADO	0x0F
#define SETOR_CHEIO 	0x00


//tipos de eventos
#define VOLTA							0
#define QUEDA							1
#define RE_PROGRAMACOES_VIA_TECLADO		2
#define RE_PROGRAMACAO_DO_RELOGIO		3
#define REGISTRO_ANTERIOR_INVALIDO		4
#define REGISTRO_DO_INICIO_DO_DIA		5
#define REGISTRO_DE_DADOS_NORMAL		6 //por ex, de 15min em 15 min


#define LSB 0
#define MSB 1


#endif
