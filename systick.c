#include "stm32l4xx.h"
#include "systick.h"

volatile int ticks=0;

void systickInit(void) {
	SysTick->CTRL = 0;
	SysTick->LOAD = 4000-1;
	SysTick->VAL = 0;
	SysTick->CTRL |= 1<<2;
	SysTick->CTRL |= 1<<0;
}

void systick80MHzInit(void){
	SysTick_Config (80);
}

void systickDelay(int ms) {
	int i;
	for(int i=0; i<ms; i++) {
	while((SysTick->CTRL & SysTick_CTRL_COUNTFLAG_Msk)==0){}
	}
}

void SysTick_Handler(void){
    ticks++;
}

//micros & millis
uint32_t millis(void) {
	return ticks/1000;
}

void delay(uint32_t ms) {
	uint32_t startTime = millis();
	while ((millis()-startTime)<ms){}
}

uint32_t micros(void) {
	return ticks;
}

void delayMicrosecondi(uint32_t us) {
	uint32_t startTime = micros();
	while((micros()-startTime)<us){}
}
