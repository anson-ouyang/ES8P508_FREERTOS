/***************************************************************
 *Copyright (C), 2017, Shanghai Eastsoft Microelectronics Co., Ltd.
 *�ļ����� lib_gpio.c
 *�� �ߣ� Liut
 *�� ���� V1.00
 *�� �ڣ� 2017/07/14
 *�� ���� flash��д�⺯��ͷ�ļ�
 *�� ע�� ������ ES8P508xоƬ
 ���������ѧϰ����ʾʹ�ã����û�ֱ�����ô����������ķ��ջ������е��κη������Ρ�
 ***************************************************************/
#include "lib_gpio.h"
extern uint32_t SystemCoreClock;
/***************************************************************
  ��������GPIO_Init
  ��  ����GPIO��ʼ��
  ����ֵ��GPIOx��������GPIOA/GPIOB �� PINx������оƬѡ����Ҫ������ �� GPIO_InitStruct����ʼ�����ýṹ���ַ
  ���ֵ����
  ����ֵ����
 ***************************************************************/
void GPIO_Init(GPIO_TYPE GPIOx, GPIO_TYPE_PIN PINx, GPIO_InitStruType *GPIO_InitStruct)
{
    if (GPIO_InitStruct->GPIO_Signal == GPIO_Pin_Signal_Analog)
    {
        GPIO_SetSingalTypeFromPin(GPIOx, PINx, GPIO_Pin_Signal_Analog);
        GPIO_SetDirRegFromPin(GPIOx, PINx, GPIO_Dir_In);
        GPIO_SetFuncxRegFromPin(GPIOx, PINx, GPIO_Func_0);
    }
    else
    {
        GPIO_SetSingalTypeFromPin(GPIOx, PINx, GPIO_Pin_Signal_Digital);
        GPIO_SetDirRegFromPin(GPIOx, PINx, GPIO_InitStruct->GPIO_Direction);
        GPIO_SetFuncxRegFromPin(GPIOx, PINx, GPIO_InitStruct->GPIO_Func);

        if (GPIO_InitStruct->GPIO_Direction == GPIO_Dir_Out)
        {
            GPIO_SetODERegFromPin(GPIOx, PINx, GPIO_InitStruct->GPIO_OD);
            GPIO_SetDSRegFromPin(GPIOx, PINx, GPIO_InitStruct->GPIO_DS);
        }

        GPIO_SetPUERegFromPin(GPIOx, PINx, GPIO_InitStruct->GPIO_PUEN);
        GPIO_SetPDERegFromPin(GPIOx, PINx, GPIO_InitStruct->GPIO_PDEN);
    }
}

/***************************************************************
  ��������GPIO_SetFuncxRegFromPin
  ��  ��������GPIO���ŵĹ��ܸ���
  ����ֵ��Pin��Ŀ������
  Func�����ܸ��ñ��
  ���ֵ����
  ����ֵ����
 ***************************************************************/
