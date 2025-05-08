/**
 ******************************************************************************
  * File Name          : LWIP.c
  * Description        : This file provides initialization code for LWIP
  *                      middleWare.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2022 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under Ultimate Liberty license
  * SLA0044, the "License"; You may not use this file except in compliance with
  * the License. You may obtain a copy of the License at:
  *                             www.st.com/SLA0044
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "lwip.h"
#include "lwip/init.h"
#include "lwip/netif.h"
#if defined ( __CC_ARM )  /* MDK ARM Compiler */
#include "lwip/sio.h"
#endif /* MDK ARM Compiler */
#include "ethernetif.h"

/* USER CODE BEGIN 0 */
#define EXT extern
#include <..\Port\global.h>
/* USER CODE END 0 */
/* Private function prototypes -----------------------------------------------*/
/* ETH Variables initialization ----------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN 1 */

/* USER CODE END 1 */

/* Variables Initialization */
struct netif gnetif;
ip4_addr_t ipaddr;
ip4_addr_t netmask;
ip4_addr_t gw;
uint8_t IP_ADDRESS[4];
uint8_t NETMASK_ADDRESS[4];
uint8_t GATEWAY_ADDRESS[4];

/* USER CODE BEGIN 2 */
void change_ip(void)
{
extern uint16_t get_port(void);

uint16_t porta_atual=get_port();

if (porta_atual==0xFFFF)
{

	porta_atual=NroPorta;
	NroPorta2=NroPorta;
	// Aqui você grava a porta atual na BattRam2
	 BattRam2.buffer[12] = (int)porta_atual;
}


if ((NroPorta!=porta_atual)||(IP_ADDRESS[0]!=ip_config.IpAdr[0])||(IP_ADDRESS[1]!=ip_config.IpAdr[1])
		||(IP_ADDRESS[2]!=ip_config.IpAdr[2])
		||(IP_ADDRESS[3]!=ip_config.IpAdr[3])
		||(NETMASK_ADDRESS[0]!=ip_config.NetMask[0])
		||(NETMASK_ADDRESS[1]!=ip_config.NetMask[1])
		||(NETMASK_ADDRESS[2]!=ip_config.NetMask[2])
		||(NETMASK_ADDRESS[3]!=ip_config.NetMask[3])
		||(GATEWAY_ADDRESS[0]!=ip_config.DefGW[0])
		||(GATEWAY_ADDRESS[1]!=ip_config.DefGW[1])
		||(GATEWAY_ADDRESS[2]!=ip_config.DefGW[2])
		||(GATEWAY_ADDRESS[3]!=ip_config.DefGW[3])



)

	{
		IP_ADDRESS[0] 	   = ip_config.IpAdr[0];
		IP_ADDRESS[1]	   = ip_config.IpAdr[1];
		IP_ADDRESS[2]	   = ip_config.IpAdr[2];
		IP_ADDRESS[3]	   = ip_config.IpAdr[3];
		NETMASK_ADDRESS[0] = ip_config.NetMask[0];
		NETMASK_ADDRESS[1] = ip_config.NetMask[1];
		NETMASK_ADDRESS[2] = ip_config.NetMask[2];
		NETMASK_ADDRESS[3] = ip_config.NetMask[3];
		GATEWAY_ADDRESS[0] = ip_config.DefGW[0];
		GATEWAY_ADDRESS[1] = ip_config.DefGW[1];
		GATEWAY_ADDRESS[2] = ip_config.DefGW[2];
		GATEWAY_ADDRESS[3] = ip_config.DefGW[3];
		NroPorta2 = NroPorta;


		  for (int i=0;i<4;i++)
		  BattRam2.buffer[i] =IP_ADDRESS[i];
		  for (int i=0;i<4;i++)
		  BattRam2.buffer[i+4] =NETMASK_ADDRESS[i];
		  for (int i=0;i<4;i++)
		  BattRam2.buffer[i+8] =GATEWAY_ADDRESS[i];

		  BattRam2.buffer[12] =NroPorta2;


	IP4_ADDR(&ipaddr, IP_ADDRESS[0], IP_ADDRESS[1], IP_ADDRESS[2], IP_ADDRESS[3]);
	IP4_ADDR(&netmask, NETMASK_ADDRESS[0], NETMASK_ADDRESS[1] , NETMASK_ADDRESS[2], NETMASK_ADDRESS[3]);
	IP4_ADDR(&gw, GATEWAY_ADDRESS[0], GATEWAY_ADDRESS[1], GATEWAY_ADDRESS[2], GATEWAY_ADDRESS[3]);




	netif_set_ipaddr(&gnetif,&ipaddr);
	netif_set_netmask(&gnetif,&netmask);
	netif_set_gw(&gnetif,&gw);


	extern void udp_echoserver_init(uint16_t PORTA_);
	udp_echoserver_init(NroPorta);

	extern void tcp_echoserver_init(uint16_t PORTA_);
	tcp_echoserver_init(NroPorta);

	}

}
/* USER CODE END 2 */

