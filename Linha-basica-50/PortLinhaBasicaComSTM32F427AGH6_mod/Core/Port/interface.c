
/*****************************************************************************
 *   interface.c:  Aqui se encontram as rotinas de interfaceamento com
 * 	 o usu�rio (telas, teclado, etc...)
 *
 *   Projeto MD2010-ARM
 *
 *   History
 *   2006.29.05  ver. codigo 1.00  Vers�o Preliminar.
 *
 *
 ******************************************************************************/
#undef EXT
#define EXT extern
#include "global.h"
#include "main.h"

#if EQUIP!=CM_EQUIP

//char const tela_apresentacao[]="    []d 4000 1p00";

typedef struct Teclas
{
	BYTE null;
	BYTE up;
	BYTE down;
	BYTE left;
	BYTE rigth;
	BYTE esc;
	BYTE prog;
} Teclas;

Teclas FuncoesDasTeclas[NUMERO_DE_TELAS];


/*
   Inicializa Funcao Das Teclas
 */
void TecladoInit()
{
	int i;
	/*Nas telas de exibi��o, todas as teclas tem a mesma fun��o*/
	for (i=INICIO_TELAS_DE_EXIBICAO;i<=FIM_TELAS_DE_EXIBICAO;i++)
	{
		FuncoesDasTeclas[i].null = NONE;
		FuncoesDasTeclas[i].up	 = NONE;
		FuncoesDasTeclas[i].down = NONE;
		FuncoesDasTeclas[i].left = GOTO_TELA_ANTERIOR;
		FuncoesDasTeclas[i].rigth= GOTO_TELA_PROXIMA;
		FuncoesDasTeclas[i].esc	 = NONE;
		FuncoesDasTeclas[i].prog = ENTRA_MODO_PRG;
	}

	FuncoesDasTeclas[TELA_PROG_REL_TP_PRI].null = NONE;
	FuncoesDasTeclas[TELA_PROG_REL_TP_PRI].up   = GOTO_REL_TP_PRI_MOD;
	FuncoesDasTeclas[TELA_PROG_REL_TP_PRI].down = GOTO_REL_TP_PRI_MOD;
	FuncoesDasTeclas[TELA_PROG_REL_TP_PRI].left = GOTO_TELA_ANTERIOR;
	FuncoesDasTeclas[TELA_PROG_REL_TP_PRI].rigth= GOTO_TELA_PROXIMA;
	FuncoesDasTeclas[TELA_PROG_REL_TP_PRI].esc  = SAIR_MODO_PRG_SEM_GRAVAR;
	FuncoesDasTeclas[TELA_PROG_REL_TP_PRI].prog = GOTO_TELA_GRAVAR_SIM_NAO;

	FuncoesDasTeclas[TELA_PROG_REL_TP_PRI_MOD].null = NONE;
	FuncoesDasTeclas[TELA_PROG_REL_TP_PRI_MOD].up   = INCREMENTA_ALGARISMO_INT;
	FuncoesDasTeclas[TELA_PROG_REL_TP_PRI_MOD].down = DECREMENTA_ALGARISMO_INT;
	FuncoesDasTeclas[TELA_PROG_REL_TP_PRI_MOD].left = GOTO_ALG_ANTERIOR_INT;
	FuncoesDasTeclas[TELA_PROG_REL_TP_PRI_MOD].rigth= GOTO_ALG_PROXIMO_INT;
	FuncoesDasTeclas[TELA_PROG_REL_TP_PRI_MOD].esc  = ABANDONA_PROG_REL_TP_PRI;
	FuncoesDasTeclas[TELA_PROG_REL_TP_PRI_MOD].prog = GRAVA_PROG_REL_TP_PRI;

	FuncoesDasTeclas[TELA_PROG_REL_TP_SEC].null = NONE;
	FuncoesDasTeclas[TELA_PROG_REL_TP_SEC].up   = GOTO_REL_TP_SEC_MOD;
	FuncoesDasTeclas[TELA_PROG_REL_TP_SEC].down = GOTO_REL_TP_SEC_MOD;
	FuncoesDasTeclas[TELA_PROG_REL_TP_SEC].left = GOTO_TELA_ANTERIOR;
	FuncoesDasTeclas[TELA_PROG_REL_TP_SEC].rigth= GOTO_TELA_PROXIMA;
	FuncoesDasTeclas[TELA_PROG_REL_TP_SEC].esc  = SAIR_MODO_PRG_SEM_GRAVAR;
	FuncoesDasTeclas[TELA_PROG_REL_TP_SEC].prog = GOTO_TELA_GRAVAR_SIM_NAO;


	FuncoesDasTeclas[TELA_PROG_REL_TP_SEC_MOD].null = NONE;
	FuncoesDasTeclas[TELA_PROG_REL_TP_SEC_MOD].up   = INCREMENTA_ALGARISMO_INT;
	FuncoesDasTeclas[TELA_PROG_REL_TP_SEC_MOD].down = DECREMENTA_ALGARISMO_INT;
	FuncoesDasTeclas[TELA_PROG_REL_TP_SEC_MOD].left = GOTO_ALG_ANTERIOR_INT;
	FuncoesDasTeclas[TELA_PROG_REL_TP_SEC_MOD].rigth= GOTO_ALG_PROXIMO_INT;
	FuncoesDasTeclas[TELA_PROG_REL_TP_SEC_MOD].esc  = ABANDONA_PROG_REL_TP_SEC;
	FuncoesDasTeclas[TELA_PROG_REL_TP_SEC_MOD].prog = GRAVA_PROG_REL_TP_SEC;

	FuncoesDasTeclas[TELA_PROG_REL_TP_FAT].null = NONE;
	FuncoesDasTeclas[TELA_PROG_REL_TP_FAT].up   = GOTO_REL_TP_FAT_MOD;
	FuncoesDasTeclas[TELA_PROG_REL_TP_FAT].down = GOTO_REL_TP_FAT_MOD;
	FuncoesDasTeclas[TELA_PROG_REL_TP_FAT].left = GOTO_TELA_ANTERIOR;
	FuncoesDasTeclas[TELA_PROG_REL_TP_FAT].rigth= GOTO_TELA_PROXIMA;
	FuncoesDasTeclas[TELA_PROG_REL_TP_FAT].esc  = SAIR_MODO_PRG_SEM_GRAVAR;
	FuncoesDasTeclas[TELA_PROG_REL_TP_FAT].prog = GOTO_TELA_GRAVAR_SIM_NAO;

	FuncoesDasTeclas[TELA_PROG_REL_TP_FAT_MOD].null = NONE;
	FuncoesDasTeclas[TELA_PROG_REL_TP_FAT_MOD].up   = INCREMENTA_ALGARISMO_INT;
	FuncoesDasTeclas[TELA_PROG_REL_TP_FAT_MOD].down = DECREMENTA_ALGARISMO_INT;
	FuncoesDasTeclas[TELA_PROG_REL_TP_FAT_MOD].left = GOTO_ALG_ANTERIOR_INT;
	FuncoesDasTeclas[TELA_PROG_REL_TP_FAT_MOD].rigth= GOTO_ALG_PROXIMO_INT;
	FuncoesDasTeclas[TELA_PROG_REL_TP_FAT_MOD].esc  = ABANDONA_PROG_REL_TP_FAT;
	FuncoesDasTeclas[TELA_PROG_REL_TP_FAT_MOD].prog = GRAVA_PROG_REL_TP_FAT;

	FuncoesDasTeclas[TELA_PROG_REL_TC_PRI].null = NONE;
	FuncoesDasTeclas[TELA_PROG_REL_TC_PRI].up   = GOTO_REL_TC_PRI_MOD;
	FuncoesDasTeclas[TELA_PROG_REL_TC_PRI].down = GOTO_REL_TC_PRI_MOD;
	FuncoesDasTeclas[TELA_PROG_REL_TC_PRI].left = GOTO_TELA_ANTERIOR;
	FuncoesDasTeclas[TELA_PROG_REL_TC_PRI].rigth= GOTO_TELA_PROXIMA;
	FuncoesDasTeclas[TELA_PROG_REL_TC_PRI].esc  = SAIR_MODO_PRG_SEM_GRAVAR;
	FuncoesDasTeclas[TELA_PROG_REL_TC_PRI].prog = GOTO_TELA_GRAVAR_SIM_NAO;


	FuncoesDasTeclas[TELA_PROG_REL_TC_PRI_MOD].null = NONE;
	FuncoesDasTeclas[TELA_PROG_REL_TC_PRI_MOD].up   = INCREMENTA_ALGARISMO_INT;
	FuncoesDasTeclas[TELA_PROG_REL_TC_PRI_MOD].down = DECREMENTA_ALGARISMO_INT;
	FuncoesDasTeclas[TELA_PROG_REL_TC_PRI_MOD].left = GOTO_ALG_ANTERIOR_INT;
	FuncoesDasTeclas[TELA_PROG_REL_TC_PRI_MOD].rigth= GOTO_ALG_PROXIMO_INT;
	FuncoesDasTeclas[TELA_PROG_REL_TC_PRI_MOD].esc  = ABANDONA_PROG_REL_TC_PRI;
	FuncoesDasTeclas[TELA_PROG_REL_TC_PRI_MOD].prog = GRAVA_PROG_REL_TC_PRI;

	FuncoesDasTeclas[TELA_PROG_REL_TC_SEC].null = NONE;
	FuncoesDasTeclas[TELA_PROG_REL_TC_SEC].up   = GOTO_REL_TC_SEC_MOD;
	FuncoesDasTeclas[TELA_PROG_REL_TC_SEC].down = GOTO_REL_TC_SEC_MOD;
	FuncoesDasTeclas[TELA_PROG_REL_TC_SEC].left = GOTO_TELA_ANTERIOR;
	FuncoesDasTeclas[TELA_PROG_REL_TC_SEC].rigth= GOTO_TELA_PROXIMA;
	FuncoesDasTeclas[TELA_PROG_REL_TC_SEC].esc  = SAIR_MODO_PRG_SEM_GRAVAR;
	FuncoesDasTeclas[TELA_PROG_REL_TC_SEC].prog = GOTO_TELA_GRAVAR_SIM_NAO;

	FuncoesDasTeclas[TELA_PROG_REL_TC_SEC_MOD].null = NONE;
	FuncoesDasTeclas[TELA_PROG_REL_TC_SEC_MOD].up   = INCREMENTA_ALGARISMO_INT;
	FuncoesDasTeclas[TELA_PROG_REL_TC_SEC_MOD].down = DECREMENTA_ALGARISMO_INT;
	FuncoesDasTeclas[TELA_PROG_REL_TC_SEC_MOD].left = GOTO_ALG_ANTERIOR_INT;
	FuncoesDasTeclas[TELA_PROG_REL_TC_SEC_MOD].rigth= GOTO_ALG_PROXIMO_INT;
	FuncoesDasTeclas[TELA_PROG_REL_TC_SEC_MOD].esc  = ABANDONA_PROG_REL_TC_SEC;
	FuncoesDasTeclas[TELA_PROG_REL_TC_SEC_MOD].prog = GRAVA_PROG_REL_TC_SEC;

	FuncoesDasTeclas[TELA_PROG_REL_TC_FAT].null = NONE;
	FuncoesDasTeclas[TELA_PROG_REL_TC_FAT].up   = GOTO_REL_TC_FAT_MOD;
	FuncoesDasTeclas[TELA_PROG_REL_TC_FAT].down = GOTO_REL_TC_FAT_MOD;
	FuncoesDasTeclas[TELA_PROG_REL_TC_FAT].left = GOTO_TELA_ANTERIOR;
	FuncoesDasTeclas[TELA_PROG_REL_TC_FAT].rigth= GOTO_TELA_PROXIMA;
	FuncoesDasTeclas[TELA_PROG_REL_TC_FAT].esc  = SAIR_MODO_PRG_SEM_GRAVAR;
	FuncoesDasTeclas[TELA_PROG_REL_TC_FAT].prog = GOTO_TELA_GRAVAR_SIM_NAO;

	FuncoesDasTeclas[TELA_PROG_REL_TC_FAT_MOD].null = NONE;
	FuncoesDasTeclas[TELA_PROG_REL_TC_FAT_MOD].up   = INCREMENTA_ALGARISMO_INT;
	FuncoesDasTeclas[TELA_PROG_REL_TC_FAT_MOD].down = DECREMENTA_ALGARISMO_INT;
	FuncoesDasTeclas[TELA_PROG_REL_TC_FAT_MOD].left = GOTO_ALG_ANTERIOR_INT;
	FuncoesDasTeclas[TELA_PROG_REL_TC_FAT_MOD].rigth= GOTO_ALG_PROXIMO_INT;
	FuncoesDasTeclas[TELA_PROG_REL_TC_FAT_MOD].esc  = ABANDONA_PROG_REL_TC_FAT;
	FuncoesDasTeclas[TELA_PROG_REL_TC_FAT_MOD].prog = GRAVA_PROG_REL_TC_FAT;

	FuncoesDasTeclas[TELA_PROG_RESET_CONSUMO].null = NONE;
	FuncoesDasTeclas[TELA_PROG_RESET_CONSUMO].up   = GOTO_RESET_CONSUMO_MOD;
	FuncoesDasTeclas[TELA_PROG_RESET_CONSUMO].down = GOTO_RESET_CONSUMO_MOD;
	FuncoesDasTeclas[TELA_PROG_RESET_CONSUMO].left = GOTO_TELA_ANTERIOR;
	FuncoesDasTeclas[TELA_PROG_RESET_CONSUMO].rigth= GOTO_TELA_PROXIMA;
	FuncoesDasTeclas[TELA_PROG_RESET_CONSUMO].esc  = SAIR_MODO_PRG_SEM_GRAVAR;
	FuncoesDasTeclas[TELA_PROG_RESET_CONSUMO].prog = GOTO_TELA_GRAVAR_SIM_NAO;

	FuncoesDasTeclas[TELA_PROG_RESET_CONSUMO_MOD].null = NONE;
	FuncoesDasTeclas[TELA_PROG_RESET_CONSUMO_MOD].up   = ALTERA_SIM_NAO;
	FuncoesDasTeclas[TELA_PROG_RESET_CONSUMO_MOD].down = ALTERA_SIM_NAO;
	FuncoesDasTeclas[TELA_PROG_RESET_CONSUMO_MOD].left = ALTERA_SIM_NAO;
	FuncoesDasTeclas[TELA_PROG_RESET_CONSUMO_MOD].rigth= ALTERA_SIM_NAO;
	FuncoesDasTeclas[TELA_PROG_RESET_CONSUMO_MOD].esc  = ABANDONA_PROG_RESET_CONSUMO;
	FuncoesDasTeclas[TELA_PROG_RESET_CONSUMO_MOD].prog = GRAVA_PROG_RESET_CONSUMO;

	FuncoesDasTeclas[TELA_PROG_ESCRAVO_MODBUS].null = NONE;
	FuncoesDasTeclas[TELA_PROG_ESCRAVO_MODBUS].up   = GOTO_ESCRAVO_MODBUS_MOD;
	FuncoesDasTeclas[TELA_PROG_ESCRAVO_MODBUS].down = GOTO_ESCRAVO_MODBUS_MOD;
	FuncoesDasTeclas[TELA_PROG_ESCRAVO_MODBUS].left = GOTO_TELA_ANTERIOR;
	FuncoesDasTeclas[TELA_PROG_ESCRAVO_MODBUS].rigth= GOTO_TELA_PROXIMA;
	FuncoesDasTeclas[TELA_PROG_ESCRAVO_MODBUS].esc  = SAIR_MODO_PRG_SEM_GRAVAR;
	FuncoesDasTeclas[TELA_PROG_ESCRAVO_MODBUS].prog = GOTO_TELA_GRAVAR_SIM_NAO;

	FuncoesDasTeclas[TELA_PROG_ESCRAVO_MODBUS_MOD].null = NONE;
	FuncoesDasTeclas[TELA_PROG_ESCRAVO_MODBUS_MOD].up   = INCREMENTA_ALGARISMO_BYTE;
	FuncoesDasTeclas[TELA_PROG_ESCRAVO_MODBUS_MOD].down = DECREMENTA_ALGARISMO_BYTE;
	FuncoesDasTeclas[TELA_PROG_ESCRAVO_MODBUS_MOD].left = GOTO_ALG_ANTERIOR_BYTE;
	FuncoesDasTeclas[TELA_PROG_ESCRAVO_MODBUS_MOD].rigth= GOTO_ALG_PROXIMO_BYTE;
	FuncoesDasTeclas[TELA_PROG_ESCRAVO_MODBUS_MOD].esc  = ABANDONA_PROG_ESCRAVO_MODBUS;
	FuncoesDasTeclas[TELA_PROG_ESCRAVO_MODBUS_MOD].prog = GRAVA_PROG_ESCRAVO_MODBUS;


	FuncoesDasTeclas[TELA_PROG_BAUD_RATE].null = NONE;
	FuncoesDasTeclas[TELA_PROG_BAUD_RATE].up   = GOTO_BAUD_RATE_MOD;
	FuncoesDasTeclas[TELA_PROG_BAUD_RATE].down = GOTO_BAUD_RATE_MOD;
	FuncoesDasTeclas[TELA_PROG_BAUD_RATE].left = GOTO_TELA_ANTERIOR;
	FuncoesDasTeclas[TELA_PROG_BAUD_RATE].rigth= GOTO_TELA_PROXIMA;
	FuncoesDasTeclas[TELA_PROG_BAUD_RATE].esc  = SAIR_MODO_PRG_SEM_GRAVAR;
	FuncoesDasTeclas[TELA_PROG_BAUD_RATE].prog = GOTO_TELA_GRAVAR_SIM_NAO;

	FuncoesDasTeclas[TELA_PROG_BAUD_RATE_MOD].null = NONE;
	FuncoesDasTeclas[TELA_PROG_BAUD_RATE_MOD].up   = INCREMENTA_BAUD_RATE;
	FuncoesDasTeclas[TELA_PROG_BAUD_RATE_MOD].down = DECREMENTA_BAUD_RATE;
	FuncoesDasTeclas[TELA_PROG_BAUD_RATE_MOD].left = DECREMENTA_BAUD_RATE;
	FuncoesDasTeclas[TELA_PROG_BAUD_RATE_MOD].rigth= INCREMENTA_BAUD_RATE;
	FuncoesDasTeclas[TELA_PROG_BAUD_RATE_MOD].esc  = ABANDONA_PROG_BAUD_RATE;
	FuncoesDasTeclas[TELA_PROG_BAUD_RATE_MOD].prog = GRAVA_PROG_BAUD_RATE;


	FuncoesDasTeclas[TELA_PROG_PARIDADE_STOPS].null = NONE;
	FuncoesDasTeclas[TELA_PROG_PARIDADE_STOPS].up   = GOTO_PARIDADE_STOPS_MOD;
	FuncoesDasTeclas[TELA_PROG_PARIDADE_STOPS].down = GOTO_PARIDADE_STOPS_MOD;
	FuncoesDasTeclas[TELA_PROG_PARIDADE_STOPS].left = GOTO_TELA_ANTERIOR;
	FuncoesDasTeclas[TELA_PROG_PARIDADE_STOPS].rigth= GOTO_TELA_PROXIMA;
	FuncoesDasTeclas[TELA_PROG_PARIDADE_STOPS].esc  = SAIR_MODO_PRG_SEM_GRAVAR;
	FuncoesDasTeclas[TELA_PROG_PARIDADE_STOPS].prog = GOTO_TELA_GRAVAR_SIM_NAO;

	FuncoesDasTeclas[TELA_PROG_PARIDADE_STOPS_MOD].null = NONE;
	FuncoesDasTeclas[TELA_PROG_PARIDADE_STOPS_MOD].up   = INCREMENTA_PARIDADE_STOPS;
	FuncoesDasTeclas[TELA_PROG_PARIDADE_STOPS_MOD].down = DECREMENTA_PARIDADE_STOPS;
	FuncoesDasTeclas[TELA_PROG_PARIDADE_STOPS_MOD].left = DECREMENTA_PARIDADE_STOPS;
	FuncoesDasTeclas[TELA_PROG_PARIDADE_STOPS_MOD].rigth= INCREMENTA_PARIDADE_STOPS;
	FuncoesDasTeclas[TELA_PROG_PARIDADE_STOPS_MOD].esc  = ABANDONA_PROG_PARIDADE_STOPS;
	FuncoesDasTeclas[TELA_PROG_PARIDADE_STOPS_MOD].prog = GRAVA_PROG_PARIDADE_STOPS;

	//#ifdef SEM_ETHERNET NAO
	FuncoesDasTeclas[TELA_PROG_IP_OCTETO1].null = NONE;
	FuncoesDasTeclas[TELA_PROG_IP_OCTETO1].up   = GOTO_IP_OCTETO1_MOD;
	FuncoesDasTeclas[TELA_PROG_IP_OCTETO1].down = GOTO_IP_OCTETO1_MOD;
	FuncoesDasTeclas[TELA_PROG_IP_OCTETO1].left = GOTO_TELA_ANTERIOR;
	FuncoesDasTeclas[TELA_PROG_IP_OCTETO1].rigth= GOTO_TELA_PROXIMA;
	FuncoesDasTeclas[TELA_PROG_IP_OCTETO1].esc  = SAIR_MODO_PRG_SEM_GRAVAR;
	FuncoesDasTeclas[TELA_PROG_IP_OCTETO1].prog = GOTO_TELA_GRAVAR_SIM_NAO;

	FuncoesDasTeclas[TELA_PROG_IP_OCTETO1_MOD].null = NONE;
	FuncoesDasTeclas[TELA_PROG_IP_OCTETO1_MOD].up   = INCREMENTA_ALGARISMO_BYTE;
	FuncoesDasTeclas[TELA_PROG_IP_OCTETO1_MOD].down = DECREMENTA_ALGARISMO_BYTE;
	FuncoesDasTeclas[TELA_PROG_IP_OCTETO1_MOD].left = GOTO_ALG_ANTERIOR_BYTE;
	FuncoesDasTeclas[TELA_PROG_IP_OCTETO1_MOD].rigth= GOTO_ALG_PROXIMO_BYTE;
	FuncoesDasTeclas[TELA_PROG_IP_OCTETO1_MOD].esc  = ABANDONA_PROG_IP_OCTETO1;
	FuncoesDasTeclas[TELA_PROG_IP_OCTETO1_MOD].prog = GRAVA_PROG_IP_OCTETO1;

	FuncoesDasTeclas[TELA_PROG_IP_OCTETO2].null = NONE;
	FuncoesDasTeclas[TELA_PROG_IP_OCTETO2].up   = GOTO_IP_OCTETO2_MOD;
	FuncoesDasTeclas[TELA_PROG_IP_OCTETO2].down = GOTO_IP_OCTETO2_MOD;
	FuncoesDasTeclas[TELA_PROG_IP_OCTETO2].left = GOTO_TELA_ANTERIOR ;
	FuncoesDasTeclas[TELA_PROG_IP_OCTETO2].rigth= GOTO_TELA_PROXIMA ;
	FuncoesDasTeclas[TELA_PROG_IP_OCTETO2].esc  = SAIR_MODO_PRG_SEM_GRAVAR;
	FuncoesDasTeclas[TELA_PROG_IP_OCTETO2].prog = GOTO_TELA_GRAVAR_SIM_NAO;

	FuncoesDasTeclas[TELA_PROG_IP_OCTETO2_MOD].null = NONE;
	FuncoesDasTeclas[TELA_PROG_IP_OCTETO2_MOD].up   = INCREMENTA_ALGARISMO_BYTE;
	FuncoesDasTeclas[TELA_PROG_IP_OCTETO2_MOD].down = DECREMENTA_ALGARISMO_BYTE;
	FuncoesDasTeclas[TELA_PROG_IP_OCTETO2_MOD].left = GOTO_ALG_ANTERIOR_BYTE;
	FuncoesDasTeclas[TELA_PROG_IP_OCTETO2_MOD].rigth= GOTO_ALG_PROXIMO_BYTE;
	FuncoesDasTeclas[TELA_PROG_IP_OCTETO2_MOD].esc  = ABANDONA_PROG_IP_OCTETO2;
	FuncoesDasTeclas[TELA_PROG_IP_OCTETO2_MOD].prog = GRAVA_PROG_IP_OCTETO2;

	FuncoesDasTeclas[TELA_PROG_IP_OCTETO3].null = NONE;
	FuncoesDasTeclas[TELA_PROG_IP_OCTETO3].up   = GOTO_IP_OCTETO3_MOD;
	FuncoesDasTeclas[TELA_PROG_IP_OCTETO3].down = GOTO_IP_OCTETO3_MOD;
	FuncoesDasTeclas[TELA_PROG_IP_OCTETO3].left = GOTO_TELA_ANTERIOR;
	FuncoesDasTeclas[TELA_PROG_IP_OCTETO3].rigth= GOTO_TELA_PROXIMA;
	FuncoesDasTeclas[TELA_PROG_IP_OCTETO3].esc  = SAIR_MODO_PRG_SEM_GRAVAR;
	FuncoesDasTeclas[TELA_PROG_IP_OCTETO3].prog = GOTO_TELA_GRAVAR_SIM_NAO;

	FuncoesDasTeclas[TELA_PROG_IP_OCTETO3_MOD].null = NONE;
	FuncoesDasTeclas[TELA_PROG_IP_OCTETO3_MOD].up   = INCREMENTA_ALGARISMO_BYTE;
	FuncoesDasTeclas[TELA_PROG_IP_OCTETO3_MOD].down = DECREMENTA_ALGARISMO_BYTE;
	FuncoesDasTeclas[TELA_PROG_IP_OCTETO3_MOD].left = GOTO_ALG_ANTERIOR_BYTE;
	FuncoesDasTeclas[TELA_PROG_IP_OCTETO3_MOD].rigth= GOTO_ALG_PROXIMO_BYTE;
	FuncoesDasTeclas[TELA_PROG_IP_OCTETO3_MOD].esc  = ABANDONA_PROG_IP_OCTETO3;
	FuncoesDasTeclas[TELA_PROG_IP_OCTETO3_MOD].prog = GRAVA_PROG_IP_OCTETO3;

	FuncoesDasTeclas[TELA_PROG_IP_OCTETO4].null = NONE;
	FuncoesDasTeclas[TELA_PROG_IP_OCTETO4].up   = GOTO_IP_OCTETO4_MOD;
	FuncoesDasTeclas[TELA_PROG_IP_OCTETO4].down = GOTO_IP_OCTETO4_MOD;
	FuncoesDasTeclas[TELA_PROG_IP_OCTETO4].left = GOTO_TELA_ANTERIOR;
	FuncoesDasTeclas[TELA_PROG_IP_OCTETO4].rigth= GOTO_TELA_PROXIMA;
	FuncoesDasTeclas[TELA_PROG_IP_OCTETO4].esc  = SAIR_MODO_PRG_SEM_GRAVAR;
	FuncoesDasTeclas[TELA_PROG_IP_OCTETO4].prog = GOTO_TELA_GRAVAR_SIM_NAO;

	FuncoesDasTeclas[TELA_PROG_IP_OCTETO4_MOD].null = NONE;
	FuncoesDasTeclas[TELA_PROG_IP_OCTETO4_MOD].up   = INCREMENTA_ALGARISMO_BYTE;
	FuncoesDasTeclas[TELA_PROG_IP_OCTETO4_MOD].down = DECREMENTA_ALGARISMO_BYTE;
	FuncoesDasTeclas[TELA_PROG_IP_OCTETO4_MOD].left = GOTO_ALG_ANTERIOR_BYTE;
	FuncoesDasTeclas[TELA_PROG_IP_OCTETO4_MOD].rigth= GOTO_ALG_PROXIMO_BYTE;
	FuncoesDasTeclas[TELA_PROG_IP_OCTETO4_MOD].esc  = ABANDONA_PROG_IP_OCTETO4;
	FuncoesDasTeclas[TELA_PROG_IP_OCTETO4_MOD].prog = GRAVA_PROG_IP_OCTETO4;

	FuncoesDasTeclas[TELA_PROG_MK_OCTETO1].null = NONE;
	FuncoesDasTeclas[TELA_PROG_MK_OCTETO1].up   = GOTO_MK_OCTETO1_MOD;
	FuncoesDasTeclas[TELA_PROG_MK_OCTETO1].down = GOTO_MK_OCTETO1_MOD;
	FuncoesDasTeclas[TELA_PROG_MK_OCTETO1].left = GOTO_TELA_ANTERIOR;
	FuncoesDasTeclas[TELA_PROG_MK_OCTETO1].rigth= GOTO_TELA_PROXIMA;
	FuncoesDasTeclas[TELA_PROG_MK_OCTETO1].esc  = SAIR_MODO_PRG_SEM_GRAVAR;
	FuncoesDasTeclas[TELA_PROG_MK_OCTETO1].prog = GOTO_TELA_GRAVAR_SIM_NAO;

	FuncoesDasTeclas[TELA_PROG_MK_OCTETO1_MOD].null = NONE;
	FuncoesDasTeclas[TELA_PROG_MK_OCTETO1_MOD].up   = INCREMENTA_ALGARISMO_BYTE;
	FuncoesDasTeclas[TELA_PROG_MK_OCTETO1_MOD].down = DECREMENTA_ALGARISMO_BYTE;
	FuncoesDasTeclas[TELA_PROG_MK_OCTETO1_MOD].left = GOTO_ALG_ANTERIOR_BYTE;
	FuncoesDasTeclas[TELA_PROG_MK_OCTETO1_MOD].rigth= GOTO_ALG_PROXIMO_BYTE;
	FuncoesDasTeclas[TELA_PROG_MK_OCTETO1_MOD].esc  = ABANDONA_PROG_MK_OCTETO1;
	FuncoesDasTeclas[TELA_PROG_MK_OCTETO1_MOD].prog = GRAVA_PROG_MK_OCTETO1;

	FuncoesDasTeclas[TELA_PROG_MK_OCTETO2].null = NONE;
	FuncoesDasTeclas[TELA_PROG_MK_OCTETO2].up   = GOTO_MK_OCTETO2_MOD;
	FuncoesDasTeclas[TELA_PROG_MK_OCTETO2].down = GOTO_MK_OCTETO2_MOD;
	FuncoesDasTeclas[TELA_PROG_MK_OCTETO2].left = GOTO_TELA_ANTERIOR ;
	FuncoesDasTeclas[TELA_PROG_MK_OCTETO2].rigth= GOTO_TELA_PROXIMA ;
	FuncoesDasTeclas[TELA_PROG_MK_OCTETO2].esc  = SAIR_MODO_PRG_SEM_GRAVAR;
	FuncoesDasTeclas[TELA_PROG_MK_OCTETO2].prog = GOTO_TELA_GRAVAR_SIM_NAO;

	FuncoesDasTeclas[TELA_PROG_MK_OCTETO2_MOD].null = NONE;
	FuncoesDasTeclas[TELA_PROG_MK_OCTETO2_MOD].up   = INCREMENTA_ALGARISMO_BYTE;
	FuncoesDasTeclas[TELA_PROG_MK_OCTETO2_MOD].down = DECREMENTA_ALGARISMO_BYTE;
	FuncoesDasTeclas[TELA_PROG_MK_OCTETO2_MOD].left = GOTO_ALG_ANTERIOR_BYTE;
	FuncoesDasTeclas[TELA_PROG_MK_OCTETO2_MOD].rigth= GOTO_ALG_PROXIMO_BYTE;
	FuncoesDasTeclas[TELA_PROG_MK_OCTETO2_MOD].esc  = ABANDONA_PROG_MK_OCTETO2;
	FuncoesDasTeclas[TELA_PROG_MK_OCTETO2_MOD].prog = GRAVA_PROG_MK_OCTETO2;

	FuncoesDasTeclas[TELA_PROG_MK_OCTETO3].null = NONE;
	FuncoesDasTeclas[TELA_PROG_MK_OCTETO3].up   = GOTO_MK_OCTETO3_MOD;
	FuncoesDasTeclas[TELA_PROG_MK_OCTETO3].down = GOTO_MK_OCTETO3_MOD;
	FuncoesDasTeclas[TELA_PROG_MK_OCTETO3].left = GOTO_TELA_ANTERIOR;
	FuncoesDasTeclas[TELA_PROG_MK_OCTETO3].rigth= GOTO_TELA_PROXIMA;
	FuncoesDasTeclas[TELA_PROG_MK_OCTETO3].esc  = SAIR_MODO_PRG_SEM_GRAVAR;
	FuncoesDasTeclas[TELA_PROG_MK_OCTETO3].prog = GOTO_TELA_GRAVAR_SIM_NAO;

	FuncoesDasTeclas[TELA_PROG_MK_OCTETO3_MOD].null = NONE;
	FuncoesDasTeclas[TELA_PROG_MK_OCTETO3_MOD].up   = INCREMENTA_ALGARISMO_BYTE;
	FuncoesDasTeclas[TELA_PROG_MK_OCTETO3_MOD].down = DECREMENTA_ALGARISMO_BYTE;
	FuncoesDasTeclas[TELA_PROG_MK_OCTETO3_MOD].left = GOTO_ALG_ANTERIOR_BYTE;
	FuncoesDasTeclas[TELA_PROG_MK_OCTETO3_MOD].rigth= GOTO_ALG_PROXIMO_BYTE;
	FuncoesDasTeclas[TELA_PROG_MK_OCTETO3_MOD].esc  = ABANDONA_PROG_MK_OCTETO3;
	FuncoesDasTeclas[TELA_PROG_MK_OCTETO3_MOD].prog = GRAVA_PROG_MK_OCTETO3;

	FuncoesDasTeclas[TELA_PROG_MK_OCTETO4].null = NONE;
	FuncoesDasTeclas[TELA_PROG_MK_OCTETO4].up   = GOTO_MK_OCTETO4_MOD;
	FuncoesDasTeclas[TELA_PROG_MK_OCTETO4].down = GOTO_MK_OCTETO4_MOD;
	FuncoesDasTeclas[TELA_PROG_MK_OCTETO4].left = GOTO_TELA_ANTERIOR;
	FuncoesDasTeclas[TELA_PROG_MK_OCTETO4].rigth= GOTO_TELA_PROXIMA;
	FuncoesDasTeclas[TELA_PROG_MK_OCTETO4].esc  = SAIR_MODO_PRG_SEM_GRAVAR;
	FuncoesDasTeclas[TELA_PROG_MK_OCTETO4].prog = GOTO_TELA_GRAVAR_SIM_NAO;

	FuncoesDasTeclas[TELA_PROG_MK_OCTETO4_MOD].null = NONE;
	FuncoesDasTeclas[TELA_PROG_MK_OCTETO4_MOD].up   = INCREMENTA_ALGARISMO_BYTE;
	FuncoesDasTeclas[TELA_PROG_MK_OCTETO4_MOD].down = DECREMENTA_ALGARISMO_BYTE;
	FuncoesDasTeclas[TELA_PROG_MK_OCTETO4_MOD].left = GOTO_ALG_ANTERIOR_BYTE;
	FuncoesDasTeclas[TELA_PROG_MK_OCTETO4_MOD].rigth= GOTO_ALG_PROXIMO_BYTE;
	FuncoesDasTeclas[TELA_PROG_MK_OCTETO4_MOD].esc  = ABANDONA_PROG_MK_OCTETO4;
	FuncoesDasTeclas[TELA_PROG_MK_OCTETO4_MOD].prog = GRAVA_PROG_MK_OCTETO4;

	FuncoesDasTeclas[TELA_PROG_GW_OCTETO1].null = NONE;
	FuncoesDasTeclas[TELA_PROG_GW_OCTETO1].up   = GOTO_GW_OCTETO1_MOD;
	FuncoesDasTeclas[TELA_PROG_GW_OCTETO1].down = GOTO_GW_OCTETO1_MOD;
	FuncoesDasTeclas[TELA_PROG_GW_OCTETO1].left = GOTO_TELA_ANTERIOR;
	FuncoesDasTeclas[TELA_PROG_GW_OCTETO1].rigth= GOTO_TELA_PROXIMA;
	FuncoesDasTeclas[TELA_PROG_GW_OCTETO1].esc  = SAIR_MODO_PRG_SEM_GRAVAR;
	FuncoesDasTeclas[TELA_PROG_GW_OCTETO1].prog = GOTO_TELA_GRAVAR_SIM_NAO;

	FuncoesDasTeclas[TELA_PROG_GW_OCTETO1_MOD].null = NONE;
	FuncoesDasTeclas[TELA_PROG_GW_OCTETO1_MOD].up   = INCREMENTA_ALGARISMO_BYTE;
	FuncoesDasTeclas[TELA_PROG_GW_OCTETO1_MOD].down = DECREMENTA_ALGARISMO_BYTE;
	FuncoesDasTeclas[TELA_PROG_GW_OCTETO1_MOD].left = GOTO_ALG_ANTERIOR_BYTE;
	FuncoesDasTeclas[TELA_PROG_GW_OCTETO1_MOD].rigth= GOTO_ALG_PROXIMO_BYTE;
	FuncoesDasTeclas[TELA_PROG_GW_OCTETO1_MOD].esc  = ABANDONA_PROG_GW_OCTETO1;
	FuncoesDasTeclas[TELA_PROG_GW_OCTETO1_MOD].prog = GRAVA_PROG_GW_OCTETO1;

	FuncoesDasTeclas[TELA_PROG_GW_OCTETO2].null = NONE;
	FuncoesDasTeclas[TELA_PROG_GW_OCTETO2].up   = GOTO_GW_OCTETO2_MOD;
	FuncoesDasTeclas[TELA_PROG_GW_OCTETO2].down = GOTO_GW_OCTETO2_MOD;
	FuncoesDasTeclas[TELA_PROG_GW_OCTETO2].left = GOTO_TELA_ANTERIOR ;
	FuncoesDasTeclas[TELA_PROG_GW_OCTETO2].rigth= GOTO_TELA_PROXIMA ;
	FuncoesDasTeclas[TELA_PROG_GW_OCTETO2].esc  = SAIR_MODO_PRG_SEM_GRAVAR;
	FuncoesDasTeclas[TELA_PROG_GW_OCTETO2].prog = GOTO_TELA_GRAVAR_SIM_NAO;

	FuncoesDasTeclas[TELA_PROG_GW_OCTETO2_MOD].null = NONE;
	FuncoesDasTeclas[TELA_PROG_GW_OCTETO2_MOD].up   = INCREMENTA_ALGARISMO_BYTE;
	FuncoesDasTeclas[TELA_PROG_GW_OCTETO2_MOD].down = DECREMENTA_ALGARISMO_BYTE;
	FuncoesDasTeclas[TELA_PROG_GW_OCTETO2_MOD].left = GOTO_ALG_ANTERIOR_BYTE;
	FuncoesDasTeclas[TELA_PROG_GW_OCTETO2_MOD].rigth= GOTO_ALG_PROXIMO_BYTE;
	FuncoesDasTeclas[TELA_PROG_GW_OCTETO2_MOD].esc  = ABANDONA_PROG_GW_OCTETO2;
	FuncoesDasTeclas[TELA_PROG_GW_OCTETO2_MOD].prog = GRAVA_PROG_GW_OCTETO2;

	FuncoesDasTeclas[TELA_PROG_GW_OCTETO3].null = NONE;
	FuncoesDasTeclas[TELA_PROG_GW_OCTETO3].up   = GOTO_GW_OCTETO3_MOD;
	FuncoesDasTeclas[TELA_PROG_GW_OCTETO3].down = GOTO_GW_OCTETO3_MOD;
	FuncoesDasTeclas[TELA_PROG_GW_OCTETO3].left = GOTO_TELA_ANTERIOR;
	FuncoesDasTeclas[TELA_PROG_GW_OCTETO3].rigth= GOTO_TELA_PROXIMA;
	FuncoesDasTeclas[TELA_PROG_GW_OCTETO3].esc  = SAIR_MODO_PRG_SEM_GRAVAR;
	FuncoesDasTeclas[TELA_PROG_GW_OCTETO3].prog = GOTO_TELA_GRAVAR_SIM_NAO;

	FuncoesDasTeclas[TELA_PROG_GW_OCTETO3_MOD].null = NONE;
	FuncoesDasTeclas[TELA_PROG_GW_OCTETO3_MOD].up   = INCREMENTA_ALGARISMO_BYTE;
	FuncoesDasTeclas[TELA_PROG_GW_OCTETO3_MOD].down = DECREMENTA_ALGARISMO_BYTE;
	FuncoesDasTeclas[TELA_PROG_GW_OCTETO3_MOD].left = GOTO_ALG_ANTERIOR_BYTE;
	FuncoesDasTeclas[TELA_PROG_GW_OCTETO3_MOD].rigth= GOTO_ALG_PROXIMO_BYTE;
	FuncoesDasTeclas[TELA_PROG_GW_OCTETO3_MOD].esc  = ABANDONA_PROG_GW_OCTETO3;
	FuncoesDasTeclas[TELA_PROG_GW_OCTETO3_MOD].prog = GRAVA_PROG_GW_OCTETO3;

	FuncoesDasTeclas[TELA_PROG_GW_OCTETO4].null = NONE;
	FuncoesDasTeclas[TELA_PROG_GW_OCTETO4].up   = GOTO_GW_OCTETO4_MOD;
	FuncoesDasTeclas[TELA_PROG_GW_OCTETO4].down = GOTO_GW_OCTETO4_MOD;
	FuncoesDasTeclas[TELA_PROG_GW_OCTETO4].left = GOTO_TELA_ANTERIOR;
	FuncoesDasTeclas[TELA_PROG_GW_OCTETO4].rigth= GOTO_TELA_PROXIMA;
	FuncoesDasTeclas[TELA_PROG_GW_OCTETO4].esc  = SAIR_MODO_PRG_SEM_GRAVAR;
	FuncoesDasTeclas[TELA_PROG_GW_OCTETO4].prog = GOTO_TELA_GRAVAR_SIM_NAO;

	FuncoesDasTeclas[TELA_PROG_GW_OCTETO4_MOD].null = NONE;
	FuncoesDasTeclas[TELA_PROG_GW_OCTETO4_MOD].up   = INCREMENTA_ALGARISMO_BYTE;
	FuncoesDasTeclas[TELA_PROG_GW_OCTETO4_MOD].down = DECREMENTA_ALGARISMO_BYTE;
	FuncoesDasTeclas[TELA_PROG_GW_OCTETO4_MOD].left = GOTO_ALG_ANTERIOR_BYTE;
	FuncoesDasTeclas[TELA_PROG_GW_OCTETO4_MOD].rigth= GOTO_ALG_PROXIMO_BYTE;
	FuncoesDasTeclas[TELA_PROG_GW_OCTETO4_MOD].esc  = ABANDONA_PROG_GW_OCTETO4;
	FuncoesDasTeclas[TELA_PROG_GW_OCTETO4_MOD].prog = GRAVA_PROG_GW_OCTETO4;

	FuncoesDasTeclas[TELA_PROG_NRO_PORTA].null = NONE;
	FuncoesDasTeclas[TELA_PROG_NRO_PORTA].up   = GOTO_NRO_PORTA_MOD;
	FuncoesDasTeclas[TELA_PROG_NRO_PORTA].down = GOTO_NRO_PORTA_MOD;
	FuncoesDasTeclas[TELA_PROG_NRO_PORTA].left = GOTO_TELA_ANTERIOR;
	FuncoesDasTeclas[TELA_PROG_NRO_PORTA].rigth= GOTO_TELA_PROXIMA;
	FuncoesDasTeclas[TELA_PROG_NRO_PORTA].esc  = SAIR_MODO_PRG_SEM_GRAVAR;
	FuncoesDasTeclas[TELA_PROG_NRO_PORTA].prog = GOTO_TELA_GRAVAR_SIM_NAO;

	FuncoesDasTeclas[TELA_PROG_NRO_PORTA_MOD].null = NONE;
	FuncoesDasTeclas[TELA_PROG_NRO_PORTA_MOD].up   = INCREMENTA_ALGARISMO_INT;
	FuncoesDasTeclas[TELA_PROG_NRO_PORTA_MOD].down = DECREMENTA_ALGARISMO_INT;
	FuncoesDasTeclas[TELA_PROG_NRO_PORTA_MOD].left = GOTO_ALG_ANTERIOR_INT;
	FuncoesDasTeclas[TELA_PROG_NRO_PORTA_MOD].rigth= GOTO_ALG_PROXIMO_INT;
	FuncoesDasTeclas[TELA_PROG_NRO_PORTA_MOD].esc  = ABANDONA_PROG_NRO_PORTA;
	FuncoesDasTeclas[TELA_PROG_NRO_PORTA_MOD].prog = GRAVA_PROG_NRO_PORTA;
	//#endif

	FuncoesDasTeclas[TELA_PROG_GRAVAR_SIM_NAO_MOD].null = NONE;
	FuncoesDasTeclas[TELA_PROG_GRAVAR_SIM_NAO_MOD].up   = ALTERA_SIM_NAO_G;
	FuncoesDasTeclas[TELA_PROG_GRAVAR_SIM_NAO_MOD].down = ALTERA_SIM_NAO_G;
	FuncoesDasTeclas[TELA_PROG_GRAVAR_SIM_NAO_MOD].left = ALTERA_SIM_NAO_G;
	FuncoesDasTeclas[TELA_PROG_GRAVAR_SIM_NAO_MOD].rigth= ALTERA_SIM_NAO_G;
	FuncoesDasTeclas[TELA_PROG_GRAVAR_SIM_NAO_MOD].esc  = VOLTA_AO_MODO_PROGRAMACAO; //SAIR_MODO_PRG_SEM_GRAVAR;
	FuncoesDasTeclas[TELA_PROG_GRAVAR_SIM_NAO_MOD].prog = SAIR_MODO_PRG_POSSIVELMENTE_GRAVANDO;

	inicializa_funcao_teclas(TELA_APRESENTACAO);
	ultimaTeclaExecutada = ~teclaAtual;
};
/*
   Executa a funcao passada como parametro
 */
