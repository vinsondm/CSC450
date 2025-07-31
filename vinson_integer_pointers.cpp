//============================================================================
// Name        : vinson_integer_pointers.cpp
// Author      : David Vinson
// Description : Intake for three user integer values, storage of each into a
//				variable, integer pointers to each variable, and output for
//				each as both a variable and pointer
// Date Created: 07-30-2025
//============================================================================/*

#include <iostream>
using namespace std;

int main() {
    // Declare variables for the three integers
    int value1, value2, value3;

    // Ask user for input
    cout << "Enter the first integer: ";
    cin >> value1;
    cout << "Enter the second integer: ";
    cin >> value2;
    cout << "Enter the third integer: ";
    cin >> value3;

    // Dynamically allocate memory for the three integers
    int* pointer1 = new int(value1);
    int* pointer2 = new int(value2);
    int* pointer3 = new int(value3);

    // Display the values stored in the variables
    cout << "\nValues stored in variables:\n";
    cout << "value1 = " << value1 << endl;
    cout << "value2 = " << value2 << endl;
    cout << "value3 = " << value3 << endl;

    // Display the values using the pointers
    cout << "\nValues accessed through pointers:\n";
    cout << "*pointer1 = " << *pointer1 << endl;
    cout << "*pointer2 = " << *pointer2 << endl;
    cout << "*pointer3 = " << *pointer3 << endl;

    // Deallocate the dynamically allocated memory
    delete pointer1;
    delete pointer2;
    delete pointer3;

    return 0;
}
