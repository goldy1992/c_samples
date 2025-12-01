#include "vector.h"
#include "test_vector.h"
#include <unity.h>
typedef struct {
    int x;
    float y;
    char z[4];
} TestStruct;

Arena arena;

void setUp(void) {
    // This is run before EACH test
    arena_init(&arena, Kilobytes(10));
}

void tearDown(void) {
    arena_free(&arena);
    // This is run after EACH test
}

void test_vector_append(void) {


    TestStruct toAppend;
    Vector testVector;
    int expectedX = 7;
    toAppend.x = expectedX;
    float expectedY = 3.14f;
    toAppend.y = expectedY;
    char expectedZ[4] = {'\0', '8', '_', 'v'};
    int c = 0;
    for(c; c < 4; ++c)
    {
        toAppend.z[c] = expectedZ[c];
    }
    vectorInit(&testVector, sizeof(TestStruct), 10, &arena);
    vectorAppend(&testVector, &toAppend, &arena);
    TEST_ASSERT_EQUAL(1, testVector.size);

    TestStruct *result = (TestStruct*)vectorGetAt(&testVector, 0);
    TEST_ASSERT_EQUAL(expectedX, result->x);
    TEST_ASSERT_EQUAL_FLOAT(expectedY, result->y);
    TEST_ASSERT_EQUAL_CHAR_ARRAY(expectedZ, result->z, 4);


}
void test_vector_append_full_capactity(void) {

}

int main() {
    UNITY_BEGIN();
    RUN_TEST(test_vector_append_full_capactity);
    RUN_TEST(test_vector_append);
    return UNITY_END();
}