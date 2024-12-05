#ifndef __BUZZER_H
#define __BUZZER_H
#include "sys.h"
#include "system.h"

//LED Port definition
#define BUZZ_TASK_PRIO		3     
#define BUZZ_STK_SIZE 		128   


#define BUZZ_PORT GPIOB
#define BUZZ_PIN GPIO_Pin_10
#define BUZZ PBout(10) 
/*----------------------------------*/

void BUZZ_Init(void);  
void buzz_task(void *pvParameters);
#endif
