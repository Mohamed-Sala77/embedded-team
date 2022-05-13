#include "initialization.h"

unsigned char SW3(){
	char SW3_IN;
	SW3_IN = GPIO_PORTE_DATA_R &= 0x01;
	return(SW3_IN);
}
