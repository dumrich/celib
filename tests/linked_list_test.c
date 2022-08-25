#include <stdio.h>
#include <celib.h>

void print(void* v) {
    int* i = (int*)v;
    printf("%d", *i);
}

int main() {
    List* l = new_list(sizeof(int));

    /* Items */
    int* i = malloc(sizeof(int));
    int* j = malloc(sizeof(int));
    int* k = malloc(sizeof(int));
    int* r = malloc(sizeof(int));
    *i = 1;
    *j = 2;
    *k = 3;
    *r = 4;
    
    push_list(l, i);
    push_list(l, j);
    push_list(l, k);
    push_list(l, r);

    print_list(l, print);
}

