//============================================================================
// Name        : vinson_integer_pointers.cpp
// Author      : David Vinson
// Description : Program takes user input, then checks existence of the
//				 file and wheter or not it is writeable, then appends the
//				 input to the file. Then the reversal method is called, which
//				 reverses the file and saves it in a new text file.
// Date Created: 08-17-2025
//============================================================================

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>  // for reverse()

using namespace std;

// Function to reverse the contents of a file and store in another
void reverseFileContent(const string& inputFile, const string& outputFile) {
    ifstream inFile(inputFile);
    if (!inFile) {
        cerr << "Error: Could not open " << inputFile << " for reading." << endl;
        return;
    }

    string content((istreambuf_iterator<char>(inFile)), istreambuf_iterator<char>());
    inFile.close();

    reverse(content.begin(), content.end());

    ofstream outFile(outputFile);
    if (!outFile) {
        cerr << "Error: Could not open " << outputFile << " for writing." << endl;
        return;
    }

    outFile << content;
    outFile.close();

    cout << "Reversed content has been written to " << outputFile << endl;
}

int main() {
    string filename = "CSC450_CT5_mod5.txt";
    string reverseFile = "CSC450-mod5-reverse.txt";

    // Get user input
    cout << "Enter text to append to file: ";
    string userInput;
    getline(cin, userInput);

    // Append input to the file
    ofstream outFile(filename, ios::app); // ios::app = append mode
    if (!outFile) {
        cerr << "Error: Could not open " << filename << " for appending." << endl;
        return 1;
    }

    outFile << userInput << endl;
    outFile.close();
    cout << "Data appended to " << filename << endl;

    // Reverse file contents and store in reverse.txt
    reverseFileContent(filename, reverseFile);

    return 0;
}



