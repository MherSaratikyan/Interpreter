#ifndef CLOX_VALUE_ARRAY_H
#define CLOX_VALUE_ARRAY_H

#include "./common.h"

typedef double value;

typedef struct {
    int count;
    int capacity;
    value* values;
} ValueArray;


void value_array_init(ValueArray* const arr);
void value_array_write(ValueArray* const arr, value num);
void value_array_reallocate(ValueArray* const arr);
void value_array_free(ValueArray* const arr);

#endif