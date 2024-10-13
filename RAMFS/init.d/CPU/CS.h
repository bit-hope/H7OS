#ifndef H7OS_CS_H
#define H7OS_CS_H

#define QSPI_Page_HaveCS 0xbb
#define QSPI_Page_None 0x00

// CS_t��һ���ַ��ṹ�壬���ڱ���ÿ�ε�ָ��. ���磺
// CS_t cs = {"mkdir /tmp", 9};
typedef struct cs {
    // data��ָ����ַ���
    // ����128�����ɺܼ򵥣�����1λ����־
    char data[126]; // 126 + 1 = 127 (1λ��\0)
    // next��ָ����һ��CS_t��ָ��
    struct cs *next;
}* CS_t;

#define CS_SIZE sizeof (struct cs)

void CS_push(char *save_str);

void CS_clean();

void CS_list();

void CS_save();

void CS_load();


#endif