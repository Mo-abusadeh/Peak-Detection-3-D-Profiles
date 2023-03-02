#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include "gradient_checking.h"
#include "file.h"
#include "gaussian_filter.h"
#include "generate_gradients.h"

using namespace std;

// Declaring the function that calls all the other functions.
float load_func (string name);

int main()
{

cout << "Peak detected at the following coordinates:" << endl;

// Loading all functions consecutively for each dimension profile.
float X_location = load_func("X.txt");
float Y_location = load_func("Y.txt");
float Z_location = load_func("Z.txt");

}


// Function to call all other functions, avoiding duplication when calling functions for 3 1D profiles.
// Input: string value of the name of the 1D profile file.
// Output: float number that returns the location of the peaks in each profile.
float load_func (string name){

    vector<float> signal = file(name);

    int data_size = signal.size();

    vector<float> filtered = gaussian_filter(data_size,signal);

    vector<float> gradients = generate_gradients(data_size,filtered);

    float location = gradient_checking(data_size, filtered, gradients);

    // Display location of peak
    cout << location << endl;

    // Returns error message if peak not found
    if (location < 0)
        cerr << "Peak not found in file:" << name << endl;

}

