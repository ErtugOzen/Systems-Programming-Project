#include <stdio.h>
#include "storage.h"


void displayMenu() {
    printf("\n Lawrence Craft's Storage\n");
    printf("1. Add Product\n");
    printf("2. Delete Product\n");
    printf("3. Show All Products\n");
    printf("4. Show Minimum Product In Stock\n");
    printf("5. Show Most Product In Stock\n");
    printf("6. Save To File\n");
    printf("7. Upload From File\n");
    printf("8. Filter by Category\n");
    printf("9. Filter by Quantity Range\n");
    printf("10. Quit\n");
    printf("Select Number : ");
}

void getInput() {
    int choice;
    Product p;
    int id;
    char category[50];
    int minQuantity, maxQuantity;

    while (1) {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Product ID: ");
                scanf("%d", &p.id);
                printf("Product Name: ");
                scanf("%s", p.name);
                printf("Product Quantity: ");
                scanf("%d", &p.quantity);
                printf("Product Category: ");
                scanf("%s", p.category);
                addProduct(products, &productCount, p);
                break;
            case 2:
                printf("ID of the Product will be Deleted: ");
                scanf("%d", &id);
                deleteProduct(products, &productCount, id);
                break;
            case 3:
                printf("Available Products:\n");
                printAllProducts(products, productCount);
                break;
            case 4:
                findProductWithLeastStock(products, productCount);
                break;
            case 5:
                findProductWithMostStock(products, productCount);
                break;
            case 6:
                saveProductsToFile(products, productCount);
                printf("Products saved to file.\n");
                break;
            case 7:
                loadProductsFromFile(products, &productCount);
                break;
            case 8:
                printf("Category that will be filtered: ");
                scanf("%s", category);
                filterProductsByCategory(products, productCount, category);
                break;
            case 9:
                printf("Min: ");
                scanf("%d", &minQuantity);
                printf("Max: ");
                scanf("%d", &maxQuantity);
                filterProductsByQuantity(products, productCount, minQuantity, maxQuantity);
                break;
            case 10:
                return; 
            default:
                printf("Invalid selection, please try again .\n");
        }
    }
}

int main() {
    getInput();
    return 0;
}
