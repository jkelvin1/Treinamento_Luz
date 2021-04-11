/*Algoritmo de Ordenação 
[x]BubbleSort, pior caso n², melhor caso n
[x]InsertionSort,
[x]SelectionSort,
[x]Complexidade*/


/*Alocação dinamica -> Pode alocar espaços durante a execução, permite a
aumentar ou diminuir a quantidade de memoria alocada, permiter alocar espaços apenas quando 
necessarios. O tamanho de uma estrutura não é necessariamente a soma dos tamanhos de seus
membros, pois depende de requisitos de alinhamentos de endereços dependentes da maquina. */


#include <stdio.h>
#include <stdlib.h>

/*Complexidade 
pior caso O(n²),
melhor caso O(n)
*/ 
void BubbleSort(int *vet, int TamVet){
    int i, j, aux;
    int tam = TamVet - 1;

    do{
        j = 0;
        for (i = 0; i < tam; i++){  
            if (vet[i] > vet[i+1]){
                aux = vet[i];
                vet[i] = vet[i+1];
                vet[i+1] = aux;
                j = i;
            }
        }
        tam = j;
    }while (tam >= 1 ); 
    
}

/*Complexidade 
pior caso O(n²),
melhor caso O(n)
*/ 
void InsertionSort(int *vet, int TamVet){
    int i, j, aux;

    for ( i = 0; i < TamVet; i++){ 
        aux = vet[i];
        j = i - 1;

        while (( aux < vet[j] ) && (j >= 0)){
            vet[ j + 1 ] = vet[j];
            j -= 1; 
        }

        vet[j + 1] = aux;
    }
}

/*Complexidade 
pior caso O(n²),    
melhor caso O(n²)
*/ 
void SelectionSort(int *vet, int TamVet){
    int i, j, min, aux;

    for(i = 0; i < (TamVet -1); i++ ){ 
        min = i;
        for (j = (i + 1); j < TamVet; j++){ 
            if( vet[j] < vet[min] ){
                min = j;
            }
        }
        if(i != min){
            aux = vet[i];
            vet[i] = vet[min];
            vet[min] = aux;
        }
    }
}

void Instructions(void){
    printf( "\nDigite sua escolha:\n\n"
    " 1 Organizar com Bubble Sort.\n"
    " 2 Organizar com Insertion Sort.\n"
    " 3 Organizar com Selection Sort.\n" );    
}

int main(void){
    int *vet;
    int i, size, choice;

    printf("\nInforme o numero de componentes do vetor: ");
    scanf("%d", &size);

    vet = (int *)malloc(size * sizeof(int));

    if(vet != NULL){
        for (i = 0; i < size; i++ ){
            printf("\nPreencha a posicao %d do vetor: ",i+1);
            scanf("%d", &vet[i]);
            //vet[i] = rand() % 9; //Teste vetor > 10000000
        }

        printf("\nVetor na ordem dado pelo usuario\n");
        for(i = 0; i < size; i++){
            printf("%4d", vet[i]);
        }

        Instructions();
        printf("? ");
        scanf("%d", &choice);

        switch (choice){
        case 1:
            printf("\nOrganizando com Bubble Sort\n");
            BubbleSort(vet, size);
            break;
        case 2:
            printf("\nOrganizando com Insertion Sort\n");
            InsertionSort(vet, size);
            break;
        case 3:
            printf("\nOrganizando com Selection Sort\n");
            SelectionSort(vet, size);
            break; 
        default:
            printf("Opcao Invalida!");
            break;
        }

        printf("\nVetor Organizado em ordem crescente\n");
        for(i = 0; i < size; i++){
            printf("%4d", vet[i]);
        }
        printf("\n");
        free(vet);
    }
    else{
        printf("\n Nao alocado! \n\n");
    }
    return 0;   
}