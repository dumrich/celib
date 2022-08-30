#ifndef VECTOR_H
#define VECTOR_H

#include <stdio.h>

typedef struct {
    void* v;
    size_t size;

    size_t obj;
} Vec;

Vec* vector_init(size_t);

void vector_add(void*);
void* vector_remove(void*);

void* vector_get(int);

void vector_free(Vec*);

#endif