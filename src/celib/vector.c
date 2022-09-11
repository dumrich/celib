#include "vector.h"
#include <stdlib.h>
#include <string.h>

#define VEC_BLOCK_SIZE 10

Vec* vector_init() {
    Vec* v = malloc(sizeof(Vec)); 

    v->length = -1;

    v->v = calloc(VEC_BLOCK_SIZE, sizeof(void*));
    v->buffer_length = VEC_BLOCK_SIZE;

    return v;
}

void vector_set(Vec* vec, unsigned int index, void* a) {
    if(index > vec->length)
        return;

    void* from = a;
    memcpy(&from, vec->v + sizeof(void*) * (index), sizeof(void*));
}

void vector_add(Vec* vec, void* a) {
    if(++vec->length == vec->buffer_length) {
        vec->buffer_length += 10;
        vec->v = realloc(vec->v, sizeof(void*) * vec->buffer_length);
    }

    vector_set(vec, vec->length, a);
}

/* 
void* vector_remove(Vec* vec) {
    
}
*/

void* vector_get(const Vec* vec, unsigned int index) {
    void* v = ((char*)vec->v) + index * sizeof(void*);
    return v;
}

void vector_free(Vec* vec) {
    free(vec->v);
    free(vec);
}
