#include "initialization.h"

void Buzzer_ON(){
	GPIO_PORTE_DATA_R |= 0x08;
}

void Buzzer_OFF(){
	GPIO_PORTE_DATA_R &= ~0x08;
}
