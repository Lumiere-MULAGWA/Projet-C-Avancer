#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
//ecrire une fonction qui prend un entier en parametre et returne un tableau de prenom
int main (){
    int nombre;
    srand(time(NULL));
    printf("entrer un nombre aleatoire: ");
    scanf("%d",&nombre);
  

    
    
    char* tableau [nombre];
    char* tableau_caractere[4] ={"lumiere","consolate","jeno","kadish"};
    for(int i = 0 ;i < nombre; i++){
        int value = rand() % 4;
        tableau[i] = tableau_caractere[value];
        printf(" %d) %s \n",i+1,tableau[i]);
    }
    
    return 0;
    
}