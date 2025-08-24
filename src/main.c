#include "../headers/common.h"
#include "../headers/chunk.h"


#ifndef NDEBUG
#include "../headers/dbg_utils.h"
#endif


int main(int argc, const char* argv[]){
    Chunk chunk;
    chunk_init(&chunk);
    chunk_write(&chunk, OP_RETURN);

    #ifndef NDEBUG
    disassemble_chunk(&chunk, "test_chunk");
    #endif

    chunk_free(&chunk);
    return 0;
}