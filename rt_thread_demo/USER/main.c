#include "sys.h"
#include "delay.h"
#include "usart.h"
#include "led.h"
#include <rtthread.h>

int main(void)
{ 
 		 
	LED_Init();		       
	while(1)
	{
		GPIO_ResetBits(GPIOA,GPIO_Pin_8);  
		GPIO_SetBits(GPIOD,GPIO_Pin_2);   
		rt_thread_mdelay(500);  		   
		GPIO_SetBits(GPIOA,GPIO_Pin_8);	  
		GPIO_ResetBits(GPIOD,GPIO_Pin_2); 
		rt_thread_mdelay(500);             
		rt_kprintf("hello world\n");		
	}
} 
 


	

