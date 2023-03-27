#include <stdlib.h>
#include <math.h>
#include "Selection.h"

//Autor: Leonardo Ribeiro
//PARCIALMENTE COPIADO: https://www.geeksforgeeks.org/selection-sort/
void selection_sort(int arr[], int size) {
    int i, j, min_idx, temp;
    for (i = 0; i < size-1; i++) {
        min_idx = i;
        for (j = i+1; j < size; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}

/*
A função recebe dois parâmetros:
um array de inteiros chamado "arr", que é o array a ser classificado.
um inteiro chamado "size", que é o tamanho do array.

O algoritmo funciona da seguinte maneira:
O primeiro loop "for" percorre cada elemento no array, começando do primeiro elemento.
Dentro desse loop, a variável "min_idx" é inicializada com o índice atual (i).
O próximo loop "for" percorre os elementos restantes no array, começando do próximo elemento após o elemento atual.
Dentro desse loop, a condição verifica se o elemento atual é menor que o elemento armazenado em "min_idx". Se for, o índice atual é armazenado em "min_idx".
Depois que o segundo loop termina, a condição garante que o menor elemento no array foi encontrado e armazenado em "min_idx".
A linha 15 armazena o valor do elemento encontrado em "temp".
A linha 16 troca o valor do elemento encontrado com o valor do primeiro elemento não ordenado.
A linha 17 troca o valor do primeiro elemento não ordenado com o valor armazenado em "temp".
Isso é repetido até que todos os elementos do array estejam ordenados.*/