void executaFuncao(int funcao){

	setDpyPiscante(NENHUM_PISCANDO,NENHUM_PISCANDO);

	switch (funcao){

		case GOTO_ESCRAVO_MODBUS_MOD:
			{
				setDpyPiscante(UNIDADE,UNIDADE);
				currentAlgarismo=UNIDADE;
				InttoBCD((unsigned short)MeuEnderecoMODBUS_temp,&tempMil,&tempCen,&tempDez,&tempUni);
				telaAtual=TELA_PROG_ESCRAVO_MODBUS_MOD;
				break;
			}

		case GOTO_BAUD_RATE_MOD:
			{
				setDpyPiscante(8,11);
				telaAtual=TELA_PROG_BAUD_RATE_MOD;
				break;
			}

		case GOTO_PARIDADE_STOPS_MOD:
			{
				setDpyPiscante(8,11);
				telaAtual=TELA_PROG_PARIDADE_STOPS_MOD;
				break;
			}

		case GOTO_IP_OCTETO1_MOD:
			{
				setDpyPiscante(UNIDADE,UNIDADE);
				currentAlgarismo=UNIDADE;
				InttoBCD((unsigned short)IPOcteto1_temp,&tempMil,&tempCen,&tempDez,&tempUni);
				telaAtual=TELA_PROG_IP_OCTETO1_MOD;
				break;
			}
		case GOTO_IP_OCTETO2_MOD:
			{
				setDpyPiscante(UNIDADE,UNIDADE);
				currentAlgarismo=UNIDADE;
				InttoBCD((unsigned short)IPOcteto2_temp,&tempMil,&tempCen,&tempDez,&tempUni);
				telaAtual=TELA_PROG_IP_OCTETO2_MOD;
				break;
			}
		case GOTO_IP_OCTETO3_MOD:
			{
				setDpyPiscante(UNIDADE,UNIDADE);
				currentAlgarismo=UNIDADE;
				InttoBCD((unsigned short)IPOcteto3_temp,&tempMil,&tempCen,&tempDez,&tempUni);
				telaAtual=TELA_PROG_IP_OCTETO3_MOD;
				break;
			}
		case GOTO_IP_OCTETO4_MOD:
			{
				setDpyPiscante(UNIDADE,UNIDADE);
				currentAlgarismo=UNIDADE;
				InttoBCD((unsigned short)IPOcteto4_temp,&tempMil,&tempCen,&tempDez,&tempUni);
				telaAtual=TELA_PROG_IP_OCTETO4_MOD;
				break;
			}
		case GOTO_MK_OCTETO1_MOD:
			{
				setDpyPiscante(UNIDADE,UNIDADE);
				currentAlgarismo=UNIDADE;
				InttoBCD((unsigned short)MKOcteto1_temp,&tempMil,&tempCen,&tempDez,&tempUni);
				telaAtual=TELA_PROG_MK_OCTETO1_MOD;
				break;
			}
		case GOTO_MK_OCTETO2_MOD:
			{
				setDpyPiscante(UNIDADE,UNIDADE);
				currentAlgarismo=UNIDADE;
				InttoBCD((unsigned short)MKOcteto2_temp,&tempMil,&tempCen,&tempDez,&tempUni);
				telaAtual=TELA_PROG_MK_OCTETO2_MOD;
				break;
			}
		case GOTO_MK_OCTETO3_MOD:
			{
				setDpyPiscante(UNIDADE,UNIDADE);
				currentAlgarismo=UNIDADE;
				InttoBCD((unsigned short)MKOcteto3_temp,&tempMil,&tempCen,&tempDez,&tempUni);
				telaAtual=TELA_PROG_MK_OCTETO3_MOD;
				break;
			}
		case GOTO_MK_OCTETO4_MOD:
			{
				setDpyPiscante(UNIDADE,UNIDADE);
				currentAlgarismo=UNIDADE;
				InttoBCD((unsigned short)MKOcteto4_temp,&tempMil,&tempCen,&tempDez,&tempUni);
				telaAtual=TELA_PROG_MK_OCTETO4_MOD;
				break;
			}
		case GOTO_GW_OCTETO1_MOD:
			{
				setDpyPiscante(UNIDADE,UNIDADE);
				currentAlgarismo=UNIDADE;
				InttoBCD((unsigned short)GWOcteto1_temp,&tempMil,&tempCen,&tempDez,&tempUni);
				telaAtual=TELA_PROG_GW_OCTETO1_MOD;
				break;
			}
		case GOTO_GW_OCTETO2_MOD:
			{
				setDpyPiscante(UNIDADE,UNIDADE);
				currentAlgarismo=UNIDADE;
				InttoBCD((unsigned short)GWOcteto2_temp,&tempMil,&tempCen,&tempDez,&tempUni);
				telaAtual=TELA_PROG_GW_OCTETO2_MOD;
				break;
			}
		case GOTO_GW_OCTETO3_MOD:
			{
				setDpyPiscante(UNIDADE,UNIDADE);
				currentAlgarismo=UNIDADE;
				InttoBCD((unsigned short)GWOcteto3_temp,&tempMil,&tempCen,&tempDez,&tempUni);
				telaAtual=TELA_PROG_GW_OCTETO3_MOD;
				break;
			}
		case GOTO_GW_OCTETO4_MOD:
			{
				setDpyPiscante(UNIDADE,UNIDADE);
				currentAlgarismo=UNIDADE;
				InttoBCD((unsigned short)GWOcteto4_temp,&tempMil,&tempCen,&tempDez,&tempUni);
				telaAtual=TELA_PROG_GW_OCTETO4_MOD;
				break;
			}
		case GOTO_NRO_PORTA_MOD:
			{
				setDpyPiscante(UNIDADE,UNIDADE);
				currentAlgarismo=UNIDADE;
				InttoBCD((unsigned short)NroPorta_temp,&tempMil,&tempCen,&tempDez,&tempUni);
				telaAtual=TELA_PROG_NRO_PORTA_MOD;
				break;
			}

		case GOTO_TELA_GRAVAR_SIM_NAO:
			telaAtual=TELA_PROG_GRAVAR_SIM_NAO_MOD;
		case ALTERA_SIM_NAO_G:
			{
				if (SairGravando=='S') {SairGravando='n';} else{SairGravando='S';}
				break;
			}

		case GOTO_RESET_CONSUMO_MOD:
		case ALTERA_SIM_NAO:
			{
				if (zeraConsumos=='S') {zeraConsumos='n';} else{zeraConsumos='S';}
				telaAtual=TELA_PROG_RESET_CONSUMO_MOD;
				break;
			}
		case GOTO_TELA_PROXIMA:
			{
				proximaTela(tela2); break;
			}
		case GOTO_TELA_ANTERIOR:
			{
				proximaTela(tela1); break;
			}
		case ENTRA_MODO_PRG:
			{
				estou_no_modo_de_programacao=SIM;
				relacaoTPpri_temp=relacaoTPpri;
				relacaoTPsec_temp=relacaoTPsec;
				relacaoTPfat_temp=relacaoTPfat;
				relacaoTCpri_temp=relacaoTCpri;
				relacaoTCsec_temp=relacaoTCsec;
				relacaoTCfat_temp=relacaoTCfat;
				MeuEnderecoMODBUS_temp=MeuEnderecoMODBUS;
				BaudRate_temp=BaudRatex;
				ParidadeStops_temp=ParidadeStops;
				IPOcteto1_temp=IPOcteto1;
				IPOcteto2_temp=IPOcteto2;
				IPOcteto3_temp=IPOcteto3;
				IPOcteto4_temp=IPOcteto4;
				MKOcteto1_temp=MKOcteto1;
				MKOcteto2_temp=MKOcteto2;
				MKOcteto3_temp=MKOcteto3;
				MKOcteto4_temp=MKOcteto4;
				GWOcteto1_temp=GWOcteto1;
				GWOcteto2_temp=GWOcteto2;
				GWOcteto3_temp=GWOcteto3;
				GWOcteto4_temp=GWOcteto4;
				NroPorta_temp=NroPorta;
				zeraConsumos='n';
				SairGravando='n';
				telaAtual=INICIO_TELAS_DE_PROGRAMACAO;
				InttoBCD(relacaoTPpri_temp,&tempMil,&tempCen,&tempDez,&tempUni);

				break;
			}
		case SAIR_MODO_PRG_SEM_GRAVAR:
			{
				estou_no_modo_de_programacao=NAO;
				telaAtual=INICIO_TELAS_DE_EXIBICAO;
				tela1=FIM_TELAS_DE_EXIBICAO;
				tela2=INICIO_TELAS_DE_EXIBICAO;
				break;
			}

		case VOLTA_AO_MODO_PROGRAMACAO:
			{
				telaAtual=INICIO_TELAS_DE_PROGRAMACAO;
				break;
			}

		case SAIR_MODO_PRG_POSSIVELMENTE_GRAVANDO:
			{
				estou_no_modo_de_programacao=NAO;
				if (SairGravando=='S')
				{
					relacaoTPpri=relacaoTPpri_temp;
					relacaoTPsec=relacaoTPsec_temp;
					relacaoTPfat=relacaoTPfat_temp;
					relacaoTCpri=relacaoTCpri_temp;
					relacaoTCsec=relacaoTCsec_temp;
					relacaoTCfat=relacaoTCfat_temp;
					MeuEnderecoMODBUS=MeuEnderecoMODBUS_temp;
					ParidadeStops=ParidadeStops_temp;
					BaudRatex=BaudRate_temp;
					IPOcteto1=IPOcteto1_temp;
					IPOcteto2=IPOcteto2_temp;
					IPOcteto3=IPOcteto3_temp;
					IPOcteto4=IPOcteto4_temp;
					MKOcteto1=MKOcteto1_temp;
					MKOcteto2=MKOcteto2_temp;
					MKOcteto3=MKOcteto3_temp;
					MKOcteto4=MKOcteto4_temp;
					GWOcteto1=GWOcteto1_temp;
					GWOcteto2=GWOcteto2_temp;
					GWOcteto3=GWOcteto3_temp;
					GWOcteto4=GWOcteto4_temp;
					NroPorta=NroPorta_temp;
					/*
					   IPOcteto1=ip_config.IpAdr[0]  ;           // Local IP Address
					   IPOcteto2=ip_config.IpAdr[1]  ;           // Local IP Address
					   IPOcteto3=ip_config.IpAdr[2]  ;           // Local IP Address
					   IPOcteto4=ip_config.IpAdr[3 ] ;           // Local IP Address
					   GWOcteto1=ip_config.DefGW[0 ] ;           // Default GateWay
					   GWOcteto2=ip_config.DefGW[1]  ;           // Default GateWay
					   GWOcteto3=ip_config.DefGW[2]  ;           // Default GateWay
					   GWOcteto4=ip_config.DefGW[3]  ;           // Default GateWay
					   MKOcteto1=ip_config.NetMask[0];         // Net Mask
					   MKOcteto2=ip_config.NetMask[1];         // Net Mask
					   MKOcteto3=ip_config.NetMask[2];         // Net Mask
					   MKOcteto4=ip_config.NetMask[3];         // Net Mask */

					ip_config.IpAdr[0]  =(U8)IPOcteto1;           // Local IP Address
					ip_config.IpAdr[1]  =(U8)IPOcteto2;           // Local IP Address
					ip_config.IpAdr[2]  =(U8)IPOcteto3;           // Local IP Address
					ip_config.IpAdr[3]  =(U8)IPOcteto4;           // Local IP Address
					ip_config.DefGW[0]  =(U8)GWOcteto1;           // Default GateWay
					ip_config.DefGW[1]  =(U8)GWOcteto2;           // Default GateWay
					ip_config.DefGW[2]  =(U8)GWOcteto3;           // Default GateWay
					ip_config.DefGW[3]  =(U8)GWOcteto4;           // Default GateWay
					ip_config.NetMask[0]=(U8)MKOcteto1;         // Net Mask
					ip_config.NetMask[1]=(U8)MKOcteto2;         // Net Mask
					ip_config.NetMask[2]=(U8)MKOcteto3;         // Net Mask
					ip_config.NetMask[3]=(U8)MKOcteto4;         // Net Mask
					ip_config.PriDNS[0] =10;          // Primary DNS Server
					ip_config.PriDNS[1] =10;          // Primary DNS Server
					ip_config.PriDNS[2] =0;          // Primary DNS Server
					ip_config.PriDNS[3] =1;          // Primary DNS Server
					ip_config.SecDNS[0] =10;         // Secondary DNS Server
					ip_config.SecDNS[1] =10;         // Secondary DNS Server
					ip_config.SecDNS[2] =0;          // Secondary DNS Server
					ip_config.SecDNS[3] =1;          // Secondary DNS Server

					refresh_ip();

					UARTInit(BaudRatex,ParidadeStops);
					SalvaParametrizacao();
				}

				telaAtual=INICIO_TELAS_DE_EXIBICAO;
				tela1=FIM_TELAS_DE_EXIBICAO;
				tela2=INICIO_TELAS_DE_EXIBICAO;

				break;
			}
		case GOTO_REL_TP_PRI_MOD:
			{
				setDpyPiscante(UNIDADE,UNIDADE);
				currentAlgarismo=UNIDADE;
				InttoBCD(relacaoTPpri_temp,&tempMil,&tempCen,&tempDez,&tempUni);
				telaAtual=TELA_PROG_REL_TP_PRI_MOD;
				break;
			}
		case GOTO_REL_TP_SEC_MOD:
			{
				setDpyPiscante(UNIDADE,UNIDADE);
				currentAlgarismo=UNIDADE;
				InttoBCD(relacaoTPsec_temp,&tempMil,&tempCen,&tempDez,&tempUni);
				telaAtual=TELA_PROG_REL_TP_SEC_MOD;
				break;
			}

		case GOTO_REL_TP_FAT_MOD:
			{
				setDpyPiscante(UNIDADE,UNIDADE);
				currentAlgarismo=UNIDADE;
				InttoBCD(relacaoTPfat_temp,&tempMil,&tempCen,&tempDez,&tempUni);
				telaAtual=TELA_PROG_REL_TP_FAT_MOD;
				break;
			}
		case GOTO_REL_TC_PRI_MOD:
			{

				setDpyPiscante(UNIDADE,UNIDADE);
				currentAlgarismo=UNIDADE;
				InttoBCD(relacaoTCpri_temp,&tempMil,&tempCen,&tempDez,&tempUni);
				telaAtual=TELA_PROG_REL_TC_PRI_MOD;
				break;
			}
		case GOTO_REL_TC_SEC_MOD:
			{
				setDpyPiscante(UNIDADE,UNIDADE);
				currentAlgarismo=UNIDADE;
				InttoBCD(relacaoTCsec_temp,&tempMil,&tempCen,&tempDez,&tempUni);
				telaAtual=TELA_PROG_REL_TC_SEC_MOD;
				break;
			}

		case GOTO_REL_TC_FAT_MOD:
			{
				setDpyPiscante(UNIDADE,UNIDADE);
				currentAlgarismo=UNIDADE;
				InttoBCD(relacaoTCfat_temp,&tempMil,&tempCen,&tempDez,&tempUni);
				telaAtual=TELA_PROG_REL_TC_FAT_MOD;
				break;
			}


		case INCREMENTA_ALGARISMO_INT:
			{
				//incrementa o algarismo atual (current)
				switch(currentAlgarismo)
				{
					case UNIDADE://unidade
						{
							if (tempUni<9){tempUni++;} else { tempUni=0; }
							break;
						}
					case DEZENA://dezena
						{
							if (tempDez<9){tempDez++;} else { tempDez=0; }
							break;
						}
					case CENTENA://centena
						{
							if (tempCen<9){tempCen++;} else { tempCen=0; }
							break;
						}
					case MILHAR://milhar
						{
							if (tempMil<9){tempMil++;} else { tempMil=0; }
							break;
						}
				}
				break;
			}
		case DECREMENTA_ALGARISMO_INT:
			{
				//decrementa o algarismo atual (current)
				switch(currentAlgarismo)
				{
					case UNIDADE://unidade
						{
							if (tempUni==0){tempUni=9;} else { tempUni--; }
							break;
						}
					case DEZENA://dezena
						{
							if (tempDez==0){tempDez=9;} else { tempDez--; }
							break;
						}
					case CENTENA://centena
						{
							if (tempCen==0){tempCen=9;} else { tempCen--; }
							break;
						}
					case MILHAR://milhar
						{
							if (tempMil==0){tempMil=9;} else { tempMil--; }
							break;
						}
				}
				break;
			}
		case GOTO_ALG_PROXIMO_INT:
			{
				//muda para o algarismo proximo, current+1
				currentAlgarismo++; if (currentAlgarismo>UNIDADE) {currentAlgarismo=MILHAR;}
				break;
			}
		case GOTO_ALG_ANTERIOR_INT:
			{
				//muda para o algarismo anterior, current-1
				currentAlgarismo--; if (currentAlgarismo<MILHAR) {currentAlgarismo=UNIDADE;}
				break;
			}

		case INCREMENTA_ALGARISMO_BYTE:
			{
				//incrementa o algarismo atual (current)
				switch(currentAlgarismo)
				{
					case UNIDADE://unidade
						{

							if (tempCen==2)
							{
								if (tempDez==5)
								{
									if (tempUni<5){tempUni++;} else { tempUni=0; }
								}
								else
								{
									if (tempUni<9){tempUni++;} else { tempUni=0; }
								}
							}
							else
							{
								if (tempUni<9){tempUni++;} else { tempUni=0; }
							}

							break;
						}
					case DEZENA://dezena
						{


							if (tempCen==2)
							{
								if (tempDez<5){
									tempDez++;
								}
								if (tempDez==5){
									if (tempUni>5){ tempUni=5; }
								}
							}
							else
							{
								if (tempDez<9){tempDez++;} else { tempDez=0; }
							}

							break;
						}
					case CENTENA://centena
						{

							if (tempCen==2){
								tempCen=0;
							}
							else
							{
								tempCen++;
								if (tempCen==2)
								{
									if (tempDez>=5)
									{
										tempDez=5;
										if (tempUni>5) { tempUni=5; }
									}
								}
							}
							break;
						}
				}//fim do switch currentAlgarismo
				break;
			}
		case DECREMENTA_ALGARISMO_BYTE:
			{
				//decrementa o algarismo atual (current)
				switch(currentAlgarismo)
				{
					case UNIDADE://unidade
						{

							if (tempCen==2)
							{
								if (tempDez==5){
									if (tempUni==0){tempUni=5;} else { tempUni--; }
								}
								else { if (tempUni==0){tempUni=9;} else { tempUni--; }}
							}
							else
							{
								if (tempUni==0){tempUni=9;} else { tempUni--; }
							}

							break;
						}
					case DEZENA://dezena
						{


							if (tempCen==2)
							{
								if (tempDez==0){tempDez=5;
									if (tempUni>5){tempUni=5;}
								} else { tempDez--; }
							}
							else
							{
								if (tempDez==0){tempDez=9;} else { tempDez--; }
							}

							break;
						}
					case CENTENA://centena
						{

							if (tempCen==0)
							{
								tempCen=2;
								if (tempDez>5) {tempDez=5;}
								if (tempDez==5)
								{
									if (tempUni>5) {tempUni=5;}
								}
							}
							else { tempCen--; }


							break;
						}
				}
				break;
			}
		case GOTO_ALG_PROXIMO_BYTE:
			{
				//muda para o algarismo proximo, current+1
				currentAlgarismo++; if (currentAlgarismo>UNIDADE) {currentAlgarismo=CENTENA;}
				break;
			}
		case GOTO_ALG_ANTERIOR_BYTE:
			{
				//muda para o algarismo anterior, current-1
				currentAlgarismo--; if (currentAlgarismo<CENTENA) {currentAlgarismo=UNIDADE;}
				break;
			}

		case NONE:
			{
				break;
			}

		case DECREMENTA_BAUD_RATE:
			{
				BaudRate_temp=BaudRate_temp-1;
				if (BaudRate_temp==0xFF){BaudRate_temp=BR115200;}
				break;
			}
		case INCREMENTA_BAUD_RATE:
			{
				BaudRate_temp=BaudRate_temp+1;
				if (BaudRate_temp>BR115200){BaudRate_temp=BR4800;}
				break;
			}
		case DECREMENTA_PARIDADE_STOPS:
			{
				ParidadeStops_temp=ParidadeStops_temp-1;
				if (ParidadeStops_temp==0xFF){ParidadeStops_temp=ps8E1;}
				break;
			}
		case INCREMENTA_PARIDADE_STOPS:
			{
				ParidadeStops_temp=ParidadeStops_temp+1;
				if (ParidadeStops_temp>ps8E1){ParidadeStops_temp=ps8N2;}
				break;
			}

		case ABANDONA_PROG_RESET_CONSUMO:
			{
				zeraConsumos='n';
				telaAtual=TELA_PROG_RESET_CONSUMO;
				break;
			}

		case ABANDONA_PROG_ESCRAVO_MODBUS :
			{
				telaAtual=TELA_PROG_ESCRAVO_MODBUS;
				break;
			}

		case ABANDONA_PROG_BAUD_RATE:
			{
				BaudRate_temp=BaudRatex;
				telaAtual=TELA_PROG_BAUD_RATE;
				break;
			}
		case ABANDONA_PROG_NRO_PORTA:
			{
				NroPorta_temp=NroPorta;
				telaAtual=TELA_PROG_NRO_PORTA;
				break;
			}
		case GRAVA_PROG_NRO_PORTA :
			{
				NroPorta_temp=BCDtoInt(tempMil,tempCen,tempDez,tempUni);
				telaAtual=TELA_PROG_NRO_PORTA;
				break;
			}
		case GRAVA_PROG_BAUD_RATE :
			{
				telaAtual=TELA_PROG_BAUD_RATE;
				break;
			}

		case GRAVA_PROG_ESCRAVO_MODBUS :
			{
				MeuEnderecoMODBUS_temp=(BYTE)BCDtoInt(0,tempCen,tempDez,tempUni);
				telaAtual=TELA_PROG_ESCRAVO_MODBUS;
				break;
			}

		case GRAVA_PROG_RESET_CONSUMO:
			{
				telaAtual=TELA_PROG_RESET_CONSUMO;
				break;
			}

		case ABANDONA_PROG_REL_TP_PRI:
			{
				telaAtual=TELA_PROG_REL_TP_PRI;
				break;
			}
		case ABANDONA_PROG_REL_TP_SEC:
			{
				telaAtual=TELA_PROG_REL_TP_SEC;
				break;
			}
		case ABANDONA_PROG_REL_TP_FAT:
			{
				telaAtual=TELA_PROG_REL_TP_FAT;
				break;
			}

		case ABANDONA_PROG_REL_TC_PRI:
			{
				telaAtual=TELA_PROG_REL_TC_PRI;
				break;
			}
		case ABANDONA_PROG_REL_TC_SEC:
			{
				telaAtual=TELA_PROG_REL_TC_SEC;
				break;
			}
		case ABANDONA_PROG_REL_TC_FAT:
			{
				telaAtual=TELA_PROG_REL_TC_FAT;
				break;
			}
		case ABANDONA_PROG_PARIDADE_STOPS:
			{
				telaAtual=TELA_PROG_PARIDADE_STOPS;
				ParidadeStops_temp=ParidadeStops;
				break;
			}
		case ABANDONA_PROG_IP_OCTETO1:
			{
				telaAtual=TELA_PROG_IP_OCTETO1;
				IPOcteto1_temp=IPOcteto1;
				break;
			}
		case ABANDONA_PROG_IP_OCTETO2:
			{
				telaAtual=TELA_PROG_IP_OCTETO2;
				IPOcteto2_temp=IPOcteto2;
				break;
			}
		case ABANDONA_PROG_IP_OCTETO3:
			{
				telaAtual=TELA_PROG_IP_OCTETO3;
				IPOcteto3_temp=IPOcteto3;
				break;
			}
		case ABANDONA_PROG_IP_OCTETO4:
			{
				telaAtual=TELA_PROG_IP_OCTETO4;
				IPOcteto4_temp=IPOcteto4;
				break;
			}
		case ABANDONA_PROG_GW_OCTETO1:
			{
				telaAtual=TELA_PROG_GW_OCTETO1;
				GWOcteto1_temp=GWOcteto1;
				break;
			}
		case ABANDONA_PROG_GW_OCTETO2:
			{
				telaAtual=TELA_PROG_GW_OCTETO2;
				GWOcteto2_temp=GWOcteto2;
				break;
			}
		case ABANDONA_PROG_GW_OCTETO3:
			{
				telaAtual=TELA_PROG_GW_OCTETO3;
				GWOcteto3_temp=GWOcteto3;
				break;
			}
		case ABANDONA_PROG_GW_OCTETO4:
			{
				telaAtual=TELA_PROG_GW_OCTETO4;
				GWOcteto4_temp=GWOcteto4;
				break;
			}
		case ABANDONA_PROG_MK_OCTETO1:
			{
				telaAtual=TELA_PROG_MK_OCTETO1;
				MKOcteto1_temp=MKOcteto1;
				break;
			}
		case ABANDONA_PROG_MK_OCTETO2:
			{
				telaAtual=TELA_PROG_MK_OCTETO2;
				MKOcteto2_temp=MKOcteto2;
				break;
			}
		case ABANDONA_PROG_MK_OCTETO3:
			{
				telaAtual=TELA_PROG_MK_OCTETO3;
				MKOcteto3_temp=MKOcteto3;
				break;
			}
		case ABANDONA_PROG_MK_OCTETO4:
			{
				telaAtual=TELA_PROG_MK_OCTETO4;
				MKOcteto4_temp=MKOcteto4;
				break;
			}

		case GRAVA_PROG_IP_OCTETO4:
			{
				IPOcteto4_temp=(BYTE)BCDtoInt(0,tempCen,tempDez,tempUni);
				telaAtual=TELA_PROG_IP_OCTETO4;
				break;
			}

		case GRAVA_PROG_IP_OCTETO3:
			{
				IPOcteto3_temp=(BYTE)BCDtoInt(0,tempCen,tempDez,tempUni);
				telaAtual=TELA_PROG_IP_OCTETO3;
				break;
			}

		case GRAVA_PROG_IP_OCTETO2:
			{
				IPOcteto2_temp=(BYTE)BCDtoInt(0,tempCen,tempDez,tempUni);
				telaAtual=TELA_PROG_IP_OCTETO2;
				break;
			}

		case GRAVA_PROG_IP_OCTETO1:
			{
				IPOcteto1_temp=(BYTE)BCDtoInt(0,tempCen,tempDez,tempUni);
				telaAtual=TELA_PROG_IP_OCTETO1;
				break;
			}
		case GRAVA_PROG_MK_OCTETO4:
			{
				MKOcteto4_temp=(BYTE)BCDtoInt(0,tempCen,tempDez,tempUni);
				telaAtual=TELA_PROG_MK_OCTETO4;
				break;
			}

		case GRAVA_PROG_MK_OCTETO3:
			{
				MKOcteto3_temp=(BYTE)BCDtoInt(0,tempCen,tempDez,tempUni);
				telaAtual=TELA_PROG_MK_OCTETO3;
				break;
			}

		case GRAVA_PROG_MK_OCTETO2:
			{
				MKOcteto2_temp=(BYTE)BCDtoInt(0,tempCen,tempDez,tempUni);
				telaAtual=TELA_PROG_MK_OCTETO2;
				break;
			}

		case GRAVA_PROG_MK_OCTETO1:
			{
				MKOcteto1_temp=(BYTE)BCDtoInt(0,tempCen,tempDez,tempUni);
				telaAtual=TELA_PROG_MK_OCTETO1;
				break;
			}
		case GRAVA_PROG_GW_OCTETO4:
			{
				GWOcteto4_temp=(BYTE)BCDtoInt(0,tempCen,tempDez,tempUni);
				telaAtual=TELA_PROG_GW_OCTETO4;
				break;
			}
		case GRAVA_PROG_GW_OCTETO3:
			{
				GWOcteto3_temp=(BYTE)BCDtoInt(0,tempCen,tempDez,tempUni);
				telaAtual=TELA_PROG_GW_OCTETO3;
				break;
			}

		case GRAVA_PROG_GW_OCTETO2:
			{
				GWOcteto2_temp=(BYTE)BCDtoInt(0,tempCen,tempDez,tempUni);
				telaAtual=TELA_PROG_GW_OCTETO2;
				break;
			}

		case GRAVA_PROG_GW_OCTETO1:
			{
				GWOcteto1_temp=(BYTE)BCDtoInt(0,tempCen,tempDez,tempUni);
				telaAtual=TELA_PROG_GW_OCTETO1;
				break;
			}

		case GRAVA_PROG_PARIDADE_STOPS:
			{
				telaAtual=TELA_PROG_PARIDADE_STOPS;
				break;
			}
		case GRAVA_PROG_REL_TP_PRI:
			{
				relacaoTPpri_temp=BCDtoInt(tempMil,tempCen,tempDez,tempUni);
				telaAtual=TELA_PROG_REL_TP_PRI;
				break;
			}
		case GRAVA_PROG_REL_TP_SEC:
			{
				relacaoTPsec_temp=BCDtoInt(tempMil,tempCen,tempDez,tempUni);
				telaAtual=TELA_PROG_REL_TP_SEC;
				break;
			}
		case GRAVA_PROG_REL_TP_FAT:
			{
				relacaoTPfat_temp=BCDtoInt(tempMil,tempCen,tempDez,tempUni);
				telaAtual=TELA_PROG_REL_TP_FAT;
				break;
			}
		case GRAVA_PROG_REL_TC_PRI:
			{
				relacaoTCpri_temp=BCDtoInt(tempMil,tempCen,tempDez,tempUni);
				telaAtual=TELA_PROG_REL_TC_PRI;
				break;
			}
		case GRAVA_PROG_REL_TC_SEC:
			{
				relacaoTCsec_temp=BCDtoInt(tempMil,tempCen,tempDez,tempUni);
				telaAtual=TELA_PROG_REL_TC_SEC;
				break;
			}
		case GRAVA_PROG_REL_TC_FAT:
			{
				relacaoTCfat_temp=BCDtoInt(tempMil,tempCen,tempDez,tempUni);
				telaAtual=TELA_PROG_REL_TC_FAT;
				break;
			}
		default:
			{
				telaAtual=funcao&0x7F;	 //util no modo de programa��o
				break;
			}

	}/* final do switch */

	ultimaFuncaoChamada=funcao;
}

