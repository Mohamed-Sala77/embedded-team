#include "Io.h" 
#include "tm4c123gh6pm2.h" 
#include "stdint.h"
#include "string.h"
#include "initialization & functions.h"
///////////////////////////////////////////////

int main(){
		char weight=0;
		double BEEF_TIME;
		int int_Btime;
		double frac_Btime;
		int sec_Btime;
		double chicken_TIME;
		int int_ctime;
		double frac_ctime;
		int sec_ctime;
		int Timer_min,Timer_sec;
		char order =Keypad_Out();
		MAIN_INIT();
	//ON LCD () "PLZ ENTER SYMPOL"
		
    
	switch (order)
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
			if (check_door ())
		{
			if ((GPIO_PORTF_DATA_R & 0X01 )==0)
			{
                LCD_ascii("01:00");//nem_sec decrease
				NUM_MIN(1);
				LED_END();
				// END "bUZZ" 
				break;
			}
			LCD_ascii("PLZ PUSH START" );
		}
		LCD_ascii("PLZ CLOSE THE DOOR");
		}
		break;
		case 'B':
		LCD_ascii("Beef weight?");
		weight=0;//  FROM KEYBAD INPUT
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
			if (check_door ())
		{
			if ((GPIO_PORTF_DATA_R & 0X01) ==0x00)
			{
				//on lcd time
				NUM_MIN(int_Btime);
				NUM_SEC(sec_Btime);
				LED_END();
				// END "bUZZ" 
				break;
			}
			//else  ON LCD "PLZ PUSH START"
		}
		//else  ON LCD "PLZ CLOSE THE DOOR"
		}
		else
		{
			//plz frrom 1 TO 9
			NUM_SEC(2);
		}				 
		}
		break;

		case 'c':
		// ON LCD "Beef weight?
		weight=0;//  FROM KEYBAD INPUT
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
			if (check_door ())
		{
			if ((GPIO_PORTF_DATA_R & 0X01) ==0x00)
			{
				//on lcd time
				NUM_MIN(int_ctime);
				NUM_SEC(sec_ctime);
				LED_END();
				// END "bUZZ" 
				break;
			}
			//else  ON LCD "PLZ PUSH START"
		}
		//else ON LCD "PLZ CLOSE THE DOOR"
		}
		else
		{
			//plz frrom 1 TO 9
			NUM_SEC(2);
		}				 
		}
		break;

		case 'D':
		//CLEAR LCD
		//PRINT "ENTERE TIME"
		NUM_SEC (2);
		TIMER_D(&Timer_min,&Timer_sec );
		while (1)
		{
			if (check_door ())
		{
			if ((GPIO_PORTF_DATA_R & 0X01) ==0)
			{
				
				NUM_MIN(Timer_min);
				NUM_SEC(Timer_sec);
				LED_END();
				// END "bUZZ" 
				break;
			}
			//else // ON LCD "PLZ PUSH START"
		}
		//else // ON LCD "PLZ CLOSE THE DOOR"
			
		}
		break;

	//default://on lcd error input .

		//break;
	}
}