void GPIO_SetFuncxRegFromPin(GPIO_TYPE GPIOx, GPIO_TYPE_PIN PINx, GPIO_TYPE_FUNC Func)
{
    uint32_t value;

    switch (Func)
    {
        case GPIO_Func_0:
            value = 0;
            break;

        case GPIO_Func_1:
            value = 1;
            break;

        case GPIO_Func_2:
            value = 2;
            break;

        case GPIO_Func_3:
            value = 3;
            break;

        default:
            value = 0;
            break;
    }

    /* ���Ź������� */
    if (GPIOx == GPIOB)
    {
        switch (PINx)
        {
            case GPIO_Pin_0:
                GPIO->PBFUNC0.PB0 = value;
                break;

            case GPIO_Pin_1:
                GPIO->PBFUNC0.PB1 = value;
                break;

            case GPIO_Pin_2:
                GPIO->PBFUNC0.PB2 = value;
                break;

            case GPIO_Pin_3:
                GPIO->PBFUNC0.PB3 = value;
                break;

            case GPIO_Pin_4:
                GPIO->PBFUNC0.PB4 = value;
                break;

            case GPIO_Pin_5:
                GPIO->PBFUNC0.PB5 = value;
                break;

            case GPIO_Pin_6:
                GPIO->PBFUNC0.PB6 = value;
                break;

            case GPIO_Pin_7:
                GPIO->PBFUNC0.PB7 = value;
                break;

            case GPIO_Pin_8:
                GPIO->PBFUNC1.PB8 = value;
                break;

            case GPIO_Pin_9:
                GPIO->PBFUNC1.PB9 = value;
                break;

            case GPIO_Pin_10:
                GPIO->PBFUNC1.PB10 = value;
                break;

            case GPIO_Pin_11:
                GPIO->PBFUNC1.PB11 = value;
                break;

            case GPIO_Pin_12:
                GPIO->PBFUNC1.PB12 = value;
                break;

            case GPIO_Pin_13:
                GPIO->PBFUNC1.PB13 = value;
                break;

            default:
                break;
        }
    }

    else
    {
        switch (PINx)
        {
            case GPIO_Pin_0:
                GPIO->PAFUNC0.PA0 = value;
                break;

            case GPIO_Pin_1:
                GPIO->PAFUNC0.PA1 = value;
                break;

            case GPIO_Pin_2:
                GPIO->PAFUNC0.PA2 = value;
                break;

            case GPIO_Pin_3:
                GPIO->PAFUNC0.PA3 = value;
                break;

            case GPIO_Pin_4:
                GPIO->PAFUNC0.PA4 = value;
                break;

            case GPIO_Pin_5:
                GPIO->PAFUNC0.PA5 = value;
                break;

            case GPIO_Pin_6:
                GPIO->PAFUNC0.PA6 = value;
                break;

            case GPIO_Pin_7:
                GPIO->PAFUNC0.PA7 = value;
                break;

            case GPIO_Pin_8:
                GPIO->PAFUNC1.PA8 = value;
                break;

            case GPIO_Pin_9:
                GPIO->PAFUNC1.PA9 = value;
                break;

            case GPIO_Pin_10:
                GPIO->PAFUNC1.PA10 = value;
                break;

            case GPIO_Pin_11:
                GPIO->PAFUNC1.PA11 = value;
                break;

            case GPIO_Pin_12:
                GPIO->PAFUNC1.PA12 = value;
                break;

            case GPIO_Pin_13:
                GPIO->PAFUNC1.PA13 = value;
                break;

            case GPIO_Pin_14:
                GPIO->PAFUNC1.PA14 = value;
                break;

            case GPIO_Pin_15:
                GPIO->PAFUNC1.PA15 = value;
                break;

            case GPIO_Pin_16:
                GPIO->PAFUNC2.PA16 = value;
                break;

            case GPIO_Pin_17:
                GPIO->PAFUNC2.PA17 = value;
                break;

            case GPIO_Pin_18:
                GPIO->PAFUNC2.PA18 = value;
                break;

            case GPIO_Pin_19:
                GPIO->PAFUNC2.PA19 = value;
                break;

            case GPIO_Pin_20:
                GPIO->PAFUNC2.PA20 = value;
                break;

            case GPIO_Pin_21:
                GPIO->PAFUNC2.PA21 = value;
                break;

            case GPIO_Pin_22:
                GPIO->PAFUNC2.PA22 = value;
                break;

            case GPIO_Pin_23:
                GPIO->PAFUNC2.PA23 = value;
                break;

            case GPIO_Pin_24:
                GPIO->PAFUNC3.PA24 = value;
                break;

            case GPIO_Pin_25:
                GPIO->PAFUNC3.PA25 = value;
                break;

            case GPIO_Pin_26:
                GPIO->PAFUNC3.PA26 = value;
                break;

            case GPIO_Pin_27:
                GPIO->PAFUNC3.PA27 = value;
                break;

            case GPIO_Pin_28:
                GPIO->PAFUNC3.PA28 = value;
                break;

            case GPIO_Pin_29:
                GPIO->PAFUNC3.PA29 = value;
                break;

            case GPIO_Pin_30:
                GPIO->PAFUNC3.PA30 = value;
                break;

            case GPIO_Pin_31:
                GPIO->PAFUNC3.PA31 = value;
                break;

            default:
                break;
        }
    }

    return;
}

/***************************************************************
  ��������GPIO_SetSingalTypeFromPin
  ��  �����������ŵ��ź�����
  ����ֵ��Pin: Ŀ������
  Signal: ���ŵ��ź�����
  ���ֵ����
  ����ֵ����
 ***************************************************************/
void GPIO_SetSingalTypeFromPin(GPIO_TYPE GPIOx, GPIO_TYPE_PIN PINx, GPIO_Pin_Signal GPIO_Signal)
{
    if (GPIOx == GPIOB)
    {
        if (GPIO_Signal == GPIO_Pin_Signal_Digital)
            GPIO->PBINEB.Word &= (~(1uL << (uint32_t)PINx));
        else
            GPIO->PBINEB.Word |= (1uL << (uint32_t)PINx);
    }
    else
    {
        if (GPIO_Signal == GPIO_Pin_Signal_Digital)
            GPIO->PAINEB.Word &= (~(1uL << (uint32_t)PINx));
        else
            GPIO->PAINEB.Word |= (1uL << (uint32_t)PINx);
    }

    return;
}

/***************************************************************
  ��������GPIO_SetDirRegFromPin
  ��  �����������ŵ�������������
  ����ֵ��Pin: Ŀ������
  Dir�����ŷ���
  ���ֵ����
  ����ֵ����
 ***************************************************************/
