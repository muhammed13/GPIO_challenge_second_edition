#ifndef GPIO_REQ9_H_
#define GPIO_REQ9_H_


#include "led.h"
#include "softwareDelay.h"


#ifndef ONE_SEC_
#define ONE_SEC_ 1000
#endif

#ifndef START
#define START 0
#endif

typedef enum STATE
{
	GO_=1,
	READY_=2,
	STOP_=3,
}STATE;

void trafficlight();

void trafficlight_using_timer0();


#endif /* GPIO_REQ7_H_ */
