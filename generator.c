#include <stdio.h>
#include <stdlib.h>
#include "lib/headers/list.h"
#include "lib/headers/conversion.h"

int main(int argc, char *argv[])
{
    if(argc == 1){
        printf("ERROR: No file names provided.\n");
        return 0;
    }

    //loop que itera por todos os arquivos fornecidos como argumento, cria uma lista contendo o conteudo do arquivo e gera um arquivo binário com o conteúdo da lista.
    for(int i = 1; i < argc; i++){
        List* list = getListFromTextFile(argv[i]);
        generateBinaryFile(list, "data.bin");
    }
    
    clear();

    return 0;
}

