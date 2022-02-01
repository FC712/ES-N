
void PulsInit(void);
int PulsRead(void);

//interrupt
void setintPA0re(void);
void setintPA1re(void);
void setintPA2re(void);
void setintPA3re(void);
void setintPA5re(void);

void EXTI0_IRQHandler(void);
void EXTI1_IRQHandler(void);
void EXTI2_IRQHandler(void);
void EXTI3_IRQHandler(void);
void EXTI9_5_IRQHandler(void);
