/*
 * Copyright (c) 2001-2003 Swedish Institute of Computer Science.
 * All rights reserved. 
 * 
 * Redistribution and use in source and binary forms, with or without modification, 
 * are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 * 3. The name of the author may not be used to endorse or promote products
 *    derived from this software without specific prior written permission. 
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR IMPLIED 
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF 
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT 
 * SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, 
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT 
 * OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS 
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN 
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING 
 * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY 
 * OF SUCH DAMAGE.
 *
 * This file is part of the lwIP TCP/IP stack.
 * 
 * Author: Adam Dunkels <adam@sics.se>
 *
 */


#include "lwip/opt.h"


#include "lwip/udp.h"
#include "lwip/tcp.h"
#include "lwip/pbuf.h"

#include "string.h"
#include "netif.h"
#include "stm32f4xx_hal.h"




struct tcp_pcb *tpcb;
struct tcp_pcb *tpcb1;

#if 0
static void close_conn(struct tcp_pcb *pcb){
      tcp_arg(pcb, NULL);
      tcp_sent(pcb, NULL);
      tcp_recv(pcb, NULL);
      tcp_close(pcb);
}

static err_t echo_recv(void *arg, struct tcp_pcb *pcb, struct pbuf *p, err_t err){
      int i;
      int len;
      char *pc;

      if (err == ERR_OK && p != NULL) {
            /* Inform TCP that we have taken the data. */
            tcp_recved(pcb, p->tot_len);

            //pointer to the pay load
            pc=(char *)p->payload;

            //size of the pay load
            len =p->tot_len;

            //copy to our own buffer
            for (i=0; i<len; i++)mydata[i]= 0xBA;

             //Close TCP when receiving "X"
            if (mydata[0]=='X')close_conn(pcb);



           //Free the packet buffer
            pbuf_free(p);

            //check output buffer capacity
            if (len >tcp_sndbuf(pcb)) len= tcp_sndbuf(pcb);
            //Send out the data
            err = tcp_write(pcb, mydata, len, 0);
            tcp_sent(pcb, NULL); /* No need to call back */
      } else {
            pbuf_free(p);
      }

      if (err == ERR_OK && p == NULL) {
            close_conn(pcb);
      }
      return ERR_OK;
}

static err_t echo_accept(void *arg, struct tcp_pcb *pcb, err_t err){
      LWIP_UNUSED_ARG(arg);
      LWIP_UNUSED_ARG(err);
      tcp_setprio(pcb, TCP_PRIO_MIN);
      tcp_recv(pcb, echo_recv);
      tcp_err(pcb, NULL); //Don't care about error here
      tcp_poll(pcb, NULL, 4); //No polling here
      return ERR_OK;
}

void tcp_echoserver_init(void){
      struct tcp_pcb *ptel_pcb;
      ptel_pcb = tcp_new();
      tcp_bind(ptel_pcb, IP_ADDR_ANY, 1001);


     ptel_pcb = tcp_listen(ptel_pcb);
     tcp_accept(ptel_pcb, echo_accept);

}

#endif




void tcp_send1(uint8_t *Remote_IP, uint16_t NroPortaRemota, uint8_t *sendbuf, uint16_t len)
{

	err_t err;
	typedef ip4_addr_t ip_addr_t;

	ip_addr_t  Ripaddr;
//	struct pbuf *p;
	IP4_ADDR (&Ripaddr, Remote_IP [0], Remote_IP [1], Remote_IP [2], Remote_IP [3]);




     if(err != ERR_OK)
     {
    	 err=-err;
     }


	// p=pbuf_alloc(PBUF_TRANSPORT, len, PBUF_POOL);


	 //memcpy(p->payload, sendbuf, len); // payload copied

	 //check output buffer capacity
     if (len >tcp_sndbuf(tpcb1)) len= tcp_sndbuf(tpcb1);
     //Send out the data
     err = tcp_write(tpcb1, sendbuf, len, TCP_WRITE_FLAG_COPY);

     tcp_sent(tpcb1, NULL); /* No need to call back */
     tcp_output(tpcb1);

    if(err != ERR_OK)
    {
   	 err=-err;
    }

	//pbuf_free(p);



//	extern void EspectroAcumulado_reinit(void);
//	EspectroAcumulado_reinit();

}











