#include "Io.h" 
#include "tm4c123gh6pm2.h" 
#include "stdint.h"
#include "string.h"
#include "math.h"
#define NVIC_ST_CTRL_R          (*((volatile unsigned long *)0xE000E010))
#define NVIC_ST_RELOAD_R        (*((volatile unsigned long *)0xE000E014))
#define NVIC_ST_CURRENT_R       (*((volatile unsigned long *)0xE000E018))
#define Clear_Display   		0x01		// Clears Display
#define SetTo8Bits              0x38		// 8-bit length, 2 display lines, 5x8 font
#define EntryMode               0x06    // Increments DDRAM address by 1 when a character is written into it
#define Cursor_On				0x0F		
#define Return_Home             0x02		//returns to idle state which is " What to eat? "
#define Next_Line 				0xC0
#define Cursor_Off				0x0C		// turns off curser blinking
//////////////////////////////////////{Initlization}//////////////////////////////////////////////////////////////	

void PortA_Init()
{
	SYSCTL_RCGCGPIO_R |= 0X01;
	while(!(SYSCTL_PRGPIO_R & 0X01)){};
	GPIO_PORTA_LOCK_R = GPIO_LOCK_KEY;
	GPIO_PORTA_CR_R |= 0xFC;
	GPIO_PORTA_DEN_R |= 0xFC;
	GPIO_PORTA_AFSEL_R = 0;
	GPIO_PORTA_PCTL_R = 0;
	GPIO_PORTA_AMSEL_R = 0;
	GPIO_PORTA_DIR_R = 0xFC;
	GPIO_PORTA_DATA_R = 0x00;

}

void PortB_Init()
{
	SYSCTL_RCGCGPIO_R |= 0x02;
	while(!(SYSCTL_PRGPIO_R & 0x02)){};
	GPIO_PORTB_LOCK_R = GPIO_LOCK_KEY;
	GPIO_PORTB_CR_R |= 0xFF;

	GPIO_PORTB_DEN_R |= 0xFF;
	GPIO_PORTB_AFSEL_R = 0;
	GPIO_PORTB_PCTL_R = 0;
	GPIO_PORTB_AMSEL_R = 0;
	GPIO_PORTB_DIR_R |= 0xFF;
	GPIO_PORTB_PUR_R = 0;
}


void PortE_Init()
{
	SYSCTL_RCGCGPIO_R |= 0X10;
	while((SYSCTL_PRGPIO_R & 0X10)==0){};
	GPIO_PORTE_LOCK_R = GPIO_LOCK_KEY;
	GPIO_PORTE_CR_R = 0X3F;

	GPIO_PORTE_DEN_R |= 0X3F;
	GPIO_PORTE_AFSEL_R &= ~0X3F;
	GPIO_PORTE_PCTL_R &= ~0XFFFFFF;
	GPIO_PORTE_AMSEL_R &= ~0X3F;
	GPIO_PORTE_DIR_R = 0X1E;
	GPIO_PORTE_DATA_R = 0X1E;
	GPIO_PORTE_DIR_R = 0X01;
	GPIO_PORTE_PDR_R = 0x1E;
	GPIO_PORTE_PUR_R |= 0X20;
}

void PortF_Init()
{
	SYSCTL_RCGCGPIO_R |= 0X20;
	while(!(SYSCTL_PRGPIO_R & 0X20)){};
	GPIO_PORTF_LOCK_R = GPIO_LOCK_KEY;
	GPIO_PORTF_CR_R = 0X1F;

	GPIO_PORTF_DEN_R |= 0X1F;
	GPIO_PORTF_AFSEL_R &= ~0X1F;
	GPIO_PORTF_PCTL_R &= ~0XFFFFF;
	GPIO_PORTF_AMSEL_R &= ~0X1F;
	GPIO_PORTF_DIR_R |= 0X0E;
	GPIO_PORTF_PUR_R |= 0x11;
	GPIO_PORTF_DATA_R &= ~0X0E;
}


