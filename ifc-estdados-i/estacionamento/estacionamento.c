#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct sNodo{
    struct sNodo* prox;
    struct sNodo* prev;
    char dado[9];
} Nodo;

typedef struct{
    struct sNodo* head;
    struct sNodo* tail;
    int size;
} Lista;

// Prototipação
Nodo* criaNodo(char[9]);
Lista* criaLista();
int listaVazia(Lista*);
int inserir(Lista*, Nodo*, char[9]);
int remover(Lista*, Nodo*);
void trataErro(char);
void escreveLista(Lista*);
void insereNaFila(Lista*, char[9]);
void removeDaFila(Lista*);
void chegadaEstacionamento(Lista*, Lista*, char[9]);
void partidaEstacionamento(Lista*, Lista*, char[9]);
void organizaCarros(Lista*, Lista*, char, char[9]);
void girarEstacionamento(Lista*);
Nodo* buscar(Lista*, char[9]);

int main(){
    Lista *estacionamento, *espera;
    estacionamento = criaLista();
    espera = criaLista();

    char comando[1], placa[9];
  
    // do{
    //     printf("Digite 'C' para chegada ou 'P' para partida (digite 0 para encerrar):");
    //     scanf(comando);
    //     if(comando != '0') {
    //         printf("Informe a placa do veículo:");
    //         scanf(placa);
    //     }
    //     organizaCarros(estacionamento, espera, comando, placa);
    // } while(comando != '0');
    organizaCarros(estacionamento, espera, 'C', "ABC-0001");
    organizaCarros(estacionamento, espera, 'C', "ABC-0101");
    organizaCarros(estacionamento, espera, 'C', "ABC-0002");
    organizaCarros(estacionamento, espera, 'C', "ABC-0202");
    organizaCarros(estacionamento, espera, 'C', "ABC-0003");
    organizaCarros(estacionamento, espera, 'P', "ABC-0101");
    organizaCarros(estacionamento, espera, 'C', "ABC-0303");
    organizaCarros(estacionamento, espera, 'C', "ABC-0004");
    organizaCarros(estacionamento, espera, 'P', "ABC-0303");
    organizaCarros(estacionamento, espera, 'C', "ABC-0404");
    organizaCarros(estacionamento, espera, 'P', "ABC-0404");
    organizaCarros(estacionamento, espera, 'C', "ABC-0005");
    organizaCarros(estacionamento, espera, 'C', "ABC-0505");
    organizaCarros(estacionamento, espera, 'C', "ABC-0006");
    organizaCarros(estacionamento, espera, 'P', "ABC-0002");
    organizaCarros(estacionamento, espera, 'C', "ABC-0606");
    organizaCarros(estacionamento, espera, 'C', "ABC-0007");
    organizaCarros(estacionamento, espera, 'C', "ABC-0707");
    organizaCarros(estacionamento, espera, 'C', "ABC-0008");
    organizaCarros(estacionamento, espera, 'C', "ABC-0808");
    organizaCarros(estacionamento, espera, 'C', "ABC-0009");
    organizaCarros(estacionamento, espera, 'C', "ABC-0909");
    organizaCarros(estacionamento, espera, 'P', "ABC-0003");
    organizaCarros(estacionamento, espera, 'P', "ABC-0606");
    organizaCarros(estacionamento, espera, 'P', "ABC-0008");
}

Nodo* criaNodo(char dado[9]){
    Nodo* novo;
    novo = (Nodo*) malloc(sizeof(Nodo));
    if (novo != NULL){
        strcpy(novo->dado, dado);
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

void trataErro(char erro){
    if (erro == -1)
        printf("\nLista vazia!\n");
    else if (erro == -2)
        printf("\nFim da lista!\n");
    else if (erro == -3)
        printf("\nIndique o elemento pivo, a lista nao esta vazia!\n");
}

int inserir(Lista* lista, Nodo* elemento_pivo, char dado[9]){
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
        printf("\nVeiculos no estacionamento: \n");
        nodo = lista->head;
        while (nodo!=NULL){
            printf("| %s |", nodo->dado);
            nodo = nodo->prox;
        }
    }
    printf("\n");
}
void insereNaFila(Lista* fila, char dado[9]){
    inserir(fila, fila->tail, dado);
}

void removeDaFila(Lista* fila){
    trataErro(remover(fila, fila->head));
}

void organizaCarros(Lista* principal, Lista* secundaria, char acao, char placaVeic[9]){
    if(acao == 'C'){
        chegadaEstacionamento(principal, secundaria, placaVeic);
    }
    if(acao == 'P'){
        partidaEstacionamento(principal, secundaria, placaVeic);
    }
}

void chegadaEstacionamento(Lista* principal, Lista* secundaria, char placaVeic[9]){
    if(principal->size < 10){
        printf("\n\nHá vaga no estacionamento p/ o veiculo %s!\n", placaVeic);
        insereNaFila(principal, placaVeic);
        escreveLista(principal);
    }else {
        printf("\nNão há vaga no estacionamento p/ o veiculo %s, aguarde na fila de espera!\n", placaVeic);
        insereNaFila(secundaria, placaVeic);
    }
}

void partidaEstacionamento(Lista* principal, Lista* secundaria,  char placaVeic[9]){
    Nodo* veiculo;
    Nodo* primeiro;
    int contMoves = 1;
    veiculo = buscar(principal, placaVeic);    
    if (veiculo != NULL) {
        primeiro = principal->head;
        if (veiculo != principal->head) {
            while(veiculo != principal->head){
                girarEstacionamento(principal);
                contMoves++;
            }
        }
        if(veiculo == principal->head){
            //removePrincipal(principal, secundaria, primeiro);
            removeDaFila(principal);
            while(primeiro != principal->head){
                girarEstacionamento(principal);
            }
            if(!listaVazia(secundaria)){
                insereNaFila(principal, secundaria->head->dado);
                removeDaFila(secundaria);
            }
        }
        printf("\n\nO veiculo com a placa %s saiu com %i movimentos!\n\n", placaVeic, contMoves);  
    } else{
        veiculo = buscar(secundaria, placaVeic);
        if(veiculo != NULL){
            primeiro = secundaria->head;
            if(veiculo != secundaria->head){
                while(veiculo != secundaria->head) {
                    girarEstacionamento(secundaria);
                }
            }
            if(veiculo == secundaria->head){
                removeDaFila(secundaria);           
            }
            while(primeiro != secundaria->head){
            girarEstacionamento(secundaria);
        }
        } else{
            printf("\nO veiculo informado nao esta nem no estacionamento, nem na fila!\n");
        }
    }
    escreveLista(principal);
    printf("\n");
    
}

void girarEstacionamento(Lista* fila){
    Nodo* vagaAux;
    vagaAux = fila->head;
    removeDaFila(fila);
    insereNaFila(fila, vagaAux->dado);
}

Nodo* buscar(Lista* lista, char dado[9]){
    Nodo* nodo;
    nodo = lista->head;
    while(nodo!= NULL){
        if(strcmp(nodo->dado, dado) == 0)
            return nodo;
        nodo = nodo->prox;
    }
    return NULL;
}

// Nodo* buscarMax(Lista* lista){
//     Nodo *nodo, *nodoMax;
//     if(lista->size == 0)
//         return NULL;
    
//     nodo = lista->head;
//     nodoMax = nodo;
//     int valor = nodo->dado;
//     while (nodo != NULL){
//         if(nodo->dado > valor){
//             valor = nodo->dado;
//             nodoMax = nodo;
//         }
//         nodo = nodo->prox;
//     }
//     return nodoMax;    
// }