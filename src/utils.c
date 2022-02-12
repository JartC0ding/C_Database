#pragma once

#include <stdio.h>
#include <stdbool.h>

typedef struct {
    unsigned long long int LENGTH;
    char* NAME;
    void* storage;
    bool* occupied;
} BASE;

void LOG(char* string, bool NO_LOG) {
    if (NO_LOG != true) {
        printf("%s\n", string);
    } else {
        return;
    }
}
