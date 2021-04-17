#include <iostream>
#include <algorithm>

using namespace std;

class No{
    private:
        int valor;
        No *prox;
    public:
        No();
        No(int);
        void setValor(int);
        int getValor();
        void setProx(No *n); 
        No* getProx(); 
};

class Lista{
    protected:
        Lista();
        Lista(int);
        void insereInicio(int valor);
        void insereFinal(int valor);
        void removeInicio();
        void removeFinal();
        virtual void exibe();
        void setInicio(No *n);
        No* getInicio();
        void setFinal(No *n);
        No* getFinal();
    private:
        No *inicio;
        No *fim;
};

class Pilha:public Lista{
    public:
        Pilha();
        void inserePilha(int);
        void removePilha();
        void exibePilha();
};

class Fila:public Lista{
    public:
        Fila();
        void insereFila(int);
        void removeFila();
        void exibeFila();
};

/* Trabalhando com o Nó*/

No::No(){
    setProx(NULL);
    setValor(0);
}
No::No(int valor){
    setProx(NULL);
    setValor(valor);
}
int No::getValor(){
    return(valor);
}   
void No::setValor(int v){
    valor = v;
}
No *No::getProx(){
    return prox;
}
void No::setProx(No *n){
    prox = n;
}

/*Trabalhando com Lista*/
Lista::Lista(){
    setInicio(NULL);
    setFinal(NULL);
}
void Lista::insereInicio(int valor){
    No *novo = new No(valor);
    if(fim == NULL){
        fim = novo;
    }
    novo->setValor(valor);
    novo->setProx(inicio);
    inicio = novo;
}
void Lista::insereFinal(int valor){
    No *novo = new No(valor);
    No *ponteiro = fim;
    if (inicio == NULL){
        inicio = novo;
    }
    else{
        ponteiro->setProx(novo);
    }
    novo->setProx(NULL);        
    fim = novo;
}
void Lista::removeInicio(){
    if(inicio == NULL){
        cout << "Lista Vazia" << endl;
    }
    else{
        if (inicio->getProx() == NULL){
            fim = NULL;
        }
        No *ponteiro = inicio;
        inicio = ponteiro->getProx();
        free(ponteiro);
        ponteiro = NULL;
    }
}
void Lista::removeFinal(){
    No *ponteiro = inicio;

    if (inicio == NULL){
        cout << "Lista vazia" << endl;
    }
    else{
        while (ponteiro->getProx() != fim){
            ponteiro = ponteiro->getProx();
        }
        if(inicio->getProx() == NULL){
            inicio = NULL;
        }
        free(fim);
        fim = ponteiro;
    }
}
void Lista::exibe(){
    No *ponteiro;
    if(inicio == NULL){
        cout << "A estrutura esta vazia" << endl;
    }
    else{
        ponteiro = inicio;
        cout << "A estrutura e" << endl;
        while (ponteiro != fim->getProx()){
            cout << ponteiro->getValor() << " ";
            ponteiro = ponteiro->getProx();
        }
    }
    cout << endl;
}
No* Lista::getInicio(){
    return inicio;
}
void Lista::setInicio(No *n){
    inicio = n;
}
No* Lista::getFinal(){
    return fim;
}
void Lista::setFinal(No *n){
    fim = n;
}

/*Trabalhando com Pilha*/
Pilha::Pilha(){
    setInicio(NULL);
    setFinal(NULL);
}
void Pilha::inserePilha(int valor){
    insereInicio(valor);
}
void Pilha::removePilha(){
    removeInicio();
}
void Pilha::exibePilha(){
    exibe();
}

/*Trabalhando com fila*/
Fila::Fila(){
    setInicio(NULL);
    setFinal(NULL);
}
void Fila::insereFila(int valor){
    insereFinal(valor);
}
void Fila::removeFila(){
    removeInicio();
}
void Fila::exibeFila(){
    exibe();
}



int main(){
    int opcao, valor;
    Pilha *pilha = new Pilha();
    Fila *fila = new Fila();
    
    do{
        cout << endl;
        cout << "1 - Inserir na pilha" << endl;
        cout << "2 - Remover da pilha" << endl;
        cout << "3 - Inserir na fila" << endl;
        cout << "4 - Remover da fila" << endl;
        cout << "5 - Sair" << endl;
        cin >> opcao;

        switch (opcao){
            case 1:
                cout << "Digite um valor para inserir na pilha: ";
                cin >> valor;
                pilha->inserePilha(valor);
                pilha->exibePilha();
                break;
            case 2:
                pilha->removePilha();
                pilha->exibePilha();
                break;
            case 3:
                cout << "Digite um valor para inserir na fila: ";
                cin >> valor;
                fila->insereFila(valor);
                fila->exibeFila();
                break;
            case 4:
                fila->removeFila();
                fila->exibeFila();
                break;                    
            case 5:
                cout<<"Finalizando"<<endl;
                break;                    
            default:
                cout << "Opcao invalida!"<<endl;
                break;
        }
    }while(opcao != 5);
    
    return 0;
}