void GPIO_SetDirRegFromPin(GPIO_TYPE GPIOx, GPIO_TYPE_PIN PINx, GPIO_TYPE_DIR Dir)
{
    if (GPIOx == GPIOB)
    {
        if (Dir == GPIO_Dir_In)
            GPIO->PBDIRBSR.Word = (1uL << (uint32_t)PINx);
        else
            GPIO->PBDIRBCR.Word = (1uL << (uint32_t)PINx);
    }
    else
    {
        if (Dir == GPIO_Dir_In)
            GPIO->PADIRBSR.Word = (1uL << (uint32_t)PINx);
        else
            GPIO->PADIRBCR.Word = (1uL << (uint32_t)PINx);
    }

    return;
}

/***************************************************************
  ��������GPIO_SetODERegFromPin
  ��  �����������ŵ������©��ʽ
  ����ֵ��Pin: Ŀ������
     ODE: �����©��ʽ
  ���ֵ����
  ����ֵ����
 ***************************************************************/
void GPIO_SetODERegFromPin(GPIO_TYPE GPIOx, GPIO_TYPE_PIN PINx, GPIO_ODE_Output ODE)
{
    if (GPIOx == GPIOB)
    {
        if (ODE == GPIO_ODE_Output_Disable)
            GPIO->PBODE.Word &= (~(1uL << (uint32_t)PINx));
        else
            GPIO->PBODE.Word |= (1uL << (uint32_t)PINx);
    }
    else
    {
        if (ODE == GPIO_ODE_Output_Disable)
            GPIO->PAODE.Word &= (~(1uL << (uint32_t)PINx));
        else
            GPIO->PAODE.Word |= (1uL << (uint32_t)PINx);
    }

    return;
}

/***************************************************************
  ��������GPIO_SetDSRegFromPin
  ��  �����������ŵ������������
  ����ֵ��Pin: Ŀ������
DS: ����������ʽ
���ֵ����
����ֵ����
 ***************************************************************/
void GPIO_SetDSRegFromPin(GPIO_TYPE GPIOx, GPIO_TYPE_PIN PINx, GPIO_TYPE_DS DS)
{
    if (GPIOx == GPIOB)
    {
        if (DS == GPIO_DS_Output_Normal)
            GPIO->PBDS.Word &= (~(1uL << (uint32_t)PINx));
        else
            GPIO->PBDS.Word |= (1uL << (uint32_t)PINx);
    }
    else
    {
        if (DS == GPIO_DS_Output_Normal)
            GPIO->PADS.Word &= (~(1uL << (uint32_t)PINx));
        else
            GPIO->PADS.Word |= (1uL << (uint32_t)PINx);
    }

    return;
}

/***************************************************************
  ��������GPIO_SetPUERegFromPin
  ��  �����������ŵ���������ʽ
  ����ֵ��Pin: Ŀ������
PUE: ��������ʽ
���ֵ����
����ֵ����
 ***************************************************************/
void GPIO_SetPUERegFromPin(GPIO_TYPE GPIOx, GPIO_TYPE_PIN PINx, GPIO_PUE_Input PUE)
{
    if (GPIOx == GPIOB)
    {
        if (PUE == GPIO_PUE_Input_Disable)
            GPIO->PBPUE.Word &= (~(1uL << (uint32_t)PINx));
        else
            GPIO->PBPUE.Word |= (1uL << (uint32_t)PINx);
    }
    else
    {
        if (PUE == GPIO_PUE_Input_Disable)
            GPIO->PAPUE.Word &= (~(1uL << (uint32_t)PINx));
        else
            GPIO->PAPUE.Word |= (1uL << (uint32_t)PINx);
    }
}

/***************************************************************
  ��������GPIO_SetPDERegFromPin
  ��  �����������ŵ���������ʽ
  ����ֵ��Pin: Ŀ������
  PDE����������ʽ
  ���ֵ����
  ����ֵ����
 ***************************************************************/
void GPIO_SetPDERegFromPin(GPIO_TYPE GPIOx, GPIO_TYPE_PIN PINx, GPIO_PDE_Input PDE)
{
    if (GPIOx == GPIOB)
    {
        if (PDE == GPIO_PDE_Input_Disable)
            GPIO->PBPDE.Word &= (~(1uL << (uint32_t)PINx));
        else
            GPIO->PBPDE.Word |= (1uL << (uint32_t)PINx);
    }
    else
    {
        if (PDE == GPIO_PDE_Input_Disable)
            GPIO->PAPDE.Word &= (~(1uL << (uint32_t)PINx));
        else
            GPIO->PAPDE.Word |= (1uL << (uint32_t)PINx);
    }

    return;
}

