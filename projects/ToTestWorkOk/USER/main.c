#include "sys.h"
#include "delay.h"
#include "usart.h"
#include "led.h"
#include "lcd.h"  


//////////////////////////////////////////////////////////////////////////////////  
//本程序只供学习使用，未经作者许可，不得用于其它任何用途
//硬件环境：STM32F407开发板
//创建日期:2016/2/17
//版本：V1.1
//版权所有，盗版必究。
//All rights reserved
//********************************************************************************
//创建及修改说明
//V1.0 C语言基础学习工程模板


/**  初始化  **/
void init_main(){
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//设置系统中断优先级分组2
	delay_init(168);  		//初始化延时函数
	
	uart_init(115200);		//初始化串口波特率为115200
		
	LED_Init();				//初始化LED  
 	LCD_Init();				//LCD初始化  
	

 	POINT_COLOR = BLUE;//设置字体为红色 
}
//******************************* 作业 *******************************************




//********************************************************************************


int main(void)
{        	
	init_main();
	
	printf("Hello STM32 I am Liaction . \r\n");
    
    LCD_ShowString(10, 10, 300, 20, 12, (u8 *)"Happy Study And Change The World!");
    LCD_ShowString(10, 40, 300, 20, 16, (u8 *)"2017-11-7 00:53:07");
	
	while(1)
	{
		//如果要用串口进行输入  进添加如下代码
		if((USART_RX_STA&0x8000)!=0)//接收完成
		{
			printf("接收到数据  %s\r\n", USART_RX_BUF);
			//在此处添加收到数据以后的处理代码
			
			USART_RX_STA = 0;
		}
		
	} 
}