void LED_Init()
		{
		SYSCTL_RCGCGPIO_R |= 0x20;             //Port F Clock enable
		while((SYSCTL_PRGPIO_R & 0x20)==0){};  //Delay
		GPIO_PORTF_LOCK_R=0x4C4F434B;
	  GPIO_PORTF_CR_R |=0x0E;
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
		GPIO_PORTE_LOCK_R=0x4C4F434B;
		GPIO_PORTE_CR_R |= 0x20; // Allow changes to PE5.
		GPIO_PORTE_AMSEL_R &= ~0x20; // Disable analog function
		GPIO_PORTE_AFSEL_R &= ~0x20; // No alternate function
		GPIO_PORTE_PCTL_R &= ~0x00F00000; // GPIO clear bit PCTL
		GPIO_PORTE_PUR_R |=0X20;
		GPIO_PORTE_DIR_R &= ~0x20; // PE0 INPUT
		GPIO_PORTE_DEN_R |= 0x20; // Enable digital pins PE0
		GPIO_PORTE_DATA_R |= 0x20; // Initialize PIN E0 TO BE OFF

		}
			void BUZZER_INIT (){	// Buzzer ==> E3
		SYSCTL_RCGCGPIO_R |= 0x10; 
		while ((SYSCTL_PRGPIO_R & 0x10)==0); 
		GPIO_PORTE_LOCK_R=0x4C4F434B;
		GPIO_PORTE_CR_R |= 0x01; 
		GPIO_PORTE_DEN_R |= 0x01;
		GPIO_PORTE_AFSEL_R &= ~0x01; 
		GPIO_PORTE_PCTL_R &= ~0x00000F; 
		GPIO_PORTE_AMSEL_R &= ~0x01;
		GPIO_PORTE_DIR_R |= 0x01; 		// Buzzer ==> Output 
		GPIO_PORTE_DATA_R &= ~0x01; 	// Clear Buzzer {E3 = 0} (No Sound at the beginning)
		}
			////////////////////////////////////////////*Keypad_Initlization*///////////////////////////////////////////////

		
void KEYPAD_ROWS_INIT(){  	// PORT A (2 --> 4 & 7) ==> Keypad Rows
  SYSCTL_RCGCGPIO_R |= 0x01;
  while((SYSCTL_PRGPIO_R & 0x01) == 0);
  GPIO_PORTA_LOCK_R=0x4C4F434B;
	GPIO_PORTA_CR_R |=0x9C;
	GPIO_PORTA_DEN_R |=0x9C;
	GPIO_PORTA_AFSEL_R &= ~0x9C;
	GPIO_PORTA_PCTL_R &= ~0xF00FFF00;
  GPIO_PORTA_AMSEL_R &= ~0x9C;
}			

void KEYPAD_COLUMNS_INIT(){  	// PORT E (1 --> 4) ==> Keypad Columns
  SYSCTL_RCGCGPIO_R |= 0x10;
  while((SYSCTL_PRGPIO_R & 0x10) == 0);
  GPIO_PORTE_LOCK_R=0x4C4F434B;
	GPIO_PORTE_CR_R |=0x1E;
	GPIO_PORTE_DEN_R |=0x1E;
  GPIO_PORTE_PUR_R |= 0x1E;		// Pins(1 --> 4) Pull Up Resistors
	GPIO_PORTE_AFSEL_R &= ~0x1E;
	GPIO_PORTE_PCTL_R &= ~0x0FFFF0;
  GPIO_PORTE_AMSEL_R &= ~0x1E;
}			
	

