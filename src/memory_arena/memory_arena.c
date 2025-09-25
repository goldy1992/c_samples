#include "memory_arena.h"
#include <stdlib.h>


void arena_init(Arena* arena, size_t capacity) {
    arena->buffer = (char*)malloc(capacity * sizeof(char));
    arena->capacity = capacity;
    arena->offset = 0;
}
void* arena_push(Arena* arena, size_t size){
    void* toReturn = (void*)((char*)arena->buffer + arena->offset);
    arena->offset += size;
    return toReturn;
}
void* arena_pop(Arena* arena, size_t size) {
    void* toReturn = (void*)((char*)arena->offset - size);
    arena->offset -= size;
    return toReturn;
}
void arena_free(Arena* arena) {

    free(arena->buffer);
    arena->buffer = NULL;
    arena->capacity = 0;
    arena->offset = 0;
}