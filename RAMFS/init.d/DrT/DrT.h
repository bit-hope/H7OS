#ifndef H7OS_DRT_H
#define H7OS_DRT_H

// DrT: Device Tree
#include "u_thread.h"
#include "Register.h"
#include "xTaskManager.h"

/****************************************************
 * DrT �豸��
 *      - �豸����һ�����νṹ����������ϵͳ�е�Ӳ���豸��
 *      - �豸����һ��ƽ̨�޹ص�����Ӳ�������ݽṹ��
 *      - �ļ�������DrT�Ĵ����������Լ�ָ���
 * */

enum DeviceType{
    DEVICE_TIMER,   // ��ʱ��
    DEVICE_BS,      // ���豸
    DEVICE_STORAGE, // �洢�豸(qspi, sd, emmc)
    DEVICE_DISPLAY, // ��ʾ�豸(RGB, LVDS, HDMI)
    DEVICE_INPUT,   // �����豸(OTG)
    DEVICE_SERIAL,  // �����豸(USART, UART, SPI, IIC, CAN, LIN, USB)
    DEVICE_TRANSPORT,   // �����豸(USB, ETH, WIFI)
    DEVICE_VOTAGE,  // ��ѹ�豸(ADC, DAC)
    DEVICE_TASK,    // �����豸(proc��ʾ������)
    // --------------------
    FILE_SYSTEM,    // �ļ�ϵͳ
    DrTFILE,           // �ļ�
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
    // --------------------
    // procĿ¼����Ŀ
    Task_t tasklist;

    // ����
    FS_t parent;
    // �㼶
    FS_t next;
    // �Ӽ�
    FS_t child;
};

// ���ļ�ϵͳ
static FS_t RAM_FS;

// ��ʼ���豸��(����豸Ŀ¼�����)
void DrTInit();

// �ж�kernel��ramfs�Ƿ����
void checkDrT();
// �����豸��
void saveDrT();


// ===============================[ָ�����]===============================

typedef void (*Comand_t)(int argc, char **argv);

typedef struct CMD* CMD_t;

struct CMD{
    char* name; // ָ��������mkdir, rm, ls
    char* description;  // ָ������, ����help
    char* usage;    // ָ��ʹ�÷���
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
void addCMD(char* name, char* description, char* usage, Comand_t cmd);

// ִ��ָ��
void execCMD(char* command);

void helpCMD(char *cmd);

#define CMD(name, description, usage, cmd) addCMD(name, description, usage, cmd)

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
 * @brief ��ʾĿ¼
 * @param path
 */
void ram_ls(char* path);

/**
 * @brief �л�Ŀ¼
 * @param path
 */
FS_t ram_cd(char* path);

/**
 * @brief ��ʾ��ǰĿ¼
 * @param fs ��ǰ�ļ���
 * @param path ·��(�Ѿ�ram_alloc)
 */
void ram_pwd(FS_t fs, char* path);

/**
 * @brief ����·��,����Ŀ¼
 * @param path
 * @return
 */
FS_t loadPath(char* path);

/**
 * @brief �����豸
 * @param path
 * @return
 */
DrTNode_t loadDevice(char* path);

// ===============================[�������]===============================

/**
 * @brief ����������Ϣ
 * @param path
 * @return
 */
Task_t loadTask(char* path);

/**
 * @brief ����豸
 * @param task ����ṹ��
 * */
void addThread(Task_t task);

/**
 * @brief ʹ���߳�����ȡ�߳̽ṹ��
 * @param name �߳���
 * */
Task_t getThread(char* name);

/**
 * @brief ʹ���߳�PID��ȡ�߳̽ṹ��
 * @param pid �߳�id
 * */
Task_t getThreadByPID(uint8_t pid);

/**
 * @brief ��ȡ�����б�
 * */
Task_t getTaskList();

/**
 * @brief ��ȡ����
 * @param handle ������
 * */
Task_t getTaskByHandle(osThreadId handle);

#endif
