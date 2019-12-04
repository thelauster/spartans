#ifndef PRINT
#define PRINT

template<typename T>
string set_to_string(const set<T>& s);

template<typename K, typename V>
string pair_to_string(pair<K,V> p);

template<typename K, typename V>
void print_map(const map<K,V>& m);

void f1(int i);

#endif