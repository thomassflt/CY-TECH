#include "stdio.h"
#include "stdlib.h"

void insert(int a[9]) {  
    int i, b[10], val, pos=0;
    printf ("La valeur : ");
    scanf ("%d", &val);
    while (a[pos]<val) {
        pos++;
    }
    for (i=0; i<=pos-1; i++) {
        b[i]=a[i];
    }
    b[pos]=val;
    for (i=pos+1; i<=9; i++) {
        b[i]=a[i-1];
    }
    for (i=0; i<=9; i++) {
        printf ("%d |", b[i]);
    }
}

void main (int argc, char *argv[]) {
    int a[9] = {1,3,5,7,9,11,13,15,17};
    insert(a);
}
