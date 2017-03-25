// File Name: assign7_c_s323.cpp
//
// Author: Christian Sylvester
// Date: 04/29/2015
// Assingment Number: 7
// CS2308.251 Spring 2015
// 
// Driver program for IntStack class that matches brackets from an input file

#include<fstream>
#include<iostream>
#include<string>
#include"IntStack.h"
using namespace std;

int main() {
   ifstream fin;
   string filename;
   char input;
   char closer;
   char top;

   cout << "Please enter a file name:" << endl;
   cin >> filename;

   fin.open(filename.c_str());

   if(!fin) {
      cout << "There was an error opening the file." << endl;
      
      return -1;
   }

   IntStack stack;

   do{
      fin >> input;

      switch(input) {
         case '{':
         case '(':
         case '[':
            stack.push(input);
            break;

         case '}':
         case ')':
         case ']':
            if(!stack.isEmpty()) {
               top = stack.pop();

               if((input == '}' && top != '{') || (input == ')' && top != '(')
                 || (input == ']' && top != '[')) {
                  cout << "Wrong bracket found " << input << endl;
               
                  return -2;
               }
            }
            else {
               cout << "You've got an extra " << input << endl;

               return -3;
            }
            break;
         default:
            break;
      }
   }while(fin);

   if(!stack.isEmpty()) {
      cout << "Missing " << top << endl;

      return -4;
   }
   else
      cout << "All brackets matched!" << endl;

   return 0;
}
