#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash.h"

int main(){

    FILE* arq;

    arq = fopen("input.txt", "r");

    char entrada[513], idioma_original[513], idioma_novo[513];
    char comando;
    int cont = 0;
    int exec = 0;

    HASH tabela_hash[10000]; //Maximo de 10000 pares de palavras.

    while(fscanf(arq, "%s", entrada) != EOF){
        
        switch(cont){
            case 0: //Entrada esta armazenando o comando "a", "r" ou "f"
                comando = entrada[0];
                cont = 1;

                if(entrada[1] != ':' ){ //Trata o caso em que os dois pontos nao estao separados do caractere de comando
                    fscanf(arq, "%s", entrada);  //Ignora os dois pontos

                    if(strcmp(entrada, ":\0") != 0){
                        printf("ERRO entrada: %s\n", entrada);
                        return 1;
                    }
                }

                break;

            case 1: //Entrada esta armazenando uma palavra.
                
                if(comando == 'A' || comando == 'a'){ // Duas palavras serao armazenadas.
                    strcpy(idioma_original, entrada);
                    cont = 2;
                }else{
                    strcpy(idioma_novo, entrada);// Somente uma palavra sera armazenada.
                    printf("%c : %s\n", comando, idioma_novo);
                    cont = 0;
                    exec = 1;
                }

                break;
            case 2:

                strcpy(idioma_novo, entrada);
                printf("%c : %s %s\n", comando, idioma_original, idioma_novo);
                cont = 0;
                exec = 1;
                break;
        }

        if(exec){
            
            switch(comando){
                case 65:
                case 97:
                    
                    hash_inserir(NULL, entrada);
                    break;
                
                case 82:
                case 114:
                    hash_remover(NULL, entrada);
                    break;
                
                case 70:
                case 102:
                    hash_buscar(NULL, entrada);
                    break;
            }

            exec = 0;
        }
    }


    fclose(arq);

    return 0;
}
