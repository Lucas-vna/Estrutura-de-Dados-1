/**
* @file pilhaEstatica.c
* @author Luiz Gustavo Pasini Abudi
* @date 06-07-2021
* @brief Pilha Estática

*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <stdbool.h>

//definindo o tamnahdo vetor
#define N 5

typedef struct{
  int vetor[N]; //iniciando o tamanho da pilha
  int topo; //variavel que auxilia na manipulaçao da pilha
} pilhaEstatica;

//iniciando a Pilha
void iniciaPilha(pilhaEstatica *p){
  p->topo = 0; //definindo a posiçao inicial da pilha
}

//tamanho da pilha (valor do topo)
int tamanhoPilha(pilhaEstatica *p){
  return(p->topo);
}

//imprimindo a Pilha
void imprimePilha(pilhaEstatica *p){
  printf("Pilha = { ");
  for(int i = 0; i < p->topo; i++){
    printf("|%d| ", p->vetor[i]);
  }
  printf("}\n");
}

//verifica se a pilha está vazia
bool estaVazia(pilhaEstatica *p){
  return(p->topo == 0);
}

//verifica se a pilha está cheia
bool estaCheia(pilhaEstatica *p){
  return(p->topo == N);
}

//inserindo um valor na pilha
void empilhar(pilhaEstatica *p, int valor){
  if(!estaCheia(p)){
    p->vetor[p->topo] = valor;
    p->topo++;
  }else{
    printf("Aviso: O valor %d não foi inserido pois a pilha está Cheia\n", valor);
  }
}

//retirando um valor da pilha
int desempilha(pilhaEstatica *p){
  int x = -1;
  if(!estaVazia(p)){
    x = p->vetor[p->topo-1];
    p->topo--;
  }else{
    printf("Aviso: A pilha está Vazia\n");
  }
  return(x);
}


int main(int argc, char const *argv[]) {
  setlocale(LC_ALL, "");

  pilhaEstatica pilha;

  iniciaPilha(&pilha);
  imprimePilha(&pilha);

  if(estaVazia(&pilha)){
    printf("A pilha está Vazia\n");
  }

  empilhar(&pilha, 1);
  imprimePilha(&pilha);

  for(int i = 0; i < 6; i++){
    empilhar(&pilha, i+2);
  }
  imprimePilha(&pilha);

  printf("Tamanho = %d\n", tamanhoPilha(&pilha));

  int x;
  for(x = 0; x < 2; x++){
    desempilha(&pilha);
  }
  imprimePilha(&pilha);

  return 0;
}//main
