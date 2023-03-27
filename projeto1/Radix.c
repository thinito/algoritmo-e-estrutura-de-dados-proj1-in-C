#include <stdlib.h>
#include <math.h>
#include "Radix.h"


//Autor: Thiago Gomez
//PARCIALMENTE COPIADO: https://gist.github.com/anubhavshrimal/afd54a4888180ca78374
int getMax(int array[], int n) {
  int max = array[0];
  for (int i = 1; i < n; i++)
    if (array[i] > max)
      max = array[i];
  return max;
}

void countingSort(int array[], int size, int place) {
  int output[size + 1];
  int max = (array[0] / place) % 10;
  for (int i = 1; i < size; i++) {
    if (((array[i] / place) % 10) > max)
      max = array[i];
  }
  int count[max + 1];
  for (int i = 0; i < max; ++i)
    count[i] = 0;
  for (int i = 0; i < size; i++)
    count[(array[i] / place) % 10]++;
  for (int i = 1; i < 10; i++)
    count[i] += count[i - 1];
  for (int i = size - 1; i >= 0; i--) {
    output[count[(array[i] / place) % 10] - 1] = array[i];
    count[(array[i] / place) % 10]--;
  }

  for (int i = 0; i < size; i++)
    array[i] = output[i];
}

void radix_sort(int* array, int size) {
  int max = getMax(array, size);
  for (int place = 1; max / place > 0; place *= 10)
    countingSort(array, size, place);
}

/*A função "radix_sort" recebe dois parâmetros:
um ponteiro para um array de inteiros chamado "array", que é o array a ser classificado.
um inteiro chamado "size", que é o tamanho do array.

O algoritmo funciona da seguinte maneira:
A primeira coisa que a função faz é chamar a função "getMax" para encontrar o valor máximo no array.
Em seguida, o algoritmo usa um loop "for" para iterar através de cada casa decimal (unidade, dezena, centena, etc.) do valor máximo. Cada iteração do loop é chamada de "place".
Dentro do loop, a função "countingSort" é chamada para classificar o array usando o "place" atual.
A função "countingSort" funciona criando um array "output" e um array "count" com o tamanho do valor máximo encontrado no passo 1.
O array "count" é usado para armazenar a contagem de cada dígito no array de entrada.
O array de saída é preenchido com os elementos do array de entrada, colocando-os em suas posições corretas de acordo com o dígito "place" atual.
Depois que todas as iterações do loop "for" são concluídas, o array de entrada é substituído pelo array de saída e o array estará classificado.*/
