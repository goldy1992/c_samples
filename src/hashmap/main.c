#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#define INITIAL_CAPACITY 16

struct Entry
{
    void *key;
    void *value;
};
typedef struct Entry Entry;

struct HashMap
{
    Entry *entries;
    size_t capacity;
    size_t size;
};
typedef struct HashMap HashMap;

void init_hashmap(HashMap *hashMap)
{
    hashMap->capacity = INITIAL_CAPACITY;
    hashMap->size = 0;
    hashMap->entries = (Entry *)calloc(INITIAL_CAPACITY, sizeof(Entry));
}

#define FNV_OFFSET 14695981039346656037UL
#define FNV_PRIME 1099511628211UL

// Return 64-bit FNV-1a hash for key (NUL-terminated). See description:
// https://en.wikipedia.org/wiki/Fowler%E2%80%93Noll%E2%80%93Vo_hash_function#FNV-1a_hash
uint64_t hash_key(const void *key)
{
    uint64_t hash = FNV_OFFSET;
    for (const char *p = key; *p; p++)
    {
        hash ^= (uint64_t)(unsigned char)(*p);
        hash *= FNV_PRIME;
    }
    return hash;
}

// this should have a custom implementation for different types, can possibly be done with macros.
int compare_keys(const void *key1, const void *key2)
{
    const char *str1 = (const char *)key1;
    const char *str2 = (const char *)key2;
    return str1 == str2 || (str1 && str2 && strcmp(str1, str2) == 0);
}

void *hashmap_put(HashMap *hashMap, void *key, void* value)
{
    uint64_t hash = hash_key(key);
    size_t index = (size_t)(hash & (uint64_t)(hashMap->capacity - 1));

    while (hashMap->entries[index].key != NULL)
    {
        if (compare_keys(hashMap->entries[index].key, key) == 0)
        {
            // the keys already exists, update the value
            hashMap->entries[index].value = value;
            return hashMap->entries[index].value;
        }
        // use
        index++;
        if (index >= hashMap->capacity)
        {
            index = 0;
        }
    }

    hashMap->entries[index].key = key;
    hashMap->entries[index].value = value;
    return hashMap->entries[index].value;
    // printf("Didn't find any space for the new entry, need to resize the hashmap\n");
    // // if we got to here we didn't find any space for the new entry
    // // TODO: implement resizing!
    // return NULL;
}

// Same as put but doesn't add a new entry if the key doesn't exist and no need for memory reallocation
void* hashmap_get(HashMap* hashMap, void* key)
{
    uint64_t hash = hash_key(key);
    size_t index = (size_t)(hash & (uint64_t)(hashMap->capacity - 1));

    while (hashMap->entries[index].key != NULL)
    {
        printf("Checking index %zu with key %s\n", index, (char*)hashMap->entries[index].key);
        if (compare_keys(hashMap->entries[index].key, key))
        {
            // the keys already exists, update the value
            return hashMap->entries[index].value;
        }
        // use linear probing to find the next index
        index++;
        if (index >= hashMap->capacity)
        {
            index = 0;
        }
    }

    // if we got to here we didn't find any space for the new entry
    printf("Didn't find any space for the new entry, need to resize the hashmap\n");
    // TODO: implement resizing!
    return NULL;
}
    



int main()
{

    const char* apple = "apple";
    const int appleValue = 100;
    // const char* new_apple = "apple";
    // const char* orange = "orange";
    // int value = strcmp(apple, new_apple);
    // printf("strcmp result: %d\n", value);
    // if (value) {
    //     printf("The strings are equal.\n");
    // } else {
    //     printf("The strings are not equal.\n");
    // }
    HashMap hashmap;
    init_hashmap(&hashmap);
    hashmap_put(&hashmap, (void*)apple, (void*)&appleValue);
    // hashmap_put(&hashmap, "oranges", 50);
    // hashmap_put(&hashmap, "durian", 150);

    int* apple_value = (int *)hashmap_get(&hashmap, "apple");
    // int *orange_value = (int *)hashmap_get(&hashmap, "oranges");
    // int *durian_value = (int *)hashmap_get(&hashmap, "durian");
    printf("apple: %d\n", *apple_value);
    // printf("oranges: %d\n", orange_value ? *orange_value : -1);
    // printf("durian: %d\n", durian_value ? *durian_value : -1);
    return 0;
}