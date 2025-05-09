/*
 * PWM0.c
 *
 * Created: 5/4/2025 8:02:21 PM
 *  Author: willi
 */ 

#include <avr/io.h>
#include "PWM0.h"

void ConfigTimer0()
{
	DDRD |= (1<<PD6)|(1<<PD5);
	
	TCCR0A = 0;
	TCCR0A |= (1 << COM0A1) | (1 << COM0B1); //MODO fast
	TCCR0A |= (1 << WGM01) | (1 << WGM00); //Modo 7 cuando se compare se reinicia

	TCCR0B = 0;
	//TCCR0B |= (1 << WGM02); //Configurar el modo FAST con top FF

	TCCR0B |= (1 << CS00) | (1 << CS02); //Preescaler de 1024 con una frecuencia de reloj de 8M para poder tener un periodo de actualización de 32ms
}

void SetAngle(uint16_t POT, uint8_t Servo)
{
	if (POT > 254){
		POT = 254; 
}
	uint16_t DutyC = ((POT * (19 - 3)) / 255) + 3;
	
	if (Servo == 3)
	{
		OCR0B = DutyC;
	}
	if (Servo == 4)
	{
		OCR0A = DutyC;
	}

}

