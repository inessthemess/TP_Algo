/***********************************************/
/*Alogritmique élémentaire, TP2 exercice1, EISE*/
/*Auteur: Inessa Kechek                        */
/*Date: 28/02/2024                             */
/***********************************************/



#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#define MIN 100
#define MAX 1000

/*Question 1*/

void afficherMatrice(int ** matrice, int n){
    for (int i = 0; i < n; i++){
        printf("\n");
        for (int j = 0; j < n; j++){
            printf("%d ", matrice[i][j]);
        }
    }
    printf("\n");
}



/*Question 2*/

int ** allouerMatrice(int n){
    int ** mat= (int **)malloc(sizeof(int *)*n);
    for (int i = 0; i < n ; i++){
        mat[i]=(int *)malloc(sizeof(int)*n);
    }
    return mat;
}


/*Question 3*/


void detruireMatrice(int ** matrice, int n){
    for (int i = 0; i < n; i++){
        free(matrice[i]);
    }
    free(matrice);
}


/*Question 4*/

void initialiserAleatoirementMatrice(int ** matrice, int n){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            matrice[i][j] = MIN + rand() % (MAX - MIN);
        }
    }
}


/*Question 5*/

/*
étape 1 : M(1,1) (supprimer la première ligne et la première colonne)
M(1,1)=[5 6; 8 9]=5*9 - 6*8 = -3

étape 2 : M(1,2) (supprimer la première ligne et la deuxième colonne)
M(1,2)=[4 6; 7 9]=4*9 - 6*7 = -6

étape 3 : M(1,3) (supprimer la première ligne et la troisième colonne)
M(1,3)=[4 5; 7 8]=4*8 - 5*7 = -3


donc det(matrice)= (-1)^1+1*1*M(1,1) + (-1)^1+2*2*M(1,2) + (-1)^1+3*3*M(1,3)
                 = -3 + 12 -9 = 0                       

*/



/*Question 6*/
/*nous supposons que indiceCol 0 correspond à la première colonne, 1 à la duexième et 2 à la troisième*/
int ** mineur(int ** matrice, int n, int indiceCol){
    int **mineur=allouerMatrice(n-1);
    
    for (int i = 0; i < n - 1; i++){
        int colonne = 0;
        for (int j = 0; j < n; j++){
            if (j != indiceCol){
                mineur[i][colonne] = matrice[i + 1][j];
                colonne++;
            }
        }
    }
    return mineur;
}

/*Quesiton 7*/
int determinant(int ** matrice, int n){
    int res = 0;
    if (n==1){
        return matrice[0][0];
    }
    for (int j = 0; j < n ; j++){
        int signe = (j % 2 == 0) ? 1: -1;
        int ** min = mineur(matrice, n ,j);
        res+=signe*matrice[0][j]*determinant(min,n-1);
        detruireMatrice(min,n - 1);
    }

    return res;
}

int main(){
    srand(time(NULL));
    int** mat=allouerMatrice(3);
    initialiserAleatoirementMatrice(mat,3);

    afficherMatrice(mat,3);
    printf("\nOn enlève la première ligne et la première colonne\n");
    int **min=mineur(mat,3,0);
    afficherMatrice(min,2);
    detruireMatrice(mat,3);
    detruireMatrice(min,3);
    int ** mat2=allouerMatrice(3);
    int k = 1;
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            mat2[i][j]=k++;
        }
    }
    afficherMatrice(mat2,3);
    printf("\nLe déterminant est %d\n", determinant(mat2,3));
    detruireMatrice(mat2,3);

    /*Question 8*/
    for (int i = 3; i < 14; i++){
        int ** mat=allouerMatrice(i);
        initialiserAleatoirementMatrice(mat,i);
        /*calcul du temps*/
        clock_t start, end;
        start = clock();
        int det = determinant(mat,i);
        end = clock();

        printf("det(M_%02d) = %10d, temps de calcul %f\n", i, det, (double) ((end - start)));
        detruireMatrice(mat,i);

    }
    /*Question 9*/
    /*on estime une complexité de O(n!) avec n la taille de la matrice*/
    return 0;
}