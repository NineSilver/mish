#pragma once

static const char* prompt_char = "➜  ";
char line[4096];
static int toksize = 64;

void prompt(const char* prompt);
char** tokenize();