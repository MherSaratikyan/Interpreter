#ifndef CLOX_CHUNK_H
#define CLOX_CHUNK_H

#include "./common.h"

typedef enum {
    OP_RETURN,
} OP_CODE;

typedef struct {
    int count;
    int capacity;
    uint8_t* code;
} Chunk;

void chunk_init(Chunk* chunk);
void chunk_write(Chunk* chunk, uint8_t byte);
void chunk_reallocate(Chunk* chunk);
void chunk_free(Chunk* chunk);

#endif