#include <iostream>
#include <cmath>
#include <vector>
#include "gradient_checking.h"

using namespace std;


// Function that checks for peaks in the gradient vector.
// Inputs: the size of data (# of elements), vector with filtered data, vector with gradient values.
// Output: a float number of the location of the peak within the data profile.
float gradient_checking (int data_size, const vector<float>& filtered, const vector<float>& gradients){

    int location = -1;
    float local_peak = 0.f;

    bool positives;
    bool negatives;
    for (int p = 0; p < data_size; p++) {

        // Checking if there are 3 positive gradients before the point.
        if (gradients[p-1] > 0 && gradients[p-2] > 0 && gradients[p-3] > 0)
            positives = true;

        // Checking if there are 3 negative gradients after the point.
        if (gradients[p+1] < 0 && gradients[p+2] < 0 && gradients[p+3] < 0)
            negatives = true;

        // Checking if the current peak is the highest peak value compared to other peaks.
        while (positives && negatives && filtered[p] > local_peak) {
            location = p;
            local_peak = filtered[p];
        }

    }

    return location;


}