static void close_conn(struct tcp_pcb *pcb){
      tcp_arg(pcb, NULL);
      tcp_sent(pcb, NULL);
      tcp_recv(pcb, NULL);
      tcp_close(pcb);
}




err_t TCPConnected(void *pvArg, struct tcp_pcb *psPcb, err_t iErr)
{
    //
    // Check if there was a TCP error.
    //
    if(iErr != ERR_OK)
    {
        //
        // Clear out all of the TCP callbacks.
        //
        tcp_sent(psPcb, NULL);
        tcp_recv(psPcb, NULL);
        tcp_err(psPcb, NULL);

        //
        // Close the TCP connection.
        //
        tcp_close(psPcb);



        //
        // And return.
        //
        return (ERR_OK);
    }


    //
    // Return a success code.
    //
    return(ERR_OK);
}











err_t tcp_echoserver_receive_callback1(void *arg, struct tcp_pcb *pcb, struct pbuf *p, err_t err){


    int len;
    char *pc;
    uint8_t* sendbuf;

    if (err == ERR_OK && p != NULL) {
          /* Inform TCP that we have taken the data. */
          tcp_recved(pcb, p->tot_len);

          //pointer to the pay load
          pc=(char *)p->payload;

          //size of the pay load
          len =p->tot_len;

     		sendbuf=(uint8_t*)malloc(len);


     		//memcpy(void *dest, const void *src
     		 memcpy(sendbuf,pc,len); // payload copied


     		uint8_t Remote_IP[4] ;
     		ip_addr_t remote_ip=pcb->remote_ip;
     		ip_addr_t remote_ip1;
     		Remote_IP[0] =ip4_addr1_val( remote_ip); //(pcb->remote_ip.addr)>>24 &0xFF;
     		Remote_IP[1] =ip4_addr2_val( remote_ip); //(pcb->remote_ip.addr)>>16 &0xFF;
     		Remote_IP[2] =ip4_addr3_val( remote_ip); //(pcb->remote_ip.addr)>>8 &0xFF;
     		Remote_IP[3] =ip4_addr4_val( remote_ip); // pcb->remote_ip.addr &0xFF;
     		IP4_ADDR (&remote_ip1, Remote_IP [0], Remote_IP [1], Remote_IP [2], Remote_IP [3]);

     		tpcb1=pcb;
     	    //podemos chamar o callback legado

     	    extern uint16_t tcp_callback(uint8_t *rip, uint16_t  rport, uint8_t *ptr, int par);
     	    tcp_callback(Remote_IP,pcb->remote_port, sendbuf, len);
     	    free(sendbuf);

     	    extern uint16_t ContSilencioMODBUS;
     	    ContSilencioMODBUS=10000;
     	    extern void timer_admite_nested_interrupt_srv();
     	    timer_admite_nested_interrupt_srv();

     			//Atende � pergunta MODBUS, se houver uma..
     			extern uint8_t HabResponder;

     			HabResponder=1;


         //Free the packet buffer
          pbuf_free(p);


    } else {
          pbuf_free(p);
    }

   // if (err == ERR_OK && p == NULL) {
   //       close_conn(pcb);
   // }

return(err);
}

static err_t echo_accept(void *arg, struct tcp_pcb *pcb, err_t err){
      LWIP_UNUSED_ARG(arg);
      LWIP_UNUSED_ARG(err);
      tcp_setprio(pcb, TCP_PRIO_MIN);
      //tcp_recv(pcb, echo_recv);
      tcp_recv(pcb,tcp_echoserver_receive_callback1);
      tcp_err(pcb, NULL); //Don't care about error here
      tcp_poll(pcb, NULL, 4); //No polling here
      return ERR_OK;
}




uint16_t get_port(void)
{
	if (tpcb !=NULL)
		 {
		return(tpcb->local_port);
		 }
	else
	{
		return(-1);
	}
}


