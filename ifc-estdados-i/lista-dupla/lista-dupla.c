#include <stdio.h>
#include <stdlib.h>

typedef struct sNodo{
    struct sNodo* prox;
    struct sNodo* prev;
    int dado;
} Nodo;

typedef struct{
    struct sNodo* head;
    struct sNodo* tail;
    int size;
} Lista;

// Prototipação
Nodo* criaNodo(int);
Lista* criaLista();
int listaVazia(Lista*);
int inserir(Lista*, Nodo*, int);
int remover(Lista*, Nodo*);
void trataErro(int);
void escreveLista(Lista*);

Nodo* buscar(Lista*, int);

int main(){
    Lista *minhaLista;
    minhaLista = criaLista();

    // Para inserir elementos
    trataErro(inserir(minhaLista, NULL, 10));
    trataErro(inserir(minhaLista, minhaLista->head, 15));
    trataErro(inserir(minhaLista, minhaLista->tail, 25));
    trataErro(inserir(minhaLista, NULL, 5));
    trataErro(inserir(minhaLista, minhaLista->tail, 35));
    escreveLista(minhaLista);

    // Para remover elementos
    trataErro(remover(minhaLista, minhaLista->tail));
    trataErro(remover(minhaLista, minhaLista->head));
    escreveLista(minhaLista);
    trataErro(remover(minhaLista, NULL));
    escreveLista(minhaLista);
    trataErro(remover(minhaLista, minhaLista->head));
    escreveLista(minhaLista);
    trataErro(remover(minhaLista, minhaLista->head));
    escreveLista(minhaLista);
    trataErro(remover(minhaLista, minhaLista->head));
    escreveLista(minhaLista);
    trataErro(remover(minhaLista, NULL));
    escreveLista(minhaLista);
    trataErro(remover(minhaLista, NULL));
}

Nodo* criaNodo(int dado){
    Nodo* novo;
    novo = (Nodo*) malloc(sizeof(Nodo));
    if (novo != NULL){
        novo->dado = dado;
        novo->prox = NULL;
        novo->prev = NULL;
    }

    return novo;
}

Lista* criaLista(){
    Lista *lista;
    lista = (Lista*) malloc(sizeof(Lista));
    if (lista != NULL){
        lista->head = NULL;
        lista->tail = NULL;
        lista->size = 0;
    }
    return lista;
}

int listaVazia(Lista *lista){
    if (lista->size == 0)
        return 1;

    return 0;
}

void trataErro(int erro){
    if (erro == -1)
        printf("\nLista vazia!\n");
    else if (erro == -2)
        printf("\nFim da lista!\n");
    else if (erro == -3)
        printf("\nIndique o elemento pivo, a lista nao esta vazia!\n");
}

int inserir(Lista* lista, Nodo* elemento_pivo, int dado){
	Nodo *novo_elemento;
	novo_elemento = criaNodo(dado);

	if ((elemento_pivo == NULL) && (!listaVazia(lista))) 
        return -3;
    
    if(listaVazia(lista)) {
        lista->head = novo_elemento;
        lista->tail = novo_elemento;
    } else {
        novo_elemento->prox = elemento_pivo->prox;
        novo_elemento->prev = elemento_pivo;
        if(elemento_pivo->prox == NULL)
            lista->tail = novo_elemento;
        else
            elemento_pivo->prox->prev = novo_elemento;
        elemento_pivo->prox = novo_elemento;
    }

	lista->size++;
}

int remover(Lista *lista, Nodo *elemento){
	if ((elemento != NULL) && (lista->size != 0)) {
        if(elemento == lista->head) {
            lista->head = elemento->prox;
            if (lista->head == NULL)
                lista->tail = NULL;
            else
                elemento->prox->prev = NULL;
        } else {
            elemento->prev->prox = elemento->prox;
            if(elemento->prox == NULL)
                lista->tail = elemento->prev;
            else
                elemento->prox->prev = elemento->prev;
        }
	free(elemento);
	lista->size--;
    }		
}

void escreveLista(Lista* lista){
    Nodo *nodo;

    if (listaVazia(lista))
         trataErro(-1);
    else {
        printf("\nElementos da lista: \n");
        nodo = lista->head;
        while (nodo!=NULL){
            printf("%i, ", nodo->dado);
            nodo = nodo->prox;
        }
    }
}