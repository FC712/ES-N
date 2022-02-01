#include <stdint.h>
#include "stm32l4xx.h"                  // Device header

void MSIInit(uint8_t range);
void pllInit(uint8_t M, uint8_t N, uint8_t R);
void SysClockInit(void);
