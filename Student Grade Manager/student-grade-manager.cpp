#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;


struct Student {
    string nameStd;
    string idStd;
    int dsa;
    int sql;
    int cpp;
};

vector<Student> listStd;

int getValidGrade();
void addStudent();
void showStudents();
void editStudent();
void deleteStudent();
void showTopStudent();
double calculateAvg(const Student& student);

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
            case 6:
                int num;
                cout << "\nEnter student id that you want to calculate his average note : ";
                cin >> num;

                if (num < 1 || num > listStd.size()) {
                    cout << "Invalid ID ❌\n";
                    break;
                }

                cout << "Average : " << calculateAvg(listStd[num - 1]) << endl;
                break;
            case 7:
                showTopStudent();
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
    };

    /*

        repetition

    do {
        cout << "Enter DSA Grade : ";
        cin >> student.dsa;

        if (student.dsa < 0 || student.dsa > 20) {
            cout << "❌ Grade must be between 0 and 20.\n";
        }

    } while (student.dsa < 0 || student.dsa > 20);

    do {
        cout << "Enter C++ Grade : ";
        cin >> student.cpp;

        if (student.cpp < 0 || student.cpp > 20) {
            cout << "❌ Grade must be between 0 and 20.\n";
        }
        
    } while (student.cpp < 0 || student.cpp > 20);
    
    do {
        cout << "Enter SQL Grade : ";
        cin >> student.sql;

        if (student.sql < 0 || student.sql > 20) {
            cout << "❌ Grade must be between 0 and 20.\n";
        }

    } while (student.sql < 0 || student.sql > 20);

    */

    cout << "Enter DSA Grade : ";
    student.dsa = getValidGrade();

    cout << "Enter C++ Grade : ";
    student.cpp = getValidGrade();

    cout << "Enter SQL Grade : ";
    student.sql = getValidGrade();

    listStd.push_back(student);

    std::cout << "Student Informations Added Successfully \n\n";
};

int getValidGrade() {
    int grade;

    do {
        cin >> grade;

        if (grade < 0 || grade > 20) {
            cout << "❌ Grade must be between 0 and 20.\n";
            cout << "TRY AGAIN : ";
        }

    } while (grade < 0 || grade > 20);

    return grade;
}

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

    cout << "\n===== EDIT STUDENT =====\n";
    cout << "1. Edit Name\n";
    cout << "2. Edit DSA Grade\n";
    cout << "3. Edit C++ Grade\n";
    cout << "4. Edit SQL Grade\n";
    cout << "5. Cancel\n";

    int choice;
    cout << "\nChoose an option : ";
    cin >> choice;

    switch(choice) {
        case 1:
            cout << "Enter the new name : ";
            std::getline(std::cin >> std::ws, listStd[id - 1].nameStd);
            break;
        case 2:
            cout << "Enter the new DSA grade : ";
            listStd[id - 1].dsa = getValidGrade();
            break;
        case 3:
            cout << "Enter the new C++ grade : ";
            listStd[id - 1].cpp = getValidGrade();
            break;
        case 4:
            cout << "Enter the new SQL grade : ";
            listStd[id - 1].sql = getValidGrade();
            break;
        case 5:
            cout << "Arigato\n";
            break;
    }

}

double calculateAvg(const Student& student) {
    return (student.dsa + student.cpp + student.sql) / 3.0;
}

void showTopStudent() {
    if (listStd.empty()) {
        cout << "No student available.\n";
        return;
    }

    int topIndex = 0;

    for (int i = 1; i < listStd.size(); i++) {
        if (calculateAvg(listStd[i]) > calculateAvg(listStd[topIndex])) {
            topIndex = i;
        }
    }

    cout << "\n===== TOP STUDENT =====\n";
    cout << "Name : " << listStd[topIndex].nameStd << endl;
    cout << "ID : " << listStd[topIndex].idStd << endl;
    cout << "Average : " << calculateAvg(listStd[topIndex]) << endl;
}