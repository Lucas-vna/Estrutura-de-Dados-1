/**
* @file pilhaDinamica.c
* @author Luiz Gustavo Pasini Abudi
* @date 06-07-2021
* @brief Pilha Dinamica

*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <stdbool.h>

// NoPilha* -> *PtrNoPilha
typedef struct NoPilha *PtrNoPilha;

//NoPilha
typedef struct NoPilha{
  //int x (chave)
  int x;
  //ptr -> proximo
  PtrNoPilha proximo;
} NoPilha;

//Pilha Dinamica
typedef struct{
  //ponteiro para o elemento mais recente
  PtrNoPilha topo;
  //contagem do nomero de elemetos dentro da pilha
  int qntElementos;

} pilhaDinamica;

//Inicializar
void iniciaPilhaDinamica(pilhaDinamica *p){
  //iniciando o ponteiro do topo para nulo
  p->topo = NULL;
  //iniciar o contador para zero
  p->qntElementos = 0;

}//void inicializar

int tamanhoPilhaDinamica(pilhaDinamica *p){
  return(p->qntElementos);
}// fun��o tamanho da pilha

bool estaVaziaPilhaDinamica(pilhaDinamica *p){
  //1. qnt de elementos == 0
  return(p->qntElementos == 0);
  //2. topo == NULL
  /*
  return(p->topo == NULL)
  */
}// fun��o estaVazia

//inserir elementos
void empilhaPilhaDinamica(pilhaDinamica *p, int x){
  //1. Inser�ao em pilha vazia

    //criar novo n�, alorcar memoria
    PtrNoPilha aux;
    aux = (PtrNoPilha)malloc(sizeof(NoPilha));
    //copiar dado para o novo n�
    aux->x = x;
    //proximo do novo n�, aponta para o topo (nulo)
    aux->proximo = p->topo;
    //topo aponta para o novo n�
    p->topo = aux;
    //contador incrementa
    p->qntElementos++;
}

//Inser�ao pilha Dinamica
void imprimePilhaDinamica(pilhaDinamica *p){
  printf("Pilha = {");
  //come�ar no topo
  //pegar o proximo do n�
  //ate chegar no NULL
  PtrNoPilha temp;
  for(temp = p->topo; temp != NULL; temp = temp->proximo){
    printf("%d ", temp->x);
  }//for
  printf("}\n");
}

//remover elementos da pilha
int desempilhaPilhaDinamica(pilhaDinamica *p){
  int ret = -1;
  //se nao estiver vazia = remover
  if(!estaVaziaPilhaDinamica(p)){
    //Criar um ptr Auxiliar
    PtrNoPilha aux;
    //aux recebe valor do topo
    aux = p->topo;
    //copiar o valor a ser retornado
    ret = aux->x;
    //atualizar os ponteiros
    p->topo = p->topo->proximo;
    //desalocar a memoria
    free(aux);
    //decrementa contador
    p->qntElementos--;
  }else{
    printf("N�o foi poss�vel remover\n");
  }//else

  return(ret);
}

void destroiPilhaDinamica(pilhaDinamica *p) {
  printf("@Destroying stack!\n");
  PtrNoPilha remover;
  while(p->topo!= NULL) {
    remover = p->topo;
    p->topo = p->topo->proximo;
    free(remover);
  }
}


int main(int argc, char const *argv[]) {
  setlocale(LC_ALL, "");

  pilhaDinamica pilha;

  //iniciar a pilha Dinamica
  iniciaPilhaDinamica(&pilha);
  imprimePilhaDinamica(&pilha);

  for(int i = 0; i < 5; i++){
    empilhaPilhaDinamica(&pilha, i+1);
    imprimePilhaDinamica(&pilha);
  }

  int ret;
  for(int i = 0; i < 6; i++){
    ret = desempilhaPilhaDinamica(&pilha);
    imprimePilhaDinamica(&pilha);
  }

  destroiPilhaDinamica(&pilha);

  //Verificar se a pilha ets� Vazia
  if(estaVaziaPilhaDinamica(&pilha)){
    printf("A pilha est� vazia\n");
  }else{
    printf("A pilha n�o est� vazia\n");
  }

  printf("Tamanho = %d\n", tamanhoPilhaDinamica(&pilha));


  return 0;
}
