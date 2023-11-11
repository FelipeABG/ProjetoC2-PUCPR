#include <stdlib.h>
#include <stdio.h>
#include "headers/list.h"

int main(int argc, char *argv[])
{
    for(int i = 1; i < argc; i++){
        List* list = getListFromFile(argv[i]);
        printList(list);
        printf("-------------------------\n");
        removeFromList(list, 3);
        printList(list);
    }
    return 0;
}

