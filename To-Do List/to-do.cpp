#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std; 

string Task;

vector<string> taskList;

void showListTask();
void addTask();
void editTask();
void removeTask();

int main() {
    int choice;

    do {
        cout << "===== TO-DO List =====\n";
        cout << "1. Show list of Tasks\n";
        cout << "2. Add Task\n";
        cout << "3. Remove Task\n";
        cout << "4. Edit Task\n";
        cout << "5. Exit\n";

        cout << "\nChoice : ";
        cin  >> choice;

        switch(choice) {
            case 1:
                showListTask();
                break;
            case 2:
                addTask();
                break;
            case 3:
                removeTask();
                break;
            case 4:
                editTask();
                break;
            case 5:
                cout << "Goodbye";
                break;
        }

    } while (choice != 5);

    return 0;
}

void showListTask() {

    if (taskList.empty()) {
        cout << "List is empty 👽.\n\n";
        return;
    }

    cout << "\n=========================================================\n";
    cout << left
         << setw(5)  << "ID"
         << setw(20) << "Task"
         << endl;
    cout << "=========================================================\n";

    for (int i = 0; i < taskList.size(); i++) {
        cout << left
             << setw(5)  << i + 1
             << setw(20) << taskList[i]
             << endl;
    }

    cout << "=========================================================\n\n";
}

void addTask() {

    string task;

    cout << "Enter your task : ";
    std::getline(std::cin >> std::ws, task);

    taskList.push_back(task);

    std::cout << "Task Added Successfully 👌\n\n";

}

void removeTask() {

    showListTask();

    int id;
    cout << "\nEnter Task ID : ";
    cin >> id;

    if (id < 1 || id > taskList.size()) {
        cout << "Invalid ID ❌\n\n";
        return;
    }

    taskList.erase(taskList.begin() + id - 1);

    cout << "Task Removed Successfully 👍\n";
}

void editTask() {
    string newTask;
    int id;

    cout << "Enter task's ID : ";
    cin >> id;

    if (id < 1 || id > taskList.size()) {
        cout << "Invalid ID ❌\n\n";
        return;
    }

    cout << "\nEnter the new task : ";
    std::getline(std::cin >> std::ws, newTask);

    taskList[id - 1] = newTask;

    cout << "Task Edited Successfully\n";

}