unsigned char Keypad_Out(){
	unsigned char Keypad_Keys [4][4] = {{1, 2, 3, 'A'}, {4, 5, 6, 'B'}, {7, 8, 9, 'C'}, {'*', 0, '#', 'D'}}; // Keys Init.
	unsigned char Keypad_Out = 0xFF; // Keypad Output = 0xFF if no Key is pressed
	int c;
	char Key_Col;		
	GPIO_PORTA_DIR_R  |= 0x9C; // pins (2-->4 & 7) outputs for Rows
	GPIO_PORTA_DATA_R |= 0x9C; // Set all Rows pins(2-->4 &7)
	
	GPIO_PORTE_DIR_R  |= 0x1E;
	GPIO_PORTE_DATA_R  |= 0x0E;		
	GPIO_PORTE_DIR_R  &= ~0x1E; // 	pins (1-->4) inputs for Columns

		// First Row 	
		GPIO_PORTA_DATA_R |= 0x9C;
	GPIO_PORTA_DATA_R &= ~0x04; 
	for(c=1;c<5;c++)
		{
			Key_Col = GPIO_PORTE_DATA_R & (1<<c); // Key_Col = Column in which a Key is pressed
			if(Key_Col == 0x00)
				{
					Keypad_Out = Keypad_Keys [0][c-1]; // Keypad_Out = Key which is pressed after knowing its Row & Column {(c-1) bec. Col are connected from pin 1}
					break; // to exit Column Loop is Key is Pressed
				}		
		}
		if(Keypad_Out == '1' || Keypad_Out == '2' || Keypad_Out == '3' || Keypad_Out == 'A')
			goto end;
		
		// Second Row
		GPIO_PORTA_DATA_R |= 0x9C;
		
	GPIO_PORTA_DATA_R &= ~0x08;  
	for(c=1;c<5;c++)
		{
			Key_Col = GPIO_PORTE_DATA_R & (1<<c); // Key_Col = Column in which a Key is pressed
			if(Key_Col == 0x00)
				{
					Keypad_Out = Keypad_Keys [1][c-1]; // Keypad_Out = Key which is pressed after knowing its Row & Column {(c-1) bec. Col are connected from pin 1}
					break; // to exit Column Loop is Key is Pressed
				}		
		}
		if(Keypad_Out == '4' || Keypad_Out == '5' || Keypad_Out == '6' || Keypad_Out == 'B')
			goto end;

		// Third Row
		GPIO_PORTA_DATA_R |= 0x9C;
	GPIO_PORTA_DATA_R &= ~0x10;  
	for(c=1;c<5;c++)
		{
			Key_Col = GPIO_PORTE_DATA_R & (1<<c); // Key_Col = Column in which a Key is pressed
			if(Key_Col == 0x00)
				{
					Keypad_Out = Keypad_Keys [2][c-1]; // Keypad_Out = Key which is pressed after knowing its Row & Column {(c-1) bec. Col are connected from pin 1}
					break; // to exit Column Loop is Key is Pressed
				}		
		}
		if(Keypad_Out == '7' || Keypad_Out == '8' || Keypad_Out == '9' || Keypad_Out == 'C')
			goto end;		
		
		// Fourth Row
		GPIO_PORTA_DATA_R |= 0x9C;
	GPIO_PORTA_DATA_R &= ~0x80;  
	for(c=1;c<5;c++)
		{
			Key_Col = GPIO_PORTE_DATA_R & (1<<c); // Key_Col = Column in which a Key is pressed
			if(Key_Col == 0x00)
				{
					Keypad_Out = Keypad_Keys [3][c-1]; // Keypad_Out = Key which is pressed after knowing its Row & Column {(c-1) bec. Col are connected from pin 1}
					break; // to exit Column Loop is Key is Pressed
				}		
		}
		if(Keypad_Out == '*' || Keypad_Out == '0' || Keypad_Out == '#' || Keypad_Out == 'D')
			goto end;		
		
		end:
		return(Keypad_Out);
}

unsigned char Keypad_read(){
while(1){
unsigned char out;
out=Keypad_Out();
if((GPIO_PORTF_DATA_R & 0x10)==0)	{
			return(11);
		}
if (out!=0xFF)
return(out);

}
}


	

		///////////////////*LCD_Initlization*////////////////
		void	Systick_Wait_1s(unsigned long num)
		{
			int i;
			for ( i = 0; i < num; i++){
				systick_init(0X00F42400); //ONE SEC
			}
		}




		void LCD_Command(char command)
		{
		GPIO_PORTA_DATA_R &= ~0x60; //RS =0, E=0
		GPIO_PORTB_DATA_R = command;
		GPIO_PORTA_DATA_R |= 0x40; //E=1 to secure command
		if (command < 4) // they take longer
        systick_init(160000);
  		else
        systick_init(32000);
		GPIO_PORTA_DATA_R &= ~0x60;
		}

		void LCD_Init(void)
		{		
		 LCD_Command(SetTo8Bits);				// using 8-bits configuration
		 LCD_Command(EntryMode);				
		 LCD_Command(Cursor_Off);				// turning off cursor blinking
		systick_init(32000);
		}

		void LCD_Display(char data) 											//for writing characters
		{ 
		GPIO_PORTA_DATA_R &= ~0x60;			//RS=0 , E=0
		GPIO_PORTA_DATA_R |= 0x20;		 	//RS=1 , E=0
		GPIO_PORTB_DATA_R = data;				// read data
		GPIO_PORTA_DATA_R |= 0x40;		 	//E=1
		systick_init(16000);						//delay for 10 micro seconds
		GPIO_PORTA_DATA_R &= ~0x60;			
		GPIO_PORTB_DATA_R = 0;					
		}

		void LCD_Write_Data(char* data, unsigned short size) 				//for writing strings on LCD
		{
		unsigned long i = 0;
		LCD_Command(Clear_Display);
		LCD_Command(Return_Home);
		for (i = 0; i < size; i++){					//for loop for displaying charecters one after the other
		LCD_Display(*(data+i));
		systick_init(16000);
		}
		}