/*
   Gerencia a exibicao das telas do equipamento
   Qdo se 'entra' em uma nova tela,
   ajustam-se as 'condicoes iniciais'
 */
void gerenciaTelas(void){
	char str[12];
	char *pstr;
	int FlagKilo,FlagMenos;
	//RTCTime LocalTime;
	//int *p;

	if(ultimaTelaExibida != telaAtual) inicializaTela(telaAtual);
	/*
	   Efetivamente atualiza condicoes din�micas da
	   tela (valores como medicoes, entradas
	   de usuario, etc. )
	 */

	switch(telaAtual)
	{
		//telas de exibi��o:
		case TELA_APRESENTACAO:
			{
				FloatToStr(Versao,&str[1],&FlagKilo,&FlagMenos);
				str[0]=' ';
				pstr=&str[0];
				WriteString(dpyLINHA3,pstr);
				break;
			}

		case TELA_TENSOES_ABC:
			{
				//p=SETOR_PARAMETRIZACAO_INICIO;
				setLED(LED_Volt);
				/*
				   UrmsA=(float)RTCGetTime().RTC_Year;
				   UrmsB=(float)RTCGetTime().RTC_Min;
				   UrmsC=(float)RTCGetTime().RTC_Hour;	*/

				TelaValoresTrifasicos(UrmsA,UrmsB,UrmsC);	break;
				//	TelaValoresTrifasicos(UrmsA,UrmsB,(float)(*p));	break;

				//		TelaValoresTrifasicos(UrmsA,UrmsAfund,DhtUA);	break;

			}

		case TELA_CORRENTES_ABC:
			{
				setLED(LED_Amp);
				TelaValoresTrifasicos(IrmsA,IrmsB,IrmsC);	break;
				//		TelaValoresTrifasicos(IrmsB,IrmsBfund,DhtIB);	break;
				//			TelaValoresTrifasicos(UrmsAfund,UrmsBfund,UrmsCfund);	break;
			}

		case TELA_FATORES_DE_POT_ABC:
			{
				setLED(LED_Fp);
				TelaValoresTrifasicos(FatPotA,FatPotB,FatPotC);	break;
			}

		case TELA_POT_ATIVA_ABC:
			{
				setLED(LED_Watt);
				TelaValoresTrifasicos(PotAtivA,PotAtivB,PotAtivC);	break;
			}

		case TELA_POT_REATIVA_ABC:
			{
				setLED(LED_Var);
				TelaValoresTrifasicos(PotReatA,PotReatB,PotReatC);	break;
			}

		case TELA_POT_APARENTE_ABC:
			{
				setLED(LED_Va);
				TelaValoresTrifasicos(PotAparA,PotAparB,PotAparC);	break;
			}

		case TELA_DHTU_ABC:
			{
				setLED(LED_DhtU);
				TelaValoresTrifasicos(DhtUA,DhtUB,DhtUC);	break;
			}

		case TELA_DHTI_ABC:
			{
				setLED(LED_DhtI);
				TelaValoresTrifasicos(DhtIA,DhtIB,DhtIC);	break;
			}

		case TELA_FREQ:
			{
				setLED(LED_Freq);
				setLED(LED_FaseA);
				WriteString(dpyLINHA2,"        ");
				WriteFloatString(FreqA,dpyLINHA1);
				break;
			}
		case TELA_FP_KW_KVAR:
			{
				setLED(LED_Trif);
				setLED(LED_Watt);
				setLED(LED_Var);
				setLED(LED_Fp);
				WriteFloatString(FatPotT,dpyLINHA1);
				WriteFloatString(PotAtivT,dpyLINHA2);
				WriteFloatString(PotReatT,dpyLINHA3);

				break;
			}

		case TELA_U_I_FP_A:
			{
				setLED(LED_FaseA);
				setLED(LED_Volt);
				setLED(LED_Amp);
				setLED(LED_Fp);
				WriteFloatString(UrmsA,dpyLINHA1);
				WriteFloatString(IrmsA,dpyLINHA2);
				WriteFloatString(FatPotA,dpyLINHA3);
				break;
			}
		case TELA_U_I_FP_B:
			{
				setLED(LED_FaseB);
				setLED(LED_Volt);
				setLED(LED_Amp);
				setLED(LED_Fp);
				WriteFloatString(UrmsB,dpyLINHA1);
				WriteFloatString(IrmsB,dpyLINHA2);
				WriteFloatString(FatPotB,dpyLINHA3);
				break;
			}
		case TELA_U_I_FP_C:
			{
				setLED(LED_FaseC);
				setLED(LED_Volt);
				setLED(LED_Amp);
				setLED(LED_Fp);
				WriteFloatString(UrmsC,dpyLINHA1);
				WriteFloatString(IrmsC,dpyLINHA2);
				WriteFloatString(FatPotC,dpyLINHA3);
				break;
			}
		case TELA_W_VAR_VA_A:
			{
				setLED(LED_FaseA);
				setLED(LED_Watt);
				setLED(LED_Var);
				setLED(LED_Va);
				WriteFloatString(PotAtivA,dpyLINHA1);
				WriteFloatString(PotReatA,dpyLINHA2);
				WriteFloatString(PotAparA,dpyLINHA3);
				break;
			}
		case TELA_W_VAR_VA_B:
			{
				setLED(LED_FaseB);
				setLED(LED_Watt);
				setLED(LED_Var);
				setLED(LED_Va);
				WriteFloatString(PotAtivB,dpyLINHA1);
				WriteFloatString(PotReatB,dpyLINHA2);
				WriteFloatString(PotAparB,dpyLINHA3);
				break;
			}
		case TELA_W_VAR_VA_C:
			{
				setLED(LED_FaseC);
				setLED(LED_Watt);
				setLED(LED_Var);
				setLED(LED_Va);
				WriteFloatString(PotAtivC,dpyLINHA1);
				WriteFloatString(PotReatC,dpyLINHA2);
				WriteFloatString(PotAparC,dpyLINHA3);
				break;
			}
		case TELA_CONSUMO_TOTAL:
			{
				setLED(LED_Trif);
				setLED(LED_Kwh);
				FloatToStrForEnergy(ConsumoT*0.001,&str[0]);
				pstr=&str[0];
				WriteString(dpyLINHA1,pstr);
				WriteString(dpyLINHA3,"  At"); //consumo ativo
				break;
			}
		case TELA_CONSUMO_PONTA:
			{
				setLED(LED_Trif);
				setLED(LED_Kwh);
				FloatToStrForEnergy(ConsumoPontaMesPassado*0.001,&str[0]);
				pstr=&str[0];
				WriteString(dpyLINHA1,pstr);
				WriteString(dpyLINHA3,"At P"); //consumo ativo
				break;
			}
		case TELA_CONSUMO_FORAPONTA:
			{
				setLED(LED_Trif);
				setLED(LED_Kwh);
				FloatToStrForEnergy(ConsumoForaPontaMesPassado*0.001,&str[0]);
				pstr=&str[0];
				WriteString(dpyLINHA1,pstr);
				WriteString(dpyLINHA3,"AtFP"); //consumo ativo
				break;
			}
		case TELA_CONSUMO_RESERVADO:
			{
				setLED(LED_Trif);
				setLED(LED_Kwh);
				FloatToStrForEnergy(ConsumoReservMesPassado*0.001,&str[0]);
				pstr=&str[0];
				WriteString(dpyLINHA1,pstr);
				WriteString(dpyLINHA3,"AtrE"); //consumo ativo
				break;
			}
		case TELA_DEMANDA_PONTA:
			{
				setLED(LED_Trif);
				setLED(LED_Watt);
				WriteString(dpyLINHA2,"        ");
				WriteFloatString(Lista7DeMaxPotAtivPontaMesPassado[0],dpyLINHA1);
				WriteString(dpyLINHA3,"dE P"); //consumo ativo
				break;
			}
		case TELA_DEMANDA_FORAPONTA:
			{
				setLED(LED_Trif);
				setLED(LED_Watt);
				WriteString(dpyLINHA2,"        ");
				WriteFloatString(Lista8DeMaxPotAtivForaPontaMesPassado[0],dpyLINHA1);
				WriteString(dpyLINHA3,"dEFP"); //consumo ativo
				break;
			}
		case TELA_DEMANDA_RESERVADO:
			{
				setLED(LED_Trif);
				setLED(LED_Watt);
				WriteString(dpyLINHA2,"        ");
				WriteFloatString(Lista9DeMaxPotAtivReservMesPassado[0],dpyLINHA1);
				WriteString(dpyLINHA3,"dErE"); //consumo ativo
				break;
			}
		case TELA_GERADA_TOTAL:
			{
				setLED(LED_Trif);
				setLED(LED_Kwh);
				FloatToStrForEnergy(EnergGerT*0.001,&str[0]);
				pstr=&str[0];
				WriteString(dpyLINHA1,pstr);
				WriteString(dpyLINHA3," GEr");
				break;
			}

		case TELA_ENERGIA_IND_TOTAL:
			{
				setLED(LED_Trif);
				setLED(LED_Kvarh);
				FloatToStrForEnergy(EnergIndT*0.001,&str[0]);
				pstr=&str[0];
				WriteString(dpyLINHA1,pstr);
				WriteString(dpyLINHA3," Ind");

				break;
			}
		case TELA_ENERGIA_CAP_TOTAL:
			{
				setLED(LED_Trif);
				setLED(LED_Kvarh);
				FloatToStrForEnergy(EnergCapT*0.001,&str[0]);
				pstr=&str[0];
				WriteString(dpyLINHA1,pstr);
				WriteString(dpyLINHA3," CAP");

				break;
			}
		case TELA_NSERIE:
			{
				clrALL_LEDs();
				WriteString(dpyLINHA1,"n.S.  ");
				pstr=(char *)&nserie_str[0];
				WriteString(dpyLINHA2,pstr);
				break;
			}

		case TELA_U_AB:
			{
				setLED(LED_FaseA);
				setLED(LED_FaseB);
				setLED(LED_Volt);
				WriteFloatString(UrmsAB,dpyLINHA1);
				WriteString(dpyLINHA2,"     ");
				WriteString(dpyLINHA3,"     ");
				break;
			}
		case TELA_U_BC:
			{
				setLED(LED_FaseB);
				setLED(LED_FaseC);
				setLED(LED_Volt);
				WriteFloatString(UrmsBC,dpyLINHA1);
				WriteString(dpyLINHA2,"     ");
				WriteString(dpyLINHA3,"     ");
				break;
			}

		case TELA_U_CA:
			{
				setLED(LED_FaseA);
				setLED(LED_FaseC);
				setLED(LED_Volt);
				WriteFloatString(UrmsCA,dpyLINHA1);
				WriteString(dpyLINHA2,"     ");
				WriteString(dpyLINHA3,"     ");
				break;
			}


		case TELA_TESTE:
			{
				setAll_LEDs();
				WriteString(dpyLINHA1,"xxxxxxxxxxxx");
				break;
			}
#ifdef MODELO_D
		case TELA_TESTE1:
			{
				FloatToStrForPulso(pulso1,&str[0]);
				pstr=&str[0];
				WriteString(dpyLINHA1,pstr);
				WriteString(dpyLINHA3,"Ed 1"); //consumo ativo
				break;
			}
//#ifndef MODELO_DURACAO_PULSO
		case TELA_TESTE2:
			{
				FloatToStrForPulso(pulso2,&str[0]);
				pstr=&str[0];
				WriteString(dpyLINHA1,pstr);
				WriteString(dpyLINHA3,"Ed 2"); //consumo ativo
				break;
			}
//#endif
#endif



			//telas de programa��o:

		case TELA_PROG_REL_TP_PRI_MOD:
		case TELA_PROG_REL_TP_SEC_MOD:
		case TELA_PROG_REL_TP_FAT_MOD:
		case TELA_PROG_REL_TC_PRI_MOD:
		case TELA_PROG_REL_TC_SEC_MOD:
		case TELA_PROG_REL_TC_FAT_MOD:
		case TELA_PROG_ESCRAVO_MODBUS_MOD:
		case TELA_PROG_IP_OCTETO1_MOD:
		case TELA_PROG_IP_OCTETO2_MOD:
		case TELA_PROG_IP_OCTETO3_MOD:
		case TELA_PROG_IP_OCTETO4_MOD:
		case TELA_PROG_MK_OCTETO1_MOD:
		case TELA_PROG_MK_OCTETO2_MOD:
		case TELA_PROG_MK_OCTETO3_MOD:
		case TELA_PROG_MK_OCTETO4_MOD:
		case TELA_PROG_GW_OCTETO1_MOD:
		case TELA_PROG_GW_OCTETO2_MOD:
		case TELA_PROG_GW_OCTETO3_MOD:
		case TELA_PROG_GW_OCTETO4_MOD:
		case TELA_PROG_NRO_PORTA_MOD:
			{
				setDpyPiscante(currentAlgarismo,currentAlgarismo);
				SkewBanner();
				WriteIntString(BCDtoInt(tempMil,tempCen,tempDez,tempUni),dpyLINHA3);
				break;
			}
		case TELA_PROG_REL_TP_PRI:
			{
				SkewBanner();
				WriteIntString(relacaoTPpri_temp,dpyLINHA3);
				break;
			}
		case TELA_PROG_REL_TP_SEC:
			{
				SkewBanner();
				WriteIntString( relacaoTPsec_temp,dpyLINHA3);
				break;
			}
		case TELA_PROG_REL_TP_FAT:
			{
				SkewBanner();
				WriteIntString(relacaoTPfat_temp,dpyLINHA3);
				break;
			}
		case TELA_PROG_REL_TC_PRI:
			{
				SkewBanner();
				WriteIntString(relacaoTCpri_temp,dpyLINHA3);
				break;
			}
		case TELA_PROG_REL_TC_SEC:
			{
				SkewBanner();
				WriteIntString(relacaoTCsec_temp,dpyLINHA3);
				break;
			}
		case TELA_PROG_REL_TC_FAT:
			{
				SkewBanner();
				WriteIntString(relacaoTCfat_temp,dpyLINHA3);
				break;
			}

		case TELA_PROG_RESET_CONSUMO_MOD:
			setDpyPiscante(8,11);
		case TELA_PROG_RESET_CONSUMO:
			{
				SkewBanner();
				if (zeraConsumos=='n'){
					WriteString(dpyLINHA3," nAO");}
				if (zeraConsumos=='S'){
					WriteString(dpyLINHA3,"SI[]");}
				break;
			}
		case TELA_PROG_ESCRAVO_MODBUS:
			{
				SkewBanner();
				WriteIntString(MeuEnderecoMODBUS_temp,dpyLINHA3);
				break;
			}
		case TELA_PROG_BAUD_RATE_MOD:
			setDpyPiscante(8,11);
		case TELA_PROG_BAUD_RATE:
			{
				SkewBanner();

				switch(BaudRate_temp)
				{
					case BR4800:
						{
							WriteString(dpyLINHA3,"  4.8");
							break;
						}
					case BR9600:
						{
							WriteString(dpyLINHA3,"  9.6");
							break;
						}
					case BR14400:
						{
							WriteString(dpyLINHA3," 14.4");
							break;
						}
					case BR19200:
						{
							WriteString(dpyLINHA3," 19.2");
							break;
						}
					case BR38400:
						{
							WriteString(dpyLINHA3," 38.4");
							break;
						}
					case BR56000:
						{
							WriteString(dpyLINHA3," 56.0");
							break;
						}
					case BR57600:
						{
							WriteString(dpyLINHA3," 57.6");
							break;
						}
					case BR115200:
						{
							WriteString(dpyLINHA3,"115.2");
							break;
						}

				}
				break;
			}
		case TELA_PROG_PARIDADE_STOPS_MOD:
			setDpyPiscante(8,11);
		case TELA_PROG_PARIDADE_STOPS:
			{
				SkewBanner();
				switch(ParidadeStops_temp)
				{
					case ps8N2:
						{
							WriteString(dpyLINHA3," 8n2");
							break;
						}
					case ps8O1:
						{
							WriteString(dpyLINHA3," 8o1");
							break;
						}
					case ps8E1:
						{
							WriteString(dpyLINHA3," 8E1");
							break;
						}
				}

				break;
			}
		case TELA_PROG_IP_OCTETO1:
			{
				SkewBanner();
				WriteIntString( IPOcteto1_temp,dpyLINHA3);
				break;
			}
		case TELA_PROG_IP_OCTETO2:
			{
				SkewBanner();
				WriteIntString( IPOcteto2_temp,dpyLINHA3);
				break;
			}
		case TELA_PROG_IP_OCTETO3:
			{
				SkewBanner();
				WriteIntString( IPOcteto3_temp,dpyLINHA3);
				break;
			}
		case TELA_PROG_IP_OCTETO4:
			{
				SkewBanner();
				WriteIntString( IPOcteto4_temp,dpyLINHA3);
				break;
			}
		case TELA_PROG_MK_OCTETO1:
			{
				SkewBanner();
				WriteIntString( MKOcteto1_temp,dpyLINHA3);
				break;
			}
		case TELA_PROG_MK_OCTETO2:
			{
				SkewBanner();
				WriteIntString( MKOcteto2_temp,dpyLINHA3);
				break;
			}
		case TELA_PROG_MK_OCTETO3:
			{
				SkewBanner();
				WriteIntString( MKOcteto3_temp,dpyLINHA3);
				break;
			}
		case TELA_PROG_MK_OCTETO4:
			{
				SkewBanner();
				WriteIntString( MKOcteto4_temp,dpyLINHA3);
				break;
			}
		case TELA_PROG_GW_OCTETO1:
			{
				SkewBanner();
				WriteIntString( GWOcteto1_temp,dpyLINHA3);
				break;
			}
		case TELA_PROG_GW_OCTETO2:
			{
				SkewBanner();
				WriteIntString( GWOcteto2_temp,dpyLINHA3);
				break;
			}
		case TELA_PROG_GW_OCTETO3:
			{
				SkewBanner();
				WriteIntString( GWOcteto3_temp,dpyLINHA3);
				break;
			}
		case TELA_PROG_GW_OCTETO4:
			{
				SkewBanner();
				WriteIntString( GWOcteto4_temp,dpyLINHA3);
				break;
			}
		case TELA_PROG_NRO_PORTA:
			{
				SkewBanner();
				WriteIntString(NroPorta_temp,dpyLINHA3);
				break;
			}

		case TELA_PROG_GRAVAR_SIM_NAO_MOD:
			//case TELA_PROG_GRAVAR_SIM_NAO:
			{
				//	SkewBanner();
				setDpyPiscante(8,11);
				if (SairGravando=='n'){
					WriteString(dpyLINHA3," nAO");}
				if (SairGravando=='S'){
					WriteString(dpyLINHA3,"SI[]");}
				break;
			}

	}/* switch telaAtual */
}




