#include "led.h"
#include "systick.h"

  int main(){
	LedRedInit();
	LedVerdeInit();
	systickInit();

	while(1){
	LedRedOn();
	systickDelay(200);
	LedRedOff();
	LedVerdeOn();
	systickDelay(200);
	LedVerdeOff();
	}
}
