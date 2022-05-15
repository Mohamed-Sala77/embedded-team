#include "Io.h" 
#include "tm4c123gh6pm2.h" 
#include "stdint.h"
#include "string.h"
 enum CASE {OFF=0 , ON=1};
#define NVIC_ST_CTRL_R          (*((volatile unsigned long *)0xE000E010))
#define NVIC_ST_RELOAD_R        (*((volatile unsigned long *)0xE000E014))
#define NVIC_ST_CURRENT_R       (*((volatile unsigned long *)0xE000E018))	
		
void LED_Init()
		{
		SYSCTL_RCGCGPIO_R |= 0x20;             //Port F Clock enable
		while((SYSCTL_PRGPIO_R & 0x20)==0){};  //Delay
		GPIO_PORTF_DIR_R |= 0x0E;              //Enable Output
		GPIO_PORTF_AFSEL_R &= ~(0x0E);         //No alternate function
		GPIO_PORTF_PCTL_R &= ~(0x0000FFF0);    //Clear PCTL bit
		GPIO_PORTF_DEN_R |= 0x0E;              //Enable Digital Pins 3 2 1 
		GPIO_PORTF_AMSEL_R &= ~(0x0E);         //Disable Analog Mode
		GPIO_PORTF_DATA_R &= ~(0x0E);          //Initialize LEDS to be off 
		 }

		 void SWICH_Init()
		{
		 SYSCTL_RCGCGPIO_R|=0x20;
		while ((SYSCTL_RCGCGPIO_R&0x20)==0);
		GPIO_PORTF_LOCK_R=0x4C4F434B;
		GPIO_PORTF_CR_R|=0x11;
		GPIO_PORTF_AFSEL_R&=~0x11;
		GPIO_PORTF_AMSEL_R&=~0x11;
		GPIO_PORTF_PCTL_R&=~0x000F000F;
		GPIO_PORTF_DEN_R|=0x11;
		GPIO_PORTF_PUR_R|=0x11;
		GPIO_PORTF_DIR_R&=~0x11;
		GPIO_PORTF_DATA_R |=(0x11);          //Initialize SWICH to be off 
		}
		
		void systick_init(unsigned long num)
		{
		NVIC_ST_CTRL_R =0x00;//disable 
		NVIC_ST_RELOAD_R = num-1;
		NVIC_ST_CURRENT_R = 0;
		NVIC_ST_CTRL_R =0x05;
		while ((NVIC_ST_CTRL_R&0x00010000)==0);
		}
		
		void SW3_INIT (){
		SYSCTL_RCGCGPIO_R |= 0x10; // PortE clock enable
		while ((SYSCTL_PRGPIO_R & 0x10)==0); //Delay
		GPIO_PORTE_CR_R |= 0x01; // Allow changes to PE0.
		GPIO_PORTE_AMSEL_R &= ~0x01; // Disable analog function
		GPIO_PORTE_AFSEL_R &= ~0x01; // No alternate function
		GPIO_PORTE_PCTL_R &= ~0x0000000F; // GPIO clear bit PCTL
		GPIO_PORTE_PUR_R |=0X01;
		GPIO_PORTE_DIR_R &= ~0x01; // PE0 INPUT
		GPIO_PORTE_DEN_R |= 0x01; // Enable digital pins PE0
		GPIO_PORTE_DATA_R |= 0x01; // Initialize PIN E0 TO BE OFF

		}
		
void KEYPAD_INIT(){  	// PORTD  Completely
  SYSCTL_RCGCGPIO_R |= 0x08;
  while((SYSCTL_PRGPIO_R & 0x08) == 0);
  GPIO_PORTD_LOCK_R=0x4C4F434B;
	GPIO_PORTD_CR_R |=0xFF;
	GPIO_PORTD_DEN_R |=0xFF;
  GPIO_PORTD_PUR_R |= 0xF0;		// Pins(4 --> 7) Pull Up Resistors
	GPIO_PORTD_AFSEL_R &= ~0xFF;
	GPIO_PORTD_PCTL_R &= ~0xFFFFFFFF;
  GPIO_PORTD_AMSEL_R &= ~0xFF;
}			

