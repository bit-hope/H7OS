#ifndef H7OS_XTASKMANAGER_H
#define H7OS_XTASKMANAGER_H

#include "cmsis_os.h"

enum TaskStatus{
    TASK_READY,
    TASK_RUNNING,
    TASK_SUSPEND,
    TASK_STOP
};

typedef enum TaskStatus TaskStatus_E;

// ����Ȩ��ö��
enum TaskPriority{
    TASK_PRIORITY_NORMAL,
    TASK_PRIORITY_HIGH,
    TASK_PRIORITY_ROOT,
    TASK_PRIORITY_SYSTEM,
};

typedef enum TaskPriority TaskPriority_E;


typedef struct Task* Task_t;

// ���������
struct Task{
    // ����ID
    char *name;
    // ����״̬
    TaskStatus_E status;
    // CPUռ����
    float cpu;
    // ����Ȩ��
    TaskPriority_E priority;
    // ������
    osThreadId handle;
    // ����
    uint32_t lastWakeTime;
    // �ۼ�ʱ��
    uint32_t accumulatedTime;
    // PID
    uint8_t PID;
    // ��һ������
    Task_t next;
};


void TaskManager(void const * argument);

#endif //H7OS_XTASKMANAGER_H
