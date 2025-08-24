#ifndef CLOX_CHUNK_H
#define CLOX_CHUNK_H

#include "./common.h"
#include "./value_array.h"

typedef enum {
    OP_CONSTANT,
    OP_RETURN,
} OP_CODE;

typedef struct {
    int count;
    int capacity;
    uint8_t* code;
    ValueArray constants;
} Chunk;

void chunk_init(Chunk* const chunk);
void chunk_write(Chunk* const chunk, uint8_t byte);
int chunk_add_num(Chunk* const chunk, value num);
void chunk_reallocate(Chunk* const chunk);
void chunk_free(Chunk* const chunk);

#endif