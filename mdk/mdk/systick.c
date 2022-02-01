#include "stm32l4xx.h"
#include "systick.h"

void systickInit(void) {
	SysTick->CTRL = 0;
	SysTick->LOAD = 4000-1;
	SysTick->VAL = 0;
	SysTick->CTRL |= 1<<2;
	SysTick->CTRL |= 1<<0;
}
void systickDelay(int ms) {
	for(int i=0; i<ms; i++)
	while((SysTick->CTRL & SysTick_CTRL_COUNTFLAG_Msk)==0){}
	}
