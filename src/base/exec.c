#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#include "commands/builtins.h"
#include "exec.h"

// Get input and execute the command
int exec(char** args)
{
    if(args[0])
    {
        if(!strcmp(args[0],"cd"))
        {
            builtin_cd(args);
        }
        else if(!strcmp(args[0], "exit"))
        {
            exit(EXIT_SUCCESS);
        } 
        else if(!strcmp(args[0], "help"))
        {
            builtin_help();
        }
        else
        {
            return exec_by_environment(args);
        }
    }

    return -1;
}

// Execute a local binary placed into your PATH variable
int exec_by_environment(char** args)
{
    pid_t pid, wpid;
    int status;

    pid = fork();
    if(pid == 0)
    {
        if(execvp(args[0], args) == -1)
        {
            perror("mish");
        }
        exit(EXIT_FAILURE);
    }
    else if(pid < 0)
    {
        perror("mish");
    }
    else
    {
        do {
            wpid = waitpid(pid, &status, WUNTRACED);
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    }

    return 1;
}