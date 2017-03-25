///////////////////////////////////////////////////////////////////////////////
// File Name: Product.cpp
// Author: Christian Sylvester
// Date: 04/18/2015
// Assignment Number: 6
// CS2308.251
// Instructor: Jill Seaman
//
// Represents a product in the inventory of a small store
///////////////////////////////////////////////////////////////////////////////
#include"Product.h"

///////////////////////////////////////////////////////////////////////////////
// Product: contstructs a Product with default values
///////////////////////////////////////////////////////////////////////////////
Product::Product() {
   locator = "";
   quantity = 0;
   price = 0;
   productName = "";
}

///////////////////////////////////////////////////////////////////////////////
// Product: constructs a product from a locator, quantity, price
//          and productName.
///////////////////////////////////////////////////////////////////////////////
Product::Product(string newLocator, int newQuantity, double newPrice,
                 string newProductName) {
   locator = newLocator;
   quantity = newQuantity;
   price = newPrice;
   productName = newProductName;
}

// setLocator: mutator function to set the locator
void Product::setLocator(string newLocator) {
   locator = newLocator;
}

// setQuantity: mutator function to set the quantity
void Product::setQuantity(int newQuantity) {
   quantity = newQuantity;
}

// setPrice: mutator function to set the price
 void Product::setPrice(double newPrice) {
   price = newPrice;
}

// setProductName: mutator function to set the productName
void Product::setProductName(string newProductName) {
   productName = newProductName;
}

// getLocator: accessor function to return the locator
string Product::getLocator() {
   return locator;
}

// getQuantity: accessor function to return the quantity
int Product::getQuantity() {
   return quantity;
}

// getPrice: accessor function to return the price
double Product::getPrice() {
   return price;
}

// getProductName: accessor function to returnt the productName
string Product::getProductName() {
   return productName;
}

///////////////////////////////////////////////////////////////////////////////
// operator<: compares this Product to another
//    compares productNames, then locators if productNames are not equal
///////////////////////////////////////////////////////////////////////////////
bool Product::operator< (Product right) {
   if (productName == right.productName)
      return (locator < right.locator);
   return productName < right.productName;
}

///////////////////////////////////////////////////////////////////////////////
// operator>: compares this Product to another
//    compares productNames, then locators if the productNames are not equal
///////////////////////////////////////////////////////////////////////////////
bool Product::operator> (Product right) {
   if (productName == right.productName)
      return (locator > right.locator);
   return productName > right.productName;
}

///////////////////////////////////////////////////////////////////////////////
// operator==: compares this Product to another
//    Products are equal if locators and productNames are equal
///////////////////////////////////////////////////////////////////////////////
bool Product::operator== (Product right) {
   if (locator != right.locator)
      return false;
   if (productName != right.productName)
      return false;
   return true;
}
