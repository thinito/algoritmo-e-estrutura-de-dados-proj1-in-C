#include <stdlib.h>
#include <math.h>
#include "Bucket.h"

//Autor: Thiago Gomez
//PARCIALMENTE COPIADO: https://pt.stackoverflow.com/questions/413274/bucket-sort-c
int getMaxi(int a[], int n)
{  
  int max = a[0];  
  for (int i = 1; i < n; i++)  
    if (a[i] > max)  
      max = a[i];  
  return max;  
}  
void bucket_sort(int a[], int n)
{  
  int max = getMaxi(a, n);
  int bucket[max], i;  
  for (int i = 0; i <= max; i++)  
  {  
    bucket[i] = 0;  
  }  
  for (int i = 0; i < n; i++)  
  {  
    bucket[a[i]]++;  
  }  
  for (int i = 0, j = 0; i <= max; i++)  
  {  
    while (bucket[i] > 0)  
    {  
      a[j++] = i;  
      bucket[i]--;  
    }  
  }  
}

/*A função "bucket_sort" recebe o mesmo array de inteiros "a" e seu tamanho "n" como entradas e usa o algoritmo de ordenação de balde para classificar os 
elementos do array de entrada. A função começa chamando a função "getMaxi" para encontrar o valor máximo no array de entrada.
A função então cria um array chamado "bucket" com tamanho "max+1" (onde "max" é o valor máximo encontrado pelo "getMaxi"), 
que é inicializado com zero. Este array será usado para armazenar a contagem de ocorrências de cada elemento no array de entrada.
A função então itera pelo array de entrada (for (int i = 0; i < n; i)) e, para cada elemento, o elemento correspondente no array 
"bucket" é incrementado em 1. 
A função então itera pelo array "bucket" (for (int i = 0, j = 0; i <= max; i)) e para cada elemento não-nulo, 
o valor desse elemento é adicionado ao array de entrada o número de vezes indicado pela contagem. Uma variável chamada "j" é usada para manter o rastreamento da posição atual no array de entrada.
Finalmente, o array de entrada será classificado em ordem crescente.*/
