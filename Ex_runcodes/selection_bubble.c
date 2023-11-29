#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int *lervetor(int n){
    int *a = (int*)malloc(sizeof(int) * n);
    if (a ==NULL){
        exit(-1);
    }
    for (int i =0; i<n;i++){
        int x;
        scanf("%d",&x);
        a[i] = x;
    }
    return a;
}

void bubble_sort(int a[], int n){
    int c;
    for(int i =n-1;i>=1;i=c){
        c = -1;
        for(int j =0;j<i;j++){
            printf("C %d %d\n",j,j+1);
            if(a[j] > a[j+1]){
                c=j;
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
                printf("T %d %d\n",j,j+1);
            }
        }
    }
}





void selection_sort(int a[], int n){
    for(int i=0;i<n-1;i++){
        int m = i;
        for(int j = i+1; j<n;j++){
            printf("C %d %d\n",m,j);
            if(a[j] < a[m]){
                m = j;
            }
        }
        if (m!=i){
            int temp = a[i];
            a[i] = a[m];
            a[m] = temp;
            printf("T %d %d\n",i,m);
        }
    }
}

void imprimir_vetor(int a[], int n){
    for(int i=0;i<n;i++){
        printf("%d ",a[i]);
    }
}

int main(){
    char metodo_escolha[50];
    char bolha[50] = "bolha";
    char selecao[50] = "selecao";
    scanf("%s",metodo_escolha);
    int n;
    scanf("%d",&n);
    int *a = lervetor(n);
    if(strcmp(metodo_escolha,bolha)==0){
        bubble_sort(a,n);
        imprimir_vetor(a,n);
        
    }else if(strcmp(metodo_escolha,selecao) == 0){
        selection_sort(a,n);
        imprimir_vetor(a,n);
    }
    free(a);
}

