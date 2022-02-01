#include "stm32l4xx.h"
#include  "led.h"
#include "systick.h"

#define RED 1
#define VERDE 2

//led rosso
	void LedRedInit(void) {
	RCC->AHB2ENR |= RCC_AHB2ENR_GPIOBEN;
	GPIOB->MODER |= GPIO_MODER_MODE2_0;
	GPIOB->MODER &= ~GPIO_MODER_MODE2_1;
}

	void LedRedOn(void) {
	GPIOB->ODR |= GPIO_ODR_OD2;
}

	void LedRedOff(void) {
	GPIOB->ODR &= ~GPIO_ODR_OD2;
}
	
  void LedRedToggle(void) {
	GPIOB->ODR ^= GPIO_ODR_OD2;
}

	void LedRedBlink(int ms)	{
	int a=0;
	while(a<10){
		LedRedToggle();
		systickDelay(ms);
		a++;
	}
}


//led verde
	void LedVerdeInit(void) {	
	RCC->AHB2ENR |= RCC_AHB2ENR_GPIOEEN;
	GPIOE->MODER |= GPIO_MODER_MODE8_0;
	GPIOE->MODER &= ~GPIO_MODER_MODE8_1;
}

	void LedVerdeOn(void) {
	GPIOE->ODR |= GPIO_ODR_OD8;
}
	
	void LedVerdeOff(void) {
	GPIOE->ODR &= ~GPIO_ODR_OD8;
}
	
	void LedVerdeToggle(void) {
	GPIOE->ODR ^= GPIO_ODR_OD8;
}

	void LedVerdeBlink(int ms)	{
	int a=0;
	while(a<10){
		LedVerdeToggle();
		systickDelay(ms);
		a++;
	}
}


//led blink
void LedBlink(void) {
	int ms=500;
	LedRedBlink(ms);
	LedVerdeBlink(ms);
}


//led blink 2
void LedBlink2(int led, int nBlink, int delayMs) {
	int ms=delayMs;
	int;
	switch (led) {
	  case 1;
		LedRedBlink(ms);
	  break;
	  case 2;
	    LedVerdeBlink(ms);
	  break;
	