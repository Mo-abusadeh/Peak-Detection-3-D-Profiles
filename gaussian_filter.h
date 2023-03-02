#ifndef GAUSSIAN_FILTER_H_INCLUDED
#define GAUSSIAN_FILTER_H_INCLUDED
#include <vector>

using namespace std;

// Declaring the function responsible for filtering the data.
vector<float> gaussian_filter (int data_size, const vector<float>& signal);

#endif // GAUSSIAN_FILTER_H_INCLUDED
