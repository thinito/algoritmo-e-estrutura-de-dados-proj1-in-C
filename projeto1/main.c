#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Selection.h"
#include "Insertion.h"
#include "Bubble.h"
#include "Merge.h"
#include "Quick.h"
#include "Radix.h"
#include "Counting.h"
#include "Bucket.h"

#define MIN_VECTOR_SIZE 100
#define MAX_VECTOR_SIZE 1000000
#define NUM_SAMPLES 8
#define NUM_BUCKETS 5

//Autores: Leonardo Ribeiro e Thiago Gomez
//AUTORIA TOTAL

double get_execution_time(void (*sort_func)(int*, int), int* vector, int size) {
    clock_t start, end;
    start = clock();
    sort_func(vector, size);
    end = clock();
    return (double) (end - start) / CLOCKS_PER_SEC;
}
/*A função get_execution_time é utilizada para medir o tempo de execução de uma função de ordenação específica. 
Ela recebe como parâmetros uma função de ordenação (sort_func), um vetor de inteiros (vector) e o tamanho desse vetor (size)
A função começa pegando o tempo atual antes de chamar a função de ordenação passada como parâmetro. 
Em seguida, chama a função de ordenação passada como parâmetro e pega o tempo final, depois disso, 
calcula a diferença entre o tempo final e o tempo inicial e divide pelo número de "ticks" por segundo (CLOCKS_PER_SEC) 
para obter o tempo de execução em segundos. O valor do tempo de execução é retornado como um double.*/

double g_e_t(void (*sort_func)(int*, int, int), int* vector, int size) {
    clock_t start, end;
    start = clock();
    sort_func(vector,0, size);
    end = clock();
    return (double) (end - start) / CLOCKS_PER_SEC;
}
/*A função g_e_t segue a mesma premissa da get_execution_time, mas, em questão a funçãp de ordenação (sort_func)
temos um vetor de inteiros (vector), um valor inicial igual a zero (0) e o tamanho desse vetor (size)*/

void print_vector(int* arr, int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int i, j, k, size, *arr;
    double S_time=0, I_time=0,Bb_time=0,M_time=0,Q_time=0,R_time=0,C_time=0,Bk_time=0;
    struct timespec start, end;
    int vectorSizes[] = {100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000};
    for (i = 0; i < NUM_SAMPLES; i++) {
        size = vectorSizes[i];
        srand(time(0));
        for (k = 0; k < 40; k++){
            arr = (int*)malloc(size * sizeof(int));
            for (j = 0; j < size; j++) {arr[j] = rand() % 100;}
            I_time += get_execution_time(insertion_sort, arr, size);
            S_time += get_execution_time(selection_sort, arr, size);
            Bb_time += get_execution_time(bubble_sort, arr, size);
            C_time += get_execution_time(counting_sort, arr, size);
            Bk_time += get_execution_time(bucket_sort, arr, size);
            R_time += get_execution_time(radix_sort, arr, size);
            Q_time += g_e_t(quick_sort, arr, size);
            M_time += get_execution_time(merge_sort, arr, size);
            free(arr);
        }
        printf("---------- Size: %d ----------\n", size);        
        printf("Selection sort time: %f\n", S_time/40);
        printf("Insertion sort time: %f\n", I_time/40);
        printf("Bubble sort time: %f\n", Bb_time/40);
        printf("Merge sort time: %f\n", M_time/40);        
        printf("Radix sort time: %f\n", R_time/40);
        printf("Counting sort time: %f\n", C_time/40);
        printf("Bucket sort time: %f\n", Bk_time/40);
        printf("Quick sort time: %f\n", Q_time/40);
        }
        return 0;
}
/*Nesta função, são declaradas variáveis de tempo para armazenar o tempo de execução de cada um dos algoritmos de ordenação implementados. 
Em seguida, é criado um loop que itera sobre o tamanho dos vetores a serem ordenados, 
criando um vetor de tamanho size e preenchendo-o com valores aleatórios. Dentro desse loop, 
é criado outro loop que itera 40 vetores aleatórios para cada "size" para medir o tempo de execução de cada algoritmo de ordenação e armazená-lo na variável correspondente. 
Por fim, é impresso o tempo de execução médio de cada algoritmo para cada tamanho de vetor testado.*/
