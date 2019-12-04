#include<iostream>
using std::cout; using std::endl;
#include<iomanip>
using std::setw;
#include<vector>
using std::vector; using std::back_inserter;
#include<string>
using std::string;
#include<sstream>
using std::ostringstream;
#include<algorithm>
using std::transform;
#include<functional>
using std::plus;

template<typename T>
using matrix_row = vector<T>;

template<typename T>
using matrix = vector<matrix_row<T>>;

/* 
nicely print a matrix. Should have row/column alignment
converts it to a string (doesn't print to cout!!!)
uses width to space elements (setw). Default is 3
*/
template<typename T>
string matrix_to_str(const matrix<T> &m1, size_t width=3){
  ostringstream oss;
  for (auto row:m1) {
    for (auto entry:row) {
      oss << setw(width) << entry;
    }
    oss << endl;
  }
  return oss.str();
}

/*
true if the two matrices have the same shape
false otherwise
*/
template<typename T>
bool same_size(const matrix<T>& m1, const matrix<T>& m2){
  /*auto r1 = m1.size();
  auto r2 = m2.size();
  auto c1 = m1[0].size();
  auto c2 = m2[0].size();
  if (r1 == r2 && c1 == c2) {
    return true;
  } else {
    return false;
  }*/
  
  if (m1.size() == m2.size()) {
    for (size_t i = 0; i < m1.size(); ++i) {
      if (!(m1[i].size() == m2[i].size())) {
        return false;
      }
    }
    return true;
  } else {
    return false;
  }
}

/*
matrices must not be empty and must be the same shape:
- if true, return a new matrix that adds m1+m2
- if false, return an empty matrix (no elements)
*/
template<typename T>
matrix<T> add(const matrix<T>& m1, const matrix<T>& m2){
  matrix<T> m3;
  if (same_size(m1, m2) && !m1.empty() && !m2.empty()) {
    transform(m1.begin(), m1.end(), m2.begin(), back_inserter(m3), 
    [] (auto r1, auto r2) {
      vector<T> r3;
      transform(r1.begin(), r1.end(), r2.begin(), back_inserter(r3), plus<T>());
      return r3;
    });
  }
  return m3;
}

/* 
matrix must not be empty:
- if true, multiply T scalar value by m
- if false, return empty matrix (no elements)
*/
template<typename T>
matrix<T> scalar_multiply(const matrix<T> &m, const T & val){
  matrix<T> m2;
  if (!m.empty()) {
    transform(m.begin(), m.end(), back_inserter(m2), 
    [&val] (auto r1) {
      vector<T> r2;
      transform(r1.begin(), r1.end(), back_inserter(r2), 
      [&val] (auto e) {
        return e * val;
      });
      return r2;
    });
  }
  return m2;
}
    
int main(){
  matrix<long> m1{ {0,1,2}, {3,4,5}, {6,7,8} };
  matrix<long> m2{ {0,1}, {2,3}, {4,5} };
  matrix<long> m3;
  matrix<long> result;

  // case 1
  cout << "Case 1" << endl;
  result = add(m1,m1);
  if (! result.empty() )
    cout << matrix_to_str(result) << endl;
  else
    cout << "could not add" << endl;

  
  // case 2
  cout << "Case 2" << endl;
  result = add(m1, m2);
  if (! result.empty() )
    cout << matrix_to_str(result) << endl;
  else
    cout << "could not add" << endl;

  // case 3
  cout << "Case 3" << endl;
  matrix<double> m_d { {0.3,1.2}, {2,3.4}, {4,-5} };
  double factor = 3.8;
  
  matrix<double> result_d = scalar_multiply(m_d, factor);
  if (! result_d.empty() )
  cout << matrix_to_str(result_d, 8) << endl;
  else
  cout << "could not multiply" << endl;
  
  // case 4
  cout << "Case 4" << endl;
  result = scalar_multiply(m3,3l);
  if (! result.empty() )
    cout << matrix_to_str(result) << endl;
  else
    cout << "could not multiply" << endl; 
  
}