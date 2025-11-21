#include "unity.h"
#include "queue.h" // Include the header for the code you are testing
#include "test_queue.h"
_Pragma("warning(disable: 4100)") // Disable warning for unused parameter 'item' in mock queue

void test_queue_creation(void) {
 Queue queue = createQueue(sizeof(int), (size_t)10);
    int i;
    for (i = 1; i <= 5; i++)
    {
        pushQueueCopy(&i, sizeof(int), &queue);
    }
    for (i = 1; i <= 5; i++)
    {
        int popped = *(int *)popQueue(&queue);
        TEST_ASSERT_EQUAL_INT(i, popped);
    }
}

void test_enqueue_and_dequeue(void) {
    Queue queue = createQueue(sizeof(int), (size_t)10);
    int i;
    for (i = 1; i <= 2; i++)
    {
        pushQueueCopy(&i, sizeof(int), &queue);
    }
    int *firstPopped = popQueue(&queue);
    TEST_ASSERT_EQUAL(1, *firstPopped);

    
    // Example test: Replace with your actual queue implementation
    // queue_t* q = queue_create(10);
    // queue_enqueue(q, (void*)123);
    // TEST_ASSERT_EQUAL_INT(1, queue_size(q));
    // void* item = queue_dequeue(q);
    // TEST_ASSERT_EQUAL_PTR((void*)123, item);
    // TEST_ASSERT_EQUAL_INT(0, queue_size(q));
    // queue_destroy(q);

    // For now, a placeholder test that passes
    TEST_ASSERT_TRUE(1);
}