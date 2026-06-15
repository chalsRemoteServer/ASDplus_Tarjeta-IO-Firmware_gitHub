/*
 * ComSer.c
 *
 *  Created on: May 7, 2026
 *      Author: desarrollo_1
 */
#include "ComSer.h"
#include "queue1.h"
#include "ft900.h"

extern struct _DISPLAY_VFD_ comm;

/*Driver principal de transmision ala procesadora  * por serial* */
void Task6_Transmisor_Serial_a_Procesadora(void){
static unsigned char estado;
static uint8_t dato;
unsigned char *x;
	x=&dato;
    switch(estado){
    	case 1:if(comm.TxProc.ncount>0){estado++;}break;
    	case 2:if(comm.TxProc.dequeue(x,&comm.TxProc)){estado++;}break;
    	case 3:if(uart_get_tx_fifo_level(UART1)<16)estado++;break;//hay espacio en la fifo de hardware?
    	case 4:if(uart_write(UART1,*x)>=0){estado++;}break;
       	default:estado=1;break;}//fin de estado
}//fin de transmision del display tft-----------------------------------

void vTask4_Process_RX_VFD(void) {    // Reservar memoria para las estructuras FIFO
static uint8_t estado,estado2;
static uint8_t c;
//static uint8_t buffer_patron[4];

	switch(estado){
		case 1:estado2=1;estado++;break;
		case 2:if(fifo_pop(fifo.VFDserial, &c))estado++;break;
		case 3:switch(estado2){
			    case 1:if(c==STX)estado2++;else{estado2=1;}break;
			    case 2:if(c==CMD_IM_ALIVE_ANS)estado2++;else{estado2=1;}break;
			    case 3:if(c==0xFF)estado2++;else{estado2=1;}break;
			    case 4:if(c==ETX){Monitor_System_status_LEDs(CMD_IM_ALIVE_ANS);}
			           else{estado2=1;}
			    	   break;
			    default:estado2=1;break;}
		       estado=2;break;
		default:estado=1;break;}//fin switch---------------------
}//task4---------------------------------------------------

//Transmisor serial a MCU-IO-TFT
void Task8_Test_Tx_Ser_a_Proc(void){
static unsigned char estado5,i;
static unsigned long int count;
const unsigned char ans[]={" Hola mundo "};

	switch(estado5){
	case 1:if(count++>20000)estado5++;break;
	case 2:i=0;estado5++;break;
	case 3:if(comm.TxProc.append(ans[i],&comm.TxProc))estado5++;break;
	case 4:if(ans[++i]!='\0')estado5--;else{estado5++;}break;
	case 5:
	default:count=0;estado5=1;break;}//fin switch------
}//fin test tx serial a procesadora----
