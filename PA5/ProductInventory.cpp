///////////////////////////////////////////////////////////////////////////////
// File Name: ProductInventory.cpp
//
// Author: Christian Sylvester
// Date: 04/19/2015
// Assignment Number: 5
// CS2308.251
// Instructor: Jill Seaman
//
// Represents the inventory of a small store (implementation). 
// Supports adding and removing products, displaying and sorting inventory,
// and computing total number of products in inventory.
#include<iostream>
#include<iomanip>
using namespace std;

#include"ProductInventory.h"

///////////////////////////////////////////////////////////////////////////////
// ProductInventory: contructs an empty inventory of the given size
///////////////////////////////////////////////////////////////////////////////
ProductInventory::ProductInventory(int size) {
   inventory = new Product[size];
   count = 0;
   capacity = size;
}

///////////////////////////////////////////////////////////////////////////////
// ~ProductInventory: deallocates the inventory array
///////////////////////////////////////////////////////////////////////////////
ProductInventory::~ProductInventory() {
   delete [] inventory;
}

///////////////////////////////////////////////////////////////////////////////
// addProduct: attempts to add a product to the inventory.
//    if the inventory is full it resizes.
//    fails if the product and locator are not unique or
//       if price or quantity are invalid.
// product: the Product to add.
// returns: true if the Product was added.
///////////////////////////////////////////////////////////////////////////////
bool ProductInventory::addProduct(Product product) {
   // check the size of the inventory
   if (count == capacity)
      resize();
   // check for uniqueness of product
   for (int i = 0; i < count; i++) {
      if (product == inventory[i])
         return false;    // already in the inventory
   }
   // check validity of price and quantity
   if (product.getPrice() > 0 && product.getQuantity() >= 0) {
      inventory[count] = product;
      count++;
      return true;
   }
   return false;
}

///////////////////////////////////////////////////////////////////////////////
// removeProduct: takes a product name and locator and removes any
//    matching entry for that product from the inventory.
// returns: true if a product was found and removed.
///////////////////////////////////////////////////////////////////////////////
bool ProductInventory::removeProduct(string removeName, string removeLocator) {
   Product remProduct(removeLocator, 0, 0, removeName);    // for comparison
   for (int i = 0; i < count; i++) {
      if (inventory[i] == remProduct) {
         inventory[i] = inventory[count - 1];    // swap in last element
         count--;
         return true;
      }
   }
   return false;
}

///////////////////////////////////////////////////////////////////////////////
// showInventory: displays a listing of the inventory to the screen,
//    nicely formatted, one product per line.
///////////////////////////////////////////////////////////////////////////////
void ProductInventory::showInventory() {
   cout << fixed << setprecision(2);
   for (int i = 0; i < count; i++) {
      Product product = inventory[i];
      cout << setw(6) << product.getLocator()
      << "  " << product.getQuantity() 
      << "  $" << product.getPrice()
      << "  " << product.getProductName() << endl;
   }
}

///////////////////////////////////////////////////////////////////////////////
// getTotalQuantity:
//    returns the total quantity of all the Products in the inventory
///////////////////////////////////////////////////////////////////////////////
int ProductInventory::getTotalQuantity() {
   int total = 0;
   for (int i = 0; i < count; i++) {
      Product product = inventory[i];
      total += product.getQuantity();
   }
   return total;
}

///////////////////////////////////////////////////////////////////////////////
// sortInventory:
//    Performs the bubble sort on the product inventory array.
//    It is sorted using the greater than (<) operator of the product
///////////////////////////////////////////////////////////////////////////////
void ProductInventory::sortInventory() {
   bool swap;       // flag, set when a swap occurs
   Product temp;    // temporary variable, used to swap the two products

   do {
      swap = false;    // reset for each new pass through the inventory
      for (int i = 0; i < (count - 1); i++) {
         // see if current Product is greater than the next
         if (inventory[i] > inventory[i + i]) {
            // if so, swap
            temp = inventory[i];
            inventory[i] = inventory[i + 1];
            inventory[i + 1] = temp;
            swap = true;
         }
      }
   } while (swap);
}

///////////////////////////////////////////////////////////////////////////////
// resize: doubles the size of the inventory array. 
//    allocates a new array and copies all the existing products to it.
///////////////////////////////////////////////////////////////////////////////
void ProductInventory::resize() {
   capacity = 2*capacity;    // double the size
   Product *newInventory = new Product[capacity];
   // copy from the old array to the new one
   for (int i = 0; i < count; i++) {
      newInventory[i] = inventory[i];
   }
   // deallocate the old inventory, befor making pointer point to new array
   delete [] inventory;
   inventory = newInventory;
}
