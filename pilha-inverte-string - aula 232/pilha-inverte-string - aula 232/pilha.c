//
//  pilha.c
//  pilha-inverte-string - aula 232
//
//  Created by Leonardo Rossi on 26/01/23.
//

#include "pilha.h"

No* empilhar(No *topoDaPilha, char valor) {
    No *novoNo = malloc(sizeof(No));
    
    if (novoNo != NULL) {
        novoNo -> caractere = valor;
        novoNo -> proximoNo = topoDaPilha;
        return novoNo;
    } else {
        printf("\nErro de alocação de memória.\n");
    }
    return NULL;
}

No *desempilhar (No **topoDaPilha) {
    No *remover = NULL;
    
    if(*topoDaPilha != NULL) {
        remover = *topoDaPilha;
        *topoDaPilha = remover -> proximoNo;
    } else {
        printf("\nNada para ser removido");
    }
    return remover;
}
