#include<vector>
using std::vector;
#include<iostream>

#include "functions.hpp"

int main() {
    vector<long> a= {1,2,3,4};
    vector<long> b = {1,2};
    vector<long> c =vector_ops(a, b, '+');
    std::cout << c[0];
}