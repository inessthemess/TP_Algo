/***********************************************/
/*Alogritmique élémentaire, TP2 exercice2, EISE*/
/*Auteur: Inessa Kechek                        */
/*Date: 28/02/2024                             */
/***********************************************/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>




/*Question 1*/
/*on modélise l'état du jeu en utilisant un tableau de 2 dimensions*/

/*Question 2*/
int ** allouerMatrice(int n,int m){
    int ** mat= (int **)malloc(sizeof(int *)*n);
    for (int i = 0; i < n ; i++){
        mat[i]=(int *)malloc(sizeof(int)*m);
    }
    return mat;
}


/*Question 3*/
void afficherMatrice(int ** matrice, int n, int m){
    printf("H:||\n");
    for (int i = 0; i < n; i++){
        printf("%d ||", matrice[i][0]);
        for (int j = 1; j < m ; j++){
            printf("%d ",matrice[i][j]);
        }
        printf("\n");
        
    }

}

int main(){
    
    int ** mat=allouerMatrice(3,4);
    for (int i = 0; i < 3; i++){
        for (int j = 1; j < 4 ; j++){
            mat[i][j]=0;
        }
    afficherMatrice(mat,3,4);

    return 0;

}
}