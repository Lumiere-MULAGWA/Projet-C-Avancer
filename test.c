#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Liste de prénoms
const char* prenoms[] = {
    "Alice", "Bob", "Charlie", "David", "Eva", "Frank", "Grace", "Hannah"
};

// Structure pour stocker les prénoms générés
typedef struct {
    char* nom;
} Prenom;

// Fonction pour générer un prénom aléatoire
const char* genererPrenomAleatoire() {
    int index = rand() % (sizeof(prenoms) / sizeof(prenoms[0]));
    return prenoms[index];
}

// Fonction principale
int main() {
    int nombrePrenoms;
    printf("Combien de prénoms souhaitez-vous générer ? ");
    scanf("%d", &nombrePrenoms);

    // Allocation dynamique pour stocker les prénoms
    Prenom* listePrenoms = (Prenom*)malloc(nombrePrenoms * sizeof(Prenom));
    if (!listePrenoms) {
        printf("Erreur d'allocation mémoire.\n");
        return 1;
    }

    srand(time(NULL)); // Initialisation du générateur de nombres aléatoires

    for (int i = 0; i < nombrePrenoms; i++) {
        const char* prenom = genererPrenomAleatoire();
        listePrenoms[i].nom = strdup(prenom); // Copie du prénom dans la structure
    }

    // Affichage des prénoms générés
    printf("Prénoms générés :\n");
    for (int i = 0; i < nombrePrenoms; i++) {
        printf("%s\n", listePrenoms[i].nom);
    }

    // Libération de la mémoire allouée
    for (int i = 0; i < nombrePrenoms; i++) {
        free(listePrenoms[i].nom);
    }
    free(listePrenoms);

    return 0;
}
