#include <stdio.h>

int main()
{
    int tableau [5] ={2,4,8,16,32};
    int *ptr = tableau;
    printf("tableau [o] = %d \n",tableau[0]);
     printf("*Adresse tableau[0] = %p\n",&tableau[0]);
    printf("*ptr = %d\n",*ptr);
    printf("*Adresse ptr = %p\n",ptr);

    printf("tableau = %d \n",*tableau);
     printf("Adresse tableau = %p \n",tableau);
    
    printf("tableau[1] = %d \n",tableau[1]);
    printf("Adresse tableau [1]= %p\n",&tableau[1]);

    //parcourir tous les elements du tableau a l'aide de ptr

    printf("\n Affichage du tableau\n");
    printf("--------------------------\n");
        for(int i = 0 ;i <=4;i++)
        {
            printf("\ttableau[%d] = %d \n",i,*ptr);
            ptr =ptr + 1;
        }
        return 0;
}
