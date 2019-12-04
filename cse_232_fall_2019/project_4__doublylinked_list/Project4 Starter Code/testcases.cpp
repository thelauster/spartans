#include "DLL.h"

void test_add_back() {
	vector<Node> v = { Node("one", 1), Node("two", 2) };
	auto list = DLL(v);
	cout << "My result: " << list << '\n';
	cout << "Expected:  " << Node("one", 1) << ", " << Node("two", 2) << '\n';
}

void test_add_front() {
	vector<Node> v = { Node("one", 1), Node("two", 2) };
	auto list = DLL(v);
	list.add_front("zero", 0);
	cout << "\nMy result: " << list << '\n';
	cout << "Expected:  " << Node("zero", 0) << ", " << Node("one", 1) << ", " << Node("two", 2) << '\n';
}

void test_add_after() {
  /*
	vector<Node> v = { Node("one", 1), Node("two", 2) };
	auto list = DLL(v);
	cout << list.add_after("one", "middle", 7) << '\n';
	cout << "\nMy result: " << list << '\n';
	cout << "Expected:  " << Node("one", 1) << ", " << Node("middle", 7) << ", " << Node("two", 2) << '\n';

  cout << list.add_after("two", "end", 3) << '\n';
	cout << "\nMy result: " << list << '\n';
	cout << "Expected:  " << Node("one", 1) << ", " << Node("middle", 7) << ", " << Node("two", 2) <<
	", " << Node("end", 3) << '\n';*/
  
  vector<Node> vec = { Node("one", 1), Node("two", 2) };
  auto list2 = DLL(vec);
  list2.add_after("two","end", 50);
  cout << list2.get_size() << std::endl; // == 3);
  cout << list2.get_tail()->key << std::endl; //== "end");
  cout << list2.get_tail()->value << std::endl; //== 50);
  cout << (list2.get_tail()->next == nullptr) << std::endl; //== nullptr);
}

void test_remove_front() {
	vector<Node> v = { Node("one", 1), Node("two", 2) };
	auto list = DLL(v);
	list.remove_front();
	cout << "\nMy result: " << list << '\n';
	cout << "Expected:  " << Node("two", 2) << '\n';
	list.remove_front();
	cout << "\nMy result: " << list << '\n';
	cout << "Expected:  " << '\n';
	
	cout << list.get_size();
}

void test_remove_back() {
	vector<Node> v = { Node("one", 1), Node("two", 2) };
	auto list = DLL(v);
	list.remove_back();
	cout << "\nMy result: " << list << '\n';
	cout << "Expected:  " << Node("one", 1) << '\n';
	list.remove_back();
	cout << "\nMy result: " << list << '\n';
	cout << "Expected:  " << '\n';
	
	cout << list.get_size();
}

void test_remove_key() {
	vector<Node> v = { Node("one", 1), Node("two", 2), Node("three", 3), Node("four", 4) };
	auto list = DLL(v);
	list.remove_key("two");
	cout << "\nMy result: " << list << '\n';
	cout << "Expected:  " << Node("one", 1) << ", " << Node("three", 3) << ", " << Node("four", 4) << '\n';
	
	list.remove_key("four");
	cout << "\nMy result: " << list << '\n';
	cout << "Expected:  " << Node("one", 1) << ", " << Node("three", 3) << '\n';
	
	list.remove_key("three");
	cout << "\nMy result: " << list << '\n';
	cout << "Expected:  " << Node("one", 1) << '\n';
}

void test_search() {
	vector<Node> v = { Node("one", 1), Node("two", 2), Node("three", 3) };
	auto list = DLL(v);
	auto result = list.search("two");
	cout << "result address:" << &result << std::endl;
	cout << "\nMy result: " << result << '\n';
	cout << "Expected:  " << Node("two", 2) << '\n';
}

void test_update_value() {
	vector<Node> v = { Node("one", 1), Node("two", 2), Node("three", 3) };
	auto list = DLL(v);
	list.update_value("two", 22);
	cout << "\nMy result: " << list << '\n';
	cout << "Expected:  " << Node("one", 1) << ", " << Node("two", 22) << ", " << Node("three", 3) << '\n';
}

void test_12a() {
  vector<Node> vec = { Node("one", 1), Node("two", 2) };
	auto list = DLL(vec);
	auto ret = list.remove_front();
	cout << (list.get_head() == list.get_tail()) << std::endl;
	cout << (ret == Node("one", 1)) << std::endl;
	cout << (list.get_size() == 1) << std::endl;
}

void test_3b() {
  vector<Node> vec = { Node("one", 1), Node("two", 2) };
	auto list = DLL(vec);
	list.add_after("two","end", 50);
	cout << (list.get_size() == 3) << std::endl;
	cout << (list.get_tail()->key == "end") << std::endl;
	cout << (list.get_tail()->value == 50) << std::endl;
	cout << (list.get_tail()->next == nullptr) << std::endl;
}

int main() {
	test_add_back();
	test_add_front();
	test_add_after();
	test_remove_front();
	test_remove_back();
	test_remove_key();
  test_search();
	test_update_value();
	//test_3b();
	return 0;
}