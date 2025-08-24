#include <stdio.h>

#include "../headers/dbg_utils.h"

void disassemble_chunk(const Chunk* const chunk, const char* name){
    printf("== %s ==\n", name);

    int offset = 0;
    while(offset < chunk->count){
        offset = disassemble_instruction(chunk, offset);
    }
}

int disassemble_instruction(const Chunk* const chunk, int offset){
    printf("%04d ", offset);
    uint8_t instruction = chunk->code[offset];
    switch(instruction){
        case OP_RETURN:
        return simple_instruction("OP_RETURN", offset);
            break;
        default:
            printf("Unknown opcode %d\n", instruction);
            return offset + 1;
    }
}

int simple_instruction(const char* op_name, int offset){
    printf("%s\n", op_name);
    return offset + 1;
}