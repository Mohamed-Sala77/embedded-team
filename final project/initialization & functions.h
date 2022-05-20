#include "Io.h" 
#include "tm4c123gh6pm2.h" 
#include "stdint.h"
#include "string.h"
#include "math.h"
#define NVIC_ST_CTRL_R          (*((volatile unsigned long *)0xE000E010))
#define NVIC_ST_RELOAD_R        (*((volatile unsigned long *)0xE000E014))
#define NVIC_ST_CURRENT_R       (*((volatile unsigned long *)0xE000E018))
#define clear_display     0x01
#define cursorBlink       0x0F
#define line              0x38
#define moveCursorRight   0x06
#define FirstRow          0x80
#define SecondRow         0xC0
#define fourbit           0x28
#define eightbit          0x38
#define write_data        0x02
#define write_command     0x00
#define enable            0x01	
		
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
		GPIO_PORTE_CR_R |= 0x01; // Allow changes to PE0.
		GPIO_PORTE_AMSEL_R &= ~0x01; // Disable analog function
		GPIO_PORTE_AFSEL_R &= ~0x01; // No alternate function
		GPIO_PORTE_PCTL_R &= ~0x0000000F; // GPIO clear bit PCTL
		GPIO_PORTE_PUR_R |=0X01;
		GPIO_PORTE_DIR_R &= ~0x01; // PE0 INPUT
		GPIO_PORTE_DEN_R |= 0x01; // Enable digital pins PE0
		GPIO_PORTE_DATA_R |= 0x01; // Initialize PIN E0 TO BE OFF

		}
		
void KEYPAD_ROWS_INIT(){  	// PORT D (0 --> 3) ==> Keypad Rows
  SYSCTL_RCGCGPIO_R |= 0x08;
  while((SYSCTL_PRGPIO_R & 0x08) == 0);
  GPIO_PORTD_LOCK_R=0x4C4F434B;
	GPIO_PORTD_CR_R |=0x0F;
	GPIO_PORTD_DEN_R |=0x0F;
	GPIO_PORTD_AFSEL_R &= ~0x0F;
	GPIO_PORTD_PCTL_R &= ~0x0000FFFF;
  GPIO_PORTD_AMSEL_R &= ~0x0F;
}			

void KEYPAD_COLUMNS_INIT(){  	// PORT A (4 --> 7) ==> Keypad Columns
  SYSCTL_RCGCGPIO_R |= 0x01;
  while((SYSCTL_PRGPIO_R & 0x01) == 0);
  GPIO_PORTA_LOCK_R=0x4C4F434B;
	GPIO_PORTA_CR_R |=0xF0;
	GPIO_PORTA_DEN_R |=0xF0;
  GPIO_PORTA_PUR_R |= 0xF0;		// Pins(4 --> 7) Pull Up Resistors
	GPIO_PORTA_AFSEL_R &= ~0xF0;
	GPIO_PORTA_PCTL_R &= ~0xFFFF0000;
  GPIO_PORTA_AMSEL_R &= ~0xF0;
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
	GPIO_PORTE_DIR_R |= 0x08; 		// Buzzer ==> Output 
	GPIO_PORTE_DATA_R &= ~0x08; 	// Clear Buzzer {E3 = 0} (No Sound at the beginning)
}

void B_Init()
		{
		SYSCTL_RCGCGPIO_R |= 0x02;             //Port B Clock enable
		while((SYSCTL_PRGPIO_R & 0x02)==0){};  //Delay
		GPIO_PORTB_LOCK_R=0x4C4F434B;
		GPIO_PORTB_CR_R |=0xF7;
		GPIO_PORTB_DIR_R |= 0xF7;              //Enable Output
		GPIO_PORTB_AFSEL_R &= ~(0xF7);         //No alternate function
		GPIO_PORTB_PCTL_R &= ~(0xFFFFF0FF);    //Clear PCTL bit
		GPIO_PORTB_DEN_R |= 0xF7;              //Enable Digital Pins 3 2 1 
		GPIO_PORTB_AMSEL_R &= ~(0xF7);         //Disable Analog Mode          //Initialize LEDS to be off 
		 }

void systick_init(unsigned long num)
		{
		NVIC_ST_CTRL_R =0x00;//disable 
		NVIC_ST_RELOAD_R = num-1;
		NVIC_ST_CURRENT_R = 0;
		NVIC_ST_CTRL_R =0x05;
		while ((NVIC_ST_CTRL_R&0x00010000)==0);
		}
		
