#include <stdio.h>

//programme testé avec 10 valeur générées de 0 à 9


void insertion(int tableau[10]) {
int i;
int j;
int temp;

for (i = 0; i < 10; i++) {
for(j = i; j >= 0; j--){
        if (tableau[j] > tableau[j-1]) {
        temp=tableau[j];
        tableau[j]=tableau[j-1];
        tableau[j-1]=temp;
        }
    }
}
printf("Tableau trie : \n ") ;      
    for (i = 0; i < 10; i++) {
        printf("%d\n", tableau[i]);
    }
}

int main () {
    int tab[10];
    int n;
    int i;

    for (i = 0;i < 10; i++) {
        tab[i]=i;
    }

    insertion(tab);

    return 0;
}
