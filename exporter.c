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

    // itera pelos arquios binários recebidos como argumento e transforma o conteúdo do arquivo em texto.
    for(int i = 1; i <argc; i++ ){
        generateTextFile(argv[i]);
    }

    clear();
    return 0;
}
