#include "system.h"
u32 bound = 115200;

void systemInit(void)
{       

	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_4);
	
	delay_init(168);			                                            
	
	//Initialize the hardware interface connected to the LED lamp
	LED_Init();  
	BUZZ_Init();
	OLED_Init();
	BUTTON_Init();
	uart3_init(115200);
	          
}
