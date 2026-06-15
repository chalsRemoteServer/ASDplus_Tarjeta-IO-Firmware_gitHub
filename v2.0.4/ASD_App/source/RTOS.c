/*
 * RTOS.c
 *
 *  Created on: Nov 26, 2025
 *      Author: desarrollo_1

 aqui se deben PONER TODAS LAS TAREAS QUE SE CREAN SOLAMENTE
 */
//#include "FreeRTOS.h"  // DEBE ir primero
//#include "task.h"
#include "RTOS.h"
#include "queue1.h"
#include <stdio.h>
#include "system.h"

extern struct _DISPLAY_VFD_ comm;

void vDisplayTFT_EVE_Task1(void *pvParam){

  for(;;){
	printf(COLOR_YELLOW"%s"COLOR_RESET, "Estoy en tarea EVE!\n");
     }

}//fin display TFT EVE TASK1-------------------------------


void Task7_Serial_Receptor_Processor(void){
static unsigned char estado3,estado4,c;
static unsigned char cmd,len;
enum{SIZE_PARAM=4,SIZE_MEMO=2};
static unsigned char parameters[SIZE_PARAM],i,mem[SIZE_MEMO];
    switch(estado3){
    case 1:estado4=1;estado3=2;break;//init
    case 2:if(comm.RxProc.dequeue(&c,&comm.RxProc))estado3++;break;
    case 3:switch(estado4){
    		case 1:if(c==STX)estado4++;else{estado3=1;}break;
    		case 2:if(findComando(c,&cmd))estado4++;else{estado3=1;}break;
    		case 3:if(findLen(c,&len,cmd)){estado4++;}else{estado3=1;}break;
    		case 4:if((len==0xFF)||(len==0))estado4=10;else{estado4++;i=0;}break;
    		case 5:if(!len--){parameters[i]=c;}else{estado4++;}
    			   estado3=2;break;
    		case 6:if(c==ETX){estado4++;mem[0]=0;}else{estado3=1;}break;
    		case 7:switch(cmd){
    				case CMD_DDS:if(comandoDDS(&parameters[0],&mem[0]))estado4++;break; //comando de transmision datos de deteccion raw X&Y
    				case CMD_IM_ALIVE:if(comandoAlive(&mem[0]))estado4++;break; //comando de transmision datos de
    				default:estado3=1;break;}
    				break;
    		case 8:
    		case 10:
    		default:estado3=1;break;}break;
    default:estado3=1;break;}//fin switch------
}//fin de serial receptcion del procesador-------------------

/* esta funcion encuantra el comando cmd que se ha dado de alta
 **/
unsigned char findComando(unsigned char c,unsigned char *cmd){
	switch(c){
	case CMD_DDS:
	case CMD_IM_ALIVE:*cmd=c;return TRUE;break;
	default:break;}
return FALSE;
}//find comando-----------------------------------

/* encuentra la longirtud que corresponde a este comando*/
unsigned char findLen(unsigned char c,unsigned char *len,unsigned char cmd){
	switch(cmd){
	case CMD_DDS:if(c==4){*len=c;return TRUE;}break;
	case CMD_IM_ALIVE:if((c==0)||(c==0xFF)){*len=0;return TRUE;}break;
	default:break;}//fin switch
return FALSE;
}//fin find lenght----------------------------------

/*aux es la memoria del proceso*/
unsigned char comandoDDS(unsigned char *param,unsigned char *aux){
unsigned char estado72;
unsigned short int x,y;
	estado72=*aux;
	switch(estado72){
	case 0:
	case 1:x=(unsigned short int)((param[0]<<8)|param[1]);
		   y=(unsigned short int)((param[2]<<8)|param[3]);
	       printf(" %u,%u",x,y);
           break;
	default:estado72=1;break;}
    *aux=estado72;
return TRUE;
}//fin comando DDS-------------------------------

//return TRUE cuando ya se insertaron todas las tramas en la FIFO tx
/*manda el comando de contestacion alive */
unsigned char comandoAlive(unsigned char *aux){
unsigned char estado88,i,ret=0;
const unsigned char ans[4]={STX,0x2F,0xFF,ETX};
 	estado88=*aux;
 	i=*(aux+1);
 	switch(estado88){
 	case 1:i=0;estado88++;break;
 	case 2:if(comm.TxProc.append(ans[i],&comm.TxProc))estado88++;break;
 	case 3:if(i++<4){estado88--;}else{estado88++;}break;
 	case 4:ret=TRUE;break;
 	default:estado88=1;break;}
    *aux=estado88;
 	*(aux+1)=i;
return ret;
}//fin comando alive-------------------