/***************************************************************
  ��������GPIO_Write
  ��  ����GPIO�˿�д����
  ����ֵ��GPIOx��������GPIOA/GPIOB �� ValueҪд�����ݡ���ע�⣺��Щ�����ڵ����ţ����õ�ֵ���Ӧ��λ�������õ�
  ���ֵ����
  ����ֵ����
 ***************************************************************/
void GPIO_Write(GPIO_TYPE GPIOx, uint32_t Value)
{
    if (GPIOx == GPIOA)
        GPIO->PADATA.Word = Value;
    else if (GPIOx == GPIOB)
        GPIO->PBDATA.Word = Value;
}

/***************************************************************
  ��������GPIO_Read
  ��  ����GPIO�˿ڶ�����
  ����ֵ��GPIOx��������GPIOA/GPIOB
  ���ֵ����
  ����ֵ�����������ݡ���ע�⣺��Щ�����ڵ����ţ�������ֵ���Ӧ��λ����Ч��
 ***************************************************************/
uint32_t GPIO_Read(GPIO_TYPE GPIOx)
{
    if (GPIOx == GPIOA)
        return GPIO->PAPORT.Word;
    else if (GPIOx == GPIOB)
        return GPIO->PBPORT.Word;

    return 0;
}

/***************************************************************
  ��������GPIO_ReadBit
  ��  ����GPIO�˿ڶ�ĳλ����
  ����ֵ��GPIOx��������GPIOA/GPIOB �� PINx:GPIO_Pin_0 ���� GPIO_Pin_31
  ���ֵ����
  ����ֵ�����������ݡ���ע�⣺��Щ�����ڵ����ţ�������ֵ����Ч��
 ***************************************************************/
PinStatus GPIO_ReadBit(GPIO_TYPE GPIOx, GPIO_TYPE_PIN PINx)
{
    PinStatus bitstatus = RESET;

    if (GPIOx == GPIOA)
    {
        if ((GPIO->PAPORT.Word & (1uL << (uint32_t)PINx)) != RESET)
            bitstatus = SET;
        else
            bitstatus = RESET;
    }
    else if (GPIOx == GPIOB)
    {
        if ((GPIO->PBPORT.Word & (1uL << (uint32_t)PINx)) != RESET)
            bitstatus = SET;
        else
            bitstatus = RESET;
    }

    return bitstatus;
}

/***************************************************************
  ��������GPIOA_SetBit
  ��  ����GPIOAĳ������1
  ����ֵ��PINx��������GPIO_Pin_0 ���� GPIO_Pin_31
  ���ֵ����
  ����ֵ����
 ***************************************************************/
void GPIOA_SetBit(GPIO_TYPE_PIN PINx)
{
    GPIO->PADATABSR.Word = 1uL << (uint32_t)PINx;
}

/***************************************************************
  ��������GPIOA_ResetBit
  ��  ����GPIOAĳ������0
  ����ֵ��PINx��������GPIO_Pin_0 ���� GPIO_Pin_31
  ���ֵ����
  ����ֵ����
 ***************************************************************/
void GPIOA_ResetBit(GPIO_TYPE_PIN PINx)
{
    GPIO->PADATABCR.Word = 1uL << (uint32_t)PINx;
}

/***************************************************************
  ��������GPIOA_ToggleBit
  ��  ����GPIOAĳ�������״̬ȡ��
  ����ֵ��PINx��������GPIO_Pin_0 ���� GPIO_Pin_31
  ���ֵ����
  ����ֵ����
 ***************************************************************/
void GPIOA_ToggleBit(GPIO_TYPE_PIN PINx)
{
    GPIO->PADATABRR.Word = 1uL << (uint32_t)PINx;
}

/***************************************************************
  ��������GPIOB_SetBit
  ��  ����GPIOBĳ������1
  ����ֵ��PINx��������GPIO_Pin_0 ���� GPIO_Pin_13
  ���ֵ����
  ����ֵ����
 ***************************************************************/
void GPIOB_SetBit(GPIO_TYPE_PIN PINx)
{
    GPIO->PBDATABSR.Word = 1uL << (uint32_t)PINx;
}

/***************************************************************
  ��������GPIOB_ResetBit
  ��  ����GPIOBĳ������0
  ����ֵ��PINx��������GPIO_Pin_0 ���� GPIO_Pin_13
  ���ֵ����
  ����ֵ����
 ***************************************************************/
void GPIOB_ResetBit(GPIO_TYPE_PIN PINx)
{
    GPIO->PBDATABCR.Word = 1uL << (uint32_t)PINx;
}

/***************************************************************
  ��������GPIOB_ToggleBit
  ��  ����GPIOBĳ�������״̬ȡ��
  ����ֵ��PINx��������GPIO_Pin_0 ���� GPIO_Pin_13
  ���ֵ����
  ����ֵ����
 ***************************************************************/
void GPIOB_ToggleBit(GPIO_TYPE_PIN PINx)
{
    GPIO->PBDATABRR.Word = 1uL << (uint32_t)PINx;
}

