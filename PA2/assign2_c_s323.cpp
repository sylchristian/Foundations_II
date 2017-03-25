// File Name: assign2_c_s323.cpp
//
// Author: Christian Sylvester
// Date: 02/16/2015
// Assignment Number: 2
// CS2308.251 Spring 2015
// Instructor: Jill Seaman
//
// This program manages the inventory of a small store.

#include<iostream>
#include<iomanip>

using namespace std;

// Function prototypes
void add(struct Inventory product[], int SIZE, int &count, string value);
void remove(struct Inventory product[], int &count);
void adjust(struct Inventory product[], int count);
void info(struct Inventory product[], int count);
void display(struct Inventory product[], int count);
void bubbleSort(struct Inventory product[], int count);
int binarySearch(struct Inventory product[], int count, string value);

// Inventory structure definition
struct Inventory{
    string productName;
    string locator;
    int quantity;
    float price;
};

const int SIZE = 100;    // Maximum size of the product array

// Beginning of main function
int main (){
    int usrInput, i;           // User's input choice
    int count = 0;             // Counter variable; +1 when add, -1 when remove
    Inventory product[SIZE];   // Product array for the above structure
    string value;

    cout << "\nWELCOME TO THE INVENTORY MANAGER";

    // Beginning of the main menu loop
    do
    {
        cout << "\nPLEASE SELECT AN OPTION BELOW \n";
        cout << "\n1. Add a new product to the inventory. \n";
        cout << "2. Remove a product from the inventory. \n";
        cout << "3. Adjust the quantity of a product. \n";
        cout << "4. Display the information for a product. \n";
        cout << "5. Display the inventory sorted by product name. \n";
        cout << "6. Quit the program. \n";

        cin >> usrInput;
        cout << endl;

        switch (usrInput){
            case 1: cout << "YOU HAVE CHOSEN TO ADD A NEW PRODUCT TO THE";
                    cout << " INVENTORY SYSTEM \n";
                    cout << "PLEASE ENTER THE NEW PRODUCT'S NAME \n";
                    cin.ignore(100,'\n');
                    getline(cin, value);

                    i = binarySearch(product, count, value);

                    if (i <= -1){
                        add(product, SIZE, count, value);
                        bubbleSort(product, count);
                    }
                    else if (i >= 0){
                        cout << "THAT PRODUCT ALREADY EXISTS \n";
                    }
                break;

            case 2: remove(product, count);
                    bubbleSort(product, count);
                break;

            case 3: adjust(product, count);
                break;

           case 4: info(product, count);
                break;

            case 5: display(product, count);
                break;

            case 6: cout << "EXITING THE PROGRAM... \n";
                break;

            default: cout << "THAT'S NOT A CHOICE \n";
        }
    }while (usrInput != 6);

    return 0;
}

//*****************************************************************************
// Function: Add; adds a new product to the inventory.
//
// Parameter 1: The product array.
// Parameter 2: The counter variable.
//*****************************************************************************
void add(struct Inventory product[], int SIZE, int &count, string value){
    if (count < SIZE){
        product[count].productName = value;

        cout << "\nPLEASE ENTER THE LOCATOR NUMBER \n";
        cin >> product[count].locator;

        cout << "\nPLEASE ENTER THE AMOUNT YOU WOULD LIKE TO ADD \n";
        cin >> product[count].quantity;

        if (product[count].quantity <= -1){
            cout << "NEGATIVE QUANTITIES ARE NOT PERMITTED \n";
            cout << "QUANTITY WILL BE RESET TO ZERO \n";

            product[count].quantity = 0;
        }

        cout << "\nPLEASE ENTER THE PRICE \n";
        cin >> product[count].price;
        cout << " \n";
    }
    else if (count = SIZE){
        cout << "THE INVENTORY IS FULL \n";
    }
    count++;
}

