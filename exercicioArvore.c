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

No *removerElemento(No *raiz, int chave){
    if(raiz == NULL){
        printf("\nElemento nao encontrado!\n");
        return NULL;
    }
    else{
        if(raiz->conteudo == chave){
            if(raiz->esquerda == NULL && raiz->direita == NULL){// remove folha
                free(raiz);
                return NULL;
            }
            else if(raiz->esquerda == NULL || raiz->direita == NULL){//remove com um filho
                No *aux;
                if(raiz->esquerda != NULL){
                    aux = raiz->esquerda;
                }
                else{
                    aux = raiz->direita;
                }
                free(raiz);
                return aux;
            }
            else{
                No *aux = raiz->direita;
                while(aux->esquerda != NULL ){
                    aux = aux->esquerda;
                }
                raiz->conteudo = aux ->conteudo;
                aux->conteudo = chave;
                raiz->direita = removerElemento(raiz->direita, chave);
                return raiz;
            }
        }
        else{
            if(chave < raiz->conteudo){
                raiz->esquerda = removerElemento(raiz->esquerda, chave);
            }
            else{
                raiz->direita = removerElemento(raiz->direita, chave);
            }
            return raiz;
        }
    }
}

Arvore *removerArvore(Arvore *arvore){
    free(arvore);
    arvore = criaArvore();
    return arvore;
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
                removerElemento(arvore->raiz, valor);
                break;
            case 3:
                removerArvore(arvore);
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