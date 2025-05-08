 
#include "flashST.h"
#define EXT
#include "..\Port\global.h"



/* Base address of the Flash sectors single bank organization*/
#define ADDR_FLASH_SECTOR_0     ((uint32_t)0x08000000) /* Base address of Sector 0, 16 Kbytes */
#define ADDR_FLASH_SECTOR_1     ((uint32_t)0x08004000) /* Base address of Sector 1, 16 Kbytes */
#define ADDR_FLASH_SECTOR_2     ((uint32_t)0x08008000) /* Base address of Sector 2, 16 Kbytes */
#define ADDR_FLASH_SECTOR_3     ((uint32_t)0x0800C000) /* Base address of Sector 3, 16 Kbytes */
#define ADDR_FLASH_SECTOR_4     ((uint32_t)0x08010000) /* Base address of Sector 4, 64 Kbytes */
#define ADDR_FLASH_SECTOR_5     ((uint32_t)0x08020000) /* Base address of Sector 5, 128 Kbytes */
#define ADDR_FLASH_SECTOR_6     ((uint32_t)0x08040000) /* Base address of Sector 6, 128 Kbytes */
#define ADDR_FLASH_SECTOR_7     ((uint32_t)0x08060000) /* Base address of Sector 7, 128 Kbytes */
#define ADDR_FLASH_SECTOR_8     ((uint32_t)0x08080000) /* Base address of Sector 8, 128 Kbytes */
#define ADDR_FLASH_SECTOR_9     ((uint32_t)0x080A0000) /* Base address of Sector 9, 128 Kbytes */
#define ADDR_FLASH_SECTOR_10    ((uint32_t)0x080C0000) /* Base address of Sector 10, 128 Kbytes */
#define ADDR_FLASH_SECTOR_11    ((uint32_t)0x080E0000) /* Base address of Sector 11, 128 Kbytes */
#define ADDR_FLASH_SECTOR_12    ((uint32_t)0x08100000) /* Base address of Sector 11, 128 Kbytes */


//#define DATA_32                 ((uint32_t)0x12345678)

uint32_t FirstSector = 0, NbOfSectors = 0;
uint32_t Address = 0, SECTORError = 0;
__IO uint32_t data32 = 0 , MemoryProgramStatus = 0;

/*Variable used for Erase procedure*/
static FLASH_EraseInitTypeDef EraseInitStruct;


static uint32_t GetSector(uint32_t Address)
{
  uint32_t sector = 0;

  if((Address < ADDR_FLASH_SECTOR_1) && (Address >= ADDR_FLASH_SECTOR_0))
  {
    sector = FLASH_SECTOR_0;
  }
  else if((Address < ADDR_FLASH_SECTOR_2) && (Address >= ADDR_FLASH_SECTOR_1))
  {
    sector = FLASH_SECTOR_1;
  }
  else if((Address < ADDR_FLASH_SECTOR_3) && (Address >= ADDR_FLASH_SECTOR_2))
  {
    sector = FLASH_SECTOR_2;
  }
  else if((Address < ADDR_FLASH_SECTOR_4) && (Address >= ADDR_FLASH_SECTOR_3))
  {
    sector = FLASH_SECTOR_3;
  }
  else if((Address < ADDR_FLASH_SECTOR_5) && (Address >= ADDR_FLASH_SECTOR_4))
  {
    sector = FLASH_SECTOR_4;
  }
  else if((Address < ADDR_FLASH_SECTOR_6) && (Address >= ADDR_FLASH_SECTOR_5))
  {
    sector = FLASH_SECTOR_5;
  }
  else if((Address < ADDR_FLASH_SECTOR_7) && (Address >= ADDR_FLASH_SECTOR_6))
  {
    sector = FLASH_SECTOR_6;
  }
  else if((Address < ADDR_FLASH_SECTOR_8) && (Address >= ADDR_FLASH_SECTOR_7))
  {
    sector = FLASH_SECTOR_7;
  }
  else if((Address < ADDR_FLASH_SECTOR_9) && (Address >= ADDR_FLASH_SECTOR_8))
  {
    sector = FLASH_SECTOR_8;
  }
  else if((Address < ADDR_FLASH_SECTOR_10) && (Address >= ADDR_FLASH_SECTOR_9))
  {
    sector = FLASH_SECTOR_9;
  }  else if((Address < ADDR_FLASH_SECTOR_11) && (Address >= ADDR_FLASH_SECTOR_10))
  {
    sector = FLASH_SECTOR_10;
  }
  else /* (Address < FLASH_END_ADDR) && (Address >= ADDR_FLASH_SECTOR_11) */
  {
    sector = FLASH_SECTOR_11;
  }
  return sector;
}



