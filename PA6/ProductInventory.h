///////////////////////////////////////////////////////////////////////////////
// File Name: ProductInventory.h
//
// Author: Jill Seaman
// Date: 4/12/2015
// Assignment Number: 5
// CS 2308 Spring 2015
// Instructor: Jill Seaman
//
// Represents the inventory of a small store (specification).
// Supports adding and removing products, displaying and sorting inventory,
// and computing total number of products in inventory.
///////////////////////////////////////////////////////////////////////////////
#include "Product.h"

class ProductInventory {
  private:
    struct ProductNode {        // the Nodes of the linked list
        Product data;           // data is a product
        ProductNode *next;      // points to next node in list
    };
    
    ProductNode *productList;  // the head pointer
    
    ProductNode *removeMaximum();  // return a pointer to node with max value
    
  public:
    ProductInventory();
    ~ProductInventory();
    
    bool addProduct(Product);
    bool removeProduct(string, string);
    void showInventory();
    int getTotalQuantity();
    void sortInventory();
};
