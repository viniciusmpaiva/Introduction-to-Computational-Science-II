#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int *lervetor(int n){
    int *a = (int*)malloc(sizeof(int) * n);
    if (a ==NULL){
        exit(-1);
    }
    for (int i =0; i<n;i++){
        scanf("%d",&a[i]);
    }
    return a;
}

int *criar_vetor(int n){
    int *a = (int*)malloc(sizeof(int) * n);
    if (a ==NULL){
        exit(-1);
    }
    return a;
}

int *copia_vetor(int a[], int n){
    int *b = criar_vetor(n);
    for(int i=0;i<n;i++){
        b[i] = a[i];
    }
    return b;
}
void insertionSort(int a[],int n,int *troca,int *comp){
    for(int i=1 ;i<n ; i++){
        *troca = *troca +1;
        int x = a[i];
        int j = i-1;
        while(j>=0){
            *comp=*comp +1;
            if(a[j]>x ){
                a[j+1] = a[j];
                *troca = *troca +1;
                j--;
            }else{
                break;
            }
        }
        a[j+1] = x;
        *troca = *troca+1;
    }
}

void mergeSort_2_vetor_uniao(int a[], int inicio_1, int final_1,int inicio_2, int final_2,int b[], int *troca, int *comp){
    int contador_1 = inicio_1;
    int contador_2 = inicio_2;
    int j = 0;
    while(contador_1<=final_1 && contador_2<=final_2){
        *comp = *comp +1;
        if(a[contador_1]<=a[contador_2]){
            b[j] = a[contador_1];
            *troca = *troca+1;
            j++;
            contador_1++; 
        }else{
            b[j] = a[contador_2];
            *troca = *troca +1;
            j++;
            contador_2++;
        }
    }
    while(contador_1<=final_1){
        *troca = *troca+1;
        b[j] = a[contador_1];
        j++;
        contador_1++;
    }
    while(contador_2<=final_2){
        *troca = *troca +1;
        b[j] = a[contador_2];
        j++;
        contador_2++;
    }
    j = 0;
    for (int i = inicio_1;i<=final_2;i++,j++){
        a[i] = b[j];
        *troca = *troca +1;
    }
    
}




void mergeSort(int a[], int inicio, int final, int b[], int *troca, int *comp){
    if(inicio>=final){
        return;
    }
    int meio = (inicio+final)/2;
    mergeSort(a,inicio,meio,b, troca, comp);
    mergeSort(a,meio+1,final,b, troca, comp);
    mergeSort_2_vetor_uniao(a,inicio,meio,meio+1,final,b, troca, comp);
}


void mergeSort_2Vetor_declaracao(int a[], int n,int *troca, int *comp){
    int *b = (int*)malloc(sizeof(int)*n);
    if(b==NULL){
        exit(-1);
    }
    mergeSort(a,0,n-1,b,troca,comp);
    free(b);
}








void imprimir_vetor(int a[], int n){
    for(int i=0;i<n;i++){
        printf("%d ",a[i]);
    }
    
}


//Vetor de q n tamanhos de vetores
//Vetores de n tamanhos
int main(){
    
    int q;
    scanf("%d",&q);
    int *q_vetores = lervetor(q);
    int *trocas_i = criar_vetor(q);
    int *comps_i = criar_vetor(q);
    int *trocas_m = criar_vetor(q);
    int *comps_m = criar_vetor(q);
    for(int i=0;i<q;i++){
        int troca_i=0;
        int troca_m=0;
        int comp_m = 0;
        int comp_i = 0;
        int *a=lervetor(q_vetores[i]);
        int *b = copia_vetor(a,q_vetores[i]);
        insertionSort(a,q_vetores[i],&troca_i,&comp_i);
        trocas_i [i] = troca_i;
        comps_i[i] = comp_i;
        mergeSort_2Vetor_declaracao(b,q_vetores[i],&troca_m,&comp_m);
        trocas_m[i] = troca_m;
        comps_m[i] = comp_m; 
    }
    for (int j=0;j<q;j++){
        printf("I %d %d %d\n",q_vetores[j],trocas_i[j],comps_i[j]);
        printf("M %d %d %d\n",q_vetores[j],trocas_m[j],comps_m[j]);
    }

}
