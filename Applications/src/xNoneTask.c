#include "xNoneTask.h"
#include "cmsis_os.h"
#include "xTaskManager.h"
#include "TaskHead.h"

extern Task_t xNoneTask;

// ���������߳�(����ͳ��CPU����)
void NoneTask(void const * argument){
    while(1){
        TaskTickStart(xNoneTask);
        osDelay(100);
        TaskTickEnd(xNoneTask);
    }
}