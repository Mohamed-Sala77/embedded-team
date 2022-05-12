    #include "Io.h" 
    #include "tm4c123gh6pm2.h" 
    #include "stdint.h"
    #include "string.h"
     enum CASE {OFF=0 , ON=1};
    #define NVIC_ST_CTRL_R          (*((volatile unsigned long *)0xE000E010))
    #define NVIC_ST_RELOAD_R        (*((volatile unsigned long *)0xE000E014))
    #define NVIC_ST_CURRENT_R       (*((volatile unsigned long *)0xE000E018))

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
    SW3_INIT ();
    //GET_SW3
    while(1){
    if (SW3==ON)
    {
    //TIMER_COUNT
    return (int)(ON);
    break; 
    }
    else if (SW3==OFF)
    {
    //print_str("Close the door for safity plz ♥ \n");
    return (int)(OFF);
    }

    }
    //LED_BLINK
    //BUZZ
    }
    void NUM_SEC(unsigned long num)
    {
    int i;		
    for (int i = 0; i < num; i++)
		{
			systick_init(0X04C4B400); //ONE SEC
            if ((GPIO_PORTE_DATA_R & 0x01==0) | (GPIO_PORTF_DATA_R & 0x10==0))
            {
               void PAUSE()
               nop;
               nop;
               nop;
               while (1)
               {
                if(GPIO_PORTF_DATA_R & 0x10==0){ 
                    clear(); 
                    break; }
                else if (GPIO_PORTF_DATA_R & 0x01==0) {
                    resume();
                    break; }
               }
               }
               if (/*LCD "00:00"*/) break;
            
		}
	
		}

	void NUM_MIN(unsigned long num )
		{
		int i;
		int j;
			for (int j = 0; j < num; i++)
			{
			for (int i = 0; i < 60; i++)
			{
				NUM_SEC(1); //ONE SEC
                 if (/*LCD "00:00"*/) break;
			}
             if (/*LCD "00:00"*/) break;
			}
	
		}

		void LED_END(){
		GPIO_PORTF_DATA_R &= ~0x0E;
        NUM_SEC(1)
		for(i=0;i < 6;i++){
		GPIO_PORTF_DATA_R ^= 0x0E;
		NUM_SEC(1);
		}
		}

        void LED_BLINK(){
		
		while(1){
        LED_Init () // PUT IN MAIN INIT ;
		GPIO_PORTF_DATA_R ^= 0x0E;
		NUM_SEC(1);
		}
		}

        void TIMER_D(){
        int n;
        uint32_t i;
        uint32_t j ;
        uint32_t total_min ;
        uint32_t total_sec ;
        
         i=//GIT_FROM_KYPAD)();
         //LCD"00:0I"
         j=i<<8;
         i=//GIT_FROM_KYPAD)()
         
        
        total_min =(i | j) ;
        while(1){
        if(total_min<=30){
            /*LCD"total_min:00"*/
            
            break;
            }
        else //printf"PLZ ENTER BELOW 30 MIN"
        }

        //------------------------------------

        
         i=//GIT_FROM_KYPAD();
        //LCD"00:0I"
         j=i<<8
         i=//GIT_FROM_KYPAD();
         
        total_sec =(i | j) ;
        //LCD"00:total_sec"
            /*LCD"00:total_sec"*/
            
            
        }
        
        float NUMBER MIN_BEEF KILO(char kilos  /*GIT_FROM_KYPAD)()*/ )
        {
        float BEEF_TIME;

        while(1){
        if (kilos<=9){
            BEEF_TIME=0.5*kilos;
        return (float) (BEEF_TIME)
        break;
        }
        else
        {
         return (char) 10   //اكبر من 4.5 نعمل داله هناك تطلع 0
        }
        }
        
        }

        float NUMBER MIN_CHICKEN KILO(char kilos  /*GIT_FROM_KYPAD)()*/ )
        {
            float CHICKEN_TIME
      while(1){
        if (kilos<=9){
            CHICKEN_TIME=0.2*kilos;
        return (float) (CHICKEN_TIME)
        break;
        }
        else
        {
         return (char) 10   //اكبر من 1.8 نعمل داله هناك تطلع 0
        }
        }
        }
   
        

