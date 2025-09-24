#include "memory_arena.h"


void arena_init(Arena* arena, size_t capacity) {
    arena->buffer = (char*)malloc(capacity);
    arena->capacity = capacity;
    arena->offset = 0;
}
void* arena_push(Arena* arena, size_t size){
    return (void*)0;
}
void* arena_pop(Arena* arena, size_t size) {
    return (void*)0;
}
void arena_free(Arena* arena) {

}