#include <stdio.h>
#include <stdlib.h>
#include "headers/list.h"
#include "headers/conversion.h"

int main(int argc, char *argv[])
{
    if(argc == 1){
        printf("ERROR: No file names provided.\n");
        return 0;
    }

    for(int i = 1; i <argc; i++ ){
        generateTextFile(argv[i]);
    }

    return 0;
}
