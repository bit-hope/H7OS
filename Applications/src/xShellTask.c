#include "xShellTask.h"
#include "cmsis_os.h"
#include "RAMFS.h"
#include "u_stdio.h"
#include "adc.h"

// �ն��̳߳�ʼ������ʱΪ�˵ȴ������̳߳�ʼ�����
void taskShellInit(){
    osDelay(1000);
}

// �ն��߳�ѭ��
void taskLoop(){
    // execCMD("help ls");
    osDelay(1000);
}