/***************************************************************
  ��������GPIOA_SetDirection
  ��  ����GPIOAĳ�������÷���
  ����ֵ��PINx��������GPIO_Pin_0 ���� GPIO_Pin_31 �� Dir_Type��GPIO_Dir_Out/GPIO_Dir_In
  ���ֵ����
  ����ֵ����
 ***************************************************************/
void GPIOA_SetDirection(GPIO_TYPE_PIN PINx, GPIO_TYPE_DIR Dir_Type)
{
    GPIO->PADIR.Word &= ~(1uL << (uint32_t)PINx);
    GPIO->PADIR.Word |= ((uint32_t)Dir_Type << (uint32_t)PINx);
}

/***************************************************************
  ��������GPIOB_SetDirection
  ��  ����GPIOBĳ�������÷���
  ����ֵ��PINx��������GPIO_Pin_0 ���� GPIO_Pin_13 �� Dir_Type��GPIO_Dir_Out/GPIO_Dir_In
  ���ֵ����
  ����ֵ����
 ***************************************************************/
void GPIOB_SetDirection(GPIO_TYPE_PIN PINx, GPIO_TYPE_DIR Dir_Type)
{
    GPIO->PBDIR.Word &= ~(1uL << (uint32_t)PINx);
    GPIO->PBDIR.Word |= ((uint32_t)Dir_Type << (uint32_t)PINx);
}
/***************************************************************
  ��������Buzz_Config
  ��  ����Buzz����
  ����ֵ��Buzz_en:Buzz�Ƿ�ʹ�ܣ�freq:Ƶ��
  ���ֵ����
  ����ֵ����
 ***************************************************************/
void Buzz_Config(TYPE_BUZZEN buzz_en, uint32_t freq)
{
    GPIO->BUZC.BUZ_LOAD = (SystemCoreClock / (freq * 2)) - 1;
    GPIO->BUZC.BUZEN = buzz_en;
}

/***************************************************************
  ��������KINT_GetKINTxIndexFromPin
  ��  �����������ŵİ�������
  ����ֵ��Pin: Ŀ������
  ���ֵ����
  ����ֵ�����ŵİ�������
 ***************************************************************/
uint8_t KINT_GetKINTxIndexFromPin(GPIO_TYPE GPIOx, GPIO_TYPE_PIN Pin)
{
    uint8_t index = 0;

    if (GPIOx == GPIOA)
    {
        switch (Pin)
        {
            case GPIO_Pin_0:
            case GPIO_Pin_8:
            case GPIO_Pin_16:
            case GPIO_Pin_24:
                index = 0;
                break;

            case GPIO_Pin_1:
            case GPIO_Pin_9:
            case GPIO_Pin_17:
            case GPIO_Pin_25:
                index = 1;
                break;

            case GPIO_Pin_2:
            case GPIO_Pin_10:
            case GPIO_Pin_18:
            case GPIO_Pin_26:
                index = 2;
                break;

            case GPIO_Pin_3:
            case GPIO_Pin_11:
            case GPIO_Pin_19:
            case GPIO_Pin_27:
                index = 3;
                break;

            case GPIO_Pin_4:
            case GPIO_Pin_12:
            case GPIO_Pin_20:
            case GPIO_Pin_28:
                index = 4;
                break;

            case GPIO_Pin_5:
            case GPIO_Pin_13:
            case GPIO_Pin_21:
            case GPIO_Pin_29:
                index = 5;
                break;

            case GPIO_Pin_6:
            case GPIO_Pin_14:
            case GPIO_Pin_22:
            case GPIO_Pin_30:
                index = 6;
                break;

            case GPIO_Pin_7:
            case GPIO_Pin_15:
            case GPIO_Pin_23:
            case GPIO_Pin_31:
                index = 7;
                break;

            default:
                index = 0;
                break;
        }
    }
    else if (GPIOx == GPIOB)
    {
        switch (Pin)
        {
            case GPIO_Pin_0:
            case GPIO_Pin_8:
                index = 0;
                break;

            case GPIO_Pin_1:
            case GPIO_Pin_9:
                index = 1;
                break;

            case GPIO_Pin_2:
            case GPIO_Pin_10:
                index = 2;
                break;

            case GPIO_Pin_3:
            case GPIO_Pin_11:
                index = 3;
                break;

            case GPIO_Pin_4:
            case GPIO_Pin_12:
                index = 4;
                break;

            case GPIO_Pin_5:
            case GPIO_Pin_13:
                index = 5;
                break;

            case GPIO_Pin_6:
                index = 6;
                break;

            case GPIO_Pin_7:
                index = 7;
                break;

            default:
                index = 0;
                break;
        }
    }

    return index ;
}

