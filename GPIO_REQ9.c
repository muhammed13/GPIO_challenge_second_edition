#include "GPIO_REQ9.h"
void trafficlight()
{
	Led_Init(LED_1);
	Led_Init(LED_2);
	Led_Init(LED_3);
	int state=GO_;
	while(1)
	{
		switch(state)
		{
			case GO_:
				Led_On(LED_1);
				softwareDelayMs(ONE_SEC_);
				Led_Off(LED_1);
				state=STOP_;
				break;
			case READY_:
				Led_On(LED_2);
				softwareDelayMs(ONE_SEC_);
				Led_Off(LED_2);
				state=GO_;
				break;
			case STOP_:
				Led_On(LED_3);
				softwareDelayMs(ONE_SEC_);
				Led_Off(LED_3);
				state=READY_;
				break;
		}

	}
}

void trafficlight_using_timer0()
{
	Led_Init(LED_1);
	Led_Init(LED_2);
	Led_Init(LED_3);
	int state=GO_;
	while(1)
	{
		switch(state)
		{
			case GO_:
				Led_On(LED_1);
				timer0DelayMs(ONE_SEC_);
				Led_Off(LED_1);
				state=STOP_;
				break;
			case READY_:
				Led_On(LED_2);
				timer0DelayMs(ONE_SEC_);
				Led_Off(LED_2);
				state=GO_;
				break;
			case STOP_:
				Led_On(LED_3);
				timer0DelayMs(ONE_SEC_);
				Led_Off(LED_3);
				state=READY_;
				break;
		}

	}
}
