#include "GPIO_REQ8.h"
#include "GPIO_REQ7.h"
#include "GPIO_REQ9.h"
#include "timers.h"
#include "softwareDelay.h"
#include <avr/interrupt.h>
//#include "interrupt.h"


ISR(INT0_vect)
{
	gpioPinToggle(GPIOB, BIT1);
}

void INT0_Init(void)
{
	SREG  &= ~(1<<7);                   // Disable interrupts by clearing I-bit
	//DDRD  &= (~(1<<PD2));               // Configure INT0/PD2 as input pin
	GICR  |= (1<<INT0);                 // Enable external interrupt pin INT0
	MCUCR |= (1<<ISC00) | (1<<ISC01);   // Trigger INT0 with the raising edge
	SREG  |= (1<<7);                    // Enable interrupts by setting I-bit
}

/*
ISR_(INT0_vect)
{
	gpioPinToggle(GPIOB, BIT1);
}

void INT0_Init(void)
{
	sei_();                   // Disable interrupts by clearing I-bit
	//DDRD  &= (~(1<<PD2));               // Configure INT0/PD2 as input pin
	GICR  |= (1<<INT0);                 // Enable external interrupt pin INT0
	MCUCR |= (1<<ISC00) | (1<<ISC01);   // Trigger INT0 with the raising edge
	cli_();                   // Enable interrupts by setting I-bit
}
*/

int main()
{
	/*REQ7*/
	/*sevensegments();*/

	/*REQ8*/
	/*button_led();*/

	/*REQ9*/
	/*trafficlight();*/

	/*REQ10*/
	/*trafficlight_using_timer0();*/
	/*button_led_using_timer0();*/

	/*REQ14*/

	/********timer0 pwm test***********/
	gpioPinDirection(GPIOB, BIT3, OUTPUT);
	gpioPinWrite(GPIOB, BIT3,LOW);
	timer0SwPWM(50,T0_FREQUENCY_16KHZ); /*50%duty cycle & 16KHZ frequency*/


	return 0;

}
