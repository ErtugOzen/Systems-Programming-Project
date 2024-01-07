#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "storage.h"

Product products[MAX_PRODUCTS];
int productCount = 0;

void addProduct(Product *products, int *productCount, const Product newProduct) {
    if (*productCount < MAX_PRODUCTS) {
        products[*productCount] = newProduct;
        (*productCount)++;
    } else {
        printf("The storage is full! Unable to add a new product.\n");
    }
}

void deleteProduct(Product *products, int *productCount, int id) {
    int found = 0;
    for (int i = 0; i < *productCount; i++) {
        if (products[i].id == id) {
            found = 1;
            for (int j = i; j < *productCount - 1; j++) {
                products[j] = products[j + 1];
            }
            (*productCount)--;
            break;
        }
    }
    if (!found) {
        printf("No product matching ID found.\n");
    }
}

void printProduct(const Product product) {
    printf("ID: %d, Name: %s, Quantity: %d, Category: %s\n", product.id, product.name, product.quantity, product.category);
}

void printAllProducts(const Product *products, int productCount) {
    for (int i = 0; i < productCount; i++) {
        printProduct(products[i]);
    }
}

void findProductWithLeastStock(const Product *products, int productCount) {
    if (productCount == 0) {
        printf("There is no product in storage.\n");
        return;
    }

    Product leastStockProduct = products[0];
    for (int i = 1; i < productCount; i++) {
        if (products[i].quantity < leastStockProduct.quantity) {
            leastStockProduct = products[i];
        }
    }

    printf("Minimum Product In Stock:\n");
    printProduct(leastStockProduct);
}

void findProductWithMostStock(const Product *products, int productCount) {
    if (productCount == 0) {
        printf("There is no product in storage.\n");
        return;
    }

    Product mostStockProduct = products[0];
    for (int i = 1; i < productCount; i++) {
        if (products[i].quantity > mostStockProduct.quantity) {
            mostStockProduct = products[i];
        }
    }

    printf("Most Product In Stock:\n");
    printProduct(mostStockProduct);
}

void saveProductsToFile(const Product *products, int productCount) {
    FILE *file = fopen("products.dat", "wb");
    if (file == NULL) {
        perror("File Couldn't Open");
        return;
    }

    fwrite(products, sizeof(Product), productCount, file);
    fclose(file);
}

void loadProductsFromFile(Product *products, int *productCount) {
    FILE *file = fopen("products.dat", "rb");
    if (file == NULL) {
        perror("File Couldn't Open");
        return;
    }

    fread(products, sizeof(Product), MAX_PRODUCTS, file);
    fclose(file);
}

void filterProductsByCategory(const Product *products, int productCount, const char *category) {
    printf("\nCategory: %s\n", category);
    for (int i = 0; i < productCount; i++) {
        if (strcmp(products[i].category, category) == 0) {
            printProduct(products[i]);
        }
    }
}

void filterProductsByQuantity(const Product *products, int productCount, int minQuantity, int maxQuantity) {
    printf("\nQuantity Range: %d - %d\n", minQuantity, maxQuantity);
    for (int i = 0; i < productCount; i++) {
        if (products[i].quantity >= minQuantity && products[i].quantity <= maxQuantity) {
            printProduct(products[i]);
        }
    }
}
