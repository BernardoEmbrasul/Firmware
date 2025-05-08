
/* USER CODE BEGIN Header */

/**
 *
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

//Esta é a versão 1.17 comercializada hoje na embrasul
// versão 1.18 corrigindo bug do MD50
// versão 1.19 corrigindo a calibração do RTC
// versão 1.20 update na atualização remota de firmware (utiliza os endereços salvos na battram2)


#include <stdio.h>
#include <stdlib.h>
#include "ssd1306.h"
#include "fonts.h"
#include "bitmap.h"


#include "stm32f4xx_hal.h"

unsigned short const mask[17]={0x0000, 0x0001 , 0x0002, 0x0004, 0x0008, 0x0010, 0x0020, 0x0040,0x0080,0x0100,0x0200,0x0400,0x0800,0x1000,0x2000,0x4000,0x8000};
unsigned long const baudrates[8] = {4800,9600,14400,19200,38400,56000,57600,115200};

#undef EXT
#define EXT extern
#include "..\Port\linhabasica_port.h"
#undef EXT
#define EXT extern

regmodbus MapaModbus __attribute__ ((section ("MODBUS_MAPA"))) ={ 0 };

/*
 *  RAM    (xrw)    : ORIGIN = 0x20000000,   LENGTH = 320K
  FLASH_BOOTLOADER   	    (rx)    : ORIGIN = 0x08000000,   LENGTH = 32K
  FLASH_CALIBRACAO    		(rx)    : ORIGIN = 0x08008000,   LENGTH = 32K
  FLASH_DADOS1    			(rx)    : ORIGIN = 0x08010000,   LENGTH = 32K
  FLASH_DADOS2    			(rx)    : ORIGIN = 0x08018000,   LENGTH = 32K
  FLASH_PARAMETRIZACAO	    (rx)    : ORIGIN = 0x08020000,   LENGTH = 128K
  FLASH       				(rx)    : ORIGIN = 0x08040000,   LENGTH = 512K
  FLASH_MM    				(rx)    : ORIGIN = 0x080c0000,   LENGTH = 256K
 * */

__attribute__((__section__(".flash_dados1"))) const uint32_t xyz[1] ={ 0x11223344};



#include "timeouts.h"
#undef EXT
#define EXT extern
#include "..\Port\global.h"			  /* Relativos a variaves globais*/
extern void ResponderMODBUS(void);
extern void ResponderPR4000(void);
extern void Calculos1(void);

unsigned char const versao_str[3] = {VER1,VER2,VER3};

unsigned int CounterMASK[16]={0xFFFF,0xFFFE,0xFFFC,0xFFF8,0xFFF0,0xFFE0,0xFFC0,0xFF80,0xFF00,0xFE00,0xFC00,0xF800,0xF000,0xE000,0xC000,0x8000};
char TAB_SIL_CARGA[8]={14,10,8,6,4,4,4,4};//	 vezes 0.88ms!



float const polinomioMIa[4]={
	0.00009148534060,
	-0.00154130076592,
	1.00687717904248,
	-0.00687907625654
};
float const polinomioMIb[4]={
	0.00009148534060,
	-0.00154130076592,
	1.00687717904248,
	-0.00687907625654
};
float const polinomioMIc[4]={
	0.00009148534060,
	-0.00154130076592,
	1.00687717904248,
	-0.00687907625654
};


extern int main1(void);
extern void testes111(void);
extern void tcp_config(void);
extern void udp_config(void);
extern void  change_ip(void);
void my_GPIO_Init(void);
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */
//para mqtt
#include "lwip_mqtt.h"
mqtt_client_t *client;
char buffer_mqtt[1000];
char recebido_mqtt;
/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */



#define htimINT htim2
#define htimADC htim3
#define htimDAC htim4
#define htimCLK htim5
#define htimFASTINT htim6

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */
uint32_t cnt_watchdog = 0;
/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
ADC_HandleTypeDef hadc1;
DMA_HandleTypeDef hdma_adc1;

CRC_HandleTypeDef hcrc;

DAC_HandleTypeDef hdac;
DMA_HandleTypeDef hdma_dac1;
DMA_HandleTypeDef hdma_dac2;

I2C_HandleTypeDef hi2c2;

IWDG_HandleTypeDef hiwdg;

RTC_HandleTypeDef hrtc;

SPI_HandleTypeDef hspi2;
SPI_HandleTypeDef hspi4;

TIM_HandleTypeDef htim2;
TIM_HandleTypeDef htim3;
TIM_HandleTypeDef htim4;
TIM_HandleTypeDef htim5;
TIM_HandleTypeDef htim6;
TIM_HandleTypeDef htim12;

UART_HandleTypeDef huart2;

/* USER CODE BEGIN PV */

volatile long int start_cicles;
volatile long int elapsed_cicles;
volatile long int cnt_amostras=0;
volatile long int cnt_amostras1;

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_DMA_Init(void);
static void MX_ADC1_Init(void);
static void MX_CRC_Init(void);
static void MX_RTC_Init(void);
static void MX_TIM2_Init(void);
static void MX_TIM4_Init(void);
static void MX_TIM3_Init(void);
static void MX_I2C2_Init(void);
static void MX_DAC_Init(void);
static void MX_SPI4_Init(void);
static void MX_USART2_UART_Init(void);
static void MX_SPI2_Init(void);
static void MX_TIM5_Init(void);
static void MX_IWDG_Init(void);
static void MX_TIM6_Init(void);
static void MX_TIM12_Init(void);
/* USER CODE BEGIN PFP */
void MX_GPIO_Init2(void);

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

void AcertaTimerParaFreqInterrupcao(TIM_HandleTypeDef *htimer,uint16_t freq_int)
{


	// Aqui vamos acertar o Timer para casar com a Freq de amostragem desejada
	(*htimer).Init.Period = (FREQ_APB / freq_int) -1; //dica em: https://youtu.be/acJ_kSEU0V0?t=764 cuidado para não ser maior que 16bits!
	if (HAL_TIM_Base_Init(htimer) != HAL_OK)
	{
		  Error_Handler();
	}
}

