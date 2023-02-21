#include <stdio.h>
#include <stdlib.h>

#define SIZE 31 // O número 31 é o número primo + próximo do dobro do tamanho que vamos precisar (15)

void startTable(int table[]) {
    
    for (int i = 0; i < SIZE; i++) {
        table[i] = 0;
    }
    
}

int hashFunction(int key) {
    return key % SIZE;
}

void insertTable(int value, int table[]) {
    int id = hashFunction(value);
    
    while (table[id] != 0) {
        id = hashFunction(id + 1);
    }
    table[id] = value;
}

int searchValue(int table[], int key) {
    int id = hashFunction(key);
    printf("\nID: %d", id);
    while (table[id] != 0) {
        if (table[id] == key) {
            return table[id];
        } else {
            id = hashFunction(id + 1);
        }
    }
    return 0;
}

void printTable (int table[]) {
    
    for (int i = 0; i < SIZE; i++) {
        printf("%d = %d\n", i, table[i]);
    }
    
}

int main(void) {
    
    int table[SIZE], menuOption, value, returnValue;
    
    startTable(table);
    
    do {
        printf("\n1 - Insert into table");
        printf("\n2 - Search");
        printf("\n3 - Print table");
        printf("\n0 - Out");
        printf("\nChoose option: ");
        scanf("%d", &menuOption);
        
        switch (menuOption) {
            case 1:
                printf("\nWhat's the value you want insert? ");
                scanf("%d", &value);
                insertTable(value, table);
                break;
            
            case 2:
                printf("\nWhat's the value you want search? ");
                scanf("%d", &value);
                returnValue = searchValue(table, value);
                
                if (returnValue == 0) {
                    printf("\nValue not found\n");
                } else {
                    printf("\nValue founded!\nValue: %d\n", returnValue);
                }
                break;
                
            case 3:
                printTable(table);
                break;
                
            case 0:
                printf("\n Option not founded!");
                break;
        }
        
        
    } while (menuOption != 0);
    
    return 0;
}
