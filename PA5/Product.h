///////////////////////////////////////////////////////////////////////////////
// File Name: Product.h
//
// Author: Christian Sylvester
// Date: 04/18/2015
// Assignment Number: 6
// CS2308.251 Spring 2015
// Instructor: Jill Seaman
//
// Represents the product in the inventory of a small store
///////////////////////////////////////////////////////////////////////////////
#include<string>
using namespace std;

class Product {
   private:
      string productName;    // product description
      string locator;        // location of the product in the store
      int quantity;          // number of copies in the inventory
      double price;          // selling price of the product

   public:
      Product();
      Product(string, int, double, string);
      
      string getLocator();
      int getQuantity();
      double getPrice();
      string getProductName();

      void setLocator(string);
      void setQuantity(int);
      void setPrice(double);
      void setProductName(string);
      
      bool operator < (Product);
      bool operator > (Product);
      bool operator == (Product);
};
