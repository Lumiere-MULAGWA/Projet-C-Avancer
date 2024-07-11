#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RECORDS 100
#define MAX_NAME_LENGTH 50

typedef struct {
    int id;
    char name[MAX_NAME_LENGTH];
    int age;
} Record;

typedef struct {
    Record records[MAX_RECORDS];
    int count;
} Table;

void initializeTable(Table* table) {
    table->count = 0;
}

void insertRecord(Table* table, int id, const char* name, int age) {
    if (table->count >= MAX_RECORDS) {
        printf("La table est pleine. Impossible d'insérer un nouvel enregistrement.\n");
        return;
    }

    Record* record = &(table->records[table->count]);
    record->id = id;
    strncpy(record->name, name, MAX_NAME_LENGTH - 1);
    record->name[MAX_NAME_LENGTH - 1] = '\0';
    record->age = age;

    table->count++;
}

void updateRecord(Table* table, int id, const char* name, int age) {
    for (int i = 0; i < table->count; i++) {
        if (table->records[i].id == id) {
            strncpy(table->records[i].name, name, MAX_NAME_LENGTH - 1);
            table->records[i].name[MAX_NAME_LENGTH - 1] = '\0';
            table->records[i].age = age;
            return;
        }
    }

    printf("Aucun enregistrement avec l'ID %d n'a été trouvé.\n", id);
}

void deleteRecord(Table* table, int id) {
    for (int i = 0; i < table->count; i++) {
        if (table->records[i].id == id) {
            // Déplacer les enregistrements suivants vers l'avant pour remplir l'emplacement supprimé
            for (int j = i; j < table->count - 1; j++) {
                table->records[j] = table->records[j + 1];
            }
            table->count--;
            return;
        }
    }

    printf("Aucun enregistrement avec l'ID %d n'a été trouvé.\n", id);
}

void displayRecords(const Table* table) {
    printf("ID\tNom\t\tAge\n");
    printf("--------------------------------\n");
    for (int i = 0; i < table->count; i++) {
        printf("%d\t%s\t\t%d\n", table->records[i].id, table->records[i].name, table->records[i].age);
    }
    printf("--------------------------------\n");
}

int main() {
    Table table;
    initializeTable(&table);

    insertRecord(&table, 1, "John Doe", 25);
    insertRecord(&table, 2, "Jane Smith", 30);
    insertRecord(&table, 3, "Bob Johnson", 35);

    displayRecords(&table);

    updateRecord(&table, 2, "Jane Brown", 32);

    displayRecords(&table);

    deleteRecord(&table, 1);

    displayRecords(&table);

    return 0;
}
