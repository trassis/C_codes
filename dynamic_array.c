# include <stdlib.h>

// Implementação de um array dinâmico.
// Inicializando um vetor de tamanho 4.
//      vector *myVector = new_vector(4);
//      free(vector);
// Após o uso, é boa prática liberar esse vetor.
typedef struct{
    int index;
    int capacity;
    int *data;
} vector;

// Initialization
vector* new_vector(int size){
    vector *v = malloc(sizeof(vector));
    v->index = 0;
    v->capacity = size;
    v->data = malloc(v->capacity*sizeof(int));
    return v;
}

// Ponteiro para a posição index.
int* get_pointer(vector *v, int index){
    return &v->data[index];
}

// Retorna o valor na posição index.
int get_value(vector *v, int index){
    return v->data[index];
}

// Atribui um valor value à posição index.
void set_value(vector *v, int index, int value){
    v->data[index] = value;
}

// Adiciona um valor value ao final do vetor.
void append(vector *v, int value){
    // Há espaço para um mais um valor.
    if(v->index < v->capacity){
        v->data[v->index] = value;
        v->index++;
    }
    // Cria um novo array, com o dobro de tamanho do original.
    else {
        int *new_data = malloc(2*(v->capacity)*sizeof(int));
        for (int i = 0; i < v->capacity; i++)
        {
            new_data[i] = v->data[i];
        }
        v->capacity *= 2;
        free(v->data);
        v->data = new_data;
        v->data[v->index] = value;
        v->index++;
    }
}

// Retorna a quantidade de elementos guardados em vector.
int get_size(vector *v){
    return v->index;
}