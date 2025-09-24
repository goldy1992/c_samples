#pragma once

#include <stdint.h>

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

uint64_t hash_key(const void *key);
int compare_keys(const void *key1, const void *key2);
void init_hashmap(HashMap *hashMap);

void* hashmap_put(HashMap *hashMap, void *key, void* value);
void* hashmap_get(HashMap* hashMap, void* key);