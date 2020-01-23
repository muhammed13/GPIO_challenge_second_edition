#include "GPIO_REQ8.h"


void button_led(void)
{
	uint8_t flag=0;
	uint8_t i;
	Led_Init(LED_1);
	pushButtonInit(BTN_1);
	while(1)
	{
		if(pushButtonGetStatus(BTN_1))
		{
			Led_On(LED_1);
	    	for(i=0;i<100;i++)
	    	{
	    		if(pushButtonGetStatus(BTN_1))
	    		{
	    			flag++;
	    		}
	    	}
	    	if(flag>10)
	    	{
	    		softwareDelayMs(ONE_SEC);
	    	}
	    	Led_Off(LED_1);
	    	softwareDelayMs(ONE_SEC);
		}
	}
}


void button_led_using_timer0(void)
{
	uint8_t flag=0;
	uint8_t i;
	Led_Init(LED_1);
	pushButtonInit(BTN_1);
	while(1)
	{
		if(pushButtonGetStatus(BTN_1))
		{
			Led_On(LED_1);
	    	for(i=0;i<100;i++)
	    	{
	    		if(pushButtonGetStatus(BTN_1))
	    		{
	    			flag++;
	    		}
	    	}
	    	if(flag>10)
	    	{
	    		timer0DelayMs(ONE_SEC);
	    	}
	    	Led_Off(LED_1);
	    	timer0DelayMs(ONE_SEC);
		}
	}
}
