#pragma once

struct Arena
{
    void* buffer;
    size_t capacity;
    size_t offset;
};

typedef struct Arena Arena;

void arena_init(Arena* arena, size_t capacity);
void* arena_push(Arena* arena, size_t size);
void* arena_pop(Arena* arena, size_t size);
void arena_free(Arena* arena);