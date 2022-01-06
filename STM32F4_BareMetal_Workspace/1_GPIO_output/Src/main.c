#include "stm32f4xx.h"

#define GPIOAEN		(1U<<0)
#define PIN5		(1U<<5)
#define LED_PIN		PIN5


int main(void){
	/*1. Enable clock access to GPIOA*/
	RCC->AHB1ENR |=GPIOAEN;
	/*2. Set PA5 as output pin*/
	GPIOA->MODER |= (1U<<10);
	GPIOA->MODER	&= ~(1U<<11);
	while(1)
	{
		/*Set PA5 as high*/
		GPIOA->ODR ^= LED_PIN;
		for(int i=0; i<=100000;i++){}
	}
}
