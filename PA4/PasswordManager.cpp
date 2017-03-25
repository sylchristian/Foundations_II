// File name: PasswordManager.cpp
//
// Author: Christian Sylvester
// Date: 03/23/2015
// Assignment Number: 4
// CS2308.251 Spring 2015
// Instructor: Jill Seaman
//
// This file contains the function definitions for the PasswordManager class.
#include<cstring>
#include<iostream>
#include<cctype>
#include<string>
#include"PasswordManager.h"

using namespace std;

//*****************************************************************************
// Function Name: setEncryptedPassword takes the proposed password and applies
// the encryption algorithm to it once it has been validated.
//
// Parameter 1: The new password.
// Returns: Nothing, this is a setter function.
//*****************************************************************************
void PasswordManager::setEncryptedPassword(string password){
   psswd = password;
}
//*****************************************************************************
// Function Name: setNewPassword takes the proposed new password from the user
// and checks to see that it meets our criteria. It returns false if not. If it
// does, it encrypts the new password for storage.
//
// Parameter 1: The new proposed password.
// Returns: True if the new password meets our specs and is encrypted.
//*****************************************************************************
bool PasswordManager::setNewPassword(string password){
   if (!verifyPassword(password)){
      return false;
   }
   else{
      setEncryptedPassword(encrypt(password));
      
      return true;
   }
}
//*****************************************************************************
// Function Name: verifyPassword tests the new proposed password to make sure it
// meets our criteria.
//
// Parameter 1: The new proposed password.
// Returns: True if the new password passes the tests.
//*****************************************************************************
bool PasswordManager::verifyPassword(string password) const{
   if (password.length() < 8){
      return false;
   }
   bool flag = false;   // Flag used to validate password

   for (int i = 0; i < password.length(); i++){
      if (isupper(password[i])){
         flag = true;
      }
      else if (flag = true){
         break;
      }
      else if (i = password.length()){
         return false;
      }
   }
   flag = false;   // Reset to false after each test

   for (int i = 0; i < password.length(); i++){
      if (isdigit(password[i])){
         flag = true;
      }
      else if (flag = true){
         break;
      }
      else if (i = password.length()){
         return false;
      }
   }
   flag = false;

   for (int i = 0; i < password.length(); i++){
      if (password[i] = '!'){
         return true;
      }
      else if (password[i] = '@'){
         return true;
      }
      else if (password[i] = '#'){
         return true;
      }
      else if (password[i] = '$'){
         return true;
      }
      else if (i = password.length()){
         return false;
      }
   }
}
//*****************************************************************************
// Function Name: encrypt takes the new password and applies the encryption
// algorithm to it and reassigns it to a new string.
//
// Parameter 1: The new proposed password.
// Returns: A string containing the encrypted password.
//*****************************************************************************
string PasswordManager::encrypt(string password) const{
   int SIZE = password.length() + 1;
   char encryptedPassword[SIZE];

   for (int i = 0; i < password.length(); i++){
      encryptedPassword[i] = password[i] ^ '5';        
   }
   return encryptedPassword;
}
//*****************************************************************************
// Function Name: getEncryptedPassword returns the stored encrypted password.
//
// Parameter 1: None
// Returns: A string containing the encrypted stored password.
//*****************************************************************************
string PasswordManager::getEncryptedPassword() const{
   return psswd;
}
//*****************************************************************************
// Function Name: validatePassword checks the password input by the user against
// the encrypted password that is stored in the file.
//
// Parameter 1: The password input by the user to check.
// Returns: True if the passwords match.
//*****************************************************************************
bool PasswordManager::validatePassword(string password) const{
   if (encrypt(password) == getEncryptedPassword()){
      return true;
   }
   else{
      return false;
   }
}
