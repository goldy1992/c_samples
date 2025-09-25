#include <stdio.h>
#include <stdlib.h>
#include "memory_arena.h"

int main()
{
    printf("Hello, Memory Arena!\n");

    // Initialize the memory arena
    Arena arena;
    arena_init(&arena, 1024);

    // Allocate some memory from the arena
    char *hello = (char *)arena_push(&arena, 6 * sizeof(char));
    strcpy(hello, "Hello");

    int *myInt = (int *)arena_push(&arena, sizeof(int));
    *myInt = 42;

    char *world = (char *)arena_push(&arena, 7 * sizeof(char));
    strcpy(world, "world!");

    char *ptr = (char *)arena.buffer;
    // Destroy the memory arena
    arena_free(&arena);
    return 0;
}