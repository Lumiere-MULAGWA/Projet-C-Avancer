#include <stdio.h>

typedef struct 
{
    int a;
    int b;
} Donnee;
typedef int Entier;

int main (){

    Donnee varDonnee = {
        .a =5 ,.b =9
    };
    Donnee *ptr = &varDonnee;
    printf("Structure :.A = %d , .B = %d \n",varDonnee.a,varDonnee.b);
    printf("Pointeur :.A = %d , .B = %d \n",ptr->a,ptr->b);
    return 0;
}