void BUZZER_INIT (){	// Buzzer ==> E3
	SYSCTL_RCGCGPIO_R |= 0x10; 
	while ((SYSCTL_PRGPIO_R & 0x10)==0); 
	GPIO_PORTE_LOCK_R=0x4C4F434B;
	GPIO_PORTE_CR_R |= 0x08; 
	GPIO_PORTE_DEN_R |= 0x08;
	GPIO_PORTE_AFSEL_R &= ~0x08; 
	GPIO_PORTE_PCTL_R &= ~0x00F000; 
	GPIO_PORTE_AMSEL_R &= ~0x08;
	GPIO_PORTE_DIR_R |= 0x08; 			// Buzzer ==> Output 
	GPIO_PORTE_DATA_R &= ~0x08; 		// Clear Buzzer {E3 = 0} (No Sound at the beginning)
}
//////////////////////////////////////////////////////////////////////
        void MAIN_INIT(){
		SW3_INIT ();
		LED_Init ();
		BUZZER_INIT ();
		KEYPAD_INIT();
				}

				void PAUSE(){

        //LCD =NVIC_ST_CURRENT_R 
        NVIC_ST_CTRL_R &= 0xFFFFFFFE;

        }

        void resume(){

        NVIC_ST_CTRL_R |=0X00000001;
        //LCD =NVIC_ST_CURRENT_R;
        }

        void clear (){
            //LCD = 00:00
            NVIC_ST_CURRENT_R=0X000;

        }
    
    
    int check_door (){
    int SW3=(GPIO_PORTE_DATA_R &0x01);
    while(1){
    if (SW3==ON)
    {
    //TIMER_COUNT
    return (int)(1);
    }
    else if (SW3==OFF)
    {
    //print_str("Close the door for safity plz ? \n");
    return (int)(0);
    }

    }
    //LED_BLINK
    //BUZZ
    }
    void NUM_SEC(unsigned long num)
    {
    int i;		
    for ( i = 0; i < num; i++)
		{
			systick_init(0X04C4B400); //ONE SEC
            if (((GPIO_PORTE_DATA_R & 0x01)==0) | ((GPIO_PORTF_DATA_R & 0x10)==0))
            {
               void PAUSE();
              NUM_SEC(1);
               while (1)
               {
                if((GPIO_PORTF_DATA_R & 0x10)==0){ 
                    clear(); 
                    break; }
                else if ((GPIO_PORTF_DATA_R & 0x01)==0) {
                    resume();
                    break; }
               }
               }
               //if (/*LCD "00:00"*/) break;
            
		}
	
		}

	void NUM_MIN(unsigned long num )
		{
		int i;
		int j;
			for ( j = 0; j < num; i++)
			{
			for ( i = 0; i < 60; i++)
			{
				NUM_SEC(1); //ONE SEC
                // if (/*LCD "00:00"*/) break;
			}
            // if (/*LCD "00:00"*/) break;
			}
	
		}

		void LED_END(){
			int i;
		GPIO_PORTF_DATA_R &= ~0x0E;
        NUM_SEC(1);
		for(i=0;i < 6;i++){
		GPIO_PORTF_DATA_R ^= 0x0E;
		NUM_SEC(1);
		}
		}

     void LED_BLINK(){
		while(1){
		GPIO_PORTF_DATA_R^= 0x0E;
		NUM_SEC(1);
			//if (/*00:00*/)break;
			
		}
		}

        void TIMER_D(int*total_min,int*total_sec){
        uint32_t i;
        uint32_t j ;
        
         i=//GIT_FROM_KYPAD)();
         //LCD"00:0I"
         j=i<<8;
         i=0;//GIT_FROM_KYPAD)()
         
        
        *total_min =(i | j) ;
        while(1){
        if(*total_min<=30){
            /*LCD"total_min:00"*/
            
            break;
            }
        //else printf"PLZ ENTER BELOW 30 MIN"
        }

        //------------------------------------

        
         i=//GIT_FROM_KYPAD();
        //LCD"00:0I"
         j=i<<8 ;
         i=0;//GIT_FROM_KYPAD();
         
        *total_sec =(i | j) ;
        //LCD"00:total_sec"
            /*LCD"00:total_sec"*/
            
        }
        
        float MIN_BEEF (char kilos  /*GIT_FROM_KYPAD)()*/ )
        {
        float BEEF_TIME;

        while(1){
        if (kilos<=9){
            BEEF_TIME=0.5*kilos;
        return (float) (BEEF_TIME);
        }
        else
        {
         return (char) 10 ;  //???? ?? 4.5 ???? ???? ???? ???? 0
        }
        }
        
        }

        float  MIN_CHICKEN (char kilos  /*GIT_FROM_KYPAD)()*/ )
        {
            float CHICKEN_TIME ;
      while(1){
        if (kilos<=9){
            CHICKEN_TIME=0.2*kilos;
        return (float) (CHICKEN_TIME) ;
        }
        else
        {
         return (char) 10 ;  //???? ?? 1.8 ???? ???? ???? ???? 0
        }
        }
        }
   
        

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
		char orded =0;	//KEYPAD_INP;
		MAIN_INIT();
	//ON LCD () "PLZ ENTER SYMPOL"
		
    
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
			if (check_door ())
		{
			if ((GPIO_PORTF_DATA_R & 0X01 )==0)
			{
				NUM_MIN(1);
				LED_END();
				// END "bUZZ" 
				break;
			}
			//else  ON LCD "PLZ PUSH START"
		}
		//else  ON LCD "PLZ CLOSE THE DOOR"
		}
		break;
	

		case 'B':
		// ON LCD "Beef weight?
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

