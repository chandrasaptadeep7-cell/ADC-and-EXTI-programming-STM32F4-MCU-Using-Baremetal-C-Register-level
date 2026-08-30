
/*
 * STM32F40101CCU6
 *
 * PA0  -> ADC1_IN0 (Analog input)
 * PB1  -> EXTI1 input
 * PC13 -> External interrupt LED
 * PC15 -> ADC threshold LED
 *
 * ADC value >= 500
 *      -> PC15 blinks
 *
 * Falling edge on PB1
 *      -> PC13 WILL LOW
 */


#include <stdint.h>
#include "CCU6.h"


void ADC1_Init(void);
uint16_t ADC1_Read(void);
void delay(void);
void EXTI1_IRQHandler(void);
void EXTI_init(void);


volatile uint16_t adc_value;


int main(void)
{



    //ENABLE CLOCK FOR GPIO A, B,C
    RCC_AHB1ENR |= (7U << 0);

    //Enable ADC1 clock
    RCC_APB2ENR |= (1U << 8);

    // Enable SYSCFG clock
    RCC_APB2ENR |= (1U << 14);

	//ENABLE GPIO A0 AS ANALOG INPUT
	GPIOA_MODER &= ~(3U << 0);
	GPIOA_MODER |=  (3U << 0);

	//ENABLE GPIO B2 AS DIGITAL INPUT
	GPIOB_MODER &= ~(3U << 2);

	//ENABLE GPIO B2 AS PULL UP
	GPIOB_PUPDR &= ~(3U << 2);
	GPIOB_PUPDR |=  (1U << 2);

	//ENABLE C13 AS OUTPUT
	GPIOC_MODER &= ~(3U << 26);
	GPIOC_MODER |=  (1U << 26);

	//ENABLE C15 AS OUTPUT
	GPIOC_MODER &= ~(3U << 30);
	GPIOC_MODER |=  (1U << 30);


    ADC1_Init();

    EXTI_init();


    while(1)
    {



        adc_value = ADC1_Read();



         // If ADC >= 500

        if(adc_value >= 500)
        {
            GPIOC_ODR |= (1U << 15);	//PC15 HIGH
            delay();

            GPIOC_ODR &= ~(1U << 15); 	//PC15 LOW
            delay();
        } else {

            GPIOC_ODR &= ~(1U << 15);
        }
    }
}




void delay(void)
{
    for (uint32_t i = 0; i<= 1000000; i++);
}



void ADC1_Init(void)
{


	//SETTING BITS OF PPRE2 OF CFGR 0B110 TO AHB CLK / 8
    RCC_CFGR &= ~(7U << 13);
    RCC_CFGR |= (0b110 << 13);


    //SET ADC1 AS 12 BIT
    ADC1_CR1 &= ~(3U << 24);


    //SET THE ADC AS SINGLE CONVERSION MODE
    ADC1_CR2 &= ~(1U << 1);


    //RIGHT ALIGHNMENT
    ADC1_CR2 &= ~(1U << 11);


    // SELECT THE SAMPLING CYCLES OF ADC TO 15 CYCLES
    ADC1_SMPR2 &= ~(7U << 0);
    ADC1_SMPR2 |=  (1U << 0);


    /*
     * Regular sequence length = 1 conversion
     * SQR1 L bits 23:20
     * 0000 = 1 conversion
     */
    ADC1_SQR1 &= ~(0xFU << 20);


    /*
     * First conversion = channel 0
     * SQR3 SQ1 bits 4:0
     * Channel 0 = 00000
     */
    ADC1_SQR3 &= ~(0x1FU << 0);
    ADC1_SQR3 |=  (0U << 0);


    //Enable ADC
    ADC1_CR2 |= (1U << 0);
}



uint16_t ADC1_Read(void)
{
    // Start regular conversion IN REGULAR CHANNEL
    ADC1_CR2 |= (1U << 30);


    //Wait until conversion is complete
    while((ADC1_SR & (1U << 1)) == 0)
    {
    }


    //RETURN CONVERTED DECIMAL VALUE FROM THE ADC
    return ((uint16_t)ADC1_DR);
}


//ISR function
void EXTI1_IRQHandler(void)
{

    //Check whether EXTI1 caused the interrupt
    if(EXTI_PR & (1U << 1))
    {

        GPIOC_ODR ^= (1U << 13);

        //Clear pending bit
        EXTI_PR |= (1U << 1);
    }
}


void EXTI_init(void)
{
	    //SELECT B1 AS INTERRUPT INPUT
	    SYSCFG_EXTICR1 &= ~(0b1111 << 4);
	    SYSCFG_EXTICR1 |=  (0b0001 << 4);


	    //ALLOW B1 TO HANDLE INTERRUPT SIGNAL
	    EXTI_IMR |= (1U << 1);


	    // DESABLE RISING EDGE TREIGGERING
	    EXTI_RTSR &= ~(1U << 1);


	    //ENABLE FALLING EDGE TREIGGERING
	    EXTI_FTSR |= (1U << 1);


	    /*
		  ENABLE EXTI1 INTERRUPT IN NVIC
		  EXTI1_IRQn = IRQ 7 on Cortex-M4 STM32F401
		  NVIC ISER0 bit 7
	     */
	    NVIC_ISER0 |= (1U << 7);
}




