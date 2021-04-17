//Criando e manipulando uma Arvore Binaria;


#include<stdio.h>
#include<stdlib.h>

typedef struct no{
    int conteudo;
    struct no *esquerda, *direita; 
}No;

typedef struct{
    No *raiz;
}Arvore;

No *criaNo(int valor){
    No *novo = (No *)malloc(sizeof(No));
        novo->conteudo = valor;
        novo->esquerda = NULL;
        novo->direita = NULL;

    return novo;
}

Arvore *criaArvore(){
    Arvore *arvore = (Arvore *)malloc(sizeof(Arvore));
    arvore->raiz = NULL;
    
    return arvore;
}
 
void menu (void){
    printf("\n\nEscolha uma opcao\n"
            "1-Inserir um elemento na Arvore\n"
            "2-Remover elemento da Arvore\n"
            "3-Remover a arvore\n"
            "4-Exibir Arvore Pre-ordem\n"
            "5-Exibir Arvore Ordem\n"
            "6-Exibir Arvore Pos-ordem\n"
            "7-Sair\n");
}

void inserirEsquerda(No *no, int valor){
    if(no->esquerda == NULL){
        No *novo = criaNo(valor);
        no->esquerda = novo;
    }
    else{
        if(valor < no->esquerda->conteudo ){
            inserirEsquerda(no->esquerda, valor);
        }
        if(valor > no->esquerda->conteudo ){
            inserirDireita(no->esquerda, valor);
        }
    }
}

void inserirDireita(No *no, int valor){
    if(no->direita == NULL){
        No *novo = criaNo(valor);
        no->direita = novo;
    }
    else{
        if(valor > no->direita->conteudo){
            inserirDireita(no->direita, valor);
        }
        if(valor < no->direita->conteudo){
            inserirEsquerda(no->direita,valor);
        }
    }
}

void inserirElemento(Arvore *arvore, int valor){
    if(arvore->raiz == NULL){
        No *novo = criaNo(valor);
        arvore->raiz = novo;        
    }
    else{
        if(valor < arvore->raiz->conteudo){
            inserirEsquerda(arvore->raiz, valor);
        }
        if(valor > arvore->raiz->conteudo){
            inserirDireita(arvore->raiz, valor);
        }
    }
}

No *removeNo(No *atual){
    No *aux, *aux2;
    if(atual->esquerda == NULL){
        aux2 = atual->direita;
        free(atual);
        return aux2;
    }
    aux = atual;
    aux2 = atual->esquerda;
    while (aux2->direita != NULL){
        aux = aux2;
        aux2 = aux2->direita;
    }
    if(aux != atual){
        aux->direita = aux2->esquerda;
        aux2->esquerda = atual->esquerda;
    }
    aux2->direita = atual->direita;
    free(atual);
    return aux2;
}

int removerElemento(Arvore *arvore, int chave){
    if(arvore == NULL && arvore->raiz == NULL){
        return 0;
    }
    No *anterior = NULL;
    No *atual = arvore->raiz;
    while(atual != NULL){
        if(atual->conteudo == chave){
            if(atual == arvore->raiz){
                arvore->raiz = removeNo(atual);
            }
            else if(anterior->direita == atual){
                anterior->direita = removeNo(atual);
            }
            else{
                anterior->esquerda = removeNo(atual);
            }
            return 1;
        }
        anterior = atual;
        if (chave > atual->conteudo){
            atual = atual->direita;
        }else{
            atual = atual->esquerda;
        }
    }    
}

void removerArvore(No *raiz){
    if(raiz != NULL){
        removerArvore(raiz->esquerda);
        removerArvore(raiz->direita);
        free(raiz);
    }
}

void printArvorePre(No *raiz){
    if(raiz != NULL){
        printf("%d ", raiz->conteudo);
        printArvorePre(raiz->esquerda);
        printArvorePre(raiz->direita);
    }
    
}

void printArvoreOrdem(No *raiz){
    if(raiz != NULL){
        printArvoreOrdem(raiz->esquerda);
        printf("%d ", raiz->conteudo);
        printArvoreOrdem(raiz->direita);
    }
}

void printArvorePos(No *raiz){
    if(raiz != NULL){
        printArvorePos(raiz->esquerda);
        printArvorePos(raiz->direita);
        printf("%d ", raiz->conteudo);

    }
}

int main(void){
    Arvore *arvore = criaArvore();
    int opcao, valor;
    

     do{
         menu();
         scanf("%d", &opcao);
         switch (opcao){
            case 1:
                printf("\nInserir um elemento na arvore: \n");
                scanf("%d", &valor);
                inserirElemento(arvore, valor);
                break;
            case 2:
                printf("\nDigite o elemento que deseja remover: \n");
                scanf("%d", &valor);
                removerElemento(arvore, valor); //
                break;
            case 3:
                removerArvore(arvore->raiz);
                break;
            case 4:
                printf("\nA arvore: \n");
                printArvorePre(arvore->raiz);
                break;
            case 5:
                printf("\nA arvore: \n");
                printArvoreOrdem(arvore->raiz);
                break;
            case 6:
                printf("\nA arvore: \n");
                printArvorePos(arvore->raiz);
                break;
            case 7:
                printf("\nFinalizando...\n");
                break;
            default:
                printf("\nOpcao invalida!\n");
                break;
         }

     }while(opcao != 7);

     return 0;
}