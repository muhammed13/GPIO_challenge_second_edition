#include "timers.h"

void timer0Init(En_timer0Mode_t en_mode,En_timer0OC_t en_OC0,
		En_timer0perscaler_t en_prescal, uint8_t u8_initialValue,
		uint8_t u8_outputCompare, En_timer0Interrupt_t en_interruptMask)
{

	switch (en_mode)
	{
	case T0_NORMAL_MODE:
		TCNT0 = u8_initialValue; /*timer initial value*/
		TIMSK = en_interruptMask; /*enable or disable interrupt*/

		/* Configure the timer control register
		 * 1. Non PWM mode FOC0=1
		 * 2. Normal Mode WGM01=0 & WGM00=0
		 * 3. Normal Mode COM00=0 & COM01=0
		 * 4. clock = F_CPU/1024 CS00=1 CS01=0 CS02=1
		 */
		TCCR0 = en_prescal | en_OC0 | (1<<FOC0);   /*I made switch case because of FOC0 will be disabled to zero in the PWM mode*/
		break;

	case T0_COMP_MODE:
		TCNT0 = u8_initialValue; /*timer initial value*/
		OCR0 = u8_outputCompare; /*set the compare value*/
		TIMSK = en_interruptMask; /*enable or disable interrupt*/

		/* Configure the timer control register
		 * 1. Non PWM mode FOC0=1
		 * 2. Normal Mode WGM01=0 & WGM00=0
		 * 3. Normal Mode COM00=0 & COM01=0
		 * 4. clock = F_CPU/1024 CS00=1 CS01=0 CS02=1
		 */
		TCCR0= en_prescal | en_OC0 | (1<<FOC0);
		break;
	}
}

void timer0Set(uint8_t u8_value)
{
	TCNT0 = u8_value;
}

uint8_t timer0Read(void)
{
	uint8_t TCNT0_value=TCNT0;
	return TCNT0_value;
}

void timer0Start(void)
{
	TCCR0 = T0_PRESCALER_NO;
}

void timer0Stop(void)
{
	TCCR0 = T0_NO_CLOCK;
}

void timer0DelayMs(uint16_t u16_delay_in_ms)
{
	/*CTC WITH POOLING*/
	/*this is the equation of ms_OCR_value
	((SEC/(1/(cpu_frq/T0_PRESCALER_64)))/TIMER0_OVER_FLOW_VALUE);
	*/
	timer0Init(T0_COMP_MODE,T0_OC0_DIS,T0_PRESCALER_64,0,MS_OCR_value,T0_POLLING);
	while(u16_delay_in_ms)
	{
		while(BIT_IS_CLEAR(TIFR,OCF0));   /*while(TCNT<OCR0) this condition will handle 1.01s */
		SET_BIT(TIFR,OCF0);
		TCNT0=0;
		u16_delay_in_ms--;
	}
	timer0Stop();
	return;
}

void timer0DelayUs(uint32_t u32_delay_in_us)
{
	/*CTC WITH POOLING*/
	timer0Init(T0_COMP_MODE,T0_OC0_DIS,T0_PRESCALER_NO,0,US_OCR_value,T0_POLLING);
	while(u32_delay_in_us)
	{
		while(TCNT0<OCF0);    /*another way to check*/
		SET_BIT(TIFR,OCF0);
		TCNT0=0;
		u32_delay_in_us--;
	}
	timer0Stop();
	return;
}

/*
 * the user has to choose one of the defined frequencies
 */
void timer0SwPWM(uint8_t u8_dutyCycle,uint8_t u8_frequency)
{
	TCNT0 = 0; /*timer initial value*/
	TIMSK = 0; /*enable overflow interrupt*/
	OCR0 = (u8_dutyCycle*TIMER0_OVER_FLOW_VALUE)/100; /*output compare value*/

	switch(u8_frequency)
	{
	case(T0_FREQUENCY_16MHZ):
			/* Configure the timer control register
			 * 1. Non PWM mode FOC0=1
			 * 2. Normal Mode WGM01=0 & WGM00=0
			 * 3. Normal Mode COM00=0 & COM01=0
			 * 4. clock = F_CPU CS00=1 CS01=0 CS02=0
			 */
			TCCR0 =T0_PRESCALER_NO | (1<<COM01)| (1<<WGM00) | (1<<WGM01);
			break;

	case(T0_FREQUENCY_2MHZ):
			/* Configure the timer control register
			 * 1. Non PWM mode FOC0=1
			 * 2. Normal Mode WGM01=0 & WGM00=0
			 * 3. Normal Mode COM00=0 & COM01=0
			 * 4. clock = F_CPU/1024 CS00=0 CS01=1 CS02=0
			 */
			TCCR0 =T0_PRESCALER_8 | (1<<COM01)| (1<<WGM00) | (1<<WGM01);
			break;

	case(T0_FREQUENCY_250KHZ):
			/* Configure the timer control register
			 * 1. Non PWM mode FOC0=1
			 * 2. Normal Mode WGM01=0 & WGM00=0
			 * 3. Normal Mode COM00=0 & COM01=0
			 * 4. clock = F_CPU/1024 CS00=1 CS01=1 CS02=0
			 */
			TCCR0 =T0_PRESCALER_64 | (1<<COM01)| (1<<WGM00) | (1<<WGM01);
			break;

	case(T0_PRESCALER_62KHZ):
			/* Configure the timer control register
			 * 1. Non PWM mode FOC0=1
			 * 2. Normal Mode WGM01=0 & WGM00=0
			 * 3. Normal Mode COM00=0 & COM01=0
			 * 4. clock = F_CPU/1024 CS00=0 CS01=0 CS02=1
			 */
			TCCR0 =T0_PRESCALER_256 | (1<<COM01)| (1<<WGM00) | (1<<WGM01);
			break;

	case(T0_FREQUENCY_16KHZ):
			/* Configure the timer control register
			 * 1. Non PWM mode FOC0=1
			 * 2. Normal Mode WGM01=0 & WGM00=0
			 * 3. Normal Mode COM00=0 & COM01=0
			 * 4. clock = F_CPU/1024 CS00=1 CS01=0 CS02=1
			 */
			TCCR0 =T0_PRESCALER_1024 | (1<<COM01)| (1<<WGM00) | (1<<WGM01);
			break;
	}
}


/*==============================Timer1===============================*/


