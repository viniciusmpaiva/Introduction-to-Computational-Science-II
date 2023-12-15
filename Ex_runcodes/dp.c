#include <stdio.h>
#include <stdlib.h>

int** create2dArray(int n){
    int** A = malloc(sizeof(int*)*n);
    for(int i=0; i<n; i++){
        A[i] = malloc(sizeof(int)*n); 
    }
    return A;
}
int** createCache(int n){
    int** A = malloc(sizeof(int*)*n);
    for(int i=0; i<n; i++){
        A[i] = malloc(sizeof(int)*n); 
    }
    for(int i=0; i<n;i++){
        for(int j=0; j<n;j++){
            A[i][j] = -1;
        }
    }
    return A;
}
int* createArray(int n){
    int*A = malloc(sizeof(int)*n);
    return A;
}

void readPaths( int** A, int n){
    int destny, num_friends;
    int origin = 0;
    for(int i =0; i<n; i++){
        scanf("%d", &origin);
        scanf("%d", &destny);
        scanf("%d", &num_friends);
        A[origin][destny] = num_friends;
        // printf("\nLeu: %d %d %d\n",origin,destny,A[origin][destny]);
    }
}

int max(int a, int b){
    return a>b? a: b;
}

int checkPath(int n,int ** A, int** cache,int *line,int* result,int* column,int* updated_line){
    printf("\n%d\n",*result);
    if(n>=(*line)*(*column)){
        return 0;
    }

    if(n+1 < (*line) * (*column)){
        if(cache[n][n+1] != -1){
            printf("Cache é %d\n",cache[n][n+1]);
            return cache[n][n+1];
        }
    }
    if(n+3 < (*line) * (*column)){
        if(cache[n][n+3] != -1){
            printf("Cache é %d\n",cache[n][n+3]);

            return cache[n][n+3];
        }
    }

    if(n+1 == *updated_line && n+3> (*line)*(*column)){
        return *result;

    }else if(n+1 == *updated_line){
        *updated_line = *updated_line * 2;
        *result = *result+  checkPath(n+3,A,cache,line,result,column,updated_line);
        cache[n][n+3] = *result;


    }else if(n+3> (*line)*(*column)){
        *result = *result + checkPath(n+1,A,cache,line,result,column,updated_line);
        cache[n][n+1] = *result;

    }else{
        int option1 = checkPath(n+1, A, cache,line,result,column,updated_line);
        int option2 = checkPath(n+3, A, cache,line,result,column,updated_line);
        *result =  *result + max(option1,option2);

    }
    return *result;
}


int main(){
    int line, column,n;
    scanf("%d",&line);
    scanf("%d",&column);
    if(line == column){
        n = (line*column)+column;
    }else{
        n = (line*column)+column+1;
    }
    int **A = create2dArray(n);
    readPaths(A, n);
    printf("Ta aqui");
    int S;
    int** cache = createCache(n);
    int result = 0;
    int updated_line = line;
    S = checkPath(0,A,cache, &line,&result,&column,&updated_line);
    // printf("%d",S);
}