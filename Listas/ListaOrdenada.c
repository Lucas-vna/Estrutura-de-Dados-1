/**
* @file ListaOrdenada.c
* @author Luiz Gustavo Pasini Abudi
* @date 14-07-2021
* @brief Aula 04 - Listas Ordenadas

*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <locale.h>


//========================================================
typedef struct NoLista* PtrNoLista;

typedef struct NoLista {

    int chave;
    PtrNoLista proximo;

} NoLista;

typedef struct {

    PtrNoLista inicio;
    int tamanho;

}ListaDinamica;


//========================================================
//inicai a lista
void iniciaListaDinamica (ListaDinamica *lista){
    //inicio
    lista->inicio = NULL;
    //tamanho
    lista->tamanho = 0;
}

//========================================================

// esta vazia
bool estaVaziaListaDinamica(ListaDinamica *lista){
    return (lista->tamanho == 0);
}

//========================================================

//tamanho da lista
int tamanhoListaDinamica(ListaDinamica *lista){
    return (lista->tamanho);
}

//========================================================

//imprimir lista
void imprimirListaDinamica(ListaDinamica *lista){
    printf("Lista = {");

    PtrNoLista percorre;
    for (percorre = lista->inicio; percorre != NULL; percorre = percorre->proximo){
        printf("%d ", percorre->chave);
    }

    printf("}\n");
}

//========================================================

void inserirListaDinamica(ListaDinamica *lista, int elemento){
    //criar o ponteiro
    PtrNoLista novo;
    //alocar a memoria para o novo
    novo = (PtrNoLista)malloc(sizeof(NoLista));
    //copia o valor do elemento para chave do Novo
    novo->chave = elemento;

    if(estaVaziaListaDinamica(lista) || elemento < lista->inicio->chave){
        //proximo do novo aponta para nulo(inicio)
        novo->proximo = lista->inicio;
        //inicio aponta para o novo no
        lista->inicio = novo;

    }else{

        PtrNoLista aux;
        //percorrer e encontrar o ponto de insercao
        aux = lista->inicio;
        while(aux->proximo != NULL && elemento > aux->proximo->chave){
            aux = aux->proximo;
        }
        //proximo Novo aponta proximo aux
        novo->proximo = aux->proximo;
        //proximo do aux aponta para o novo
        aux->proximo = novo;
    }
    //incrementa o contador
    lista->tamanho++;
}

//========================================================

bool pesquisaListaDinamica(ListaDinamica *lista, int consulta){
    PtrNoLista percorre;
    for (percorre = lista->inicio; percorre != NULL; percorre = percorre->proximo){
        if(consulta == percorre->chave){
            return (true);
        }
    }
    return (false);
}

//========================================================

bool pesquisaListaDinamica2(ListaDinamica *lista, int consulta)
{
    if(estaVaziaListaDinamica(lista)){
        return (false);
    }
    PtrNoLista percorre = lista->inicio;
    while (percorre != NULL && consulta > percorre->chave){
        percorre = percorre->proximo;
    }

    if(percorre == NULL || percorre->chave > consulta){
        return false;
    }
    return true;
}

//========================================================

int main()
{
    setlocale(LC_ALL, "");

    ListaDinamica lista;

    iniciaListaDinamica(&lista);

    inserirListaDinamica(&lista, 5);
    imprimirListaDinamica(&lista);

    inserirListaDinamica(&lista, 0);
    imprimirListaDinamica(&lista);

    inserirListaDinamica(&lista, 3);
    imprimirListaDinamica(&lista);

    inserirListaDinamica(&lista, -99);
    imprimirListaDinamica(&lista);

    inserirListaDinamica(&lista, 99);
    imprimirListaDinamica(&lista);

    if(estaVaziaListaDinamica(&lista)){
        printf("Lista Vazia\n");
    }else{
        printf("Tem elemento\n");
    }

    //elemento que tem na lista
    if(pesquisaListaDinamica2(&lista, 99)){
        printf("Elemento encontrado\n");
    }else{
        printf("Não Achou\n");
    }

    //elemento que nao tem na lista
    if(pesquisaListaDinamica2(&lista, 1)){
        printf("Elemento encontrado\n");
    }else{
        printf("Não Achou\n");
    }


    printf("Tamanho = %d", tamanhoListaDinamica(&lista));

    return 0;
} //main