/**
  * LwIP initialization function
  */
void MX_LWIP_Init(void)
{
  /* IP addresses initialization */
  IP_ADDRESS[0] = 10;
  IP_ADDRESS[1] = 1;
  IP_ADDRESS[2] = 25;
  IP_ADDRESS[3] = 123;
  NETMASK_ADDRESS[0] = 255;
  NETMASK_ADDRESS[1] = 255;
  NETMASK_ADDRESS[2] = 255;
  NETMASK_ADDRESS[3] = 0;
  GATEWAY_ADDRESS[0] = 10;
  GATEWAY_ADDRESS[1] = 1;
  GATEWAY_ADDRESS[2] = 25;
  GATEWAY_ADDRESS[3] = 1;

/* USER CODE BEGIN IP_ADDRESSES */
  IP_ADDRESS[0] = 10;
  IP_ADDRESS[1] = 1;
  IP_ADDRESS[2] = 25;
  IP_ADDRESS[3] = 123;
  NETMASK_ADDRESS[0] = 255;
  NETMASK_ADDRESS[1] = 255;
  NETMASK_ADDRESS[2] = 255;
  NETMASK_ADDRESS[3] = 0;
  GATEWAY_ADDRESS[0] = 10;
  GATEWAY_ADDRESS[1] = 1;
  GATEWAY_ADDRESS[2] = 25;
  GATEWAY_ADDRESS[3] = 1;

  HAL_GPIO_TogglePin( WDI_GPIO_Port,WDI_Pin);  //WDI
/* USER CODE END IP_ADDRESSES */

  /* Initilialize the LwIP stack without RTOS */
  lwip_init();

  /* IP addresses initialization without DHCP (IPv4) */
  IP4_ADDR(&ipaddr, IP_ADDRESS[0], IP_ADDRESS[1], IP_ADDRESS[2], IP_ADDRESS[3]);
  IP4_ADDR(&netmask, NETMASK_ADDRESS[0], NETMASK_ADDRESS[1] , NETMASK_ADDRESS[2], NETMASK_ADDRESS[3]);
  IP4_ADDR(&gw, GATEWAY_ADDRESS[0], GATEWAY_ADDRESS[1], GATEWAY_ADDRESS[2], GATEWAY_ADDRESS[3]);

  /* add the network interface (IPv4/IPv6) without RTOS */
  netif_add(&gnetif, &ipaddr, &netmask, &gw, NULL, &ethernetif_init, &ethernet_input);

  /* Registers the default network interface */
  netif_set_default(&gnetif);

  if (netif_is_link_up(&gnetif))
  {
    /* When the netif is fully configured this function must be called */
    netif_set_up(&gnetif);
  }
  else
  {
    /* When the netif link is down this function must be called */
    netif_set_down(&gnetif);
  }

  /* Set the link callback function, this function is called on change of link status*/
  netif_set_link_callback(&gnetif, ethernetif_update_config);

  /* Create the Ethernet link handler thread */

/* USER CODE BEGIN 3 */
  HAL_GPIO_TogglePin( WDI_GPIO_Port,WDI_Pin);  //WDI


/* USER CODE END 3 */
}

#ifdef USE_OBSOLETE_USER_CODE_SECTION_4
/* Kept to help code migration. (See new 4_1, 4_2... sections) */
/* Avoid to use this user section which will become obsolete. */
/* USER CODE BEGIN 4 */
/* USER CODE END 4 */
#endif

/**
 * ----------------------------------------------------------------------
 * Function given to help user to continue LwIP Initialization
 * Up to user to complete or change this function ...
 * Up to user to call this function in main.c in while (1) of main(void)
 *-----------------------------------------------------------------------
 * Read a received packet from the Ethernet buffers
 * Send it to the lwIP stack for handling
 * Handle timeouts if LWIP_TIMERS is set and without RTOS
 * Handle the llink status if LWIP_NETIF_LINK_CALLBACK is set and without RTOS
 */
