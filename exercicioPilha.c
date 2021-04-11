//implementando Pilha

#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int valor;
    struct No *proximo;
}No;

typedef struct{
    int tamanhoPilha;
    No *inicio;
}Pilha; 

void menu(void){
    printf("\nEscolha uma opcao\n"
            "1-Inserir um elemento na pilha\n"
            "2-Deletar um elemento da pilha\n"
            "3-Exibir Pilha\n"
            "4-sair\n");
}

Pilha *criaPilha(){
    Pilha *pilha = (Pilha *)malloc(sizeof(Pilha));
    pilha->inicio = NULL;
    pilha->tamanhoPilha = 0;

    return pilha;
}

No *criaNo(){
    No *novo = (No *)malloc(sizeof(No));

    return novo;
}

void insereElemento(Pilha *pilha, int valor){
    No *novo = criaNo();
    No *no = criaNo();

    novo->valor = valor;
    novo->proximo = NULL;

    if(pilha->inicio == NULL){
        pilha->inicio = novo;
    }
    else{
        no = pilha->inicio;
        while (no->proximo != NULL){
            no = no->proximo;
        }
        no->proximo = novo;
    }
    pilha->tamanhoPilha++;
    
}

void removeElemento(Pilha *pilha){
    No *ultimo = pilha->inicio;
    No *penultimo = pilha;
    No *remover = NULL;

    if(pilha->inicio == NULL){
        printf("\nFalha ao remover!\n");
    }
    else{
        if(pilha->inicio != NULL && ultimo->proximo == NULL){
        remover = pilha->inicio;
        pilha->inicio = remover->proximo;
        }
        else{
            while (ultimo->proximo != NULL){
                penultimo = ultimo;
                ultimo = ultimo->proximo;
            }
            penultimo->proximo = remover;
        }    
        if(remover == NULL){
            free(remover);
            pilha->tamanhoPilha--;
        }
    }
}

void exibePilha(Pilha *pilha){
    No *inicio = pilha->inicio;
    printf("\nPilha atual: \n\n");
    while(inicio != NULL){
        printf("%d ", inicio->valor);
        inicio = inicio->proximo;
    }
    printf("\n\n");

}

int main(void){
    Pilha *pilha = criaPilha();
    int opcao, valor;

    do{
        menu();
        scanf("%d", &opcao);
        switch (opcao){
            case 1:
                printf("\nDigite um valor que deseja inserir na Pilha: ");
                scanf("%d", &valor);
                insereElemento(pilha,valor);
                break;
            case 2:
                removeElemento(pilha);
                exibePilha(pilha);
                break;
            case 3:
                exibePilha(pilha);
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