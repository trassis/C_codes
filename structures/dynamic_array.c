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
    int n = v->size;
    if(v->index == n){
        int *data = malloc(2*n*sizeof(int));
        for (int i = 0; i < n; i++)
        {
            data[i] = vector->array[i];
        }
        free(v->array);
        v->array = data;
        v->size *= 2;
    }
    v->array[v->index++] = value;
}