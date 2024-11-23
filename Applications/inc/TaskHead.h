#ifndef H7OS_TASKHEAD_H
#define H7OS_TASKHEAD_H

#include "cmsis_os.h"
#include "xTaskManager.h"

#define UserName "root"

// �����̶߳���Ҫ�����������ע��
static osThreadId xTaskInitHandle; // ��FreeRTOS��ʼ������еĳ�ʼ����Ȼ�������
static osThreadId xTaskManagerHandle; // ���������������ͳ���߳�ռ�õ�
static osThreadId xShellHandle; // shell�߳�
static osThreadId xTaskTestHandle;  // �����߳�
static osThreadId xNoneHandle; // �����̣߳����ڲ���CPU���жȵ�

// ͳ��ʱ��
#define TaskTickStart(task) task->lastWakeTime = xTaskGetTickCount();
#define TaskTickEnd(task) task->accumulatedTime = xTaskGetTickCount() - task->lastWakeTime;

void ThreadInit();

#endif //H7OS_TASKHEAD_H
