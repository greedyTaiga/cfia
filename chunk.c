#include <stdlib.h>

#include "chunk.h"
#include "memory.h"

void initChunk(Chunk* chunk) {
	chunk -> count = 0;
	chunk -> capacity = 0;
	chunk -> code = NULL;
}

void freeChunk(Chunk* chunk) {
	FREE_ARRAY(uint8_t, chunk -> code, chunk -> capacity);
	initChunk(chunk);
}

void writeChunk(Chunk* chunk, uint8_t byte) {
	if (chunk -> count + 1 > chunk -> capacity) {
		int prevCapacity = chunk -> capacity;
		chunk -> capacity = GROW_CAPACITY(prevCapacity);
		chunk -> code = GROW_ARRAY(uint8_t, chunk -> code,
			prevCapacity, chunk -> capacity);
	}
	chunk -> code[chunk -> count] = byte;
	chunk -> count ++; 
}
