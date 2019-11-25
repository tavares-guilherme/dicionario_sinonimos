#include "hash.h"

//  Dado uma string, retorna seu codigo da funcao hash, ou seja, retorna o indice
//do vetor hash, em que devemos buscar esta string.
int hash(HASH tabela[], char* chave) {

    printf("string: %s\n", chave);

    int codigo = 0;
    int temp = 0;
    
    while(chave[temp] != '\0'){
        codigo += (int) chave[temp];
        temp++;
    }

    return codigo%10000;
}

int hash_buscar(HASH tabela[], char* chave) {
    printf("Buscando...\n");
    return 0;
}

int hash_inserir(HASH tabela[], char* chave) {
    printf("Inserindo...\n");
    return 0;
}

int hash_remover(HASH tabela[], char* chave) {
    printf("Removendo...\n");
    return 0;
}

