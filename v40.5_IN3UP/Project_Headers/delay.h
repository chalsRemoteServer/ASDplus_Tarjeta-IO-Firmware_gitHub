/*
 * delay.h
 *
 *  Created on: Sep 12, 2015
 *      Author: chals
 */

#ifndef DELAY_H_
#define DELAY_H_

// ============================================
// CONFIGURACIÓN PARA TIMER DE 9.7 µs
// SIN DIVISIONES - SOLO MULTIPLICACIÓN Y SHIFT
// ============================================
#define TICKS_TO_US_FACTOR          9933    // Factor precalculado
#define TICKS_TO_US_SHIFT           10      // Dividir por 1024
#define pdTICKS_TO_US( xTicks )     (((xTicks) * TICKS_TO_US_FACTOR) >> TICKS_TO_US_SHIFT)



void delay_ms(unsigned  int t);
void delay1ms(void);
void delay1us(void);
void delay_us(unsigned short int t);
//void delay_us_VFD(unsigned short int t);
//unsigned char delay_us_VFD(unsigned short int t);
unsigned char delay_us_VFD(unsigned short int t);
unsigned char delay_ms_VFD(unsigned short int t);
//unsigned char delay_us_v2(unsigned short int t,unsigned char *p);

unsigned char delay_us_VFD_exclusivo(unsigned short int t);
//unsigned char delay_ms_VFD_exclusivo(unsigned short int t);
unsigned char delay_us_v3(unsigned short int t,unsigned char *p);
unsigned char delay_general_1ms(unsigned long long int *delay1,unsigned long long int t_deseado,unsigned char *inst);
unsigned long int xTaskGetTickCount(void);
static inline uint32_t ulGetSystemTimeUs(void);

#endif /* DELAY_H_ */


