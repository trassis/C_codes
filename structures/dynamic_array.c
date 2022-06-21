# include <stdlib.h>

typedef struct {
    int index; 
    int size;
    int *array;
} vector;

void init_vector(vector *v, int size){
    v->index = 0;
    v->size = size;
    v->array = malloc(size*sizeof(int));
}

void free_vector(vector *v){
    free(v->array);
}

void vec_append(vector *v, int value){
    if(v->index == v->size){
        v->array = realloc(v->array, 2*v->size*sizeof(int));
        v->size *= 2;
    }
    v->array[v->index++] = value;
}
