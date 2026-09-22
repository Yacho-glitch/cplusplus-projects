#include <iostream>
#include <string>
#include <vector> // A dynamic array "vector"
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

    cout << "Product Added Successfully";
};














    // string choice = "1. Show Products\n2. Add Product\n3. View Cart\n4. Remove Product\n5. Checkout\n6. Exit\n\nChoice: ";
    // Product item1 = { "Apple", 1.50 };
    // Product item2 = { "Bread", 3.00 };

    // products.push_back(item1);
    // products.push_back(item2);

    // cout << "You have " << cart.size() << " items in your cart." << endl;
    // cout << "The first one is " << cart.at(0);

    // cout << "====== SHOPPING CART ======\n";
    // cout << choice << "\n";
    // cout << products;