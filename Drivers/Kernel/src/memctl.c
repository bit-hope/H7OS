#include "memctl.h"
#include "quadspi.h"
#include "tlsf.h"

/***
 * @brief �ڴ濽��
 * @param dest: destination address
 * @param src: source address
 * @param size: size of the memory block
 * */
void memoryCopy(void *dest, void *src, int size){
    char *d = (char *)dest;
    char *s = (char *)src;
    for(int i = 0; i < size; i++) d[i] = s[i];
}

/***
 * @brief �ڴ�����
 * @param dest: destination address
 * @param val: value to set
 * @param size: size of the memory block
 * */
void memorySet(void *dest, char val, int size){
    char *d = (char *)dest;
    for(int i = 0; i < size; i++) d[i] = val;
}

/***
 * @brief �ڴ�Ƚ�
 * @param dest: destination address
 * @param src: source address
 * @param size: size of the memory block
 * @return �ȽϽ��
 * */
int memoryCompare(void *dest, void *src, int size){
    char *d = (char *)dest;
    char *s = (char *)src;
    for(int i = 0; i < size; i++) if(d[i] != s[i]) return 0;
    return 1;
}

/***
 * @brief QSPI flashд������
 * @param addr: д���ַ(��0x0000��ʼ��0x0400)
 * @param data: д������
 * @param size: д�����ݴ�С
 * */
void flashWrite(uint32_t addr, uint8_t *data, uint32_t size){
    QSPI_W25Qxx_WriteBuffer(data, addr, size);
}

/***
 * @brief QSPI flash��ȡ����
 * @param addr: ��ȡ��ַ
 * @param data: ��ȡ���ݴ�ŵ�ַ
 * @param size: ��ȡ���ݴ�С
 * */
void flashRead(uint32_t addr, uint8_t *data, uint32_t size){
    QSPI_W25Qxx_ReadBuffer(data, addr, size);
}

// ========================= ������SDRAM�ڴ�����㷨 =========================
/***
 * @brief ˢ��SDRAM
 * */
void flashSDRAM(){
    for (uint32_t i = 0; i < SDRAM_Size; i++) IO_U8 (SDRAM_BANK_ADDR+i) = 0;
}

// �ڴ��
tlsf_t mem_pool;
tlsf_t kernel_pool;
// ʹ���ڴ�
uint32_t using_mem = 0;

/***
 * @brief SDRAM�ڴ�����ʼ��
 * @note �ú������ʼ��SDRAM�ڴ�����㷨, ����ʹ��SDRAM�ڴ����ǰ���øú���.
 * */
void MemControl_Init(){
    flashSDRAM();
    // �ں˿ռ�(���Զ�������QSPI Flash��)
    kernel_pool = tlsf_create_with_pool((void*)SDRAM_BANK_ADDR, 2 * 1024 * 1024);
    // �������пռ�
    mem_pool = tlsf_create_with_pool((void*)SDRAM_BANK_ADDR + 2 * 1024 * 1024, 30 * 1024 * 1024);
}

/***
 * @brief SDRAM�ڴ�������
 * @param size: �����ڴ��С
 * @return �����ڴ�ĵ�ַ
 * */
void* ram_alloc(uint32_t size){
    using_mem += size;
    return tlsf_malloc(mem_pool, size);
}

/***
 * @brief SDRAM�ڴ�������·���
 * @param addr: ���·����ڴ�ĵ�ַ
 * @param size: ���·����ڴ��С
 * @return ���·����ڴ�ĵ�ַ
 * */
void* ram_realloc(void* addr, uint32_t size){
    return tlsf_realloc(mem_pool, addr, size);
}

/***
 * @brief SDRAM�ڴ�����ͷ�
 * @param addr: �ͷ��ڴ�ĵ�ַ
 * */
void ram_free(void* addr){
    using_mem -= tlsf_block_size(addr);
    tlsf_free(mem_pool, addr);
}

/***
 * @brief SDRAM�ڴ������
 * @return �����
 * */
int ram_check(){
    return tlsf_check(mem_pool);
}

/***
 * @brief SDRAM�ڴ������Ϣ
 * */
void ram_info(){
    if (using_mem < 1024) u_print("Using memory: %d bytes\n", using_mem);
    else if (using_mem < 1024*1024) u_print("Using memory: %d KB\n", using_mem/1024);
    else u_print("Using memory: %d MB\n", using_mem/1024/1024);
}

/***
 * @brief SDRAM�ڴ��������
 * @note �ú���������SDRAM�ڴ�����㷨, ���ڲ�ʹ��SDRAM�ڴ�������øú���.
 * */
void ram_destroy(){
    tlsf_destroy(mem_pool);
}

/***
 * @brief SDRAM�ڴ�������
 * @param align: �����С
 * @param bytes: �����ֽ���
 * */
void ram_align(size_t align, size_t bytes){
    tlsf_memalign(mem_pool, align, bytes);
}

void* kernel_alloc(uint32_t size){
    return tlsf_malloc(kernel_pool, size);
}

void* kernel_realloc(void* addr, uint32_t size){
    return tlsf_realloc(kernel_pool, addr, size);
}

void kernel_free(void* addr){
    tlsf_free(kernel_pool, addr);
}
