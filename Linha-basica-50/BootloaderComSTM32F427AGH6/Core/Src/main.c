/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "lwip.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
CRC_HandleTypeDef hcrc;

TIM_HandleTypeDef htim12;

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_CRC_Init(void);
static void MX_TIM12_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
///////////////////////////////////////////////////////////////////////////////////////////////////
#undef STM47x

#include "lwip/opt.h"
#include "lwip/udp.h"
#include "lwip/pbuf.h"

#include "string.h"
#include "netif.h"

#ifdef STM47x
	#include "stm32f7xx_hal.h"
#else
	#include "stm32f4xx_hal.h"
#endif



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

//#define PORTA_ 1001
#define PORTA_ BattRam2.buffer[12]

uint32_t buffwords[64*256+10];
uint32_t next_addr_to_write;
uint32_t indx;


/* Base address of the Flash sectors single bank organization*/
#ifdef STM47x

#define ADDR_FLASH_SECTOR_0     ((uint32_t)0x08000000) /* Base address of Sector 0, 32 Kbytes */
#define ADDR_FLASH_SECTOR_1     ((uint32_t)0x08008000) /* Base address of Sector 1, 32 Kbytes */
#define ADDR_FLASH_SECTOR_2     ((uint32_t)0x08010000) /* Base address of Sector 2, 32 Kbytes */
#define ADDR_FLASH_SECTOR_3     ((uint32_t)0x08018000) /* Base address of Sector 3, 32 Kbytes */
#define ADDR_FLASH_SECTOR_4     ((uint32_t)0x08020000) /* Base address of Sector 4, 128 Kbytes */
#define ADDR_FLASH_SECTOR_5     ((uint32_t)0x08040000) /* Base address of Sector 5, 256 Kbytes */
#define ADDR_FLASH_SECTOR_6     ((uint32_t)0x08080000) /* Base address of Sector 6, 256 Kbytes */
#define ADDR_FLASH_SECTOR_7     ((uint32_t)0x080C0000) /* Base address of Sector 7, 256 Kbytes */


#define FLASH_CODIGO	((uint32_t) 0x080c0000)


#else

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

#define FLASH_CODIGO	ADDR_FLASH_SECTOR_5

#endif


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

#ifdef STM47x
  else /* (Address < FLASH_END_ADDR) && (Address >= ADDR_FLASH_SECTOR_11) */
  {
	  sector = FLASH_SECTOR_7; //sector = FLASH_SECTOR_11;
  }
  return sector;
}
#else
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
		  sector  = FLASH_SECTOR_11;
	}
	return sector;
	}

#endif






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

	for (int i=0;i<10;i++)
		if( HAL_FLASH_Program(FLASH_TYPEPROGRAM_WORD,(uint64_t)endereco, *dado) == HAL_OK){
			// rotina caso ocorra erro no processo de apagar
			break;
		}

	HAL_FLASH_OB_Lock();
	HAL_FLASH_Lock();

}
/*-----------------------------------------------------------------------------------------------------------------------------------*/



void erase(uint32_t  start,uint32_t end){
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
	  for (int i=0;i<10;i++)
		  if (HAL_FLASHEx_Erase(&EraseInitStruct, &SECTORError) == HAL_OK)
		  {
			/*
			  Error occurred while sector erase.
			  User can add here some code to deal with this error.
			  SECTORError will contain the faulty sector and then to know the code error on this sector,
			  user can call function 'HAL_FLASH_GetError()'
			*/
			  break;
		  }


	HAL_FLASH_OB_Lock();
	HAL_FLASH_Lock();
}


unsigned int program(void *flash_addr, unsigned int data_addr, unsigned int size){
unsigned int bsize=size>>2;  //a gravacao acontece em palavras de 32bits, por isso devido por 4 o size quera passado em bytes
uint32_t *data_to_FLASH;
int i;
unsigned int problema=0;
data_to_FLASH=(uint32_t)data_addr;

	for(i = 0; i < bsize; i+=1){
	   problema=FLASH_escreve_32bits(flash_addr + i*4, (uint32_t*)&data_to_FLASH[i]);
	   if (problema!=0) break;
    }
	return problema;
}




