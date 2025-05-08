/*****************************************************************************
 *   modbus.h: 
 *
 *
 *   History
 *   
 *
 ******************************************************************************/
#ifndef __MODBUS_H__
#define __MODBUS_H__

#define NORMAL_MODBUS					 			 0
//VALORES PARA A VARIAVEL FUNCAOREMOTA1							
#define DEFAULT 									 0	
#define LINEARIZA_SO_TP								 1	
#define READ_NORMAL_MODBUS 							 2	
#define READ_FLASH									 3	
#define FULL_RAM									 4	
#define MODBUS_LIBERADO								 5	
#define CALIBRA_AC_AGORA_E_GRAVA_CALIBRACAO			 6	
#define CALIBRA_CORRENTE_A							 7	
#define CALIBRA_CORRENTE_B							 8	
#define CALIBRA_CORRENTE_C							 9	
#define CALIBRA_EM_MEIO_AMPERE_A	 				 10	
#define CALIBRA_EM_MEIO_AMPERE_B	 				 11	
#define CALIBRA_EM_MEIO_AMPERE_C	 				 12	
#define FINALIZA_CALIBRACAO	 						 13	
#define RESETA_SISTEMA								 14	
#define APAGA_ULTIMOS_SETORES						 15	
#define ATUALIZA_POLINOMIOS	 						 16	
#define HABILITA_MEDICAO_FREQUENCIA	 				 17	
#define MEDE_NIVEL_DC	 							 18	
#define ESCREVE_FATORES_DE_CALIBRACAO	 			 19 	
#define DESABILITA_MEDICAO_FREQUENCIA	 			 20	
#define DESABILITA_CAPATOR	 		 				 21	
#define HABILITA_CAPATOR	 		 				 22	
#define APAGA_SETOR_CALIBRACAO	 					 23	
#define APAGA_SETOR_FLASH_PARAMETRIZACAO			 24	
#define ZERA_DHT_TENSOES						 	 25
#define ZERA_DHT_TENSOES_INIT					 	 26
#define ZERA_DHT_IA								 	 27
#define ZERA_DHT_IA_INIT						 	 28
#define ZERA_DHT_IB								 	 29
#define ZERA_DHT_IB_INIT						 	 30
#define ZERA_DHT_IC								 	 31
#define ZERA_DHT_IC_INIT							 32
#define CALIBRA_CORRENTE_A_LIN0	 					 33
#define CALIBRA_CORRENTE_A_LIN1						 34
#define CALIBRA_CORRENTE_A_LIN2						 35
#define CALIBRA_CORRENTE_A_LIN3						 36
#define CALIBRA_CORRENTE_B_LIN0						 37
#define CALIBRA_CORRENTE_B_LIN1						 38
#define CALIBRA_CORRENTE_B_LIN2						 39
#define CALIBRA_CORRENTE_B_LIN3						 40
#define CALIBRA_CORRENTE_C_LIN0						 41
#define CALIBRA_CORRENTE_C_LIN1						 42
#define CALIBRA_CORRENTE_C_LIN2						 43
#define CALIBRA_CORRENTE_C_LIN3						 44
#define READ_FLASH1									 45
#define READ_FLASH2									 46									
#define READ_FLASH3									 47
#define READ_FLASH4									 48
#define READ_FLASH5									 49
#define BOOTLOADER									 50
#define FATORESNOVOS								 51
#define FATORESNOVOS2								 52
#define INIT_MM_BATT_RAM							 60
#define FLASH_PAG3									 63
#define FLASH_PAG4									 64
#define FLASH_PAG5									 65
#define FLASH_PAG6									 66
#define FLASH_PAG7									 67

short  Xor(short in1, short in2);
extern void ComMODBUSInit(void);
extern short CalcCRC(short oldCRC, BYTE newbyte);
EXT void ResponderMODBUS(void);

extern void AnalizaBufferMODBUS(void);
extern void AnalizaBufferMODBUS_MASTER(void);
extern BOOL ComparaCRC(short index);

#define FUNC_REMOTA_DEFAULT 						0
#define FUNC_REMOTA_APAGA_TOTAIS_ABSOLUTOS 			1
#define FUNC_REMOTA_BLOQUEIO_TECLADO_OFF			2
#define FUNC_REMOTA_BLOQUEIO_TECLADO_ON				3
#define FUNC_REMOTA_RELE_ON							4
#define FUNC_REMOTA_RELE_OFF						5	
#define FUNC_REMOTA_APAGA_TOTAIS_HORARIOS			6
#define FUNC_REMOTA_CICLAR_TELAS 					7	
#define FUNC_REMOTA_MEDICAO_CONCESSIONARIA 			8
#define FUNC_REMOTA_FORCE_POWERDOWN					9
#define FUNC_REMOTA_ZERAED1							10
#define FUNC_REMOTA_ZERAED2							11
#define FUNC_REMOTA_SEM_HARMONICAS					12
#define FUNC_REMOTA_COM_HARMONICAS					13

