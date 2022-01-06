//Where is the led connected?
//Port: A
//Pin: 5
#include <stdio.h>
#define PERIPH_BASE		(0x40000000UL)

#define AHB1_OFFSET		(0x00020000UL)
#define AHB1_BASE		(PERIPH_BASE + AHB1_OFFSET)

#define GPIOA_OFFSET	(0x00000000UL)
#define GPIOA_BASE		(AHB1_BASE + GPIOA_OFFSET)

#define RCC_OFFSET		(0x00003800UL)
#define RCC_BASE		(AHB1_BASE + RCC_OFFSET)

//#define AHB1EN_R_OFFSET	(0x30UL)
//#define RCC_AHB1EN_R	(*(volatile unsigned int *)(RCC_BASE + AHB1EN_R_OFFSET))
//
//#define MODE_R_OFFSET	(0x0000UL)
//#define GPIO_MODE_R		(*(volatile unsigned int *)(GPIOA_BASE + MODE_R_OFFSET))
//
//#define OD_R_OFFSET		(0x14UL)
//#define GPIOA_OD_R		(*(volatile unsigned int *)(GPIOA_BASE + OD_R_OFFSET))

#define GPIOAEN			(1U<<0) //0b 0000 0000 0000 0000 0000 0000 0000 0000

#define PIN5			(1U<<5)
#define LED_PIN			PIN5
#define __IO	volatile



typedef struct
 {

__IO uint32_t MODER; /*!< GPIO port mode register, Address offset: 0x00 */
__IO uint32_t OTYPER; /*!< GPIO port output type register, Address offset: 0x04 */
__IO uint32_t OSPEEDR; /*!< GPIO port output speed register, Address offset: 0x08 */
__IO uint32_t PUPDR; /*!< GPIO port pull-up/pull-down register, Address offset: 0x0C */
__IO uint32_t IDR; /*!< GPIO port input data register, Address offset: 0x10 */
__IO uint32_t ODR; /*!< GPIO port output data register, Address offset: 0x14 */
__IO uint16_t BSRRL; /*!< GPIO port bit set/reset low register, Address offset: 0x18 */
__IO uint16_t BSRRH; /*!< GPIO port bit set/reset high register, Address offset: 0x1A */
__IO uint32_t LCKR; /*!< GPIO port configuration lock register, Address offset: 0x1C */
__IO uint32_t AFR[2]; /*!< GPIO alternate function registers, Address offset: 0x20-0x24 */
__IO uint32_t BRR; /*!< GPIO bit reset register, Address offset: 0x28 */
}GPIO_TypeDef;

/* Reset and Clock Control Registers (RCC), Address Range: 0x4002 3800 - 0x4002 3BFF */
typedef struct
{
 __IO uint32_t CR;            /* Offset: 0x00 (R/W) Clock Control Register                                 */
 __IO uint32_t PLLCFGR;       /* Offset: 0x04 (R/W) PLL Configuration Register                             */
 __IO uint32_t CFGR;          /* Offset: 0x08 (R/W) Clock Configuration Register                           */
 __IO uint32_t CIR;           /* Offset: 0x0C (R/W) Clock Interrupt Register                               */
 __IO uint32_t AHB1RSTR;      /* Offset: 0x10 (R/W) AHB1 Peripheral Reset Register                         */
 __IO uint32_t AHB2RSTR;      /* Offset: 0x14 (R/W) AHB2 Peripheral Reset Register                         */
 __IO uint32_t AHB3RSTR;      /* Offset: 0x18 (R/W) AHB3 Peripheral Reset Register                         */
 __IO uint32_t reserved0;
 __IO uint32_t APB1RSTR;      /* Offset: 0x20 (R/W) APB1 Peripheral Reset Register                         */
 __IO uint32_t APB2RSTR;      /* Offset: 0x24 (R/W) APB2 Peripheral Reset Register                         */
 __IO uint32_t reserved1[2];
 __IO uint32_t AHB1ENR;       /* Offset: 0x30 (R/W) AHB1 Peripheral Clock Enable Register                  */
 __IO uint32_t AHB2ENR;       /* Offset: 0x34 (R/W) AHB2 Peripheral Clock Enable Register                  */
 __IO uint32_t AHB3ENR;       /* Offset: 0x38 (R/W) AHB3 Peripheral Clock Enable Register                  */
 __IO uint32_t reserved2;
 __IO uint32_t APB1ENR;       /* Offset: 0x40 (R/W) APB1 Peripheral Clock Enable Register                  */
 __IO uint32_t APB2ENR;       /* Offset: 0x44 (R/W) APB1 Peripheral Clock Enable Register                  */
 __IO uint32_t reserved3[2];
 __IO uint32_t AHB1LPENR;     /* Offset: 0x50 (R/W) AHB1 Peripheral Clock Enable Lower Power Mode Register */
 __IO uint32_t AHB2LPENR;     /* Offset: 0x54 (R/W) AHB2 Peripheral Clock Enable Lower Power Mode Register */
 __IO uint32_t AHB3LPENR;     /* Offset: 0x58 (R/W) AHB3 Peripheral Clock Enable Lower Power Mode Register */
 __IO uint32_t reserved4;
 __IO uint32_t APB1LPENR;     /* Offset: 0x60 (R/W) APB1 Peripheral Clock Enable Lower Power Mode Register */
 __IO uint32_t APB2LPENR;     /* Offset: 0x64 (R/W) APB2 Peripheral Clock Enable Lower Power Mode Register */
 __IO uint32_t reserved5[2];
 __IO uint32_t BDCR;          /* Offset: 0x70 (R/W) Backup Domain Control Register                         */
 __IO uint32_t CSR;           /* Offset: 0x74 (R/W) Clock Control & Status Register                        */
 __IO uint32_t reserved6[2];
 __IO uint32_t SSCGR;         /* Offset: 0x80 (R/W) Spread Spectrum Clock Generation Register              */
 __IO uint32_t PLLI2SCFGR;    /* Offset: 0x84 (R/W) PLLI2S Configuration Register                          */
 __IO uint32_t PLLSAICFGR;    /* Offset: 0x88 (R/W) PLLSAI Configuration Register                          */
 __IO uint32_t DCKCFGR;       /* Offset: 0x8C (R/W) Dedicated Clocks Configuration Register                */
 __IO uint32_t CKGATENR;      /* Offset: 0x90 (R/W) Clocks Gated Enabled Register                          */
 __IO uint32_t DCKCFGR2;      /* Offset: 0x94 (R/W) Dedicated Clocks Configuration Register 2              */
} RCC_TypeDef;


#define RCC		((RCC_TypeDef *) RCC_BASE)
#define GPIOA	((GPIO_TypeDef *) GPIOA_BASE)

int main(void){
	/*1. Enable clock access to GPIOA*/
	RCC->AHB1ENR |= GPIOAEN;
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
