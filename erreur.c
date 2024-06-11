#include <stdio.h>

int main(){
    int  jour1,jour2,mois1,mois2,anne1,anne2,grand1,grand2;
    printf("Saisir la date 1 au format jj/mm/aaaa: ");
    
    if (scanf("%d/%d/%d",&jour1,&mois1,&anne1) != 3){
        printf("Votre saisie est incorecte.\n");
        return 1;

    }
    printf("enre votre deuxieme date:");
  if (scanf("%d/%d/%d",&jour2,&mois2,&anne2) != 3){
        printf("Votre saisie est incorecte.\n");
        return 1;
    }
   
    if (anne1 > anne2){
      
            printf("la date %d / %d / %d est plus grande que la date %d / %d / %d \n",jour1,mois1 , anne1,jour2 , mois2 , anne2);
    }
    else if (anne1 < anne2){
        printf("la date %d/%d/%d est plus grande que la date %d/%d/%d \n",jour2 , mois2 , anne2,jour1,mois1 , anne1);

    }
    else if (anne1 == anne2){
         if (mois1 > mois2) {
            printf("la date %d / %d / %d est plus grande que la date %d / %d / %d \n",jour1,mois1 , anne1,jour2 , mois2 , anne2);
        }
        else if (mois1 == mois2){
            if (jour1 > jour2){
                printf("la date %d / %d / %d est plus grande que la date %d / %d / %d \n",jour1,mois1 , anne1,jour2 , mois2 , anne2);
            }
            else if(jour1 == jour2){
                printf("la date %d / %d / %d est identique que la date %d / %d / %d \n",jour1,mois1 , anne1,jour2 , mois2 , anne2);

            }
        }
        else{
            printf("la date %d / %d / %d est plus grande que la date %d / %d / %d \n",jour2 , mois2 , anne2,jour1,mois1 , anne1);
        }
         

    }
    return 0;

}