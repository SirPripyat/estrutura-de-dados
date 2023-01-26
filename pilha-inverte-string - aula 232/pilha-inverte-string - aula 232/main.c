//
//  main.c
//  pilha-inverte-string - aula 232
//
//  Created by Leonardo Rossi on 26/01/23.
//

#include "pilha.h"

void inverter_palavras(char x[]) {
    int i = 0;
    No *remover, *topoDaPilha = NULL;
    
    while (x[i] != '\0') {
        if (x[i] != ' ') {
            topoDaPilha = empilhar(topoDaPilha, x[i]);
        } else {
            while (topoDaPilha != NULL) {
                remover = desempilhar(&topoDaPilha);
                printf("%c", remover -> caractere);
                free(remover);
            }
            printf(" ");
        }
        i++;
    }
    
    while (topoDaPilha != NULL) {
        remover = desempilhar(&topoDaPilha);
        printf("%c", remover -> caractere);
        free(remover);
    }
    printf("\n");
}

int main(void) {
    char palavra[100] = {"ABRA A PORTA PIRUA"};
    
    inverter_palavras(palavra);
}
