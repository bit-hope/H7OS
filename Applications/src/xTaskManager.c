#include "xTaskManager.h"
#include "TaskHead.h"
#include "xShellTask.h"
#include "xTaskInit.h"
#include "memctl.h"
#include "u_stdio.h"
#include "init.d/DrT/DrT.h"

uint8_t PID_Global = 0;

Task_t RAMFS_TASK_Create(char *name, TaskStatus_E status, TaskPriority_E priority, osThreadId handle){
    Task_t task = (Task_t) kernel_alloc(sizeof(struct Task));

    task->name = kernel_alloc(strlen(name) + 1);
    strcopy(task->name, name);

    task->status = status;
    task->PID = PID_Global++;
    task->cpu = 0;
    task->priority = priority;
    task->handle = handle;
    task->next = NULL;
    return task;
}


void ThreadInit(){
    // �̶߳����������ע��
    osThreadDef(xShell, ShellTask, osPriorityNormal, 0, 1024);
    xShellHandle = osThreadCreate(osThread(xShell), NULL);

    osThreadDef(xTaskManager, TaskManager, osPriorityAboveNormal, 0, 1024);
    xTaskManagerHandle = osThreadCreate(osThread(xTaskManager), NULL);

    osThreadDef(xTaskInit, QueueInit, osPriorityIdle, 0, 2048);
    xTaskInitHandle = osThreadCreate(osThread(xTaskInit), NULL);
}

void TaskManager(void const * argument){
    addThread(RAMFS_TASK_Create("xShell", TASK_READY, TASK_PRIORITY_SYSTEM, xShellHandle));
    addThread(RAMFS_TASK_Create("xTaskManager", TASK_READY, TASK_PRIORITY_SYSTEM, xTaskManagerHandle));
    addThread(RAMFS_TASK_Create("xTaskInit", TASK_READY, TASK_PRIORITY_SYSTEM, xTaskInitHandle));

    uint8_t *info = kernel_alloc(1024);

    while(1){
        memorySet(info, 0, 1024);
        // TODO ������FreeRTOS��vTaskList��������ΪFreeRTOS��vTaskList�����ᵼ����������޷���ȡ������Ϣ
        // TODO ʵ��һ���Լ���vTaskList����

//         vTaskList((char *)&info); //��ȡ��������ʱ����Ϣ
//        u_print("%s", info);
//        u_print("TaskManager\n");
        osDelay(1000);
    }
}