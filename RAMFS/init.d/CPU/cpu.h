#ifndef H7OS_CPU_H
#define H7OS_CPU_H

#include <stdint-gcc.h>
#include "RAMFS.h"
#include "cmsis_os.h"

typedef float (*CPU_Func_t)(void);

struct CPU{
    // CPU����
    char* name;
    // CPU����
    char* description;
    // CPUƵ��
    uint32_t frequency;
    // CPU�¶�
    double temperature;
    // CPU����
    double load;
};
// CPU����
typedef struct CPU* CPU_t;

/**
 * ����CPU����
 * @return CPU����
 * @note �ú������Զ���ʼ��CPU���󣬶���ΪCortexM7
 */
void createCPU();

void showCPUInfo();


#endif //H7OS_CPU_H
