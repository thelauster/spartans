#include<iostream>
using std::cin; using std::cout; using std::endl;

#include<string>
using std::string;

#include<cmath>

long loc_to_dec(string loc) {
    int sum = 0;
    string::size_type loc_sz = loc.size();
    for (long i = 0; i < static_cast<long>(loc_sz); i++ ) {
        int num = static_cast<int>(loc[i]) - 97;
        sum += pow(2, num);
    }
    return sum;
}

string abbreviate(string loc) {
    string::size_type loc_sz = loc.size();
    for (long i = 0; i < static_cast<long>(loc_sz); ) {
        char chr = loc[i];
        char nxt_chr = chr + 1;
        if (loc.find(chr, i + 1) != string::npos) {
            string::size_type nxt_pos = loc.find(chr, i + 1);
            loc.erase(nxt_pos, 1);
            loc.erase(i, 1);
            string::size_type nxt_chr_pos = i;
            if (loc.find(chr, i) != string::npos) {
                nxt_chr_pos = loc.find_last_of(chr) + 1;
            }
            loc.insert(nxt_chr_pos, 1, nxt_chr);
            loc_sz = loc.size();
        } else {
            i++;
        }
        //cout << i << " " << loc << endl;
    }
    return loc;
}

string dec_to_loc(long dec) {
    string out_str = "";
    int i = 0;
    while (dec - i > 0) {
        out_str.append("a");
        i++;
    }
    return abbreviate(out_str);
}

long add_loc (string loc1, string loc2) {
    string new_loc = loc1 + loc2;
    string shrt_new = abbreviate(new_loc);
    return loc_to_dec(shrt_new);
}
/*
int main() {
    string loc = "";
    string loc1 = "";
    string loc2 = "";
    int dec;
    cout << "Give me a location string:" << endl;
    cin >> loc;
    cout << "Give me an integer:" << endl;
    cin >> dec;
    cout << loc << " to dec: " << loc_to_dec(loc) << endl;
    cout << loc << " abbreviated " << abbreviate(loc) << endl;
    cout << dec << " to loc: " << dec_to_loc(dec) << endl;
    cout << "Give me two more location strings:" << endl;
    cin >> loc1;
    cin >> loc2;
    long added = add_loc(loc1, loc2);
    cout << "Sum of " << loc1 << " and " << loc2 << "is: " << added;
}*/
