/**************************************************************/
/* TP1                                                        */
/* POLYTECH SORBONNE , FISE , ALGORITHMIQUE ELEMENTAIRE       */
/*                                                            */
/* auteur :     Inessa KECHEK                                 */
/* date :    14/02/2024                                       */
/**************************************************************/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>


/* variables globales */
#define MIN 100
#define MAX 1000


/* Question 1 */
void afficherTableau(int tab[], int nbElem){
    int i;
    printf("[");
    for(i = 0; i < nbElem - 1; i++){
        printf("%d,", tab[i]);
    }
    printf("%d]\n", tab[nbElem-1]);
}


/* Question 2-3 */

void initialiserTabSelonMode(int tab[], int nbElem, int mode){
    int i;
    for (i = 0; i < nbElem; i++){
        if (mode == 1){
            tab[i] = i;
        }
        else if (mode == 2){
            tab[i] = nbElem - 1 - i;
        }
        else if (mode == 3){
            tab[i] = rand() % (MAX - MIN) + MIN;
        }
        else{
            printf("[!] Warning : mode can only take the values 1, 2 or 3\n");
            break;
        }   
    }

}


/* Question 5 */

void verifierTri(int tab[], int nbElem){
    int i;
    for (i = 0; i < nbElem - 1; i++){
        if (tab[i] > tab[i+1]){
            afficherTableau(tab, nbElem);
            printf("[!] Warning: the array is not sorted in an ascending order\n");
            printf("These numbers aren't ascending : %d, %d with these indexes %d, %d\n",tab[i],tab[i+1],i,i+1);
            break;
        }
    }
}

/* Question 6 */

void echangerContenuCase(int tab[], int i, int j){
    int tmp;
    tmp = tab[i];
    tab[i] = tab[j];
    tab[j] = tmp;
}


/* Question 7*/

void renverserSection(int tab[], int deb, int fin){
    int i;
    int taille=(fin-deb)/2;
    for (i = 0; i < taille ; i++){
        echangerContenuCase(tab,deb,fin - i - 1);
        deb++;
    }
}

/* Question 8*/

void renverserTableau(int tab[], int nbElem){
    renverserSection(tab,0,nbElem);
}

/* Question 9*/


void triSelection(int tab[], int nbElem){
    int i,j,min,tmp;
    for (i=0; i < (nbElem-1); i++)
    {
    min = i;
   
    for (j=i + 1; j < nbElem; j++)
    {
      if (tab[min] > tab[j])
        min = j;
    }
    if (min != i)
    {
      tmp = tab[i];
      tab[i] = tab[min];
      tab[min] = tmp;
    }
  }
}


/* Question 10 */

void triInsertion(int tab[], int nbElem){
    int i, j, index;
    for (i = 1; i < nbElem; i++){
        index = tab[i];
        j = i - 1;
        while (j >= 0 && tab[j] > index){
            tab[j + 1] = tab[j];
            j = j - 1;
        }
        tab[j + 1] = index;
    }
}


/* Question 11*/

int comparerEntier(const void * e1, const void * e2){
    int * q1 = (int *)e1;
    int * q2 = (int *)e2;

    return (*q1 > *q2);
}

/* Question 12*/

void triRapide(int tab[], int nbElem){
    qsort((int*)tab, nbElem, sizeof(int), comparerEntier);
}


/* Question 13 */

int calculerIndiceIMax(int tab[], int nbElem){
    int indiceMax = 0;
    for (int i = 1; i < nbElem; i++){
        if (tab[i] > tab[indiceMax]){
            indiceMax = i;
        }
    }

    int indMax = 0;
    int maxb = tab[indiceMax];
    while (maxb > 0){
        maxb = maxb >> 1;
        indMax++;
    }
    return indMax;
}


/* Question 14 */

void eclaterTableau(int tab[],int tab0[],int tab1[], int numBit, int nbElem){
    for (int i = 0 ; i < nbElem; i++){
        if (tab[i] & (1<<numBit)){
            tab1[i]=tab[i];
        }
        else{
            tab0[i]=tab[i];
        }
    }
}




int main(){
    srand(time(NULL));
    /* Question 4 */
    /*
    int nbElem = 10;
    int* tab = (int *) malloc(nbElem * sizeof(int));
    for (int i = 0; i < 10; i++){
        int aleatoire = rand() % (4 - 1) + 1;
        initialiserTabSelonMode(tab,nbElem,aleatoire);
        afficherTableau(tab, nbElem);
    }
    free(tab);*/
    /* test pour la fonction eclaterTableau */
    int tab[5]={3,11,5,17,6};
    int tab0[1];
    int tab1[4];
    eclaterTableau(tab,tab0,tab1,0,5);
    for (int i = 0; i<1;i++){
        printf("%d ",tab0[i]);
    }
    printf("\n");
    for (int j= 0; j<4;j++){
        printf("%d ",tab1[j]);
    }
    
}
