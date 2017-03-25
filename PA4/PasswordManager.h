// File Name: PasswordManager.h
//
// Author: Christian Sylvester
// Date: 03/23/2015
// Assignment Number: 4
// CS2308.251 Spring 2015
// Instructor: Jill Seaman
//
// This file contains the PasswordManager class.
#include<cstring>
#include<string>

using namespace std;

class PasswordManager{
   private:
      string psswd;
      string encrypt(string) const;
      bool verifyPassword(string) const;

   public:
      void setEncryptedPassword(string);
      string getEncryptedPassword() const;
      bool setNewPassword(string);
      bool validatePassword(string) const;
};
