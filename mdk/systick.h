#include <stdint.h>

void systickInit(void);
void systickDelay(int ms);

void delayMicrosecondi(uint32_t us);
void delay(uint32_t ms);
void systick80MHzInit(void);
