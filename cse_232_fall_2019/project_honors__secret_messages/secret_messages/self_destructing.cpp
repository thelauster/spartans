#include<algorithm>
using std::transform;
#include<vector>
using std::back_inserter;
#include<stdexcept>
using std::invalid_argument; using std::out_of_range;
#include<iomanip>
using std::setw; using std::setfill;

#include "self_destructing.h"
#include "redact.h"

// Constructor
SelfDestructingMessage::SelfDestructingMessage(vector<string> m, long views) {
  messages_ = m;
  max_views_ = views;
  std::cout << views << std::endl;
  allowed_views_ = vector<long>(static_cast<int>(m.size()), views);
}

// Returns the number of messages in the sdm
size_t SelfDestructingMessage::size() {
  return messages_.size();
}

// Returns a list of messages into a list of alphanum-redacted messages
vector<string> SelfDestructingMessage::get_redacted() {
  vector<string> redacted_v;
  transform(messages_.begin(), messages_.end(), back_inserter(redacted_v),
  [](const string & s){
    return redact_alphabet_digits(s);
  });
  return redacted_v;
}

// Returns the number of views remaining for a specific message
long SelfDestructingMessage::number_of_views_remaining(size_t index) {
  return allowed_views_[index];
}

// Returns the complete message and reduces the number of views for that line
const string& SelfDestructingMessage::operator[](size_t index) {
  if (index >= size()) {
    throw out_of_range("");
  }
  if (allowed_views_[index] <= 0) {
    throw invalid_argument("");
  }
  allowed_views_[index]--;
  return messages_[index];
}

// Outputs all messages with remaining views and redacted alphanum characters
ostream& operator<<(ostream &out, SelfDestructingMessage & sdm) {
  vector<string> redacted_v = sdm.get_redacted();
  for (int i = 0; i < static_cast<int>(sdm.size()); ++i) {
    out << setw(2) << setfill('0') << sdm.allowed_views_[i];
    out << ": " << redacted_v[i] << '\n';
  }
  return out;
}

// Input lines are added to messages with starting number of views
istream& operator>>(istream &in, SelfDestructingMessage & sdm) {
  string line;
  while (getline(in, line)) {
    sdm.messages_.push_back(line);
    sdm.allowed_views_.push_back(sdm.max_views_);
  }
  return in;
}

// Adds lines to list of messages with starting number of views
void SelfDestructingMessage::add_array_of_lines(string ary[], long size) {
  for (string *p = ary; p < ary + size; ++p) {
    string line = *p;
    messages_.push_back(line);
    allowed_views_.push_back(max_views_);
  }
}

//Helper function to set remaining views for all messages to 0
void SelfDestructingMessage::clear_views() {
  allowed_views_ = vector<long>(static_cast<int>(size()), 0);
}

// Copy Construction
SelfDestructingMessage::SelfDestructingMessage(SelfDestructingMessage& sdm) {
  messages_ = sdm.messages_;
  allowed_views_ = sdm.allowed_views_;
  max_views_ = sdm.max_views_;
  sdm.clear_views();
}

// Assignment Operator
SelfDestructingMessage& SelfDestructingMessage::operator=(SelfDestructingMessage sdm) {
  messages_ = sdm.messages_;
  allowed_views_ = sdm.allowed_views_;
  max_views_ = sdm.max_views_;
  sdm.clear_views();
  return *this;
}
