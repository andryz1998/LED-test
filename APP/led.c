#include "led.h"

/*******************************************************************************
* �� �� ��         : delay
* ��������		   : ��ʱ������delay(6000000)��ʱԼ1s
* ��    ��         : i
* ��    ��         : ��
*******************************************************************************/
void delay(u32 i)	  
{
	while(i--);
}

/*******************************************************************************
* �� �� ��         : LED_Init
* ��������		   : LED��ʼ������
* ��    ��         : ��
* ��    ��         : ��
*******************************************************************************/
void LED_Init()	  //�˿ڳ�ʼ��
{
	GPIO_InitTypeDef GPIO_InitStructure; //����һ���ṹ�������������ʼ��GPIO

	SystemInit();	//ʱ�ӳ�ʼ��
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC,ENABLE);

	/*  ����GPIO��ģʽ��IO�� */
	GPIO_InitStructure.GPIO_Pin=LED;  //ѡ����Ҫ���õ�IO��
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_Out_PP;	 //�����������ģʽ
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;	  //���ô�������
	GPIO_Init(GPIOC,&GPIO_InitStructure); 	   /* ��ʼ��GPIO */
}

/*******************************************************************************
* �� �� ��         : led_display
* ��������		   : LED��ʾ����  LED��˸
* ��    ��         : ��
* ��    ��         : ��
*******************************************************************************/
void led_display()
{
	GPIO_SetBits(GPIOC,LED);
	delay(6000000);//��ʱԼΪ1s
	GPIO_ResetBits(GPIOC,LED);
	delay(6000000);
}
