#include "vector.h"
#include <string.h>
#include <assert.h>

void vectorInit(Vector* vector, size_t itemSize, size_t itemCapacity, Arena* allocator) {
    vector->data = arena_push(allocator, itemSize * itemCapacity);
    vector->itemCapacity= itemCapacity;
    vector->itemSize = itemSize;
    vector->byteCapacity = itemSize * itemCapacity;
    vector->size = 0;
}

void vectorAppend(Vector* vector, void* item, Arena* arena) {
    // first check to see if full
    if (vector->size >= vector->itemCapacity)
    {
       void* oldItems = vector->data; // reference to the current list to copy to a new location
       size_t oldItemCapacity = vector->itemCapacity;
       size_t oldByteCapacity = vector->byteCapacity;


       vector->itemCapacity = oldItemCapacity * 2;
       vector->byteCapacity = vector->itemCapacity * vector->itemSize;
       vector->data = arena_push(arena, vector->byteCapacity);

       // copy the old items to the newer, larger area of contigeous memory
       memcpy_s(vector->data, vector->byteCapacity, oldItems, oldByteCapacity);
    }

    char* dataPtr = (char*)vector->data;
    dataPtr+= vector->itemSize * vector->size;
    memcpy_s(dataPtr, vector->itemSize, item, vector->itemSize);
    vector->size++;
}

void vectorInsertAt(Vector* vector, size_t index, void* item, Arena* arena) {

}

void* vectorGetAt(Vector* vector, size_t index) {
    assert(index >= 0 && index < vector->size);
    char* dataPtr = vector->data;
    return dataPtr + (vector->itemSize * index);
}
void* vectorRemoveAt(Vector* vector, size_t index, void* item, Arena* arena) {

}