/***************************************************************
  ��������KINT_SetTriggerStyleFromPin
  ��  �����������ŵİ���������ʽ
  ����ֵ��Pin: Ŀ������
   Style: �жϴ�����ʽ
  ���ֵ����
  ����ֵ����
 ***************************************************************/
void KINT_SetTriggerStyleFromPin(GPIO_TYPE GPIOx, GPIO_TYPE_PIN Pin, KINT_Trigger_Style Style)
{
    uint8_t Kintx;
    uint32_t value;

    Kintx = KINT_GetKINTxIndexFromPin(GPIOx, Pin);
    value = GPIO->KINTCFG.Word;
    value &= (~(7uL << (Kintx * 4)));

    switch (Style)
    {
        case KINT_Trigger_Rising_Edge:
            value |= (0uL << (Kintx * 4));
            break;

        case KINT_Trigger_Trailing_Edge:
            value |= (1uL << (Kintx * 4));
            break;

        case KINT_Trigger_High_Level:
            value |= (2uL << (Kintx * 4));
            break;

        case KINT_Trigger_Low_Level:
            value |= (3uL << (Kintx * 4));
            break;

        case KINT_Trigger_Both_Edge:
            value |= (4uL << (Kintx * 4));
            break;

        default:
            break;
    }

    GPIO->KINTCFG.Word = value;

    return;
}

/***************************************************************
  ��������KINT_GetSelxIndexFromPin
  ��  �����������ŵĶ˿�ѡ������
  ����ֵ��Pin: Ŀ������
  ���ֵ����
  ����ֵ��Ŀ�����ŵĶ˿�ѡ������
 ***************************************************************/
uint8_t KINT_GetSelxIndexFromPin(GPIO_TYPE GPIOx, GPIO_TYPE_PIN Pin)
{
    uint8_t index = 0;

    if (GPIOx == GPIOA)
    {
        switch (Pin)
        {
            case GPIO_Pin_0:
            case GPIO_Pin_1:
            case GPIO_Pin_2:
            case GPIO_Pin_3:
            case GPIO_Pin_4:
            case GPIO_Pin_5:
            case GPIO_Pin_6:
            case GPIO_Pin_7:
                index = 0;
                break;

            case GPIO_Pin_8:
            case GPIO_Pin_9:
            case GPIO_Pin_10:
            case GPIO_Pin_11:
            case GPIO_Pin_12:
            case GPIO_Pin_13:
            case GPIO_Pin_14:
            case GPIO_Pin_15:
                index = 1;
                break;

            case GPIO_Pin_16:
            case GPIO_Pin_17:
            case GPIO_Pin_18:
            case GPIO_Pin_19:
            case GPIO_Pin_20:
            case GPIO_Pin_21:
            case GPIO_Pin_22:
            case GPIO_Pin_23:
                index = 2;
                break;

            case GPIO_Pin_24:
            case GPIO_Pin_25:
            case GPIO_Pin_26:
            case GPIO_Pin_27:
            case GPIO_Pin_28:
            case GPIO_Pin_29:
            case GPIO_Pin_30:
            case GPIO_Pin_31:
                index = 3;
                break;

            default:
                index = 0;
                break;
        }
    }

    else if (GPIOx == GPIOB)
    {
        switch (Pin)
        {
            case GPIO_Pin_0:
            case GPIO_Pin_1:
            case GPIO_Pin_2:
            case GPIO_Pin_3:
            case GPIO_Pin_4:
            case GPIO_Pin_5:
            case GPIO_Pin_6:
            case GPIO_Pin_7:
                index = 4;
                break;

            case GPIO_Pin_8:
            case GPIO_Pin_9:
            case GPIO_Pin_10:
            case GPIO_Pin_11:
            case GPIO_Pin_12:
            case GPIO_Pin_13:
                index = 5;
                break;

            default:
                index = 0;
                break;
        }
    }

    return index;
}

/***************************************************************
  ��������KINT_SetEnableOrNotFromPin
  ��  ����ʹ�ܻ�������ŵİ����ж�
  ����ֵ��Pin: Ŀ������
      IE: �����ж�ʹ�ܷ�ʽ
  ���ֵ����
  ����ֵ����
 ***************************************************************/
