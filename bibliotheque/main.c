#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BOOKS 100
#define MAX_BORROWERS 50
#define MAX_BOOK_TITLE 50
#define MAX_AUTHOR_NAME 50

typedef struct {
    char title[MAX_BOOK_TITLE];
    char author[MAX_AUTHOR_NAME];
    int publicationYear;
    int available;
} Book;

typedef struct {
    int bookId;
    int borrowerId;
    char borrowDate[11];
    char dueDate[11];
    float lateFee;
} Borrow;

typedef struct {
    int id;
    char name[50];
} Borrower;

Book books[MAX_BOOKS];
Borrow borrows[MAX_BOOKS];
Borrower borrowers[MAX_BORROWERS];
int numBooks = 0, numBorrows = 0, numBorrowers = 0;

void addBook() {
    if (numBooks < MAX_BOOKS) {
        printf("Entrez le titre du livre : ");
        scanf("%[^\n]s", books[numBooks].title);
        getchar();
        printf("Entrez le nom de l'auteur : ");
        scanf("%[^\n]s", books[numBooks].author);
        getchar();
        printf("Entrez l'année de publication : ");
        scanf("%d", &books[numBooks].publicationYear);
        getchar();
        books[numBooks].available = 1;
        numBooks++;
        printf("Livre ajouté avec succès.\n");
    } else {
        printf("Limite de livres atteinte.\n");
    }
}

void searchBooks() {
    char searchTitle[MAX_BOOK_TITLE];
    char searchAuthor[MAX_AUTHOR_NAME];
    int found = 0;

    printf("Recherche de livre par titre ou auteur.\n");
    printf("Entrez le titre (ou une partie) : ");
    scanf("%[^\n]s", searchTitle);
    getchar();
    printf("Entrez le nom de l'auteur (ou une partie) : ");
    scanf("%[^\n]s", searchAuthor);
    getchar();

    printf("Livres correspondants :\n");
    for (int i = 0; i < numBooks; i++) {
        if (strstr(books[i].title, searchTitle) != NULL && strstr(books[i].author, searchAuthor) != NULL) {
            printf("Titre : %s, Auteur : %s, Année : %d, Disponibilité : %s\n",
                   books[i].title, books[i].author, books[i].publicationYear,
                   books[i].available ? "Oui" : "Non");
            found = 1;
        }
    }
    if (!found) {
        printf("Aucun livre correspondant.\n");
    }
}

void borrowBook() {
    int bookId, borrowerId;
    int found = 0;

    printf("Emprunt de livre.\n");
    printf("Entrez l'ID du livre : ");
    scanf("%d", &bookId);
    getchar();
    printf("Entrez l'ID de l'emprunteur : ");
    scanf("%d", &borrowerId);
    getchar();

    for (int i = 0; i < numBooks; i++) {
        if (books[i].available == bookId && books[i].available) {
            for (int j = 0; j < numBorrowers; j++) {
                if (borrowers[j].id == borrowerId) {
                    // Enregistrer l'emprunt
                    borrows[numBorrows].bookId = bookId;
                    borrows[numBorrows].borrowerId = borrowerId;
                    // Configurer la date d'emprunt et de retour prévu
                    // ...
                    books[i].available = 0;
                    numBorrows++;
                    printf("Livre emprunté avec succès.\n");
                    found = 1;
                    break;
                }
            }
            if (!found) {
                printf("Emprunteur inconnu.\n");
            }
            break;
        }
    }
    if (!found) {
        printf("Livre indisponible.\n");
    }
}

void returnBook() {
    int bookId, borrowerId;
    int found = 0;
    float lateFee = 0.0;

    printf("Retour de livre.\n");
    printf("Entrez l'ID du livre : ");
    scanf("%d", &bookId);
    getchar();
    printf("Entrez l'ID de l'emprunteur : ");
    scanf("%d", &borrowerId);
    getchar();

    for (int i = 0; i < numBorrows; i++) {
        if (borrows[i].bookId == bookId && borrows[i].borrowerId == borrowerId) {
            
            books[bookId].available = 1;
            borrows[i].lateFee = lateFee;
            printf("Livre retourné avec succès. Frais de retard : %.2f€\n", lateFee);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Emprunt introuvable.\n");
    }
}
void generateReports() {
  //generer un rapport 
}

int main() {
    int choice;

    do {
        printf("\nMenu de la bibliothèque :\n");
        printf("1. Ajouter un livre\n");
        printf("2. Rechercher des livres\n");
        printf("3. Emprunter un livre\n");
        printf("4. Retourner un livre\n");
        printf("5. Générer des rapports\n");
        printf("6. Quitter\n");
        printf("Votre choix : ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                addBook();
                break;
            case 2:
                searchBooks();
                break;
            case 3:
                borrowBook();
                break;
            case 4:
                returnBook();
                break;
            case 5:
                generateReports();
                break;
            case 6:
                printf("Au revoir !\n");
                break;
            default:
                printf("Choix invalide. Veuillez réessayer.\n");
                main();
        }
    } while (choice != 6);

    return 0;
}
