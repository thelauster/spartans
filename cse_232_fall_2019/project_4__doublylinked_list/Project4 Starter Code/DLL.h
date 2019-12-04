#pragma once
#include<iostream>
using std::ostream; using std::cout;
#include<string>
using std::string;
#include <vector>
using std::vector;
#include <sstream>
using std::ostringstream;
// DO NOT MODIFY
//
// Node
//
struct Node {
	string key;
	int value;
	Node* next = nullptr;
	Node* prev = nullptr;
	Node() = default;
	Node(string, int);
	bool operator==(const Node&) const;
	friend ostream& operator<<(ostream& out, const Node& n) {
		out << n.key << ":" << n.value;
		return out;
	}
};

Node::Node(string key_, int value_) {
	key = key_;
	value = value_;
}

bool Node::operator==(const Node& n) const {
	if ((key == n.key) && (value == n.value)) {
		return true;
	}
	else {
		return false;
	}
}

// DO NOT MODIFY
//
// DLL
//
class DLL {
private:
	Node* head_ = nullptr;
	Node* tail_ = nullptr;
	size_t sz_ = 0;
public:
	DLL() = default;
	DLL(const DLL&);
	DLL(vector<Node>);
	Node* get_head();
	Node* get_tail();
	size_t get_size();
	Node add_back(string, int);
	Node add_front(string, int);
	Node add_after(string, string, int);
	Node search(string);
	Node remove_front();
	Node remove_back();
	Node remove_key(string);
	int update_value(string, int);
	friend ostream& operator<<(ostream& out, const DLL& list) {
		auto itr = list.head_;
		ostringstream oss;
		for (; itr != nullptr; itr = itr->next) {
			oss << itr->key << ":" << itr->value << ", ";
		}
		string ans = oss.str();
		ans = ans.substr(0, ans.size() - 2);
		out << ans;
		return out;
	}
};

Node* DLL::get_head() {
	return head_;
}
Node* DLL::get_tail() {
	return tail_;
}
size_t DLL::get_size() {
	return sz_;
}

DLL::DLL(const DLL& list) {
	head_ = list.head_;
	tail_ = list.tail_;
	sz_ = list.sz_;
}

DLL::DLL(vector<Node> vec) {
	for (const auto& node : vec) {
		add_back(node.key, node.value);
	}
}

// Add a node behind the last in the DLL. Returns added node
Node DLL::add_back(string str, int num) {
	Node * new_ptr = new Node(str, num);
	if (tail_ == nullptr) { // No nodes in DLL case
	  head_ = new_ptr;
	} else {
  	tail_->next = new_ptr;
  	new_ptr->prev = tail_;
	}
	tail_ = new_ptr;
	++sz_;
	return *new_ptr;
}

// Add a node before the first in the DLL. Returns added node
Node DLL::add_front(string str, int num) {
	Node * new_ptr = new Node(str, num);
	if (head_ == nullptr) { // No nodes in DLL case
	  tail_ = new_ptr;
	} else {
  	head_->prev = new_ptr;
  	new_ptr->next = head_;
	}
  head_ = new_ptr;
  ++sz_;
	return *new_ptr;
}

// Add a node after one with the given key. 
// Returns added node if key exists. Otherwise, returns empty node
Node DLL::add_after(string add_key, string str, int num) {
	Node * track_ptr = head_;
	while (track_ptr != nullptr) {
	  Node & current_node = *track_ptr;
	  if (add_key == current_node.key) {
	    if (current_node.next == nullptr) {
	      return add_back(str, num);
	    } else {
	      Node * new_ptr = new Node(str, num);
	      Node & next_node = *(current_node.next);
  	    current_node.next = new_ptr;
  	    next_node.prev = new_ptr;
  	    new_ptr->next = &next_node;
  	    new_ptr->prev = &current_node;
  	    ++sz_;
  	    return *new_ptr;
	    }
	  } else {
	    track_ptr = current_node.next;
	  }
	}
	return Node();
}

// Copies and deletes a dynamically allocated node
Node get_copy(Node* old_ptr) {
  Node copy = *old_ptr;
  delete old_ptr;
  return copy;
}

// Removes the last node in a DLL. If empty DLL, returns empty node
// If key found, returns a copy of the deleted node. Otherwise, returns empty
Node DLL::remove_back() {
	if (tail_ == nullptr) {
	  return Node();
	}
	Node * old_ptr = tail_;
	if (tail_ == head_) {
	  tail_ = nullptr;
	  head_ = nullptr;
	} else {
  	tail_ = old_ptr->prev;
  	tail_->next = nullptr;
	}
	--sz_;
	return get_copy(old_ptr);
}

// Removes the last node from DLL. 
// If key found, returns a copy of the deleted node. Otherwise, returns empty
Node DLL::remove_front() {
	if (head_ == nullptr) {
	  return Node();
	}
	Node * old_ptr = head_;
	if (head_ == tail_) {
	  tail_ = nullptr;
	  head_ = nullptr;
	} else {
  	head_ = old_ptr->next;
  	head_->prev = nullptr;
	}
	--sz_;
	return get_copy(old_ptr);
}

// Removes node with a given key from DLL.
// If key found, returns a copy of the deleted node. Otherwise, returns empty
Node DLL::remove_key(string to_remove) {
  Node * track_ptr = head_;
	while (track_ptr != nullptr) {
	  Node & current_node = *track_ptr;
	  if (to_remove == current_node.key) {
	    if (current_node.prev == nullptr) {
	      return remove_front();
	    } 
	    if (current_node.next == nullptr) {
	      return remove_back();
	    }
	    Node & next_node = *(current_node.next);
	    Node & prev_node = *(current_node.prev);
	    prev_node.next = &next_node;
	    next_node.prev = &prev_node;
	    --sz_;
	    return get_copy(track_ptr);
	  } else {
	    track_ptr = current_node.next;
	  }
	}
	return Node(); // No key found
}

//Returns a copy of a node given a key. If no key exists, returns empty node
Node DLL::search(string find_key) {
  // If this function returned a reference to a node, it could be used in the
  // functions remove_key, add_after, and update_value to streamline the code.
	Node * track_ptr = head_;
	while (track_ptr != nullptr) {
	  Node & current_node = *track_ptr;
	  if (find_key == current_node.key) {
	      return current_node;
	    } else {
	    track_ptr = current_node.next;
	  }
  }
  return Node(); // No key found
}

// Updates the value of a node at a key. 
// Returns updated value if key exists. Returns -1 otherwise
int DLL::update_value(string find_key, int new_value) {
	Node * track_ptr = head_;
	while (track_ptr != nullptr) {
	  Node & current_node = *track_ptr;
	  if (find_key == current_node.key) {
	    current_node.value = new_value;
	    return current_node.value;
	  } else {
	    track_ptr = current_node.next;
	  }
	}
	return -1; // No key found
}
