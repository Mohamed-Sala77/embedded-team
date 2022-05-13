#include "Io.h" 
#include <math.h>
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
	

		case 'B':
		char weight=0;
		float BEEF_TIME;
		int int_Btime;
		float frac_Btime;
		int sec_Btime;
		// ON LCD "Beef weight?
		weight=//  FROM KEYBAD INPUT
		//keypad out 
		NUM_SEC(2);
		//lcd clear
        while(weight==0){};
		BEEF_TIME=MIN_BEEF(weight);
		int_Btime=BEEF_TIME;
		frac_Btime=BEEF_TIME-int_Btime;
		sec_Btime=frac_Btime*60;
					
		while(1){
		if (BEEF_TIME<=4.5)
		{
			if (GPIO_PORTE_DATA_R == 0x01)
		{
			if (GPIO_PORTF_DATA_R & 0X01 ==0;)
			{
				//on lcd time
				NUM_MIN(int_Btime);
				NUM_SEC(sec_Btime);
				LED_END();
				// END "bUZZ" 
				break;
			}
			else // ON LCD "PLZ PUSH START"
		}
		else // ON LCD "PLZ CLOSE THE DOOR"
		}
		else
		{
			//plz frrom 1 TO 9
			NUM_SEC(2);
		}				 
		}
		break;

		case 'c':
		char weight=0;
		float chicken_TIME;
		int int_ctime;
		float frac_ctime;
		int sec_ctime;
		// ON LCD "Beef weight?
		weight=//  FROM KEYBAD INPUT
		//keypad out 
		NUM_SEC(2);
		//lcd clear
        while(weight==0){/*err*/};
		chicken_TIME=MIN_CHICKEN(weight);
		int_ctime=chicken_TIME;
		frac_ctime=chicken_TIME-int_ctime;
		sec_ctime=frac_ctime*60;
					
		while(1){
		if (chicken_TIME<=1.8)
		{
			if (GPIO_PORTE_DATA_R == 0x01)
		{
			if (GPIO_PORTF_DATA_R & 0X01 ==0;)
			{
				//on lcd time
				NUM_MIN(int_ctime);
				NUM_SEC(sec_ctime);
				LED_END();
				// END "bUZZ" 
				break;
			}
			else // ON LCD "PLZ PUSH START"
		}
		else // ON LCD "PLZ CLOSE THE DOOR"
		}
		else
		{
			//plz frrom 1 TO 9
			NUM_SEC(2);
		}				 
		}
		break;

		case 'D':
		int Timer_min,Timer_sec;
		//CLEAR LCD
		//PRINT "ENTERE TIME"
		NUM_SEC (2);
		Timer_min,Timer_sec = TIMER_D();
		while (1)
		{
			if (GPIO_PORTE_DATA_R == 0x01)
		{
			if (GPIO_PORTF_DATA_R & 0X01 ==0;)
			{
				
				NUM_MIN(Timer_min);
				NUM_SEC(Timer_sec);
				LED_END();
				// END "bUZZ" 
				break;
			}
			else // ON LCD "PLZ PUSH START"
		}
		else // ON LCD "PLZ CLOSE THE DOOR"
			
		}
		break;

	default://on lcd error input .
		break;
	}
}