void AcertaTimerParaFs(TIM_HandleTypeDef *htimer)
{


	// Aqui vamos acertar o Timer para casar com a Freq de amostragem desejada
	(*htimer).Init.Period = (FREQ_APB / FREQ_AMOSTRAGEM) -1; //dica em: https://youtu.be/acJ_kSEU0V0?t=764 cuidado para não ser maior que 16bits!
	if (HAL_TIM_Base_Init(htimer) != HAL_OK)
	{
		  Error_Handler();
	}
}

void AcertaTimerParaFs1(TIM_HandleTypeDef *htimer)
{


	// Aqui vamos acertar o Timer para casar com a Freq de amostragem desejada
	(*htimer).Init.Period = (FREQ_APB / FREQ_AMOSTRAGEM_DAC) -1; //dica em: https://youtu.be/acJ_kSEU0V0?t=764 cuidado para não ser maior que 16bits!
	if (HAL_TIM_Base_Init(htimer) != HAL_OK)
	{
		  Error_Handler();
	}
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


void fullADC  (void){

	 //goto saircomhonra1;
	  int k=0;
	  for(int i=(ADC1_BUF_LEN>>1); i<(ADC1_BUF_LEN   ); i=i+(NUM_CHANNELS)){
		  ch0_buffer[k]=(float32_t)(adc1_data_buffer[i]-2048);
		  k++;
	  }
	  k=0;
	  for(int i=(ADC1_BUF_LEN>>1)+1; i<(ADC1_BUF_LEN ); i=i+(NUM_CHANNELS)){
		  ch1_buffer[k]=(float32_t)(adc1_data_buffer[i]-2048);
		  k++;
	  }
	  k=0;
	  for(int i=(ADC1_BUF_LEN>>1)+2; i<(ADC1_BUF_LEN ); i=i+(NUM_CHANNELS)){
		  ch2_buffer[k]=(float32_t)(adc1_data_buffer[i]-2048);
		  k++;
	  }
	  k=0;
	  for(int i=(ADC1_BUF_LEN>>1)+3; i<(ADC1_BUF_LEN   ); i=i+(NUM_CHANNELS)){
		  ch3_buffer[k]=(float32_t)(adc1_data_buffer[i]-2048);
		  k++;
	  }
	  k=0;
	  for(int i=(ADC1_BUF_LEN>>1)+4; i<(ADC1_BUF_LEN ); i=i+(NUM_CHANNELS)){
		  ch4_buffer[k]=(float32_t)(adc1_data_buffer[i]-2048);
		  k++;
	  }
	  k=0;
	  for(int i=(ADC1_BUF_LEN>>1)+5; i<(ADC1_BUF_LEN ); i=i+(NUM_CHANNELS)){
		  ch5_buffer[k]=(float32_t)(adc1_data_buffer[i]-2048);
		  k++;
	  }
	  saircomhonra1:
	flag_hab_processa_full1=1;
	flag_hab_processa_full1=2;
	 extern uint32_t HabCalculos;
	 HabCalculos =1;
}

void halfADC (){
	//goto saircomhonra1;
	  int k=0;
	  for(int i=0; i<(ADC1_BUF_LEN>>1); i=i+(NUM_CHANNELS)){
		  ch0_buffer[k]=(float32_t)(adc1_data_buffer[i]-2048);
		  k++;
	  }
	  k=0;
	  for(int i=1; i<(ADC1_BUF_LEN>>1); i=i+(NUM_CHANNELS)){
		  ch1_buffer[k]=(float32_t)(adc1_data_buffer[i]-2048);
		  k++;
	  }
	  k=0;
	  for(int i=2; i<(ADC1_BUF_LEN>>1); i=i+(NUM_CHANNELS)){
		  ch2_buffer[k]=(float32_t)(adc1_data_buffer[i]-2048);
		  k++;
	  }
	  k=0;
	  for(int i=3; i<(ADC1_BUF_LEN>>1); i=i+(NUM_CHANNELS)){
		  ch3_buffer[k]=(float32_t)(adc1_data_buffer[i]-2048);
		  k++;
	  }
	  k=0;
	  for(int i=4; i<(ADC1_BUF_LEN>>1); i=i+(NUM_CHANNELS)){
		  ch4_buffer[k]=(float32_t)(adc1_data_buffer[i]-2048);
		  k++;
	  }
	  k=0;
	  for(int i=5; i<(ADC1_BUF_LEN>>1); i=i+(NUM_CHANNELS)){
		  ch5_buffer[k]=(float32_t)(adc1_data_buffer[i]-2048);
		  k++;
	  }
    saircomhonra1:
	flag_hab_processa_half1=1;
	flag_hab_processa_half2=1;
	 extern uint32_t HabCalculos;
	 HabCalculos =1;
}


// Called when first half of buffer is filled
void HAL_ADC_ConvHalfCpltCallback(ADC_HandleTypeDef* hadc) {


//if (hadc==&hadc1)
	{
	  if (flag_processando_full1==1)
		  {
			  flag_acavalou=1;
			  //liga LED
		  }
	  else
	  {
		  halfADC ();
			flag_hab_processa_half1=1;
			flag_hab_processa_half2=1;
	  }
	}

	  if (0) //(flag_flushADCbuffers==1)
	  {
		  HabCalculos =0;
		  flag_hab_processa_half1=0;
		  flag_hab_processa_half2=0;
	  }


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

// Called when buffer is completely filled
void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef* hadc) {


		{
		start_cicles= DWT->CYCCNT;

		 cnt_amostras1=cnt_amostras;
		cnt_amostras=0;
		  if (flag_processando_half1==1)
			  {
				  flag_acavalou=1;
				  //liga LED
			  }
		  else
		  {
			   fullADC();
			  flag_hab_processa_full1=1;
			  flag_hab_processa_full2=1;
		  }
		}

		  if (0) //(flag_flushADCbuffers==1)
		  {
			  HabCalculos =0;
			  flag_hab_processa_full1=0;
			  flag_hab_processa_full2=0;
		  }
}

//como usar o OLED : https://controllerstech.com/oled-display-using-i2c-stm32/
void InitOled(void)
{
	SSD1306_Init();  // initialise

	  /// lets print some string

	/*	    SSD1306_GotoXY (0,0);
	    SSD1306_Puts ("HELLO", &Font_11x18, 1);
	    SSD1306_GotoXY (10, 30);
	    SSD1306_Puts ("  WORLD :)", &Font_11x18, 1);
	    SSD1306_UpdateScreen(); //display

	    HAL_Delay (2000);


	    SSD1306_ScrollRight(0,7);  // scroll entire screen
	    HAL_Delay(2000);  // 2 sec

	    SSD1306_ScrollLeft(0,7);  // scroll entire screen
	    HAL_Delay(2000);  // 2 sec

	    SSD1306_Stopscroll();
	    SSD1306_Clear();

	    SSD1306_DrawBitmap(0,0,logo, 128, 64, 1);
	    SSD1306_UpdateScreen();

	    HAL_Delay(2000);

	    SSD1306_ScrollRight(0x00, 0x0f);    // scroll entire screen right

	    HAL_Delay (2000);

	    SSD1306_ScrollLeft(0x00, 0x0f);  // scroll entire screen left

	    HAL_Delay (2000);

	    SSD1306_Scrolldiagright(0x00, 0x0f);  // scroll entire screen diagonal right

	    HAL_Delay (2000);

	    SSD1306_Scrolldiagleft(0x00, 0x0f);  // scroll entire screen diagonal left

	    HAL_Delay (2000);

	    SSD1306_Stopscroll();   // stop scrolling. If not done, screen will keep on scrolling


	    SSD1306_InvertDisplay(1);   // invert the display

	    HAL_Delay(2000);

	    SSD1306_InvertDisplay(0);  // normalize the display
	//

	    HAL_Delay(2000);*/


}

void ADC_DMAError(DMA_HandleTypeDef *hdma){

	   HAL_Delay(2000);
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
  //enable_backup_sram(1);
  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */
  CoreDebug->DEMCR |= CoreDebug_DEMCR_TRCENA_Msk;
  DWT->CYCCNT = 0;
  DWT->CTRL |= DWT_CTRL_CYCCNTENA_Msk;
	 start_cicles= DWT->CYCCNT;

  MX_GPIO_Init();
  MX_TIM12_Init();
  HAL_TIM_Base_Start_IT(&htim12);
  MX_I2C2_Init();
  InitOled();
  HAL_Delay(100);
  TelaTR1(0);
  //HAL_Delay(100);
  //InitOled();


  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_DMA_Init();
  MX_ADC1_Init();
  MX_CRC_Init();
  MX_RTC_Init();

  MX_TIM2_Init();
  MX_TIM4_Init();
  MX_LWIP_Init();
  MX_TIM3_Init();
  MX_I2C2_Init();
  MX_DAC_Init();
  MX_SPI4_Init();
  MX_USART2_UART_Init();
  MX_SPI2_Init();
  MX_TIM5_Init();
  MX_IWDG_Init();
  MX_TIM6_Init();
  MX_TIM12_Init();
  /* USER CODE BEGIN 2 */

  MX_GPIO_Init2( );

  for(int x = 0; x < 10; x++)toogleWDI();

  HAL_NVIC_ClearPendingIRQ(EXTI0_IRQn);
  HAL_NVIC_ClearPendingIRQ(EXTI1_IRQn);
  HAL_NVIC_ClearPendingIRQ(EXTI2_IRQn);
  HAL_NVIC_ClearPendingIRQ(EXTI3_IRQn);
  HAL_NVIC_ClearPendingIRQ(EXTI4_IRQn);
  //HAL_TIM_Base_Stop(&htim12);

#if 0 //PLACA_RELES==SIM


  HAL_GPIO_WritePin(ALARM1_GPIO_Port,ALARM1_Pin, GPIO_PIN_SET);
  HAL_GPIO_WritePin(ALARM2_GPIO_Port,ALARM2_Pin, GPIO_PIN_SET);
  HAL_GPIO_WritePin(ALARM3_GPIO_Port,ALARM3_Pin, GPIO_PIN_SET);


  HAL_GPIO_TogglePin(ALARM1_GPIO_Port,ALARM1_Pin);
  HAL_GPIO_TogglePin(ALARM2_GPIO_Port,ALARM2_Pin);
  HAL_GPIO_TogglePin(ALARM3_GPIO_Port,ALARM3_Pin);


#endif

  WDTFeed();
#ifdef JANELAMENTO_HANNING
  hanning(janela,FFT_LEN,1);
#endif


  MyFFT_Init();
  AcertaTimerParaFreqInterrupcao(&htimINT,100);//timer para contador de silencio
  AcertaTimerParaFreqInterrupcao(&htimFASTINT,7000);// timer para contar pulsos tipo no CP...

  AcertaTimerParaFs(&htimADC);//timer para amostragem
  AcertaTimerParaFs(&htimDAC);//timer para amostragem

  //CriandoSinalParaTestes1(dac1_data_buffer,pSinal,DAC_BUF_LEN);
  //CriandoSinalParaTestes2(dac2_data_buffer,pSinal,DAC_BUF_LEN);

  //
  CriandoSinalBuffREF((uint16_t*)dac1_data_buffer, DAC_BUF_LEN);
  CriandoSinalBuffREF((uint16_t*)dac2_data_buffer, DAC_BUF_LEN);


  int tamanho_do_buffer_ADC=ADC1_BUF_LEN;
  HAL_ADC_Start_DMA(&hadc1, (uint32_t*) adc1_data_buffer, tamanho_do_buffer_ADC);
  HAL_Delay(1);

   //   tamanho_do_buffer_ADC=ADC2_BUF_LEN;
  //HAL_ADC_Start_DMA(&hadc2, (uint32_t*) adc2_data_buffer, tamanho_do_buffer_ADC);
  //HAL_Delay(1);

  #if 0 //(EQUIP_LINHA50==MD_EQUIP)
  int tamanho_do_buffer_DAC=DAC_BUF_LEN;
	  HAL_DAC_Start_DMA(&hdac,DAC_CHANNEL_1,(uint32_t*)dac1_data_buffer,tamanho_do_buffer_DAC,DAC_ALIGN_12B_R);
	  HAL_Delay(1);
	  HAL_DAC_Start_DMA(&hdac,DAC_CHANNEL_2,(uint32_t*)dac2_data_buffer,tamanho_do_buffer_DAC,DAC_ALIGN_12B_R);
	  HAL_Delay(1);
  #endif

  enable_backup_sram(1);


  HAL_TIM_Base_Start(&htimCLK);
  HAL_TIM_Base_Start_IT(&htimINT);
#if ((EQUIP_LINHA50 == MD_EQUIP)||(EQUIP_LINHA50 == CA_EQUIP)||(EQUIP_LINHA50 == CT_EQUIP))

  HAL_TIM_Base_Start(&htimADC);

	#if ((EQUIP_LINHA50 == CA_EQUIP)||(EQUIP_LINHA50 == CT_EQUIP))
  	  	 HAL_TIM_Base_Start_IT(&htimFASTINT);
	#endif
#else

  HAL_TIM_Base_Start_IT(&htimFASTINT);
#endif


 // MX_LWIP_Init();

  //HAL_TIM_Base_Start(&htimDAC); para evitar ficar gerando uma sinal no DAC, vou comentar esta linha...


  /*QUANDO NA FLUKE SE APLICA ANGULOS NEGATIVOS,
O FP DEVE MARCAR POSITIVO NO EQUIPAMENTO
CARACTERIZANDO UM CIRCUITO INDUTIVO, e vice-versa
*/




//InitOled();
//  client = mqtt_client_new();



main1();
	 for (;;) {
 MX_LWIP_Process( );

 WDTFeed();
	 }


  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
   while (1)
  {

	 WDTFeed();

     newCalc();
     extern uint8_t HabResponder;
		if (HabResponder==1)
		{

			extern void ResponderMODBUS(void);
			ResponderMODBUS();
			HabResponder=0;
		}



      MX_LWIP_Process( );

	  if (flag_acavalou==1)
		 {
			 flag_acavalou=0;

		 }

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
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);
  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_LSI|RCC_OSCILLATORTYPE_HSE
                              |RCC_OSCILLATORTYPE_LSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.LSEState = RCC_LSE_ON;
  RCC_OscInitStruct.LSIState = RCC_LSI_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = 4;
  RCC_OscInitStruct.PLL.PLLN = 180;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 7;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Activate the Over-Drive mode
  */
  if (HAL_PWREx_EnableOverDrive() != HAL_OK)
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

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_5) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief ADC1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_ADC1_Init(void)
{

  /* USER CODE BEGIN ADC1_Init 0 */
#if ((EQUIP_LINHA50 == MD_EQUIP)||(EQUIP_LINHA50 == CA_EQUIP)||(EQUIP_LINHA50 == CT_EQUIP))
  /* USER CODE END ADC1_Init 0 */

  ADC_ChannelConfTypeDef sConfig = {0};

  /* USER CODE BEGIN ADC1_Init 1 */

  /* USER CODE END ADC1_Init 1 */
  /** Configure the global features of the ADC (Clock, Resolution, Data Alignment and number of conversion)
  */
  hadc1.Instance = ADC1;
  hadc1.Init.ClockPrescaler = ADC_CLOCK_SYNC_PCLK_DIV8;
  hadc1.Init.Resolution = ADC_RESOLUTION_12B;
  hadc1.Init.ScanConvMode = ENABLE;
  hadc1.Init.ContinuousConvMode = DISABLE;
  hadc1.Init.DiscontinuousConvMode = DISABLE;
  hadc1.Init.ExternalTrigConvEdge = ADC_EXTERNALTRIGCONVEDGE_RISING;
  hadc1.Init.ExternalTrigConv = ADC_EXTERNALTRIGCONV_T3_TRGO;
  hadc1.Init.DataAlign = ADC_DATAALIGN_RIGHT;
  hadc1.Init.NbrOfConversion = 6;
  hadc1.Init.DMAContinuousRequests = ENABLE;
  hadc1.Init.EOCSelection = ADC_EOC_SEQ_CONV;
  if (HAL_ADC_Init(&hadc1) != HAL_OK)
  {
    Error_Handler();
  }
  /** Configure for the selected ADC regular channel its corresponding rank in the sequencer and its sample time.
  */
  sConfig.Channel = ADC_CHANNEL_0;
  sConfig.Rank = 1;
  sConfig.SamplingTime = ADC_SAMPLETIME_144CYCLES;
  if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /** Configure for the selected ADC regular channel its corresponding rank in the sequencer and its sample time.
  */
  sConfig.Channel = ADC_CHANNEL_3;
  sConfig.Rank = 2;
  if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /** Configure for the selected ADC regular channel its corresponding rank in the sequencer and its sample time.
  */
  sConfig.Channel = ADC_CHANNEL_6;
  sConfig.Rank = 3;
  if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /** Configure for the selected ADC regular channel its corresponding rank in the sequencer and its sample time.
  */
  sConfig.Channel = ADC_CHANNEL_8;
  sConfig.Rank = 4;
  if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /** Configure for the selected ADC regular channel its corresponding rank in the sequencer and its sample time.
  */
  sConfig.Channel = ADC_CHANNEL_9;
  sConfig.Rank = 5;
  if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /** Configure for the selected ADC regular channel its corresponding rank in the sequencer and its sample time.
  */
  sConfig.Channel = ADC_CHANNEL_12;
  sConfig.Rank = 6;
  if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN ADC1_Init 2 */
#endif
  /* USER CODE END ADC1_Init 2 */

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
  * @brief DAC Initialization Function
  * @param None
  * @retval None
  */
static void MX_DAC_Init(void)
{

  /* USER CODE BEGIN DAC_Init 0 */
#if ((EQUIP_LINHA50 == MD_EQUIP))

  /* USER CODE END DAC_Init 0 */

  DAC_ChannelConfTypeDef sConfig = {0};

  /* USER CODE BEGIN DAC_Init 1 */

  /* USER CODE END DAC_Init 1 */
  /** DAC Initialization
  */
  hdac.Instance = DAC;
  if (HAL_DAC_Init(&hdac) != HAL_OK)
  {
    Error_Handler();
  }
  /** DAC channel OUT1 config
  */
  sConfig.DAC_Trigger = DAC_TRIGGER_T4_TRGO;
  sConfig.DAC_OutputBuffer = DAC_OUTPUTBUFFER_ENABLE;
  if (HAL_DAC_ConfigChannel(&hdac, &sConfig, DAC_CHANNEL_1) != HAL_OK)
  {
    Error_Handler();
  }
  /** DAC channel OUT2 config
  */
  if (HAL_DAC_ConfigChannel(&hdac, &sConfig, DAC_CHANNEL_2) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN DAC_Init 2 */

#endif
  /* USER CODE END DAC_Init 2 */

}

/**
  * @brief I2C2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_I2C2_Init(void)
{

  /* USER CODE BEGIN I2C2_Init 0 */

  /* USER CODE END I2C2_Init 0 */

  /* USER CODE BEGIN I2C2_Init 1 */

  /* USER CODE END I2C2_Init 1 */
  hi2c2.Instance = I2C2;
  hi2c2.Init.ClockSpeed = 400000;
  hi2c2.Init.DutyCycle = I2C_DUTYCYCLE_2;
  hi2c2.Init.OwnAddress1 = 0;
  hi2c2.Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;
  hi2c2.Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
  hi2c2.Init.OwnAddress2 = 0;
  hi2c2.Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
  hi2c2.Init.NoStretchMode = I2C_NOSTRETCH_DISABLE;
  if (HAL_I2C_Init(&hi2c2) != HAL_OK)
  {
    Error_Handler();
  }
  /** Configure Analogue filter
  */
  if (HAL_I2CEx_ConfigAnalogFilter(&hi2c2, I2C_ANALOGFILTER_ENABLE) != HAL_OK)
  {
    Error_Handler();
  }
  /** Configure Digital filter
  */
  if (HAL_I2CEx_ConfigDigitalFilter(&hi2c2, 0) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN I2C2_Init 2 */

  /* USER CODE END I2C2_Init 2 */

}

/**
  * @brief IWDG Initialization Function
  * @param None
  * @retval None
  */
static void MX_IWDG_Init(void)
{

  /* USER CODE BEGIN IWDG_Init 0 */
#if 1
  /* USER CODE END IWDG_Init 0 */

  /* USER CODE BEGIN IWDG_Init 1 */

  /* USER CODE END IWDG_Init 1 */
  hiwdg.Instance = IWDG;
  hiwdg.Init.Prescaler = IWDG_PRESCALER_64;
  hiwdg.Init.Reload = 2048;
  if (HAL_IWDG_Init(&hiwdg) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN IWDG_Init 2 */
#endif
  /* USER CODE END IWDG_Init 2 */

}

/**
  * @brief RTC Initialization Function
  * @param None
  * @retval None
  */
static void MX_RTC_Init(void)
{

  /* USER CODE BEGIN RTC_Init 0 */

  /* USER CODE END RTC_Init 0 */

  RTC_TimeTypeDef sTime = {0};
  RTC_DateTypeDef sDate = {0};

  /* USER CODE BEGIN RTC_Init 1 */
#if 0
  /* USER CODE END RTC_Init 1 */
  /** Initialize RTC Only
  */
  hrtc.Instance = RTC;
  hrtc.Init.HourFormat = RTC_HOURFORMAT_24;
  hrtc.Init.AsynchPrediv = 127;
  hrtc.Init.SynchPrediv = 255;
  hrtc.Init.OutPut = RTC_OUTPUT_DISABLE;
  hrtc.Init.OutPutPolarity = RTC_OUTPUT_POLARITY_HIGH;
  hrtc.Init.OutPutType = RTC_OUTPUT_TYPE_OPENDRAIN;
  if (HAL_RTC_Init(&hrtc) != HAL_OK)
  {
    Error_Handler();
  }

  /* USER CODE BEGIN Check_RTC_BKUP */
#endif



     //configuracao pra LSE

     hrtc.Instance = RTC;
     hrtc.Init.HourFormat = RTC_HOURFORMAT_24;
     hrtc.Init.AsynchPrediv = 127;
     hrtc.Init.SynchPrediv = 255;
     hrtc.Init.OutPut = RTC_OUTPUT_DISABLE;
     hrtc.Init.OutPutPolarity = RTC_OUTPUT_POLARITY_HIGH;
     hrtc.Init.OutPutType = RTC_OUTPUT_TYPE_OPENDRAIN;

     /*

     // 1. 8Mhz oscillator (Source crystal! Not after PLL!) div by 8 = 1 Mhz
     __HAL_RCC_RTC_CONFIG(RCC_RTCCLKSOURCE_HSE_DIV8);
     hrtc.Instance = RTC;
     hrtc.Init.HourFormat = RTC_HOURFORMAT_24;
     // 2. (1 Mhz / 125) = 7999 ticks per second
     hrtc.Init.AsynchPrediv = 125 - 1;
     hrtc.Init.SynchPrediv = 8000 - 1;
     hrtc.Init.OutPut = RTC_OUTPUT_DISABLE;
     hrtc.Init.OutPutPolarity = RTC_OUTPUT_POLARITY_HIGH;
     hrtc.Init.OutPutType = RTC_OUTPUT_TYPE_OPENDRAIN;

*/


  sTime.Hours = 9;
  sTime.Minutes = 39;
  sTime.Seconds = 0x0;
  sTime.DayLightSaving = RTC_DAYLIGHTSAVING_NONE;
  sTime.StoreOperation = RTC_STOREOPERATION_RESET;

  sDate.WeekDay = RTC_WEEKDAY_TUESDAY;
  sDate.Month = RTC_MONTH_MAY;
  sDate.Date = 10;
  sDate.Year = 22;

  // HAL_RTCEx_DeactivateCoarseCalib(&hrtc);
  // HAL_RTC_Init(&hrtc);
  // HAL_RTCEx_SetCoarseCalib(&hrtc,RTC_CALIBSIGN_POSITIVE,0);
  // HAL_RTC_Init(&hrtc) ;
  // HAL_RTCEx_BKUPWrite(&hrtc,RTC_BKP_DR0,0x32d2);
  // HAL_RTCEx_SetCoarseCalib(&hrtc,RTC_CALIBSIGN_POSITIVE,0);


 // int cal= no range de -512 até 512 cada um significando  0.954 ppm ()
  //cada "bin" de calibração corresponde a 0.0824segundos por dia de correção.
 //ex. 5 segundos de drift por dia, corresponde a 5/0.0824=61bins
  //ex 1 segundo de drift por dica, corresponde a 1/0.0824=12bins
//int cal=205; valor correto para calibrar quando o aparelho está desligagdo
 // int cal=205-60; //deu drift de aprox 1segundo pra traz

  HAL_RTCEx_DeactivateCoarseCalib(&hrtc);

  int cal = -43 ; // calibrado em abril de 2025
  	  	  	  	  // 1.19

  uint32_t cal_p, cal_m;

  if (cal > 0) {
      cal_p = RTC_SMOOTHCALIB_PLUSPULSES_SET;
      cal_m = 512 - cal;
  } else {
      cal_p = RTC_SMOOTHCALIB_PLUSPULSES_RESET;
      cal_m = (uint32_t)(-1 * cal);
  }

  HAL_RTCEx_SetSmoothCalib(&hrtc, RTC_SMOOTHCALIB_PERIOD_32SEC, cal_p, cal_m);

 //HAL_RTC_Init(&hrtc) ;

  //HAL_RTCEx_SetSmoothCalib(&hrtc, RTC_SMOOTHCALIB_PERIOD_32SEC, cal_p, cal_m);



  /* Disable the write protection for RTC registers */
  //__HAL_RTC_WRITEPROTECTION_DISABLE(&hrtc);

  /*Wait until the RTC Time and Date registers are synchronized with RTC APB clock*/
//   HAL_RTC_WaitForSynchro(&hrtc);

  /* Enable the write protection for RTC registers */
 // __HAL_RTC_WRITEPROTECTION_ENABLE(&hrtc);
  //__HAL_RTC_CALIBRATION_OUTPUT_ENABLE(&hrtc);

  #define KEY 0x32FE

  if(HAL_RTCEx_BKUPRead(&hrtc, RTC_BKP_DR0) != KEY){
	  if (HAL_RTC_Init(&hrtc) != HAL_OK)
	  {
	    Error_Handler();
	  }

	  if (HAL_RTC_SetDate(&hrtc, &sDate, RTC_FORMAT_BIN) != HAL_OK)
	  {
	    Error_Handler();
	  }
	  if (HAL_RTC_SetTime(&hrtc, &sTime, RTC_FORMAT_BIN) != HAL_OK)
	  {
	    Error_Handler();
	  }
	  //HAL_RTCEx_SetCoarseCalib(&hrtc,RTC_CALIBSIGN_POSITIVE,15);
      HAL_RTCEx_BKUPWrite(&hrtc,RTC_BKP_DR0, KEY);
    }





#if 0
  /* USER CODE END Check_RTC_BKUP */

  /** Initialize RTC and set the Time and Date
  */
  sTime.Hours = 0;
  sTime.Minutes = 0;
  sTime.Seconds = 0;
  sTime.DayLightSaving = RTC_DAYLIGHTSAVING_NONE;
  sTime.StoreOperation = RTC_STOREOPERATION_RESET;
  if (HAL_RTC_SetTime(&hrtc, &sTime, RTC_FORMAT_BIN) != HAL_OK)
  {
    Error_Handler();
  }
  sDate.WeekDay = RTC_WEEKDAY_MONDAY;
  sDate.Month = RTC_MONTH_JANUARY;
  sDate.Date = 1;
  sDate.Year = 0;

  if (HAL_RTC_SetDate(&hrtc, &sDate, RTC_FORMAT_BIN) != HAL_OK)
  {
    Error_Handler();
  }

#endif


  /* USER CODE BEGIN RTC_Init 2 */

  /** Enable Calibrartion

  if (HAL_RTCEx_SetCalibrationOutPut(&hrtc, RTC_CALIBOUTPUT_512HZ) != HAL_OK)
  {
    Error_Handler();
  }
   */






  /* USER CODE END RTC_Init 2 */

}

/**
  * @brief SPI2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_SPI2_Init(void)
{

  /* USER CODE BEGIN SPI2_Init 0 */

  /* USER CODE END SPI2_Init 0 */

  /* USER CODE BEGIN SPI2_Init 1 */

  /* USER CODE END SPI2_Init 1 */
  /* SPI2 parameter configuration*/
  hspi2.Instance = SPI2;
  hspi2.Init.Mode = SPI_MODE_MASTER;
  hspi2.Init.Direction = SPI_DIRECTION_1LINE;
  hspi2.Init.DataSize = SPI_DATASIZE_8BIT;
  hspi2.Init.CLKPolarity = SPI_POLARITY_LOW;
  hspi2.Init.CLKPhase = SPI_PHASE_1EDGE;
  hspi2.Init.NSS = SPI_NSS_SOFT;
  hspi2.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_2;
  hspi2.Init.FirstBit = SPI_FIRSTBIT_MSB;
  hspi2.Init.TIMode = SPI_TIMODE_DISABLE;
  hspi2.Init.CRCCalculation = SPI_CRCCALCULATION_DISABLE;
  hspi2.Init.CRCPolynomial = 10;
  if (HAL_SPI_Init(&hspi2) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN SPI2_Init 2 */

  /* USER CODE END SPI2_Init 2 */

}

/**
  * @brief SPI4 Initialization Function
  * @param None
  * @retval None
  */
static void MX_SPI4_Init(void)
{

  /* USER CODE BEGIN SPI4_Init 0 */

  /* USER CODE END SPI4_Init 0 */

  /* USER CODE BEGIN SPI4_Init 1 */

  /* USER CODE END SPI4_Init 1 */
  /* SPI4 parameter configuration*/
  hspi4.Instance = SPI4;
  hspi4.Init.Mode = SPI_MODE_MASTER;
  hspi4.Init.Direction = SPI_DIRECTION_1LINE;
  hspi4.Init.DataSize = SPI_DATASIZE_8BIT;
  hspi4.Init.CLKPolarity = SPI_POLARITY_LOW;
  hspi4.Init.CLKPhase = SPI_PHASE_1EDGE;
  hspi4.Init.NSS = SPI_NSS_SOFT;
  hspi4.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_2;
  hspi4.Init.FirstBit = SPI_FIRSTBIT_MSB;
  hspi4.Init.TIMode = SPI_TIMODE_DISABLE;
  hspi4.Init.CRCCalculation = SPI_CRCCALCULATION_DISABLE;
  hspi4.Init.CRCPolynomial = 10;
  if (HAL_SPI_Init(&hspi4) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN SPI4_Init 2 */

  /* USER CODE END SPI4_Init 2 */

}

/**
  * @brief TIM2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM2_Init(void)
{

  /* USER CODE BEGIN TIM2_Init 0 */

  /* USER CODE END TIM2_Init 0 */

  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};

  /* USER CODE BEGIN TIM2_Init 1 */

  /* USER CODE END TIM2_Init 1 */
  htim2.Instance = TIM2;
  htim2.Init.Prescaler = 0;
  htim2.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim2.Init.Period = 4294967295;
  htim2.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim2.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_ENABLE;
  if (HAL_TIM_Base_Init(&htim2) != HAL_OK)
  {
    Error_Handler();
  }
  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim2, &sClockSourceConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_UPDATE;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim2, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM2_Init 2 */

  /* USER CODE END TIM2_Init 2 */

}

/**
  * @brief TIM3 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM3_Init(void)
{

  /* USER CODE BEGIN TIM3_Init 0 */

  /* USER CODE END TIM3_Init 0 */

  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};

  /* USER CODE BEGIN TIM3_Init 1 */

  /* USER CODE END TIM3_Init 1 */
  htim3.Instance = TIM3;
  htim3.Init.Prescaler = 0;
  htim3.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim3.Init.Period = 65535;
  htim3.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim3.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_ENABLE;
  if (HAL_TIM_Base_Init(&htim3) != HAL_OK)
  {
    Error_Handler();
  }
  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim3, &sClockSourceConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_UPDATE;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim3, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM3_Init 2 */

  /* USER CODE END TIM3_Init 2 */

}

/**
  * @brief TIM4 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM4_Init(void)
{

  /* USER CODE BEGIN TIM4_Init 0 */

  /* USER CODE END TIM4_Init 0 */

  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};

  /* USER CODE BEGIN TIM4_Init 1 */

  /* USER CODE END TIM4_Init 1 */
  htim4.Instance = TIM4;
  htim4.Init.Prescaler = 0;
  htim4.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim4.Init.Period = 65535;
  htim4.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim4.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_ENABLE;
  if (HAL_TIM_Base_Init(&htim4) != HAL_OK)
  {
    Error_Handler();
  }
  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim4, &sClockSourceConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_UPDATE;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim4, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM4_Init 2 */

  /* USER CODE END TIM4_Init 2 */

}

