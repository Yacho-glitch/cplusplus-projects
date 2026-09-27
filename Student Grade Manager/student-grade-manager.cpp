#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

int calculateAvg;

struct Student {
    string nameStd;
    string idStd;
    int dsa;
    int sql;
    int cpp;
};

vector<Student> listStd;

void addStudent();
void showStudents();
void editStudent();
void deleteStudent();

int main() {

    int choice;
    do {
        cout << "\n===== STUDENT GRADE MANAGER =====\n";
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
            case 4:
                editStudent();
                break;
            case 5:
                deleteStudent();
                break;
            case 8:
                cout << "Arigato Gozaimasu.";
                break;
        }

    } while (choice != 8);
    return 0;
}

void addStudent() {

    Student student;

    cout << "Enter student name : ";
    std::getline(std::cin >> std::ws, student.nameStd);

    
    while (true) {
        cout << "Enter ID student : ";
        cin >> student.idStd;
        
        bool exists = false;
        
        for (const Student& previousStdId : listStd) {
            if (previousStdId.idStd == student.idStd) {
                exists = true;
                break;
            }
        }

        if (exists) {
            cout << "❌ Student ID already exists. Try another ID.\n";
        } else {
            break;
        }
    }

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
        return;
    } 

    cout << "\n===============================================================================================\n";
    cout << left
         << setw(5)  << "Id"
         << setw(10) << "ID_STD"
         << setw(20) << "Name_STD"
         << setw(36) << "DataStructureAlgorithms"
         << setw(20) << "C++"
         << setw(20) << "SQL"
         << endl;
    cout << "===============================================================================================\n";

    for (int i = 0; i < listStd.size(); i++) {
        cout << left
             << setw(5)  << i + 1
             << setw(10) << listStd[i].idStd
             << setw(20) << listStd[i].nameStd
             << setw(36) << listStd[i].dsa
             << setw(20) << listStd[i].cpp
             << setw(20) << listStd[i].sql
             << endl;
    }
    cout << "===============================================================================================\n";
    
};

void deleteStudent() {
    showStudents();
    int id;
    std::cout << "\nEnter Student Id : ";
    cin >> id;

    if (id < 1 || id > listStd.size()) {
        cout << "Invalid Id ❌\n\n";
        return;
    }

    listStd.erase(listStd.begin() + id - 1);

    cout << "Student Informations Deleted Successfully.\n";
}

void editStudent() {
    int id;
    cout << "\nEnter student Id : ";
    cin >> id;

    if (id < 1 || id > listStd.size()) {
        cout << "Invalid ID ❌\n\n";
        return;
    }

    cout << "\nEnter ";

}