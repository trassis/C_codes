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
