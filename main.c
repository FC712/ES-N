#include "led.h"
#include "systick.h"
#include "joystick.h"

  int main(){
	LedRedInit();
	LedVerdeInit();
  PulsInit();
	setintPA0re();
	setintPA1re();
	setintPA2re();
  setintPA3re();
	setintPA5re();

	while(1){
    }
	
}
