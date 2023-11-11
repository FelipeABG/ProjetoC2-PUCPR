#include <stdlib.h>
#include <stdio.h>
#include "list.h"

int main(int argc, char *argv[])
{
    for(int i = 1; i < argc; i++){
        List* list = getElementsFromFile(argv[i]);
        printList(list);
        printf("-------------------------\n");
        removeFromList(list, 4);
        printList(list);
    }
    return 0;
}

