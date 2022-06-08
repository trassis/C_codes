# include <stdio.h>

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