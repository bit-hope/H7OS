#include "DrT.h"
#include "stm32h7xx_hal.h"
#include "memctl.h"
#include "usart.h"
#include "u_stdio.h"

void addFSChild(FS_t parent, char *path){
    // �����ӽڵ�
    FS_t child = (FS_t) ram_alloc(sizeof(struct FS));
    child->path = (char*) ram_alloc(strlen(path) + 1);
    strcopy(child->path, path);

    child->node = (DrTNode_t) ram_alloc(sizeof(struct DrTNode));
    child->node_count = 0;
    child->parent = parent;
    child->next = NULL;
    child->Level = NULL;

    // ��ӵ����ڵ�ͬ���б�
    FS_t p = parent;
    while(p->Level != NULL) p = p->Level;
    p->Level = child;
}

FS_t getFSChild(FS_t parent, char *path){
    FS_t p = parent->Level;
    while(p != NULL){
        if(strcmp(p->path, path) == 0) return p;
        p = p->next;
    }
    return NULL;
}


// ����豸
/**
 * @brief ����豸
 * @param node �豸�ڵ�
 * @param devicePtr �豸ָ��(htim, huart, hspi)
 * @param name �豸����(��TIM1, USART1, SPI1)
 * @param description �豸����(�綨ʱ��1, ����1, SPI1)
 * @param type �豸����(��ͨ���豸��ʱ���豸)
 * @param driver �豸����(һ������ָ��)
 */
void addDevice(char *path, void* devicePtr, char *name, char *description, DeviceType_E type,
               DeviceStatus_E status, Func_t driver){
    FS_t node = getFSChild(RAM_FS, path);
    if (node == NULL) return;
    // �����豸�ڵ�
    DrTNode_t device = (DrTNode_t) ram_alloc(sizeof(struct DrTNode));
    device->name = (char*) ram_alloc(strlen(name) + 1);
    device->description = (char*) ram_alloc(strlen(description) + 1);

    strcopy(device->name, name);
    strcopy(device->description, description);

    device->device = devicePtr;
    device->status = status;
    device->type = type;
    device->data = ram_alloc(128);
    device->driver = driver;
    Mutex_t mutex = (Mutex_t) ram_alloc(MUTEX_SIZE);
    mutex_init(mutex);
    device->mutex = mutex;
    device->parent = node;
    device->next = NULL;

    // ��ӵ��豸����
    DrTNode_t p = node->node;
    while(p->next != NULL) p = p->next;
    p->next = device;
    node->node_count++;
}

void DrTInit(){
    RAM_FS = (FS_t) ram_alloc(sizeof(struct FS));
    RAM_FS->path = "/";

    RAM_FS->node = NULL;
    RAM_FS->node_count = 0;

    RAM_FS->parent = NULL;
    RAM_FS->next = NULL;
    RAM_FS->Level = NULL;

    // �����·��
    // TODO ��ô��Ӷ���ROOT��ͬ��·�����ˣ�Ӧ������ROOT�µ���·��
    addFSChild(RAM_FS, "dev");
    addFSChild(RAM_FS, "tmp");
    addFSChild(RAM_FS, "mnt");
    addFSChild(RAM_FS, "bin");
    addFSChild(RAM_FS, "usr");
    addFSChild(RAM_FS, "root");
    addFSChild(RAM_FS, "opt");

    addDevice("dev", &huart1, "USART1", "Serial uart", DEVICE_SERIAL, DEVICE_BUSY, NULL);
}

FS_t temp_node;

void displayDevice(){
    FS_t node = RAM_FS;
    while (node->Level != NULL){
        u_print("path: %s \n",node->path);
        node = node->Level;
    }
}