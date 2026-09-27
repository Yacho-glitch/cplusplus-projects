#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

int calculateAvg;

struct Student {
    string nameStd;
    int idStd;
    int dsa;
    int sql;
    int cpp;
};

vector<Student> listStd;

void addStudent();
void showStudents();

int main() {

    int choice;
    do {
        cout << "===== STUDENT GRADE MANAGER =====\n";
        cout << "1. Add Student\n";
        cout << "2. Show Students\n";
        cout << "3. Search Student\n";
        cout << "4. Edit Student\n";
        cout << "5. Delete Student\n";
        cout << "6. Calculate Average\n";
        cout << "7. Show Top Student\n";
        cout << "8. Exit\n\n";

        cout << "Choice a number : ";
        cin  >> choice;

        switch(choice) {
            case 1:
                addStudent();
                break;
            case 2:
                showStudents();
                break;
        }

    } while (choice != 8);
    return 0;
}

void addStudent() {

    Student student;

    cout << "Enter student name : ";
    std::getline(std::cin >> std::ws, student.nameStd);

    cout << "Enter ID student : ";
    cin >> student.idStd;

    cout << "Enter DSA Grade : ";
    cin >> student.dsa;

    cout << "Enter C++ Grade : ";
    cin >> student.cpp;

    cout << "Enter SQL Grade : ";
    cin >> student.sql;

    listStd.push_back(student);

    std::cout << "Student Informations Added Successfully \n\n";
};

void showStudents() {
    if (listStd.empty()) {
        cout << "There is no student included yet.\n";
    } 

    cout << "\n===============================================================\n";
    cout << left
         << setw(5)  << "ID"
         << setw(10) << "Name_STD"
         << setw(10) << "DataStructureAlgorithms"
         << setw(10) << "C++"
         << setw(10) << "SQL"
         << endl;
    cout << "=================================================================\n";

    for (int i = 0; i < listStd.size(); i++) {
        cout << left
             << setw(5)  << listStd[i].idStd
             << setw(20) << listStd[i].nameStd
             << setw(20) << listStd[i].dsa
             << setw(20) << listStd[i].cpp
             << setw(20) << listStd[i].sql
             << endl;
    }
    cout << "=================================================================\n";
    
};