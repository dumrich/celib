#include <stdio.h>
#include <celib.h>

void print(void* v) {
    List* l = (List*)v;

    Node* n = l->tail;
    while(n != NULL) {
        printf("%d\n", *(int*)n->data);
        n = n->prev;
    }    

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

    print(l);
}

