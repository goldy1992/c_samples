#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#define INITIAL_CAPACITY 16

struct Entry {
    void* key;
    void* value;
};
typedef struct Entry Entry;


struct HashMap
{
    Entry* entries;
    size_t capacity;
    size_t size;
};
typedef struct HashMap HashMap;

void init_hashmap(HashMap* hashMap)
{
    hashMap->capacity = INITIAL_CAPACITY;
    hashMap->size = 0;
    hashMap->entries = (Entry*)calloc(INITIAL_CAPACITY, sizeof(Entry));
}

#define FNV_OFFSET 14695981039346656037UL
#define FNV_PRIME 1099511628211UL

// Return 64-bit FNV-1a hash for key (NUL-terminated). See description:
// https://en.wikipedia.org/wiki/Fowler%E2%80%93Noll%E2%80%93Vo_hash_function#FNV-1a_hash
uint64_t hash_key(const void* key) {
    uint64_t hash = FNV_OFFSET;
    for (const char* p = key; *p; p++) {
        hash ^= (uint64_t)(unsigned char)(*p);
        hash *= FNV_PRIME;
    }
    return hash;
}

void hashmap_put(HashMap* hashMap, void* key, void* value) {
    uint64_t hash = hash_key(key);
    size_t index = (size_t)(hash & (uint64_t)(hashMap->capacity - 1));
}

int main() {
    HashMap hashmap;
    init_hashmap(&hashmap);
    printf("Hello, Hashmap!\n");
    return 0;
}