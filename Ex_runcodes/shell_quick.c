#include<stdio.h>
#include<stdlib.h>
#define QUICKSORT 1
#define SHELLSORT 2
#define SAME_OPERATIONS 0 


int *readArray(int n){
    int *a=(int*)malloc(sizeof(int)*n);
    if(a==NULL){
        exit(-1);
    }
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    return a;
}
int *createArray(int n){
    int *a=(int*)malloc(sizeof(int)*n);
    if(a==NULL){
        exit(-1);
    }
    return a;
}


int *copyArray(int a[], int n){
    int *b = createArray(n);
    for(int i=0;i<n;i++){
        b[i] = a[i];
    }
    return b;
}



void shell(int v[], int n,int *num_operations) {
    int gap = 1;
    while(gap <= n) {
        gap *= 2;
    }
    gap = gap / 2 - 1;
    while(gap > 0) {
        for (int i = gap; i < n; i++){
            int x = v[i];
            *num_operations = *num_operations + 1;
            int j = i - gap;
            while(j >= 0 && v[j]>x){ 
                *num_operations = *num_operations + 1; 
                v[j + gap] = v[j];
                *num_operations = *num_operations +1;
                j -= gap;
            }
            if(j>=0){
                *num_operations = *num_operations + 1;                
            }
            v[j + gap] = x;
            *num_operations = *num_operations +1;
        }
        gap /= 2;
    }
}

void quick(int v[], int f, int l,int *num_operations) {

    if (f >= l) {

        return;

    }
    int m = (l + f)/2;
    int pivot = v[m];
    *num_operations = *num_operations +1;
    int i = f;
    int j = l;
    while(1) {
        while(v[i] < pivot) {
            *num_operations = *num_operations +1;
            i++;
        }
        *num_operations = *num_operations + 1;
        while(v[j] > pivot) {
            j--;
        *num_operations = *num_operations + 1;
        }
        *num_operations = *num_operations +1;
        if (i >= j) {
            break;
        }

        int aux = v[i];
        v[i] = v[j];
        v[j] = aux;
        *num_operations = *num_operations +3;
        i++;

        j--;

    }
    quick(v, f, j,num_operations);
    quick(v, j+1, l,num_operations);
}



int main(){
    int n;
    scanf("%d",&n);
    int *a = readArray(n);
    int *operations = createArray(n);
    // 1 vetor - indice 0 até indice 0
    // 2 vetor - indice 0 ate indice 1
    // 3 vetor - indice 0 ate indice 2
    for(int i=0;i<n;i++){
        int operations_q = 0;
        int *tempArrayQuick = copyArray(a,i+1);
        int *tempArrayShell = copyArray(a,i+1);
        int operations_s = 0;
        quick(tempArrayQuick,0,i,&operations_q);
        shell(tempArrayShell,i+1,&operations_s);

        if(operations_q < operations_s){
            operations[i] = QUICKSORT;
        }else if(operations_s < operations_q){
            operations[i] = SHELLSORT;
        }else{
            operations[i] = SAME_OPERATIONS;
        }
        free(tempArrayQuick);
        free(tempArrayShell);
    }
    for(int i=0;i<n;i++){
        if(operations[i] == QUICKSORT){
            printf("Q");
        }else if (operations[i] == SHELLSORT){
            printf("S");
        } else{
            printf("-");            
        }
    }
    free(operations);
    free(a);

}