void tcp_echoserver_init(uint16_t PORTA_){
	 err_t err;

	 if (tpcb !=NULL)
		 {
		 tcp_close(tpcb);
		 }


      tpcb = tcp_new();

     // p_for_send=pbuf_alloc(PBUF_TRANSPORT, len, PBUF_POOL);




      //if ((tpcb!=NULL)&&  (tpcb1!=NULL))
      if (tpcb!=NULL)
      {
    		  err=tcp_bind(tpcb, IP_ADDR_ANY, PORTA_);
    		  //err=tcp_bind(tpcb1, IP_ADDR_ANY, PORTA_);

    		  if (err == ERR_OK)
    		  {
    	            tpcb = tcp_listen(tpcb);
    	            tcp_accept(tpcb, echo_accept);
    	            tcp_recv(tpcb,tcp_echoserver_receive_callback1);
    		  }
    		  else
    		  {
    			   Error_Handler();

    		  }

      }
      else
      {
    	   Error_Handler();

      }

}







#if 0

#define PORTA_ 1001

static struct tcp_pcb *echo_pcb;
struct tcp_pcb *mytpcb;


static err_t echo_recv(void *arg, struct tcp_pcb *pcb, struct pbuf *p, err_t err){
      int i;
      int len;
      char *pc;

      if (err == ERR_OK && p != NULL) {
            /* Inform TCP that we have taken the data. */
            tcp_recved(pcb, p->tot_len);

            //pointer to the pay load
            pc=(char *)p->payload;

            //size of the pay load
            len =p->tot_len;

            //copy to our own buffer
            for (i=0; i<len; i++)mydata[i]= pc[i];

             //Close TCP when receiving "X"
            if (mydata[0]=='X')close_conn(pcb);

           //Free the packet buffer
            pbuf_free(p);

            //check output buffer capacity
            if (len >tcp_sndbuf(pcb)) len= tcp_sndbuf(pcb);
            //Send out the data
            err = tcp_write(pcb, mydata, len, 0);
            tcp_sent(pcb, NULL); /* No need to call back */
      } else {
            pbuf_free(p);
      }

      if (err == ERR_OK && p == NULL) {
            close_conn(pcb);
      }
      return ERR_OK;
}


enum echo_states
{
  ES_NONE = 0,
  ES_ACCEPTED,
  ES_RECEIVED,
  ES_CLOSING
};

struct echo_state
{
  u8_t state;
  u8_t retries;
  struct tcp_pcb *pcb;
  /* pbuf (chain) to recycle */
  struct pbuf *p;
};

err_t echo_accept(void *arg, struct tcp_pcb *newpcb, err_t err);
err_t echo_recv(void *arg, struct tcp_pcb *tpcb, struct pbuf *p, err_t err);
void echo_error(void *arg, err_t err);
err_t echo_poll(void *arg, struct tcp_pcb *tpcb);
err_t echo_sent(void *arg, struct tcp_pcb *tpcb, u16_t len);
void echo_send(struct tcp_pcb *tpcb, struct echo_state *es);
void echo_close(struct tcp_pcb *tpcb, struct echo_state *es);


err_t echo_accept(void *arg, struct tcp_pcb *newpcb, err_t err)
{
  err_t ret_err;
  struct echo_state *es;

  LWIP_UNUSED_ARG(arg);
  LWIP_UNUSED_ARG(err);

  /* commonly observed practive to call tcp_setprio(), why? */
  tcp_setprio(newpcb, TCP_PRIO_MIN);

  es = (struct echo_state *)mem_malloc(sizeof(struct echo_state));
  if (es != NULL)
  {
    es->state = ES_ACCEPTED;
    es->pcb = newpcb;
    es->retries = 0;
    es->p = NULL;
    /* pass newly allocated es to our callbacks */
    tcp_arg(newpcb, es);
    tcp_recv(newpcb, echo_recv);
    tcp_err(newpcb, echo_error);
    tcp_poll(newpcb, echo_poll, 0);
    ret_err = ERR_OK;
  }
  else
  {
    ret_err = ERR_MEM;
  }
  return ret_err;
}

