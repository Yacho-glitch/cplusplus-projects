#include <iostream>
#include <string>
#include <vector>
using namespace std; 

struct Task {
    string taskName;
};

vector<Task> listTask;

int main() {
    string task;
    int choice;

    do {
        cout << "1. Show list of Tasks\n";
        cout << "2. Add Task\n";
        cout << "3. Remove Task\n";
        cout << "4. Edit Task\n";
        cout << "5. Exit\n";

        cout << "\nYour choice : ";
        cin >> choice;

    } while (choice != 5);

    cout << "Enter your task : ";
    std::getline(std::cin >> std::ws, task);

    std::cout << "Your task is " << task;
    return 0;
}