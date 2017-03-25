// File Name: assign1_c_s323
//
// Author: Christian Sylvester
// Date: 01/31/2015
// Assignment Number: 1
// CS 2308.251 Spring 2015
// Instructor: Jill Seaman
//
// Averages and assigns a letter grade for various assignments belonging to
// multiple students.

# include <iostream>
# include <fstream>
using namespace std;

int main (){
    ifstream fin;
    fin.open("class_scores.txt");

//  Arrays for the student IDs, lab and quiz marks.
    char student_1[9];
    int lab_1[7];
    int quiz_1[7];

    for (int i = 0; i < 9; i++){
        fin >> student_1[i];
    }
    for (int i = 0; i < 7; i++){
        fin >> lab_1[i];
    }
    for (int i = 0; i < 7; i++){
        fin >> quiz_1[i];
    }
    fin.close();

    ofstream fout;
    fout.open("final_grades.txt");

    for (int i = 0; i < 9; i++){
        fout << student_1[i];
    }
    cout << endl;

    for (int i = 0; i < 7; i++){
        fout << lab_1[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < 7; i++){
        fout << quiz_1[i] << " ";
    }
    cout << endl;

    fout.close();

    cout << endl;

    return 0;
}
