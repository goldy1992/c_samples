#include "unity.h"
#include "test_queue.h"

// Forward declare the test functions from other files

void setUp(void) {
    // This is run before EACH test
}

void tearDown(void) {
    // This is run after EACH test
}

int main() {
    UNITY_BEGIN();
    RUN_TEST(test_queue_creation);
    RUN_TEST(test_enqueue_and_dequeue);
    return UNITY_END();
}
