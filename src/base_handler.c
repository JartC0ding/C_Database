#pragma once

#include <stdio.h>
#include "map.c"
#include "utils.c"

BASE* db_startup_new_clear(BASE* base) {
    // Set the array of void* to fixed size
    int tmp_arr[base->LENGTH];

    // set the array of bool pointers to false if occupied
    bool tmp_b_arr[base->LENGTH];

    for (int i = 0; i < base->LENGTH; i++) {
        tmp_b_arr[i] = false;
    }
    
    base->occupied = tmp_b_arr;
    base->storage = (void*) tmp_arr;
    return base;
}
