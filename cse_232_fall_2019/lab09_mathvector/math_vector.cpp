#include<string>
using std::string;
#include<cmath>
#include<iostream>
#include<sstream>
using std::ostringstream;

#include "math_vector.h"

MathVector MathVector::add (const MathVector& v2) {
  long x3 = x + v2.x;
  long y3 = y + v2.y;
  MathVector v3(x3, y3);
  return v3;
}

MathVector MathVector::mult(long c) {
  long x2 = x * c;
  long y2 = y * c;
  MathVector v2(x2, y2);
  return v2;
}

long MathVector::mult(const MathVector& v2) {
  long prod = x * v2.x + y * v2.y;
  return prod;
}

double MathVector::magnitude() {
  double mag = sqrt(static_cast<double>( x * x + y * y));
  return mag;
}

string vec_to_str(const MathVector& v) {
  ostringstream oss;
  oss << v.x << ':' << v.y;
  return oss.str();
}