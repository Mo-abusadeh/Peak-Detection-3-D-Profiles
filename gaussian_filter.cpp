#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include "gaussian_filter.h"

using namespace std;

// Function for filtering the 1D profile data
// Inputs: the size of data (# of elements), the vector containing all the unfiltered profile data.
// Output: vector "filtered" containing all the filtered values
vector<float> gaussian_filter (int data_size, const vector<float>& signal){

    const int w = 5;
    // Creating a vector "filtered" with the same size as the input data
    vector <float> filtered(data_size);
    for (int i=0; i<data_size; i++){
        float N = 0.f;
        float S_nf = 0.f;

        for (int k=-(w-1)/2; k<=(w-1)/2; k++){

                if (((i+k)<data_size) && ((i+k)>=0)){
                  // Gaussian filtering using kernel g.
                  // N is the sum of the kernels at each point
                  // S_nf is the convolution of the signal value and the kernel over the sum of kernel points N.
                  float g = exp(-(pow(k,2)/2.f));
                  N += g;
                  S_nf += signal[i+k]*g;
                }
        }

        if (i<=((w-1)/2) || i>=(data_size-((w-1)/2)))
            // The first and the last (w-1)/2 samples are kept to their original values.
            filtered[i] = signal[i];
        else
            // All other values are assigned the value of the convolution respectively over N.
            filtered[i] = S_nf/N;

    }

    return filtered;
}
