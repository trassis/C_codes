// Merge dois arrays, os [b...m] e [m+1...e].
void _merge(int *arr, int b, int m, int e){
    int i = b, j = m + 1;
    int work[e - b + 1]; // Array de trabalho
    while (i <= m && j <= e) // Merge os arrays
    {
        // Comparação entre [b...m] e [m+1...e].
        if(arr[b + i] < arr[m + 1 + j]){
            work[i + j - b - m - 1] = arr[i];
            i++;
        }
        else {
            work[i + j - b - m - 1] = arr[j];
            j++;
        }
    }
    while (i <= m) // [m+1...e] já foi utilizado
    {
        work[i + j - b - m - 1] = arr[i];
        i++;
    }
    while (j <= e) // [b..m] já foi utilizado
    {
        work[i + j - b - m - 1] = arr[j];
        j++;
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
