#ifndef H7OS_PRELOAD_H
#define H7OS_PRELOAD_H

#include "RAMFS.h"

// �û��ڴ�ռ����
#define user_malloc(size) ram_alloc(size)
#define user_free(ptr) ram_free(ptr)



#endif