//Modo 1 = com todas as correntes em s�rie (fase B invertida no HW!).
#define ETAPA00_MODO1_CAL_DC	     1
#define ETAPA01_MODO1_CAL_V			 2
#define ETAPA02_MODO1_CAL_DHTV		 3
#define ETAPA03_MODO1_CAL_I_HIGH	 4
#define ETAPA04_MODO1_CAL_FP_HIGH	 5
#define ETAPA05_MODO1_CAL_DHTI		 6
#define ETAPA06_MODO1_CAL_I_LOW		 7
#define ETAPA07_MODO1_CAL_FP_LOW	 8


//Modo 2 = com as correntes calibradas uma por vez.
#define ETAPA00_MODO2_CAL_DC		 9
#define ETAPA01_MODO2_CAL_V			 10
#define ETAPA02_MODO2_CAL_DHTV		 11
#define ETAPA03_MODO2_CAL_IA_HIGH	 12
#define ETAPA04_MODO2_CAL_FPA_HIGH	 13
#define ETAPA05_MODO2_CAL_DHTIA		 14
#define ETAPA06_MODO2_CAL_IB_HIGH	 15
#define ETAPA07_MODO2_CAL_FPB_HIGH	 16
#define ETAPA08_MODO2_CAL_DHTIB		 17
#define ETAPA09_MODO2_CAL_IC_HIGH	 18
#define ETAPA10_MODO2_CAL_FPC_HIGH	 19
#define ETAPA11_MODO2_CAL_DHTIC		 20
#define ETAPA12_MODO2_CAL_IA_LOW	 21
#define ETAPA13_MODO2_CAL_FPA_LOW	 22
#define ETAPA14_MODO2_CAL_IB_LOW	 23
#define ETAPA15_MODO2_CAL_FPB_LOW	 24
#define ETAPA16_MODO2_CAL_IC_LOW	 25
#define ETAPA17_MODO2_CAL_FPC_LOW	 26
//Prepara��o para novas calibra��es
#define ETAPA_PREPARA_CALIB_V		 27
#define ETAPA_PREPARA_CALIB_I		 28
#define ETAPA_PREPARA_CALIB_DHTV	 29
#define ETAPA_PREPARA_CALIB_DHTI	 30
#define ETAPA_PREPARA_CALIB_FP_HIGH	 31
#define ETAPA_PREPARA_CAL_FP_LOW 	 32
#define ETAPA_PREPARA_CALIB_IA		 33
#define ETAPA_PREPARA_CALIB_IB		 34
#define ETAPA_PREPARA_CALIB_IC		 35
#define ETAPA_PREPARA_CALIB_DHTVA	 36
#define ETAPA_PREPARA_CALIB_DHTVB	 37
#define ETAPA_PREPARA_CALIB_DHTVC	 38
#define ETAPA_PREPARA_CALIB_DHTIA	 39
#define ETAPA_PREPARA_CALIB_DHTIB	 40
#define ETAPA_PREPARA_CALIB_DHTIC	 41
#define ETAPA_PREPARA_CALIB_FP_HIGHA 42
#define ETAPA_PREPARA_CALIB_FP_HIGHB 43
#define ETAPA_PREPARA_CALIB_FP_HIGHC 44
#define ETAPA_PREPARA_CAL_FP_LOWA 	 45
#define ETAPA_PREPARA_CAL_FP_LOWB 	 46
#define ETAPA_PREPARA_CAL_FP_LOWC 	 47
//Gravar Calibra��es realizadas
#define ETAPA_GRAVAR_SETOR_CALIBRACAO 48
#define ETAPA_CALIB_TEMPERATURA 49



extern void AnalizaBufferPR4000(void);

// Defini��es utilizadas no protocolo do PR4000
#define eCOMNINGUEM 0
#define eCOMIGO 1
#define eCOMTODOS 2

