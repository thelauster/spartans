#include<iostream>
using std::cin; using std::cout; using std::endl;
#include<cmath>
using std::pow;

int main() {
    int persistence = 0;
    int root = 0;
    int current_num = 0;
    
    while (cin >> current_num) {
        //Negatives trigger error
        if (current_num < 0) {
            cout << "Error" << endl;
            break;
        }
        root = current_num;
        
        if (current_num / 10 < 1) {
            //Single digit case
            cout << persistence << " " << root << endl;
        } else {
            //Multiple digit case -- continue until only one digit
            while (root / 10 > 0) {
                root = 0;
                //Take digits of number and add to root
                while (current_num != 0) {
                    root += current_num % 10;
                    current_num /= 10;
                }
                current_num = root;
                persistence += 1;
            }
            cout << persistence << " " << root << endl;
        }
    }
}
