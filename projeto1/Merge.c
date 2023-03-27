#include <stdlib.h>
#include <math.h>
#include "Merge.h"

//Autor: Thiago Gomez
//PARCIALMENTE COPIADO: https://gist.github.com/olegon/27c2a880c9b932862e60ab5eb89be5b6
void merge(int *v, int *c, int i, int m, int f) {
  int z,iv = i,ic = m + 1;
  for (z = i; z <= f; z++) c[z] = v[z];
  z = i;
  while (iv <= m && ic <= f) {
    if (c[iv] <= c[ic]) v[z++] = c[iv++];
    else v[z++] = c[ic++];
  }
  while (iv <= m) v[z++] = c[iv++];
  while (ic <= f) v[z++] = c[ic++];
}

void sort(int *v, int *c, int i, int f) {
  if (i >= f) return;
  int m = (i + f) / 2;
  sort(v, c, i, m);
  sort(v, c, m + 1, f);
  if (v[m] <= v[m + 1]) return;
  merge(v, c, i, m, f);
}

void merge_sort(int *v, int n) {
  int *c = malloc(sizeof(int) * n);
  sort(v, c, 0, n - 1);
  free(c);
}


/*A função merge_sort é uma implementação do algoritmo de ordenação Merge Sort. 
Ela recebe como parâmetro um vetor de inteiros "v" e o tamanho do vetor "n".

A função sort é uma função recursiva que divide o vetor em duas metades e chama ela mesma para cada metade. 
Cada chamada da função sort tem como parâmetro o vetor "v", um vetor auxiliar "c", 
o índice inicial "i" e o índice final "f" do segmento do vetor que está sendo ordenado. 
Se o índice inicial for maior ou igual ao final, significa que o vetor já está ordenado, então a função é encerrada. 
Caso contrário, é calculado o índice médio "m" do vetor e a função é chamada recursivamente para as duas metades esquerda e direita.

A função merge é chamada quando as chamadas recursivas da função sort retornam. Ela recebe como parâmetro o vetor "v", o vetor auxiliar "c", 
o índice inicial "i", o índice médio "m" e o índice final "f" do segmento do vetor que está sendo ordenado. 
O vetor auxiliar "c" é preenchido com os elementos do vetor "v" e, então, os elementos são comparados e ordenados entre os vetores "v" e "c", 
de acordo com a ordem crescente.*/
