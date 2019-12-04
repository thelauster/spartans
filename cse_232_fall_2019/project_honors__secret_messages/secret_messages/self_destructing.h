#ifndef SELF_DESTRUCTING_H
#define SELF_DESTRUCTING_H

#include <string>
using std::string;
#include <vector>
using std::vector;
#include <iostream>
using std::ostream; using std::istream;

class SelfDestructingMessage {
  private:
    vector<string> messages_;
    long max_views_;
    vector<long> allowed_views_;
    
  public:
    SelfDestructingMessage() = default;
    SelfDestructingMessage(vector<string> m, long views);
    
    size_t size();
    vector<string> get_redacted();
    long number_of_views_remaining(size_t index);
    void add_array_of_lines(string ary[], long size);
    void clear_views();
    
    const string& operator[](size_t index);
    friend ostream& operator<<(ostream &out, SelfDestructingMessage & sdm);
    friend istream& operator>>(istream &in, SelfDestructingMessage & sdm);
    
    SelfDestructingMessage(SelfDestructingMessage& sdm);
    SelfDestructingMessage& operator=(SelfDestructingMessage);
    
};

#endif
