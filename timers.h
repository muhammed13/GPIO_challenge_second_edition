#ifndef TIMERS_H_
#define TIMERS_H_

#include "registers.h"
#include "gpio.h"
#include "common_macros.h"
/*
 * User Configuration Macros
 */
#define cpu_frq 16000000
#define TIMER0_OVER_FLOW_VALUE 256
#ifndef SEC
#define SEC 1000
#endif

#define MS_OCR_value 250
#define US_OCR_value 16

#define T0_PWM_GPIO	GPIOD
#define T0_PWM_BIT	BIT0

#define T1_PWM_GPIO	GPIOD
#define T1_PWM_BIT	BIT1

#define T2_PWM_GPIO GPIOD
#define T2_PWM_BIT	BIT2

typedef enum En_timer0Mode_t{
	T0_NORMAL_MODE=0,T0_COMP_MODE=0x08
}En_timer0Mode_t;

typedef enum En_timer0OC_t{
	T0_OC0_DIS=0,T0_OC0_TOGGLE=0x10,T0_OC0_CLEAR=0x20,T0_OC0_SET=0x30
}En_timer0OC_t;

typedef enum En_timer0perscaler_t{
	T0_NO_CLOCK=0,T0_PRESCALER_NO=0x01,T0_PRESCALER_8=0x02,T0_PRESCALER_64=0x03,T0_PRESCALER_256=0x04,T0_PRESCALER_1024=0x05
}En_timer0perscaler_t;

typedef enum En_timer0Interrupt_t{
	T0_POLLING=0,T0_INTERRUPT_NORMAL=0x01,T0_INTERRUPT_CMP=0x02
}En_timer0Interrupt_t;

typedef enum En_timer0frequency_t{
	T0_FREQUENCY_16MHZ=0x01,T0_FREQUENCY_2MHZ=0x02,T0_FREQUENCY_250KHZ=0x03,T0_PRESCALER_62KHZ=0x04,T0_FREQUENCY_16KHZ=0x05
}En_timer0frequency_t;



// for timer 1
typedef enum En_timer1Mode_t{
	T1_NORMAL_MODE=0x0000,T1_COMP_MODE_OCR1A_TOP=0x0008, T1_COMP_MODE_ICR1_TOP = 0x0018

}En_timer1Mode_t;
typedef enum En_timer1OC_t{
	T1_OC1_DIS=0,T1_OC1A_TOGGLE=0x4000,T1_OC1B_TOGGLE=0x1000,T1_OC1A_CLEAR=0x8000,T1_OC1B_CLEAR=0x2000,T1_OC1A_SET=0xC000,T1_OC1B_SET=0x3000
}En_timer1OC_t;

typedef enum En_timer1perscaler_t{
	T1_NO_CLOCK=0x0000,T1_PRESCALER_NO=0x0001,T1_PRESCALER_8=0x0002,T1_PRESCALER_64=0x0003,T1_PRESCALER_256=0x0004,T1_PRESCALER_1024=0x0005
}En_timer1perscaler_t;

typedef enum En_timer1Interrupt_t{
	T1_POLLING=0,T1_INTERRUPT_NORMAL=0x04,T0_INTERRUPT_CMP_1B=0x08, T1_INTERRUPT_CMP_1A=0x10, T1_INTERRUPT_ICAPTURE = 0x20
}En_timer1Interrupt_t;




// for timer 2
typedef enum En_timer2Mode_t{
	T2_NORMAL_MODE=0,T2_COMP_MODE=0x08
}En_timer2Mode_t;

typedef enum En_timer2OC_t{
	T2_OC2_DIS=0,T2_OC2_TOGGLE=0x10,T2_OC2_CLEAR=0x20,T2_OC2_SET=0x30
}En_timer2OC_t;

typedef enum En_timer2perscaler_t{
	T2_NO_CLOCK=0,T2_PRESCALER_NO=0x01,T2_PRESCALER_8=0x02, T2_PRESCALER_32=0x03, T2_PRESCALER_64=0x04, T2_PRESCALER_128=0x05, T2_PRESCALER_256 = 0x06, T2_PRESCALER_1024=0x07
}En_timer2perscaler_t;

typedef enum En_timer2Interrupt_t{
	T2_POLLING=0,T2_INTERRUPT_NORMAL=0x40,T2_INTERRUPT_CMP=0x80
}En_timer2Interrupt_t;







/*===========================Timer0 Control===============================*/
/**
 * Description:
 * @param control
 * @param initialValue
 * @param outputCompare
 * @param interruptMask
 */
void timer0Init(En_timer0Mode_t en_mode,En_timer0OC_t en_OC0,En_timer0perscaler_t en_prescal, uint8_t u8_initialValue, uint8_t u8_outputCompare, En_timer0Interrupt_t en_interruptMask);

/**
 * Description:
 * @param value
 */
