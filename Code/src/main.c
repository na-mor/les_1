#include "stm32f10x.h"
#define _delay_cycles	5000000
void delay(uint32_t time);

int main(void)
{
	RCC->APB2ENR |= RCC_APB2ENR_IOPCEN;
	
	GPIOC->CRH &= ~GPIO_CRH_CNF8;
	GPIOC->CRH |= GPIO_CRH_MODE8_0;
	
	GPIOC->CRH &= ~GPIO_CRH_CNF9;
	GPIOC->CRH |= GPIO_CRH_MODE9_0;
	
	//GPIOC->BSRR |= GPIO_BSRR_BS8;
	//GPIOC->BSRR |= GPIO_BSRR_BS9;
	
	while(1)
	{
		GPIOC->BSRR |= GPIO_BSRR_BS8;
		GPIOC->BSRR |= GPIO_BSRR_BR9;
		delay(_delay_cycles);
		GPIOC->BSRR |= GPIO_BSRR_BR8;
		GPIOC->BSRR |= GPIO_BSRR_BS9;
		delay(_delay_cycles);
	}
}


void delay(uint32_t time){
	uint32_t i = 0;
	for (i = 0; i < time; i++)
	{
		
	}
}