err_t echo_recv(void *arg, struct tcp_pcb *tpcb, struct pbuf *p, err_t err)
{
  struct echo_state *es;
  err_t ret_err;

  LWIP_ASSERT("arg != NULL",arg != NULL);
  es = (struct echo_state *)arg;


 // p=es->p;

  //uint8_t *sendbuf;

	//  	 sendbuf=(uint8_t*)p;

	//	sendbuf=(uint8_t*)malloc( p->len);

		//memcpy(void *dest, const void *src
		//memcpy(sendbuf,p->payload, ,p->len); // payload copied



  if (p == NULL)
  {
    /* remote host closed connection */
    es->state = ES_CLOSING;
    if(es->p == NULL)
    {
       /* we're done sending, close it */
       echo_close(tpcb, es);
    }
    else
    {
      /* we're not done yet */
      tcp_sent(tpcb, echo_sent);
      echo_send(tpcb, es);
    }
    ret_err = ERR_OK;
  }
  else if(err != ERR_OK)
  {
    /* cleanup, for unkown reason */
    if (p != NULL)
    {
      es->p = NULL;
      pbuf_free(p);
    }
    ret_err = err;
  }
  else if(es->state == ES_ACCEPTED)
  {
    /* first data chunk in p->payload */
    es->state = ES_RECEIVED;
    /* store reference to incoming pbuf (chain) */









    es->p =  p;

//    uint8_t *sendbuf;

  //	  	 sendbuf=(uint8_t*)p;

  	//	sendbuf=(uint8_t*)malloc( p->len);

		//memcpy(void *dest, const void *src
		// memcpy(sendbuf,p->payload, p->len); // payload copied




    /* install send completion notifier */
    tcp_sent(tpcb, echo_sent);
    echo_send(tpcb, es);
    ret_err = ERR_OK;
  }
  else if (es->state == ES_RECEIVED)
  {
    /* read some more data */
    if(es->p == NULL)
    {
      es->p = p;
      tcp_sent(tpcb, echo_sent);
      echo_send(tpcb, es);
    }
    else
    {
      struct pbuf *ptr;

      /* chain pbufs to the end of what we recv'ed previously  */
      ptr = es->p;
      pbuf_chain(ptr,p);
    }
    ret_err = ERR_OK;
  }
  else if(es->state == ES_CLOSING)
  {
    /* odd case, remote side closing twice, trash data */
    tcp_recved(tpcb, p->tot_len);
    es->p = NULL;
    pbuf_free(p);
    ret_err = ERR_OK;
  }
  else
  {
    /* unkown es->state, trash data  */
    tcp_recved(tpcb, p->tot_len);
    es->p = NULL;
    pbuf_free(p);
    ret_err = ERR_OK;
  }
  return ret_err;
}

void echo_error(void *arg, err_t err)
{
  struct echo_state *es;

  LWIP_UNUSED_ARG(err);

  es = (struct echo_state *)arg;
  if (es != NULL)
  {
    mem_free(es);
  }
}

err_t echo_poll(void *arg, struct tcp_pcb *tpcb)
{
  err_t ret_err;
  struct echo_state *es;

  es = (struct echo_state *)arg;
  if (es != NULL)
  {
    if (es->p != NULL)
    {
      /* there is a remaining pbuf (chain)  */
      tcp_sent(tpcb, echo_sent);
      echo_send(tpcb, es);
    }
    else
    {
      /* no remaining pbuf (chain)  */
      if(es->state == ES_CLOSING)
      {
        echo_close(tpcb, es);
      }
    }
    ret_err = ERR_OK;
  }
  else
  {
    /* nothing to be done */
    tcp_abort(tpcb);
    ret_err = ERR_ABRT;
  }
  return ret_err;
}