void MX_LWIP_Process(void)
{
/* USER CODE BEGIN 4_1 */
/* USER CODE END 4_1 */
  ethernetif_input(&gnetif);

/* USER CODE BEGIN 4_2 */
/* USER CODE END 4_2 */
  /* Handle timeouts */
  sys_check_timeouts();

/* USER CODE BEGIN 4_3 */

//o trecho a seguir cuida para iniciar a interface ethernet, nos casos de power up sem cabo rj45 conectado.

  uint32_t phyBSR = 0;
  	HAL_ETH_ReadPHYRegister(&heth, PHY_BSR, &phyBSR);
  	if ((phyBSR & PHY_LINKED_STATUS) != PHY_LINKED_STATUS) {


  	} else {
  		if (!netif_is_link_up(&gnetif)) {
  			HAL_ETH_ReadPHYRegister(&heth, PHY_BSR, &phyBSR);
  			// When system initializes w/o Ethernet cable plugged in, PHY_LINKED_STATUS is down.
  			// lwip.c MX_LWIP_Init calls netif_add, eventually calls thernetif.c low_level_init.
  			// In there the call to HAL_ETH_Init times out because PHY_LINKED_STATUS is down.
  			// This causes NETIF_FLAG_LINK_UP not set. Back in MX_LWIP_Init netif_set_down is called
  			// so NETIF_FLAG_LINK_UP is down. Following that dhcp_start fails.
  			//
  			// When the Ethernet cable is reconnected the first time we enter the following block where
  			// we need to bring up netif and start DHCP.
  			//
  			// Subsequent Ethernet dis/re-connect will not come here since NETIF_FLAG_LINK_UP is already set.
  			if ((phyBSR & PHY_LINKED_STATUS) == PHY_LINKED_STATUS
  					&& !netif_is_link_up(&gnetif)) {
  				// Recover network at first reconnect after system bootup
  				// 1. set NETIF_FLAG_LINK_UP. This is needed by netif_set_up. Since this is first reconnect,
  				// DHCP has not started yet. We cannot call netif_set_link_up() because it assumes DHCP is up.
  				gnetif.flags |= NETIF_FLAG_LINK_UP;
  				// 2. set NETIF_FLAG_UP
  				netif_set_up(&gnetif);

		}
  		}
  	}



/* USER CODE END 4_3 */
}

#if defined ( __CC_ARM )  /* MDK ARM Compiler */
/**
 * Opens a serial device for communication.
 *
 * @param devnum device number
 * @return handle to serial device if successful, NULL otherwise
 */
sio_fd_t sio_open(u8_t devnum)
{
  sio_fd_t sd;

/* USER CODE BEGIN 7 */
  sd = 0; // dummy code
/* USER CODE END 7 */

  return sd;
}

/**
 * Sends a single character to the serial device.
 *
 * @param c character to send
 * @param fd serial device handle
 *
 * @note This function will block until the character can be sent.
 */
void sio_send(u8_t c, sio_fd_t fd)
{
/* USER CODE BEGIN 8 */
/* USER CODE END 8 */
}

/**
 * Reads from the serial device.
 *
 * @param fd serial device handle
 * @param data pointer to data buffer for receiving
 * @param len maximum length (in bytes) of data to receive
 * @return number of bytes actually received - may be 0 if aborted by sio_read_abort
 *
 * @note This function will block until data can be received. The blocking
 * can be cancelled by calling sio_read_abort().
 */
u32_t sio_read(sio_fd_t fd, u8_t *data, u32_t len)
{
  u32_t recved_bytes;

/* USER CODE BEGIN 9 */
  recved_bytes = 0; // dummy code
/* USER CODE END 9 */
  return recved_bytes;
}

/**
 * Tries to read from the serial device. Same as sio_read but returns
 * immediately if no data is available and never blocks.
 *
 * @param fd serial device handle
 * @param data pointer to data buffer for receiving
 * @param len maximum length (in bytes) of data to receive
 * @return number of bytes actually received
 */
u32_t sio_tryread(sio_fd_t fd, u8_t *data, u32_t len)
{
  u32_t recved_bytes;

/* USER CODE BEGIN 10 */
  recved_bytes = 0; // dummy code
/* USER CODE END 10 */
  return recved_bytes;
}
#endif /* MDK ARM Compiler */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
