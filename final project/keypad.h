#include "initialization.h"

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
