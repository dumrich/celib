#ifndef COLLECTIONS_H
#define COLLECTIONS_H

#include <stdlib.h>

typedef struct {
    struct Node* head;
    struct Node* tail;

    
    long long length;

    /* Length of data in bytes */
    size_t data_width;
} List;

struct Node {
    void* data;
    struct Node* next;
    struct Node* prev;
};

typedef struct Node Node;

List* new_list(size_t data_width);

void free_list(List*);

Node* push_list(List*, void*);
void prepend_list(List*, void*);

void insert_list(List* l, int index, void* data); /* TODO */

void* list_get(List*, int);
Node* list_get_node(List*, int);

void remove_node(Node*);

void print_list(List*, void (*print)(void*));

/*
  How to iterate over list:

  Node* n = List->head;
  while(n != NULL) {
      ...
      n = n->next;
  }
*/

/*
  Reverse:
  
  Node* n = List->tail;
  while(n != NULL) {
      ...
      n = n->prev;
  }

*/


#endif
