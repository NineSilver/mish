#include <stdio.h>
#include <unistd.h>

#include "builtins.h"

void builtin_cd(char** args)
{
    if(chdir(args[1]) == -1)
    {
        perror("cd");
    }
    else
    {
        getcwd(cwd, sizeof(cwd));
    }
}