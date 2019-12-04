#include<vector>
using std::vector;
using std::max;
#include <iterator>
using   std::back_inserter;
#include<algorithm>
using std::copy;

vector<long> vector_ops(const vector<long>& v1, const vector<long>& v2, char op) {
    vector<long> out_v;
    
    
    if (v1.size() > v2.size()) {
        copy(v1.begin(), v1.end(), back_inserter(out_v));
        for (size_t i = 0; i < v2.size(); ++i) {
            if (char == '+') {
                out_v[i] += v2[i];
            }
            else if (char == '-') {
                out_v[i] -= v2[i];
            }
        }
    } else {
        copy(v2.begin(), v2.end(), back_inserter(out_v));
        for (size_t i = 0; i < v1.size(); ++i) {
            if (char == '+') {
                out_v[i] += v1[i];
            }
            else if (char == '-') {
                out_v[i] -= v1[i];
            }
        }
    }
   
    return out_v;
}