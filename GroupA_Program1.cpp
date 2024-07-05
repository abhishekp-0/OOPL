#include<iostream>
using namespace std;

class Complex {
    double real;
    double img;
public: 
    Complex(); // Default Constructor
    friend istream & operator >> (istream &, Complex &); // Input 
    friend ostream & operator << (ostream &, const Complex &); // Output
    Complex operator + (Complex); // Addition
    Complex operator - (Complex); // Subtraction
    Complex operator * (Complex); // Multiplication
    Complex operator / (Complex); // Division
};

Complex::Complex() {
    real = 0;
    img = 0;
}

istream & operator >> (istream & in, Complex & c) {
    cout << "Enter Real and Imaginary part of the Complex Number: ";
    in >> c.real >> c.img;
    return in;
}

ostream & operator << (ostream & out, const Complex & c) {
    out << c.real << " + " << c.img << "i";
    return out;
}

Complex Complex::operator + (Complex c) {
    Complex temp;
    temp.real = real + c.real;
    temp.img = img + c.img;
    return temp;
}

Complex Complex::operator * (Complex c) {
    Complex temp;
    temp.real = real * c.real - img * c.img;
    temp.img = real * c.img + img * c.real;
    return temp;
}

int main() {
    Complex C1, C2, result;
    char choice;
    
    do {
        cout << "Enter Complex Number 1:\n";
        cin >> C1;
        cout << "Enter Complex Number 2:\n";
        cin >> C2;

        cout << "Complex Number 1: " << C1 << endl;
        cout << "Complex Number 2: " << C2 << endl;

        cout << "********** MENU **********\n";
        cout << "1. Addition\n";
        cout << "2. Multiplication\n";
        cout << "3. Exit\n";
        cout << "Enter your choice (1-5): ";
        int option;
        cin >> option;

        switch(option) {
            case 1:
                result = C1 + C2;
                cout << "Addition Result: " << result << endl;
                break;
            case 2:
                result = C1 * C2;
                cout << "Multiplication Result: " << result << endl;
                break;
            case 3:
                cout << "Exiting program. Goodbye!\n";
                return 0;
            default:
                cout << "Invalid choice. Please enter a number from 1 to 3.\n";
        }

        cout << "Do you want to perform another operation? (y/n): ";
        cin >> choice;
    } while(choice == 'y' || choice == 'Y');

    cout << "Thanks for using this program!\n";
    return 0;
}
