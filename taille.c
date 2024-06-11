#include <stdio.h>
#include <stdlib.h>
#include <time.h>


char *getprenom(int nombre);
char *prenom [9] = {"lumiere","john","kevin",
                    "ben","joe","caleb",
                    "dan","andy","fred"
                    };


int main(void){
 int nombre ;
 printf("combien de nom voulez vous?: ");
 scanf("%d ",&nombre);


char get =getnombre(nombre);
 
}
char *getprenom(int *nombre){
 char* prenomfin [nombre] = {};
  
  for (int i = 0 ; i <= nombre;i++){
      int nombre_random = rand() % 9;
      prenomfin [i] = prenom[nombre_random];
      printf("%d ) %c ", i+1 , prenomfin[i]);  
  }
  
}

char *getprenom(int nombre)
{
    return NULL;
}
