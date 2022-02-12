#pragma once

#include <stdio.h>
#include "map.c"

typedef struct {
    unsigned long long int LENGTH;
    char* NAME;
    void* storage;
} BASE;

BASE* db_startup_new_clear(BASE* base) {
    // Set the array of void* to fixed size
    int tmp_arr[base->LENGTH];
    base->storage = (void*) tmp_arr;
    return base;
}
