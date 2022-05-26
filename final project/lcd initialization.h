//////#define clear_display     0x01
#define returnHome        0x02
#define moveCursorRight   0x06
#define moveCursorLeft    0x08
#define shiftDisplayRight 0x1C
#define shiftDisplayLeft  0x18
#define cursorBlink       0x0F    
#define cursorOff         0x0C
#define cursorOn          0x0E
#define Entry_mode        0x06
#define Function_8_bit    0x32
#define set font          0x20 ////////

#define FirstRow          0x80
#define SecondRow         0xC0
#define 4bit              0x28
#define 8bit              0x38
#define write_data        0x02
#define write_command     0x00
#define enable            0x01

void LCD_init(){
//enable port
LCD_command(//initizalize 5x7);
LCD_command(4bit);
LCD_command(moveCursorRight);
LCD_command(//clear display);
LCD_command(//open cursor and blink);
}

void LCD_write (unsigned char data, unsigned char control_write_select){
 data &= 0xF0; //take upperpart of data
 control_write_select &= 0x0A;                         //take lower part of control
 GPIO_PORTB_DATA_R = data|control_write_select;        //send data to be written or command to be executed 
 LCD_enable(); \\ give enable and delay
 GPIO_PORTB_DATA_R = 0;  //clear port data        
}

void LCD_display(unsigned char data){
 LCD_write(data &0xF0,write_data);
 LCD_write(data <<4  ,write_data);
}

void LCD_command(unsigned char command){
 LCD_write(command &0xF0,write_command);
 LCD_write(command <<4  ,write_command);
}
void LCD_ascii(unsigned char *letter){
int i;
for (i=0; letter[i]!=0;i++){
    LCD_display(letter[i]);
    }
}
void LCD_enable(){
GPIO_PORTB_DATA_R |=enable;
systic_wait(80000);
GPIO_PORTB_DATA_R &= ~enable;
systic_wait(32000);
}

int LCD_cursor(unsigned char row,unsigned char column){
unsigned char position=0;
if(row==1){
position= FirstRow+column-1;
}
else if(row==2){
position= SecondRow+comlumn-1;
}
else position=FirstRow;
return position;
}