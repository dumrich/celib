#include "collections.h"
#include <stdarg.h>
#include <stdio.h>

List* new_list(size_t width) {
    List* l = malloc(sizeof(List));
    l->head = l->tail = NULL;

    l->length = 0;

    l->data_width = width;

    return l;
}

void free_list(List* l) {
    Node* n = l->head;

    while(n != NULL) {
        Node* tmp = n->next;
        free(n->data);
        free(n);
        n = tmp;
    }
    
    free(l);
}

Node* push_list(List* l, void* d) {
    if(l->head == NULL) {
        l->head = l->tail = malloc(sizeof(Node));
        l->head->next = l->head->prev = NULL;
    } else {
        l->tail->next = malloc(sizeof(Node));
        l->tail->next->prev = l->tail;
        l->tail = l->tail->next;
    }

    l->tail->data = d;
    l->tail->next = NULL;

    l->length++;

    return l->tail;
}


void prepend_list(List* l, void* d) {
    l->head->prev = malloc(sizeof(Node));
    l->head->prev->next = l->head;
    l->head = l->head->prev;

    l->head->data = d;

    l->length++;
}

void* list_get(List* l, int index) {

    if(index >= l->length) {
        return NULL;
    }
    
    int cur = 0;
    Node* n = l->head;

    while(cur++ <= index && (n = n->next) != NULL);

    return n->data;
}


void remove_node(Node* n) {
    n->prev->next = n->next;
    n->next->prev = n->prev;
    free(n);
}

void print_list(List* l, void (*print)(void*)) {
    Node* n = l->head;
    while(n != NULL) {
        print(n->data);
        printf("\n");
    }
}