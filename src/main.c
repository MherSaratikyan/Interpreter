#include "../headers/common.h"
#include "../headers/chunk.h"

int main(int argc, const char* argv[]){
    Chunk chunk;
    chunk_init(&chunk);
    chunk_write(&chunk, OP_RETURN);
    chunk_free(&chunk);
    return 0;
}