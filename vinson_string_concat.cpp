//============================================================================
// Name        : vinson_string_concat.cpp
// Author      : David Vinson
// Description : Intake for two user input strings, and output for the both as a single concatenated string
// Date Created: 07-26-2025
//============================================================================/*


#include <iostream>
#include <string>
using namespace std;

int main() {
    string str1, str2, result;

    cout << "This program will take in two string inputs entered by the user, repeated 3 times.\n\n";

    for (int i = 1; i <= 3; ++i) {
        cout << "Entry " << i << ":\n";

        cout << "Enter first string: ";
        getline(cin, str1);

        cout << "Enter second string: ";
        getline(cin, str2);

        result = str1 + str2;

        cout << "Concatenated result: " << result << "\n\n";
    }

    cout << "All done!\n";
    return 0;
}



