#ifndef H7OS_XTASKINIT_H
#define H7OS_XTASKINIT_H


#include "cmsis_os.h"

static osThreadId xTaskInitHandle;

// ��FreeRTOS��ʼ��ǰ���еĳ�ʼ��
void taskGlobalInit();

// ��FreeRTOS��ʼ������еĳ�ʼ��
void QueueInit(void const * argument);

#endif
