#include<iostream>
using std::cout; using std::endl;
#include<string>
using std::string;
#include<iterator>
using std::ostream_iterator;
#include<sstream>
#include<set>
using std::set;
#include<map>
using std::map;
#include<utility>
using std::pair;

#include "print.hpp"

template<typename T>
string set_to_string(const set<T>& s){
  std::ostringstream oss;
  for (auto element : s)
    oss << element << ", ";
  string result = oss.str();
  result = result.substr(0, result.size() - 2 );
  return result;
}

template<typename K, typename V>
string pair_to_string(pair<K,V> p){
  std::ostringstream oss;
  oss << p.first <<":"<< set_to_string(p.second) << endl;
  return oss.str();
}

template<typename K, typename V>
void print_map(const map<K,V>& m){
  transform(m.cbegin(), m.cend(),
	    ostream_iterator<string>(cout, ", "),
	    pair_to_string<K,V>
	    );
}

void f1(int i) {
  cout << i;
}