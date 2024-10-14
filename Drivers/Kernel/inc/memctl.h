#ifndef H7OS_MEMCTL_H
#define H7OS_MEMCTL_H

#include "fmc.h"

#define LOGGER printf

// �����ڴ�����㷨
/***
 * @brief �ڴ濽��
 * @param dest: destination address
 * @param src: source address
 * @param size: size of the memory block
 * */
void memoryCopy(void *dest, void *src, int size);

/***
 * @brief �ڴ�����
 * @param dest: destination address
 * @param val: value to set
 * @param size: size of the memory block
 * */
void memorySet(void *dest, char val, int size);

/***
 * @brief �ڴ�Ƚ�
 * @param dest: destination address
 * @param src: source address
 * @param size: size of the memory block
 * @return �ȽϽ��
 * */
int memoryCompare(void *dest, void *src, int size);


// ========================= ������QSPI Flash�ڴ�����㷨 =========================
/***
 * @brief QSPI flashд������
 * @param addr: д���ַ(��0x0000��ʼ��0x0400)
 * @param data: д������
 * @param size: д�����ݴ�С
 * */
void flashWrite(uint32_t addr, uint8_t *data, uint32_t size);

/***
 * @brief QSPI flash��ȡ����
 * @param addr: ��ȡ��ַ
 * @param data: ��ȡ���ݴ�ŵ�ַ
 * @param size: ��ȡ���ݴ�С
 * */
void flashRead(uint32_t addr, uint8_t *data, uint32_t size);

// ========================= ������SDRAM�ڴ�����㷨 =========================

// ����IO����
#define IO_U8 *(__IO uint8_t*)  // ����IO_U8Ϊһ��ָ��uint8_t��ָ��
#define IO_U16 *(__IO uint16_t*)    // ����IO_U16Ϊһ��ָ��uint16_t��ָ��
#define IO_U32 *(__IO uint32_t*)    // ����IO_U32Ϊһ��ָ��uint32_t��ָ��
#define IO_U64 *(__IO uint64_t*)    // ����IO_U64Ϊһ��ָ��uint64_t��ָ��
#define IO_VOID *(__IO void*)    // ����IO_VOIDΪһ��ָ��void��ָ��
#define IO_STRUCT(Pointer) *(__IO Pointer)  // ����IO_STRUCTΪһ��ָ��ṹ�������ָ��
// ����IO��������
#define VideoMemSize 8 * 1024 * 1024  // �Դ��С8MB
#define KernelMemSize 12 * 1024 * 1024  // �ں��ڴ�12MB
#define UserMemSize 12 * 1024 * 1024   // SDRAM�ڴ�12MB

/***
 * @brief SDRAM�ڴ�����ʼ��
 * @note �ú������ʼ��SDRAM�ڴ�����㷨, ����ʹ��SDRAM�ڴ����ǰ���øú���.
 * */
void MemControl_Init();

/***
 * @brief SDRAM�ڴ�������
 * @param size: �����ڴ��С
 * @return �����ڴ�ĵ�ַ
 * */
void* ram_alloc(uint32_t size);


/***
 * @brief �ں��ڴ�������
 * @param size: �����ڴ��С
 * @return �����ڴ�ĵ�ַ
 * */
void* kernel_alloc(uint32_t size);


/***
 * @brief SDRAM�ڴ�������·���
 * @param addr: ���·����ڴ�ĵ�ַ
 * @param size: ���·����ڴ��С
 * @return ���·����ڴ�ĵ�ַ
 * */
void* ram_realloc(void* addr, uint32_t size);

/***
 * @brief �ں��ڴ�������·���
 * @param addr: ���·����ڴ�ĵ�ַ
 * @param size: ���·����ڴ��С
 * @return ���·����ڴ�ĵ�ַ
 * */
void* kernel_realloc(void* addr, uint32_t size);

/***
 * @brief SDRAM�ڴ�����ͷ�
 * @param addr: �ͷ��ڴ�ĵ�ַ
 * */
void ram_free(void* addr);

/***
 * @brief ram�ڴ�鿴
 * */
int ram_check();

/***
 * @brief �ں��ڴ�����ͷ�
 * @param addr: �ͷ��ڴ�ĵ�ַ
 * */
void kernel_free(void* addr);

/***
 * @brief SDRAM�ڴ������Ϣ
 * */
void ram_info();

/***
 * @brief SDRAM�ڴ��������
 * @note �ú���������SDRAM�ڴ�����㷨, ���ڲ�ʹ��SDRAM�ڴ�������øú���.
 * */
void ram_destroy();

/***
 * @brief SDRAM�ڴ�������
 * @param align: �����С
 * @param bytes: �����ֽ���
 * */
void ram_align(size_t align, size_t bytes);


#endif
