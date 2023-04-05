#include <stdio.h>
#include <stdlib.h>

// Tipos aceitados pela lista
typedef enum {
    INT,
    DOUBLE,
    CHAR,
    // Adicione outros tipos aqui
} DataType;

// Estrutura da lista
typedef struct list {
    void *value;
    DataType type;
    struct list *next;
} List;


// Adiciona um novo indice
List* newIndice(List *lista, void *value, DataType type){
    List *novo_elemento = (List*)malloc(sizeof(List));
    novo_elemento->value = value;
    novo_elemento->type = type;
    novo_elemento->next = NULL;
    
    if (lista == NULL) {
        return novo_elemento;
    }
    
    List *atual = lista;
    while (atual->next != NULL) {
        atual = atual->next;
    }
    atual->next = novo_elemento;
    
    return lista;
}

// Mostra a lista no console
void printl(List *lista){
    printf("[");
    while (lista != NULL){
        switch (lista->type) {
            case INT:
                printf("%d", *(int*)lista->value);
                break;
            case DOUBLE:
                printf("%lf", *(double*)lista->value);
                break;
            case CHAR:
                printf("%c", *(char*)lista->value);
                break;
            // adicione outros tipos aqui
            default:
                printf("?");
                break;
        }
        lista = lista->next;
        if (lista != NULL) {
            printf(", ");
        }
    }
    printf("]\n");
}

// retorna o valor de um indice
void* getIndex(List *lista, int indice){
    int i;
    List *atual = lista;

    for (i = 0; i < indice; i++) {
        atual = atual->next;
    }

	return atual->value;
}

// main para testar as funções
int main(){
    List *teste = NULL;
    int a = 10;
    double b = 20.5;
    char c = 'a';
    
    teste = newIndice(teste, &a, INT);
    teste = newIndice(teste, &b, DOUBLE);
    teste = newIndice(teste, &c, CHAR);
    
    printl(teste);
    printf("%d\n", *(int*) getIndex(teste, 0));
    printf("%lf\n", *(double*) getIndex(teste, 1));
    printf("%c\n", *(char*) getIndex(teste, 2));
    
    return 0;
}
