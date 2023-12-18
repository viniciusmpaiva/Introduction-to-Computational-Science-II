#include <stdio.h>
#include <stdlib.h>

//Vinicius Paiva 13783530
//Vitor Oliveira Zago 14783595
//Jose Guilherme Lepera 14758811

int** create2dArray(int n){
    int** A = malloc(sizeof(int*)*n);
    for(int i=0; i<n; i++){
        A[i] = malloc(sizeof(int)*n); 
    }
    return A;
}

int* createArray(int n){
    int*A = malloc(sizeof(int)*n);
    for(int i=0; i<n;i++){
        A[i] = -1;
    }
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
    }
}

int max(int a, int b){
    return a>b? a: b;
}

int* ArrayUpdatedLine(int line, int column){
    int *A = malloc(sizeof(int)*line);
    int sum = column;
    for(int i=0; i<line;i++){
        A[i] = sum;
        sum = sum +column;
    }
    return A;
}

int checkPath(int n,int ** A, int* cache,int line,int column,int* updated_line,int* S){
    int result;
    // printf("\nCaminho de %d a %d ou de %d a %d\n",n,n+1,n,n+(*column));
    // printf("n = %d, updated_line = %d\n",n,*updated_line);
    if(cache[n]!=-1){
        return cache[n];
    }
    if(n>=line*column - 1){
        return *S;

    }else if(n==(line*column)-2){
        result = checkPath(n+1, A, cache,line,column,updated_line,S);
        *S = *S + A[n][n+1];
        cache[n] = *S;
        return *S;

    }
    for(int i=0; i<line; i++){
        if(n+1 == updated_line[i] && n+column>=  line*column){
            result = checkPath(n+1, A, cache,line,column,updated_line,S);
            *S = *S + A[n][n+1];
            cache[n] = *S;
            return cache[n];

        }else if(n+1 == updated_line[i]){
            result = checkPath(n+column, A, cache,line,column,updated_line,S);
            *S = *S + A[n][n+column];
            cache[n] = *S ;
            return cache[n];
        }
    }
        // printf("Caso normal, de %d a %d ou %d a %d\n",n,n+1,n,n+(*column));
    *S = 0;
    int option1 = checkPath(n+1, A, cache,line,column,updated_line,S) + A[n][n+1]; 
    *S = 0;
    int option2 = checkPath(n+column, A, cache,line,column,updated_line,S) + A[n][n+column];
    result = max(option1,option2);
    cache[n] = result; 
    return cache[n];
}



int main(){
    int line, column,n;
    scanf("%d",&line);
    scanf("%d",&column);
    n = ((column-1) * line) + ((line-1)*column); 
    // printf("\nO n é %d\n",n);
    int **A = create2dArray(n);
    readPaths(A, n);
    int* cache = createArray(n);

    int S = 0;
    int* updated_line = ArrayUpdatedLine(line,column);
    int result= checkPath(0,A,cache, line,column,updated_line,&S);
    printf("%d",result);
}