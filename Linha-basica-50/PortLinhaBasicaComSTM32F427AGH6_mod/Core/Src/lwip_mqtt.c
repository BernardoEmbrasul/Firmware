#include "lwip/apps/mqtt.h"
#include <string.h>
#include "stm32f4xx_hal.h"
#include <stdio.h>
#include <stdlib.h>
#define EXT extern
#include "..\Port\global.h"			  /* Relativos a variaves globais*/
//extern UART_HandleTypeDef huart3;
char buffer[1000];



// Função para converter um byte em hexadecimal
void byteToHex(unsigned char byte, char *hex) {
    static const char hexChars[] = "0123456789ABCDEF";
    hex[0] = hexChars[(byte >> 4) & 0x0F];
    hex[1] = hexChars[byte & 0x0F];
    hex[2] = '\0';
}

// Função para processar um vetor de bytes e retornar uma string em hexadecimal
//char *processBytes(const unsigned char *input, size_t inputSize,char *output) {
char *processBytes(const unsigned char *input, size_t inputSize) {
    char *output = (char *)malloc(inputSize * 2 + 1);

    for (size_t i = 0; i < inputSize; i++) {
        byteToHex(input[i], output + i * 2);
    }



    return output;
}

// Função para converter um par de dígitos em hexadecimal para um byte
unsigned char hexToByte(char c1, char c2) {
    unsigned char result = 0;

    if (c1 >= '0' && c1 <= '9') {
        result = (c1 - '0') << 4;
    } else if (c1 >= 'A' && c1 <= 'F') {
        result = (c1 - 'A' + 10) << 4;
    }

    if (c2 >= '0' && c2 <= '9') {
        result |= c2 - '0';
    } else if (c2 >= 'A' && c2 <= 'F') {
        result |= c2 - 'A' + 10;
    }

    return result;
}

// Função para processar a string e retornar um vetor de bytes em hexadecimal
unsigned char *processString(const char *input, size_t *outputSize, char *output) {
    size_t inputLength = strlen(input);
    if (inputLength % 2 != 0) {
        //printf("A entrada deve ter um número par de caracteres.\n");
        return NULL;
    }

    *outputSize = inputLength / 2;
    //unsigned char *output = (unsigned char *)malloc(*outputSize);

    for (size_t i = 0; i < inputLength; i += 2) {
        output[i / 2] = hexToByte(input[i], input[i + 1]);
    }

    return output;
}




/* The idea is to demultiplex topic and create some reference to be used in data callbacks
   Example here uses a global variable, better would be to use a member in arg
   If RAM and CPU budget allows it, the easiest implementation might be to just take a copy of
   the topic string and use it in mqtt_incoming_data_cb
*/
static int inpub_id;
static void mqtt_incoming_publish_cb(void *arg, const char *topic, u32_t tot_len)
{
  //sprintf(buffer,"Incoming publish at topic %s with total length %u\n\r", topic, (unsigned int)tot_len);
//HAL_UART_Transmit(&huart3,buffer,strlen(buffer),1000);
  /* Decode topic string into a user defined reference */
  if(strcmp(topic, "print_payload") == 0) {
    inpub_id = 0;
  } else if(topic[0] == 'A') {
    /* All topics starting with 'A' might be handled at the same way */
    inpub_id = 1;
  }
  else {
    /* For all other topics */
    inpub_id = 9;
  }
  inpub_id = 0;
}

