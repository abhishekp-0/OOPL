#include<iostream>
using namespace std;

class Complex {
    
    public: 
        //Constructors
        Complex() : real(0.0), img(0.0) {}  //Default Constructor
        Complex(double r, double i) : real(r), img(i) {} //User-defined Constructor

        // Overload + operator for addition
        Complex operator+(const Complex& other) const {
            return Complex(real + other.real, img + other.img);
        }

        // Overload * operator for multiplication
        Complex operator*(const Complex& other) const {
            double r = real * other.real - img * other.img;
            double i = real * other.img + img * other.real;
            return Complex(r, i);
        }
        // Input and output operators
        friend ostream& operator<<(ostream& output, const Complex& complex) {
            output << complex.real << "+" << complex.img << "i";
            return output;
        }

        friend istream& operator>>(istream& input, Complex& complex) {
            cout << "Enter Real Part: ";
            input >> complex.real;
            cout << "Enter Imaginary Part: ";
            input >> complex.img;
            return input;
        }

    private:
        // Data Members
        double real;  //Real part
        double img;   //Imaginary part
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

    return 0;
}