void timer0Set(uint8_t u8_value);

/**
 * Description:
 * @return
 */
uint8_t timer0Read(void);

/**
 * Description:
 */
void timer0Start(void);

/**
 * Description:
 */
void timer0Stop(void);

/**
 * Description:
 * @param delay
 */
void timer0DelayMs(uint16_t u16_delay_in_ms);

/*
 * user defined
 */
void timer0DelayUs(uint32_t u32_delay_in_us);

/**
 * Description:
 * @param dutyCycle
 */
void timer0SwPWM(uint8_t u8_dutyCycle,uint8_t u8_frequency);









/*===========================Timer1 Control===============================*/
/**
 * Description:
 * @param controlA
 * @param controlB
 * @param initialValue
 * @param outputCompare
 * @param interruptMask
 */
void timer1Init(En_timer1Mode_t en_mode,En_timer1OC_t en_OC,En_timer1perscaler_t en_prescal, uint16_t u16_initialValue, uint16_t u16_outputCompareA, uint16_t u16_outputCompareB,uint16_t u16_inputCapture, En_timer1Interrupt_t en_interruptMask);

/**
 * Description:
 * @param value
 */
void timer1Set(uint16_t u16_value);

/**
 * Description:
 * @return
 */
uint16_t timer1Read(void);

/**
 * Description:
 */
void timer1Start(void);

/**
 * Description:
 */
void timer1Stop(void);

/**
 * Description:
 * @param delay
 */
void timer1DelayMs(uint16_t u16_delay_in_ms);

/*
 * user defined
 */
void timer1DelayUs(uint32_t u32_delay_in_us);

/**
 * Description:
 * @param dutyCycle
 */
void timer1SwPWM(uint8_t u8_dutyCycle,uint8_t u8_frequency);





/*===========================Timer2 Control===============================*/
/**
 * Description:
 * @param control
 * @param initialValue
 * @param outputCompare
 * @param interruptMask
 */
void timer2Init(En_timer2Mode_t en_mode,En_timer2OC_t en_OC,En_timer2perscaler_t en_prescal, uint8_t u8_initialValue, uint8_t u8_outputCompare, uint8_t u8_assynchronous, En_timer2Interrupt_t en_interruptMask);
/**
 * Description:
 * @param value
 */
void timer2Set(uint8_t u8_a_value);

/**
 * Description:
 * @return
 */
uint8_t timer2Read(void);

/**
 * Description:
 */
void timer2Start(void);

/**
 * Description:
 */
void timer2Stop(void);

/**
 * Description:
 * @param delay
 */
void timer2DelayMs(uint16_t u16_delay_in_ms);

/*
 * user defined
 */
void timer2DelayUs(uint32_t u16_delay_in_us);

/**
 * Description:
 * @param dutyCycle
 */
void timer2SwPWM(uint8_t u8_dutyCycle,uint8_t u8_frequency);



/*===========================TIMERS GENERAL REGISTERS===============================*/

/*==================TIMSK======================*/
#define TOIE0 0	    // defines BIT0 in a TIMSK register
#define OCIE0 1	    // defines BIT1 in a TIMSK register
#define TOIE1 2	    // defines BIT2 in a TIMSK register
#define OCIE1B 3	// defines BIT3 in a TIMSK register
#define OCIE1A 4	// defines BIT4 in a TIMSK register
#define TICIE1 5	// defines BIT5 in a TIMSK register
#define TOIE2 6	    // defines BIT6 in a TIMSK register
#define OCIE2 7	   // defines BIT7 in a TIMSK register

/*===================TIFR=====================*/
#define TOV0 0	  // defines BIT0 in a TIMSK register
#define OCF0 1	  // defines BIT1 in a TIMSK register
#define TOV1 2	  // defines BIT2 in a TIMSK register
#define OCF1B 3	  // defines BIT3 in a TIMSK register
#define OCF1A 4	  // defines BIT4 in a TIMSK register
#define ICF1 5	  // defines BIT5 in a TIMSK register
#define TOV2 6	  // defines BIT6 in a TIMSK register
#define OCF2 7	  // defines BIT7 in a TIMSK register



/*===========================TIMER0 Registers Bits Definitions===============================*/

/*==================TCCR0======================*/
#define CS00 0	 // defines BIT0 in a TCCR0 register
#define CS01 1	 // defines BIT1 in a TCCR0 register
#define CS02 2	 // defines BIT2 in a TCCR0 register
#define WGM01 3	 // defines BIT3 in a TCCR0 register
#define COM00 4	 // defines BIT4 in a TCCR0 register
#define COM01 5	 // defines BIT5 in a TCCR0 register
#define WGM00 6	 // defines BIT6 in a TCCR0 register
#define FOC0 7	 // defines BIT7 in a TCCR0 register

/*these defines shouldn't be changing to 0 to 7 */
#endif /* TIMERS_H_ */
