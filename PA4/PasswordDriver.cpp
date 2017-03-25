// File Name: PasswordDriver.cpp
//
// Author: Christian Sylvester
// Date: 03/23/2015
// Assignment Number: 4
// CS2308.251 Spring 2015
// Instructor: Jill Seaman
//
// This file is the driver for the password manager. It contains the main 
// function.
#include<iostream>
#include<cstring>
#include<string>
#include<cctype>
#include<fstream>
#include"PasswordManager.h"

using namespace std;

int main(){
   string pwd;   // String that stores any new input from the user.

   PasswordManager password;   // Created instance of PasswordManager

   // Creation of file I/O objects
   ifstream fin;
   ofstream fout;
   fin.open("password.txt");

   if (fin){
      fin >> pwd;
    
      password.setEncryptedPassword(pwd);
   }
   else if (!fin){
      pwd = "ABC123$$$";

      password.setNewPassword(pwd);
   }
   fin.close();

   char usrinput;   // Character for menu input

   // Beginning of the main menu loop
   do{
      cout << "Password Utilities:" << endl;
      cout << "A. Change Password" << endl;
      cout << "B. Validate Password" << endl;
      cout << "C. Quit" << endl;
      cout << "Please input your selection:" << endl;
      cin >> usrinput;

      switch (usrinput){
         case 'A':
            cout << "Please input a new password below. It must be at" << endl;
            cout << "least 8 characters long and contain at least one" << endl;
            cout << "uppercase letter. It must contain at least one" << endl;
            cout << "digit, and either an '!,' an '@,' a '#' or a '$.'" << endl;
            cin >> pwd;

         if (password.setNewPassword(pwd)){
            fout.open("password.txt");
            fout << password.getEncryptedPassword();
            fout.close();
            cout << "The password has been successfully updated." << endl;
         }
         else{
            cout << "The password was not altered." << endl;
         }
         break;

         case 'B':
            cout << "Please input your password: " << endl;
            cin >> pwd;
         
         if (password.validatePassword(pwd)){
            cout << "Password is valid!" << endl;
         }
         else{
            cout << "The password you entered does not match." << endl;
         }
         break;

         case 'C':
            cout << "You have chosen to quit." << endl;
            fout.open("password.txt");
            fout << password.getEncryptedPassword();
            fout.close();

            break;
      }
   }while (usrinput != 'C');
   return 0;
}
