#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../headers/list.h"

//Gera um arquivo em formato binário baseado nos dados fornecidos no parâmetro (lista). O arquivo gerado tem o nome fornecido nos parâmetros.
void generateBinaryFile (List *data, char* file_name){

    char path[1000] = "lib/files/binary/";
    strcat(path, file_name);

    FILE *file = fopen(path, "wb");

    Product *product = data->head;

    if(file == NULL){
        printf("ERROR: Could not open file.\n");
        return;
    }

    while(product != NULL){
        fwrite(product, sizeof(Product), 1, file);
        product = product->next;
    }

    fclose(file);
    
}

//Gera um arquivo em formato texto baseado nos arquvio binário passado como parâmetro.
void generateTextFile (char* file_name){

    FILE *binary_file = fopen(file_name, "rb");
    FILE *text_file = fopen("lib/files/text/data.txt", "w");
    Product *product = (Product*) malloc(sizeof(Product));

    if(binary_file == NULL){
        printf("ERROR: The following file could not be opened: %s\n", file_name);
        return;
    }

    while(fread(product, sizeof(Product), 1, binary_file)){
        fprintf(text_file, "%d %d %.2f\n", product->id, product->amount, product->price);
    }

    fclose(binary_file);
    fclose(text_file);
    free(product);

}