void LCD_enable(){
GPIO_PORTB_DATA_R |=enable;
systick_init(80000);
GPIO_PORTB_DATA_R &= ~enable;
systick_init(32000);
}
void LCD_write (unsigned char data, unsigned char control_write_select){
 data &= 0xF0; /*take upperpart of data*/
 control_write_select &= 0X0F;                         /*take lower part of control*/
 GPIO_PORTB_DATA_R = data|control_write_select;        /*send data to be written or command to be executed*/ 
 LCD_enable();   /* give enable and delay*/
 GPIO_PORTB_DATA_R = 0;  //clear port data        
}

void LCD_display(unsigned char data){
 LCD_write(data &0xF0,write_data);
 LCD_write(data <<4  ,write_data);
}

void LCD_command(unsigned char command){
 LCD_write(command &0xF0,write_command);
 LCD_write(command <<4  ,write_command);
systick_init(32000);
}
void LCD_ascii(char *letter){
int i;
for (i=0; letter[i]!=0;i++){
    LCD_display(letter[i]);
    }
}

void LCD_cursor(unsigned char row,unsigned char column){
unsigned char position=0;
if(row==1){
position= FirstRow+column-1;
}
else if(row==2){
position= SecondRow+column-1;
}
else position=FirstRow;
LCD_command(position);
}
void LCD_init(){
LCD_command(line);
LCD_command(fourbit);
LCD_command(moveCursorRight);
LCD_command(clear_display);
LCD_command(cursorBlink);
}

/* LCD_enable function gives enable a pulse that lasts for some time(enable acts like latches and read data while clock is high)
LCD_write is a function that makes writing the ffunctions in four bits mode easier
LCD_display is a function that will display numbers or letters on screen
LCD_ascii is the function that will read the letter
LCD_cursor is a function that controls the cursor location on the 2x16 lcd screen
LCD_command is a function that gives commands to lcd like on and off and open display and close display*/
        void MAIN_INIT(){
		SW3_INIT ();
		SWICH_Init();
		LED_Init ();
		BUZZER_INIT ();
		KEYPAD_ROWS_INIT();
		KEYPAD_COLUMNS_INIT();			
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
				LCD_ascii("00:00");
        NVIC_ST_CURRENT_R=0X000;

        }
    
    
    int check_door (){
    int SW3=(GPIO_PORTE_DATA_R &0x01);
    while(1){
    if (SW3==0x00)
    {
    //TIMER_COUNT
    return (int)(1);
    }
    else 
    {
    //print_str("Close the door for safity plz ? \n");
    return (int)(0);
    }

    }
    }


    void NUM_SEC(unsigned long num)
    {
    int i;		
    for ( i = 0; i < num; i++)
		{
			systick_init(0X00F42400); //ONE SEC
            if (((GPIO_PORTE_DATA_R & 0x01)==0) | ((GPIO_PORTF_DATA_R & 0x10)==0))
            {
               void PAUSE();
              systick_init(16000);
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
        
         
        while(1){
			//clear lcd
		i=//GIT_FROM_KYPAD)();
         //LCD"00:0I"
         j=i*10;
         i=//GIT_FROM_KYPAD)();
         
        
        *total_min =(i + j) ;
        if(*total_min<=30){
            /*LCD"total_min:00"*/
            
            break;
            }
        //else printf"PLZ ENTER BELOW 30 MIN"
        }

        //------------------------------------

        
         i=//GIT_FROM_KYPAD();
        //LCD"00:0I"
         j=i*10 ;
         i=0;//GIT_FROM_KYPAD();
         
        *total_sec =(i + j) ;
        //LCD"total_min:total_sec"
            
        }
        
        int MIN_BEEF (char kilos  /*GIT_FROM_KYPAD)()*/ )
        {
        int BEEF_TIME;

        while(1){
        if (kilos<=9){
            BEEF_TIME=30*kilos;//in sec
        return (int) (BEEF_TIME);
        }
        else
        {
           //enter nom bet 1:9
        }
        }
        
        }

        int  MIN_CHICKEN (char kilos  /*GIT_FROM_KYPAD)()*/ )
        {
            int CHICKEN_TIME ;
      while(1){
        if (kilos<=9){
            CHICKEN_TIME=12*kilos;
        return (int) (CHICKEN_TIME) ;
        }
        else
        {
         //enter nom bet 1:9
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

		unsigned char Keypad_Out(){
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
		}

		void Buzzer_ON(){
		GPIO_PORTE_DATA_R |= 0x08;
		}

		void Buzzer_OFF(){
		GPIO_PORTE_DATA_R &= ~0x08;
		}	
   
        
