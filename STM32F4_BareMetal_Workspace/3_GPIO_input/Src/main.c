#include "stm32f4xx.h"

#define GPIOAEN		(1U<<0)
#define GPIOCEN		(1U<<2)


#define PIN5		(1U<<5)
#define PIN13		(1U<<13)

#define LED_PIN		PIN5
#define BTN_PIN		PIN13

int main(void){
	/*1. Enable clock access to GPIOA*/
	RCC->AHB1ENR |= GPIOAEN;
	RCC->AHB1ENR |= GPIOCEN;
	/*2. Set PA5 as output pin*/
	GPIOA->MODER |= (1U<<10);
	GPIOA->MODER &= ~(1U<<11);
	/* Set PC13 as input port */
	GPIOC->MODER &=~(1U<<26);
	GPIOC->MODER &=~(1U<<27);

	while(1)
	{
		/* Check if button is pressed*/
		if(!(GPIOC->IDR & BTN_PIN))
		{
			/*Set PA5 as high*/
			GPIOA->BSRR = LED_PIN;
		}
		GPIOA->BSRR = (1U<<21);
	}
}
