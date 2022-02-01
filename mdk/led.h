
//led rosso
void LedRedInit(void);
void LedRedOn(void);
void LedRedToggle(void);
void LedRedOff(void);

//led verde
void LedVerdeInit(void);
void LedVerdeOn(void);
void LedVerdeToggle(void);
void LedVerdeOff(void);

//led blink
void LedRedBlink(int ms, int nlampeggi);
void LedVerdeBlink(int ms, int nlampeggi);
void LedBlink(int nr);
void LedBlink2(int led, int nrlampeggi, int delayMs);

//delay
void Delay(int ms);

//led test
void LedTest(int nr);
