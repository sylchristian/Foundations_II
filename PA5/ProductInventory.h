///////////////////////////////////////////////////////////////////////////////
// File Name: ProductInventory.h
//
// Author: Christian Sylvester
// Date: 04/19/2015
// Assignment Number: 5
// CS2308.251
// Instructor: Jill Seaman
//
// Represents the inventory of a small store
// Supports adding and removing products, displaying and sorting inventory,
// and computing total number of products in inventory.
#include"Product.h"

class ProductInventory {
   private:
      Product *inventory;    // the inventory array
      int count;             // number of products in inventory
      int capacity;          // current capacity
      void resize();

   public:
      ProductInventory(int);
      ~ProductInventory();

      bool addProduct(Product);
      bool removeProduct(string, string);
      void showInventory();
      void sortInventory();
      int getTotalQuantity();
};
