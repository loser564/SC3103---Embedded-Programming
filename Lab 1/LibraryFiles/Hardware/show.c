#include "show.h"


void show_task(void *pvParameters)
{
   u32 lastWakeTime = getSysTickCnt();
   while(1)
    {	
			

			vTaskDelayUntil(&lastWakeTime, F2T(RATE_50_HZ));

			oled_show();    
    }
}  


void oled_show(void)
{  
		uint8_t sec = 0;
		uint8_t min = 0;
		uint8_t time[5];
    // Display the string on the OLED
		while(1){
			OLED_ShowString(0, 0, (const uint8_t *)"timer"); // Display a static message
			sec = sec + 1;
			if (sec == 60){
				min = min + 1;
				sec = 0;
			}
			sprintf((char*) time, "%02d Min %02d Sec", min, sec);
			OLED_ShowString(0, 15, (uint8_t *)time);
		

			OLED_Refresh_Gram(); // Refresh the OLED RAM
			delay_ms(999);	
		}
	
		
}





