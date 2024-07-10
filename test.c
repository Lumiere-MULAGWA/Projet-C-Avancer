#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


const char* prenoms[] = {
    "Alice", "Bob", "Charlie", "David", "Eva", "Frank", "Grace", "Hannah","Chan"
};
typedef struct {
    char* nom;
} Prenom;
const char* genererPrenomAleatoire() {
    int index = rand() % (sizeof(prenoms) / sizeof(prenoms[0]));
    return prenoms[index];
}

int main() {
    int nombrePrenoms;
    printf("Combien de prénoms souhaitez-vous générer ? ");
    scanf("%d", &nombrePrenoms);
    
    Prenom* listePrenoms = (Prenom*)malloc(nombrePrenoms * sizeof(Prenom));
    if (!listePrenoms) {
        printf("Erreur d'allocation mémoire.\n");
        return 1;
    }
    srand(time(NULL)); 

    for (int i = 0; i < nombrePrenoms; i++) {
        const char* prenom = genererPrenomAleatoire();
        listePrenoms[i].nom = strdup(prenom); // Copie du prénom dans la structure
    }

    printf("Prénoms générés :\n");
    for (int i = 0; i < nombrePrenoms; i++) {
        printf("%s\n", listePrenoms[i].nom);
    }

    for (int i = 0; i < nombrePrenoms; i++) {
        free(listePrenoms[i].nom);
    }
    free(listePrenoms);

    return 0;
}
