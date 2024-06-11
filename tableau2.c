#include <stdio.h>

int main()
{
    int tableau[2][3]={
                        {1,2,4},
                        {7,8,9}
                    };

    int *ptr = tableau;
    //boucle pour afficher les adresses
    printf("Affichage des emplacements memoires \n");
    printf("-----------------------------------------\n");
    for (int i = 0;i<2;i++){
        printf(" i %d : ",i);
        for(int j=0;j<3;j++){
            printf(", %d ",&tableau[i][j]);
        }
        printf("\n"); 
    }
   //boucle pour parcourir le tableau 
    printf("\nAffichage des elements \n");
    printf("--------------------------\n");
    while(ptr !=tableau + 2){
        printf("element : %d\n",*ptr);
        ptr ++;
    }
    
}