#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int value;
    struct node *next;
} Node;

Node* push(Node *stack, int number) {
    Node *newNode = malloc(sizeof(Node));
    
    if (newNode != NULL) {
        newNode -> value = number;
        newNode -> next = stack;
        
        return newNode;
    } else {
        printf("\nERROR!\n");
    }
    return NULL;
}

Node* pop(Node **stack) {
    Node *trash = NULL;
    
    if (*stack != NULL) {
        trash = *stack;
        *stack = trash -> next;
        
    } else {
        printf("\nNothing to remove\n");
    }
    
    return trash;
}

void print(Node *stack) {
    
    printf("\n----- START -----\n");
    
    while (stack -> next != NULL) {
        printf("%d ", stack -> value);
        stack = stack -> next;
    }
        

    printf("\n------ END ------");
}

int factorial(int number) {
    Node *stack = NULL;
    Node *trash = NULL;
    
    while (number > 1) {
        stack = push(stack, number);
        number--;
    }
    
    print(stack);
    
    while (stack != NULL) {
        trash = pop(&stack);
        number = number * trash -> value;
        free(trash);
    }
    
    return number;
}

int main (void) {
    
    int value;
    
    printf("Write a number: ");
    scanf("%d", &value);
    
    printf("\nFactorial of %d: %d", value, factorial(value));
    
    
    printf("\n\n");
}

