#include <stdio.h>

int main()
{   
    int varA =5;
    double varB = 7.3;
    char varC = 'v';
//Declaration des pointeurs 
    int* ptrA ;
    double* ptrB ;
    char* ptrC;

// Intialisation des ponteurs avec leurs adresses des variables
    ptrA = &varA;
    ptrB = &varB;

    printf("varA = %d, taille  varA = %ld , taille ptrA = %ld\n",
            varA,sizeof(varA),sizeof(ptrA));
    printf("varB = %.4f  , taille  varB = %ld , taille ptrB = %ld \n",
            varB,sizeof(varB),sizeof(ptrB));
    printf("varc = %c  , taille  varB = %ld , taille ptrB = %ld \n",
            varC,sizeof(varC),sizeof(ptrC));
    printf("Affichage a partir des pointeurs\n");
    printf("varA = %d , varB = %.4f , varc = %c \n",varA,varB,varC);
    printf("%d\n", (int)((*ptrA)*(*ptrB)));
    printf("%ls\n",&*ptrA);
    return 0;
}