static void mqtt_incoming_data_cb(void *arg, const u8_t *data, u16_t len, u8_t flags)
{
//	  sprintf(buffer,"Incoming publish payload with length %d, flags %u\n\r", len, (unsigned int)flags);
	  //HAL_UART_Transmit(&huart3,buffer,strlen(buffer),1000);

  if(flags & MQTT_DATA_FLAG_LAST) {
    /* Last fragment of payload received (or whole part if payload fits receive buffer
       See MQTT_VAR_HEADER_BUFFER_LEN)  */

    /* Call function or do action depending on reference, in this case inpub_id */
    if(inpub_id == 0) {


//		sprintf(buffer,"%s\n\r", (const char *)data);
//		HAL_UART_Transmit(&huart3,buffer,len,1000);

    	//extern char *UART0Buffer;
		extern char recebido_mqtt;
	    size_t outputSize;
	    extern uint8_t HabResponder;
	    extern void modbus_message_received(uint8_t *buf, int len);

	    processString(data, &outputSize,UART0Buffer);
	    recebido_mqtt=1;
	    modbus_message_received(UART0Buffer,outputSize);




    	/* Don't trust the publisher, check zero termination */
    	/*
    	if((data[len-1]== 0)||(data[len]==0)) {
    		sprintf(buffer,"mqtt_incoming_data_cb: %s\n\r", (const char *)data);
    		HAL_UART_Transmit(&huart3,buffer,strlen(buffer),1000);
         }
    	 else {
    	 sprintf(buffer,"mqtt_incoming_data_cb: but some fail...\n\r");
	 	 HAL_UART_Transmit(&huart3,buffer,strlen(buffer),1000);}
	 	 */
	}
    else
    {
    	//sprintf(buffer,"mqtt_incoming_data_cb: Ignoring payload...\n\r");
    	//HAL_UART_Transmit(&huart3,buffer,strlen(buffer),1000);
	}
  }
}






static void mqtt_sub_request_cb(void *arg, err_t result)
{
  /* Just print the result code here for simplicity,
     normal behaviour would be to take some action if subscribe fails like
     notifying user, retry subscribe or disconnect from server */
  //sprintf(buffer,"Subscribe result: %d\n\r", result);
  //HAL_UART_Transmit(&huart3,buffer,strlen(buffer),1000);

}

static void mqtt_connection_cb(mqtt_client_t *client, void *arg, mqtt_connection_status_t status)
{
  const char * topico = arg;
  char temp_string[20];
  err_t err;
  if(status == MQTT_CONNECT_ACCEPTED) {

//    sprintf(buffer,"mqtt_connection_cb: Successfully connected\n");
	//  HAL_UART_Transmit(&huart3,buffer,strlen(buffer),1000);

    /* Setup callback for incoming publish requests */
    mqtt_set_inpub_callback(client, mqtt_incoming_publish_cb, mqtt_incoming_data_cb, arg);

    /* Subscribe to a topic named "12345678/perguntas" with QoS level 0, call mqtt_sub_request_cb with result */
    err = mqtt_subscribe(client, topico, 0, mqtt_sub_request_cb, arg);

    if(err != ERR_OK) {
      //sprintf(buffer,"mqtt_subscribe return: %d\n", err);
	  //HAL_UART_Transmit(&huart3,buffer,strlen(buffer),1000);
    	conectou_broker=1;

    }
  } else {
    //sprintf(buffer,"mqtt_connection_cb: Disconnected, reason: %d\n", status);
//	  HAL_UART_Transmit(&huart3,buffer,strlen(buffer),1000);

    /* Its more nice to be connected, so try to reconnect */
    //example_do_connect(client);

/*
		sprintf(temp_string,"12345678/perguntas");
	  	temp_string[0]=nserie_str[0];
	  	temp_string[1]=nserie_str[1];
	  	temp_string[2]=nserie_str[2];
	  	temp_string[3]=nserie_str[3];
	  	temp_string[4]=nserie_str[4];
	  	temp_string[5]=nserie_str[5];
	  	temp_string[6]=nserie_str[6];
	  	temp_string[7]=nserie_str[7];
	    example_do_connect(client, temp_string);
	    */

  }

}


