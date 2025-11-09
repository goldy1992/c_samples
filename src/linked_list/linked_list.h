#pragma once

#define NULL ((void*)0)


typedef struct ListEntry ListEntry;
struct ListEntry 
{
    void *data;
    ListEntry *next;
};

typedef struct 
{
    ListEntry *head;
    ListEntry *tail;
    size_t size;
} LinkedList;

void init_linked_list(LinkedList *list);

void linked_list_append(LinkedList *list, ListEntry *data);

void* linked_list_get(LinkedList *list, size_t index);

ListEntry* lined_list_replace_at(LinkedList *list, ListEntry* data, size_t index);
void lined_list_insert_at(LinkedList *list, ListEntry* entry, size_t index);