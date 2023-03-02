#ifndef GRADIENT_CHECKING_H_INCLUDED
#define GRADIENT_CHECKING_H_INCLUDED
#include <vector>

using namespace std;

// Declaring the function responsible for detecting the peaks in the gradient vector
float gradient_checking (int data_size, const vector<float>& filtered, const vector<float>& gradients);


#endif // gradient_checking_H_INCLUDED
