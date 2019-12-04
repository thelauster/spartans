#include<vector>
#include<string>
using std::vector;
using std::string;

#include "extra.hpp"


string my_fun(const vector<string>& v){
    string result="";
    for(auto element : v)
        result += element[0];
    return result;
}
