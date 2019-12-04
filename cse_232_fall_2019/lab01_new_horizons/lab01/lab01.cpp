#include <iostream>
using std::cout; using std::cin; using std::endl; using std::fixed;
#include<iomanip>
using std::setprecision;

int main() {
    cout << fixed << setprecision(2);
    int days;
    double speed_kms = 14.33, speed_mps = 8.90;  // km/s and mi/s
    double start_au = 37.33; 
    double start_km = 149598000 * start_au;
    double start_mi = 92955800 * start_au;
    double radio_ms = 299792458;  // radio speed m/s
    cin >> days;
    double distance_km = speed_kms * 86400 * days + start_km;
    double distance_mi = speed_mps * 86400 * days + start_mi;
    double radio_hours = distance_km * 1000 * 2 / (radio_ms * 3600);
    cout << distance_km << endl;
    cout << distance_mi << endl;
    cout << radio_hours << endl;
    return 0;
}
