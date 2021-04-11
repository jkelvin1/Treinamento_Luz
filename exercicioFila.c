//implementando fila

#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int valor;
    struct No *proximo;
}No;

typedef struct{
    int tamanhoFila;
    No *inicio;
}Fila; 

void menu(void){
    printf("\nEscolha uma opcao\n"
            "1-Inserir um elemento na fila\n"
            "2-Deletar um elemento da fila\n"
            "3-Exibir fila\n"
            "4-sair\n");
}


Fila *criaFila(){
    Fila *fila = (Fila *)malloc(sizeof(Fila));
    fila->inicio = NULL;
    fila->tamanhoFila = 0;

    return fila;
}

No *criaNo(){
    No *novo = (No *)malloc(sizeof(No));

    return novo;
}

void insereElemento(Fila *fila, int valor){
    No *novo = criaNo();
    No *no = criaNo();

    novo->valor = valor;
    novo->proximo = NULL;

    if(fila->inicio == NULL){
        fila->inicio = novo;
    }
    else{
        no = fila->inicio;
        while (no->proximo != NULL){
            no = no->proximo;
        }
        no->proximo = novo;
    }
    fila->tamanhoFila++;

}

void removeElemento(Fila *fila){
    No *inicio = fila->inicio;
    No *remover = NULL;

    if (fila->inicio == NULL){
        printf("\nFalha ao remover!\n");
        
    }
    else{
        remover = fila->inicio;
        fila->inicio = remover->proximo;
    }
    if(remover == NULL){
            free(remover);
            fila->tamanhoFila--;
        }
}

void exibeFila(Fila *fila){
    No *inicio = fila->inicio;
    printf("\nFila atual possui: \n\n");
    while(inicio != NULL){
        printf("%d ", inicio->valor);
        inicio = inicio->proximo;
    }
    printf("\n\n");

}

int main(void){
    Fila *fila = criaFila();
    int opcao, valor;

    do{
        menu();
        scanf("%d", &opcao);
        switch (opcao){
            case 1:
                printf("\nDigite um valor que deseja inserir na Fila: ");
                scanf("%d", &valor);
                insereElemento(fila,valor);
                break;
            case 2:
                removeElemento(fila);
                exibeFila(fila);
                break;
            case 3:
                exibeFila(fila);
                break;
            case 4:
                printf("\nFinalizando...\n");
                break;    
            default:
                printf("\n Opcao Invalida!\n");
                break;
        }
    }while (opcao != 4);
    
    return 0;
}