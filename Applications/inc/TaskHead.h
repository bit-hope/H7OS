#ifndef H7OS_TASKHEAD_H
#define H7OS_TASKHEAD_H

#include "cmsis_os.h"

// �����̶߳���Ҫ�����������ע��
static osThreadId xTaskInitHandle;
static osThreadId xTaskManagerHandle;
static osThreadId xShellHandle;

void ThreadInit();

#endif //H7OS_TASKHEAD_H