void KINT_SetEnableOrNotFromPin(GPIO_TYPE GPIOx, GPIO_TYPE_PIN Pin, KINT_IE_Set IE)
{
    uint8_t Kintx;
    uint8_t Selx;
    uint32_t value;

    /* �ж���������ѡ�� */
    Kintx = KINT_GetKINTxIndexFromPin(GPIOx, Pin);
    Selx = KINT_GetSelxIndexFromPin(GPIOx, Pin);

    value = GPIO->KINTSEL.Word;
    value &= (~(7uL << (Kintx * 4)));
    value |= (Selx << (Kintx * 4));
    GPIO->KINTSEL.Word = value;

    /* ����жϱ�־ */
    value = (1uL << Kintx);
    GPIO->KINTIF.Word = value;

    /* ʹ��KINT�ж� */
    value = GPIO->KINTIE.Word;

    if (IE == KINT_IE_Set_Disable)
    {
        value &= (~(1uL << Kintx)); /* ���ʹ��λ */
        value |= (1uL << (Kintx + 8));  /* �����ж� */
        GPIO->KINTIE.Word = value;
        NVIC->ICER[0] = (1uL << 18);
    }
    else
    {
        value |= (1uL << Kintx);    /* ����ʹ��λ */
        value &= (~(1uL << (Kintx + 8))); /* �������ж� */
        GPIO->KINTIE.Word = value;
        NVIC->ISER[0] = (1uL << 19);
    }

    return;
}

/***************************************************************
  ��������KINT_Init
  ��  �����������ų�ʼ��
  ����ֵ��Pin: Ŀ������
 InitSet: ��ʼ���ṹ��
  ���ֵ����
  ����ֵ����
 ***************************************************************/
void KINT_Init(GPIO_TYPE GPIOx, GPIO_TYPE_PIN Pin, KINT_InitSettingType *InitSet)
{
    KINT_SetTriggerStyleFromPin(GPIOx, Pin, InitSet->Trigger_Style);
    KINT_SetEnableOrNotFromPin(GPIOx, Pin, InitSet->IE_Set);
}

/***************************************************************
  ��������KINT_ClearITFlag
  ��  ����������ŵİ����жϱ�־
  ����ֵ��Pin: Ŀ������
  ���ֵ����
  ����ֵ����
 ***************************************************************/
void KINT_ClearITFlag(GPIO_TYPE GPIOx, GPIO_TYPE_PIN Pin)
{
    uint8_t Kintx;
    uint32_t value;

    Kintx = KINT_GetKINTxIndexFromPin(GPIOx, Pin);

    value = (1uL << Kintx);
    GPIO->KINTIF.Word = value;
    return;
}

/***************************************************************
  ��������KINT_GetITFlag
  ��  ������ȡ���ŵİ����жϱ�־
  ����ֵ��Pin: Ŀ������
  ���ֵ����
  ����ֵ��Ŀ�����ŵİ����жϱ�־
 ***************************************************************/
uint32_t KINT_GetITFlag(GPIO_TYPE GPIOx, GPIO_TYPE_PIN Pin)
{
    uint8_t Kintx;
    uint32_t value;

    Kintx = KINT_GetKINTxIndexFromPin(GPIOx, Pin);

    value = GPIO->KINTIF.Word;
    value >>= Kintx;
    value &= 0x01;
    return value;
}

/***************************************************************
  ��������PINT_Config
  ��  ����PINT����
  ����ֵ��PINTx����ѡPINT0 ���� PINT7 �� SELx������ѡ�� �� TRIGx������ѡ��
  ���ֵ����
  ����ֵ����
 ***************************************************************/
void PINT_Config(PINT_TYPE PINTx, PINT_TYPE_SEL SELx, PINT_TYPE_TRIG TRIGx)
{
    GPIO->PINTSEL.Word &= ~(7uL << ((uint32_t)PINTx * 4));
    GPIO->PINTSEL.Word |= ((uint32_t)SELx << ((uint32_t)PINTx * 4)); //selѡ��

    GPIO->PINTCFG.Word &= ~(7uL << ((uint32_t)PINTx * 4));
    GPIO->PINTCFG.Word |= ((uint32_t)TRIGx << ((uint32_t)PINTx * 4)); //������ʽѡ��
}

/***************************************************************
  ��������PINT_GetIFStatus
  ��  ����PINT��ȡ�жϱ�־
  ����ֵ��PINTx��PINT0-PINT7
  ���ֵ����
  ����ֵ��SET/RESET
 ***************************************************************/
FlagStatus PINT_GetIFStatus(PINT_TYPE_IT PINT_Flag)
{
    FlagStatus bitstatus = RESET;

    if ((GPIO->PINTIF.Word & (uint32_t)PINT_Flag) != (uint32_t)RESET)
        bitstatus = SET;
    else
        bitstatus = RESET;

    return  bitstatus;
}

/***************************************************************
  ��������PINT_GetITStatus
  ��  ����PINT��ȡ�жϱ�־
  ����ֵ��PINTx��PINT0-PINT7
  ���ֵ����
  ����ֵ��SET/RESET
 ***************************************************************/
FlagStatus PINT_GetITStatus(PINT_TYPE_IT PINT_Flag)
{
    FlagStatus bitstatus = RESET;

    if ((GPIO->PINTIF.Word & (uint32_t)PINT_Flag) != (uint32_t)RESET)
        bitstatus = SET;
    else
        bitstatus = RESET;

    return  bitstatus;
}