/**-----------------------------------------------------------------------------------------------------------------------------------
  * @resumo Apaga a quantidade de páginas especificada a partir do endereço de memória FLASH especificado.
  *
  * @OBS    As funções HAL_FLASH_Unlock() e HAL_FLASH_OB_Unlock() devem ser chamadas previamente para habilitar a interface FLASH
  *         As funções HAL_FLASH_Lock() e HAL_FLASH_OB_Lock() devem ser chamadas  posteriormente para desabilitar a interface FLASH
  *
  * @param  Endereço:	  Endereço inicial da página que deseja ser apagada
  * @param  Paginas:      Quantidade de páginas que deseja apagar a partir do endereço inicial.
  *
  * @retval Void
  */
void FLASH_apaga(uint32_t endereco, uint8_t paginas){
#define FLASH_USER_START_ADDR   ADDR_FLASH_SECTOR_2   /* Start @ of user Flash area */
#define FLASH_USER_END_ADDR     (ADDR_FLASH_SECTOR_7-1)   /* End @ of user Flash area */


	/* Unlock the Flash to enable the flash control register access *************/
	HAL_FLASH_Unlock();

	/* Allow Access to option bytes sector */
	HAL_FLASH_OB_Unlock();

	/* Fill EraseInit structure
	FLASH_EraseInitTypeDef EraseInitStruct;			    // cria estrutura de dados para armazenar informações de apagamento
	EraseInitStruct.TypeErase = FLASH_TYPEERASE_PAGES;  // definição padrão da biblioteca HAL
	EraseInitStruct.PageAddress = endereco;				// definição do usuário do endereço da página que deseja apagar
	EraseInitStruct.NbPages = paginas;					// número de páginas que serão apagadas

	uint32_t PageError;									// Valor do endereço caso ocorra erro no apagamento da função HAL_FLASHEx_Erase
	if (HAL_FLASHEx_Erase(&EraseInitStruct, &PageError) != HAL_OK){
		// rotina caso ocorra erro no processo de apagar
	}
*/
	 /* Get the 1st sector to erase */
	  FirstSector = GetSector(FLASH_USER_START_ADDR);
	  /* Get the number of sector to erase from 1st sector*/
	  NbOfSectors = GetSector(FLASH_USER_END_ADDR) - FirstSector + 1;
	  /* Fill EraseInit structure*/
	  EraseInitStruct.TypeErase     = FLASH_TYPEERASE_SECTORS;
	  EraseInitStruct.VoltageRange  = FLASH_VOLTAGE_RANGE_3;
	  EraseInitStruct.Sector        = FirstSector;
	  EraseInitStruct.NbSectors     = NbOfSectors;
	  if (HAL_FLASHEx_Erase(&EraseInitStruct, &SECTORError) != HAL_OK)
	  {
	    /*
	      Error occurred while sector erase.
	      User can add here some code to deal with this error.
	      SECTORError will contain the faulty sector and then to know the code error on this sector,
	      user can call function 'HAL_FLASH_GetError()'
	    */
		  forceReset();
	  }


	HAL_FLASH_OB_Lock();
	HAL_FLASH_Lock();
}
/*-----------------------------------------------------------------------------------------------------------------------------------*/



