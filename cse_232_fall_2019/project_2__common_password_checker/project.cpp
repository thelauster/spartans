#include<iostream>
using std::cin; using std::cout; using std::endl;
#include<string>
using std::string;
#include<set>
using std::set;
#include<map>
using std::map;
#include<fstream>
using std::ifstream;
#include<algorithm>
using std::min; using std::max;

// Calculates the difference between two strings
int get_difference (const string& pw, const string& ref) {
  size_t n = min(pw.size(), ref.size());
  size_t m = max(pw.size(), ref.size());
  int differences = 0;
  // Compares shortest strings
  for (size_t i = 0; i < n; ++i) {
    if (pw[i] != ref[i]) {
      ++differences;
    } 
  }
  differences += static_cast<int>(m - n); // Accounts for size difference
  return differences;
}

// Builds a map of the number of differences 
// to the set of passwords with that difference.
map<int, set<string>> check_pw (const string& pw) {
  map<int, set<string>> pw_map;
  
  ifstream common_pws("common_passwords.txt");
  string ref;
  while (!common_pws.eof()) {
    common_pws >> ref; //reference word to check password against
    int diff = get_difference(pw, ref);
    pw_map[diff].insert(ref);
  }
  return pw_map;
}

int main() {
  string pw;
  cout << "Give me a password:" << endl;
  cin >> pw;
  cout << "You provided a password of " << pw << endl;
  map<int, set<string>> pw_map = check_pw(pw);
  int diff = pw_map.begin()->first; 
  set<string> refs = pw_map.begin()->second;
  
  cout << "The most similar passwords to " << pw << " are:" << endl;
  for (auto ref:refs) {
    cout << ref << ", ";
  }
  cout << endl;
  
  cout << "All of which are " << diff << " character(s) different." << endl;
}
