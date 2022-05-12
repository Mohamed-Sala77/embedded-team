#include "Io.h" 
#include "initialization.h" 
#include "tm4c123gh6pm2.h" 
#include "functions.h" 

int main(){
	//MAIN_INIT
	//ON LCD () "PLZ ENTER SYMPOL"
    char orded = //KEYPAD_INP;
	switch (orded)
	{
	case 'A':
		//CLEAR LCD
		//PRINT "POPCORN"
		NUM_SEC (2);
		//CLEAR LCD
		//PRINT 1 MIN
		NUM_SEC (2);
		while (1)
		{
			if (GPIO_PORTE_DATA_R == 0x01)
		{
			if (GPIO_PORTF_DATA_R & 0X01 ==0;)
			{
				NUM_MIN(1);
				LED_END();
				// END "bUZZ" 
				break;
			}
			else // ON LCD "PLZ PUSH START"
		}
		else // ON LCD "PLZ CLOSE THE DOOR"
		}
		
		
		
		
		
		break;
	
	default:
		break;
	}
}