/**
  * @brief TIM5 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM5_Init(void)
{

  /* USER CODE BEGIN TIM5_Init 0 */

  /* USER CODE END TIM5_Init 0 */

  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};

  /* USER CODE BEGIN TIM5_Init 1 */

  /* USER CODE END TIM5_Init 1 */
  htim5.Instance = TIM5;
  htim5.Init.Prescaler = 0;
  htim5.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim5.Init.Period = 4294967295;
  htim5.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim5.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_ENABLE;
  if (HAL_TIM_Base_Init(&htim5) != HAL_OK)
  {
    Error_Handler();
  }
  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim5, &sClockSourceConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_UPDATE;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim5, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM5_Init 2 */

  /* USER CODE END TIM5_Init 2 */

}

/**
  * @brief TIM6 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM6_Init(void)
{

  /* USER CODE BEGIN TIM6_Init 0 */

  /* USER CODE END TIM6_Init 0 */

  TIM_MasterConfigTypeDef sMasterConfig = {0};

  /* USER CODE BEGIN TIM6_Init 1 */

  /* USER CODE END TIM6_Init 1 */
  htim6.Instance = TIM6;
  htim6.Init.Prescaler = 0;
  htim6.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim6.Init.Period = 65535;
  htim6.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_ENABLE;
  if (HAL_TIM_Base_Init(&htim6) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_UPDATE;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim6, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM6_Init 2 */

  /* USER CODE END TIM6_Init 2 */

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
  * @brief USART2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_USART2_UART_Init(void)
{

  /* USER CODE BEGIN USART2_Init 0 */

  /* USER CODE END USART2_Init 0 */

  /* USER CODE BEGIN USART2_Init 1 */

  /* USER CODE END USART2_Init 1 */
  huart2.Instance = USART2;
  huart2.Init.BaudRate = 115200;
  huart2.Init.WordLength = UART_WORDLENGTH_8B;
  huart2.Init.StopBits = UART_STOPBITS_1;
  huart2.Init.Parity = UART_PARITY_NONE;
  huart2.Init.Mode = UART_MODE_TX_RX;
  huart2.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart2.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart2) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART2_Init 2 */

  /* USER CODE END USART2_Init 2 */

}

