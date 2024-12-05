#include "buzzer.h"

//BUZZER initialization
void BUZZ_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);   //Enable APB Clock
	
	GPIO_InitStructure.GPIO_Pin = BUZZ_PIN;				//BUZZER Pin
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;            //Push pull output
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;	//50M
	GPIO_Init(BUZZ_PORT, &GPIO_InitStructure);			//Initialize BUZZER GPIO
	//GPIO_SetBits(BUZZ_PORT,BUZZ_PIN);
	GPIO_ResetBits(BUZZ_PORT,BUZZ_PIN);
}

void buzz_task(void *pvParameters)
{
    while(1)
    {
      BUZZ=~BUZZ;        //0 on, 1 off   
      delay_ms(7000);	
			//vTaskDelay(7000); //Delay 
			
			
    }
}  

