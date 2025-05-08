/*****************************************************************************
 *   config.h:  Header file for global variables and global includes
 *
 *   Copyright(C) 2006, Embrasul Ind. Eletr�nica
 *   All rights reserved.
 *
 *   History
 *   2006.17.04  ver 1.00    Prelimnary version, first Release
 *
 ******************************************************************************/

#ifndef __GLOBAL_H__
#define __GLOBAL_H__

/******************************************************************************
 **                            All Includes
 ******************************************************************************/
//Aqui ser�o incluidas TODOS os .h utilizados no projeto,
//De forma que, incluindo o global.h estaremos incluindo tudo
//Aqui ser�o incluidas TODOS os .h utilizados no projeto,
//De forma que, incluindo o global.h estaremos incluindo tudo

#undef EXT
#define EXT extern
#include "linhabasica_port.h"
#include "battram.h"
#include "rtc.h"
#include "flash.h"
#include "config1.h"
#include "config.h"

#undef EXT
#define EXT

#include "global.h"


/*
unsigned char AT[] = "AT\r";
unsigned char ATI[] = "ATI\r";
unsigned char ATGMI[] = "AT+GMI\r";
unsigned char ATGMM[] = "AT+GMM\r";
unsigned char ATGMR[] = "AT+GMR\r";

unsigned char ATCREG[] = "AT+CREG\r";
unsigned char ATQICSGP[] = "AT+QICSGP=1,\"ZAP.VIVO.COM.BR\",\"vivo\",\"vivo\"\r";
unsigned char ATQIACT[] = "AT+QIACT=1\r";
unsigned char ATQIACTq[] = "AT+QIACT?\r";
unsigned char ATQIOPEN[] = "AT+QIOPEN=1,0,\"TCP\",\"220.180.239.201\",8009,0,0\r";
unsigned char ATQISEND[] = "AT+QISEND=0\r";
unsigned char TEST_MESSAGE[] = "TESTE123\r";
unsigned char ATQIRD[] = "AT+QIRD=0,1500";
unsigned char ATQIDEACT[] = "AT+QIDEACT=1";

unsigned char ATCSQ[] = "AT+CSQ";

unsigned char ATSGACT[] = "AT#SGACT=1,1";
unsigned char ATSGACTCFG[] = "AT#SGACTCFG=1,1";*/








//

#endif

/******************************************************************************
 **                            End Of File
 ******************************************************************************/

