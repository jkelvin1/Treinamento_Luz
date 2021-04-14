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
    public:
        Lista();
        Lista(int);
        void insereInicio(int valor);
        void insereFinal(int valor);
        void removeInicio();
        void removeFinal();
        void setInicio(No *n);
        No* getInicio();
        void setFinal(No *n);
        No* getFinal();
        virtual void exibe();
    private:
        No *inicio;
        No *fim;
};

class Pilha:public Lista{
    public:
        void insereInicio(int);
        void removePilha();
        void exibe();
        Pilha();
        
};

class Fila:public Lista{
    public:
        void insereFinal(int);
        void removeFila();
        void exibe();
        Fila();
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
void Lista::exibe(){
    struct No *ponteiro;
    if(inicio == NULL){
        cout << "Lista esta vazia" << endl;
    }
    else{
        ponteiro = inicio;
        cout << "A lista e" << endl;
        while (ponteiro != fim->getProx()){
            cout << ponteiro->getValor() << " ";
            ponteiro = ponteiro->getProx();
        }
    }
    cout << endl;
}
Lista::Lista(){
    setInicio(NULL);
    setFinal(NULL);
}
void Lista::insereInicio(int valor){
    No *novo = new No();
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
void Pilha::insereInicio(int valor){
    No *novo = new No(valor);
    
    novo->setValor(valor);
    novo->setProx(getInicio());
    setInicio(novo);
}
void Pilha::exibe(){
    Pilha *aux = new Pilha;
    if(getInicio() == NULL){
        cout << "A pilha esta vazia" << endl;
    }
    else{
        cout << "A Pilha" << endl;
        while (getInicio() != NULL){
            cout<< getInicio()->getValor() <<" ";
            aux->insereInicio((getInicio())->getValor());
		    removeInicio();
        }   
         while (aux->getInicio()!=NULL) {
         insereInicio((aux->getInicio())->getValor());
		 aux->removeInicio();
      }
    }
    delete aux;
    cout << endl;
}
Pilha::Pilha(){
    setInicio(NULL);
    setFinal(NULL);
}
void Pilha::removePilha(){
    removeInicio();
}

/*Trabalhando com fila*/
void Fila::insereFinal(int valor){
    No *novo = new No(valor);
    No *ponteiro = getFinal();

    if(getInicio() == NULL){
        setInicio(novo);
    }
    else{
        ponteiro->setProx(novo);
    }
    novo->setProx(NULL);
    setFinal(novo);
}
void Fila::exibe(){
    Fila *aux = new Fila;
    if(getInicio() == NULL){
        cout << " Fila vazia" << endl;
    }
    else{
        while (getInicio() != NULL){
            cout<< getInicio()->getValor() <<" ";
            aux->insereFinal((getInicio())->getValor());
		    removeInicio();
        }
        while(aux->getInicio() !=  NULL){
            insereFinal((aux->getInicio())->getValor());
		    aux->removeInicio();
        }
    }
    delete aux;
    cout << endl;
}
Fila::Fila(){
    setInicio(NULL);
    setFinal(NULL);
}
void Fila::removeFila(){
    removeInicio();
}

int main(){
    int opcao, valor;
    Lista *lista;
    lista = new Lista();

    Pilha *pilha;
    pilha = new Pilha();

    Fila *fila;
    fila = new Fila();
    
    
    do{
        cout << endl;
        cout << "1 - Inserir no inicio da lista" << endl;
        cout << "2 - Inserir no final da lista" << endl;
        cout << "3 - Remover do Inicio da lista" << endl;
        cout << "4 - Remover do final da lista" << endl;
        cout << "5 - Inserir na pilha" << endl;
        cout << "6 - Remover da pilha" << endl;
        cout << "7 - Inserir na fila" << endl;
        cout << "8 - Remover da fila" << endl;
        cout << "9 - Sair" << endl;
        cin >> opcao;

        switch (opcao){
            case 1:
                cout << "Digite um valor para inserir no inicio: ";
                cin >> valor;
                lista->insereInicio(valor);
                lista->exibe();
                break;
            case 2:
                cout << "Digite um valor para inserir no final: ";
                cin >> valor;
                lista->insereFinal(valor);
                lista->exibe();
                break;
            case 3:
                lista->removeInicio();
                lista->exibe();
                break;
            case 4:
                lista->removeFinal();
                lista->exibe();
                break;
            case 5:
                cout << "Digite um valor para inserir na pilha: ";
                cin >> valor;
                pilha->insereInicio(valor);
                pilha->exibe();
                break;
            case 6:
                pilha->removeInicio();
                pilha->exibe();
                break;
            case 7:
                cout << "Digite um valor para inserir na fila: ";
                cin >> valor;
                
                fila->insereFinal(valor);
                fila->exibe();
                break;
            case 8:
                fila->removeInicio();
                fila->exibe();
                break;                    
            case 9:
                cout<<"Finalizando"<<endl;
                break;                    
            default:
                cout << "Opcao invalida!"<<endl;
                break;
        }
    }while(opcao != 9);
    
    return 0;
}