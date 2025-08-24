#include <stdlib.h>

#include "../headers/value_array.h"

void value_array_init(ValueArray* const arr){
    arr->capacity = 0;
    arr->count = 0;
    arr->values = NULL;
}

void value_array_write(ValueArray* const arr, value num){
    if (arr->capacity == arr->count) value_array_reallocate(arr);

    arr->values[arr->count] = num;
    ++(arr->count);
}

void value_array_reallocate(ValueArray* const arr){
    arr->capacity = 2 * arr->capacity + 1;
    value* new_arr = (value*)malloc(sizeof(value) * (arr->capacity));
    for(int i = 0; i < arr->count; ++i) {
        new_arr[i] = arr->values[i];
    }
    free(arr->values);
    arr->values = new_arr;
}

void value_array_free(ValueArray* const arr){
    arr->capacity = 0;
    arr->count = 0;
    free(arr->values);
    arr->values = NULL;
}