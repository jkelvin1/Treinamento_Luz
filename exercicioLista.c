//Criando e manipulando uma lista encadeada


#include <stdio.h>
#include <stdlib.h>

typedef struct No{
    int valor;
    struct No *proximo;    
}No;

typedef struct{
    int tamanhoLista;
    No *inicio;
}Lista;

void menu(void){
    printf("\nEscolha uma opcao\n"
            "1-Inserir um elemento no inicio da lista\n"
            "2-Inserir um elemento no final da lista\n"
            "3-Deletar um elemento no inicio da lista\n"
            "4-Deletar um elemento no final da lista\n"
            "5-Deletar um elemento especifico da lista\n"
            "6-Imprimir a lista\n"
            "7-sair\n");
}

Lista *criaLista(){
    Lista *lista =(Lista *)malloc(sizeof(Lista));
    lista->inicio = NULL;
    lista->tamanhoLista = 0;

    return lista;
}

No *criaNo(){
    No *novo = (No *)malloc(sizeof(No));

    return novo;
}

void insereInicio(Lista *lista, int valor){
    No *novo = criaNo();
    novo->valor = valor;
    novo->proximo = lista->inicio;
    lista->inicio = novo;
    lista->tamanhoLista++;
}

void insereFinal(Lista *lista, int valor){
    No *novo = criaNo();
    No *no = criaNo();

    novo->valor = valor;
    novo->proximo = NULL;

    if(lista->inicio == NULL){
        lista->inicio = novo;
    }
    else{
        no = lista->inicio;
        while (no->proximo != NULL){
            no = no->proximo;
        }
        no->proximo = novo;
    }
    lista->tamanhoLista++;
}

void deleteInicio(Lista *lista){
    No *inicio = lista->inicio;
    No *remover = NULL;

    if (lista->tamanhoLista<1){
        printf("\nFalha ao remover!\n");
        
    }
    else{
        remover = lista->inicio;
        lista->inicio = remover->proximo;
    }
    if(remover == NULL){
            free(remover);
            lista->tamanhoLista--;
        }
}

void deleteFinal(Lista *lista){
    No *ultimo = lista->inicio;
    No *penultimo = lista;
    No *remover = NULL;

    if(lista->tamanhoLista < 1){
        printf("\nFalha ao remover!\n");
    }
    else{
        if(lista->inicio != NULL && ultimo->proximo == NULL){
        remover = lista->inicio;
        lista->inicio = remover->proximo;
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
            lista->tamanhoLista--;
        }
    }
}

void deleteEscolhido(Lista *lista, int valor){
    No *inicio = lista->inicio;
    No *remover = NULL;

    if(lista->tamanhoLista<1){
        printf("\nFalha ao remover!\n");
    }
    else{
        if(inicio->valor == valor ){
            remover = lista->inicio;
            lista->inicio = inicio->proximo;
        }
        else{
            while(inicio->proximo != NULL && inicio->proximo->valor != valor){
                inicio = inicio->proximo;
            }
            if(inicio->valor != NULL){
                remover = inicio->proximo;
                inicio->proximo = remover->proximo;
            }
        }
        if(remover == NULL){
            free(remover);
            lista->tamanhoLista--;
        }
    }
}

void imprimeLista(Lista *lista){
    No *inicio = lista->inicio;

    printf("\nLista Atual: \n\n");
    while(inicio != NULL){
        printf("%d ", inicio->valor);
        inicio = inicio->proximo;
    }
    printf("\n\n");
}

int main(void){
    Lista *lista = criaLista();
    int opcao, valor;

    do{
        menu();
        scanf("%d", &opcao);
        switch (opcao)
        {
            case 1:
                printf("\nDigite um valor que deseja inserir no inicio da lista: ");
                scanf("%d", &valor);
                insereInicio(lista, valor);
                imprimeLista(lista);
                break;
            case 2:
                printf("\nDigite um valor que deseja inserir no final da lista: ");
                scanf("%d", &valor);
                insereFinal(lista, valor);
                imprimeLista(lista);
                break;
            case 3:
                deleteInicio(lista);
                imprimeLista(lista);
                break;
            case 4:
                deleteFinal(lista);
                imprimeLista(lista);
                break;
            case 5:
                printf("\nDigite o valor que deseja remover da lista: ");
                scanf("%d", &valor);
                deleteEscolhido(lista, valor);
                imprimeLista(lista);
                break;
            case 6:
                imprimeLista(lista);
                break;
            case 7:
                printf("\nFinalizando\n");
                break;
            
            default:
                printf("\nOpcao Invalida!\n");
                break;
        }

    }while (opcao != 7);

    return 0;
} 

