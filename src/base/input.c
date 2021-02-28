#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "commands/builtins.h"
#include "consts.h"
#include "input.h"
#include "session.h"

// Prompt for a line
void prompt(const char* prompt)
{
    if(is_logged)
        printf(GREEN "%s@%s:" BLUE "%s ", user, hostname, cwd);
    else
        printf(BLUE "%s ", cwd);
    
    printf(MAGENTA "%s" RESET, prompt);

    fgets(line, 4096, stdin);
    
    if(feof(stdin))
    {
        puts("exit");
        exit(EXIT_SUCCESS);
    }
}

// Split the line into tokens
char** tokenize()
{
    char* token;
    char** tokens = malloc(toksize * sizeof(char*));
    int pos = 0;

    token = strtok(line, "\a\n\r\t ");
    while(token != NULL)
    {
        tokens[pos] = token;
        pos++;
        
        if(pos >= toksize)
        {
            toksize += toksize;
            tokens = realloc(tokens, toksize * sizeof(char*));
            
            if(!tokens)
            {
                puts("mish: ran out of memory");
                exit(EXIT_FAILURE);
            }
        }
        
        token = strtok(NULL, "\a\n\r\t ");
    }
     
    free(token);
    return tokens;
}