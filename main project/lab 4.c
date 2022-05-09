#include "Io.h" 
#define NVIC_ST_CTRL_R          (*((volatile unsigned long *)0xE000E010))
#define NVIC_ST_RELOAD_R        (*((volatile unsigned long *)0xE000E014))
#define NVIC_ST_CURRENT_R       (*((volatile unsigned long *)0xE000E018))
#include "Io.h"


void SystemInit(void){

SYSCTL_RCGCGPIO_R |= 0x20; // PortF clock enable
while ((SYSCTL_PRGPIO_R & 0x20)==0); //Delay
GPIO_PORTF_LOCK_R = 0x4C4F434B; // Unlock PortF Commit register
GPIO_PORTF_CR_R |= 0x02; // Allow changes to PF1
GPIO_PORTF_AMSEL_R &= ~0x02; // Disable analog function
GPIO_PORTF_PCTL_R &= ~0x000000F0; // GPIO clear bit PCTL
GPIO_PORTF_AFSEL_R &= ~0x02; // No alternate function
GPIO_PORTF_DIR_R |= 0x02; // PF321 output
GPIO_PORTF_DEN_R |= 0x02; // Enable digital pins PF4-PF0
GPIO_PORTF_DATA_R &= ~0x02; // Initialize LEDs to be off
}
void systick_init(unsigned long num)
{
	NVIC_ST_CTRL_R |=0x00;//disable 
	NVIC_ST_RELOAD_R = num-1;
	NVIC_ST_CURRENT_R = 0;
	NVIC_ST_CTRL_R |=0x05;
	while ((NVIC_ST_CTRL_R&00010000)==0);
}
void systickrep(unsigned long num)
{
	int i;
	for(i=0;i<=num ;i++)
	systick_init(80000);
	
}
int main(){
	SystemInit();
	while(1)
	{
		GPIO_PORTF_DATA_R= GPIO_PORTF_DATA_R^0x02;
		systickrep(1000);
	
	
	}
}