/*
   Ao se entrar em uma nova tela, eh preciso
   inicializar suas variaveis de controle (condicoes iniciais),
   como posicao do cursor (se existe um),
   desenhar o 'fundo', funcoes de teclado, etc.
 */
void inicializaTela(int tela)
{

	inicializa_funcao_teclas(tela);
	clrALL_LEDs();
	FlagHabBanner=OFF;

	if (tela>=INICIO_TELAS_DE_PROGRAMACAO) //Telas de Programa��o
	{
		//escreve PROG no fundo da tela...
		WriteString(dpyLINHA1,"ProG"); //, esta tela podia ser um banner tamb�m no futuro.
		//	  	  WriteString(dpyLINHA3,"    ");
		if (tela==INICIO_TELAS_DE_PROGRAMACAO) /* tela ANTERIOR */
		{
#if (MODELO==COM_ETHERNET_COM_RS485)
			tela1=FIM_TELAS_DE_PROGRAMACAO;
#endif

#if (MODELO==COM_ETHERNET_SEM_RS485)
			tela1=FIM_TELAS_DE_PROGRAMACAO;
#endif

#if (MODELO==SEM_ETHERNET_COM_RS485)
			tela1=TELA_PROG_PARIDADE_STOPS;
#endif

#if (MODELO==SEM_ETHERNET_SEM_RS485)
			tela1= TELA_PROG_RESET_CONSUMO;
#endif

		}
		else
		{
			tela1=tela-1;
#if (MODELO==COM_ETHERNET_COM_RS485)

#endif

#if (MODELO==COM_ETHERNET_SEM_RS485)
			if (tela==TELA_PROG_IP_OCTETO1)
			{
				tela1=TELA_PROG_RESET_CONSUMO;
			}
#endif
#if (MODELO==SEM_ETHERNET_COM_RS485)
			if (tela==TELA_PROG_IP_OCTETO1)
			{
				tela1=TELA_PROG_PARIDADE_STOPS;
			}
#endif

#if (MODELO==SEM_ETHERNET_SEM_RS485)

			if (tela==TELA_PROG_ESCRAVO_MODBUS)
			{
				tela1=TELA_PROG_RESET_CONSUMO;
			}

#endif

		}

		if (tela==FIM_TELAS_DE_PROGRAMACAO)  /* tela PROXIMA */
		{
			tela2=INICIO_TELAS_DE_PROGRAMACAO;
		}
		else
		{
			tela2=tela+1;

#if (MODELO==COM_ETHERNET_SEM_RS485)
			if (tela2==TELA_PROG_ESCRAVO_MODBUS)
			{tela2=TELA_PROG_IP_OCTETO1;}
			// if (tela2==TELA_PROG_MK_OCTETO1)
			// {tela2=INICIO_TELAS_DE_PROGRAMACAO;}
#endif

#if (MODELO==SEM_ETHERNET_COM_RS485)

			if (tela2==TELA_PROG_IP_OCTETO1)
			{
				tela2=INICIO_TELAS_DE_PROGRAMACAO;
			}
#endif
#if (MODELO==SEM_ETHERNET_SEM_RS485)

			if (tela2==TELA_PROG_ESCRAVO_MODBUS)
			{
				tela2=INICIO_TELAS_DE_PROGRAMACAO;
			}
#endif

		}

		switch(tela)
		{

			case TELA_PROG_REL_TP_PRI:
				{
					WriteBanner(dpyLINHA2,"    rELACAO tP PrI[]ArIO");
					break;
				}
			case TELA_PROG_REL_TP_SEC:
				{
					WriteBanner(dpyLINHA2,"    rELACAO tP SECUndArIO");
					break;
				}
			case TELA_PROG_REL_TP_FAT:
				{
					WriteBanner(dpyLINHA2,"    FAtOr []ULtIPLICACAO tP");
					break;
				}
			case TELA_PROG_REL_TC_PRI:
				{
					WriteBanner(dpyLINHA2,"    rELACAO tC PrI[]ArIO");
					break;
				}
			case TELA_PROG_REL_TC_SEC:
				{
					WriteBanner(dpyLINHA2,"    rELACAO tC SECUndArIO");
					break;
				}
			case TELA_PROG_REL_TC_FAT:
				{
					WriteBanner(dpyLINHA2,"    FAtOr []ULtIPLICACAO tC");
					break;
				}
			case TELA_PROG_RESET_CONSUMO:
				{
					WriteBanner(dpyLINHA2,"    rESEt COnSU[]OS");
					break;
				}

			case TELA_PROG_ESCRAVO_MODBUS:
				{
					WriteBanner(dpyLINHA2,"    nU[]ErO nA rEdE []OdbUS");
					break;
				}
			case TELA_PROG_BAUD_RATE:
				{
					WriteBanner(dpyLINHA2,"    bAUd rAtE");
					break;
				}
			case TELA_PROG_PARIDADE_STOPS:
				{
					WriteBanner(dpyLINHA2,"    PArIdAdE-StOP bItS");
					break;
				}
			case TELA_PROG_IP_OCTETO1:
				{
					WriteBanner(dpyLINHA2,"    1@-OCtEtO-EndErECO IP");
					break;
				}
			case TELA_PROG_IP_OCTETO2:
				{
					WriteBanner(dpyLINHA2,"    2@-OCtEtO-EndErECO IP");
					break;
				}
			case TELA_PROG_IP_OCTETO3:
				{
					WriteBanner(dpyLINHA2,"    3@-OCtEtO-EndErECO IP");
					break;
				}
			case TELA_PROG_IP_OCTETO4:
				{
					WriteBanner(dpyLINHA2,"    4@-OCtEtO-EndErECO IP");
					break;
				}
			case TELA_PROG_MK_OCTETO1:
				{
					WriteBanner(dpyLINHA2,"    1@-OCtEtO-[]ASCArA SUbrEdE");
					break;
				}
			case TELA_PROG_MK_OCTETO2:
				{
					WriteBanner(dpyLINHA2,"    2@-OCtEtO-[]ASCArA SUbrEdE");
					break;
				}
			case TELA_PROG_MK_OCTETO3:
				{
					WriteBanner(dpyLINHA2,"    3@-OCtEtO-[]ASCArA SUbrEdE");
					break;
				}
			case TELA_PROG_MK_OCTETO4:
				{
					WriteBanner(dpyLINHA2,"    4@-OCtEtO-[]ASCArA SUbrEdE");
					break;
				}
			case TELA_PROG_GW_OCTETO1:
				{
					WriteBanner(dpyLINHA2,"    1@-OCtEtO-GAtE)(AY");
					break;
				}
			case TELA_PROG_GW_OCTETO2:
				{
					WriteBanner(dpyLINHA2,"    2@-OCtEtO-GAtE)(AY");
					break;
				}
			case TELA_PROG_GW_OCTETO3:
				{
					WriteBanner(dpyLINHA2,"    3@-OCtEtO-GAtE)(AY");
					break;
				}
			case TELA_PROG_GW_OCTETO4:
				{
					WriteBanner(dpyLINHA2,"    4@-OCtEtO-GAtE)(AY");
					break;
				}
			case TELA_PROG_NRO_PORTA:
				{
					WriteBanner(dpyLINHA2,"    PortA nr@");
					break;
				}

			case TELA_PROG_GRAVAR_SIM_NAO_MOD:
				{
					WriteString(dpyLINHA2,"ConFIr[]A ?");
					//	WriteBanner(dpyLINHA2,"    ConFIr[]A ?");
					break;
				}


		}
	}

	else									//Telas de Exibi��o
	{
		if (tela==INICIO_TELAS_DE_EXIBICAO) /* tela ANTERIOR */
		{
			tela1=FIM_TELAS_DE_EXIBICAO;
		}
		else
		{
			tela1=tela-1;
		}
		if (tela==FIM_TELAS_DE_EXIBICAO)  /* PROXIMA */
		{
			tela2=INICIO_TELAS_DE_EXIBICAO;
		}
		else
		{
			tela2=tela+1;
		}

		switch(tela)
		{
			case TELA_APRESENTACAO:
				{
#ifndef MD_EM_TESTE
#ifdef MD4000
					WriteString(dpyLINHA1,"[]d 4000"); //escreve MD4000 no fundo da tela...
#endif
#ifdef MD4040
					WriteString(dpyLINHA1,"[]d 4040"); //escreve MD4040 no fundo da tela...
#endif
#endif
#ifdef MD_EM_TESTE
					WriteString(dpyLINHA1,"E[] tESt"); //escreve 'Em teste' no fundo da tela...
#endif

					break;
				}
		}
	}

	//ultimaTelaExibida=tela;
}




