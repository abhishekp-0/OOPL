#include<iostream>
using namespace std;

class Complex {
    
    public: 
        //Constructors
        Complex() : real(0.0), imag(0.0) {}  //Default Constructor
        Complex(double r, double i) : real(r), imag(i) {} //User-defined Constructor
        Complex(const Complex& other) : real(other.real), imag(other.imag) {}  //Copy Constructor
        Complex(double r) : real(r), imag(0.0) {}  //Conversion Constructor


        // Overload + operator for addition
        Complex operator+(const Complex& other) const {
            return Complex(real + other.real, imag + other.imag);
        }

        // Overload * operator for multiplication
        Complex operator*(const Complex& other) const {
            double r = real * other.real - imag * other.imag;
            double i = real * other.imag + imag * other.real;
            return Complex(r, i);
        }
        // Input and output operators
        friend ostream& operator<<(ostream& output, const Complex& complex) {
            output << complex.real << "+" << complex.imag << "i";
            return output;
        }

        friend istream& operator>>(istream& input, Complex& complex) {
            cout << "Enter Real Part: ";
            input >> complex.real;
            cout << "Enter Imaginary Part: ";
            input >> complex.imag;
            return input;
        }

    private:
        // Data Members
        double real;  //Real part
        double imag;   //Imaginary part
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

    // Output exmaple
    cout << "You entered: " << c4 << endl;

    // Copy Constructor Usage
    Complex c5(c1);     
    cout << c5 << endl;
    
    // Conversion Constructor Usage
    Complex c6(3.7);
    cout << c6 << endl;
    return 0;
}
