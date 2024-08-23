#include "timer.h"
#include "rtc.h"
#include "rng.h"

RTC_TimeTypeDef Time_Struct;
RTC_DateTypeDef Date_Struct;

/***
 * ����ʱ��
 */
void UpdateTime(){
    HAL_RTC_GetTime(&hrtc,&Time_Struct,RTC_FORMAT_BIN);
    HAL_RTC_GetDate(&hrtc,&Date_Struct,RTC_FORMAT_BIN);
}

/***
 * ��ȡ��ǰ��
 * @return ��ǰ��
 */
uint8_t getSecond(){
    return Time_Struct.Seconds;
}

/***
 * ��ȡ��ǰ����
 * @return ��ǰ����
 */
uint8_t getMinute(){
    return Time_Struct.Minutes + Correct_Minute;
}

/***
 * ��ȡ��ǰСʱ
 * @return ��ǰСʱ
 */
uint8_t getHour(){
    return Time_Struct.Hours + Correct_Hour;
}

/***
 * ��ȡ��ǰ����
 * @return ��ǰ����
 */
uint8_t getDay(){
    return Date_Struct.Date + Correct_Day;
}

/***
 * ��ȡ��ǰ�·�
 * @return ��ǰ�·�
 */
uint8_t getMonth(){
    return Date_Struct.Month + Correct_Month;
}

/***
 * ��ȡ��ǰ���
 * @return ��ǰ���
 */
uint16_t getYear(){
    return Date_Struct.Year + Correct_Year;
}

/***
 * ��ȡ�����
 * @return �����
 */
uint32_t Random(){
    uint32_t *random = NULL;
    HAL_RNG_GenerateRandomNumber(&hrng, random);
    return *random;
}
