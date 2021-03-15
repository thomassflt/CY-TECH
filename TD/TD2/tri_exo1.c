#include <stdio.h>
#include <stdlib.h>
#define N 10

void tri(int* t){

    int etape,ncase,min, temp;

    for(etape = 0; etape < N-1; etape++){
        min = etape;

        for(ncase= etape+1;ncase < N;ncase++){
            if(t[ncase] < t[min]){
                min = ncase;
            }
        }

        if(min != etape){
            temp = t[min];
            t[min] = t[etape];
            t[etape]= temp;
        }
        for(int i=0;i<N;i++){
            printf(" %d ", t[i]);
        }
        printf("\n");
    }

    

    
}


int main(void){

    int tableau[N] = {4,8,2,10,1,9,7,6,3,5};


    for(int i=0;i<N;i++){
        printf(" %d ", tableau[i]);
    }
    printf("\n");
    tri(tableau);


    return 0;
}