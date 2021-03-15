#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#define SIZE 100000

void remplir_tableau (int a[]) {
    int i;
    for (i=0; i<SIZE; i++) {
        a[i]=(rand()%SIZE);
    }
}

void permuter(int *a, int *b) {
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

void triRapid(int tab2[], int first, int last) {
    int pivot, i, j;
    if(first<last) {
        pivot=first;
        i=first;
        j=last;
        while (i<j) {
            while(tab2[i]<=tab2[pivot] && i<last)
                i++;
            while(tab2[j]>tab2[pivot])
                j--;
            if(i<j) {
                permuter(&tab2[i], &tab2[j]);
            }
        }
        permuter(&tab2[pivot], &tab2[j]);
        triRapid(tab2, first, j - 1);
        triRapid(tab2, j + 1, last);
    }
}

void tri_insertion(int tab[], int taille)
{
  int i,j;
 
  for (i=1 ; i <= SIZE-1; i++) {
    j = i;
 
    while (j > 0 && tab[j-1] > tab[j]) {
      permuter(&tab[j],&tab[j-1]);
 
      j--;
    }
 }
}

void tri_selection(int *t, int n){
        int i, min, j , tmp;
        for(i =0; i < n -1; i++){
                min = i;
                for(j = i+1; j < n ; j++)
                    if(t[j] < t[min])
                        min = j;
                if(min != i){
                        tmp = t[i];
                        t[i] = t[min];
                        t[min] = tmp;
                }
        }
}

void triFusion(int i, int j, int tab[], int tmp[]) {
    if(j <= i){ return;}
  
    int m = (i + j) / 2;
    
    triFusion(i, m, tab, tmp);     //trier la moitié gauche récursivement
    triFusion(m + 1, j, tab, tmp); //trier la moitié droite récursivement
    int pg = i;     //pg pointe au début du sous-tableau de gauche
    int pd = m + 1; //pd pointe au début du sous-tableau de droite
    int c;          //compteur
// on boucle de i à j pour remplir chaque élément du tableau final fusionné
    for(c = i; c <= j; c++) {
        if(pg == m + 1) { //le pointeur du sous-tableau de gauche a atteint la limite
            tmp[c] = tab[pd];
            pd++;
        }else if (pd == j + 1) { //le pointeur du sous-tableau de droite a atteint la limite
            tmp[c] = tab[pg];
            pg++;
        }else if (tab[pg] < tab[pd]) { //le pointeur du sous-tableau de gauche pointe vers un élément plus petit
            tmp[c] = tab[pg];
            pg++;
        }else {  //le pointeur du sous-tableau de droite pointe vers un élément plus petit
            tmp[c] = tab[pd];
            pd++;
        }
    }
    for(c = i; c <= j; c++) {  //copier les éléments de tmp[] à tab[]
        tab[c] = tmp[c];
    }
}


void trilent(int tab[]) {

    int i, j, tmp;
    for (i=0; i<SIZE-1; i++) {
        for (j=0; j<SIZE-i-1; j++) { 
            if (tab[j]>tab[j+1]) {       /* Pour un ordre décroissant utiliser < sur cette ligne*/
            tmp=tab[j];
            tab[j]=tab[j+1];
            tab[j+1]=tmp;
            }
        }
    }
}
void main (int argc, char* argv[]) {  //a mettre dans le main deja existant
    int i, j, tmp, tab[SIZE], tmp_tab[SIZE];
    clock_t start_t, end_t;
    float temps;

    remplir_tableau(tab);
    start_t = clock();
    trilent(tab);
    end_t = clock();
    temps = (float)(end_t - start_t);
    printf("%d;%f\n", SIZE, temps);
    remplir_tableau(tab);
    start_t = clock();
    tri_insertion(tab, SIZE);
    end_t = clock();
    temps = (float)(end_t - start_t);
    printf("%d;%f\n", SIZE, temps);
    remplir_tableau(tab);
    start_t = clock();
    tri_selection(tab, SIZE);
    end_t =clock();
    temps = (float)(end_t - start_t);
    printf("%d;%f\n", SIZE, temps);
    remplir_tableau(tab);
    start_t = clock();
    triRapid(tab, 0, SIZE-1);
    end_t =clock();
    temps = (float)(end_t - start_t);
    printf("%d;%f\n", SIZE, temps);
    remplir_tableau(tab);
    start_t = clock();
    triFusion(0, SIZE-1, tab, tmp_tab);
    end_t =clock();
    temps = (float)(end_t - start_t);
    printf("%d;%f\n", SIZE, temps);

}

