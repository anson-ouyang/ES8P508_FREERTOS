#include "global_define.h"


void NMI_IRQHandler(void)
{

}

void HardFault_IRQHandler(void)
{
    while (1)
    {
    }
}

// void SVC_IRQHandler(void)
// {

// }

// void PendSV_IRQHandler(void)
// {

// }

/*
*********************************************************************************
* @������	��SysTick_IRQHandler
* @����  	��SysTick�ж�
* @����  	����
* @����ֵ 	����
*********************************************************************************
*/
// void SysTick_IRQHandler(void)
// {
//     //TimingDelay_Decrement();
// }


void IWDT_IRQHandler(void)
{
    //IWDT_Clear();
}


void CCM_IRQHandler(void)
{
    //CCMConfig(DISABLE, DISABLE, CCM_Trig_Rise);
    //SystemClockConfig();//ʹ���ڲ�20MHZ����
}


void PINT0_IRQHandler(void)
{
    if(PINT_GetITStatus(PINT_IT_PINT0) != RESET)
    {
        PINT_ClearITPendingBit(PINT_IT_PINT0);
        IWDT_Clear();
    }
}


void PINT2_IRQHandler(void)
{
    if(PINT_GetITStatus(PINT_IT_PINT2) != RESET)
    {
        PINT_ClearITPendingBit(PINT_IT_PINT2);
        IWDT_Clear();
    }
}


/*********************************************************
������: void T16N3_IRQHandler(void)
��  ��: T16N3��ʱ�жϺ���
����ֵ: ��
���ֵ: ��
����ֵ: ��
**********************************************************/
void T16N3_IRQHandler(void)
{


    return;
}

/*********************************************************
������: void Interrupt_KINT_Handler(void)
��  ��: �����жϴ�����
����ֵ: ��
���ֵ: ��
����ֵ: ��
**********************************************************/
void KINT_IRQHandler(void)
{

}


