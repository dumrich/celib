#include <stdio.h>
#include <celib.h>
#include <stdlib.h>

int main() {
    Vec* v = vector_init();

    for(int i = 0; i <= 100; i++) {
        long long* x = malloc(sizeof(long long));
        *x = i * i;
        vector_add(v, x);
    }

    for(int i = 0; i <= 100; i++) {
        long long* a = vector_get(v, i);
        printf("%lld ", *a);
    }

    fflush(stdout);
    
    vector_free(v);
}