void enable_backup_sram(uint16_t clockforever)
{
    /*DBP : Enable access to Backup domain */
   HAL_PWR_EnableBkUpAccess();
    /*PWREN : Enable backup domain access  */
 __HAL_RCC_PWR_CLK_ENABLE();
    /*BRE : Enable backup regulator
      BRR : Wait for backup regulator to stabilize */
 HAL_PWREx_EnableBkUpReg();
   /*DBP : Disable access to Backup domain */
    //HAL_PWR_DisableBkUpAccess();

    if  (clockforever==1) //se 1 deixa habilitado o clock, fazendo com que o acesso a ram backup seja direto.
    __HAL_RCC_BKPSRAM_CLK_ENABLE();



}

void writeBkpSram(uint32_t l_data, uint32_t WRITE_READ_ADDR)
{
   /* Enable clock to BKPSRAM */
  __HAL_RCC_BKPSRAM_CLK_ENABLE();
  /* Pointer write on specific location of backup SRAM */
  *(uint32_t *) (BKPSRAM_BASE + WRITE_READ_ADDR) = l_data;
 /* Disable clock to BKPSRAM */
 __HAL_RCC_BKPSRAM_CLK_DISABLE();
}

uint32_t readBkpSram ( uint32_t WRITE_READ_ADDR)
{
   uint32_t i_retval;

  /* Enable clock to BKPSRAM */
  __HAL_RCC_BKPSRAM_CLK_ENABLE();
  /* Pointer write from specific location of backup SRAM */
  i_retval =  *(uint32_t*) (BKPSRAM_BASE + WRITE_READ_ADDR);
  /* Disable clock to BKPSRAM */
  __HAL_RCC_BKPSRAM_CLK_DISABLE();
  return i_retval;
}


//extern uint16_t udp_callback(uint8_t soc, uint8_t *rip, uint16_t rport, uint8_t *buf, uint16_t len);//

uint32_t cnt_watchdog = 0;

struct udp_pcb *upcb;
struct udp_pcb *upcb1;


void udp_echoserver_receive_callback1(void *arg, struct udp_pcb *upcb, struct pbuf *p, struct ip_addr *addr, u16_t port)
{
	 u8_t *data;
	  u16_t len;
	  err_t err;
	  uint8_t *buf;

        //resposta aqui...
			buf=p->payload;
			uint32_t Command 	  = (buf[ 3]<<24) +  (buf[ 2]<<16) +  (buf[1]<<8) +  buf[0];
			uint32_t adressFlash  = (buf[ 7]<<24) +  (buf[ 6]<<16) +  (buf[5]<<8) +  buf[4];
			uint32_t dataToFlash  = (buf[11]<<24) +  (buf[10]<<16) +  (buf[9]<<8) +  buf[8];


			if (Command==0xFFFFFFFF) //apagar 1 setor
			{
				 erase(adressFlash, adressFlash+1);
			     next_addr_to_write =FLASH_CODIGO;
			     //HAL_Delay(1000);

				 indx=0;

			}
			if (Command==0xDEADBEEF) //resetar o sistema
			{
				 HAL_PWR_EnableBkUpAccess();

				 free(buffwords);
				 if (BattRam1.id==0xABCD)
					 BattRam1.id=0x0009;


				 HAL_NVIC_SystemReset();
			}
			if (Command==0x0) //escreve uma word na FLASH
			{
				 FLASH_escreve_32bits(adressFlash, &dataToFlash);
			}
			if (Command==0x1BABACA1) //escreve uma 1024 bytes num buffer de 64k
			{
				int k=0, i=0;
				while (i<(256*2)){

					   dataToFlash = (buf[ 11+i]<<24) +  (buf[ 10 +i]<<16) +  (buf[9 +i]<<8) +  buf[8 +i];

					   //FLASH_escreve_32bits(adressFlash + i, &dataToFlash);
					   buffwords[indx]=dataToFlash;
					   indx=indx+1;
					   i=i+4;
					   k=k+1;
				    }

			}


			if (Command==0x2BABACA2) //escreve na FLASH o que tiver que ser escrito.
			{
				for(int i = 0; i <indx; i+=1){

				    FLASH_escreve_32bits(next_addr_to_write + i*4, &buffwords[i]);
				}
				next_addr_to_write=next_addr_to_write+indx*4;
				indx=0;

			}



			//HAL_Delay(10);

			uint8_t temp = buf ;









  /* Free the p buffer */
  pbuf_free(p);

  udp_send1 ( addr, port, temp, 8);

}

