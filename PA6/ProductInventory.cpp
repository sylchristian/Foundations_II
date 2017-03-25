///////////////////////////////////////////////////////////////////////////////
// File Name: ProductInventory.cpp
//
// Author: Jill Seaman
// Date: 4/12/2015
// Assignment Number: 5
// CS 2308 Spring 2015
// Instructor: Jill Seaman
//
// Represents the inventory of a small store (implementation).
// Supports adding and removing products, displaying and sorting inventory,
// and computing total number of products in inventory.
///////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <iomanip>
using namespace std;

#include "ProductInventory.h"

///////////////////////////////////////////////////////////////////////////////
// ProductInventory: constructs an empty inventory
//////////////////////////////////////////////
/////////////////////////////////
ProductInventory::ProductInventory() {
    productList = NULL;
}

///////////////////////////////////////////////////////////////////////////////
// ~ProductInventory: deallocates the inventory
///////////////////////////////////////////////////////////////////////////////
ProductInventory::~ProductInventory() {
    ProductNode *p = productList;  //traversal pointer
    ProductNode *n;                //saves the next node
    
    while (p) {
        n = p->next;
        delete p;
        p = n;
    }
}

///////////////////////////////////////////////////////////////////////////////
// addProduct: attempts to add a product to the inventory
// product: the product to add
// returns true if the the product was added.
///////////////////////////////////////////////////////////////////////////////
bool ProductInventory::addProduct(Product product) {
    //check for uniqueness of product
    ProductNode *p;  // To move through the list
    for (p = productList; p != NULL; p = p->next) {
        if (p->data == product) {
            return false;
        }
    }
    
    // check validity of price and quantity
    if (product.getPrice() <= 0 || product.getQuantity() < 0)
        return false;
    
    // Allocate a new node and store product there
    ProductNode *newNode;         // To point to a new node
    newNode = new ProductNode;
    newNode->data = product;
    newNode->next = NULL;
    
    // If empty, make newNode the first node
    if (!productList)
        productList = newNode;
    else {
        // make p point to head of list
        p = productList;
        
        // traverse list to find last node
        while (p->next)
            p = p->next;
        
        // make last node point to newNode
        p->next = newNode;
    }
    return true;
}

///////////////////////////////////////////////////////////////////////////////
// removeProduct: takes a product name and locator and removes any
//   matching entry for that product from the inventory.
// returns true if a product was found and removed.
///////////////////////////////////////////////////////////////////////////////
bool ProductInventory::removeProduct(string removeName, string removeLocator) {
    
    Product product(removeLocator,0,0,removeName); //use for comparison
    ProductNode *p = productList;     // to traverse the list
    ProductNode *n = NULL;            //trailing node (there's no prev yet)
    
    // skip nodes not equal to product, stop at last
    while (p && !(p->data==product)) {
        n = p;        // save it!
        p = p->next;  // advance it
    }

    // p not null: product is found, set links + delete
    if (p) {
        if (p==productList) {   // p points to the first elem.
            productList = p->next;
            delete p;
        } else {         // n points to the predecessor
            n->next = p->next;
            delete p;
        }
        return true;
    }
    return false;
}

///////////////////////////////////////////////////////////////////////////////
// showInventory: displays a listing of the product inventory to the screen,
//   nicely formatted, one product entry per line.
///////////////////////////////////////////////////////////////////////////////
void ProductInventory::showInventory() {
   ProductNode *p;     // to traverse the list
   p = productList;    // start p at the head of the list

   // while p points to something (is not NULL), continue
   while (p) {
      // display all values in the current node
      cout << p->data.getLocator() << endl;
      cout << p->data.getQuantity() << endl;
      cout << p->data.getPrice() << endl;
      cout << p->data.getProductName() << endl;

      // advance p to the next node
      p = p->next;
   }
   cout << endl;
}

///////////////////////////////////////////////////////////////////////////////
// getTotalQuantity:
// returns the total quantity of (copies of) products in the inventory.
///////////////////////////////////////////////////////////////////////////////
int ProductInventory:: getTotalQuantity() {
   ProductNode *p;    // to traverse the list
   p = productList;   // to start p at the head of the list
   int total = 0;     // variable to hold the total quantity to be returned

   // while p points to something, traverse the list
   while (p) {
      total += p->data.getQuantity();    // add the amt of each item to total
      p = p->next;                       // advance to the next node
   }
   return total;
}

///////////////////////////////////////////////////////////////////////////////
// removeMaximum: finds the maximum product in the list, and removes it
//   from the original list, returning a pointer to the Node.
//   It uses  operator> with Products to determine the ordering.
// returns a pointer to the Node containing the maximum Product
//  (or NULL if the list is empty).
///////////////////////////////////////////////////////////////////////////////
ProductInventory::ProductNode *ProductInventory::removeMaximum() {
   ProductNode *p = productList;             // to traverse the list
   ProductNode *maxProduct = productList;    // holder for maxProduct node

   if (!p)
      return NULL;    // return NULL if the list is empty
   
   p = p->next;    // advance p to the next node

   while (p->data > maxProduct->data && p) {
      maxProduct = p;    // copy the new max
      p = p->next;
   }

   p = productList;
   ProductNode *n = NULL;    // trailer pointer

   while (p != maxProduct) {
      n = p;
      p = p->next;
   }

   if (n != productList) {
      n->next = p->next;
   }
   else if (maxProduct = productList) {
      productList = maxProduct->next;
   }
   return maxProduct;
}

///////////////////////////////////////////////////////////////////////////////
// sortInventory:
//   Sorts the product inventory array.
//   It is sorted using the less than operator (>) of the product.
//   It uses removeMaximum to determine the ordering.
///////////////////////////////////////////////////////////////////////////////
void ProductInventory::sortInventory() {
   ProductNode *p = productList;
   ProductNode *n = NULL;

   while (p) {
      n = removeMaximum();
      n->next = NULL;
   }
}
