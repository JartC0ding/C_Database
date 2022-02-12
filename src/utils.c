#pragma once

#include <stdio.h>
#include <stdbool.h>

void LOG(char* string, bool NO_LOG) {
    if (NO_LOG != true) {
        printf("%s\n", string);
    } else {
        return;
    }
}
