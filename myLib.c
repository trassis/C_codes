# include <stdio.h>
# include <stdlib.h>

// Imprime o array especificado.
void _print_array(int *arr, int size){
    for (int i = 0; i < size - 1; i++) 
        printf("%d ", arr[i]);   
    printf("%d\n", arr[size - 1]);
}

// Retorna base elevado à exp.
int _pow(int base, int exp){
    if(exp < 0) return 0;
    else if(exp == 0) return 1;
    else return base*_pow(base, exp-1);
}

// Merge dois arrays, os [b...m] e [m+1...e].
void _merge(int *arr, int b, int m, int e){
    int i = 0, j = 0;
    int work[e - b + 1]; // Array de trabalho
    while (b + i <= m && m + 1 + j <= e) // Merge os arrays
    {
        // Comparação entre [b...m] e [m+1...e].
        if(arr[b + i] < arr[m + 1 + j]){
            work[i++ + j] = arr[b + i];
        }
        else {
            work[i + j++] = arr[m + 1 + j];
        }
    }
    while (b + i <= m) // [m+1...e] já foi utilizado
    {
        work[i++ + j] = arr[b + i];
    }
    while (m + 1 + j <= e) // [b..m] já foi utilizado
    {
        work[i + j++] = arr[m + 1 + j];
    }

    // Atualiza o array original
    for (int u = 0; u <= e - b; u++)
    {
        arr[b + u] = work[u];    
    }
}

// Sort in O(n*log(n)) time
void mergeSort(int *arr, int begin, int end){
    if(begin < end){
        int middle = (begin + end)/2;
        mergeSort(arr, begin, middle);
        mergeSort(arr, middle + 1, end);
        _merge(arr, begin, middle, end);
    }
}

// TODO:

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

int main(){

    vector *p = new_vector(4);
    printf("%d\n", p->index);

    append(p, 1);
    append(p, 5);
    append(p, 6);
    append(p, 7);
    append(p, 11);
    append(p, 12);
    append(p, 13);
    append(p, 14);
    set_value(p, 5, 400);

    for (int i = 0; i < get_size(p); i++)
    {
        printf("%d ", get_value(p, i));
    }
    printf(" (%d)\n", get_size(p));
    
    *get_pointer(p, 3) = 10;
    printf("%d\n", *get_pointer(p,3));

    free(p);

    printf("%d ", get_value(p,0));
    printf("%d ", p->data[1]);
    printf("%d ", p->data[2]);
    printf("%d\n", p->data[3]);

    return 0;
}