#include <stdio.h>
#include "RAMFS.h"
#include "usbd_cdc_if.h"
#include "usart.h"

#define ShowTab(level) for (int time_tick_temp = 0; time_tick_temp < level; time_tick_temp++) USB_printf(TAB);

#define DFS_color_printf(token, color, format, ...){         \
                        USB_printf(token);                  \
                        USB_printf(color);                  \
                        USB_printf(format, ##__VA_ARGS__);  \
                        USB_printf(NONE);}

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
        if (i == node->node_count - 1) DFS_color_printf(END_SIGNAL, LIGHT_BLUE, "%s\n", device->name)
        else DFS_color_printf(T_SIGNAL, LIGHT_BLUE, "%s\n", device->name)
        device = device->next;
    }

    // 2. ��ӡ��ǰ�ڵ��µ������б�
    Task_t task = node->tasklist;
    while (task != NULL){
        ShowTab(level);
        if (task->next == NULL)DFS_color_printf(END_SIGNAL, LIGHT_PURPLE, "%s\n", task->name)
        else DFS_color_printf(T_SIGNAL, LIGHT_PURPLE, "%s\n", task->name)
        task = task->next;
    }

    // ����FS_t�ض����
    // �ݹ�����ӽڵ�
    if (level <= depth){
        FS_t child_tmp = node->child_next;
        while (child_tmp != NULL){
            ShowTab(level);
            if (child_tmp->level_next == NULL) DFS_color_printf(END_SIGNAL, LIGHT_GREEN, "%s\n", child_tmp->path)
            else DFS_color_printf(T_SIGNAL, LIGHT_GREEN, "%s\n", child_tmp->path)


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
