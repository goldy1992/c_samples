#include "hashmap.h"
#include <stdio.h>

int main()
{
    // apples
    const char* apple = "apple";
    const int appleValue = 100;
    // oranges
    const char* orange = "orange";
    const int orangeValue = 25;

    HashMap hashmap;
    init_hashmap(&hashmap);
    hashmap_put(&hashmap, (void*)apple, (void*)&appleValue);
    hashmap_put(&hashmap, (void*)orange, (void*)&orangeValue);

    int* apple_value = (int *)hashmap_get(&hashmap, "apple");
    int* orange_value = (int *)hashmap_get(&hashmap, "orange");

    printf("apple: %d\n", *apple_value);
    printf("orange: %d\n", *orange_value);
    return 0;
}