void proximaTela(int tela){
	telaAnterior=telaAtual;
	telaAtual=tela;
}

/*
   Recebe como parametro o endereco do array de funcoes
   a ser copiado para funcaoTeclas
 */
void inicializa_funcao_teclas(int tela)
{
	funcaoTeclas[TC_NULL]	= FuncoesDasTeclas[tela].null;
	funcaoTeclas[TC_UP]		= FuncoesDasTeclas[tela].up;
	funcaoTeclas[TC_DOWN]	= FuncoesDasTeclas[tela].down;
	funcaoTeclas[TC_LEFT]	= FuncoesDasTeclas[tela].left;
	funcaoTeclas[TC_RIGTH]	= FuncoesDasTeclas[tela].rigth;
	funcaoTeclas[TC_ESC]	= FuncoesDasTeclas[tela].esc;
	funcaoTeclas[TC_PRG]	= FuncoesDasTeclas[tela].prog;
}



/*
   Le o teclado
 */

//    Qdo o usuario pressiona uma tecla, por exemplo 01
//
//    teclaAtual      =       01
//    ultimaTeclaExecutada (=00)
//
//    Como teclaAtual != ultimaTeclaExecutada, executa a funcao
//
//    No proximo laco, se o usuario nao 'tirou' o dedo do teclado,
//    teclaAtual      =       01
//    ultimaTeclaExecutada =  (01)
//
//    Nenhuma acao eh executada.
//
//    Qdo o usuario soltar o teclado, teclaAtual sera igual a zero,
//    e o software chamara executaFuncao, executando funcao ZERO,
//    ou seja, este algoritmo naturalmente previne pressao repetitiva




