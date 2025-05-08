/*
 *  * //////////md////////////*/


/* opções de equipamentos da linh básica
 MD_EQUIP
 CA_EQUIP
 CP_EQUIP
 CT_EQUIP
 CD_EQUIP
*/

// DEFINIR O EQUIPAMENTO DA LINHA BÁSICA A SER USADO
#define EQUIP_LINHA50 MD_EQUIP

#define CA_EQUIP_ENTRADAS_VOLT 1  //definir 1 se o CA50 será com 4 ch em [V], caso 0 serão 4 ch em [mA]
#define MAXIMA_TEMP_CT50  110    //acima deste valor, considero que o canal está aberto!
#define EQUIP EQUIP_LINHA50	// Op��es: TR_EQUIP , MD_EQUIP, CM_EQUIP

//equipamentos derivados de outros:  (EQUIP � redefinido em config.h)
#define MD4040TI 0
#define MD4060 0

#define CAPATOR_VALOR_Amp 0.03  //0.03A é o usual, em casos com TI aumentar apara 1A no minimo


#define MONO_TRI TRIFASICO 		// S� vale para controlador de fator de pot�ncia ( MONOFASICO ou TRIFASICO)
#define SeisEstagios  			// S� vale para controlador de fator de pot�ncia	(SeisEstagios ou DozeEstagios)
//#define MODELO_EARHT			// Modelo de sensor de temperatura
//#define MODELO_S501			// Modelo de sensor de temperatura
#define MEMORIA_DE_MASSA_NOVA		// Este define deve ser fixo pois este firmware apenas deve ser gravado em equipamentos compativeis com pwr5000
//#define MEDE_TEMPERATURA			// Modelo de sensor de temperatura
//#define MODELO_EA					// Comunica��o ethernet
#define MODELO_RA 				// Comunica��o RS485
//#define MODELO_REA 				// Comunica��o ethernet e RS485
#define COM_TOROIDE					// Se n�o for modelo T
//#define TOROIDE_TRIFASICO			// Quando for modelo T
//#define MODELO_DURACAO_PULSO		// Mede a dura��o de uma carga ligada
//#define MODELO_D					// Entradas digitais/pulso
//#define TECLADO_NOVO				// Apenas para placas do MD4040TI e MD4060

//permite escrever na regi�o da MM, para permitir atualiza��o a dist�ncia via Eth, cuidado! isto desprotege a escrita na RAM do MD!  (corrigir depois)
#define ATUALIZ_VIA_ETH
//#define BLOQUEIA_TP_TC

//#define MODEM_GSM_QUECTEL

/*
 * //////////tr/////////////
#define EQUIP TR_EQUIP	// Opções: TR_EQUIP , MD_EQUIP, CM_EQUIP

//equipamentos derivados de outros:  (EQUIP é redefinido em config.h)
#define MD4040TI 0
#define MD4060 0
#define CP40 0


#define MONO_TRI TRIFASICO 		// Só vale para controlador de fator de potência ( MONOFASICO ou TRIFASICO)
#define SeisEstagios  			// Só vale para controlador de fator de potência	(SeisEstagios ou DozeEstagios)
//#define MODELO_EARHT			// Modelo de sensor de temperatura
//#define MODELO_S501			// Modelo de sensor de temperatura
#define MEMORIA_DE_MASSA_NOVA		// Este define deve ser fixo pois este firmware apenas deve ser gravado em equipamentos compativeis com pwr5000
//#define MEDE_TEMPERATURA			// Modelo de sensor de temperatura
#define MODELO_EA					// Comunicação ethernet
//#define MODELO_RA 				// Comunicação RS485
#define COM_TOROIDE					// Se não for modelo T
//#define TOROIDE_TRIFASICO			// Quando for modelo T
//#define MODELO_DURACAO_PULSO		// Mede a duração de uma carga ligada
#define MODELO_D					// Entradas digitais/pulso
//#define TECLADO_NOVO				// Apenas para placas do MD4040TI e MD4060

//permite escrever na região da MM, para permitir atualização a distância via Eth, cuidado! isto desprotege a escrita na RAM do MD!  (corrigir depois)
#define ATUALIZ_VIA_ETH
//#define BLOQUEIA_TP_TC

//#define MODEM_GSM_QUECTEL
*/

