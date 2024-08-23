#ifndef H7OS_TIMER_H
#define H7OS_TIMER_H

#include <stdint-gcc.h>


// ����ʱ��, ��Ҫ����ʵ������޸�
#define Correct_Year 2024
#define Correct_Month 8 - 1
#define Correct_Day 14 - 1
#define Correct_Hour 22
#define Correct_Minute 9

/***
 * ��ȡ��ǰ��
 * @return ��ǰ��
 */
uint8_t getSecond();

/***
 * ��ȡ��ǰ����
 * @return ��ǰ����
 */
uint8_t getMinute();

/***
 * ��ȡ��ǰСʱ
 * @return ��ǰСʱ
 */
uint8_t getHour();

/***
 * ��ȡ��ǰ����
 * @return ��ǰ����
 */
uint8_t getDay();

/***
 * ��ȡ��ǰ�·�
 * @return ��ǰ�·�
 */
uint8_t getMonth();

/***
 * ��ȡ��ǰ���
 * @return ��ǰ���
 */
uint16_t getYear();

/***
 * ����ʱ��
 */
void UpdateTime();

/***
 * ��ȡ�����
 * @return �����
 */
uint32_t Random();

#endif //H7OS_TIMER_H