void setLED (DWORD led)
{
	DWORD m[3]={0x000000FF,0x0000FF00,0x00FF0000};
	if ((led|m[0])==m[0])
	{
		LatchLED_1=LatchLED_1|led;//|(led<<16);
	}

	if ((led|m[1])==m[1])
	{

		LatchLED_2=LatchLED_2|(led>>8); //(led<<8);
	}

	if ((led|m[2])==m[2])
	{
		LatchLED_3=LatchLED_3|(led>>16);//|led ;
	}
}

void clrLED (DWORD led)
{
	DWORD m[3]={0x000000FF,0x0000FF00,0x00FF0000};
	if ((led|m[0])==m[0])
	{
		LatchLED_1=LatchLED_1&(~(led));
	}
	if ((led|m[1])==m[1])
	{
		LatchLED_2=LatchLED_2&(~(led>>8));
	}
	if ((led|m[2])==m[2])
	{
		LatchLED_3=LatchLED_3&(~(led>>16));
	}





}

/*{
  DWORD m[3]={0x000000FF,0x0000FF00,0x00FF0000};
  if ((led|m[0])==m[0])
  {
  LatchLED_1=LatchLED_1&(~(led<<16));
  }
  if ((led|m[1])==m[1])
  {
  LatchLED_2=LatchLED_2&(~(led<<8));
  }
  if ((led|m[2])==m[2])
  {
  LatchLED_3=LatchLED_3&(~(led));
  }
  }  */

void clrALL_LEDs()
{
	char i;
	DWORD n;

	n=0x00000001;
	clrLED(n);
	for (i=2;i<=21;i++)
	{
		n=n<<1;
		clrLED(n);
	}
}

void setAll_LEDs()
{
	char i;
	DWORD n;

	n=0x00000001;
	setLED(n);
	for (i=2;i<=21;i++)
	{
		n=n<<1;
		setLED(n);
	}
}

void TelaValoresTrifasicos(float grandeza1,float grandeza2,float grandeza3)
{
	setLED(LED_FaseA);
	setLED(LED_FaseB);
	setLED(LED_FaseC);
	WriteFloatString(grandeza1,dpyLINHA1);
	WriteFloatString(grandeza2,dpyLINHA2);
	WriteFloatString(grandeza3,dpyLINHA3);
}

void WriteIntString(short ii,char canal){
	char str[6];
	char *pstr;
	IntToStr(ii,&str[0]);
	pstr=&str[0];
	WriteString(canal,pstr);
}

void WriteFloatString(float f,char canal){
	char str[6];
	char *pstr;
	int FlagKilo,FlagMenos;

	FloatToStr(f,&str[0],&FlagKilo,&FlagMenos);
	pstr=&str[0];
	switch (canal)
	{
		case dpyLINHA1:
			{
				if (FlagKilo==ON) {setLED(LED_KiloA);} else {clrLED(LED_KiloA);}
				if (FlagMenos==ON) {setLED(LED_MinA);} else {clrLED(LED_MinA);}
				break;
			}
		case dpyLINHA2:
			{
				if (FlagKilo==ON) {setLED(LED_KiloB);} else {clrLED(LED_KiloB);}
				if (FlagMenos==ON) {setLED(LED_MinB);} else {clrLED(LED_MinB);}
				break;
			}
		case dpyLINHA3:
			{
				if (FlagKilo==ON) {setLED(LED_KiloC);} else {clrLED(LED_KiloC);}
				if (FlagMenos==ON) {setLED(LED_MinC);} else {clrLED(LED_MinC);}
				break;
			}
	}

	WriteString(canal,pstr);

}

void InttoBCD(unsigned short numero, char *milhar, char *centena, char *dezena, char *unidade)
{
	*milhar=numero/1000;

	*centena=(numero-*milhar*1000)/100;
	*dezena=(numero-*milhar*1000-*centena*100)/10;
	*unidade=(numero-*milhar*1000-*centena*100-*dezena*10);
}

long int divround1(float a, float b )
{
	/*
	   float r;
	   r=(a/b)-(long int)(a/b);
	   if (r>0.5)
	   {
	   return((long int)(a/b)+1);
	   }
	   else
	   {
	   return((long int)(a/b));
	   }
	 */
	return ( (long int)(a/b + 0.5) );

}

unsigned short BCDtoInt(char milhar, char centena, char dezena, char unidade)
{
	return(milhar*1000+centena*100+dezena*10+unidade);
}

/*
   void AtualizaParametrizacao()
   {
   relacaoTP=(float)relacaoTPfat*((float)relacaoTPpri/(float)relacaoTPsec);
   relacaoTC=(float)relacaoTCfat*((float)relacaoTCpri/(float)relacaoTCsec);


   if (zeraConsumos=='S')
   {
//aqui � apagado o consumo
ConsumoT=0;ConsumoA=0; ConsumoB=0;ConsumoC=0;
EnergGerT=0;EnergGerA=0;EnergGerB=0;EnergGerC=0;
EnergIndT=0;EnergIndA=0;EnergIndB=0;EnergIndC=0;
EnergCapT=0; EnergCapA=0;EnergCapB=0;EnergCapC=0;
pulso1=0;
pulso2=0;
zeraConsumos='n';
}
}
 */

/*
   typedef struct _RelesStruct{
//endereco modbus das grandezas que serao comparadas com os setpoints
short eRgrandeza1;
short eRgrandeza2;
short eRgrandeza3;
//setpoints
short Rsetpoint1;
short Rsetpoint2;
short Rsetpoint3;
//setpoints
short RtempoObservacao;	//se 'infinito' nunca liga o RELE!
//tipo de compara�ao
short RtipoDeComparacao;
} RelesStruct;
 */

void OperaRele(short QualRele,short OnOff)
{




	switch (QualRele)
	{
		case 1:
			{
				if (OnOff==OFF)
				{

#if ((EQUIP_LINHA50 != MD_EQUIP))
	  HAL_GPIO_WritePin(ALARM1_GPIO_Port,ALARM1_Pin, GPIO_PIN_RESET);
#endif
					StatusDeTodosOsReles=StatusDeTodosOsReles&0x0FFF;

				}
				else
				{
#if ((EQUIP_LINHA50 != MD_EQUIP))
	  HAL_GPIO_WritePin(ALARM1_GPIO_Port,ALARM1_Pin, GPIO_PIN_SET);
#endif
					StatusDeTodosOsReles=StatusDeTodosOsReles|0xF000;

				}

				break;
			}
		case 2:
			{
				if (OnOff==OFF)
				{
#if ((EQUIP_LINHA50 != MD_EQUIP))
	  HAL_GPIO_WritePin(ALARM2_GPIO_Port,ALARM2_Pin, GPIO_PIN_RESET);
#endif
					StatusDeTodosOsReles=StatusDeTodosOsReles&0xF0FF;

				}
				else
				{
#if ((EQUIP_LINHA50 != MD_EQUIP))
	  HAL_GPIO_WritePin(ALARM2_GPIO_Port,ALARM2_Pin, GPIO_PIN_SET);
#endif
					StatusDeTodosOsReles=StatusDeTodosOsReles|0x0F00;

				}


				break;
			}
		case 3:
			{
				if (OnOff==OFF)
				{
#if ((EQUIP_LINHA50 != MD_EQUIP))
	  HAL_GPIO_WritePin(ALARM3_GPIO_Port,ALARM3_Pin, GPIO_PIN_RESET);
#endif
					StatusDeTodosOsReles=StatusDeTodosOsReles&0xFF0F;

				}
				else
				{
#if ((EQUIP_LINHA50 != MD_EQUIP))
	  HAL_GPIO_WritePin(ALARM3_GPIO_Port,ALARM3_Pin, GPIO_PIN_SET);
#endif
					StatusDeTodosOsReles=StatusDeTodosOsReles|0x00F0;

				}
				break;
			}
	}

}

short AvaliaRele(RelesStruct ReleX, short QualRele)
{

#ifdef CLIENTE_SETPOINT_X_1000
	float ReleXRsetpoint1;
	float ReleXRsetpoint2;
	float ReleXRsetpoint3;
#endif

	float *GrandezaA;
	float *GrandezaB;
	float *GrandezaC;

	float *GrandezaComparacaoA;
	float *GrandezaComparacaoB;
	float *GrandezaComparacaoC;

	static short contadorRele[3];

	GrandezaA=(float*)(2*ReleX.eRgrandeza1+(unsigned long int)&Versao);
	GrandezaB=(float*)(2*ReleX.eRgrandeza2+(unsigned long int)&Versao);
	GrandezaC=(float*)(2*ReleX.eRgrandeza3+(unsigned long int)&Versao);

	GrandezaComparacaoA=(float*)(2*ReleX.Rsetpoint1+(unsigned long int)&Versao);
	GrandezaComparacaoB=(float*)(2*ReleX.Rsetpoint2+(unsigned long int)&Versao);
	GrandezaComparacaoC=(float*)(2*ReleX.Rsetpoint3+(unsigned long int)&Versao);



#ifdef CLIENTE_SETPOINT_X_1000
	ReleXRsetpoint1= 1000.0*(float)ReleX.Rsetpoint1;
	ReleXRsetpoint2= 1000.0*(float)ReleX.Rsetpoint2;
	ReleXRsetpoint3= 1000.0*(float)ReleX.Rsetpoint3;
#endif

	if (ReleX.eRgrandeza1==0)
	{
		return (0);
	}

	//switch (ReleX.RtipoDeComparacao)
	{
		/*case 0: //
		  {
		  return(0);
		  }*/
		//case COMPARACAO_TIPO1: //compara��o tipo 1;
		if (ReleX.RtipoDeComparacao ==COMPARACAO_TIPO1)
		{
#ifndef CLIENTE_SETPOINT_X_1000
			//if ((*GrandezaA>ReleX.Rsetpoint1)&&(*GrandezaB>ReleX.Rsetpoint2)&&(*GrandezaC>ReleX.Rsetpoint3))
			if ((*GrandezaA>*GrandezaComparacaoA)&&(*GrandezaB>*GrandezaComparacaoB)&&(*GrandezaC>*GrandezaComparacaoC))
#else
				if ((*GrandezaA>ReleXRsetpoint1)&&(*GrandezaB>ReleXRsetpoint2)&&(*GrandezaC>ReleXRsetpoint3))
#endif
				{
					contadorRele[QualRele]++;//habilita contador
				}
				else
				{
					contadorRele[QualRele]=0;//zera contador
					OperaRele(QualRele,OFF);
				}
			//	break;
		}
		//case COMPARACAO_TIPO2: //compara��o tipo 2;
		if (ReleX.RtipoDeComparacao ==COMPARACAO_TIPO2)
		{
#ifndef CLIENTE_SETPOINT_X_1000
			//  	if ((*GrandezaA<ReleX.Rsetpoint1)&&(*GrandezaB<ReleX.Rsetpoint2)&&(*GrandezaC<ReleX.Rsetpoint3))
			if ((*GrandezaA<*GrandezaComparacaoA)&&(*GrandezaB<*GrandezaComparacaoB)&&(*GrandezaC<*GrandezaComparacaoC))

#else
				if ((*GrandezaA<ReleXRsetpoint1)&&(*GrandezaB<ReleXRsetpoint2)&&(*GrandezaC<ReleXRsetpoint3))
#endif
				{
					contadorRele[QualRele]++; //habilita contador
				}
				else
				{
					contadorRele[QualRele]=0; //zera contador
					OperaRele(QualRele,OFF);
				}
			//break;
		}

		//case COMPARACAO_TIPO3: //compara��o tipo 3;
		if (ReleX.RtipoDeComparacao ==COMPARACAO_TIPO3)
		{
#ifndef CLIENTE_SETPOINT_X_1000
			//if ((*GrandezaA>ReleX.Rsetpoint1)||(*GrandezaB>ReleX.Rsetpoint2)||(*GrandezaC>ReleX.Rsetpoint3))
			if ((*GrandezaA>*GrandezaComparacaoA)||(*GrandezaB>*GrandezaComparacaoB)||(*GrandezaC>*GrandezaComparacaoC))
#else
				if ((*GrandezaA>ReleXRsetpoint1)||(*GrandezaB>ReleXRsetpoint2)||(*GrandezaC>ReleXRsetpoint3))
#endif
				{
					contadorRele[QualRele]++;//habilita contador
				}
				else
				{
					contadorRele[QualRele]=0;//zera contador
					OperaRele(QualRele,OFF);
				}
			//break;
		}
		//case COMPARACAO_TIPO4: //compara��o tipo 4
		if (ReleX.RtipoDeComparacao ==COMPARACAO_TIPO4)
		{
#ifndef CLIENTE_SETPOINT_X_1000
			//  	if ((*GrandezaA<ReleX.Rsetpoint1)||(*GrandezaB<ReleX.Rsetpoint2)||(*GrandezaC<ReleX.Rsetpoint3))
			if ((*GrandezaA<*GrandezaComparacaoA)||(*GrandezaB<*GrandezaComparacaoB)||(*GrandezaC<*GrandezaComparacaoC))
#else
				if ((*GrandezaA<ReleXRsetpoint1)||(*GrandezaB<ReleXRsetpoint2)||(*GrandezaC<ReleXRsetpoint3))
#endif
				{
					contadorRele[QualRele]++; //habilita contador
				}
				else
				{
					contadorRele[QualRele]=0; //zera contador
					OperaRele(QualRele,OFF);
				}
			//	break;
		}

		//case COMPARACAO_TIPO5: //compara��o tipo 5;
		if (ReleX.RtipoDeComparacao ==COMPARACAO_TIPO5)
		{
#ifndef CLIENTE_SETPOINT_X_1000
			//if ((*GrandezaA>ReleX.Rsetpoint1))
			if ((*GrandezaA>(*GrandezaComparacaoA)))
#else
				if ((*GrandezaA>ReleXRsetpoint1))
#endif
				{
					contadorRele[QualRele]++; //habilita contador
				}
				else
				{
					contadorRele[QualRele]=0; //zera contador
					OperaRele(QualRele,OFF);
				}
			//break;
		}
		//case COMPARACAO_TIPO6: //compara��o tipo 6;
		if (ReleX.RtipoDeComparacao ==COMPARACAO_TIPO6)
		{
#ifndef CLIENTE_SETPOINT_X_1000
			//	if ((*GrandezaA<ReleX.Rsetpoint1))
			if ((*GrandezaA<(*GrandezaComparacaoA)))
#else
				if ((*GrandezaA<ReleXRsetpoint1))
#endif
				{
					contadorRele[QualRele]++; //habilita contador
				}
				else
				{
					contadorRele[QualRele]=0; //zera contador
					OperaRele(QualRele,OFF);
				}
			//break;
		}
		//case COMPARACAO_TIPO7: //compara��o tipo 7; N�O FAZ NADA
		if (ReleX.RtipoDeComparacao ==COMPARACAO_TIPO7)
		{
			OperaRele(QualRele,OFF);
			contadorRele[QualRele]=0; //zera contador
		}
	}

	if (contadorRele[QualRele]==ReleX.RtempoObservacao)
	{
		OperaRele(QualRele,ON);
		GravaNaBatteryRAM(REG_BATT_MEM_ALT_RELES);
	}

	if (contadorRele[QualRele]>=ReleX.RtempoObservacao)
	{
		contadorRele[QualRele]=ReleX.RtempoObservacao+1;
	}


	return(1);


}

