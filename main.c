#include "GPIO_REQ8.h"
#include "GPIO_REQ7.h"
#include "GPIO_REQ9.h"
#include "timers.h"
#include "softwareDelay.h"
#include "interrupt.h"
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
