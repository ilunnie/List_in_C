#include <stdio.h>
#include <stdlib.h>

typedef struct list {
    int value;
    struct list *proximo;
} List;

List* newIndice(List *lista, int value){
    List *novo_elemento = (List*)malloc(sizeof(List));
    novo_elemento->value = value;
    novo_elemento->proximo = NULL;
    
    if (lista == NULL) {
        return novo_elemento;
    }
    
    List *atual = lista;
    while (atual->proximo != NULL) {
        atual = atual->proximo;
    }
    atual->proximo = novo_elemento;
    
    return lista;
}

void printl(List *lista){
    printf("[");
    while (lista != NULL){
        printf("%d, ", lista->value);
        lista = lista->proximo;
    }
    printf("]\n");
}

List* getI(List *lista, int indice){
    int i;
    List *atual = lista;

    for (i = 0; i < indice; i++) {
        atual = atual->proximo;
    }

    return atual;
}

int main(){
    List *teste = NULL;

    teste = newIndice(teste, 10);
    teste = newIndice(teste, 20);
    teste = newIndice(teste, 30);

    printl(teste);
    printf("%d\n", getI(teste, 0)->value);

    return 0;
}
