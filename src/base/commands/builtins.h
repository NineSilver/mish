#pragma once

// Current dir
char cwd[256];

// Builtin commands
void builtin_help();
void builtin_cd(char** args);