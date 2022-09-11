#ifndef VECTOR_H
#define VECTOR_H

#include <stdio.h>

typedef struct {
    void** v;
    long long length;
    long long buffer_length;
} Vec;

Vec* vector_init();

void vector_add(Vec*, void*);
void vector_set(Vec*, unsigned int, void*);

void* vector_remove(Vec* v);

void* vector_get(const Vec* vec, unsigned int index);

void vector_free(Vec*);

#endif
