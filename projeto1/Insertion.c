#include <stdlib.h>
#include <math.h>
#include "Insertion.h"

//Autor: Leonardo Ribeiro
//COPIADO: https://www.geeksforgeeks.org/insertion-sort/
void insertion_sort(int arr[], int size) {
    int i, key, j;
    for (i = 1; i < size; i++) {
        key = arr[i];
        j = i-1;
        while (j >= 0 && arr[j] > key) {
            arr[j+1] = arr[j];
            j = j-1;
        }
        arr[j+1] = key;
    }
}

/*Este código define uma função chamada "insertion_sort" que recebe um array de inteiros chamado "arr" e seu tamanho "size" como entradas. 
A função usa o algoritmo de ordenação por inserção para classificar os elementos do array de entrada em ordem crescente.

A função começa iterando pelo array começando pelo segundo elemento (i = 1) e terminando no último elemento (i < size). 
Em cada iteração, o elemento atual (arr[i]) é armazenado em uma variável chamada "key" e uma variável "j" é inicializada com o índice do elemento anterior (j = i-1).
A função então entra em um laço while que continua enquanto "j" é maior ou igual a 0 e o elemento no índice "j" (arr[j]) é maior que "key". 
Em cada iteração do laço while, o elemento no índice "j+1" é substituído pelo elemento no índice "j" e "j" é decrementado em 1. 
Este processo mantém movendo o elemento maior para a direita até que a chave esteja na sua posição correta.
Finalmente, a chave é colocada na posição correta atribuindo-a ao elemento no índice "j+1". Este processo continua até que todo o array esteja classificado em ordem crescente.*/