//*****************************************************************************
// Function: Remove; deletes a product from the inventory.
//
// Parameter 1: The product array
// Parameter 2: The counter variable
//*****************************************************************************
void remove(struct Inventory product[], int &count){
    string value;
    int i;

    cout << "INPUT PRODUCT TO BE REMOVED \n";
    cin.ignore(100,'\n');
    getline(cin, value);
    cout << endl;

    i = binarySearch(product, count, value);

    if (i <= -1){
        cout << "COULD NOT LOCATE THE PRODUCT \n";
    }
    else if (i >= 0){
        product[i] = product[count - 1];

        cout << "PRODUCT HAS BEEN REMOVED \n";

        count--;
    }
}

//*****************************************************************************
// Function: Adjust; changes the quantity on hand for a product.
//
// Parameter 1: The product array
// Parameter 2: the counter variable
//*****************************************************************************
void adjust(struct Inventory product[], int count){
    string value;
    int i, x;

    cout << "INPUT PRODUCT NAME \n";
    cin.ignore(100,'\n');
    getline(cin, value);
    cout << endl;

    i = binarySearch(product, count, value);

    cout << "INPUT CHANGE AMOUNT \n";
    cin >> x;

    product[i].quantity += x;

    if (product[i].quantity <= 0){
        cout << "\nNEGATIVE QUANTITIES ARE NOT PERMITTED \n";

        product[i].quantity -= x;
    }
    else if (product[i].quantity >= 0){
        cout << "\nACKNOWLEDGED \n";
    }
}

//*****************************************************************************
// Function: Info; takes input from user and performs search.
//
// Parameter 1: The product array
// Parameter 2: The counter variable
//*****************************************************************************
void info(struct Inventory product[], int count){
    string value;    // Temporary string variable for user input
    int i;           // Variable that will be the index of the product

    cout << "INPUT SEARCH \n";
    cin.ignore(100,'\n');
    getline(cin, value);
    cout << endl;

    i = binarySearch(product, count, value);

    if (i <= -1){
        cout << "THE PRODUCT COULD NOT BE FOUND AS TYPED \n";
    }
    else if (i >= 0){
        cout << product[i].productName << endl;
        cout << product[i].locator << endl;
        cout << product[i].quantity << endl;
        cout << product[i].price << endl;
    }
}

//*****************************************************************************
// Function: Display; displays the sorted inventory.
//
// Parameter 1: The product array.
// Parameter 2: The counter variable.
//*****************************************************************************
void display(struct Inventory product[], int count){
    cout << "PRODUCT    LOCATOR NUMBER    QUANTITY    PRICE \n\n";

    for (int i = 0; i < count; i++){
        cout << setw(16) << left << product[i].productName << setw(16) << left
        << product[i].locator << setw(10) << left << product[i].quantity
        << product[i].price << " \n";
    }
}

//*****************************************************************************
// Function: Bubble Sort; sorts the inventory alphabetically.
//
// Parameter 1: The product array.
// Parameter 2: The counter variable.
//*****************************************************************************
void bubbleSort(struct Inventory product[], int count){
    bool swap;         // Swap variable indicates whether a swap has occured
    Inventory temp;    // Temporary inventory structure for swap process

    do{
        swap = false;
        for (int i = 0; i < (count - 1); i++){
           if (product[i].productName > product[i + 1].productName){
              temp = product[i];
              product[i] = product[i + 1];
              product[i + 1] = temp;
              swap = true;
           }
        }
    }while (swap);
}

//*****************************************************************************
// Function: Binary Search; searches the product array.
//
// Parameter 1: The product array.
// Parameter 2: The counter variable.
// Parameter 3: What it is we're looking for.
//*****************************************************************************
int binarySearch(struct Inventory product[], int count, string value){
   int first = 0,           // First array element
       last = count - 1,    // Last array element
       middle,              // Mid point of search
       position = -1;       // Position of search value
   bool found = false;      // Flag

   while (!found && first <= last){
      middle = (first + last) / 2;                  // Calculate mid point
      if (product[middle].productName == value){    // If value is found at mid
         found = true;
         position = middle;
      }
      else if (product[middle].productName > value)// If value is in lower half
         last = middle - 1;
      else
         first = middle + 1;                       // If value is in upper half
   }
   return position;
}