#define NS0   				0 //MSB
#define NS1                 1
#define NS2				 	2
#define NS3				 	3
#define NS4				 	4
#define NS5				 	5
#define NS6				 	6
#define NS7				 	7
#define FUNC_PR4000         8
#define relacaoTPpriMSB 	9
#define relacaoTPpriLSB     10
#define relacaoTPsecMSB					    11
#define relacaoTPsecLSB 				    12
#define relacaoTPfatMSB					    13
#define relacaoTPfatLSB 				    14
#define relacaoTCpriMSB 				    15
#define relacaoTCpriLSB					    16
#define relacaoTCsecMSB					    17
#define relacaoTCsecLSB                     18
#define relacaoTCfatMSB					    19
#define relacaoTCfatLSB 				    20
#define rtcAnoMSB                                           21
#define rtcAnoLSB                                           22
#define rtcMesMSB                                           23
#define rtcMesLSB                                           24
#define rtcDiaAnoMSB                                        25
#define rtcDiaAnoLSB                                        26
#define rtcDiaSemanaMSB                                     27
#define rtcDiaSemanaLSB                                     28
#define rtcDiaMesMSB                                         29
#define rtcDiaMesLSB                                         30
#define rtcHoraMSB                                           31
#define rtcHoraLSB                                           32
#define rtcMinMSB                                            33
#define rtcMinLSB                                            34
#define rtcSegMSB                                            35
#define rtcSegLSB                                            36
#define hora_ponta_inicio1_horaMSB                           37
#define hora_ponta_inicio1_horaLSB                           38
#define hora_ponta_inicio1_minMSB  	                     39
#define hora_ponta_inicio1_minLSB  	                     40
#define hora_fora_ponta_inicio1_horaMSB                      41
#define hora_fora_ponta_inicio1_horaLSB                      42
#define hora_fora_ponta_inicio1_minMSB                       43
#define hora_fora_ponta_inicio1_minLSB                       44
#define hora_reserv_inicio1_horaMSB 	                     45
#define hora_reserv_inicio1_horaLSB 	                     46
#define hora_reserv_inicio1_minMSB  	                     47
#define hora_reserv_inicio1_minLSB  	                     48
#define hora_ponta_inicio2_horaMSB 	                     49
#define hora_ponta_inicio2_horaLSB 	                     50
#define hora_ponta_inicio2_minMSB  	                     51
#define hora_ponta_inicio2_minLSB  	                     52
#define hora_fora_ponta_inicio2_horaMSB                      53
#define hora_fora_ponta_inicio2_horaLSB                      54
#define hora_fora_ponta_inicio2_minMSB                       55
#define hora_fora_ponta_inicio2_minLSB                       56
#define hora_reserv_inicio2_horaMSB 	                     57
#define hora_reserv_inicio2_horaLSB 	                     58
#define hora_reserv_inicio2_minMSB  	                     59
#define hora_reserv_inicio2_minLSB  	                     60
#define hora_ponta_inicio3_horaMSB 	                     61
#define hora_ponta_inicio3_horaLSB 	                     62
#define hora_ponta_inicio3_minMSB  	                     63
#define hora_ponta_inicio3_minLSB  	                     64
#define hora_fora_ponta_inicio3_horaMSB                      65
#define hora_fora_ponta_inicio3_horaLSB                      66
#define hora_fora_ponta_inicio3_minMSB                       67
#define hora_fora_ponta_inicio3_minLSB                       68
#define hora_reserv_inicio3_horaMSB                          69
#define hora_reserv_inicio3_horaLSB 	                     70
#define hora_reserv_inicio3_minMSB  	                     71
#define hora_reserv_inicio3_minLSB  	                     72
#define hora_ponta_inicio4_horaMSB 	                     73
#define hora_ponta_inicio4_horaLSB 	                     74
#define hora_ponta_inicio4_minMSB                            75
#define hora_ponta_inicio4_minLSB                            76
#define hora_fora_ponta_inicio4_horaMSB                      77
#define hora_fora_ponta_inicio4_horaLSB                      78
#define hora_fora_ponta_inicio4_minMSB                       79
#define hora_fora_ponta_inicio4_minLSB                       80
#define hora_reserv_inicio4_horaMSB                          81
#define hora_reserv_inicio4_horaLSB                          82
#define hora_reserv_inicio4_minMSB                           83
#define hora_reserv_inicio4_minLSB                           84
#define feriados1Dia                                         85
#define feriados1Mes                                         86
#define feriados2Dia                                         87   
#define feriados2Mes                                         88   
#define feriados3Dia                                         89   
#define feriados3Mes                                         90   
#define feriados4Dia                                         91   
#define feriados4Mes                                         92
#define feriados5Dia                                         93   
#define feriados5Mes                                         94   
#define feriados6Dia                                         95   
#define feriados6Mes                                         96     
#define feriados7Dia                                         97     
#define feriados7Mes                                         98     
#define feriados8Dia                                         99
#define feriados8Mes                                         100     
#define feriados9Dia                                         101   
#define feriados9Mes                                         102     
#define feriados10Dia                                        103     
#define feriados10Mes                                        104   
#define feriados11Dia                                        105     
#define feriados11Mes                                        106
#define feriados12Dia                                        107      
#define feriados12Mes                                        108   
#define feriados13Dia                                        109       
#define feriados13Mes                                        110     
#define feriados14Dia                                        111    
#define feriados14Mes                                        112     
#define feriados15Dia                                         113
#define feriados15Mes                                         114     
#define feriados16Dia                                         115    
#define feriados16Mes                                         116      
#define feriados17Dia                                         117     
#define feriados17Mes                                         118   
#define feriados18Dia                                         119     
#define feriados18Mes                                         120
#define feriados19Dia                                         121     
#define feriados19Mes                                         122    
#define feriados20Dia                                         123     
#define feriados20Mes                                         124     
#define EnderecoMODBUS                                        125
#define BAUDRate                                              126
#define PARIDStops                                            127
#define XIPOcteto1                                            128     
#define XIPOcteto2                                            129   
#define XIPOcteto3			                      			  130    
#define XIPOcteto4                                            131     
#define XMKOcteto1                                            132    
#define XMKOcteto2                                            133     
#define XMKOcteto3                                            134
#define XMKOcteto4			                      			  135     
#define XGWOcteto1			                      			  136    
#define XGWOcteto2                                            137     
#define XGWOcteto3                                            138     
#define XGWOcteto4                                            139   
#define XNroPorta                                             140           
#define XEqPARAMETRIZADO								 	  141	


#endif