/***************************************************************
  ��������PINT_ClearITPendingBit
  ��  ����PINT����жϱ�־
  ����ֵ��PINT�ж�����
  ���ֵ����
  ����ֵ����
 ***************************************************************/
void PINT_ClearITPendingBit(PINT_TYPE_IT PINT_Flag)
{
    GPIO->PINTIF.Word = (uint32_t)PINT_Flag;
}

/***************************************************************
��������UART_TXxConfig
��  ����TXx��������������
����ֵ��Plv�����Ƶ�ƽѡ�� ��Ps������PWM����ѡ�� ��TxSx: ���Ʋ�������ܽ�ѡ��
���ֵ����
����ֵ����
***************************************************************/

void GPIO_TX0Config(UART_TYPE_TXPLV Plv, UART_TYPE_TX0PS Ps, UART_TYPE_TX0Sx TX0Sx)
{
    GPIO->TXPWM.TX0PS = Ps;
    GPIO->TXPWM.TX0PLV = Plv;

    if (Ps == UART_TX0PS_NO)
        return;

    switch (TX0Sx)
    {
        case UART_TYPE_TXD0:
            GPIO->TXPWM.TX0_S = 0x0;
            break;

        case UART_TYPE_TX0BUZ:
            GPIO->TXPWM.TX0_S = 0x1;
            break;

        case UART_TYPE_T16N0OUT0:
            GPIO->TXPWM.TX0_S = 0x2;
            break;

        case UART_TYPE_T16N0OUT1:
            GPIO->TXPWM.TX0_S = 0x3;
            break;
    }
}

void GPIO_TX1Config(UART_TYPE_TXPLV Plv, UART_TYPE_TX1PS Ps, UART_TYPE_TX1Sx TX1Sx)
{
    GPIO->TXPWM.TX1PLV = Plv;
    GPIO->TXPWM.TX1PS = Ps;

    if (Ps == UART_TX1PS_NO)
        return;

    switch (TX1Sx)
    {
        case UART_TYPE_TXD1:
            GPIO->TXPWM.TX1_S = 0x0;
            break;

        case UART_TYPE_TX1BUZ:
            GPIO->TXPWM.TX1_S = 0x1;
            break;

        case UART_TYPE_T16N1OUT0:
            GPIO->TXPWM.TX1_S = 0x2;
            break;

        case UART_TYPE_T16N1OUT1:
            GPIO->TXPWM.TX1_S = 0x3;
            break;
    }
}

void GPIO_TX2Config(UART_TYPE_TXPLV Plv, UART_TYPE_TX2PS Ps, UART_TYPE_TX2Sx TX2Sx)
{
    GPIO->TXPWM.TX2PLV = Plv;
    GPIO->TXPWM.TX2PS = Ps;

    if (Ps == UART_TX2PS_NO)
        return;

    switch (TX2Sx)
    {
        case UART_TYPE_TXD2:
            GPIO->TXPWM.TX2_S = 0x0;
            break;

        case UART_TYPE_TX2BUZ:
            GPIO->TXPWM.TX2_S = 0x1;
            break;

        case UART_TYPE_T16N2OUT0:
            GPIO->TXPWM.TX2_S = 0x2;
            break;
            
        case UART_TYPE_T16N2OUT1:
            GPIO->TXPWM.TX2_S = 0x3;
            break;
            

    }
}

void GPIO_TX3Config(UART_TYPE_TXPLV Plv, UART_TYPE_TX3PS Ps, UART_TYPE_TX3Sx TX3Sx)
{
    GPIO->TXPWM.TX3PLV = Plv;
    GPIO->TXPWM.TX3PS = Ps;

    if (Ps == UART_TX3PS_NO)
        return;

    switch (TX3Sx)
    {
        case UART_TYPE_TXD3:
            GPIO->TXPWM.TX3_S = 0x0;
            break;

        case UART_TYPE_TX3BUZ:
            GPIO->TXPWM.TX3_S = 0x1;
            break;

        case UART_TYPE_T16N3OUT0:
            GPIO->TXPWM.TX3_S = 0x2;
            break;

        case UART_TYPE_T16N3OUT1:
            GPIO->TXPWM.TX3_S = 0x3;
            break;
    }
}


void GPIO_Set(GPIO_TYPE type, GPIO_TYPE_PIN pin)
{
    switch(type)
    {
        case GPIOB:
            GPIOB_SetBit(pin);
            break;
        default:
            GPIOA_SetBit(pin);
            break;
    }
}


void GPIO_Reset(GPIO_TYPE type, GPIO_TYPE_PIN pin)
{
    switch(type)
    {
        case GPIOB:
            GPIOB_ResetBit(pin);
            break;
        default:
            GPIOA_ResetBit(pin);
            break;
    }
}






/*************************END OF FILE**********************/



