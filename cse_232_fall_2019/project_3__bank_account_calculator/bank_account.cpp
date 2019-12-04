/*
#include<string>
using std::string;
#include<sstream>
using std::istringstream;

#include "bank_account.hpp"

void deposit(double& bal, double amt) {
  bal += amt;
}

void withdraw(double&bal, double amt) {
  bal -= amt;
}

void overdraft(double&bal, double amt) {
  bal -= (amt + 35);
}

double interest_for_month(double& bal, double apr) {
  return bal * apr / 1200;
}

void string_date_to_int_ptrs(const string& date, int* y, int* m, int* d) {
  istringstream iss(date);
  iss >> *y;
  iss.get();
  iss >> *m;
  iss.get();
  iss >> *d;
}

void string_date_to_ints(const string& date, int& y, int& m, int& d) {
  istringstream iss(date);
  iss >> y;
  iss.get();
  iss >> m;
  iss.get();
  iss >> d;
}

int number_of_first_of_months(const string& date1, const string& date2) {
  int y1, m1, d1, y2, m2, d2;
  string_date_to_ints(date1, y1, m1, d1);
  string_date_to_ints(date2, y2, m2, d2);
  return (12 * (y2-y1) + (m2-m1));
}

double interest_earned(double bal, double apr, const string& date1, const string& date2) {
  return 0.0;
}
*/