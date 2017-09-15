#include <bits/stdc++.h>

using namespace std;


const int NumberOfExams = 5;
const int NumberOfStudents = 10;
const string FileName = "grades.txt";

// Global array with 10 rows and 5 columns
int grades[NumberOfStudents][NumberOfExams];


void readGrades(string fileName, int numberOfExams, int numberOfStudents) {
    ifstream input;
    input.open(fileName);

    // Check for valid file opening
    if(!input) {
        cerr << "No file";
        return;
    }

    // Outer loop for each student
    for(int i = 0; i < numberOfStudents; ++i) {
        // Loop for each exam
        for(int j = 0; j < numberOfExams; ++j) {
            // Read each number into each spot in the array
            input >> grades[i][j];
        }
    }

}

void getWeights(double weights[], int numOfExams) {

}

void getAvgsOfExams(double examAvgs[], int numOfExams, int numOfStudents) {

}

void getAvgsOfStudents(double studentAvgs[], double weights[], int numOfExams, int numOfStudents) {

}

void writeFinalGrades(double examAvgs[], double studentGrades[], int numOfExams, int numOfStudents) {

}


int main() {
    readGrades(FileName, NumberOfExams, NumberOfStudents);
    return (0);
}