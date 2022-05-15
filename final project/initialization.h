#include "Io.h" 
#include "tm4c123gh6pm2.h" 
#include "stdint.h"
#include "string.h"
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