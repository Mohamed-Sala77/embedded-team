#include "Io.h" 
#include "initialization.h" 
#include "tm4c123gh6pm2.h" 
#define NVIC_ST_CTRL_R          (*((volatile unsigned long *)0xE000E010))
#define NVIC_ST_RELOAD_R        (*((volatile unsigned long *)0xE000E014))
#define NVIC_ST_CURRENT_R       (*((volatile unsigned long *)0xE000E018))


void SystemInit(void){

SYSCTL_RCGCGPIO_R |= 0x20; // PortF clock enable
while ((SYSCTL_PRGPIO_R & 0x20)==0); //Delay
GPIO_PORTF_LOCK_R = 0x4C4F434B; // Unlock PortF Commit register
GPIO_PORTF_CR_R |= 0x0E; // Allow changes to PF1
GPIO_PORTF_AMSEL_R &= ~0x0E; // Disable analog function
GPIO_PORTF_PCTL_R &= ~0x0000FFF0; // GPIO clear bit PCTL
GPIO_PORTF_AFSEL_R &= ~0x0E; // No alternate function
GPIO_PORTF_DIR_R |= 0x0E; // PF321 output
GPIO_PORTF_DEN_R |= 0x0E; // Enable digital pins PF4-PF0
GPIO_PORTF_DATA_R |=0x0E; // Initialize LEDs to be off
}

void systickrep(unsigned long num)
{
	int i;
	for(i=0;i<num ;i++){
	systick_init(16000);}
	
}
int main(){
	int i ;
	SystemInit();
	  systickrep(1000);
	for(i=0;i<7;i++){
		GPIO_PORTF_DATA_R= GPIO_PORTF_DATA_R ^ 0x0E;
		systickrep(1000);
	}

}

