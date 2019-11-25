#ifndef HASH_H
    #define HASH_H

    #include <stdio.h>

    #define TAMANHO_PALAVRA 513

    typedef struct hash_ {
        char original[TAMANHO_PALAVRA];
        char estrangeiro[TAMANHO_PALAVRA];
    } HASH;

    //Mudar prototipo se julgar necessario
    int hash(HASH tabela[], char* chave);
    int hash_buscar(HASH tabela[], char* chave);
    int hash_inserir(HASH tabela[], char* chave);
    int hash_remover(HASH tabela[], char* chave);

#endif