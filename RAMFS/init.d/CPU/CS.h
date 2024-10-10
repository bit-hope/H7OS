#ifndef H7OS_CS_H
#define H7OS_CS_H

// CS_t��һ���ַ��ṹ�壬���ڱ���ÿ�ε�ָ��. ���磺
// CS_t cs = {"mkdir /tmp", 9};
typedef struct cs {
    // data��ָ����ַ���
    char data[128];
    // next��ָ����һ��CS_t��ָ��
    struct cs *next;
}* CS_t;

#define CS_SIZE sizeof (struct cs)

void CS_push(char *save_str);

void CS_list();

void CS_save();


#endif
