#include <iostream>
#include <cmath>
#include <vector>
#include <fstream>
#include "file.h"


using namespace std;



// Function for loading the 1D profiles
// Input: string (the file name)
// Output: vector containing all the profile data
vector<float> file (string name) {


    // Opening the file and storing it in inFile
    ifstream inFile;
    inFile.open(name);
    // Display error if file could not be opened
    if (!inFile) {
            cerr << "Error: Could not open file \"" << name << ".txt" << endl;
        }

    // Storing the profile data in vector "signal"
    vector<float> signal;
    float value;
    while (inFile >> value)
        signal.push_back(value);


    // closing the file
    inFile.close();

    return signal;

}
