#include <stdlib.h>

#include "../headers/chunk.h"

void chunk_init(Chunk* chunk) {
    chunk->capacity = 0;
    chunk->count = 0;
    chunk->code = NULL;
}

void chunk_write(Chunk* chunk, uint8_t byte) {
    if(chunk->capacity == chunk->count) chunk_reallocate(chunk);

    chunk->code[chunk->count] = byte;
    ++chunk->count;
}

void chunk_reallocate(Chunk* chunk) {
    chunk->capacity = 2 * chunk->capacity + 1;
    uint8_t* new_code = malloc(chunk->capacity * sizeof(uint8_t));
    for(int i = 0; i < chunk->count; ++i){
        new_code[i] = chunk->code[i];
    }
    free(chunk->code);
    chunk->code = new_code;
}

void chunk_free(Chunk* chunk) {
    free(chunk->code);
    chunk->code = NULL;
    chunk->count = 0;
    chunk->capacity = 0;
}