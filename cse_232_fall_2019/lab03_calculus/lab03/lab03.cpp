#include<iostream>
using std::cin; using std::cout; using std::endl;
#include<iomanip>
using std::fixed; using std::setprecision;
#include<cmath>
using std::pow;

double fn (double x) {
    return -6 * pow(x , 2) + 5 * x + 3;
}

double integral(double x) {
    return -2 * pow(x, 3) + 2.5 * pow(x, 2) + 3 * x;
}

double trapezoid(double a, double b, long n) {
    double area = 0;
    double diff = b - a;
    double dx = diff / n;
  
    //for (long i = n; i > 0; i--) {
    //    long interval = n - i;
    for (long i = 0; i < n; i++) {
        double x_0 = a + i * dx;
        double x_1 = a + (i + 1) * dx;
        
        double y_0 = fn(x_0);
        double y_1 = fn(x_1);
        
        double t_area = 0.5 * (y_0 + y_1) * dx;
        area += t_area;
    }
    
    return area;
}

int main () {
    double a; double b; double tolerance; long n;
    cout << "Lower Range:" << endl;
    cin >> a; //cout << endl;
    cout << "Upper Range:" << endl;
    cin >> b; //cout << endl;
    cout << "Tolerance:" << endl;
    cin >> tolerance; //cout << endl;
    cout << "Initial trapezoid count:" << endl;
    cin >> n; //cout << endl;
    
    double approx_area = 0;
    double area = integral(b) - integral(a);
    double difference;
    do {
        approx_area = trapezoid(a, b, n);
        difference = std::abs(approx_area - area);
        //cout << difference << "aa" << approx_area << "a"<< area <<endl;
        if (difference > tolerance) {
            cout << fixed << setprecision(4);
            cout << "Intermediate Result:" << approx_area << ", traps:" 
                << n << ", diff:" << difference << endl;
            n *= 2;
        }
    } while (difference > tolerance);
    
    cout << "Trap count:" << n << ", estimate:" << approx_area
        << ", exact:" << area << ", tolerance:" << tolerance << endl;
}
