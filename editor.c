#include <stdlib.h>
#include <stdio.h>
#include "lib/headers/list.h"
#include "lib/headers/conversion.h"

int main(int argc, char *argv[]){

    //switch case que verifica quantos se apenas um arquivo foi fornecido como argumento.
    switch (argc)
    {
    case 1:
        printf("ERROR: No file name provided.");
        return 0;
    case 3:
        printf("ERROR: Only 1 file can be edited at a time.");
        return 0;
    }

    List* list = getListFromBinaryFile(argv[1]); //gera a lista com os valores contidos no arquivo binário.
    int id, amount, option, executing = 1;
    float price;
    char* string;

    clear();


    // Menu de interação com o  usuário.
    do
    {
        printf("\n\n");
        printf(" 1 - Add product\n 2 - Remove product\n 3 - Show especific product\n 4 - Generate new binary file. \n 5 - Save and exit\n");
        printf("Choose an option: ");
        scanf("%d", &option);

        switch(option){
            case 1: //Adiciona um novo produto.
                clear();
                printf("Enter product id, amount and price: ");
                if(!scanf("%d %d %f", &id, &amount, &price)){  
                    printf("ERROR: Invalid input.\n");
                    
                };
                addSortedToList(list, id, amount, price);
                break;
            case 2: //Remove um produto.
                clear();
                printf("Enter the product id: ");
                if(!scanf("%d", &id)){
                    printf("ERROR: Invalid input.\n");

                };
                removeFromList(list, id);
                break;
            case 3: //Mostra um produto específico.
                clear();
                printf("Enter the product id: ");
                if(!scanf("%d", &id)){
                    printf("ERROR: Invalid input.\n");

                };
                Product* product = getProductById(list->head, id);
                product == NULL ? printf("Product not found.\n") : printf(" Product found:\n ID: %d\n Amount: %d\n Price: %.2f\n", product->id, product->amount, product->price);
                break;
            case 4: //Gera um novo arquivo binário.
                clear();
                printf("Enter the file name (.bin): ");
                scanf("%s", string);
                generateBinaryFile(list, string);
                printf("Binary file generated successfully.");
                break;
            case 5: // Salva e sai do programa, gerando um novo arquivo binário.
                clear();
                generateBinaryFile(list, "dataEdited.bin");
                executing = 0;
                break;
            default:
                printf("ERROR: Invalid option.");
                break;
        }
    } while (executing);
    
    return 0;
}

