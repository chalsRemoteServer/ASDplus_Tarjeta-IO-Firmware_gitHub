/*
 * queue.c
 *
 *  Created on: Apr. 22, 2026
 *      Author: desarrollo_1
 */
#include "queue1.h"
#include "system.h"

struct _DISPLAY_VFD_ comm;

unsigned char buffer50[SIZE_BUFFER50];//fifo de recepcion serial desde procesadora
unsigned char buffer51[SIZE_BUFFER51];//fifo de TX serial HACIA procesadora

void init_queues(void){

	init_FIFO_General_1byte_v2(&comm.RxProc,&buffer50[0],SIZE_BUFFER50);
	init_FIFO_General_1byte_v2(&comm.TxProc,&buffer51[0],SIZE_BUFFER51);
    comm.RxProc.mode=1;//modo debug
    comm.TxProc.mode=1;//modo debug

}//fin init queue-------------------------------------------


// Versión v2: funciones para _FIFO_1byte_v2_ (appendByte con un solo parámetro)
void init_FIFO_General_1byte_v2(struct _FIFO_1byte_v2 *s, unsigned char *buff,unsigned char size){
    s->head = buff;
    s->tail = buff+(size-1);//ultimo elemento
    s->pop = s->push= buff;
    s->ncount = 0;
    s->dequeue = FIFO_general_1byte_pop_v2;
    s->append = FIFO_general_1byte_push_v2;
    s->peek =FIFO_general_1byte_peek_v2;
    s->search=FIFO_general_1byte_search_v2;
    s->size = size;
    s->resetFIFO = reset_FIFO_general_UChar_v2;
}//fini init general-------------------------------------------

//sacar un dato de la queue fifo
unsigned char FIFO_general_1byte_pop_v2(unsigned char *dato, struct _FIFO_1byte_v2 *s){
    if(s->ncount == 0)
        return FALSE;
    if(s->mode==0){//normal
		if(s->ncount == 1){
			*dato = *(s->pop);
			*(s->pop) = 0;
			s->pop = s->push = s->tail;
			s->ncount = 0;}
		else{
			*dato = *(s->pop);
			*(s->pop) = 0;
			if(s->ncount > 0) s->ncount--;
			if(s->pop == s->tail)
				s->pop = s->head;
			else
				s->pop++;}
		return TRUE;}
    else{//modo debug
    	*dato=*(s->head);
    	s->push=shift_left(s->head,s->ncount);
        s->ncount--;
    	return TRUE;}
return FALSE;
}//-----------------------------------------------------------------

/* mueve todos elementos ala izq 1,2,3 ->queda-> 2,3 y regresa puntero al 3
 * ncount es la cantidad de elementos que hay en la fifo incluyendo el que se va a sacar */
static unsigned char *shift_left(unsigned char *arr,unsigned char size){
unsigned char last_value = arr[size - 1],i;
      switch(size){
    	  case 0:return &arr[0];
      	  case 1:arr[0]=0;return &arr[0];
      	  case 2:arr[0]=arr[1];arr[1]=0;return &arr[0];
      	  default:
      	  	  for(i=0;i< size-1;i++){
	               arr[i] = arr[i + 1];}
	          arr[size - 1] = 0;
	          return &arr[size-2];}
}//fin shift left------------------------------------------------


//regresa FALSE si no se pudo insertar en la cola
unsigned char FIFO_general_1byte_push_v2(unsigned char dato, struct _FIFO_1byte_v2 *s){
unsigned char ret=FALSE;
  if(s->ncount < s->size){
    if(s->mode==0){//normal
			*(s->push) = dato;
			if(s->push==s->tail) s->push=s->head;
			else{s->push++;}
			s->ncount++;
			ret=TRUE;}
    else{//modo debug, en esta version no es circular
    	*(s->push) = dato;
    	s->push++;
    	s->ncount++;}}
  if(s->push>s->tail){
	     while(1);}   /* detiene la ejecución aquí */
return ret;
}//fin de push en fifo------------------------------------------------

/* muestra el primer elemento que se va  a sacar en fifo */
unsigned char FIFO_general_1byte_peek_v2(struct _FIFO_1byte_v2 *s){
	if(s->mode==0){//modo normal
		return *(s->pop);}
	else{ return *(s->head);}
}//fin de peek the first data pointed to be fifo poped-------------

//regresa 1 si lo encuentra
unsigned char FIFO_general_1byte_search_v2(unsigned char dato,struct _FIFO_1byte_v2 *s){
unsigned char *ptr;
	if(s->mode==0){//modo normal
	  ptr=s->pop;
	  switch(s->ncount){
		  case 0:return FALSE;
		  case 1:return(dato==*ptr)?TRUE:FALSE;
		  default:do{if(*ptr==dato)return TRUE;
                	 ptr++;
                	 if(ptr>=s->tail)ptr=s->head;}
		   	         while(ptr!=s->push);
		  	  	  	 return FALSE;}}
	else{return(busqueda2(s->head,s->ncount,dato))?TRUE:FALSE;}
return FALSE;
}//fin de search v2------------------------------------------------------------

unsigned char busqueda2(unsigned char *arr,unsigned char size,unsigned char dato){
	if(size==0)return 0;
	if(*arr==dato)return 1;
	return busqueda2(arr+1,size-1,dato);
}//fin algoritmo de busqueda----------------------------------------



void reset_FIFO_general_UChar_v2(struct _FIFO_1byte_v2 *s, unsigned char size){
unsigned char *i;
	s->pop = s->push =s->head;
    s->ncount = 0;
    for(i=s->head;i<(s->head+size);i++){//cleanArray(s->head, size, 0);
             *i=0;}
}//-----------------------------------------------