//esta rotina garante o envio de todos os pacotes em cadeia dentro do 'es'
err_t echo_sent(void *arg, struct tcp_pcb *tpcb, u16_t len)
{
  struct echo_state *es;

  LWIP_UNUSED_ARG(len);

  es = (struct echo_state *)arg;
  es->retries = 0;

  if(es->p != NULL)
  {
    /* still got pbufs to send */
    tcp_sent(tpcb, echo_sent);
    echo_send(tpcb, es);
  }
  else
  {
    /* no more pbufs to send */
    if(es->state == ES_CLOSING)
    {
      echo_close(tpcb, es);
    }
  }
  return ERR_OK;
}


void echo_send(struct tcp_pcb *tpcb, struct echo_state *es)
{
  struct pbuf *ptr;
  uint8_t *sendbuf;

	 ptr = es->p;
	 sendbuf=(uint8_t*)ptr;

		sendbuf=(uint8_t*)malloc( ptr->len);


		//memcpy(void *dest, const void *src
		 memcpy(sendbuf,ptr->payload, ptr->len); // payload copied





	    //podemos chamar o callback legado
	    extern uint16_t tcp_callback(uint8_t soc, uint8_t evt, uint8_t *ptr, int par);
	    tcp_callback(NULL,NULL, sendbuf,   ptr->len);
	    free(sendbuf);

	    extern uint16_t ContSilencioMODBUS;
	    ContSilencioMODBUS=10000;
	    extern void timer_admite_nested_interrupt_srv();
	    timer_admite_nested_interrupt_srv();

			//Atende � pergunta MODBUS, se houver uma..
			extern uint8_t HabResponder;

			HabResponder=1;
			if (HabResponder==1)
			{
				extern void ResponderMODBUS(void);
				ResponderMODBUS();
				HabResponder=0;
			}

    u8_t freed;
	do
	  {
		/* try hard to free pbuf */
		freed = pbuf_free(ptr);
	  }
	  while(freed == 0);
	 /* we can read more data now */
	 tcp_recved(tpcb, ptr->len);


	 mytpcb=tpcb;
}






void tcp_send1(uint8_t *Rem_IP, uint16_t NroPortaRemota, uint8_t *sendbuf, uint16_t len)
{

	struct tcp_pcb *tpcb;
	  err_t wr_err = ERR_OK;
	struct echo_state *es;

	struct pbuf *ptr;


	ptr=pbuf_alloc(PBUF_TRANSPORT, len, PBUF_POOL);



		//memcpy(void *dest, const void *src
		memcpy(ptr->payload, sendbuf ,ptr->len); // payload copied


     tpcb=echo_pcb;
     //tpcb->state  = ESTABLISHED;

     tcp_sent(tpcb, echo_sent);



  while ((wr_err == ERR_OK) &&
         (ptr != NULL) &&
         (ptr->len <= tcp_sndbuf(tpcb)))
 //while(ptr != NULL)
  {



  /* enqueue data for transmission */
  wr_err = tcp_write(tpcb, ptr->payload, ptr->len, 1);

  tcp_output(tpcb);//cesar
  if (wr_err == ERR_OK)
  {
     u16_t plen;
      u8_t freed;

     plen = ptr->len;
     /* continue with next pbuf in chain (if any) */
     ptr = ptr->next;
     if(es->p != NULL)
     {
       /* new reference! */
       pbuf_ref(ptr);
     }
     /* chop first pbuf from chain */
      do
      {
        /* try hard to free pbuf */
        freed = pbuf_free(ptr);
      }
      while(freed == 0);
     /* we can read more data now */
     tcp_recved(tpcb, plen);
   }
   else if(wr_err == ERR_MEM)
   {
      /* we are low on memory, try later / harder, defer to poll */
	   ptr = ptr;
   }
   else
   {
     /* other problem ?? */
   }
  }


   pbuf_free(ptr);
	 mytpcb=tpcb;
}

void echo_close(struct tcp_pcb *tpcb, struct echo_state *es)
{
  tcp_arg(tpcb, NULL);
  tcp_sent(tpcb, NULL);
  tcp_recv(tpcb, NULL);
  tcp_err(tpcb, NULL);
  tcp_poll(tpcb, NULL, 0);

  if (es != NULL)
  {
    mem_free(es);
  }
  tcp_close(tpcb);
	 mytpcb=tpcb;
}



