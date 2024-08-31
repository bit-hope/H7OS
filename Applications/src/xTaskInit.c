#include "xTaskInit.h"
#include "fatfs.h"
#include "u_stdio.h"
#include "sdmmc.h"
#include "quadspi.h"
#include "RAMFS.h"
#include "adc.h"

// ��ʼ��ȫ������
void taskGlobalInit(){
    // ���SD����Ϣ�� ȷ��SD����������
    HAL_SD_CardInfoTypeDef  SDCardInfo;
    HAL_SD_CardCIDTypeDef SDCard_CID;

    HAL_SD_GetCardCID(&hsd1,&SDCard_CID);
    HAL_SD_GetCardInfo(&hsd1,&SDCardInfo);
    uint64_t CardCap=(uint64_t)(SDCardInfo.LogBlockNbr)*(uint64_t)(SDCardInfo.LogBlockSize);	//����SD������
    u_print("SD card Drive Capacitor: %D MB\r\n", (uint32_t)(CardCap>>20));

    // CPU������ʼ��
    HAL_ADCEx_Calibration_Start(&hadc3,ADC_CALIB_OFFSET,ADC_SINGLE_ENDED);
    HAL_ADC_Start(&hadc3);  /* ����ADC3��ת�� */

    // QSPI Flash��ʼ����������������
    if(QSPI_W25Qxx_BlockErase_32K(0) != QSPI_W25Qxx_OK)
        u_print("Erase Failed\n");
    else u_print("QSPI Flash Succeed, ID: %d\n", QSPI_W25Qxx_ReadID());

    // RAMFS��ʼ��
    DrTInit();
    // CPU�ṹ���ʼ��(���ڱ�עCPU����Ϣ)
    createCPU();
}

/*** ������д���� **
 *  @note: �ú������ڳ�ʼ��SD�������SD��δ���أ����Ը�ʽ��SD��
 *      ����Ŀʹ��CubeMX���ɵ�Fatfs����ʹ����Freertos��Fatfs����ʹ��FreeRTOS����Ϣ����
 *      ������Ҫ��osKernelStart()֮ǰ��ʼ��Fatfs
 *      ע�⣺��Ҫ����MDMA�ſ�������ʹ��FATFS��f_mkfs����
 * */
void QueueInit(void const * argument){
    // SD������FATFS
    FRESULT FSRes = f_mount(&SDFatFS,SDPath,1);
    BYTE work[_MAX_SS];
    // �������ʧ�ܣ����Ը�ʽ��SD��
    if (FSRes != FR_OK){
        // ����FAT32�ļ�ϵͳ
        FSRes = f_mkfs(SDPath, FM_FAT32, 0, work, sizeof work);
        // �ж��Ƿ��ʼ���ɹ�
        if (FSRes == FR_OK) {
            // ��ʼ���ɹ������¹���
            u_print("SD card init succeed\r\n");
            f_mount(&SDFatFS,SDPath,1);
        }
        // ��ʼ��ʧ�ܣ���ʾ�û�����SD��
        else u_print("Init Faild, please replace SD card\r\n");
    }
    // ��ʼ���ɹ�����ʾ�û�
    else u_print("SD card Succeed\r\n");
    // һ���Գ�ʼ����ɣ������ʼ������
    vTaskSuspend(xTaskInitHandle);
}