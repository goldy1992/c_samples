#include "linked_list.h"
#include <assert.h>


void init_linked_list(LinkedList *list) {
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
}
void lined_list_insert_at(LinkedList *list, ListEntry* entry, size_t index) {

}

void linked_list_append(LinkedList *list, ListEntry *data) {
    if (list->head == NULL) {
        list->head = data;
        list->tail = data;
        list->size = 1;
    } else {
        ListEntry* currentTail = list->tail;
        currentTail->next = data;
        list->tail = data;
        list->size += 1;
    }
}

void* linked_list_get(LinkedList *list, size_t index) {
    assert((index >= 0) && (index < list->size) && "Index out of bounds in linked_list_get");
    if (list->head == NULL) {
        return NULL;
    }
    else if (index == 0) {
        return list->head->data;
    }
    else {
        ListEntry* current = list->head;
        for (int i = 0; i < index; i++) {
            current = current->next;
        }
        return current->data;
    }
}

// return a pointer to value replaced
ListEntry* lined_list_replace_at(LinkedList *list, ListEntry* data, size_t index) {
    assert((index >= 0) && (index < list->size) && "Index out of bounds in linked_list_get");
    if (list->head == NULL) {
        list->head = data;
        list->tail = data;
    }
    else if (index == 0) {
        ListEntry* currentHead = list->head;
        list->head = data;
        if (currentHead != NULL ) {
            data->next = currentHead->next;
            return currentHead;
        }
        else {
            return NULL;
        }
    }
    else {
        ListEntry* current = list->head;
        for (int i = 0; i < index - 1; i++) {
            current = current->next;
        }
        data->next = current->next;
        current->next = data;
    }
    return NULL;
}