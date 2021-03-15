#include <stdio.h>
#include <stdlib.h>


//Exercice 1
/*
int main() {
    int i;
    int* p = NULL;

    i = 3;
    p = &i;

    printf("%d\n", i);

    *p = 5;

    printf("%d\n", i);

    return 0;
}
*/

//Exercice 2
/*
int main() {
    int a, b;
    int* p;
    int** pp;

    a = 0;
    b = 1;
    p = &a;
    a += b;
    pp = &p;

    printf("a = %d, *p = %d, **pp = %d", a, *p, **pp);

    return 0;
}
*/

//Exercice 3

void index(int t[]){
    int* i;
    
    for (int* i = t; i < &t[10]; i++) {
        if (*i==0) {
            printf("\n index nul : %d", (int) ((i-t)));
        }
    }
}

int main() {
    int t[10] = {0,1,4,0,3,8,9,2,0,1};

    index(t);
    return 0;
}