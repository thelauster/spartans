#include<vector>
using std::vector;
#include<string>
using std::string;
#include <iostream>
using std::cout; using std::endl;
#include <sstream>
using std::ostream; using std::istringstream;

vector<string> split (const string & str, char separator) {
    istringstream iss(str);
    vector<string> out_v;
    string word = "";
    while (getline(iss, word, separator)) {
        cout << word << endl;
        out_v.push_back(word);
    }
    /*for(auto itr = s.begin(); itr != s.end(); ++itr) {
        word.append(1, *itr);
        if (*itr == separator) {
            out_v.push_back(word);
            word = "";
        }
        
        cout << *itr << " "<< word << endl;
    }
    if (word != " ") {
        out_v.push_back(word);
    }*/
    //cout << out_v[1] << out_v[0];
    return out_v;
}

void print_vector (ostream &out, const vector<string> &v) {
    for(auto itr = v.begin(); itr != v.end(); ++itr) {
        out << *itr << '\n';
    }
}