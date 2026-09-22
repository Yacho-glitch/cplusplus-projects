#include <iostream>
#include <string>
using namespace std;

int main() {

    // The first program
    string name;
    int age;
    string nationality;


    std::cout << "Enter your name : ";
    std::cin >> name;

    std::cout << "Enter your age : ";
    std::cin >> age;

    std::cout << "Enter your nationality : ";
    std::cin >> nationality;

    // cout << name.append(" say hello to the world!\n");

    cout << "You're : " << name << ". You're are " << age << " years old. You're " << nationality << ".";

    return 0;

}