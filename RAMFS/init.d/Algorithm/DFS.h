#ifndef H7OS_DFS_H
#define H7OS_DFS_H

// ������ű��
#define SPACE " "
#define TAB "  "
#define T_SIGNAL "|-"
#define END_SIGNAL "`-"

// ������������㷨
/***
 * @brief �ݹ�����ļ�ϵͳ
 * @param node �ļ�ϵͳ�ڵ�
 * @param level ��ǰ�ڵ����
 * @param depth ��Ҫ�������
 * */
void dfs(FS_t node, int level, int depth);

/***
 * @brief ������������㷨
 * @param node �ļ�ϵͳ�ڵ�
 * @param depth ��Ҫ�������
 * */
void DFS(FS_t node, int depth);

#endif