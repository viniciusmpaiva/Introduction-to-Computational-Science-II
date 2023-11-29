#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>



//Vinicius Paiva 13783530
//Vitor Oliveira Zago 14783595
//Jose Guilherme Lepera 14758811

typedef struct hash_node{
    int idx;
    bool IsOccupied;
    bool NeverBeenOccupied;
}hash_node;

hash_node* create_hashTable(long M){
    hash_node* Hash_Table = malloc(sizeof(hash_node)*M);
    if(Hash_Table == NULL){
        return 0;
    }
    for(int i=0; i<M;i++){
        Hash_Table[i].IsOccupied = false;
        Hash_Table[i].NeverBeenOccupied = true;
        Hash_Table[i].idx= -1;
    }
    return Hash_Table;
}



long hash(long key, long M ){
    return(key%M);
}


void hashTable_insertion(hash_node* Hash_Table, long key, long M){
    int index =hash(key,M);
    int i = index;

    while(Hash_Table[i].IsOccupied == true){
        if(Hash_Table[i].idx == key){
            return;
        }
        i= (i+1) %M;
        if(i==index){
            return;
        }
    }
    Hash_Table[i].IsOccupied=true;
    Hash_Table[i].NeverBeenOccupied = false;
    Hash_Table[i].idx = key;
}



void hashTable_removals(hash_node* Hash_table, long key, long M){
    int index = hash(key,M);
    int i = index;
    while(Hash_table[i].NeverBeenOccupied!=true){
        if(Hash_table[i].idx == key){
            Hash_table[i].idx = -1;
            Hash_table[i].IsOccupied = false;
            return;
        }
        i = (i+1) % M;
        if(i==index){
            return;
        }
    }
}

void hashTable_searches(hash_node* Hash_Table, long key, long M){
    int index = hash(key, M);
    int i = index;
    while(Hash_Table[i].NeverBeenOccupied == false){
        if(Hash_Table[i].idx == key){
            printf("%d ",i);
            return;
        }
        i=(i+1) %M;
        if(i==index){
            printf("%d ",-1);
            return;
        }
    }
    printf("%d ",-1);
    return;
}


int main(){
    //Hash table size
    long M;
    scanf("%ld",&M);
    hash_node* Hash_table = create_hashTable(M);

    //Number of insertions
    long N;
    scanf("%ld",&N);
    long insertion;
    for(int i=0; i<N;i++){
        scanf("%ld",&insertion);
        hashTable_insertion(Hash_table, insertion,M);
    }

    // Number of removals
    long D;
    scanf("%ld",&D);
    long removals;
    for(int i=0; i<D;i++){
        scanf("%ld",&removals);
        hashTable_removals(Hash_table, removals,M);
    }

    //Number or searches
    long B;
    scanf("%ld",&B);
    long searches;
    for(int i=0; i<B;i++){
        scanf("%ld",&searches);
        hashTable_searches(Hash_table, searches,M);
    }
    
    //print result
    // for(int i =0; i<B; i++){
    //     printf("%ld ",res[i]);
    // }
    free(Hash_table);
    

}