//Where is the led connected?
//Port: A
//Pin: 5
#define PERIPH_BASE		(0x40000000UL)

#define AHB1_OFFSET		(0x00020000UL)
#define AHB1_BASE		(PERIPH_BASE + AHB1_OFFSET)

#define GPIOA_OFFSET	(0x00000000UL)
#define GPIOA_BASE		(AHB1_BASE + GPIOA_OFFSET)

#define RCC_OFFSET		(0x00003800UL)
#define RCC_BASE		(AHB1_BASE + RCC_OFFSET)

#define AHB1EN_R_OFFSET	(0x30UL)
#define RCC_AHB1EN_R	(*(volatile unsigned int *)(RCC_BASE + AHB1EN_R_OFFSET))

#define MODE_R_OFFSET	(0x0000UL)
#define GPIO_MODE_R		(*(volatile unsigned int *)(GPIOA_BASE + MODE_R_OFFSET))

#define OD_R_OFFSET		(0x14UL)
#define GPIOA_OD_R		(*(volatile unsigned int *)(GPIOA_BASE + OD_R_OFFSET))

#define GPIOAEN			(1U<<0) //0b 0000 0000 0000 0000 0000 0000 0000 0000

#define PIN5			(1U<<5)
#define LED_PIN			PIN5
/*
 * (1U<<10) 	//Set bit 10 to 1
 * ~(1U<<11)	//Set bit 11 to 0
 * */
int main(void){
	/*1. Enable clock access to GPIOA*/
	RCC_AHB1EN_R |= GPIOAEN;
	/*2. Set PA5 as output pin*/
	GPIO_MODE_R |= (1U<<10);
	GPIO_MODE_R	&= ~(1U<<11);
	while(1)
	{
		/*Set PA5 as high*/
		GPIOA_OD_R ^= LED_PIN;
		for(int i=0; i<=100000;i++){}
	}
}
