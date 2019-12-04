#pragma once

#include<iostream>
using std::ostream; using std::cout; using std::endl;

struct Node{
public:
    int data_;
    Node *next_;

    
    Node() : data_( 0 ), next_(nullptr) {};
    Node(int d) : data_(d), next_(nullptr) {};
};

class SingleLink{
private:
    Node *head_;
    Node *tail_;
  
public:
  SingleLink();
  SingleLink(int dat);
  void append_back(int);

  friend ostream& operator<<(ostream &out, SingleLink & s);
  bool del(int val);
  Node& operator[](size_t index);
  
  // Rule of three stuff
  ~SingleLink();
  SingleLink(const SingleLink &);
  SingleLink& operator=(SingleLink);
  
};

