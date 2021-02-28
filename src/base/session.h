#pragma once

#include <limits.h>
#include <stdbool.h>

const char* homedir;
char hostname[HOST_NAME_MAX + 1];
const char* user;

bool is_logged;

void logged_session();
void non_logged_session();