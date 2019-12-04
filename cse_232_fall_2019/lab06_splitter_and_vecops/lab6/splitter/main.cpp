#include<iostream>
using std::cin; using std::cout; 
using std::ostream; using std::istringstream;
#include<string>
using std::string;
#include<vector>
using std::vector;


#include "functions.hpp"

int main() {
    string s = "";
    char separator = ' ';
    getline(cin, s);
    separator = getchar();
    vector<string> v = split(s, separator);
    print_vector(cout, v);
}