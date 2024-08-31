#include "test.h"
#include "u_stdio.h"
#include "cmsis_os.h"
#include "quadspi.h"
#include "RAMFS.h"
#include "fatfs.h"
#include "sdmmc.h"

// ���SD����Ϣ
void printf_sdcard_info(void)
{
    HAL_SD_CardInfoTypeDef  SDCardInfo;
    uint64_t CardCap;      	//SD������
    HAL_SD_CardCIDTypeDef SDCard_CID;

    HAL_SD_GetCardCID(&hsd1,&SDCard_CID);	//��ȡCID
    HAL_SD_GetCardInfo(&hsd1,&SDCardInfo);                    //��ȡSD����Ϣ
    CardCap=(uint64_t)(SDCardInfo.LogBlockNbr)*(uint64_t)(SDCardInfo.LogBlockSize);	//����SD������
    switch(SDCardInfo.CardType)
    {
        case CARD_SDSC:
        {
            if(SDCardInfo.CardVersion == CARD_V1_X)
                u_print("Card Type:SDSC V1\r\n");
            else if(SDCardInfo.CardVersion == CARD_V2_X)
                u_print("Card Type:SDSC V2\r\n");
        }
            break;
        case CARD_SDHC_SDXC:u_print("Card Type:SDHC\r\n");break;
        default:break;
    }
    // SD�ĸ�����Ϣ���������ȷ��SD���Ƿ���������
    u_print("Card ManufacturerID: %d \r\n",SDCard_CID.ManufacturerID);				//������ID
    u_print("CardVersion:         %d \r\n",(uint32_t)(SDCardInfo.CardVersion));		//���汾��
    u_print("Class:               %d \r\n",(uint32_t)(SDCardInfo.Class));		    //
    u_print("Card RCA(RelCardAdd):%d \r\n",SDCardInfo.RelCardAdd);					//����Ե�ַ
    u_print("Card BlockNbr:       %d \r\n",SDCardInfo.BlockNbr);						//������
    u_print("Card BlockSize:      %d \r\n",SDCardInfo.BlockSize);					//���С
    u_print("LogBlockNbr:         %d \r\n",(uint32_t)(SDCardInfo.LogBlockNbr));		//�߼�������
    u_print("LogBlockSize:        %d \r\n",(uint32_t)(SDCardInfo.LogBlockSize));		//�߼����С
    u_print("Card Capacity:       %d MB\r\n",(uint32_t)(CardCap>>20));				//������
}


void testFunc(){
    // kernel_test();
    // displayDevice();
    // execCMD("cd /mnt");
    // execCMD("ls");
    // u_print("testFunc\n");

    osDelay(1000);
}