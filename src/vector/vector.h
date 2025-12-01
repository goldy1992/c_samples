#pragma once
#include "memory_arena.h"
/**
 * Implementation of a resizeable array similar to the C++ std::vector
 */
typedef struct {
    size_t itemCapacity;
    size_t byteCapacity;
    size_t size; // number of items in the vector
    size_t itemSize;
    void* data;
} Vector;

void vectorInit(Vector* vector, size_t itemSize, size_t capacity, Arena* arena);
void vectorAppend(Vector* vector, void* item, Arena* arena);
void vectorInsertAt(Vector* vector, size_t index, void* item, Arena* arena);
void* vectorGetAt(Vector* vector, size_t index);
void* vectorRemoveAt(Vector* vector, size_t index, void* item, Arena* arena);