void tcp_echoserver_init(void)
{


  echo_pcb = tcp_new();
  if (echo_pcb != NULL)
  {
    err_t err;

    //err = tcp_bind(echo_pcb, IP_ADDR_ANY, 7);
    err = tcp_bind(echo_pcb, IP_ADDR_ANY, PORTA_);
    if (err == ERR_OK)
    {
      echo_pcb = tcp_listen(echo_pcb);
      tcp_accept(echo_pcb, echo_accept);
    }
    else
    {
      /* abort? output diagnostic? */
    }
  }
  else
  {
    /* abort? output diagnostic? */
  }
}

#endif



#if LWIP_NETCONN

#include "lwip/sys.h"
#include "lwip/api.h"

#include "string.h"

#define TCPECHO_THREAD_PRIO  ( tskIDLE_PRIORITY + 5 )



/*-----------------------------------------------------------------------------------*/
static void tcpecho_thread(void *arg)
{
  struct netconn *conn, *newconn;
  err_t err, accept_err;
  struct netbuf *buf;
  u8_t *data;
  u8_t *all_data;
  u16_t all_data_len=0;
  u16_t len;
  err_t recv_err;
      
  LWIP_UNUSED_ARG(arg);

  /* Create a new connection identifier. */
  conn = netconn_new(NETCONN_TCP);
  
  if (conn!=NULL)
  {  
    /* Bind connection to well known port number 7. */
    err = netconn_bind(conn, NULL, 7);
    
    if (err == ERR_OK)
    {
      /* Tell connection to go into listening mode. */
      netconn_listen(conn);
    
      while (1) 
      {
        /* Grab new connection. */
         accept_err = netconn_accept(conn, &newconn);  //funcao bloqueante... so sai quando algo chega...
    
        /* Process the new connection. */
        if (accept_err == ERR_OK) 
        {
          recv_err = netconn_recv(newconn, &buf);
		  while ( recv_err == ERR_OK)
          {
            do 
            {



              netbuf_data(buf, &data, &len);  //a informação tem tamanho len e esta em data[0],data[1],etc...
              //ha que mover eles para outro buffer, de acordo com o que já tem vindo.
              if (all_data_len==0)
              {
            	  all_data=( u8_t *)malloc(sizeof(u8_t)*len);
            	  //memcpy(​void *to, const void *from, size_t numBytes);
            	  memcpy(&all_data[0],&data[0],len);
            	  all_data_len=len;

              }
              else
              {
            	  all_data=( u8_t *)malloc(sizeof(u8_t)*(len+all_data_len));
            	  //memcpy(​void *to, const void *from, size_t numBytes);
            	  memcpy(&all_data[all_data_len],&data[0],len);
            	  all_data_len=len+all_data_len;

              }


              netconn_write(newconn, data, len, NETCONN_COPY); //aqui acontece o envio dos dados
          
            } 
            while (netbuf_next(buf) >= 0);   //as vezes TCP vem fragmentado, por isso precisa deste while
          
            			netbuf_delete(buf);
						recv_err = netconn_recv(newconn, &buf);  //pega o proximo fragmento
          }
        
          /* Close connection and discard connection identifier. */
          netconn_close(newconn);
          netconn_delete(newconn);
        }
      }
    }
    else
    {
      netconn_delete(newconn);
      printf(" can not bind TCP netconn");
    }
  }
  else
  {
    printf("can not create TCP netconn");
  }
}
/*-----------------------------------------------------------------------------------*/

void tcp_config(void)
{
  sys_thread_new("tcpecho_thread", tcpecho_thread, NULL, DEFAULT_THREAD_STACKSIZE, TCPECHO_THREAD_PRIO);
}
/*-----------------------------------------------------------------------------------*/
https://github.com/dreamcat4/lwip/blob/master/contrib/apps/tcpecho_raw/echo.c
testar este link acima
#endif /* LWIP_NETCONN */


