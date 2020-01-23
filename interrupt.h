#ifndef INTERRUPT_H_
#define INTERRUPT_H_

/*
 * interrupts vector table
 */
#define RESET_ *((reg_type8_t)(0X000))
#define INT0_ *((reg_type8_t)(0X002))
#define INT1_ *((reg_type8_t)(0X004))
#define INT2_ *((reg_type8_t)(0X006))
#define TIMER2_COMP_ *((reg_type8_t)(0X008))
#define TIMER2_OVF_ *((reg_type8_t)(0X00A))
#define TIMER1_CAPT_ *((reg_type8_t)(0X00C))
#define TIMER1_COMPA_ *((reg_type8_t)(0X00E))
#define TIMER1_COMPB_ *((reg_type8_t)(0X010))
#define TIMER1_OVF_ *((reg_type8_t)(0X012))
#define TIMER0_COMP_ *((reg_type8_t)(0X014))
#define TIMER0_OVF_ *((reg_type8_t)(0X016))
#define SPI_STC_ *((reg_type8_t)(0X018))   /*serial transfer complete*/
#define USART_RXC_ *((reg_type8_t)(0X01A))
#define USART_UDRE_ *((reg_type8_t)(0X01C))
#define USART_TXC_ *((reg_type8_t)(0X01E))
#define ADC_ *((reg_type8_t)(0X020))
#define EE_RDY_ *((reg_type8_t)(0X022))
#define ANA_COMP_ *((reg_type8_t)(0X024))
#define TWI_ *((reg_type8_t)(0X026))
#define SPM_RDY_ *((reg_type8_t)(0X028))

/*
 * external interrupt registers
 *
 */
/*MCUCR register*/

#define ISC00 0
#define ISC01 1
#define ISC10 2
#define ISC11 3
#define SM0 4
#define SM1 5
#define SM2 6
#define SE 7

/*MCUCSR*/
#define PORF 0
#define EXTRF 1
#define BORF 2
#define WDRF 3
#define JTRF 4
/*reserved bit(bit5)*/
#define ISC2 6
#define JTD 7

/*GICR*/
#define IVCE 0
#define IVSEL 1
/*reserved bit(bit2)*/
/*reserved bit(bit3)*/
/*reserved bit(bit4)*/
#define INT2 5
#define INT0 6
#define INT1 7

/*GIFR*/
/*reserved bit(bit0)*/
/*reserved bit(bit1)*/
/*reserved bit(bit2)*/
/*reserved bit(bit3)*/
/*reserved bit(bit4)*/
#define INTF2 5
#define INTF0 6
#define INTF1 7


#define ISR_(vector, ...) void vector (void) __attribute__ \
	((signal, used, externally_visible)) __VA_ARGS__; void vector (void)


#define sei_()  __asm__ __volatile__ ("sei" ::)
#define cli_()  __asm__ __volatile__ ("cli" ::)


#endif /*INTERRUPT_H_*/

