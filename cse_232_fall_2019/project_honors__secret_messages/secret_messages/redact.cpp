#include<sstream>
using std::istringstream; using std::ostringstream;
#include<cctype>
using std::isalnum;
#include<string>
using std::getline;
#include<algorithm>
using std::find; using std::fill;

#include "redact.h"

// Redacts all characters with '#'
string redact_all_chars(const string & s) {
  istringstream iss(s);
  ostringstream oss;
  char ch;
  while (iss.get(ch)) {
    oss << '#';
  }
  return oss.str();
}

// Redacts all alpha-numeric characters with '#'
string redact_alphabet_digits(const string & s) {
  istringstream iss(s);
  ostringstream oss;
  char ch;
  while (iss.get(ch)) {
    if (isalnum(ch)) {
      oss << '#';
    } else {
      oss << ch;
    }
  }
  return oss.str();
}

// Redacts secret words found in a given string with '#'
string redact_words(const string & s, const vector<string> & v) {
  istringstream iss(s);
  ostringstream oss;
  char ch;
  string word;
  while (iss.get(ch)) {
    // if: Constructs words from the iss until a non-alphanum char is reached
    // else: Replaces any secret words found in constructed word with '#'
    if (isalnum(ch)) {
      word += ch;
    } else {
      for (auto secret:v) {
        if (word.find(secret, 0) != string::npos) {
          auto fill_start = word.begin() + word.find(secret, 0);
          auto fill_end = fill_start + secret.size();
          fill(fill_start, fill_end, '#');
        }
      }
      oss << word << ch;
      word = ""; // Clear word
    }
  }
  return oss.str();
}
