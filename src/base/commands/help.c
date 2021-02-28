#include <stdio.h>

#include "../consts.h"
#include "builtins.h"

void builtin_help()
{
    puts(YELLOW "mish shell, version 0.1a" RESET);
    puts("Licensed under GNU GPL 3\n");

    puts("This commands are defined internally:");
    puts("\tcd: changes the actual directory");
    puts("\thelp: shows this information page");
    puts("\texit: exits the shell\n");

    puts("Use the man command for getting help on other programs");
    puts("Developer information:");
    #if defined(__linux__)
        printf("\tplatform: %s-linux-gnu\n", sizeof(void*) == 8 ? "x86_64" : "x86");    
    #else
        #if defined (__WIN32__)
            printf("\tplatform: %s-windows\n", sizeof(void*) == 8 ? "x86_64" : "x86");
        #else
            printf("\tplatform: %s\n", sizeof(void*) == 8 ? "x86_64" : "x86");
        #endif
    #endif
}