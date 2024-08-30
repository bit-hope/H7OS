#ifndef H7OS_CPU_H
#define H7OS_CPU_H

#include <stdint-gcc.h>
#include "RAMFS.h"
#include "cmsis_os.h"

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
    // --------------------
    // CPU����
    Func_t loadState;
};

typedef struct CPU* CPU_t;

static CPU_t CortexM7;

/**
 * ����CPU����
 * @return CPU����
 * @note �ú������Զ���ʼ��CPU���󣬶���ΪCortexM7
 */
CPU_t createCPU();


#endif //H7OS_CPU_H
