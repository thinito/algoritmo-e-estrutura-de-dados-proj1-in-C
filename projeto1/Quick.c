#include <stdlib.h>
#include <math.h>
#include "Quick.h"

//Autor: Leonardo Ribeiro
//PARCIALMENTE COPIADO: https://gist.github.com/marcoscastro/13278494d52dd970c7f4
void troca(int vet[], int i, int j){
  int aux = vet[i];
  vet[i] = vet[j];
  vet[j] = aux;
}
int particiona(int* vet, int inicio, int fim){
    int pivo, pivo_indice, i;
    pivo = vet[fim];
    pivo_indice = inicio;
    for(i = inicio; i < fim; i++){
        if(vet[i] <= pivo){
            troca(vet, i, pivo_indice);
            pivo_indice++;
        }
    }
    troca(vet, pivo_indice, fim);
    return pivo_indice;
}

int particiona_random(int* vet, int inicio, int fim){
    int pivo_indice = (rand() % (fim - inicio + 1)) + inicio;
    troca(vet, pivo_indice, fim);
    return particiona(vet, inicio, fim);
}

void quick_sort(int* vet,int inicio, int fim){
    if(inicio < fim){
        int pivo_indice = particiona_random(vet, inicio, fim);
        quick_sort(vet, inicio, pivo_indice - 1);
        quick_sort(vet, pivo_indice + 1, fim);
    }
}


/*A função "quick_sort" recebe três parâmetros:
um ponteiro para um array de inteiros chamado "vet", que é o array a ser classificado.
um inteiro chamado "inicio" e outro chamado "fim", que delimitam o tamanho do array.

A função começa declarando duas outras funções auxiliares, "troca" e "particiona". 
A função "troca" simplesmente troca o valor de dois elementos de um vetor. 
A função "particiona" escolhe um elemento do vetor como pivô e organiza os outros elementos de forma que os menores fiquem à esquerda do pivô e os maiores à direita.
A função "particiona_random" é semelhante à "particiona", mas em vez de escolher sempre o último elemento como pivô, escolhe um elemento aleatório dentro do intervalo como pivô. Isso é feito para evitar casos de pior desempenho, quando o pivô é escolhido sempre ser o maior ou menor elemento.
A função "quick_sort" chama a função "particiona_random" para escolher um pivô e dividir o vetor. 
Em seguida, chama recursivamente a si mesma para ordenar cada sub-vetor gerado. 
Isso é feito até que todos os elementos estejam ordenados.*/
