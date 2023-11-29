



#include <stdio.h>
#include <stdlib.h>
int *readArray(int n){
    int *a = (int*)malloc(sizeof(int) * n);
    if (a ==NULL){
        exit(-1);
    }
    for (int i =0; i<n;i++){
        scanf("%d",&a[i]);
    }
    return a;
}



int main(){
    int N;
    scanf("%d", &N);
    int *a = readArray(N);
    int K;
    scanf("%d", &K);
    int *k = readArray(K);
    int found = 0;
    for (int i=0; i<K; i++){
        found = 0;
        for (int j=0; j<N;j++){
            if(k[i] == a[j]){
                found++;
                break;
            }
        }
        if (found == 0){
            printf("0\n");
        }else{
            printf("1\n");
        }
    }
}