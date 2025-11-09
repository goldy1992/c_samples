#include "memory_arena.h"
#include "linked_list.h"
#include "hashmap.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void test_hashmap()
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
}

void test_linked_list(Arena* arena) {
    wchar_t kamT1[10] = { L'ป', L'ร', L'ะ', L'เ', L'ท', L'ศ', L'ไ', L'ท', L'ย', L'\0' };
    printf("%ls\n", kamT1);
    wchar_t* kamT2 = L"รวม";
    wchar_t* kamT3 = L"เลือด";
    wchar_t* kamT4 = L"เนื้อ";
    wchar_t* kamT5 = L"ชาติ";
    wchar_t* kamT6 = L"เชื้อ";
    wchar_t* kamT7 = L"ไทย";
    LinkedList* list = (LinkedList*)arena_push(arena, sizeof(LinkedList));
    init_linked_list(list);
    ListEntry* entry1 = (ListEntry*)arena_push(arena, sizeof(ListEntry));
    entry1->data = kamT1;
    linked_list_append(list, entry1);
    ListEntry entry2;
    entry2.data = kamT1;
    linked_list_append(list, &entry2);

    wchar_t* result = (wchar_t*)linked_list_get(list, 0);
    assert(result == kamT1);
}

int main() {
    Arena arena;
    arena_init(&arena, 1024);
    test_linked_list(&arena);


}
