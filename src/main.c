// Include necessary headers
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

// In-shell commands
#include "base/commands/builtins.h"
#include "base/exec.h"
#include "base/input.h"
#include "base/session.h"

// Main shell loop: get user input, parse it and execute it
void shell_loop()
{
    int status;

    do {
        prompt(prompt_char);
        char **tokens = tokenize();
        status = exec(tokens);
    } while(status);
}

// Entry point: check if it is a login shell and do the set-up
int main(int argc, char** argv)
{
    if(argc >= 2)
    {
        if(!strcmp(argv[1], "--login"))
        {
            logged_session();
        }
    }
    else
    {
        non_logged_session();
    }

    shell_loop();
    return 0;
}