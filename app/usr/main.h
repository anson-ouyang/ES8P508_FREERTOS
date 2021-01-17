#ifndef __MAIN_H__
#define __MAIN_H__

//#include "global_define.h"

#define GPIO_SYSTICK_COUNT  10


typedef enum
{
    ADC_TASK_ID=0,
    PM_TASK_ID,
    UPDATE_DATA_TASK_ID,
    WDT_TASK_ID,
    
}TASK_ID_S;


#define    ALL_TASK_EVENTS  (0x07) //WDT_TASK除外




typedef enum
{
    KEY_DOWN_EV_ID = 0,
    KEY_UP_EV_ID,
    SC8933_INT_EV_ID,
    PHONE_OUT_EV_ID,
    IIC_READ_EV_ID,
    IIC_WRITE_EV_ID=5,
    PAYLOAD_IN_EV_ID,

}GPIO_EVENT_ID;



typedef enum
{

    FLASH_RESET_PW_EV_ID =0,
    FLASH_RESET_SN_EV_ID,
    FLASH_RESET_ID_EV_ID,
    FLASH_RESET_UPDATE_FLAG_EV_ID,
    FLASH_RESET_SYSGOOD_FLAG_EV_ID,
    FLASH_RESET_REBOOT_COUNT_EV_ID=5,
    FLASH_RESET_PWL_EV_ID,
    FLASH_RESET_DS_EV_ID,
    FLASH_RESET_E2_EV_ID,
    FLASH_RESET_E1_EV_ID,
    FLASH_RESET_CDS_EV_ID=10,
    FLASH_RESET_SCM_EV_ID,
    FLASH_RESET_M2_EV_ID,
    FLASH_RESET_M1_EV_ID,
    FLASH_RESET_ALLOW_SN_EV_ID,

}FLASH_RESET_EVENTS_ID;




#define    KEY_DOWN_EV                  (1<<KEY_DOWN_EV_ID)
#define    KEY_UP_EV                    (1<<KEY_UP_EV_ID)
#define    SC8933_INT_EV                (1<<SC8933_INT_EV_ID)
#define    PHONE_OUT_EV                 (1<<PHONE_OUT_EV_ID)
#define    PAYLOAD_IN_EV                (1<<PAYLOAD_IN_EV_ID)
#define    IIC_READ_EV                  (1<<IIC_READ_EV_ID)
#define    IIC_WRITE_EV                 (1<<IIC_WRITE_EV_ID)
#define    ALL_GPIO_EVENT                (0x7f)




#define    FLASH_RESET_PW_EV            (1<<FLASH_RESET_PW_EV_ID)
#define    FLASH_RESET_SN_EV            (1<<FLASH_RESET_SN_EV_ID)
#define    FLASH_RESET_ID_EV            (1<<FLASH_RESET_ID_EV_ID)
#define    FLASH_RESET_UPDATE_FLAG_EV   (1<<FLASH_RESET_UPDATE_FLAG_EV_ID)
#define    FLASH_RESET_SYSGOOD_FLAG_EV  (1<<FLASH_RESET_SYSGOOD_FLAG_EV_ID)
#define    FLASH_RESET_REBOOT_COUNT_EV  (1<<FLASH_RESET_REBOOT_COUNT_EV_ID)
#define    FLASH_RESET_PWL_EV           (1<<FLASH_RESET_PWL_EV_ID)
#define    FLASH_RESET_DS_EV            (1<<FLASH_RESET_DS_EV_ID)
#define    FLASH_RESET_E2_EV            (1<<FLASH_RESET_E2_EV_ID)
#define    FLASH_RESET_E1_EV            (1<<FLASH_RESET_E1_EV_ID)
#define    FLASH_RESET_CDS_EV           (1<<FLASH_RESET_CDS_EV_ID)
#define    FLASH_RESET_SCM_EV           (1<<FLASH_RESET_SCM_EV_ID)
#define    FLASH_RESET_M2_EV            (1<<FLASH_RESET_M2_EV_ID)
#define    FLASH_RESET_M1_EV            (1<<FLASH_RESET_M1_EV_ID)
#define    FLASH_RESET_ALLOW_SN_EV      (1<<FLASH_RESET_ALLOW_SN_EV_ID)
#define    ALL_FLASH_RESET_EVENTS       (0x7fff)






typedef struct BAT_INFO
{
    //结构体数据
    TypeOfADC_Result stAdcRlt;
    
    KEY_RESULT enKeyOpt;
    
    TEMP_INFO stTempInfo;

    BAT_CAP_INFO stBatInfo;

    IIC_TASK_INFO stIICTaskInfo;

    //标志位
    uint8_t chargeFlag;
    uint8_t dischargeFlag;
    uint8_t dcInFlag;
    uint8_t payloadInFlag;
    uint8_t sleepFlag;

    uint16_t sleepTimeout;
    
    //数组
    uint32_t systick[GPIO_SYSTICK_COUNT];

    //事件句柄
    EventGroupHandle_t hGpioEvent;
    EventGroupHandle_t hTaskEvent;
    EventGroupHandle_t hFlashEvent;
    
    

    //任务句柄
    TaskHandle_t hadcTask;
    TaskHandle_t hpmTask;
    TaskHandle_t hwdtTask;

    //定时器句柄
    TimerHandle_t hledTimer1;
    TimerHandle_t hledTimer2;
    TimerHandle_t h1sTimer;
    
}BAT_INFO_ST;


#ifndef __MAIN_C__
extern BAT_INFO_ST g_stBatInfo;

#endif
void SetPeripheralGate(boolean_t bFlag);

#endif

