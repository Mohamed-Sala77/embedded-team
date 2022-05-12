#include "Io.h" 
#include "tm4c123gh6pm2.h" 
#include "stdint.h"
#include "string.h"
#define NVIC_ST_CTRL_R          (*((volatile unsigned long *)0xE000E010))
#define NVIC_ST_RELOAD_R        (*((volatile unsigned long *)0xE000E014))
#define NVIC_ST_CURRENT_R       (*((volatile unsigned long *)0xE000E018))
	
	void UART0_INIT(){
		SYSCTL_RCGCUART_R |= SYSCTL_RCGCUART_R0;
		SYSCTL_RCGCGPIO_R |= SYSCTL_RCGCGPIO_R0;
		UART0_CTL_R &= ~ UART_CTL_UARTEN;
		UART0_IBRD_R = 104;  
		UART0_FBRD_R = 11;
		UART0_LCRH_R = (UART_LCRH_WLEN_8 | UART_LCRH_FEN)  ;
		UART0_CTL_R |= (UART_CTL_UARTEN|UART_CTL_TXE|UART_CTL_RXE);
		GPIO_PORTA_AFSEL_R=0X03;
		GPIO_PORTA_PCTL_R= (GPIO_PORTA_PCTL_R& ~0XFF) | (0X11);
		GPIO_PORTA_DEN_R|=0X03;
		GPIO_PORTA_AMSEL_R &= ~0x03;
		}
		
		void UART1_INIT(){
		SYSCTL_RCGCUART_R |=SYSCTL_RCGCUART_R1 ;
		SYSCTL_RCGCGPIO_R |=SYSCTL_RCGCGPIO_R1 ;
		UART1_CTL_R &= ~ UART_CTL_UARTEN;
		UART1_IBRD_R = 104;  
		UART1_FBRD_R = 11;
		UART1_LCRH_R = (UART_LCRH_WLEN_8 | UART_LCRH_FEN)  ;
		UART1_CTL_R |= (UART_CTL_UARTEN|UART_CTL_TXE|UART_CTL_RXE);
		GPIO_PORTB_AFSEL_R=0X03;
		GPIO_PORTB_PCTL_R= (GPIO_PORTA_PCTL_R& ~0XFF) | (0X11);
		GPIO_PORTB_DEN_R|=0X03;
		GPIO_PORTB_AMSEL_R &= ~0x03;
		}
		
		void UART2_INIT(){
		SYSCTL_RCGCUART_R |=SYSCTL_RCGCUART_R2 ;
		SYSCTL_RCGCGPIO_R |=SYSCTL_RCGCGPIO_R3 ;
		UART2_CTL_R &= ~ UART_CTL_UARTEN;
		UART2_IBRD_R = 104;  
		UART2_FBRD_R = 11;
		UART2_LCRH_R = (UART_LCRH_WLEN_8 | UART_LCRH_FEN)  ;
		UART2_CTL_R |= (UART_CTL_UARTEN|UART_CTL_TXE|UART_CTL_RXE);
		GPIO_PORTD_AFSEL_R=0XC0;
		GPIO_PORTD_PCTL_R= (GPIO_PORTA_PCTL_R& ~0XFF000000) | (0X1100000);
		GPIO_PORTD_DEN_R|=0XC0;
		GPIO_PORTD_AMSEL_R &= ~0xC0;
		}

		void UART3_INIT(){
		SYSCTL_RCGCUART_R |=SYSCTL_RCGCUART_R3 ;
		SYSCTL_RCGCGPIO_R |=SYSCTL_RCGCGPIO_R2 ;
		UART3_CTL_R &= ~ UART_CTL_UARTEN;
		UART3_IBRD_R = 104;  
		UART3_FBRD_R = 11;
		UART3_LCRH_R = (UART_LCRH_WLEN_8 | UART_LCRH_FEN)  ;
		UART3_CTL_R |= (UART_CTL_UARTEN|UART_CTL_TXE|UART_CTL_RXE);
		GPIO_PORTC_AFSEL_R=0XC0;
		GPIO_PORTC_PCTL_R= (GPIO_PORTA_PCTL_R& ~0XFF000000) | (0X1100000);
		GPIO_PORTC_DEN_R|=0XC0;
		GPIO_PORTC_AMSEL_R &= ~0xC0;
		}

		void UART4_INIT(){
		SYSCTL_RCGCUART_R |=SYSCTL_RCGCUART_R4 ;
		SYSCTL_RCGCGPIO_R |=SYSCTL_RCGCGPIO_R2 ;
		UART4_CTL_R &= ~ UART_CTL_UARTEN;
		UART4_IBRD_R = 104;  
		UART4_FBRD_R = 11;
		UART4_LCRH_R = (UART_LCRH_WLEN_8 | UART_LCRH_FEN)  ;
		UART4_CTL_R |= (UART_CTL_UARTEN|UART_CTL_TXE|UART_CTL_RXE);
		GPIO_PORTC_AFSEL_R=0X30;
		GPIO_PORTC_PCTL_R= (GPIO_PORTA_PCTL_R& ~0XFF0000) | (0X110000);
		GPIO_PORTC_DEN_R|=0X30;
		GPIO_PORTC_AMSEL_R &= ~0x30;
		}

		void UART5_INIT(){
		SYSCTL_RCGCUART_R |=SYSCTL_RCGCUART_R5 ;
		SYSCTL_RCGCGPIO_R |=SYSCTL_RCGCGPIO_R4 ;
		UART5_CTL_R &= ~ UART_CTL_UARTEN;
		UART5_IBRD_R = 104;  
		UART5_FBRD_R = 11;
		UART5_LCRH_R = (UART_LCRH_WLEN_8 | UART_LCRH_FEN)  ;
		UART5_CTL_R |= (UART_CTL_UARTEN|UART_CTL_TXE|UART_CTL_RXE);
		GPIO_PORTE_AFSEL_R=0X30;
		GPIO_PORTE_PCTL_R= (GPIO_PORTA_PCTL_R& ~0XFF0000) | (0X110000);
		GPIO_PORTE_DEN_R|=0X30;
		GPIO_PORTE_AMSEL_R &= ~0x30;
		}
		
		void UART6_INIT(){
		SYSCTL_RCGCUART_R |=SYSCTL_RCGCUART_R6 ;
		SYSCTL_RCGCGPIO_R |=SYSCTL_RCGCGPIO_R3 ;
		UART6_CTL_R &= ~ UART_CTL_UARTEN;
		UART6_IBRD_R = 104;  
		UART6_FBRD_R = 11;
		UART6_LCRH_R = (UART_LCRH_WLEN_8 | UART_LCRH_FEN)  ;
		UART6_CTL_R |= (UART_CTL_UARTEN|UART_CTL_TXE|UART_CTL_RXE);
		GPIO_PORTD_AFSEL_R=0X30;
		GPIO_PORTD_PCTL_R= (GPIO_PORTA_PCTL_R& ~0XFF0000) | (0X110000);
		GPIO_PORTD_DEN_R|=0X30;
		GPIO_PORTD_AMSEL_R &= ~0x30;
		}

		void UART7_INIT(){
		SYSCTL_RCGCUART_R |=SYSCTL_RCGCUART_R7 ;
		SYSCTL_RCGCGPIO_R |=SYSCTL_RCGCGPIO_R4 ;
		UART7_CTL_R &= ~ UART_CTL_UARTEN;
		UART7_IBRD_R = 104;  
		UART7_FBRD_R = 11;
		UART7_LCRH_R = (UART_LCRH_WLEN_8 | UART_LCRH_FEN)  ;
		UART7_CTL_R |= (UART_CTL_UARTEN|UART_CTL_TXE|UART_CTL_RXE);
		GPIO_PORTE_AFSEL_R=0X03;
		GPIO_PORTE_PCTL_R= (GPIO_PORTA_PCTL_R& ~0XFF) | (0X11);
		GPIO_PORTE_DEN_R|=0X03;
		GPIO_PORTE_AMSEL_R &= ~0x03;
		}
		
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