/**-----------------------------------------------------------------------------------------------------------------------------------
  * @resumo Escreve uma half-word (16-bit) no endereço de memória flash específico
  *
  * @OBS1   As funções HAL_FLASH_Unlock() e HAL_FLASH_OB_Unlock() devem ser chamadas previamente para habilitar a interface FLASH
  *         As funções HAL_FLASH_Lock() e HAL_FLASH_OB_Lock() devem ser chamadas  posteriormente para desabilitar a interface FLASH
  *
  * @OBS2   O endereço de memória FLASH deve ser apagado antes da inserção de um novo valor. Neste caso, a página deve ser apagada.
  *
  * @param  Endereço:	  Endereço da memória em que o dado de 16 bits deverá ser armazenado. Endereço deve ser múltiplo de 2)
  * @param  *dado:        Ponteiro para o valor a ser inserido no endereço de memória especificado
  *
  * @retval Void
  */
void FLASH_escreve_16bits(uint32_t endereco, uint16_t *dado){

	HAL_FLASH_Unlock();
	HAL_FLASH_OB_Unlock();

	if( HAL_FLASH_Program(FLASH_TYPEPROGRAM_HALFWORD,(uint64_t)endereco, *dado) != HAL_OK){
		// rotina caso ocorra erro no processo de apagar
	}

	HAL_FLASH_OB_Lock();
	HAL_FLASH_Lock();
}


void FLASH_escreve_8bits(uint32_t endereco, uint8_t *dado){

	HAL_FLASH_Unlock();
	HAL_FLASH_OB_Unlock();

	if( HAL_FLASH_Program(FLASH_TYPEPROGRAM_BYTE,(uint64_t)endereco, *dado) != HAL_OK){
		// rotina caso ocorra erro no processo de apagar
	}

	HAL_FLASH_OB_Lock();
	HAL_FLASH_Lock();
}

/*-----------------------------------------------------------------------------------------------------------------------------------*/



/**-----------------------------------------------------------------------------------------------------------------------------------
  * @resumo Programa uma word (32-bit) no endereço de memória flash específico
  *
  * @OBS1   As funções HAL_FLASH_Unlock() e HAL_FLASH_OB_Unlock() devem ser chamadas previamente para habilitar a interface FLASH
  *         As funções HAL_FLASH_Lock() e HAL_FLASH_OB_Lock() devem ser chamadas  posteriormente para desabilitar a interface FLASH
  *
  * @OBS2   O endereço de memória FLASH deve ser apagado antes da inserção de um novo valor. Neste caso, a página deve ser apagada.
  *
  * @param  Endereço:	  Endereço da memória em que o dado de 32 bits deverá ser armazenado. Endereço deve ser múltiplo de 2
  * @param  *dado:        Ponteiro para o valor a ser inserido no endereço de memória especificado
  *
  * @retval Void
  */
unsigned int FLASH_escreve_32bits(uint32_t endereco, uint32_t *dado){
	unsigned int problema=0;
	HAL_FLASH_Unlock();
	HAL_FLASH_OB_Unlock();

	//__HAL_FLASH_CLEAR_FLAG(FLASH_FLAG_EOP | FLASH_FLAG_OPERR | FLASH_FLAG_WRPERR |
	//			FLASH_FLAG_PGAERR | FLASH_FLAG_PGPERR|FLASH_FLAG_PGSERR);


	if( HAL_FLASH_Program(FLASH_TYPEPROGRAM_WORD,(uint64_t)endereco, *dado) != HAL_OK){
		// rotina caso ocorra erro no processo
		problema=0xFF;
	}

	HAL_FLASH_OB_Lock();
	HAL_FLASH_Lock();
	return problema;
}
/*-----------------------------------------------------------------------------------------------------------------------------------*/


