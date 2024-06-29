#include "etudiant.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void afficherEtudiant (Etudiant *);
void tostring(Étudiant *):
void modifierEtudiant (Etudiant *,char *nom,char *postNom,
                         char *prenom,char genre,Date dateNaiss);


/**
 * Fonction permettant de creer des etudiants 
 * allouer la memoire pour un etudiant et renvoyer le pointeur
*/
Etudiant * creerEtudiant(char *matricule,char *nom,char *postNom,
                         char *prenom,char genre,Date dateNaiss)
{
    Etudiant * etu = malloc(sizeof(Etudiant));
    if (etu != NULL){
        strcpy(etu->matricule,matricule);
        strcpy(etu->nom,nom);
        strcpy(etu->postNom,postNom);
        strcpy(etu->prenom,prenom);
        etu->genre = genre;
        etu->dateNaiss = dateNaiss;
        etu ->afficher = afficherEtudiant;
        etu->modifier = modifierEtudiant;
    }
return etu;

                        
}

void afficherEtudiant (Etudiant * etu)
{
    printf("matricule = %s Nom = %s  prenom = %s  postnom = %s genre = %s  date = %d/%d/%d ",
    etu->matricule,
    etu->nom, 
    etu->prenom,
    etu->postNom, 
    etu->genre,
    etu->dateNaiss.jour, 
    etu->dateNaiss.mois, 
    etu->dateNaiss.annee);
}
void modifierEtudiant (Etudiant * etu,char *nom,char *postNom,
                         char *prenom,char genre,Date dateNaiss){
   
    if(etu != NULL){
        strcpy(etu->nom,nom);
        strcpy(etu->postNom,postNom);
        strcpy(etu->prenom,prenom);
        etu->genre = genre;
        etu->dateNaiss = dateNaiss;
    }
    
    

return true;

}
