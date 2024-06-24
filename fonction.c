#include <stdio.h>

//parammetre de la ligne de commande argc et argv
int main(int argc , char *argv[]) {
  /*   int calcul = 0;
   for (int i = 0 ; i < argc ; i++) {
      
       if (i > 0){
        if (i % 2 ==1){
            printf("argv[%d] = %s\n", i, argv[i]);
        calcul = calcul + atoi(argv[i]) ;
        }
         
       }
       

   }
   printf("%d\n",(int)calcul); */
   if(argc != 4){
    return 1;
   }
   int nombre1 = atoi(argv[1]);
   int nombre2 = atoi(argv[3]);
   char operation = argv[2][0];
   switch (operation)
   {
   case '+':
        printf("%d + %d = %d \n",nombre1,nombre2,nombre1+nombre2);
        break;
    case '-':
        printf("%d - %d = %d \n",nombre1,nombre2,nombre1-nombre2);
        break;
    case '/':
        printf("%d / %d = %d \n",nombre1,nombre2,nombre1/nombre2);
        break;
    case 'x':
        printf("%d x %d = %d \n",nombre1,nombre2,nombre1*nombre2);
        break;
    default:
        printf("non valide \n");
   
   
   }
    return 0;
}

