#include "Io.h" 
#include "tm4c123gh6pm2.h" 
#include "stdint.h"
#include "string.h"
#include "initialization & functions.h"
///////////////////////////////////////////////

int main(){
		int weight=0 ;
		int BEEF_SEC=0,BEEF_MIN=0;
		int chicken_SEC,chicken_MIN;
		int Timer_min=0,Timer_sec=0;
		int door ;
		char order =Keypad_Out();
		MAIN_INIT();
	//ON LCD () "PLZ ENTER SYMPOL"
		
    
	switch (order)
	{
		
	case 'A':
	case 'a':
		//CLEAR LCD
		//PRINT "POPCORN"
		NUM_SEC (2);
		while (1)
		{
			door=check_door ();
			if (door==1)
		{
			while(1){
			if ((GPIO_PORTF_DATA_R & 0X01 )==0)
			{
					//CLEAR LCD
					//PRINT 1 MIN
					NUM_SEC (2);
                LCD_ascii("01:00");//nem_sec decrease
				NUM_MIN(1);
				LED_END();
				// END "bUZZ" 
				break;
			}
			LCD_ascii("PLZ PUSH START" );
			}
			 
		}
		 if(door & ~(GPIO_PORTF_DATA_R & 0X01 )) break;
		}
		break;

		case 'B':
		case 'b':
		LCD_ascii("Beef weight?");
		BEEF_SEC=MIN_BEEF(weight);			
		while(1){
			door=check_door ();
			if (door==1)
		{
			while(1){
			if ((GPIO_PORTF_DATA_R & 0X01) ==0x00)
			{ 
				calc_min(&BEEF_SEC ,&BEEF_MIN);
				NUM_MIN(BEEF_MIN);
				NUM_SEC(BEEF_SEC);
				LED_END();
				// END "bUZZ" 
				break;
			}
			//else  ON LCD "PLZ PUSH START"
			}
		}
		 if(door & ~(GPIO_PORTF_DATA_R & 0X01 )) break;
		
						 
		}
		break;

		case 'c':
		case 'C':
		// ON LCD "chicken weight?
		chicken_SEC=MIN_CHICKEN(weight);
					
		while(1){
			door=check_door ();
			if (door==1)
		{
			while(1){
			if ((GPIO_PORTF_DATA_R & 0X01) ==0x00)
			{
				calc_min(&chicken_SEC,&chicken_MIN);
				NUM_MIN(chicken_MIN);
				NUM_SEC(chicken_SEC);
				LED_END();
				// END "bUZZ" 
				break;
			}
			//else  ON LCD "PLZ PUSH START"
			}
		}
			 if(door & ~(GPIO_PORTF_DATA_R & 0X01 )) break;
						 
		}
		break;

		case 'D':
		case 'd':
		//CLEAR LCD
		//PRINT "ENTERE TIME"
		NUM_SEC (2);
		TIMER_D(&Timer_min,&Timer_sec );
		while (1)
		{
			door=check_door ();
			if (door==1)
		{
			while(1){
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
		}
		 if(door & ~(GPIO_PORTF_DATA_R & 0X01 )) break;
			
		}
		break;

	//default://on lcd error input .

		//break;
	}
}

