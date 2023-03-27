#include <stdlib.h>
#include <math.h>
#include "Bubble.h"

//Autor: Leonardo Ribeiro
//PARCIALMENTE COPIADO: https://www.chegg.com/homework-help/questions-and-answers/static-void-bubblesort-int-arr-int-n-arrlength-int-temp-0-int-0-q64578931
void bubble_sort(int* arr, int size) {
    int i, j, temp;
    for (i = 0; i < size-1; i++) {
        for (j = 0; j < size-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

/*Esse código implementa o algoritmo de ordenação "bubble sort". 
A função recebe dois parâmetros:
um array de inteiros chamado "arr", que é o array a ser classificado.
um inteiro chamado "size", que é o tamanho do array.

O algoritmo começa comparando o primeiro elemento do array com o segundo, 
e se o primeiro for maior que o segundo, os dois elementos são trocados de posição. Isso é feito para todos os elementos até o final do array. 
Esse processo é repetido várias vezes até que todos os elementos estejam ordenados. O laço externo "for (i = 0; i < size-1; i++)" 
controla o número de vezes que o algoritmo passa pelo array. O laço interno "for (j = 0; j < size-i-1; j++)" controla as comparações e 
trocas de elementos em cada passagem. A variável "temp" é usada para armazenar temporariamente o valor de um elemento enquanto outro é atribuído a ele.*/
