#include <stdio.h>
#define N 5

int TriVerification(int tab[N]) 
{
    int i,j,tmp;

    for(i = 2;i < N;i++)
    {
        tmp = tab[i];
        j = i-1;

        while (j > 0 && tab[j] > tmp) 
        {
            printf("erreur de trie à la position %d\n",i);
            tab[j+1] = tab[j];
            j = j-1;
        }
     tab[j+1] = tmp;
    }
    printf("-------- FIN VERIFICATION DE TABLEAU --------\n");
}

int main()
{
    printf("Initialisation\n");

    int tab1[N],tab2[N];

    tab1[0] = 1;
    tab1[1] = 9;
    tab1[2] = 3;
    tab1[3] = 4;
    tab1[4] = 5;

    tab2[0] = 2;
    tab2[1] = 3;
    tab2[2] = 4;
    tab2[3] = 7;
    tab2[4] = 6;

    printf("------ DEBUT DE VERIFICATION DE TABLEAU -----\n");
    TriVerification(tab1);
    printf("------ DEBUT DE VERIFICATION DE TABLEAU -----\n");
    TriVerification(tab2);
}