/**-----------------------------------------------------------------------------------------------------------------------------------
  * @resumo Programa uma string a partir do endereço de memória flash específico
  *
  * @OBS1   A função escreve valores de 16bits. Caso a string tenha número ímpar, a própria função preenche com 0xFF.
  *
  * @OBS2 	A própria função calcula o comprimento de memória que será utilizado
  *
  * @OBS3   O endereço de memória FLASH deve ser apagado antes da inserção de um novo valor. Neste caso, a página deve ser apagada.
  *			Caso a string ocupe mais de uma página, o projetista deverá interpretar isso e apagar a qtd. de páginas necessárias
  *
  * @param  Endereço:	  Endereço da memória em que a string[0] deverá ser armazenado. Endereço deve ser múltiplo de 2
  * @param  *dado:        Ponteiro para a string[] a ser inserido a partir endereço de memória especificado
  *
  * @retval Void
  */
void FLASH_escreve_string(uint32_t endereco, int8_t *dado){

	uint8_t contagem_de_endereco = 0;
	uint8_t comprimento_dado_FLASH = 0;
	uint8_t i = 0;

	// Se comprimento de *dado for par  : data_to_flash[a] , *dado[b] => a = b
	// Se comprimento dw *dado for ímpar: data_to_flash[a] , *dado[b] => a = b + 1
	comprimento_dado_FLASH = (strlen((char*)dado)) + (int)((strlen((char*)dado) % 2) != 0);
	uint8_t data_to_FLASH[comprimento_dado_FLASH];

	// Escreve o valor 0xFF (valor que consiste em endereço não utilizado na FLASH) em todos os elementos do vetor
	memset((uint8_t*)data_to_FLASH, 0xFF, comprimento_dado_FLASH);

	// Copia dado para data_to_flash (mantem último caractere com 0xFF caso seja ímpar)
	memcpy(data_to_FLASH,dado,strlen((char*)dado));

	for(i = 0; i < comprimento_dado_FLASH; i+=2){
		FLASH_escreve_16bits(endereco + contagem_de_endereco, (uint16_t*)&data_to_FLASH[i]);
		contagem_de_endereco += 2;
	}

}
/*-----------------------------------------------------------------------------------------------------------------------------------*/




/**-----------------------------------------------------------------------------------------------------------------------------------
  * @resumo Realiza a leitura de uma half-word (16-bit) no endereço de memória flash específico
  *
  * @param  Endereço:	  Endereço da memória em que o dado de 16 bits deverá ser lido. Endereço deve ser múltiplo de 2
  * @param  *dado:        Ponteiro para armazenar o valor a ser lido no endereço de memória especificado
  *
  * @retval Void
  */
void FLASH_le_16bits(uint32_t endereco, uint16_t *dado){

	*dado = *(uint32_t*)(endereco);

}
/*-----------------------------------------------------------------------------------------------------------------------------------*/




/**-----------------------------------------------------------------------------------------------------------------------------------
  * @resumo Realiza a leitura de uma word (32-bit) no endereço de memória flash específico
  *
  * @param  Endereço:	  Endereço da memória em que o dado de 32 bits deverá ser lido. Endereço deve ser múltiplo de 2
  * @param  *dado:        Ponteiro para armazenar o valor a ser lido no endereço de memória especificado
  *
  * @retval Void
  */
void FLASH_le_32bits(uint32_t endereco, uint32_t *dado){

	*dado = *(uint32_t*)(endereco);

}
/*-----------------------------------------------------------------------------------------------------------------------------------*/


/**-----------------------------------------------------------------------------------------------------------------------------------
  * @resumo Realiza a leitura de uma string[] a partir do endereço de memória flash indicado
  *
  * @param  Endereço:	  Endereço da memória em que a string[0] inicia. Endereço deve ser múltiplo de 2
  * @param  *dado:        Ponteiro (string[]) para armazenar o valor a ser lido no endereço de memória especificado
  *
  * @retval Void
  */
