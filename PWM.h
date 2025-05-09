/*
 * PWM0.h
 *
 * Created: 5/4/2025 8:02:34 PM
 *  Author: willi
 */ 

#define F_CPU 8000000UL
#include <avr/io.h>

#ifndef PWM0_H_
#define PWM0_H_


void ConfigTimer0(void);
void SetAngle(uint16_t POT, uint8_t Servo);


#endif /* PWM0_H_ */
