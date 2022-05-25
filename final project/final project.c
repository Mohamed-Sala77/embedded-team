#include "Io.h" 
#include "tm4c123gh6pm.h" 
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
		char order;	
		MAIN_INIT();
	 
		LCD_Write_Data("Welcome",7);
		Systick_Wait_1s(1); // 1 sec
	while(1){
	LCD_Write_Data("Enter sympol",12);
		Systick_Wait_1s(1); // 1 sec
		order = Keypad_Out();
	
    
	switch (order)
	{
		
	case 'A':
	case 'a':
		LCD_Write_Data("POPCORN",7);
		Systick_Wait_1s(1); // 1 sec
		while (1)
		{
			door=check_door ();
			if (door==1)
		{
			while(1){
			if ((GPIO_PORTF_DATA_R & 0X01 )==0)
			{
					GPIO_PORTF_DATA_R|= 0x0E;
					LCD_Write_Data("1 Min",5);
					Systick_Wait_1s(1); // 1 sec
				Timer(0,12);
				LED_END();
				
				break;
			}
			LCD_Write_Data("Push Start",10);
			systick_init(1600000); // 1 sec
			}
			 
		}
		if(door==1) break;
		}
		break;

		case 'B':
		case 'b':
		LCD_Write_Data("BEEF",4);
		Systick_Wait_1s(1); // 1 sec
		LCD_Write_Data("Enter weight?",13);
		Systick_Wait_1s(1); // 1 sec
		BEEF_SEC=MIN_BEEF(weight);			
		while(1){
			door=check_door ();
			if (door==1)
		{
			while(1){
			if ((GPIO_PORTF_DATA_R & 0X01) ==0x00)
			{ 
		
				calc_min(&BEEF_SEC ,&BEEF_MIN);
				GPIO_PORTF_DATA_R|= 0x0E;
				Timer(BEEF_MIN,BEEF_SEC);
				LED_END();
				
				break;
			}
			LCD_Write_Data("Push Start",10);
			systick_init(1600000); // 1 sec
			}
		}
		 if(door==1) break;
		
						 
		}
		break;

		case 'c':
		case 'C':
		LCD_Write_Data("Chicken",7);
		Systick_Wait_1s(1); // 1 sec
		LCD_Write_Data("Enter weight?",13);
		Systick_Wait_1s(1); // 1 sec
		chicken_SEC=MIN_CHICKEN(weight);
					
		while(1){
			door=check_door ();
			if (door==1)
		{
			while(1){
			if ((GPIO_PORTF_DATA_R & 0X01) ==0x00)
			{
				calc_min(&chicken_SEC,&chicken_MIN);
				GPIO_PORTF_DATA_R|= 0x0E;
				Timer(chicken_MIN,chicken_SEC);
				LED_END();
				
				break;
				
			}
			
			LCD_Write_Data("Push Start",10);
			systick_init(1600000); // 1 sec
			}
		}
		
			 if(door==1) break;
						 
		}
		break;

		case 'D':
		case 'd':
		LCD_Write_Data("ENTER TIME",10);
		Systick_Wait_1s(1); // 1 sec
		TIMER_D(&Timer_min,&Timer_sec );
		while (1)
		{
			door=check_door ();
			if (door==1)
		{
			while(1){
			if ((GPIO_PORTF_DATA_R & 0X01) ==0)
			{
				GPIO_PORTF_DATA_R|= 0x0E;
				Timer(Timer_min,Timer_sec);
				LED_END();
				
				break;
			}
			LCD_Write_Data("Push Start",10);
			systick_init(1600000); // 1 sec
			}
		}
		if(door==1) break;
			
		}
		break;
		default:
			LCD_Write_Data("Err.",4);
			Systick_Wait_1s(1); // 1 sec
			LCD_Write_Data("Enter A,B,C or D",16);
			Systick_Wait_1s(1); // 1 sec
		break;
	}
}
}
