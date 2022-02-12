//#pragma once
#include "src/hash/hash.c"
#include "src/base_handler.c"
#include "src/utils.c"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*
Initializes a database with a given length and returns it.
That includes:
    - Creating a store file (for data and config data like length and name)
    - And create the database hash map
*/
BASE* INIT_DATA_BASE(unsigned long long int base_length, char* name, bool NO_LOG) {
    LOG("LOG::Allocating Database", NO_LOG);
    BASE* base = (BASE*) malloc(sizeof(BASE));
    
    LOG("LOG::Allocated succesfully", NO_LOG);
    LOG("LOG::Setting Database", NO_LOG);

    LOG("LOG::Setting Length and Name", NO_LOG);
    base->LENGTH = base_length;
    base->NAME = name;
    LOG("LOG::Set Length and name", NO_LOG);

    base = db_startup_new_clear(base);

    LOG("LOG::Sucessfully created a database", NO_LOG);
    LOG("LOG::Now creating store file", NO_LOG);

    // create store file
    FILE* fptr;
    fptr = fopen("store.db", "w");

    if (fptr == NULL) {
        printf("Unable to create store file!\n");
        exit(EXIT_FAILURE);
    }

    fprintf(fptr, "NAME=%s\nLENGTH=%llu\n", base->NAME, base->LENGTH);
    fclose(fptr);

    LOG("Created store file", NO_LOG);
    LOG("LOG::Done\n", NO_LOG);

    return base;
}

/*
Start a allready existing database with a given name,
that is used to find the config.
*/
bool START_DATA_BASE(char* name) {
    return true;
}

int main() {
    BASE* my_base = INIT_DATA_BASE(50, "TestBase", false);
}