/**
  * Enable DMA controller clock
  */
static void MX_DMA_Init(void)
{

  /* DMA controller clock enable */
  __HAL_RCC_DMA2_CLK_ENABLE();
  __HAL_RCC_DMA1_CLK_ENABLE();

  /* DMA interrupt init */
  /* DMA1_Stream5_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(DMA1_Stream5_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(DMA1_Stream5_IRQn);
  /* DMA1_Stream6_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(DMA1_Stream6_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(DMA1_Stream6_IRQn);
  /* DMA2_Stream0_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(DMA2_Stream0_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(DMA2_Stream0_IRQn);

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
  __HAL_RCC_GPIOB_CLK_ENABLE();
  __HAL_RCC_GPIOD_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOI_CLK_ENABLE();
  __HAL_RCC_GPIOE_CLK_ENABLE();
  __HAL_RCC_GPIOH_CLK_ENABLE();
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOG_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOD, AUXOUT3_Pin|TOUCH_RESET_Pin|ALARM1_Pin|DPY7_Pin
                          |DPY6_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, AUXOUT2_Pin|AUXOUT1_Pin|TCL5_Pin|DPY5_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOH, RS_HAB_SERV_Pin|DPY3_Pin|DPY4_Pin|DPY2_Pin
                          |DPY1_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(DPY_RS_GPIO_Port, DPY_RS_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(LED_PWR_GPIO_Port, LED_PWR_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(DPY0_GPIO_Port, DPY0_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(WDI_GPIO_Port, WDI_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : AUXOUT3_Pin TOUCH_RESET_Pin ALARM1_Pin DPY7_Pin
                           DPY6_Pin */
  GPIO_InitStruct.Pin = AUXOUT3_Pin|TOUCH_RESET_Pin|ALARM1_Pin|DPY7_Pin
                          |DPY6_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);

  /*Configure GPIO pin : TOUCH_INT_Pin */
  GPIO_InitStruct.Pin = TOUCH_INT_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_RISING;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(TOUCH_INT_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : TCL4_Pin */
  GPIO_InitStruct.Pin = TCL4_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(TCL4_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pins : AUXOUT2_Pin AUXOUT1_Pin TCL5_Pin DPY5_Pin */
  GPIO_InitStruct.Pin = AUXOUT2_Pin|AUXOUT1_Pin|TCL5_Pin|DPY5_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

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

  /*Configure GPIO pins : RS_HAB_SERV_Pin DPY3_Pin DPY4_Pin DPY2_Pin
                           DPY1_Pin */
  GPIO_InitStruct.Pin = RS_HAB_SERV_Pin|DPY3_Pin|DPY4_Pin|DPY2_Pin
                          |DPY1_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOH, &GPIO_InitStruct);

  /*Configure GPIO pin : TCL6_Pin */
  GPIO_InitStruct.Pin = TCL6_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(TCL6_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : USB_OTG_VBUS_Pin */
  GPIO_InitStruct.Pin = USB_OTG_VBUS_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(USB_OTG_VBUS_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : DPY_RS_Pin */
  GPIO_InitStruct.Pin = DPY_RS_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(DPY_RS_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : LED_PWR_Pin */
  GPIO_InitStruct.Pin = LED_PWR_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(LED_PWR_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : DPY0_Pin */
  GPIO_InitStruct.Pin = DPY0_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(DPY0_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : WDI_Pin */
  GPIO_InitStruct.Pin = WDI_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(WDI_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : PWD_Pin */
  GPIO_InitStruct.Pin = PWD_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_FALLING;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(PWD_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : ETH_RMII_ERR_Pin */
  GPIO_InitStruct.Pin = ETH_RMII_ERR_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_RISING;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(ETH_RMII_ERR_GPIO_Port, &GPIO_InitStruct);

  /* EXTI interrupt init*/
  HAL_NVIC_SetPriority(EXTI2_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(EXTI2_IRQn);

}

/* USER CODE BEGIN 4 */
void MX_GPIO_Init2(void)
{
#if ((EQUIP_LINHA50 != MD_EQUIP))
	  GPIO_InitTypeDef GPIO_InitStruct = {0};

	  GPIO_InitStruct.Pin = ALARM2_Pin|ALARM3_Pin;
	  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	  GPIO_InitStruct.Pull = GPIO_NOPULL;
	  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

	  GPIO_InitStruct.Pin = ALARM1_Pin;
	  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	  GPIO_InitStruct.Pull = GPIO_NOPULL;
	  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	  HAL_GPIO_Init(ALARM1_GPIO_Port, &GPIO_InitStruct);

#endif

#if (0)

	  GPIO_InitTypeDef GPIO_InitStruct = {0};

	  GPIO_InitStruct.Pin = ADC1P_Pin|ADC2P_Pin|ADC3P_Pin|DAC_OUT1_Pin|DAC_OUT2_Pin;
	  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
	  GPIO_InitStruct.Pull = GPIO_NOPULL;
	  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

	  GPIO_InitStruct.Pin = ADC4P_Pin|ADC5P_Pin ;
	  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
	  GPIO_InitStruct.Pull = GPIO_NOPULL;
	  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

	  GPIO_InitStruct.Pin = ADC6P_Pin ;
	  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
	  GPIO_InitStruct.Pull = GPIO_NOPULL;
	  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

	  GPIO_InitStruct.Pin = ALARM1_Pin;
	  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
	  GPIO_InitStruct.Pull = GPIO_NOPULL;
	  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
	  HAL_GPIO_Init(ALARM1_GPIO_Port, &GPIO_InitStruct);

#endif

}
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

	//  forceReset();    //se entra aqui, forçamos o reset, para não ficar travado!

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
