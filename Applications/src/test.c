#include "test.h"
#include "u_stdio.h"
#include "cmsis_os.h"
#include "quadspi.h"
#include "timer.h"
#include "fatfs.h"
#include "memctl.h"
#include "RAMFS.h"

FRESULT FSRes;

void testFuncInit(){
    FATFS_LinkDriver(&SD_Driver, SDPath);
    FSRes = f_mount(&SDFatFS,SDPath,1);
    BYTE work[_MAX_SS];
    if (FSRes != FR_OK){
        FSRes = f_mkfs(SDPath, FM_FAT32, 0, work, sizeof work);
        if (FSRes == FR_OK) u_print("SD card init succeed\r\n");
        else u_print("Init Faild, please replace SD card\r\n");
    }

    if(QSPI_W25Qxx_BlockErase_32K(0) != QSPI_W25Qxx_OK)
        u_print("Erase Failed\n");


    DrTInit();

    u_print("init OK");

}


void testFunc(){
    // kernel_test();
    // displayDevice();
    // execCMD("ls");
    // u_print("testFunc\n");
    osDelay(1000);
}