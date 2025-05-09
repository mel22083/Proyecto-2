/*
 * servo1.c
 *
 * Created: 4/28/2025 9:55:54 AM
 *  Author: willi
 */ 
#include "PWM1.h"
#define SERVO_MIN 500   // 1 ms
#define SERVO_MAX 2500   // 2 ms

void PWM1_INIT(void)
{
	
	DDRB |= (1 << PB1) | (1 << PB2);					//OCIA y OCIB como salidas
	
	TCCR1A = (1 << COM1A1) | (1 << COM1B1) | (1 << WGM11);			//
	TCCR1B = (1 << WGM13) | (1 << WGM12) | (1 << CS11);			   //FAST PWM y preescaler de 8
	ICR1 = 39999;
	
}

void angulo_servo1(uint8_t angulo, uint8_t servo1)
{
	// Mapea 0–180° a 1000–2000 µs
	uint16_t ancho_de_pulso = SERVO_MIN
	+ ((uint32_t)angulo * (SERVO_MAX - SERVO_MIN)) / 180;

	if (servo1 == 1) {
		OCR1A = ancho_de_pulso;
		} else if (servo1 == 2) {
		OCR1B = ancho_de_pulso;
	}
}
