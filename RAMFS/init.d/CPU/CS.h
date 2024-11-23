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

// ָ����С
#define CS_SIZE sizeof (struct cs)
// NULL�ķ���
#define Normal ((void *)1)

// ���ָ���
void CS_push(char *save_str);

// ��ձ���
void CS_clean();

// ���չʾ
void CS_list();

// ����
void CS_save();

// ����
void CS_load();

// ִ��
void CS_Run();

#endif
