# include <stdlib.h>

typedef struct {
    int index; 
    int size;
    int *data;
} vector;

void init_vect(vector *v, int size){
    v->index = 0;
    v->size = size;
    v->data = malloc(size*sizeof(int));
}

void append_vect(vector *v, int value){
    if(v->index == v->size){
        v->data = realloc(v->data, 2*v->size*sizeof(int));
        v->size *= 2;
    }
    v->data[v->index++] = value;
}
