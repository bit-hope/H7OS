#include <stdio.h>
#include "RAMFS.h"
#include "usbd_cdc_if.h"

#define ShowTab(level) for (int time_tick_temp = 0; time_tick_temp < level; time_tick_temp++) USB_printf(TAB);

/***
 * @brief �ݹ�����ļ�ϵͳ
 * @param node �ļ�ϵͳ�ڵ�
 * @param level ��ǰ�ڵ����
 * @param depth ��Ҫ�������
 * */
void dfs(FS_t node, int level, int depth){
    // �ݹ�����ļ�ϵͳ

    // 1. ��ӡ��ǰ�ڵ��µ��豸
    DrTNode_t device = node->node;
    for (int i = 0;i < node->node_count; i++){
        ShowTab(level);
        if (i == node->node_count - 1) USB_printf("%s%s\n", END_SIGNAL, device->name);
        else USB_printf("%s%s\n", T_SIGNAL, device->name);
        device = device->next;
    }

    // 2. ��ӡ��ǰ�ڵ��µ������б�
    Task_t task = node->tasklist;
    while (task != NULL){
        ShowTab(level);
        if (task->next == NULL) {
            USB_printf("%s%s\n", END_SIGNAL, task->name);
            break;
        } else USB_printf("%s%s\n", T_SIGNAL, task->name);
        task = task->next;
    }

    // ����FS_t�ض����
    // �ݹ�����ӽڵ�
    if (level <= depth){
        FS_t child_tmp = node->child_next;
        while (child_tmp != NULL){
            ShowTab(level);
            if (child_tmp->level_next == NULL) USB_printf("%s%s\n", END_SIGNAL, child_tmp->path);
            else USB_printf("%s%s\n", T_SIGNAL, child_tmp->path);

            dfs(child_tmp, level + 1, depth);
            child_tmp = child_tmp->level_next;
        }
    }
}

/***
 * @brief ������������㷨
 * @param node �ļ�ϵͳ�ڵ�
 * @param depth ��Ҫ�������
 * */
void DFS(FS_t node, int depth){
    dfs(node, 0, depth);
}
