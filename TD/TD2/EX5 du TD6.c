#include "stdio.h"
#include "stdlib.h"

void tri(int a[10]) {  
    int i, b[10],pos_gauche=0, pos_droite=9;
    for (i=0; i<10; i++) {
        if (a[i]==0) {
            b[pos_gauche]=a[i];
            pos_gauche++;
        }
        else {
            b[pos_droite]=a[i];
            pos_droite--;
        }
    }
    for (i=0; i<10; i++) {
        printf ("%d;", b[i]);
    }
}

void main (int argc, char *argv[]) {
    int a[10] = {1,0,1,1,0,0,0,1,0,1};
    tri(a);
}
