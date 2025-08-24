#include <stdlib.h>

#include "../headers/chunk.h"

void chunk_init(Chunk* const chunk) {
    value_array_init(&(chunk->constants));
    chunk->capacity = 0;
    chunk->count = 0;
    chunk->code = NULL;

}

void chunk_write(Chunk* const chunk, uint8_t byte) {
    if(chunk->capacity == chunk->count) chunk_reallocate(chunk);

    chunk->code[chunk->count] = byte;
    ++(chunk->count);
}

int chunk_add_num(Chunk* const chunk, value num){
    value_array_write(&(chunk->constants), num);
    return (chunk->constants).count - 1;
}

void chunk_reallocate(Chunk* const chunk) {
    chunk->capacity = 2 * chunk->capacity + 1;
    uint8_t* new_code = (uint8_t*)malloc((chunk->capacity) * sizeof(uint8_t));
    for(int i = 0; i < chunk->count; ++i){
        new_code[i] = chunk->code[i];
    }
    free(chunk->code);
    chunk->code = new_code;
}

void chunk_free(Chunk* const chunk) {
    free(chunk->code);
    chunk->code = NULL;
    chunk->count = 0;
    chunk->capacity = 0;
    value_array_free(&(chunk->constants));
}