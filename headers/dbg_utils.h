#ifndef CLOX_DEBUG_UTILS_H
#define CLOX_DEBUG_UTILS_H

#include "./chunk.h"

void disassemble_chunk(const Chunk* const chunk, const char* name);
int disassemble_instruction(const Chunk* const chunk, int offset);
int simple_instruction(const char* op_name, int offset);

#endif