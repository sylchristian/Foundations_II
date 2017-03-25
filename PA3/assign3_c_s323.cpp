// File Name: assign3_c_s323.cpp
//
// Author: Christian Sylvester
// Date: 03/01/2015
// Assignment Number: 3
// CS2308.251
// Instructor: Jill Seaman
//
// This program performs five exercises that use pointers in different ways.

#include<iostream>
using namespace std;

//*****************************************************************************
// maximum: This function takes the first test array and finds the
// highest value stored within.
//
// int *arr: Is the test array.
// int size: Is the size of the test array.
// returns: The maximum value in the array.
//*****************************************************************************
int maximum(int *arr, int size){
    int max = 0;

    for (int i = 0; i < size; i++){
        if (*arr > max){
            max = *arr;
        }

        arr++;
    } 

    return max;
}

//*****************************************************************************
// oddSwap: This function takes two integer variables and performs some
// calculations on them and reassigns them.
//
// int *x: The address of the first variable.
// int *y: The address of the second variable.
// returns: The sum of the two altered variables.
//*****************************************************************************
int oddSwap (int *x, int *y){
    int temp = *x;
    *x = *y * 5;
    *y = temp * 5;  

    return *x + *y;
}

//*****************************************************************************
// resize: This function takes an array and creates a copy that is twice the
// size of the original and fills the first half with the same contents as the
// first array, while initializing the rest to-1.
//
// int *arr: The test array.
// int size: The size of the test array.
// returns: The pointer to a dynamically allocated array.
//*****************************************************************************
int *resize(int *arr, int size){
    int *newArray;

    if (size <= 0){
        return NULL;
    }

    newArray = new int [size * 2];
    
    for (int i = 0; i < size; i++){
        *(newArray + i) = *(arr + i);
    }

    for (int i = size; i < size * 2; i++){
        *(newArray + i) = -1;
    }

    return newArray;
    delete [] newArray;
}

//*****************************************************************************
// concatenate: This function takes two functions and combines them.
//
// int *arr: The first test array.
// int *arr2: the second test array.
// int size: The size of the first test array.
// int size2: The size of the second test array.
// returns: The pointer to a dynamically allocated array.
//*****************************************************************************
int *concatenate(int *arr, int *arr2, int size, int size2){
    int *newArray;

    if (size <= 0){
        return NULL;
    }

    newArray = new int [size + size2];

    for (int i = 0; i < size; i++){
        *(newArray + i) = *(arr + i);
    }

    for (int i = size; i < size + size2; i++){
        *(newArray + i) = *(arr2 + (i - size));
    }
    
    return newArray;
    delete [] newArray;
}

//*****************************************************************************
// duplicateArray: This function creates a copy of arrays passed to it.
//
// int *arr: The test array.
// int start: The beginning of where we want the function to start copying from
// the original arrray.
// int size: The size of the new array to be filled.
// returns: The pointer to a dynamically allocated array.
//*****************************************************************************
int *duplicateArray(int *arr, int start, int size){
    int *newArray;
    if (size <= 0){
        return NULL;
    }

    newArray = new int [size];

    for (int i = 0; i < size; i++){
        *(newArray + i) = *(arr + (i + start));
    }

    return newArray;
    delete [] newArray;
} 

//*****************************************************************************
// subArray: This array creates a new array that is a smaller subsection of an
// array that is passed to it.
//
// int *array: The test array.
// int start: Where we want the function to begin copying the old array.
// int length: The length of the new array.
// returns: The pointer to a dynamically allocated array.
//*****************************************************************************
int *subArray(int *array, int start, int length){
    int *result = duplicateArray(array, start, length);

    return result;
}

//*****************************************************************************
// main: Main function from which all others are called.
//
// returns: 0 upon successful completion.
//*****************************************************************************
int main(){
    int size = 10;                                       // Size of first array
    int size2 = 5;                                       // Size of second array
    int testArray[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};    // Main test array
    int testArray2[] = {-1, -2, -3, -4, -5};             // Second test array
    int max;                                             // Var. for max
    int a = 3;                                           // Int 1 for oddSwap
    int b = 5;                                           // Int 2 for oddSwap
    int start = 5;                                       // subArray start
    int length = 4;                                      // subArray length

    cout << "testing maximum:" << endl;    // Beginning of maximum test
    cout << "test data:";

    for (int i = 0; i < size; i++){
        cout << testArray[i] << " ";
    }

    cout << endl << "expected maximum: " << 10 << endl;
    cout << "actual maximum: " << maximum(testArray, size) << endl << endl;

    cout << "testing oddSwap:" << endl;    // Beginning oddSwap test
    cout << "test data: a: " << a << " b: " << b << endl;
    cout << "expected result: " << 40 << " a: " << 25 << " b: " << 15 << endl;

    int z = oddSwap(&a, &b);

    cout << "actual result: " << z << " a: " << a << " b: " << b
    << endl << endl;

    cout << "testing resize:" << endl;    // Beginning resize test
    cout << "test data: ";

    for (int i = 0; i < size; i++){
        cout << testArray[i] << " ";
    }

    cout << endl << "expected result: " << 1 << " " << 2 << " " << 3 << " " <<
    4 << " " << 5 << " " << 6 << " " << 7 << " " << 8 << " " << 9 << " " << 10 
    << " " << -1 << " " << -1 << " " << -1 << " " << -1 << " " << -1 << " " <<
    -1 << " " << -1 << " " << -1 << " " << -1 << " " << -1 << endl;
    cout << "actual result: ";

    for (int i = 0; i < size * 2; i++){
        cout << *(resize(testArray, size) + i) << " ";
    }

    cout << endl << endl;

    cout << "testing concatenate:" << endl;    // Beginning concatenate test
    cout << "test data: ";

    for (int i = 0; i < size; i++){
        cout << testArray[i] << " ";
    }

    cout << "and ";

    for (int i = 0; i < size2; i++){
        cout << testArray2[i] << " ";
    }

    cout << endl << "expected result: " << 1 << " " << 2 << " " << 3 << " " << 
    4 << " " << 5 << " " << 6 << " " << 7 << " " << 8 << " " << 9 << " " << 10 
    << " " << -1 << " " << -2 << " " << -3 << " " << -4 << " " << -5 << endl;
    cout << "actual result: "; 

    for (int i = 0; i < size + size2; i++){
        cout << *(concatenate(testArray, testArray2, size, size2) + i) << " ";
    }

    cout << endl << endl;

    cout << "testing subArray:" << endl;    // Beginning subArray test
    cout << "test data: ";

    for (int i = 0; i < size; i++){
        cout << testArray[i] << " ";
    }

    cout << endl << "start: " << 5 << " length: " << 4 << endl;
    cout << "expected result: " << 6 << " " << 7 << " " << 8 << " " << 9 << 
    endl;
    cout << "actual results: ";

    for (int i = 0; i < length; i++){
        cout << *(subArray(testArray, start, length) + i) << " ";
    }

    cout << endl;

    return 0;
}
