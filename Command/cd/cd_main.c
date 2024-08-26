#include <stddef.h>
#include "cd_main.h"
#include "RAMFS.h"
#include "u_stdio.h"

extern FS_t currentFS;

void cd_main(int argc, char **argv){
    if(argc == 1){
        FS_t temp = ram_cd(argv[0]);
        if (temp == NULL)
            u_print("cd: no such directory\r\n");
        else currentFS = temp;
    }else if (argc > 1){
        u_print("cd: too many arguments\r\n");
    }
}