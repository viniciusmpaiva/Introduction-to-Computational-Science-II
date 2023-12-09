#include<stdio.h>
#include <string.h>
#include <stdlib.h>


char** createArray(int N){
    char** a = malloc(sizeof(char*)*N);
    for(int i=0; i<N;i++){
        a[i] = malloc(sizeof(char)*1000);
    }
    return a;
}


int checkOverlap(const char* str1, const char* str2) {


    int len1 = strlen(str1);
    int len2 = strlen(str2);

    int i = len1-1;
    int j = len2-1;
    int overlap = 0;

    while(i>=0 && j>=0){

        if(str1[i] == str2[j]){
            overlap ++;
            j--;
            i--;
        }else if(overlap>0){
            overlap =0;
            i = len1-1;
        }else{
            j--;
        }
    }
    return overlap;
}

char* concatOverlap(char* a, char* b, int overlap){
    int a_size = strlen(a);
    int b_size = strlen(b);
    char* result = malloc(a_size + b_size - overlap + 1);

    strncpy(result,a,strlen(a)-overlap);
    result[a_size - overlap] = '\0';
    result = strcat(result,b);
    return result; 

}


char* recOverlap(char** reads, int N,char s_overlap_string[]){


    int overlap;
    int b_overlap = 0;
    int final_i = 0;
    int final_j=0;
    int first_overlap=-1;

    for(int i=0; i<N; i++){
        if( i!=0){
            for(int u= 0; u<i; u++){
                overlap = checkOverlap(reads[i], reads[u]);
                if(overlap>=b_overlap && overlap !=first_overlap){
                    b_overlap = overlap;
                    first_overlap = overlap;
                    char* concat_result = concatOverlap(reads[i], reads[u], b_overlap);
                    strcpy(s_overlap_string,concat_result);
                    free(concat_result);

                    final_i = u;
                    final_j = i;

                }
            }
        }

        for(int j=i+1; j<N; j++){
            overlap = checkOverlap(reads[i], reads[j]);
            if(overlap>=b_overlap&&overlap!=first_overlap){
                b_overlap = overlap;
                first_overlap = overlap;
                char* concat_result = concatOverlap(reads[i], reads[j], b_overlap);
                strcpy(s_overlap_string,concat_result);
                free(concat_result);
                final_i = i;
                final_j = j;
            }
        }
    }
    N--;
    if(N==1){
        return s_overlap_string; 
    } 
    char** newreads = createArray(N);
    
    strcpy(newreads[0],s_overlap_string);
    

    int j=0;
    for(int i=1; i<N;i++){
        while(strcmp(reads[j], reads[final_j]) == 0 || strcmp(reads[j], reads[final_i]) ==0){
            j++;
        }
        strcpy(newreads[i],reads[j]);
        
        j++;
    }
    recOverlap(newreads,N,s_overlap_string); 
}


int main(){
    int N;
    scanf(" %d",&N);
    getchar();
    char** reads = createArray(N);
    for(int i = 0; i<N;i++){
        scanf("%s",reads[i]);
    }
    char s_overlap_string[1000];
    char*res = recOverlap(reads, N,s_overlap_string);
    printf("%s\n",res);
    for (int i = 0; i < N; i++) {
        free(reads[i]);
    }
    free(reads);
}
