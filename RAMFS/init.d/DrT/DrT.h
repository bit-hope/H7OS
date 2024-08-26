#ifndef H7OS_DRT_H
#define H7OS_DRT_H

// DrT: Device Tree
#include "u_thread.h"

/****************************************************
 * DrT �豸��
 *      - �豸����һ�����νṹ����������ϵͳ�е�Ӳ���豸��
 *      - �豸����һ��ƽ̨�޹ص�����Ӳ�������ݽṹ��
 *      - �ļ�������DrT�Ĵ����������Լ�ָ���
 * */

enum DeviceType{
    DEVICE_TIMER,   // ��ʱ��
    DEVICE_STORAGE, // �洢�豸(qspi, sd, emmc)
    DEVICE_DISPLAY, // ��ʾ�豸(RGB, LVDS, HDMI)
    DEVICE_INPUT,   // �����豸(OTG)
    DEVICE_SERIAL,  // �����豸(USART, UART, SPI, IIC, CAN, LIN, USB)
    DEVICE_TRANSPORT,   // �����豸(USB, ETH, WIFI)
    DEVICE_VOTAGE,  // ��ѹ�豸(ADC, DAC)
    // --------------------
    FILE_SYSTEM,    // �ļ�ϵͳ
    FILE,           // �ļ�
};

typedef enum DeviceType DeviceType_E;

// �豸״̬
enum DeviceStatus{
    DEVICE_OFF,     // �ر�
    DEVICE_ON,      // ��
    DEVICE_SUSPEND, // ����
    DEVICE_ERROR,   // ����
    DEVICE_BUSY,    // ռ��
};

typedef enum DeviceStatus DeviceStatus_E;
typedef struct FS* FS_t;
typedef struct DrTNode* DrTNode_t;

struct DrTNode{
    // �豸��ַ
    void* device;
    // �豸״̬
    DeviceStatus_E status;
    // �豸����
    DeviceType_E type;
    // �豸����
    char* name;
    // �豸����
    char* description;
    // �豸���ݻ���
    void* data;
    // --------------------
    // �豸����
    Func_t driver;
    // --------------------
    Mutex_t mutex;  // �豸��
    // --------------------
    DrTNode_t next;
    FS_t parent;
};

struct FS{
    // ·��
    char* path;

    // ���豸����
    DrTNode_t node;
    // �豸����
    int node_count;

    // ����
    FS_t parent;
    // �㼶
    FS_t next;
    // �Ӽ�
    FS_t child;
};

static FS_t RAM_FS;

// ��ʼ���豸��(����豸Ŀ¼�����)
void DrTInit();


// ===============================[ָ�����]===============================

typedef void (*Comand_t)(int argc, char **argv);

typedef struct CMD* CMD_t;

struct CMD{
    char* name; // ָ��������mkdir, rm, ls
    char* description;  // ָ������, ����help
    /***
     * @brief ָ���Ҫ��
     * @param argc ��������
     * @param argv �����б�(char**)
     * */
    Comand_t cmd; // ָ��������
    CMD_t next; // ��һ��ָ��
};

static CMD_t CMDList;

// ���ָ��
void addCMD(char* name, char* description, Comand_t cmd);

// ִ��ָ��
void execCMD(char* command);

#define CMD(name, description, cmd) addCMD(name, description, cmd)

// ===============================[�豸����]===============================

/**
 * @brief ����Ŀ¼
 * @param path
 * @param name
 */
void ram_mkdir(char* path, char* name);

/**
 * @brief �����ļ�
 * @param path
 * @param name
 */
void ram_mkfile(char* path, char* name);

/**
 * @brief ɾ��Ŀ¼
 * @param path
 * @param name
 */
void ram_rm(char* path, char *name);

/**
 * @brief ��ȡ�ļ�
 * @param path
 * @param buf
 * @param size
 */
void ram_read(char* path, void* buf, int size);

/**
 * @brief д���ļ�
 * @param path
 * @param buf
 * @param size
 */
void ram_write(char* path, void* buf, int size);

/**
 * @brief ����·��,����Ŀ¼
 * @param path
 * @return
 */
FS_t loadPath(char* path);

#endif
