#include <stdio.h>


#define LIMIT 1000000


void eratosthenes(int * list){
    for(int i = 2; i <= LIMIT; i++) {
        if(i != 0){
            for(int k = i+i; k <= LIMIT; k+=i) {
                list[k] = 0;
            }   
        }
    }
}


int main(){

    int list[LIMIT];

    for(int i = 2; i <= LIMIT; i++) {
        list[i] = i;
    }

    eratosthenes(list);

    for (int i = 2; i <= LIMIT; i++) {
        if(list[i] != 0){
            printf("%d ", list[i]);
        }
    }

}