////////////////////////////////////////////////////////{Functions}////////////////////////////////////////////////////////////////////////
        void MAIN_INIT(){
		PortA_Init();
		PortB_Init();
		PortE_Init();
		PortF_Init();
		LCD_Init();
		LCD_Command(Clear_Display);
		LCD_Command(Return_Home);
		SW3_INIT ();
			KEYPAD_ROWS_INIT();
	KEYPAD_COLUMNS_INIT();
		SWICH_Init();
		LED_Init ();
		BUZZER_INIT ();			
		}

		
		void Buzzer_ON(){
		GPIO_PORTE_DATA_R |= 0x01;
		}

		void Buzzer_OFF(){
		GPIO_PORTE_DATA_R &= ~0x01;
		}	

		void Buzz (){
			Buzzer_ON();
			Systick_Wait_1s(3);
			Buzzer_OFF();
		}

        void clear (){
        NVIC_ST_CURRENT_R=0X000;
        }
    
    
    	int check_door (){
    	int SW3=(GPIO_PORTE_DATA_R &0x20);
    	if (SW3==0x00)
    	{
			LCD_Write_Data("Close the door ",15);
		systick_init(160000);
    	return (int)(0);
    	
    	}
    	else 
    	{
    	return (int)(1);
    	}

    	}
			
    


    	int NUM_SEC(unsigned long num)
    	{
    	int i;		
    	for ( i = 0; i < 10*num; i++)
		{
		systick_init(1605000); //1/10 SEC
		
        if (((GPIO_PORTE_DATA_R &0x20)==0x00)| ((GPIO_PORTF_DATA_R & 0x10)==0) )
        {
    	
        systick_init(1605000); //PAUSE
        	while (1)
        	{
				GPIO_PORTF_DATA_R^= 0x0E;  // blink
        	if((GPIO_PORTF_DATA_R & 0x10)==0){ 
        		clear(); 
        		return(0); }
        	else if ((GPIO_PORTF_DATA_R & 0x01)==0) {
        		break; } //resume
				else systick_init(6400000);
        	}
        }
        GPIO_PORTF_DATA_R|= 0x0E;
        }
        }

		void LED_END(){
		int i;
		char fstr[10]={0};
		sprintf(fstr,"00%c00",':');				
		LCD_Write_Data(fstr,5);
		GPIO_PORTF_DATA_R &= ~0x0E;
        Systick_Wait_1s(1);
		for(i=0;i < 6;i++){
			GPIO_PORTE_DATA_R ^= 0x01;
		GPIO_PORTF_DATA_R ^= 0x0E;
		Systick_Wait_1s(1);
		
		}
		Buzzer_OFF();
		LCD_Write_Data("Done",4);
			systick_init(160000000);
		}

        void TIMER_D(int*total_min,int*total_sec){
		int t;	
        uint32_t i1,i2;
		uint32_t s1,s2;
        uint32_t j ;
        char fstr[10]={0};
         
        while(1){
			char fstr[10]={0};
			sprintf(fstr,"00%c00",':');
         LCD_Write_Data(fstr,5);
			systick_init(16000000);
			//clear lcd
		i1=Keypad_read();
		for(t=0;t<10;t++){
		if(i1==11)	{
			goto zeros;
		}
		sprintf(fstr,"00%c0%i",':',i1);
         LCD_Write_Data(fstr,5);
			systick_init(1600000);}
        j=i1*10;
    	i2=Keypad_read();//Read_Keypad();
		for(t=0;t<10;t++)	{
		if(i2==11)	{
			goto zeros;
		}
		sprintf(fstr,"00%c%i%i",':',i1,i2);
         LCD_Write_Data(fstr,5);
			systick_init(1600000);}
		
         
        
        *total_min =(i2 + j) ;
        if(*total_min<=30){
            
        break;
    	}
		LCD_Write_Data("Err.",4);
			systick_init(16000000);
         LCD_Write_Data("below 30 min",12);
			systick_init(16000000);
        }

        //------------------------------------

        
         s1=Keypad_read();
		 for(t=0;t<10;t++)	{
		if(s1==11)	{
			goto zeros;
		}
		sprintf(fstr,"0%i%c%i%i",i1,':',i2,s1);
         LCD_Write_Data(fstr,5);
			systick_init(1600000);}
        j=s1*10 ;
        s2=Keypad_read();
		 for(t=0;t<10;t++)	{
		if(s2==11)	{
			goto zeros;
		}
		sprintf(fstr,"%i%i%c%i%i",i1,i2,':',s1,s2);
         LCD_Write_Data(fstr,5);
			systick_init(1600000);}
         
        *total_sec =(s2 + j) ;
		

			if((*total_min==0) && (*total_sec==0)){
				zeros:
		*total_sec=0;
		*total_min=0;
		sprintf(fstr,"00%c00",':');
         LCD_Write_Data(fstr,5);
			systick_init(16000000);
			}
            
        }
		
        
        int MIN_BEEF ()
        {
		char kilos;
        int BEEF_TIME;
		char fstr[10]={0};
		
        while(1){
		kilos=Keypad_read();
        if ((kilos<=9) & (kilos>0)){
		sprintf(fstr,"%i",kilos);
         LCD_Write_Data(fstr,1);
			systick_init(16000000); 
		//lcd clear
            BEEF_TIME=30*kilos;//in sec
        return (int) (BEEF_TIME);
        }
        else
        {
			sprintf(fstr,"%i",kilos);
         LCD_Write_Data(fstr,2);
			systick_init(16000000);
			LCD_Write_Data("Err.",4);
			Systick_Wait_1s(2);// 2 sec 
         LCD_Write_Data("Enter bet 1:9",13);
			systick_init(16000000);
           
        }
        }
        }


        int  MIN_CHICKEN ()
        {
		char kilos;
    	int CHICKEN_TIME ;
		char fstr[10]={0};
      while(1){
		kilos= Keypad_read();//Read_Keypad();
        if ((kilos<=9) &(kilos>0)){
			sprintf(fstr,"%i",kilos);
         LCD_Write_Data(fstr,1);
			systick_init(16000000); 
		//lcd clear
        CHICKEN_TIME=12*kilos;
        return (int) (CHICKEN_TIME) ;
        }
        else
        {
		sprintf(fstr,"%i",kilos);
         LCD_Write_Data(fstr,2);
			systick_init(16000000);
			LCD_Write_Data("Err.",4);
			Systick_Wait_1s(2);// 2 sec 
         LCD_Write_Data("Enter bet 1:9",13);
			systick_init(16000000);
        }
        }
        }
			

		void calc_min(int*sec , int*min){
		while ((*sec)>=60)
		{
			*sec-=60;
			(*min)++;
		}
		
		}

		/*unsigned char Keypad_Out(){
		unsigned char Keypad_Keys [4][4] = {{'1', '2', '3', 'A'}, {'4', '5', '6', 'B'}, {'7', '8', '9', 'C'}, {'*', '0', '#', 'D'}}; // Keys Init.
		unsigned char Keypad_Out = 0xFF; // Keypad Output = 0xFF if no Key is pressed
		int r;
		int c;
		char Key_Col;		
		GPIO_PORTD_DIR_R = 0x0F; // pins (0-->3) outputs for Rows, pins (4-->7) inputs for Columns
	
		for(r=0;r<4;r++)
		{
		GPIO_PORTD_DATA_R &= ~(1<<r); // put 0 in each Row 
		for(c=4;c<8;c++)	
		{
			Key_Col = GPIO_PORTD_DATA_R & (1<<c); // Key_Col = Column in which a Key is pressed
			if(Key_Col == 0x00)
				{
					Keypad_Out = Keypad_Keys [r][c-4]; // Keypad_Out = Key which is pressed after knowing its Row & Column {(c-4) bec. Col are connected from pin 4}
					break; // to exit Column Loop is Key is Pressed
				}
		}
		break;
		}
		return(Keypad_Out);
		}*/


		
	void Timer(int time_min,int time_sec){
	int min,sec,check=1;
	char fstr[10]={0};
	// time_min ==> Number of Minutes to Start count from it 
	// time_sec ==> Number of Seconds to Start count from it 
	
	for(min=time_min;min>=0;min--)
    {
    if(min > 9)
            for(sec=time_sec;sec>=0;sec--)
            {
                if(sec > 9){
                    sprintf(fstr,"%i%c%i",min,':',sec);				
					LCD_Write_Data(fstr,5);	}												
                else if(sec <= 9){
                    sprintf(fstr,"%i%c0%i",min,':',sec);
					LCD_Write_Data(fstr,5);	}	
																
					check=NUM_SEC(1);
					if(check==0)
					{
						sec=0;
						min=0;
					}
            }
    else if(min <= 9)
            for(sec=time_sec;sec>=0;sec--)
            {
                if(sec > 9){
                    sprintf(fstr,"0%i%c%i",min,':',sec);   
										LCD_Write_Data(fstr,5);	}													
                    // Delay 1 Second
                else if(sec <= 9){
                    sprintf(fstr,"0%i%c0%i",min,':',sec);				
										LCD_Write_Data(fstr,5);	}	
																					
                   check=NUM_SEC(1);
				   if(check==0)
					{
						sec=0;
						min=0;
						sprintf(fstr,"00%c00",':');				
						LCD_Write_Data(fstr,5);	}
					}
             
						
        time_sec = 59;  // To start 2nd iteration in Minutes loop with 59 seconds
    }
}

   
        
