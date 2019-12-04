#include<stdexcept>
using std::out_of_range;
#include<iostream>
using std::cout; using std::endl;

#include "singlelink.h"

SingleLink::SingleLink() {
  head_ = nullptr;
  tail_ = nullptr;
}

SingleLink::SingleLink(int dat) {
  Node * node = new Node(dat);
  head_ = node;
  tail_ = node;
}

SingleLink::~SingleLink() {
  Node * current_ptr = head_;
  while (current_ptr != nullptr) {
    Node * next_ptr = current_ptr->next_;
    delete current_ptr;
    current_ptr = next_ptr;
  }
}

SingleLink::SingleLink(const SingleLink & s) {
  head_ = s.head_;
  tail_ = s.tail_;
}

SingleLink& SingleLink::operator=(SingleLink s) {
  head_ = s.head_;
  tail_ = s.tail_;
  return *this;
}

void SingleLink::append_back(int dat) {
  Node * new_node_ptr = new Node(dat);
  if (head_ != nullptr) {
    tail_->next_ = new_node_ptr;
  } else {
    head_ = new_node_ptr;
  }
  tail_ = new_node_ptr;
}

ostream& operator<<(ostream &out, SingleLink & s) {
  Node * lead_ptr = s.head_;
  while (lead_ptr != nullptr ) {
    Node n = (*lead_ptr);
    out << n.data_;
    lead_ptr = n.next_;
    if (lead_ptr != nullptr) {
      out << ", ";
    }
  }
  
  return out;
}

Node& SingleLink::operator[](size_t index) {
  Node * lead_ptr = head_;
  Node * return_ptr = head_;
  for (int i = 0; i <= static_cast<int>(index); ++i) {
    return_ptr = lead_ptr;
    if (return_ptr == nullptr) {
      throw out_of_range("Index out of range");
      break;
    }
    lead_ptr = return_ptr->next_;
  }
  return *return_ptr;
}

bool SingleLink::del(int val) {
  Node * lead_ptr = head_;
  Node * last_ptr = nullptr;
  while (lead_ptr != nullptr) {
    int data = lead_ptr->data_;
    if (data == val) {
      Node * next_ptr = lead_ptr->next_;
      if (lead_ptr == head_) {
        head_ = next_ptr;
      } else {
        last_ptr->next_ = next_ptr;
      }
      delete lead_ptr;
      return true;
    }
    last_ptr = lead_ptr;
    lead_ptr = lead_ptr->next_;
  }
  return false;
}