void example_do_connect(mqtt_client_t *client, const char *topic)
{
  struct mqtt_connect_client_info_t ci;
  err_t err;
  char temp_string[20];
  /* Setup an empty client info structure */
  memset(&ci, 0, sizeof(ci));

	sprintf(temp_string,"12345678");
/*	temp_string[0]=nserie_str[0];
	temp_string[1]=nserie_str[1];
	temp_string[2]=nserie_str[2];
	temp_string[3]=nserie_str[3];
	temp_string[4]=nserie_str[4];
	temp_string[5]=nserie_str[5];
	temp_string[6]=nserie_str[6];
	temp_string[7]=nserie_str[7];*/

  /* Minimal amount of information required is client identifier, so set it here */
  ci.client_id = temp_string;
  ci.client_user = "usuario";
  ci.client_pass = "senha";


  /* Initiate client and connect to server, if this fails immediately an error code is returned
     otherwise mqtt_connection_cb will be called with connection result after attempting
     to establish a connection with the server.
     For now MQTT version 3.1.1 is always used */
  ip_addr_t mqttServerIP;




  //descobrindo o ip do servidor da embrasul, onde está o mosquito.
  //problema: se o cliente compra o power! dai tem que ser configurado.
  //precisou fazer #define LWIP_DNS  1 em opt.h

  err_t result = dns_gethostbyname("www.embrasul.com.br", &mqttServerIP, NULL);

  //por enquanto usamos um ip fixo.
  //IP4_ADDR(&mqttServerIP, 10, 1, 25, 200); //189.126.121.82
    IP4_ADDR(&mqttServerIP, 189,126,121,82);

//  err = mqtt_client_connect(client, &mqttServerIP, MQTT_PORT, mqtt_connection_cb, 0, &ci);
  err = mqtt_client_connect(client, &mqttServerIP, MQTT_PORT, mqtt_connection_cb, topic, &ci);



  if((err == ERR_OK) || (err == ERR_ISCONN)) {

	  	 // conectou_broker=1;
  }

}

/* Called when publish is complete either with sucess or failure */
static void mqtt_pub_request_cb(void *arg, err_t result)
{
  if(result != ERR_OK) {
    //sprintf(buffer,"Publish result: %d\n", result);
//	  HAL_UART_Transmit(&huart3,buffer,strlen(buffer),1000);
  }
}
void example_publish(mqtt_client_t *client, void *arg)
{
  //const char *pub_payload= "Hola mundo de mierda!";
  const char *pub_payload= arg;
  char temp_string[20];
	sprintf(temp_string,"12345678/respostas");
	temp_string[0]=nserie_str[0];
	temp_string[1]=nserie_str[1];
	temp_string[2]=nserie_str[2];
	temp_string[3]=nserie_str[3];
	temp_string[4]=nserie_str[4];
	temp_string[5]=nserie_str[5];
	temp_string[6]=nserie_str[6];
	temp_string[7]=nserie_str[7];

  err_t err;
  u8_t qos = 0; /* 0 1 or 2, see MQTT specification */
  u8_t retain = 0; /* No don't retain such crappy payload... */
  //err = mqtt_publish(client, "12345678/respostas", pub_payload, strlen(pub_payload), qos, retain, mqtt_pub_request_cb, arg);
  err = mqtt_publish(client, temp_string, pub_payload, strlen(pub_payload), qos, retain, mqtt_pub_request_cb, arg);
  if(err != ERR_OK) {
	  u8_t retain = 0;
  //  sprintf(buffer,"Publish err: %d\n\r", err);
	//  HAL_UART_Transmit(&huart3,buffer,strlen(buffer),1000);
  }
}


void send_mqtt(uint8_t *buf, int len)
{
	//para funcionar há que redefinir em mqtt_opts.h:
	//#define MQTT_OUTPUT_RINGBUF_SIZE 512 //256

	extern mqtt_client_t *client;
	char *result;

	//processBytes(buf, len-2,result); //porque len-2??
	result=processBytes(buf, len-2); //porque len-2??


	example_publish(client, result);
	free(result);

}
