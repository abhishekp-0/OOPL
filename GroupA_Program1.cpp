#include<iostream>
using namespace std;

class Complex {
    
    public: 
        //Constructors
        Complex() : real(0.0), img(0.0) {}  //Default Constructor
        Complex(double r, double i) : real(r), imaginary(i) {} //User-defined Constructor

        // Overload + operator for addition
        Complex operator+(const Complex& other) const {
            return Complex(real + other.real, imaginary + other.imaginary);
        }

        // Overload * operator for multiplication
        Complex operator*(const Complex& other) const {
            double r = real * other.real - imaginary * other.imaginary;
            double i = real * other.imaginary + imaginary * other.real;
            return Complex(r, i);
        }
        // Input and output operators
        friend ostream& operator<<(ostream& os, const Complex& complex) {
            os << complex.real << "+" << complex.imag << "i";
            return os;
        }

        friend istream& operator>>(istream& is, Complex& complex) {
            cout << "Enter Real Part: ";
            is >> complex.real;
            cout << "Enter Imaginary Part: ";
            is >> complex.imag;
            return is;
        }

    private:
        double real;
        double img;
};





int main() {
    Complex c1(2.3, 4.5);
    Complex c2(3.4, 5.6);
    Complex c3;

    // Addition
    c3 = c1 + c2;
    cout << "Sum: " << c3 << endl;

    // Multiplication
    c3 = c1 * c2;
    cout << "Product: " << c3 << endl;

    // Input example
    Complex c4;
    cin >> c4;
    cout << "You entered: " << c4 << endl;

    return 0;
}
