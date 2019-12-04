#include<iostream>
using std::cin; using std::cout; using std::endl;
#include<string>
using std::string; using std::stoi; using std::to_string;

// Returns the summation of all of the digits of a string
int get_line_sum (const string & line) {
    int sum = 0;
    string::size_type str_size = line.size();
    for (int i = 0; i < static_cast<int>(str_size); i++) {
        int dig = static_cast<int> (line[i] - '0');
        sum += dig;
    }
    return sum;
}

// Applies rules to a neighborhood and returns the next state
// Rules have format "XXX -> X". If no rules match, returns '0'
char get_next_state(string neigh, const string & rules) {
    string::size_type location = 0;
    char out_chr = '0';
    if (rules.find(neigh) != string::npos) {
        location = rules.find(neigh);
        out_chr = rules[location + 7];
    }
    return out_chr;
}

// Updates a line given a set of rules using get_next_state
void update_line (string & line, const string & rules) {
    string ref = line.back() + line + line.front(); // Accounts for looping
    long line_sz = static_cast<long>(line.size());
    for (long i = 0; i < line_sz ; i++) {
        string neigh = ref.substr(i, 3);
        char new_chr = get_next_state(neigh, rules);
        line.replace(i, 1, 1, new_chr);
    }
}

// Takes in a set of rules, generation number, and starting line
// Returns the line after given generations
string run_cellular_automata (const string & rules, int gen, string line) {
    string output;
    
    // Base case before line updates
    int sum = get_line_sum(line);
    output.append(line + " sum = " + to_string(sum) + '\n');
    
    // Updates lines and adds to output string
    for (int i = 1; i < gen; i++) {
        update_line(line, rules);
        int sum = get_line_sum(line);
        output.append(line + " sum = " + to_string(sum) + '\n');
    }
    return output;
}

int main(){
    string line = "";
    string rules = "";
    int gen;
    
    //Phases (0 - Rules, 1 - Iteration Num, 2 - Starting Line)
    int phase = 0; 
    string input = "";
    while (phase < 3) {
        getline(cin, input);
        if (input == ".") {
            phase = 1;
            continue;
        }
        if (phase == 0) {
            rules.append(input + '\n');
        } else if  (phase == 1) {
            gen = stoi(input);
            phase++;
        } else if (phase == 2) {
            line = input; 
            phase++;
        }
    }
    cout << run_cellular_automata(rules, gen, line) << endl;
}
