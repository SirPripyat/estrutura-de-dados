//
//  pilha.h
//  pilha-inverte-string - aula 232
//
//  Created by Leonardo Rossi on 26/01/23.
//

#ifndef pilha_h
#define pilha_h

#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    char caractere;
    struct no *proximoNo;
} No;

No* empilhar(No *topoDaPilha, char valor);
No* desempilhar(No **topoDaPilha);

#endif /* pilha_h */