/*
//////////cm4040/////////////
#define EQUIP CM_EQUIP	// Opções: TR_EQUIP , MD_EQUIP, CM_EQUIP

//equipamentos derivados de outros:  (EQUIP é redefinido em config.h)
#define MD4040TI 0
#define MD4060 0
#define CP40 0

//#define TECLADO_NOVO

#define MONO_TRI TRIFASICO 		// Só vale para controlador de fator de potência ( MONOFASICO ou TRIFASICO)
#define DozeEstagios  			// Só vale para controlador de fator de potência	(SeisEstagios ou DozeEstagios)
//#define  MODELO_EARHT			// Modelo de sensor de temperatura
//#define  MODELO_S501			// Modelo de sensor de temperatura
#define  MEMORIA_DE_MASSA_NOVA		// Este define deve ser fixo pois este firmware apenas deve ser gravado em equipamentos compativeis com pwr5000
#define  MEDE_TEMPERATURA			// Modelo de sensor de temperatura
#define  MODELO_EA 						// Comunicação ethernet
//#define  MODELO_RA 					// Comunicação RS485
#define COM_TOROIDE					// sempre se CM4040 Se não for modelo T
//#define COM_FLEX
//#define TOROIDE_TRIFASICO		   // Quando for modelo T
//#define MODELO_DURACAO_PULSO	// Mede a duração de uma carga ligada
//#define MODELO_D   			// Entradas digitais/pulso
//#define TECLADO_NOVO			  // Apenas para placa do MD4060

//permite escrever na região da MM, para permitir atualização a distância via Eth, cuidado! isto desprotege a escrita na RAM do MD!  (corrigir depois)
#define ATUALIZ_VIA_ETH
//#define BLOQUEIA_TP_TC

//#define MODEM_GSM_QUECTEL

*/

/*
//////////cp40/////////////
#define EQUIP TR_EQUIP	// Opções: TR_EQUIP , MD_EQUIP, CM_EQUIP

//equipamentos derivados de outros:  (EQUIP é redefinido em config.h)
#define MD4040TI 0
#define MD4060 0
#define CP40 1


#define MONO_TRI TRIFASICO 		// Só vale para controlador de fator de potência
#define SeisEstagios  			// Só vale para controlador de fator de potência
//#define  MODELO_EARHT			// Modelo de sensor de temperatura
//#define  MODELO_S501			// Modelo de sensor de temperatura
#define  MEMORIA_DE_MASSA_NOVA		// Modelo de sensor de temperatura
#define  MODELO_EA 						// Comunicação ethernet
//#define  MODELO_RA 					// Comunicação RS485
#define COM_TOROIDE
//#define TOROIDE_TRIFASICO
//#define MODELO_DURACAO_PULSO	// Mede a duração de uma carga ligada
#define MODELO_D   			// Entradas digitais/pulso
//#define TECLADO_NOVO

//permite escrever na região da MM, para permitir atualização a distância via Eth, cuidado! isto desprotege a escrita na RAM do MD!  (corrigir depois)
#define ATUALIZ_VIA_ETH

//#define MODEM_GSM_QUECTEL
*/

/*
//////////ca40/////////////
#define EQUIP TR_EQUIP	// Opções: TR_EQUIP , MD_EQUIP, CM_EQUIP

//equipamentos derivados de outros:  (EQUIP é redefinido em config.h)
#define MD4040TI 0
#define MD4060 0
#define CP40 1


#define MONO_TRI TRIFASICO 		// Só vale para controlador de fator de potência
#define SeisEstagios  			// Só vale para controlador de fator de potência
//#define  MODELO_EARHT			// Modelo de sensor de temperatura
//#define  MODELO_S501			// Modelo de sensor de temperatura
#define  MEMORIA_DE_MASSA_NOVA		// Modelo de sensor de temperatura
#define  MODELO_EA 						// Comunicação ethernet
//#define  MODELO_RA 					// Comunicação RS485
#define COM_TOROIDE
//#define TOROIDE_TRIFASICO
//#define MODELO_DURACAO_PULSO	// Mede a duração de uma carga ligada
#define MODELO_D   			// Entradas digitais/pulso
//#define TECLADO_NOVO

//permite escrever na região da MM, para permitir atualização a distância via Eth, cuidado! isto desprotege a escrita na RAM do MD!  (corrigir depois)
#define ATUALIZ_VIA_ETH

//#define PLACA_ANTIGA

//#define MODEM_GSM_QUECTEL

*/


/*
 /////////////ct40////////////
#define EQUIP TR_EQUIP	// Opções: TR_EQUIP , MD_EQUIP, CM_EQUIP

//equipamentos derivados de outros:  (EQUIP é redefinido em config.h)
#define MD4040TI 0
#define MD4060 0
#define CP40 1


#define MONO_TRI TRIFASICO 		// Só vale para controlador de fator de potência
#define SeisEstagios  			// Só vale para controlador de fator de potência
//#define  MODELO_EARHT			// Modelo de sensor de temperatura
//#define  MODELO_S501			// Modelo de sensor de temperatura
#define  MEMORIA_DE_MASSA_NOVA		// Modelo de sensor de temperatura
#define  MODELO_EA 						// Comunicação ethernet
//#define  MODELO_RA 					// Comunicação RS485
#define COM_TOROIDE
//#define TOROIDE_TRIFASICO
//#define MODELO_DURACAO_PULSO	// Mede a duração de uma carga ligada
#define MODELO_D   			// Entradas digitais/pulso
//#define TECLADO_NOVO

//permite escrever na região da MM, para permitir atualização a distância via Eth, cuidado! isto desprotege a escrita na RAM do MD!  (corrigir depois)
#define ATUALIZ_VIA_ETH

//#define MODEM_GSM_QUECTEL
*/












