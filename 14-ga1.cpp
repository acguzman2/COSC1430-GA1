#include <bits/stdc++.h>

using namespace std;


const int NumberOfExams = 5;
const int NumberOfStudents = 10;
const string FileName = "grades.txt";
double Weights[NumberOfExams];
double Sum = 0;

// Global arrays
int grades[NumberOfStudents][NumberOfExams];
double examAvgs[NumberOfExams];
double studentAvgs[NumberOfStudents];

void readGrades(string fileName, int numberOfExams, int numberOfStudents) {
    ifstream input;
    input.open(fileName);

    // Check for valid file opening
    if (!input) {
        cerr << "No file";
        return;
    }

    // Outer loop for each student
    for (int i = 0; i < numberOfStudents; ++i) {
        // Loop for each exam
        for (int j = 0; j < numberOfExams; ++j) {
            // Read each number into each spot in the array
            input >> grades[i][j];
        }
    }

}

void getWeights(double weights[], int numOfExams) {
    for (int i = 0; i < numOfExams; ++i) {
        cout << "Please enter the weight of exam " << i + 1 << ": ";
        cin >> weights[i];
        Sum += weights[i];
    }
}


// Average of all students on each exam
void getAvgsOfExams(double examAvgs[], int numOfExams, int numOfStudents) {
    for (int i = 0; i < numOfExams; ++i) {
        int sum = 0;
        for (int j = 0; j < numOfStudents; ++j) {
            sum += grades[j][i];
        }
        examAvgs[i] = (sum / (numOfStudents + 0.0));
    }
}

void getAvgsOfStudents(double studentAvgs[], double weights[], int numOfExams, int numOfStudents) {
    for (int i = 0; i < numOfStudents; ++i) {
        int sum = 0;
        for (int j = 0; j < numOfExams; ++j) {
            sum += grades[i][j] * weights[j];
        }
        studentAvgs[i] = sum;
    }
}

void writeFinalGrades(double examAvgs[], double studentGrades[], int numOfExams, int numOfStudents) {
    ofstream output;
    output.open("output.txt");

    if (!output) {
        cerr << "No file";
        return;
    }
    // Outer loop for each student
    for (int i = 0; i < numOfStudents; ++i) {
        // Loop for each exam
        for (int j = 0; j < numOfExams; ++j) {
            // Read each number into each spot in the array
            output << grades[i][j] << " ";
        }
        output << studentGrades[i] << endl;
    }

    for(int i = 0; i < numOfExams; ++i) {
        output << examAvgs[i] << " ";
    }
    output.close();
}


int main() {
    readGrades(FileName, NumberOfExams, NumberOfStudents);
    getWeights(Weights, NumberOfExams);
    if (Sum != 1) {
        cerr << "Invalid weight distribution" << endl;
        return 1;
    }
    getAvgsOfExams(examAvgs, NumberOfExams, NumberOfStudents);
    getAvgsOfStudents(studentAvgs, Weights, NumberOfExams, NumberOfStudents);
    writeFinalGrades(examAvgs, studentAvgs, NumberOfExams, NumberOfStudents);

    return (0);
}