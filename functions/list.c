#include <stdlib.h>
#include <stdio.h>
#include "../headers/list.h"


void addSortedToList(List *list, int product_id, int product_amount, float product_price){

    Product *product = (Product*)malloc(sizeof(Product));
    Product *head = list->head;


    product->id = product_id;
    product->amount = product_amount;
    product->price = product_price;

    if(head == NULL){
        product->next = NULL;
        list->head = product;
    }
    else if(product->id < head->id){
        product->next = head;
        list->head = product;

    }
    else{
        while(head->next != NULL && product->id > head->next->id){
            head = head->next;
        }
        product->next = head->next;
        head->next = product;
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
    list->size --;
}

void printList(List *list){

    Product *product = list->head;

    while(product != NULL){
        printf("Product id: %d \nProduct price: %.2f \nProduct amount: %d \n\n", product->id, product->price, product->amount);
        product = product->next;
    }

}


List* getListFromFile(char* file_name){

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
        addSortedToList(list, product_id, product_amount, product_price);
    }

    fclose(file);
    return list;
}
