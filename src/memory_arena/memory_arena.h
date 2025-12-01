#pragma once
#include <stddef.h>

#define Kilobytes(Value) ((Value)*1024LL)
#define Megabytes(Value) (Kilobytes(Value)*1024LL)
#define Gigabytes(Value) (Megabytes(Value)*1024LL)
#define Terabytes(Value) (Gigabytes(Value)*1024LL)

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

// convenience macro for getting some memory from the arena
#define ALLOC(allocator, type) (type*) arenaPush(allocator, sizeof(type))
#define FREE(allocator, type) (type*) arenaPop(allocator, sizeof(type))
#define ALLOC_N(n, allocator, type) (type*) arenaPush(allocator, n * sizeof(type))
#define FREE_N(n, allocator, type) (type*) arenaPop(allocator, n * sizeof(type))
// #define ALLOC(name, allocator, type) type* name = (type*) arenaPush(allocator, sizeof(type))