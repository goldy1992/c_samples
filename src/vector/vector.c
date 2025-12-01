#include "vector.h"
#include <string.h>
#include <assert.h>

inline void _increaseCapacity(Vector *vector, Arena *arena)
{
    void *oldItems = vector->data; // reference to the current list to copy to a new location
    size_t oldItemCapacity = vector->itemCapacity;
    size_t oldByteCapacity = vector->byteCapacity;

    if (oldItemCapacity == 0)
    {
        vector->itemCapacity = 1;
    }
    else
    {
        vector->itemCapacity = oldItemCapacity * 2;
    }
    vector->byteCapacity = vector->itemCapacity * vector->itemSize;
    vector->data = arena_push(arena, vector->byteCapacity);

    // copy the old items to the newer, larger area of contigeous memory
    memcpy_s(vector->data, vector->byteCapacity, oldItems, oldByteCapacity);
}

inline void _checkCapacity(Vector* vector, Arena* arena) {
  // first check to see if full
    if (vector->size >= vector->itemCapacity)
    {
        _increaseCapacity(vector, arena);
    }
}

inline void _moveItems(size_t nItems, Vector* vector, char* from, char* to)
{
        // Move all items in the array forward by the size of an item.
        size_t sizeOfItemsToMoveInBytes = vector->itemSize * nItems;
        memmove_s(to, sizeOfItemsToMoveInBytes, from, sizeOfItemsToMoveInBytes);

}

void vectorInit(Vector *vector, size_t itemSize, size_t itemCapacity, Arena *allocator)
{
    assert(itemCapacity > 0); // vector should have some default capacity greater than zero
    vector->data = arena_push(allocator, itemSize * itemCapacity);
    vector->itemCapacity = itemCapacity;
    vector->itemSize = itemSize;
    vector->byteCapacity = itemSize * itemCapacity;
    vector->size = 0;
}

void vectorAppend(Vector *vector, void *item, Arena *arena)
{
    _checkCapacity(vector, arena);

    char *dataPtr = (char *)vector->data;
    dataPtr += vector->itemSize * vector->size;
    memcpy_s(dataPtr, vector->itemSize, item, vector->itemSize);
    vector->size++;
}

void vectorInsertAt(Vector *vector, size_t index, void *item, Arena *arena)
{
    assert(index >= 0 && index < vector->size);

    if (index == vector->size)
    { // then just append
        vectorAppend(vector, item, arena);
        return;
    }
    else {
        _checkCapacity(vector, arena);
        char* insertIdx = ((char*) vector->data) + (index * vector->itemSize);
        // Move all items in the array forward by the size of an item.
        char* copyLaterItemsToIdx = insertIdx + vector->itemSize;
        size_t nItemsToMove = vector->size - index;
        size_t sizeOfItemsToMoveInBytes = vector->itemSize * nItemsToMove;
        memmove_s(copyLaterItemsToIdx, sizeOfItemsToMoveInBytes, insertIdx, sizeOfItemsToMoveInBytes);
        // copy the item into the index position
        memcpy_s(insertIdx, vector->itemSize, item, vector->itemSize);
        vector->size++;
    }
}

void *vectorGetAt(Vector *vector, size_t index)
{
    assert(index >= 0 && index < vector->size);
    char *dataPtr = vector->data;
    return dataPtr + (vector->itemSize * index);
}
void *vectorRemoveAt(Vector *vector, size_t index, void *item, Arena *arena)
{
}