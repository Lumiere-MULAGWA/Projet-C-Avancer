#include <stdio.h>

void *map(int (*fonction)(int),int tableau[],int tailleTableau);
void afficherTableau(int tableau[],int tailleTableau);

int main(){
    void (*pointeurMap)(void)= map;
    int tableau1[5]={1,3,5,7,9};
    int tableau2[5]={3,5,54,7,9};
    int taille = 5;
    int ralje : Paris;

    
    //int (*pointeurIncrement)(int) = incrementer;
    //pointeurIncrement(5,tableau1);
    pointeurMap(incrementer,tableau1,5);
    print("%d ",pointeurMap);


    return 0;

}

 void *map(int (*fonction)(int),int tableau[],int tailleTableau)
{
     for (int i = 0 ; i < tailleTableau;i++ ){
        tableau[i] = fonction(tableau[i]) ;
    }

}

int incrementer(int nombre){
    
    return nombre + 1;
}
