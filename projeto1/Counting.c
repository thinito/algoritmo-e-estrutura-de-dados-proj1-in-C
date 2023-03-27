#include <stdlib.h>
#include <math.h>
#include "Counting.h"
#define MAX_VECTOR_SIZE 1000000

//Autor: Thiago Gomez
//PARCIALMENTE COPIADO: https://www.geeksforgeeks.org/counting-sort/
void counting_sort(int* arr, int size) {
    int i, j;
    int count[MAX_VECTOR_SIZE] = {0};
    for (i = 0; i < size; i++) {
        count[arr[i]]++;
    }
    int k = 0;
    for (i = 0; i < MAX_VECTOR_SIZE; i++) {
        for (j = 0; j < count[i]; j++) {
            arr[k++] = i;
        }
    }
}

/*Este código define uma função chamada "counting_sort" que recebe um array de inteiros chamado "arr" e seu tamanho "size" como entradas. 
A função usa o algoritmo de ordenação de contagem para classificar os elementos do array de entrada.

A função começa criando um array chamado "count" com "MAX_VECTOR_SIZE" elementos, que é inicializado com zero. 
Este array será usado para armazenar a contagem de ocorrências de cada elemento no array de entrada.

A função então itera pelo array de entrada (i = 0; i < size; i) e, para cada elemento, o elemento correspondente no array "count" é incrementado em 1. 
A função então itera pelo array "count" (i = 0; i < MAX_VECTOR_SIZE; i), e para cada elemento não-nulo, o valor desse elemento é adicionado ao array de 
entrada o número de vezes indicado pela contagem. Uma variável chamada "k" é usada para manter o rastreamento da posição atual no array de entrada.
Finalmente, o array de entrada será classificado em ordem crescente.*/
