#ifndef STORAGE_H
#define STORAGE_H

#define MAX_PRODUCTS 200

typedef struct {
    int id;
    char name[50];
    int quantity;
    char category[50];
} Product;

extern Product products[MAX_PRODUCTS];
extern int productCount;



void addProduct(Product *products, int *productCount, const Product newProduct);
void deleteProduct(Product *products, int *productCount, int id);
void printAllProducts(const Product *products, int productCount);
void findProductWithLeastStock(const Product *products, int productCount);
void findProductWithMostStock(const Product *products, int productCount);
void saveProductsToFile(const Product *products, int productCount);
void loadProductsFromFile(Product *products, int *productCount);
void filterProductsByCategory(const Product *products, int productCount, const char *category);
void filterProductsByQuantity(const Product *products, int productCount, int minQuantity, int maxQuantity);

#endif 
