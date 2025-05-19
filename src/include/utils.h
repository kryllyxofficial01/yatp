#ifndef __YATP_UTILS_H
#define __YATP_UTILS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define YATP_CAPACITY(n, t) (n * sizeof(t))

char* load_file(const char* filepath);

#ifdef _WIN32
    size_t getline(char** line, size_t* capacity, FILE* file_stream);
#endif

#endif