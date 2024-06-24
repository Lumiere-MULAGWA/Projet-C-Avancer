#ifndef __ETUDIANT_H
#define __ETUDIANT_H

#include <stdbool.h>

#define TAILLE_MAT 10
#define TAILLE_NOM 30
//structure date 
typedef struct _dateNaissance{
    unsigned jour;
    unsigned mois;
    unsigned annee;
}Date;

//structure etudiant
typedef struct _etudiant Etudiant;
typedef struct _etudiant
{   
    //Attribut Etudiant
    char matricule[TAILLE_MAT];
    char nom[TAILLE_NOM];
    char postNom[TAILLE_NOM];
    char prenom[TAILLE_NOM];
    char genre;
    Date dateNaiss;

    //methodes Etudiants
void (*afficher)(Etudiant *);
void (*modifier) (Etudiant *,char *,char *,
                         char *,char ,Date )

};



Etudiant * creerEtudiant(char *matricule,char *nom,char *postNom,
                         char *prenom,char genre,Date dateNaiss);

#endif