#pragma once
#include <stddef.h>
#include <stdint.h>

typedef struct {
	size_t capacity;
	size_t size;
	size_t itemSize;
	uint32_t headIdx;
	void* data;	
} Queue;

Queue createQueue(size_t itemSize, size_t capacity);
void pushQueueCopy(void* item, size_t itemSize, Queue* queue);
void* pushQueueGetRef(Queue* queue);
void* popQueue(Queue* queue);
