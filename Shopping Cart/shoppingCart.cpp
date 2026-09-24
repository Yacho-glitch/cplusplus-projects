#include <iostream>
#include <string>
#include <vector> // A dynamic array "vector"
#include <iomanip> // input/output formating (table...)
using namespace std;

struct Product {
    string name;
    double price;
    int quantity;
};

vector<Product> cart; // Create array with [{name:"",price:num,quantity:chiffre},{}...]

void addProduct();
void viewCart();
void removeProduct();
void checkout();

int main() {

    int choice;
 
    do {
        cout << "====== SHOPPING CART ======\n";
        cout << "1. Show Products\n";
        cout << "2. Add Products\n";
        cout << "3. View Cart\n";
        cout << "4. Remove Product\n";
        cout << "5. Checkout\n";
        cout << "6. Exit\n";

        cout << "\nChoice : ";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "List of the product";
                break;
            case 2:
                addProduct();
                break;
            case 3:
                viewCart();
                break;
            case 4:
                cout << "Remove product";
                break;
            case 5:
                cout << "Checkout";
                break;
            case 6:
                cout << "Goodbye";
                break;
        }

    } while (choice != 6);

    return 0;
}

// showMenu(), viewCart(), removeProduct(), checkout()

void addProduct() {

    Product product;

    cout << "Enter Product Name : ";
    cin >> product.name;

    cout << "Enter Product Price : ";
    cin >> product.price;

    cout << "Enter Quantity : ";
    cin >> product.quantity;

    cart.push_back(product);

    cout << "Product Added Successfully\n\n";
};

void viewCart() {

    if (cart.empty()) {
        cout << "Cart is empty.\n";
        return;
    }

    cout << "\n=========================================================\n";
    cout << left
         << setw(5)  << "ID"
         << setw(20) << "Product"
         << setw(15) << "Price"
         << setw(10) << "Quantity"
         << endl;
    cout << "=========================================================\n";

    for (int i = 0; i < cart.size(); i++) {
        cout << left
             << setw(5)  << i + 1 
             << setw(20) << cart[i].name
             << setw(15) << cart[i].price
             << setw(10) << cart[i].quantity
             << endl;
    }

    cout << "=========================================================\n\n";
};