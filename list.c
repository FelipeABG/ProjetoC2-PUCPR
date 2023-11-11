#include <stdlib.h>
#include <stdio.h>
#include "list.h"


void addToEnd(List *list, int product_id, int product_amount, float product_price){

    Product *product = (Product*)malloc(sizeof(Product));
    Product *iterator = list->head;

    product->id = product_id;
    product->amount = product_amount;
    product->price = product_price;
    product->next = NULL;

    if(list->head == NULL){
        list->head = product;
    }
    else{
        while(iterator->next != NULL){
            iterator = iterator->next;
        }
        iterator->next = product;
    }
    list->size ++;
}

void removeFromList(List *list, int product_id){

    Product *head = list->head;
    Product *elementToBeRemoved = NULL;

    if(head == NULL){
        printf("ERROR: List is empty.\n");
        return;
    }

    if(head->id == product_id){
        elementToBeRemoved = head;
        list->head = head->next;
    }
    else{
        while(head->next->id != product_id && head->next != NULL){
            head = head->next;
        }
        elementToBeRemoved = head->next;
        head->next = elementToBeRemoved->next;
    }
    free(elementToBeRemoved);
}

void printList(List *list){

    Product *product = list->head;

    while(product != NULL){
        printf("Product id: %d \nProduct price: %.2f \nProduct amount: %d \n\n", product->id, product->price, product->amount);
        product = product->next;
    }

}


List* getElementsFromFile(char* file_name){

    FILE* file = fopen(file_name, "r");
    List* list = (List*)malloc(sizeof(List));

    if(file == NULL){
        printf("Error opening file %s\n", file_name);
        exit(1);
    }

    list->head = NULL;
    list->size = 0;

    int product_id, product_amount;
    float product_price;

    while(fscanf(file, "%d %d %f", &product_id, &product_amount, &product_price) != EOF){
        addToEnd(list, product_id, product_amount, product_price);
    }

    fclose(file);

    return list;
}
