/*Algoritmo de ordenação*/

#include <stdio.h>
#include <stdlib.h>


/*Complexidade 
pior caso O(n²),
melhor caso O(n log n)
*/ 
void QuickSort(int *vet, int left, int right){
    int y;
    int i = left;
    int j = right;
    int x = vet[(left + right) / 2];
    
    while(i <= j){
        while( (vet[i] < x) && (i < right)){ 
            i++;
        }
        while ( (vet[j] > x) && (j > left)){
            j--;
        }

        if(i <= j){
            y = vet[i];
            vet[i] = vet[j];
            vet[j] = y;
            i++;
            j--;
        }
    }
    
    if (j > left){
        QuickSort(vet, left, j);
    }
    if (i < right){
        QuickSort(vet, i, right);
    }
}

/*Complexidade 
pior caso O(n log n),
melhor caso O(n log n) tipico, O(n) variante narural
*/ 
void MergeSort(int *vet, int TamVet){
    int *aux = malloc(sizeof(int) * TamVet);
    sort(vet, aux, 0, TamVet-1);
    free(aux);
}

void sort(int *vet, int *aux,int inicio, int final){
    if( inicio < final){
        int meio = (inicio + final) / 2;
        sort(vet, aux, inicio, meio);
        sort(vet, aux, meio + 1, final);
        merge(vet, aux, inicio, meio, final);
    }
}

void merge(int *vet, int *aux, int inicio, int meio, int final){
    int z;
    int iv = inicio;
    int ia = meio + 1;

    for (z = inicio; z <= final; z++){
        aux[z] = vet [z];
    }
    z = inicio;
    
    while ( (iv <= meio) && (ia <= final)){
        if (aux[iv] < aux[ia]){
            vet[z++] = aux[iv++];
        }
        else{
                vet[z++] = aux[ia++];
        }
    }
    while (iv <= meio){
        vet[z++] = aux[iv++];
    }
    while (ia <= final){
        vet[z++] = aux[ia++];
    }
}

void Instructions(void){
    printf( "\nDigite sua escolha:\n\n"
    " 1 Organizar com Quick Sort.\n"
    " 2 Organizar com Merge Sort.\n" );    
}

int main(void){
    int *vet;
    int i, size,choice;

    printf("\nInforme o numero de componentes do vetor: ");
    scanf("%d", &size);

    vet = (int *)malloc(size * sizeof(int));

    if(vet != NULL){

        for (i = 0; i < size; i++ ){
            printf("\nPreencha a posicao %d do vetor: ",i+1);
            scanf("%d", &vet[i]);
            //vet[i] = rand() % 9; //Teste vetor >10000000
        }

        printf("\nVetor na posicao dado pelo usuario\n");
        for(i = 0; i < size; i++){
            printf("%4d", vet[i]);
        }

        Instructions();
        printf("? ");
        scanf("%d", &choice);

        switch (choice){
        case 1:
            printf("\nOrganizando com Quick Sort\n");
            QuickSort(vet, 0, size-1);
            break;
        case 2:
            printf("\nOrganizando com Merge Sort\n");
            MergeSort(vet, size);
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