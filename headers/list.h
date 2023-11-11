typedef struct product{
    int id;
    int amount;
    float price;
    struct product *next;
} Product;

typedef struct {
    Product* head;
    int size;
} List;

void addSortedToList(List*, int, int, float);
void printList(List*);
void removeFromList(List*, int);
List* getElementsFromFile(char*);