void  udp_send1 (struct ip_addr *addr, u16_t port, uint8_t *sendbuf, uint16_t len)
{

	err_t err;
	typedef ip4_addr_t ip_addr_t;




	struct pbuf *p;


	p=pbuf_alloc(PBUF_TRANSPORT, len, PBUF_POOL);

    //pbuf_take(p, sendbuf, len) ;
	 memcpy(p->payload, sendbuf, len); // payload copied


    //err= udp_connect(upcb,  &Ripaddr, NroPortaRemota);
	//err=-err;
     err= udp_connect(upcb1,  addr, port);
     if(err != ERR_OK)
     {
    	 err=-err;
     }


    //err=udp_send (upcb, p);
	err=udp_sendto (upcb1, p, addr, port); // the message back to the original host
    if(err != ERR_OK)
    {
   	 err=-err;
    }

	pbuf_free(p);
	  /* free the UDP connection, so we can accept new clients */
    udp_disconnect(upcb1);

}

void udp_echoserver_init(void)
{
   struct udp_pcb *upcb;
   err_t err;

   /* Create a new UDP control block  */
   upcb = udp_new();
   upcb1 = udp_new();

   if (upcb)
   {
     /* Bind the upcb to the UDP_PORT port */
     /* Using IP_ADDR_ANY allow the upcb to be used by any local interface */
      err = udp_bind(upcb, IP_ADDR_ANY, PORTA_);

      if(err == ERR_OK)
      {
        /* Set a receive callback for the upcb */
        udp_recv(upcb, udp_echoserver_receive_callback1, NULL);
      }
      else
      {
        udp_remove(upcb);
        printf("can not bind pcb");
      }
   }
   else
   {
     printf("can not create pcb");
   }
}

static void MX_GPIO_DeInit(void)
{

    __HAL_RCC_GPIOG_CLK_DISABLE();
    __HAL_RCC_GPIOD_CLK_DISABLE();
	__HAL_RCC_GPIOB_CLK_DISABLE();
	__HAL_RCC_GPIOA_CLK_DISABLE();
    __HAL_RCC_GPIOH_CLK_DISABLE();
	__HAL_RCC_GPIOC_CLK_DISABLE();





  HAL_GPIO_DeInit(TCL1_GPIO_Port, TCL1_Pin);
  HAL_GPIO_DeInit(TCL2_GPIO_Port, TCL2_Pin);
  HAL_GPIO_DeInit(TCL3_GPIO_Port, TCL3_Pin);
  HAL_GPIO_DeInit(TCL4_GPIO_Port, TCL4_Pin);
  HAL_GPIO_DeInit(TCL5_GPIO_Port, TCL5_Pin);
  HAL_GPIO_DeInit(TCL6_GPIO_Port, TCL6_Pin);
  HAL_GPIO_DeInit(WDI_GPIO_Port, WDI_Pin);


}

void deinitEverything()
{
	//-- reset peripherals to guarantee flawless start of user application
	MX_GPIO_DeInit( );
	HAL_RCC_DeInit();
	HAL_DeInit();
	SysTick->CTRL = 0;
	SysTick->LOAD = 0;
	SysTick->VAL = 0;
}

typedef void (application_t)(void);

typedef struct
{
    uint32_t		stack_addr;     // Stack Pointer
    application_t*	func_p;        // Program Counter
} JumpStruct;

void jumpToApp(const uint32_t address)
{
	const JumpStruct* vector_p = (JumpStruct*)address;

	deinitEverything();

	/* let's do The Jump! */
    /* Jump, used asm to avoid stack optimization */
    asm("msr msp, %0; bx %1;" : : "r"(vector_p->stack_addr), "r"(vector_p->func_p));
}

// Callback: timer has rolled over
// External Watchdog Timer
void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
  // Check which version of the timer triggered this callback and toggle strobe pin on external watchdog
  if (htim == &htim12 )
  {
	  cnt_watchdog++;

	  if(cnt_watchdog <= 800){ 					// 800 equiv 8s
		  HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_13);
	  }


  }
}

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

#if 0
  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_CRC_Init();
  MX_LWIP_Init();
  MX_TIM12_Init();
  /* USER CODE BEGIN 2 */