void FLASH_le_string_0xFF(uint32_t endereco, int8_t *dado){
	uint32_t leitura_FLASH = 0;
	uint8_t cont_end = 0;

	while(leitura_FLASH != 0xFFFFFFFF){

		leitura_FLASH = *(uint32_t*)(endereco + cont_end);

		if(leitura_FLASH != 0xFFFFFFFF){
			dado[0 + cont_end] = (int8_t)leitura_FLASH;
			dado[1 + cont_end] = (int8_t)(leitura_FLASH >> 8);
			dado[2 + cont_end] = (int8_t)(leitura_FLASH >> 16);
			dado[3 + cont_end] = (int8_t)(leitura_FLASH >> 24);
			cont_end +=4;
		}
	}

}
/*-----------------------------------------------------------------------------------------------------------------------------------*/




void erase1(void* start, void* end){
#define FLASH_USER_START_ADDR   ADDR_FLASH_SECTOR_2   /* Start @ of user Flash area */
#define FLASH_USER_END_ADDR     (ADDR_FLASH_SECTOR_7-1)   /* End @ of user Flash area */

	/* Unlock the Flash to enable the flash control register access *************/
	HAL_FLASH_Unlock();

	/* Allow Access to option bytes sector */
	HAL_FLASH_OB_Unlock();

	/* Fill EraseInit structure
	FLASH_EraseInitTypeDef EraseInitStruct;			    // cria estrutura de dados para armazenar informações de apagamento
	EraseInitStruct.TypeErase = FLASH_TYPEERASE_PAGES;  // definição padrão da biblioteca HAL
	EraseInitStruct.PageAddress = endereco;				// definição do usuário do endereço da página que deseja apagar
	EraseInitStruct.NbPages = paginas;					// número de páginas que serão apagadas

	uint32_t PageError;									// Valor do endereço caso ocorra erro no apagamento da função HAL_FLASHEx_Erase
	if (HAL_FLASHEx_Erase(&EraseInitStruct, &PageError) != HAL_OK){
		// rotina caso ocorra erro no processo de apagar
	}
*/
	 /* Get the 1st sector to erase */
	  FirstSector = GetSector(FLASH_USER_START_ADDR);
	  /* Get the number of sector to erase from 1st sector*/
	  NbOfSectors = GetSector(FLASH_USER_END_ADDR) - FirstSector + 1;
	  /* Fill EraseInit structure*/
	  EraseInitStruct.TypeErase     = FLASH_TYPEERASE_SECTORS;
	  EraseInitStruct.VoltageRange  = FLASH_VOLTAGE_RANGE_3;
	  EraseInitStruct.Sector        = FirstSector;
	  EraseInitStruct.NbSectors     = NbOfSectors;
	  if (HAL_FLASHEx_Erase(&EraseInitStruct, &SECTORError) != HAL_OK)
	  {
	    /*
	      Error occurred while sector erase.
	      User can add here some code to deal with this error.
	      SECTORError will contain the faulty sector and then to know the code error on this sector,
	      user can call function 'HAL_FLASH_GetError()'
	    */
		  while(1);
	  }


	HAL_FLASH_OB_Lock();
	HAL_FLASH_Lock();


};


void get_calib_addr(void)
{
	BYTE const *pFlashByte;
	BYTE DataInFlash;


	for (int i=0;i<16;i++)
	{
		pFlashByte=(const BYTE*)FLASH_CALIBRACAO;
		pFlashByte += (long int)SALTO_NO_SETOR*i+0x1500;
		DataInFlash=*pFlashByte;

		if (DataInFlash==0xFF){
			next_calib_addr=(long int)(pFlashByte);
			curr_calib_addr=next_calib_addr-256;
			if (curr_calib_addr<(FLASH_CALIBRACAO+0x1500))
					curr_calib_addr=next_calib_addr;

			break;
		}

	}
}



