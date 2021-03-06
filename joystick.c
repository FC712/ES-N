#include "stm32l4xx.h"                  
#include "joystick.h"
#include "led.h"

void PulsInit(void) {
	
	RCC->AHB2ENR |= RCC_AHB2ENR_GPIOAEN;
	
	//pulsante centrale
	GPIOA->MODER &= ~GPIO_MODER_MODER0_0;
	GPIOA->MODER &= ~GPIO_MODER_MODER0_1;
	
	GPIOA->PUPDR &= ~GPIO_MODER_MODER0_0;
	GPIOA->PUPDR |= GPIO_MODER_MODER0_1;

	//pulsante sinistro
	GPIOA->MODER &= ~GPIO_MODER_MODER1_0;
	GPIOA->MODER &= ~GPIO_MODER_MODER1_1;
	
	GPIOA->PUPDR &= ~GPIO_MODER_MODER1_0;
	GPIOA->PUPDR |= GPIO_MODER_MODER1_1;
	
	//pulsante destro
	GPIOA->MODER &= ~GPIO_MODER_MODER2_0;
	GPIOA->MODER &= ~GPIO_MODER_MODER2_1;
	
	GPIOA->PUPDR &= ~GPIO_MODER_MODER2_0;
	GPIOA->PUPDR |= GPIO_MODER_MODER2_1;
	
	//pulsante su
	GPIOA->MODER &= ~GPIO_MODER_MODER3_0;
	GPIOA->MODER &= ~GPIO_MODER_MODER3_1;
	
	GPIOA->PUPDR &= ~GPIO_MODER_MODER3_0;
	GPIOA->PUPDR |= GPIO_MODER_MODER3_1;
	
	//pulsante gi?
	GPIOA->MODER &= ~GPIO_MODER_MODER5_0;
	GPIOA->MODER &= ~GPIO_MODER_MODER5_1;
	
	GPIOA->PUPDR &= ~GPIO_MODER_MODER5_0;
	GPIOA->PUPDR |= GPIO_MODER_MODER5_1;
}


int PulsRead(void) {

		//Pulsante centrale
		return GPIOA->IDR & GPIO_IDR_ID0_Msk;

		//Pulsante sinistra
		return GPIOA->IDR & GPIO_IDR_ID1_Msk;
		
		//Pulsante destra
		return GPIOA->IDR & GPIO_IDR_ID2_Msk;

		//Pulsante su
		return GPIOA->IDR & GPIO_IDR_ID3_Msk;
		
		//Pulsante gi?
		return GPIOA->IDR & GPIO_IDR_ID5_Msk;
}


void setintPA0re(void) {
	SYSCFG->EXTICR[0] &= ~SYSCFG_EXTICR1_EXTI0_Msk;
	SYSCFG->EXTICR[0] |= SYSCFG_EXTICR1_EXTI0_PA;
	EXTI->RTSR1 |= EXTI_RTSR1_RT0;
	EXTI->FTSR1 &= EXTI_RTSR1_RT0;
	EXTI->IMR1 |= EXTI_IMR1_IM0;
  NVIC_SetPriority(EXTI0_IRQn,0);
  NVIC_EnableIRQ(EXTI0_IRQn);	
}
	

void setintPA1re(void) {
	SYSCFG->EXTICR[0] &= ~SYSCFG_EXTICR1_EXTI1_Msk;
	SYSCFG->EXTICR[0] |= SYSCFG_EXTICR1_EXTI1_PA;
	EXTI->RTSR1 |= EXTI_RTSR1_RT1;
	EXTI->FTSR1 &= EXTI_RTSR1_RT1;
	EXTI->IMR1 |= EXTI_IMR1_IM1;
  NVIC_SetPriority(EXTI1_IRQn,0);
  NVIC_EnableIRQ(EXTI1_IRQn);	
}


void setintPA2re(void) {
	SYSCFG->EXTICR[0] &= ~SYSCFG_EXTICR1_EXTI2_Msk;
	SYSCFG->EXTICR[0] |= SYSCFG_EXTICR1_EXTI2_PA;
	EXTI->RTSR1 |= EXTI_RTSR1_RT2;
	EXTI->FTSR1 &= EXTI_RTSR1_RT2;
	EXTI->IMR1 |= EXTI_IMR1_IM2;
  NVIC_SetPriority(EXTI2_IRQn,0);
  NVIC_EnableIRQ(EXTI2_IRQn);	
}


	void setintPA3re(void) {
	SYSCFG->EXTICR[0] &= ~SYSCFG_EXTICR1_EXTI3_Msk;
	SYSCFG->EXTICR[0] |= SYSCFG_EXTICR1_EXTI3_PA;
	EXTI->RTSR1 |= EXTI_RTSR1_RT3;
	EXTI->FTSR1 &= EXTI_RTSR1_RT3;
	EXTI->IMR1 |= EXTI_IMR1_IM3;
  NVIC_SetPriority(EXTI3_IRQn,0);
  NVIC_EnableIRQ(EXTI3_IRQn);	
}
	

void setintPA5re(void) {
	SYSCFG->EXTICR[0] &= ~SYSCFG_EXTICR2_EXTI5_Msk;
	SYSCFG->EXTICR[0] |= SYSCFG_EXTICR2_EXTI5_PA;
	EXTI->RTSR1 |= EXTI_RTSR1_RT5;
	EXTI->FTSR1 &= EXTI_RTSR1_RT5;
	EXTI->IMR1 |= EXTI_IMR1_IM5;
  NVIC_SetPriority(EXTI9_5_IRQn,0);
  NVIC_EnableIRQ(EXTI9_5_IRQn);	
}


void EXTI0_IRQHandler(void) {
	LedRedToggle();
	LedVerdeToggle();
	EXTI->PR1 |= EXTI_PR1_PIF0;
}


void EXTI1_IRQHandler(void) {
	LedVerdeOn();
	EXTI->PR1 |= EXTI_PR1_PIF1;
}


void EXTI2_IRQHandler(void) {
	LedVerdeOff();
	EXTI->PR1 |= EXTI_PR1_PIF2;
}


void EXTI3_IRQHandler(void) {
	LedRedOff();
	EXTI->PR1 |= EXTI_PR1_PIF3;
}


void EXTI9_5_IRQHandler(void) {
	LedRedOn();
	EXTI->PR1 |= EXTI_PR1_PIF5;
}
