#include "queue.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

Queue createQueue(size_t itemSize, size_t capacity)
{
	// start by mallocing the size
	Queue queue;
	queue.size = 0;
	queue.capacity = capacity;
	queue.headIdx = -1;
	queue.itemSize = itemSize;
 	queue.data = malloc(sizeof(itemSize) * capacity);
	return queue;
}

void pushQueueCopy(void* item, size_t itemSize, Queue* queue) {
	void* copyAddr = pushQueueGetRef(queue);
	memcpy(copyAddr, item, sizeof(itemSize));
}

void* pushQueueGetRef(Queue* queue) {
	assert(queue->size < queue->capacity);
	size_t insertIdx = 0;
	if (queue->headIdx == -1) {
		queue->headIdx = 0;
		queue->size = 1;
	}
	else {
		insertIdx = (queue->size++ + queue->headIdx) % queue->capacity;
	}	
	return queue->data + (insertIdx* queue->itemSize);
}

void* popQueue(Queue* queue) {
	assert(queue->size > 0);
	void* toReturn  = queue->data + (queue->itemSize * queue->headIdx);
	if (--queue->size == 0) {
		queue->headIdx = -1;
	}
	else {
		++queue->headIdx % queue->capacity;
	}
	return toReturn;
}

