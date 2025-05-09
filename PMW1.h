/*
 * servo1.h
 *
 * Created: 4/28/2025 9:56:22 AM
 *  Author: willi
 */ 

#define F_CPU 8000000UL
#include <avr/io.h>

#ifndef SERVO1_H_
#define SERVO1_H_


void PWM1_INIT(void);
void angulo_servo1(uint8_t angulo, uint8_t servo1);


#endif /* SERVO1_H_ */
