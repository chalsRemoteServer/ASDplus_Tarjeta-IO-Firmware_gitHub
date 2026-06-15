/*
 * RTOS.h
 *
 *  Created on: Nov 26, 2025
 *      Author: desarrollo_1
 */

#ifndef ASD_APP_INCLUDE_RTOS_H_
#define ASD_APP_INCLUDE_RTOS_H_

//prioridades de las tareas----------------------------
#define PR_TFT_EVE tskIDLE_PRIORITY+1 //tarea que constrola y enciende el TFT EVE

//RTOS STACK SIZE TASK
#define ST_TFT_EVE ( ( unsigned short ) 256 )  //tarea de control de TFT EVE


void vDisplayTFT_EVE_Task1(void *pvParam);
unsigned char findComando(unsigned char c,unsigned char *cmd);
unsigned char findLen(unsigned char c,unsigned char *len,unsigned char cmd);
unsigned char comandoDDS(unsigned char *param,unsigned char *aux);
unsigned char comandoAlive(unsigned char *aux);
void Task7_Serial_Receptor_Processor(void);


#endif /* ASD_APP_INCLUDE_RTOS_H_ */
