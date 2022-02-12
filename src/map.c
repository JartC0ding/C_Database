#pragma once

#include "utils.c"
#include <stdbool.h>
#include "hash/hash.c"

/* 
Defines a generic function.
DELETE_arr is called if a char* array is passed.
DELETE_no_arr is called if called with char* 
*/
#define DELETE(X) _Generic ((X), \
        char**: DELETE_arr, \
        char*: DELETE_no_arr \
        ) (X)

/*
returns the data of the data at a key location.
*/
void* MAP_GET(char* key) {

}

/*
Adds data (void* data) with a key to the map
Returns: true on success
         false on Allready exists
*/
bool MAP_ADD(char* key, void* data, BASE* base) {
	int idx = hash(key, base->LENGTH);
	
	// check if occupied
	if (base->occupied[idx] == true) {
		return false;
	}

	// cast the data to int temporarly
	int* d = (int*) data;
	// casts all the data to ints to change values in it
	int** a = (int*) base->storage;
	// set data
	a[idx] = d;
	
	// cast back to void*
	base->storage = (void*) a;
	base->occupied[idx] = true;
	return true;
}

/*
Updates the data in the map with a given key.
Returns: true on success
         false on failure
*/
bool UPDATE(char* key, void* data) {

}

/*
Delets with key and returns a copy of the deleted element
*/
void* DELETE_no_arr(char* key) {

}

/*
Delets with keys and returns copys of the deleted elements
*/
void* DELETE_arr(char* key) {

}
