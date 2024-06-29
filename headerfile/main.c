#include "etudiant.h"
#include <stdio.h>

int main (){
    char * matricule = "21mb389";
    char * nom = "lmr";
    char * postNom = "lum";
    char * prenom = "lucifer";
    char genre = "M";
    Date dateN = {.jour = 5,.mois = 5 ,.annee = 2010};

    Etudiant * etudiant1 = creerEtudiant(matricule,nom,postNom,prenom,genre,dateN);
    etudiant1 -> afficher(etudiant1);

    free(etudiant1);    
    return 0;
}
