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
	case 'a':
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
	

