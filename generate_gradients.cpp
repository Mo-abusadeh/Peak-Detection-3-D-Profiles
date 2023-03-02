#include <iostream>
#include <cmath>
#include <vector>
#include <fstream>
#include "generate_gradients.h"


using namespace std;

// Function to find the gradient between each two points.
// Inputs: the size of data (# of elements), and the vector containing the filtered data.
// Output: vector containing gradient values of all points.
vector<float> generate_gradients(int data_size, const vector<float>& filtered){

    // Vector with the same size as the original 1D profile containing all gradient values
    vector<float> gradients(data_size);
    // The first element of the gradient vector is set to 0,
    // as there is not a point prior to it to find relative gradient
    gradients [0] = 0.f;
    for (int g = 1; g < data_size; g++)
        // Equation for computing the gradient values
        gradients[g] = filtered[g] - filtered[g-1];


    return gradients;
}