void erase(void* start, void* end){
	HAL_StatusTypeDef status;
	//goto sair;
	if ((long int)start==FLASH_CALIBRACAO)
	{
		get_calib_addr( );
		//não existe erase de fato no setor de calibração... Só pode haver 16 calibrações...

	}
	else
	{

			/* Unlock the Flash to enable the flash control register access *************/
			HAL_FLASH_Unlock();

			/* Allow Access to option bytes sector */
			HAL_FLASH_OB_Unlock();



			 /* Get the 1st sector to erase */
			  FirstSector = GetSector(start);
			  /* Get the number of sector to erase from 1st sector*/
			  NbOfSectors = GetSector(end) - FirstSector + 1;
			  /* Fill EraseInit structure*/
			  EraseInitStruct.TypeErase     = FLASH_TYPEERASE_SECTORS;
			  EraseInitStruct.VoltageRange  = FLASH_VOLTAGE_RANGE_3;
			  EraseInitStruct.Sector        = FirstSector;
			  EraseInitStruct.NbSectors     = NbOfSectors;
			  toogleWDI();
			  int8_t attemptsRemaining = 10;  //numero de tentativas para apagar o setor...
			  while (attemptsRemaining--)
			  {
					/* Clear pending flags (if any) */
		    __HAL_FLASH_CLEAR_FLAG(FLASH_FLAG_EOP | FLASH_FLAG_OPERR | FLASH_FLAG_WRPERR |
			FLASH_FLAG_PGAERR | FLASH_FLAG_PGPERR|FLASH_FLAG_PGSERR);

			  status=HAL_FLASHEx_Erase(&EraseInitStruct, &SECTORError) ;
			  	  if (status!= HAL_OK){
			  		 status=HAL_FLASH_GetError();
			  		 toogleWDI();
			  		 continue;
			  	  }
			  	  else
			  	  {
			  		  break;
			  	  }

			  }
			  if (status!= HAL_OK)
			  {
				/*
				  Error occurred while sector erase.
				  User can add here some code to deal with this error.
				  SECTORError will contain the faulty sector and then to know the code error on this sector,
				  user can call function 'HAL_FLASH_GetError()'
				*/
				  forceReset();
			  }

			  while(status != HAL_OK)
			  {
				  toogleWDI();
				  status = FLASH_WaitForLastOperation((uint32_t)50000U);
			  }






			HAL_FLASH_OB_Lock();
			HAL_FLASH_Lock();
	}
	sair:
		status=HAL_OK;
}


 unsigned int program(void *flash_addr, unsigned long int data_addr, unsigned int size){
unsigned int bsize=size>>2;  //a gravacao acontece em palavras de 32bits, por isso devido por 4 o size quera passado em bytes
uint32_t *data_to_FLASH;
int i;
unsigned int problema=0;
HAL_StatusTypeDef status;
data_to_FLASH=(uint32_t)data_addr;
//goto sair;
if ((long int)flash_addr==FLASH_CALIBRACAO)
{
	flash_addr=(void *)next_calib_addr;
}

while(status != HAL_OK)
	  status = FLASH_WaitForLastOperation((uint32_t)50000U);

	for(i = 0; i < bsize; i+=1){
	   problema=FLASH_escreve_32bits(flash_addr + i*4, (uint32_t*)&data_to_FLASH[i]);
	   toogleWDI();
	   if (problema!=0)
	   {
		   HAL_Delay(10);
		   toogleWDI();
		   problema=FLASH_escreve_32bits(flash_addr + i*4, (uint32_t*)&data_to_FLASH[i]);
		   HAL_Delay(10);
		   toogleWDI();
		   if (problema!=0)
		   break; // se dá algum problema sai do loop
		   problema=FLASH_escreve_32bits(flash_addr + i*4, (uint32_t*)&data_to_FLASH[i]);
		   HAL_Delay(10);
		   toogleWDI();
		   if (problema!=0)
		   break; // se dá algum problema sai do loop
	   }
	}
sair:
	return problema;

}