void atualizaDevName(void)
{
	lhost_name[1]=dev_name[0];
	lhost_name[0]=dev_name[1];
	lhost_name[3]=dev_name[2];
	lhost_name[2]=dev_name[3];
	lhost_name[5]=dev_name[4];
	lhost_name[4]=dev_name[5];
	lhost_name[7]=dev_name[6];
	lhost_name[6]=dev_name[7];
	lhost_name[9]=dev_name[8];
	lhost_name[8]=dev_name[9];
	lhost_name[11]=dev_name[10];
	lhost_name[10]=dev_name[11];
	lhost_name[13]=dev_name[12];
	lhost_name[12]=dev_name[13];
	//lhost_name[15]=dev_name[14];
	//lhost_name[14]=dev_name[15];
}

/*
#if EQUIP_LINHA50 == CA_EQUIP
int OLDTela = 0;



void TelaTR1(int NTela)
{
	char strE[12];
	char str[12];
	int FlagKilo,FlagMenos;

	if(OLDTela != NTela){
		SSD1306_Clear();
	}

	if (NTela==0)
	{

		uint8_t temp_string[10];
		sprintf(temp_string, "%c.%c%c", versao_str[0], versao_str[1], versao_str[2]);

		PrtLcd2("CA50", 4, 42, &Font_11x18);
		PrtLcd2("VF:",28,0, &Font_11x18);
		PrtLcd2(temp_string,28, 33, &Font_11x18);

		PrtLcd2("NS:",45,0, &Font_11x18);
		PrtLcd2((char *)&nserie_str[0],45,33, &Font_11x18);

	}

	if (NTela==1)
	{
		uint8_t temp_string[10];
		#if(TIPO_ENTRADA_CA == VOLTAGE)
				sprintf(temp_string, "%f4.2 V", UrmsA);
				PrtLcd2("E1:",28,0, &Font_11x18);
				PrtLcd2(temp_string, 28, 33, &Font_11x18);

				sprintf(temp_string, "%f4.2 V", UrmsB);
				PrtLcd2("E2:",45,0, &Font_11x18);
				PrtLcd2(temp_string, 45, 33, &Font_11x18);

		#elif(TIPO_ENTRADA_CA == CURRENT)
				sprintf(temp_string, "%f4.2 mA", IrmsA);
				PrtLcd2("E1:",28,0, &Font_11x18);
				PrtLcd2(temp_string, 28, 33, &Font_11x18);

				sprintf(temp_string, "%f4.2 mA", IrmsB);
				PrtLcd2("E2:",45,0, &Font_11x18);
				PrtLcd2(temp_string, 45, 33, &Font_11x18);
		#endif

		/*
		FloatToStr(UrmsA,&strE[0],&FlagKilo,&FlagMenos); //mudar o algoritmo de forma a fixar
		PrtLcd("E1:              V",0,0);
		PrtLcd(strE,0,3);

		FloatToStr(UrmsB,&strE[0],&FlagKilo,&FlagMenos); //mudar o algoritmo de forma a fixar
		PrtLcd("E2:              V",1,0);
		PrtLcd(strE,1,3);


		FloatToStr(UrmsC,&strE[0],&FlagKilo,&FlagMenos); //mudar o algoritmo de forma a fixar
		PrtLcd("E3:             mA",2,0);
		PrtLcd(strE,2,3);

		FloatToStr(IrmsA,&strE[0],&FlagKilo,&FlagMenos); //mudar o algoritmo de forma a fixar
		PrtLcd("E4:             mA",3,0);
		PrtLcd(strE,3,3);


	}

	if (NTela==2)
    {
				/*
				PosCur(0,0);
				PrtLcd("ENDERECO IP:    ",0,0);
				PosCur(1,0);
				If_PutInt((unsigned int)localm[NETIF_ETH].IpAdr[0]);
				WrLcdData('.');
				PosCur(1,4);
				If_PutInt((unsigned int)localm[NETIF_ETH].IpAdr[1]);
				WrLcdData('.');
				PosCur(1,8);
				If_PutInt((unsigned int)localm[NETIF_ETH].IpAdr[2]);
				WrLcdData('.');
				PosCur(1,12);
				If_PutInt((unsigned int)localm[NETIF_ETH].IpAdr[3]);
				PrtLcd(" ",1,15);

				PrtLcd("PORTA:",3,0);

			    if (NroPorta>10000)
				{
				Sys_HexBcd(NroPorta-10000);
				PosCur(4,0);
				PrtLcdBcdNibble(4,0);
				}
				else
				{
				Sys_HexBcd(NroPorta);
				PosCur(4,0);
				}

				PrtLcdBcdNumber(Zaz[1]);
				PrtLcdBcdNumber(Zaz[0]);
				PrtLcd("                ",4,5);



	}

}

*/

//-----------------------------------------------------------------------------
// LB50
// TECLADO PARA CONTROLE DE TELAS
//-----------------------------------------------------------------------------

#if EQUIP_LINHA50 == MD_EQUIP
    int sequenciatela [15]= {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14};
	int		tela_max	  = 14;
#elif EQUIP_LINHA50 == CP_EQUIP
    int sequenciatela [11]= {0,14,15,16,17,9+1,10+1,11+1,12+1,13+1};
	int 	tela_max	  = 9;
#elif EQUIP_LINHA50 == CD_EQUIP
    int sequenciatela [11]= {0,14,15,16,17,9+1,10+1,11+1,12+1,13+1};
	int 	tela_max	  = 9;
#elif EQUIP_LINHA50 == CA_EQUIP
    int sequenciatela [10]= {0,14,15,17,9+1,10+1,11+1,12+1,13+1};
	int 	tela_max	  = 8;
#elif EQUIP_LINHA50 == CT_EQUIP
    int sequenciatela [11]= {0,14,15,16,17,9+1,10+1,11+1,12+1,13+1};
	int 	tela_max	  = 9;
#endif

uint32_t count_debouncing = 0;
uint32_t count_ip_reset = 0;
uint32_t debouncing=0;

short newLeTeclado(short NTelaTR){
#include "main.h"
static int	last_tela	= 0;

	if( HAL_GPIO_ReadPin(TCL1_GPIO_Port, TCL1_Pin)==0 && HAL_GPIO_ReadPin(TCL2_GPIO_Port, TCL2_Pin)==0 ){
		count_ip_reset++;

		if(count_ip_reset >= 30){
			count_ip_reset = 0;

			IPOcteto1 = 10;            // Local IP Address
			IPOcteto2 = 1;             // Local IP Address
			IPOcteto3 = 25;            // Local IP Address
			IPOcteto4 = 100;           // Local IP Address
			localm[NETIF_ETH].IpAdr[0] =  10;
			localm[NETIF_ETH].IpAdr[1] =   1;
			localm[NETIF_ETH].IpAdr[2] =  25;
			localm[NETIF_ETH].IpAdr[3] = 100;

			MKOcteto1=255;
			MKOcteto2=255;
			MKOcteto3=255;
			MKOcteto4=0;
			localm[NETIF_ETH].NetMask[0] = 255;
			localm[NETIF_ETH].NetMask[1] = 255;
			localm[NETIF_ETH].NetMask[2] = 255;
			localm[NETIF_ETH].NetMask[3] =   0;

			GWOcteto1=10;
			GWOcteto2=1;
			GWOcteto3=1;
			GWOcteto4=1;
			localm[NETIF_ETH].DefGW[0] =  10;
			localm[NETIF_ETH].DefGW[1] =   1;
			localm[NETIF_ETH].DefGW[2] =   1;
			localm[NETIF_ETH].DefGW[3] =   1;

			//NroPorta=1001;
			//NroPorta2=1001;
			NroPorta=1001;

			refresh_ip();  // inserido por Cesar para ST

			SalvaParametrizacao();

		}

	}
	else{
		count_ip_reset = 0;
	}


	if(debouncing == 0)	{
		if (HAL_GPIO_ReadPin(TCL1_GPIO_Port, TCL1_Pin)==0 && HAL_GPIO_ReadPin(TCL2_GPIO_Port, TCL2_Pin)!=0){
			NTelaTR ++;
			debouncing = 1;
			count_debouncing = 0;
		}
		else if (HAL_GPIO_ReadPin(TCL2_GPIO_Port, TCL2_Pin)==0 && HAL_GPIO_ReadPin(TCL1_GPIO_Port, TCL1_Pin)!=0)	{
			NTelaTR--;
			debouncing = 1;
			count_debouncing = 0;
		}
	}
	else{
		count_debouncing++;
		if(count_debouncing >= 5){
			debouncing = 0;
		 }
	 }

	if (NTelaTR > tela_max)	{
		NTelaTR = 0;
	}
	else if (NTelaTR < 0)	{
		NTelaTR = tela_max;
	}
	if (last_tela!=NTelaTR) {
		last_tela=NTelaTR;
	}

	return NTelaTR;
}



//-----------------------------------------------------------------------------
// LB50
// SEQUENCIA DE TELAS E APRESENTACAO DE VARIAVEIS
//-----------------------------------------------------------------------------
int OLDTela = 0;

