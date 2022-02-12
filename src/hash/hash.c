#pragma once

#include <string.h>

// literally any hashing algorithm

int hash(char* key) {
    int index = 0;
    for (int i = 0; i < strlen(key); i++) {
        index += key[i];
        index += key[i] * i + index;
    }
    return index;
}
