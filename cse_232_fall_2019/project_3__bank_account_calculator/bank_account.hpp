#ifndef BANK_ACCOUNT
#define BANK_ACCOUNT

#include<string>
using std::string;
#include<sstream>
using std::istringstream; using std::ostringstream; using std::getline;
#include<iomanip>
using std::setprecision; using std::fixed;
#include<vector>
using std::vector;

//truncates a double to two decimal places
double truncate(double d) {
  int i = static_cast<int>(d * 100);
  d = static_cast<double>(i) / 100;
  return d;
}

void deposit(double& bal, double amt) {
  bal += amt;
}

bool withdraw(double&bal, double amt) {
  if (bal - amt > 0) {
   bal -= amt;
   return true;
  } else {
    return false;
  }
}

void overdraft(double&bal, double amt) {
  bal -= (amt + 35);
}

double interest_for_month(double bal, double apr) {
  return truncate(bal * apr / 1200);
}

// Converts "yy-mm-dd" and assigns to pointers
void string_date_to_int_ptrs(const string& date, int* y, int* m, int* d) {
  istringstream iss(date);
  iss >> *y; iss.get();
  iss >> *m; iss.get();
  iss >> *d;
}

// Converts "yy-mm-dd" and assigns to reference ints
void string_date_to_ints(const string& date, int& y, int& m, int& d) {
  istringstream iss(date);
  iss >> y; iss.get();
  iss >> m; iss.get();
  iss >> d;
}

int number_of_first_of_months(const string& date1, const string& date2) {
  int y1, m1, d1, y2, m2, d2;
  string_date_to_ints(date1, y1, m1, d1);
  string_date_to_ints(date2, y2, m2, d2);
  return (12 * (y2-y1) + (m2-m1));
}

double interest_earned(double bal, double apr, const string& date1, 
                       const string& date2) {
  if (bal <= 0) {
    return 0.0; // No interest accumulated on a nonpositive balance
  }
  int firsts = number_of_first_of_months(date1, date2);
  double starting_bal = bal;
  for (int i = 0; i < firsts; ++i) {
    double interest = interest_for_month(bal, apr);
    bal += interest;
  }
  return bal - starting_bal;
}

// Splits a line at spaces into a vector
vector<string> split(const string &line) {
  istringstream iss(line);
  string item;
  vector<string> v;
  while(getline(iss, item, ' '))
    v.push_back(item);
  return v;
}

// Converts "$###" to a double
double dollar_to_double(const string & dollar) {
  istringstream iss(dollar);
  iss.get();
  double d;
  iss >> d;
  return d;
}

string process_command(const string& line, string& prev_date, 
                       double& bal, double apr) {
  vector<string> data = split(line);
  string date = data[0];
  string command = data[1];
  string amt_str = data[2];
  
  ostringstream oss;
  oss << fixed << setprecision(2);
  oss << "On " << date << ": Instructed to perform \"" << command << " " 
      << amt_str << "\"\n"; 
      
  // Only processes interest if prev date exists
  if (!prev_date.empty()) { 
    int firsts = number_of_first_of_months(prev_date, date);
    // Only processes interest if >1 month has passed
    if (firsts) { 
      oss << "Since " << prev_date << ", interest has accrued " << firsts 
          << " times.\n";
      double interest = interest_earned(bal, apr, prev_date, date);
      oss << '$' << interest << " interest has been earned.\n";
      bal += interest;
    }
  }
  
  double amt = dollar_to_double(amt_str);
  if (command == "Deposit") {
    deposit(bal, amt);
  } else if (command == "Withdraw") {
    if (!withdraw(bal, amt)) {
      overdraft(bal, amt);
      oss << "Overdraft!\n";
    }
  }
  
  oss << "Balance: " << bal << '\n';
  prev_date = date;
  return oss.str();
}

string process_commands(const string& lines, double apr) {
  istringstream iss(lines);
  ostringstream oss;
  string line;
  string prev_date = "";
  double bal = 0;
  while (getline(iss, line)) {
    oss << process_command(line, prev_date, bal, apr);
  }
  return oss.str();
}

#endif