#endif



  MX_GPIO_Init();

  MX_TIM12_Init();
  HAL_TIM_Base_Start_IT(&htim12);

  __HAL_RCC_BKPSRAM_CLK_ENABLE();

  if(!HAL_GPIO_ReadPin(TCL2_GPIO_Port, TCL2_Pin) || BattRam1.id==0xABCD)
  {
		//se o botão está pressionado, então entra no modo de bootloader

		//MX_GPIO_DeInit();
		//MX_GPIO_Init();
		MX_CRC_Init();
		MX_LWIP_Init();

	//	buffwords=(uint32_t*)calloc(64*1024, sizeof(uint8_t));  //o processador possui 192Kbytes de RAM


	    udp_echoserver_init();

	    HAL_TIM_Base_Stop(&htim12);


	    while (1)
	    {

	  	   HAL_GPIO_WritePin(WDI_GPIO_Port,WDI_Pin, GPIO_PIN_RESET);
	   	   HAL_GPIO_WritePin(WDI_GPIO_Port,WDI_Pin, GPIO_PIN_SET);


	   	   HAL_GPIO_WritePin( AUX_OUT3_GPIO_Port ,AUX_OUT3_Pin,GPIO_PIN_SET); //desliga o LED
	   	   HAL_GPIO_WritePin( LED_POWER_GPIO_Port , LED_POWER_Pin,GPIO_PIN_SET); //desliga o LED
	   	   HAL_Delay(50);
	   	   MX_LWIP_Process( );
	   	   HAL_GPIO_WritePin( AUX_OUT3_GPIO_Port ,AUX_OUT3_Pin,GPIO_PIN_RESET); //liga o LED
	   	   HAL_GPIO_WritePin( LED_POWER_GPIO_Port , LED_POWER_Pin,GPIO_PIN_RESET); //liga o LED
	   	   HAL_Delay(50);
	       MX_LWIP_Process( );

	       if(!HAL_GPIO_ReadPin(TCL1_GPIO_Port, TCL1_Pin)){

	    	   HAL_PWR_EnableBkUpAccess();
			   BattRam1.id=0x0009;
			   HAL_NVIC_SystemReset();

			   //MX_GPIO_DeInit();
			   //jumpToApp(FLASH_CODIGO);

	       }

	    }

    }
    else //se o botão não esta apertado, então pulamos até a aplicação.
    {
    	HAL_TIM_Base_Stop(&htim12);
    	MX_GPIO_DeInit();
    	jumpToApp(FLASH_CODIGO);

    }

  ///nunca chega nesta parte do código pra baixo...

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE3);
  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
  RCC_OscInitStruct.PLL.PLLM = 8;
  RCC_OscInitStruct.PLL.PLLN = 120;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 4;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_3) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief CRC Initialization Function
  * @param None
  * @retval None
  */
static void MX_CRC_Init(void)
{

  /* USER CODE BEGIN CRC_Init 0 */

  /* USER CODE END CRC_Init 0 */

  /* USER CODE BEGIN CRC_Init 1 */

  /* USER CODE END CRC_Init 1 */
  hcrc.Instance = CRC;
  if (HAL_CRC_Init(&hcrc) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN CRC_Init 2 */

  /* USER CODE END CRC_Init 2 */

}

/**
  * @brief TIM12 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM12_Init(void)
{

  /* USER CODE BEGIN TIM12_Init 0 */

  /* USER CODE END TIM12_Init 0 */

  TIM_ClockConfigTypeDef sClockSourceConfig = {0};

  /* USER CODE BEGIN TIM12_Init 1 */

  /* USER CODE END TIM12_Init 1 */
  htim12.Instance = TIM12;
  htim12.Init.Prescaler = 9999;
  htim12.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim12.Init.Period = 90;
  htim12.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim12.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim12) != HAL_OK)
  {
    Error_Handler();
  }
  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim12, &sClockSourceConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM12_Init 2 */

  /* USER CODE END TIM12_Init 2 */

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOD_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOI_CLK_ENABLE();
  __HAL_RCC_GPIOE_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();
  __HAL_RCC_GPIOC_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(AUX_OUT3_GPIO_Port, AUX_OUT3_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOC, WDI_Pin|LED_POWER_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin : AUX_OUT3_Pin */
  GPIO_InitStruct.Pin = AUX_OUT3_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(AUX_OUT3_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : TCL4_Pin */
  GPIO_InitStruct.Pin = TCL4_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(TCL4_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pins : TCL2_Pin TCL1_Pin */
  GPIO_InitStruct.Pin = TCL2_Pin|TCL1_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  HAL_GPIO_Init(GPIOE, &GPIO_InitStruct);

  /*Configure GPIO pin : TCL3_Pin */
  GPIO_InitStruct.Pin = TCL3_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(TCL3_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pins : TCL5_Pin TCL6_Pin */
  GPIO_InitStruct.Pin = TCL5_Pin|TCL6_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pins : WDI_Pin LED_POWER_Pin */
  GPIO_InitStruct.Pin = WDI_Pin|LED_POWER_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