void TelaTR1(int NTela)
{
	float tgrandeza;
	uint8_t temp_string[20];
	ultimaTelaExibida = NTela;

	if(OLDTela != NTela){
		SSD1306_Clear();
	}

// MD50, CP50, CA50, CD50, CT50: TELA INICIAL IDENTIFICAÇÃO , NUMERO DE SÉRIE , VERSAO DE FW
	switch(sequenciatela[NTela]){
		case 0:

			sprintf(temp_string, "%c.%c%c", versao_str[0], versao_str[1], versao_str[2]);
#if (EQUIP_LINHA50 == MD_EQUIP)
			PrtLcd2("MD50", 0, 45, &Font_11x18);
#elif (EQUIP_LINHA50 == CP_EQUIP)
			PrtLcd2("CP50", 0, 45, &Font_11x18);
#elif (EQUIP_LINHA50 == CA_EQUIP)
			PrtLcd2("CA50", 0, 45, &Font_11x18);
#elif (EQUIP_LINHA50 == CD_EQUIP)
			PrtLcd2("CD50", 0, 45, &Font_11x18);
#elif (EQUIP_LINHA50 == CT_EQUIP)
			PrtLcd2("CT50", 0, 45, &Font_11x18);
#endif

			PrtLcd2("VF:",28,0, &Font_11x18);
			PrtLcd2(temp_string,28, 33, &Font_11x18);
			sprintf(temp_string, "%c%c%c%c%c%c%c%c", nserie_str[0],nserie_str[1],nserie_str[2],nserie_str[3],
													 nserie_str[4],nserie_str[5],nserie_str[6],nserie_str[7]);
			PrtLcd2("NS:",45,0, &Font_11x18);
			PrtLcd2(temp_string,45, 33, &Font_11x18);
		break;

// MD50: TELA DE TENSAO, CORRENTE, FP DA FASE A
		case 1:

//			UrmsA=64244.59738225;
//			IrmsA=-575.9823;
//			FatPotA=-0.863423;
			PrtLcd2("A", 1, 0, &Font_11x18);

			sprintf(temp_string,"%9.2f", UrmsA); 	PrtLcd2(temp_string, 1, 35, &Font_11x18);
			sprintf(temp_string,"V"); 			 	PrtLcd2(temp_string, 1, 115, &Font_11x18);

			sprintf(temp_string,"%9.2f", IrmsA); 	PrtLcd2(temp_string, 23, 35, &Font_11x18);
			sprintf(temp_string,"A");		 	 	PrtLcd2(temp_string, 23, 115, &Font_11x18);

			sprintf(temp_string,"%8.3f", FatPotA);  PrtLcd2(temp_string, 45, 35, &Font_11x18);
			sprintf(temp_string,"FP"); 		 		PrtLcd2(temp_string, 45, 105, &Font_11x18);
		break;

// MD50: TELA DE TENSAO, CORRENTE, FP DA FASE B
		case 2:

//			UrmsB=127.69;
//			IrmsB=4.67;
//			FatPotB=-0.923;
			PrtLcd2("B",1, 0, &Font_11x18);

			sprintf(temp_string,"%9.2f", UrmsB); 	PrtLcd2(temp_string,1,35, &Font_11x18);
			sprintf(temp_string,"V");		 	 	PrtLcd2(temp_string,1,115, &Font_11x18);

			sprintf(temp_string,"%9.2f", IrmsB); 	PrtLcd2(temp_string,23,35, &Font_11x18);
			sprintf(temp_string,"A"); 	 			PrtLcd2(temp_string,23,115, &Font_11x18);

			sprintf(temp_string,"%8.3f", FatPotB);  PrtLcd2(temp_string,45,35, &Font_11x18);
			sprintf(temp_string,"FP");		 	 	PrtLcd2(temp_string,45,105, &Font_11x18);
		break;

// MD50: TELA DE TENSAO, CORRENTE, FP DA FASE C
		case 3:

//			UrmsC=34.24459738225;
//			IrmsC=5.759823;
//			FatPotC=1.00000;
			PrtLcd2("C",1, 0, &Font_11x18);

			sprintf(temp_string,"%9.2f", UrmsC); 	PrtLcd2(temp_string, 1, 35, &Font_11x18);
			sprintf(temp_string,"V");		 	 	PrtLcd2(temp_string, 1, 115, &Font_11x18);

			sprintf(temp_string,"%9.2f", IrmsC); 	PrtLcd2(temp_string, 23, 35, &Font_11x18);
			sprintf(temp_string,"A"); 	 			PrtLcd2(temp_string, 23, 115, &Font_11x18);

			sprintf(temp_string,"%8.3f", FatPotC);  PrtLcd2(temp_string, 45, 35, &Font_11x18);
			sprintf(temp_string,"FP");		 	 	PrtLcd2(temp_string, 45, 105, &Font_11x18);
		break;

// MD50: TELA DE FP, POTENCIA ATIVA E REATIVA DA FASE A
		case 4:

//			PotAtivA=22964244.59738225;
//			PotReatA=-700575.9823;
//			FatPotA=-0.863423;
			PrtLcd2("A",1, 0, &Font_11x18);

			sprintf(temp_string,"%8.3f", FatPotA);  PrtLcd2(temp_string, 1, 35, &Font_11x18);
			sprintf(temp_string,"FP");		 	 	PrtLcd2(temp_string, 1, 105, &Font_11x18);

			tgrandeza = PotAtivA*0.001;
			if (tgrandeza > 1000.0) {
				tgrandeza *= 0.001;
				PrtLcd2("MW", 23, 105, &Font_11x18);
			}
			else {
				PrtLcd2("kW", 23, 105, &Font_11x18);
			}

			char new_string[20] = {};
			sprintf(new_string,"%8.3f", tgrandeza); 	PrtLcd2(new_string, 23, 35, &Font_11x18);

			tgrandeza = PotReatA*0.001;
			//tgrandeza = (-0.001)*0.001;

			if (tgrandeza > 1000.0) {
				tgrandeza *= 0.001;
				PrtLcd2("MVAr", 45, 83, &Font_11x18);
			}
			else {
				PrtLcd2("kVAr", 45, 83, &Font_11x18);
			}
			sprintf(temp_string,"%8.3f", tgrandeza);	PrtLcd2(temp_string, 45, 12, &Font_11x18);

		break;

//  MD50: TELA DE FP, POTENCIA ATIVA E REATIVA DA FASE B
		case 5:
			PrtLcd2("B",1, 0, &Font_11x18);

			sprintf(temp_string,"%8.3f", FatPotB);  PrtLcd2(temp_string, 1, 35, &Font_11x18);
			sprintf(temp_string,"FP");		 	 	PrtLcd2(temp_string, 1, 105, &Font_11x18);

			tgrandeza = PotAtivB*0.001;
			if (tgrandeza > 1000.0) {
				tgrandeza *= 0.001;
				PrtLcd2("MW", 23, 105, &Font_11x18);
			}
			else {
				PrtLcd2("kW", 23, 105, &Font_11x18);
			}
			sprintf(temp_string,"%8.3f", tgrandeza); 	PrtLcd2(temp_string, 23, 35, &Font_11x18);

			tgrandeza = PotReatB*0.001;
			//tgrandeza = (-0.001)*0.001;
			if (tgrandeza > 1000.0) {
				tgrandeza *= 0.001;
				PrtLcd2("MVAr", 45, 83, &Font_11x18);
			}
			else {
				PrtLcd2("kVAr", 45, 83, &Font_11x18);
			}
			sprintf(temp_string,"%8.3f", tgrandeza);	PrtLcd2(temp_string, 45, 12, &Font_11x18);

		break;

//  MD50: TELA DE FP, POTENCIA ATIVA E REATIVA DA FASE C
		case 6:
			PrtLcd2("C",1, 0, &Font_11x18);

			sprintf(temp_string,"%8.3f", FatPotC);  PrtLcd2(temp_string, 1, 35, &Font_11x18);
			sprintf(temp_string,"FP");		 	 	PrtLcd2(temp_string, 1, 105, &Font_11x18);

			tgrandeza = PotAtivC*0.001;
			if (tgrandeza > 1000.0) {
				tgrandeza *= 0.001;
				PrtLcd2("MW", 23, 105, &Font_11x18);
			}
			else {
				PrtLcd2("kW", 23, 105, &Font_11x18);
			}
			sprintf(temp_string,"%8.3f", tgrandeza); 	PrtLcd2(temp_string, 23, 35, &Font_11x18);

			tgrandeza = PotReatC*0.001;
			//tgrandeza = (-0.001)*0.001;
			if (tgrandeza > 1000.0) {
				tgrandeza *= 0.001;
				PrtLcd2("MVAr", 45, 83, &Font_11x18);
			}
			else {
				PrtLcd2("kVAr", 45, 83, &Font_11x18);
			}
			sprintf(temp_string,"%8.3f", tgrandeza); 	PrtLcd2(temp_string, 45, 12, &Font_11x18);

		break;

//  MD50: TELA DE FP, POTENCIA ATIVA E REATIVA TRIFASICO
		case 7:
			PrtLcd2("T",1, 0, &Font_11x18);

			sprintf(temp_string,"%8.3f", FatPotT);  PrtLcd2(temp_string, 1, 35, &Font_11x18);
			sprintf(temp_string,"FP");		 	 	PrtLcd2(temp_string, 1, 105, &Font_11x18);

			tgrandeza = PotAtivT*0.001;
			if (tgrandeza > 1000.0) {
				tgrandeza *= 0.001;
				PrtLcd2("MW", 23, 105, &Font_11x18);
			}
			else {
				PrtLcd2("kW", 23, 105, &Font_11x18);
			}
			sprintf(temp_string,"%8.3f", tgrandeza); 	PrtLcd2(temp_string, 23, 35, &Font_11x18);

			tgrandeza = PotReatT*0.001;
			//tgrandeza = (-0.001)*0.001;

			if (tgrandeza > 1000.0) {
				tgrandeza *= 0.001;
				PrtLcd2("MVAr", 45, 83, &Font_11x18);
			}
			else {
				PrtLcd2("kVAr", 45, 83, &Font_11x18);
			}

			PrtLcd2("kVAr", 45, 83, &Font_11x18);

			sprintf(temp_string,"%8.3f", tgrandeza); 	PrtLcd2(temp_string, 45, 12, &Font_11x18);
		break;

//  MD50: TELA DE CONSUMO DE ENERGIA
		case 8:
			PrtLcd2("T", 1, 0, &Font_11x18);

			tgrandeza = ConsumoT*0.001;
			/*
			if (tgrandeza > 1000.0){
				tgrandeza *= 0.001;
				PrtLcd2("MWh", 1, 94, &Font_11x18);
			}
			else{
				PrtLcd2("kWh", 1, 94, &Font_11x18);
			}
			*/
			PrtLcd2("kWh", 1, 94, &Font_11x18);
			sprintf(temp_string,"%8.3f", tgrandeza); 	PrtLcd2(temp_string, 1, 24, &Font_11x18);
/*
			tgrandeza = EnergIndT*0.001;
			//tgrandeza = PotAtivT*0.001;
			if (tgrandeza > 1000.0){
				tgrandeza *= 0.001;
				PrtLcd2("MVArh", 23, 72, &Font_11x18);
			}
			else{
				PrtLcd2("kVArh", 23, 72, &Font_11x18);
			}*/
			PrtLcd2("kVArh", 23, 72, &Font_11x18);
			sprintf(temp_string,"%7.2f", tgrandeza); 	PrtLcd2(temp_string, 23, 13, &Font_11x18); PrtLcd2("i", 23, 0, &Font_11x18);

			tgrandeza = EnergCapT*0.001;
			/*
			if (tgrandeza > 1000.0) {
				tgrandeza *= 0.001;
				PrtLcd2("MVArh", 45, 72, &Font_11x18);
			}
			else {
				PrtLcd2("kVArh", 45, 72, &Font_11x18);
			}*/
			PrtLcd2("kVArh", 45, 72, &Font_11x18);
			sprintf(temp_string,"%7.2f", tgrandeza); 	PrtLcd2(temp_string, 45, 13, &Font_11x18); PrtLcd2("c", 45, 0, &Font_11x18);

		break;


		//  MD50: TELA DE GERACAO DE ENERGIA
				case 9:
					PrtLcd2("TG", 1, 0, &Font_11x18);

					tgrandeza = EnergGerT*0.001;
					if (tgrandeza<0)tgrandeza=-tgrandeza;
					/*
					if (tgrandeza > 1000.0){
						tgrandeza *= 0.001;
						PrtLcd2("MWh", 1, 94, &Font_11x18);
					}
					else{
						PrtLcd2("kWh", 1, 94, &Font_11x18);
					}
					*/
					PrtLcd2("kWh", 1, 94, &Font_11x18);
					sprintf(temp_string,"%8.3f", tgrandeza); 	PrtLcd2(temp_string, 1, 24, &Font_11x18);

					tgrandeza = EnergIndT*0.001;

					/*
					if (tgrandeza >= 1000.0){
						tgrandeza *= 0.001;
						PrtLcd2("MVArh", 23, 72, &Font_11x18);
					}
					else{
						PrtLcd2("kVArh", 23, 72, &Font_11x18);
					}*/
					PrtLcd2("kVArh", 23, 72, &Font_11x18);

					sprintf(temp_string,"%7.2f", tgrandeza); 	PrtLcd2(temp_string, 23, 13, &Font_11x18); PrtLcd2("i", 23, 0, &Font_11x18);

					tgrandeza = EnergCapT*0.001;
					/*
					if (tgrandeza > 1000.0) {
						tgrandeza *= 0.001;
						PrtLcd2("MVArh", 45, 72, &Font_11x18);
					}
					else {
						PrtLcd2("kVArh", 45, 72, &Font_11x18);
					}
					*/
					PrtLcd2("kVArh", 45, 72, &Font_11x18);

					sprintf(temp_string,"%7.2f", tgrandeza); 	PrtLcd2(temp_string, 45, 13, &Font_11x18); PrtLcd2("c", 45, 0, &Font_11x18);

				break;



// MD50, CP50, CA50, CD50, CT50: TELA IP
		case 9+1:
			PrtLcd2("IP:", 8, 2, &Font_11x18);
			sprintf(temp_string, "%03d.%03d.%03d.%03d", (unsigned int)localm[NETIF_ETH].IpAdr[0], (unsigned int)localm[NETIF_ETH].IpAdr[1],
														(unsigned int)localm[NETIF_ETH].IpAdr[2], (unsigned int)localm[NETIF_ETH].IpAdr[3] );
			PrtLcd2(temp_string, 36, 2, &Font_11x18);
		break;

// MD50, CP50, CA50, CD50, CT50: TELA PORTA
		case 10+1:
			PrtLcd2("PORTA:", 8, 2, &Font_11x18);
			sprintf(temp_string, "%05d", (int)NroPorta);
			PrtLcd2(temp_string, 36, 42, &Font_11x18);
		break;

// MD50, CP50, CA50, CD50, CT50: TELA MASCARA
		case 11+1:
			PrtLcd2("MASCARA:", 8, 2, &Font_11x18);
			sprintf(temp_string, "%03d.%03d.%03d.%03d", (unsigned int)localm[NETIF_ETH].NetMask[0], (unsigned int)localm[NETIF_ETH].NetMask[1],
														(unsigned int)localm[NETIF_ETH].NetMask[2], (unsigned int)localm[NETIF_ETH].NetMask[3]);
			PrtLcd2(temp_string, 36, 2, &Font_11x18);
		break;

// MD50, CP50, CA50, CD50, CT50: TELA GATEWAY
		case 12+1:
			PrtLcd2("GATEWAY:", 8, 2, &Font_11x18);

			sprintf(temp_string, "%03d.%03d.%03d.%03d", (unsigned int)localm[NETIF_ETH].DefGW[0], (unsigned int)localm[NETIF_ETH].DefGW[1],
											  	  	  	(unsigned int)localm[NETIF_ETH].DefGW[2], (unsigned int)localm[NETIF_ETH].DefGW[3] );
			PrtLcd2(temp_string, 36, 2, &Font_11x18);
		break;

// MD50, CP50, CA50, CD50, CT50: TELA DATA E HORA
		case 13+1:
			sprintf(temp_string, "%02d/%02d/%04d", (unsigned int)RTCGetTime().RTC_Mday, (unsigned int)RTCGetTime().RTC_Mon, (unsigned int)RTCGetTime().RTC_Year );
			PrtLcd2(temp_string, 8, 17, &Font_11x18);

			sprintf(temp_string, "%02d:%02d:%02d", (unsigned int)RTCGetTime().RTC_Hour, (unsigned int)RTCGetTime().RTC_Min, (unsigned int)RTCGetTime().RTC_Sec );
			PrtLcd2(temp_string, 36, 26, &Font_11x18);
		break;

// CP50, CD50, CA50 e CT50: TELA ENTRADAS E1 e E2
		case 14+1:

			#if (EQUIP_LINHA50 == CP_EQUIP)
						PrtLcd2("E1:", 8, 8, &Font_11x18);
						PrtLcd2("E2:", 36, 8, &Font_11x18);

						IntToStr1((int)pulso_cp_1, &temp_string[0] );
						PrtLcd2(temp_string, 8, 52, &Font_11x18);

						IntToStr1((int)pulso_cp_2,&temp_string[0] );
						PrtLcd2(temp_string, 36, 52, &Font_11x18);
			#elif (EQUIP_LINHA50 == CD_EQUIP)
						PrtLcd2("E1:", 8, 8, &Font_11x18);
						PrtLcd2("E2:", 36, 8, &Font_11x18);

						if (pulso_cp_1!=0)
							PrtLcd2("ON ", 8, 52, &Font_11x18);
						else
							PrtLcd2("OFF", 8, 52, &Font_11x18);

						if (pulso_cp_2!=0)
							PrtLcd2("ON ", 36, 52, &Font_11x18);
						else
							PrtLcd2("OFF", 36, 52, &Font_11x18);


			#elif (EQUIP_LINHA50 == CA_EQUIP)
						PrtLcd2("EA1", 8, 8, &Font_11x18);
						PrtLcd2("EA2:", 36, 8, &Font_11x18);

					#if CA_EQUIP_ENTRADAS_VOLT==1
					sprintf(temp_string,"%2.2f%s", UrmsA," V  ");
					PrtLcd2(temp_string, 8,55, &Font_11x18);

					sprintf(temp_string,"%2.2f%s", UrmsB," V  ");
					PrtLcd2(temp_string, 36, 55, &Font_11x18);


					#else
					sprintf(temp_string,"%2.2f%s", UrmsA," mA  ");
					PrtLcd2(temp_string, 8,55, &Font_11x18);

					sprintf(temp_string,"%2.2f%s", UrmsB," mA  ");
					PrtLcd2(temp_string, 36, 55, &Font_11x18);

					#endif


			#elif (EQUIP_LINHA50 == CT_EQUIP)
				PrtLcd2("EA1", 8, 8, &Font_11x18);
				PrtLcd2("EA2:", 36, 8, &Font_11x18);

				if (UrmsA>MAXIMA_TEMP_CT50)
					sprintf(temp_string,"--- oC ");
				else
					sprintf(temp_string,"%2.2f%s", UrmsA," oC ");  //°C
				PrtLcd2(temp_string, 8,55, &Font_11x18);

				if (UrmsB>MAXIMA_TEMP_CT50)
					sprintf(temp_string,"--- oC ");
				else
				sprintf(temp_string,"%2.2f%s", UrmsB," oC ");
				PrtLcd2(temp_string, 36, 55, &Font_11x18);



			#endif
		break;

// CP50, CD50, CA50 e CT50: TELA ENTRADAS E3 e E4
		case 15+1:

			#if (EQUIP_LINHA50 == CP_EQUIP)
						PrtLcd2("E3:", 8, 8, &Font_11x18);
						PrtLcd2("E4:", 36, 8, &Font_11x18);

						IntToStr1((int)pulso_cp_3, &temp_string[0] );
						PrtLcd2(temp_string, 8, 52, &Font_11x18);

						IntToStr1((int)pulso_cp_4,&temp_string[0] );
						PrtLcd2(temp_string, 36, 52, &Font_11x18);
			#elif (EQUIP_LINHA50 == CD_EQUIP)
						PrtLcd2("E3:", 8, 8, &Font_11x18);
						PrtLcd2("E4:", 36, 8, &Font_11x18);

						if (pulso_cp_3!=0)
							PrtLcd2("ON ", 8, 52, &Font_11x18);
						else
							PrtLcd2("OFF", 8, 52, &Font_11x18);

						if (pulso_cp_4!=0)
							PrtLcd2("ON ", 36, 52, &Font_11x18);
						else
							PrtLcd2("OFF", 36, 52, &Font_11x18);
			#elif (EQUIP_LINHA50 == CA_EQUIP)
						PrtLcd2("EA3:", 8, 8, &Font_11x18);
						PrtLcd2("EA4:", 36, 8, &Font_11x18);




						#if CA_EQUIP_ENTRADAS_VOLT==1
						sprintf(temp_string,"%2.2f%s", UrmsC," V  ");
						PrtLcd2(temp_string, 8,55, &Font_11x18);

						sprintf(temp_string,"%2.2f%s", IrmsA," V  ");
						PrtLcd2(temp_string, 36, 55, &Font_11x18);


						#else
						sprintf(temp_string,"%2.2f%s", UrmsC," mA  ");
						PrtLcd2(temp_string, 8,55, &Font_11x18);

						sprintf(temp_string,"%2.2f%s", IrmsA," mA  ");
						PrtLcd2(temp_string, 36, 55, &Font_11x18);

						#endif
																							#




			#elif (EQUIP_LINHA50 == CT_EQUIP)
						PrtLcd2("EA3:", 8, 8, &Font_11x18);
						PrtLcd2("EA4:", 36, 8, &Font_11x18);
						if (UrmsC>MAXIMA_TEMP_CT50)
							sprintf(temp_string,"--- oC ");
						else
						sprintf(temp_string,"%2.2f%s", UrmsC," oC ");
						PrtLcd2(temp_string, 8,55, &Font_11x18);
						if (IrmsA>MAXIMA_TEMP_CT50)
							sprintf(temp_string,"--- oC ");
						else
						sprintf(temp_string,"%2.2f%s", IrmsA," oC ");
						PrtLcd2(temp_string, 36, 55, &Font_11x18);

			#endif
		break;

// CP50, CD50 e CT50: TELA ENTRADAS E5 e E6
		case 16+1:

			#if (EQUIP_LINHA50 == CP_EQUIP)
						PrtLcd2("E5:", 8, 8, &Font_11x18);
						PrtLcd2("E6:", 36, 8, &Font_11x18);

						IntToStr1((int)pulso_cp_5, &temp_string[0] );
						PrtLcd2(temp_string, 8, 52, &Font_11x18);

						IntToStr1((int)pulso_cp_6,&temp_string[0] );
						PrtLcd2(temp_string, 36, 52, &Font_11x18);
			#elif (EQUIP_LINHA50 == CD_EQUIP)
						PrtLcd2("E5:", 8, 8, &Font_11x18);
						PrtLcd2("E6:", 36, 8, &Font_11x18);

						if (pulso_cp_5!=0)
							PrtLcd2("ON ", 8, 52, &Font_11x18);
						else
							PrtLcd2("OFF", 8, 52, &Font_11x18);

						if (pulso_cp_6!=0)
							PrtLcd2("ON ", 36, 52, &Font_11x18);
						else
							PrtLcd2("OFF", 36, 52, &Font_11x18);
			#elif (EQUIP_LINHA50 == CA_EQUIP)
			#elif (EQUIP_LINHA50 == CT_EQUIP)

						//

				PrtLcd2("EA5", 8, 8, &Font_11x18);
				PrtLcd2("EA6:", 36, 8, &Font_11x18);

				if (IrmsB>MAXIMA_TEMP_CT50)
					sprintf(temp_string,"--- oC ");
				else
				sprintf(temp_string,"%2.2f%s", IrmsB," oC ");  //°C
				PrtLcd2(temp_string, 8,55, &Font_11x18);
				if (IrmsC>MAXIMA_TEMP_CT50)
					sprintf(temp_string,"--- oC ");
				else
				sprintf(temp_string,"%2.2f%s", IrmsC," oC ");
				PrtLcd2(temp_string, 36, 55, &Font_11x18);
						///


			#endif
		break;

		case 17+1:

			PrtLcd2("RELE1:", 0, 8, &Font_11x18);
			if( (StatusDeTodosOsReles&0xF000) == 0xF000 ){	// print ON
				PrtLcd2("ON ", 0, 75, &Font_11x18);
			}
			else{ // print OFF
				PrtLcd2("OFF", 0, 75, &Font_11x18);
			}

			PrtLcd2("RELE2:", 22, 8, &Font_11x18);
			if( (StatusDeTodosOsReles&0x0F00) == 0x0F00 ){	// print ON
				PrtLcd2("ON ", 22, 75, &Font_11x18);
			}
			else{ // print OFF
				PrtLcd2("OFF", 22, 75, &Font_11x18);
			}

			PrtLcd2("RELE3:", 44, 8, &Font_11x18);
			if( (StatusDeTodosOsReles&0x00F0) == 0x00F0 ){	// print ON
				PrtLcd2("ON ", 44, 75, &Font_11x18);
			}
			else{ // print OFF
				PrtLcd2("OFF", 44, 75, &Font_11x18);
			}
		break;

	}	//end switch

	OLDTela = NTela;
}

void TelaAtualizando(){
	uint8_t temp_string[20];

	PrtLcd2("ATUALIZANDO:", 0, 0, &Font_11x18);
	PrtLcd2("IP:", 27, 2, &Font_11x18);
	sprintf(temp_string, "%03d.%03d.%03d.%03d", (unsigned int)localm[NETIF_ETH].IpAdr[0], (unsigned int)localm[NETIF_ETH].IpAdr[1],
												(unsigned int)localm[NETIF_ETH].IpAdr[2], (unsigned int)localm[NETIF_ETH].IpAdr[3] );
	PrtLcd2(temp_string, 45, 2, &Font_11x18);
}




#endif

void Sys_HexBcd(unsigned long int numero)
{
	char milhar; char centena; char dezena; char unidade;
	char dezmilesimo;char decimo; char milesimo;

	/*char unidade=0,dezena=0,centena=0,milhar=0,decimo=0,centesimo=0,milesimo=0;
	  long int centCemMil,dezDezMil,uniMil,decmCem,centmDez;

	  centena=(char)((long int)numero/100000);
	  centCemMil=(long int)centena*100000;

	  dezena=(char)((numero-centCemMil)/10000);
	  dezDezMil=(long int)dezena*10000;

	  unidade=(char)((numero-centCemMil-dezDezMil)/1000);
	  uniMil=(long int)unidade*1000;

	  decimo=(char)((numero-centCemMil-dezDezMil-uniMil)/100);
	  decmCem=(long int)decimo*100;

	  centesimo=(char)((numero-centCemMil-dezDezMil-uniMil-decmCem)/10);
	  centmDez=(long int)centesimo*10;

	  milesimo=(char)(numero-centCemMil-dezDezMil-uniMil-decmCem-centmDez);

	  Z[3]=milhar;
	  Z[2]=dezena|(centena<<4);
	  Z[1]=decimo|(unidade<<4);
	  Z[0]=milesimo|(centesimo<<4);
	 */


	milhar=  (char)((float)(numero/1000000));
	centena= (char)((float)(numero-(float)milhar*1000000)/100000);
	dezena=  (char)((float)(numero-(float)milhar*1000000-(float)centena*100000)/10000);
	unidade= (char)((float)(numero-(float)milhar*1000000-(float)centena*100000-(float)dezena*10000)/1000);
	decimo=  (char)((float)(numero-(float)milhar*1000000-(float)centena*100000-(float)dezena*10000-(float)unidade*1000)/100);
	milesimo=(char)((float)(numero-(float)milhar*1000000-(float)centena*100000-(float)dezena*10000-(float)unidade*1000-(float)decimo*100)/10);
	dezmilesimo=(char)((float)(numero-(float)milhar*1000000-(float)centena*100000-(float)dezena*10000-(float)unidade*1000-(float)decimo*100-(float)milesimo*10));

	Zaz[3]=milhar;
	Zaz[2]=dezena|(centena<<4);
	Zaz[1]=decimo|(unidade<<4);
	Zaz[0]=dezmilesimo|(milesimo<<4);

	/*
	   InttoBCD((unsigned short)numero, &milhar, &centena, &dezena, &unidade);
	   Z[3]=milhar;
	   Z[2]=dezena|(centena<<4);
	   Z[1]=decimo|(unidade<<4);
	   Z[0]=milesimo|(centesimo<<4);

	   Z[3]=milhar;
	   Z[2]=dezena|(centena<<4);
	   Z[1]=*milhar|(*centena<<4);
	   Z[0]=*unidade|(*dezena<<4);

	   {

	 *milhar=numero/1000000;
	 *centena=( numero-*milhar*1000000)/100000;
	 *dezena=  (numero-*milhar*1000000-*centena*100000)/10000;
	 *unidade= (numero-*milhar*1000000-*centena*100000-*dezena*10000)/1000;
	 *decimo=  (numero-*milhar*1000000-*centena*100000-*dezena*10000-*unidade*1000)/100;
	 *milesimo=(numero-*milhar*1000000-*centena*100000-*dezena*10000-*unidade*1000-*decimo*100)/10;
	 *dezmilesimo=(numero-*milhar*1000000-*centena*100000-*dezena*10000-*unidade*1000-*decimo*100-*milesimo*10);

	 }
	 */
}
void If_PutInt(unsigned int v)
{
	Sys_HexBcd(v);
	//PrtLcdBcdNumber(Zaz[2]);
	PrtLcdBcdNumber2(Zaz[1]);
	PrtLcdBcdNumber(Zaz[0]);

}
void PrtLcdBcdNumber2(char number)
{
	//PrtLcdBcdNibble(number,2);
	//PrtLcdBcdNibble(number,1);
	PrtLcdBcdNibble(number,0);
}
void PrtLcdBcdNumber(char number)
{
	PrtLcdBcdNibble(number,1);
	PrtLcdBcdNibble(number,0);
}
