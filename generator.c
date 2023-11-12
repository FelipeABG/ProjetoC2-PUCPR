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

    for(int i = 1; i < argc; i++){
        List* list = getListFromTextFile(argv[i]);
        generateBinaryFile(list, "data.bin");
    }
    
    clear();

    return 0;
}

