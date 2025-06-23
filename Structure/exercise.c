#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 1000

struct Item{
    char *itemName;
    int quantity;
    float price;
    float amount;
};

struct Item* readItem(char itemName[], int quantity, float price);
void printItem(struct Item* item);

int main(int argc, char *argv[]){
    struct Item* item1 = NULL;
    
    char itemName[MAX];
    printf("Enter Item Name: ");
    fgets(itemName, MAX, stdin);

    int quantity;
    printf("Enter Quantity: ");
    scanf("%d", &quantity);

    float price;
    printf("Enter Price: ");
    scanf("%f", &price);

    item1 = readItem(itemName, quantity, price);
    printItem(item1);
    
    free(item1->itemName);
    item1->itemName = NULL;
    
    free(item1);
    item1 = NULL;

    return 0;
}

struct Item* readItem(char itemName[], int quantity, float price){
    struct Item* res = (struct Item*) malloc (sizeof(struct Item));
    
    int len = strlen(itemName);
    if(itemName[len-1]=='\n'){
        itemName[len-1] = '\0';
        len--;
    }



    res->itemName = (char*) malloc((len + 1)*sizeof(char));
    strcpy(res->itemName, itemName);

    res->price = price;
    res->quantity = quantity;
    res->amount = price * quantity;

    return res;
}

void printItem(struct Item* item){
    printf("\nItem Details:\nItem Name:%s\nQuantity:%d\nPrice:%0.2f\nAmount:%0.2f\n", 
        item->itemName, item->quantity, item->price, item->amount
    );
}