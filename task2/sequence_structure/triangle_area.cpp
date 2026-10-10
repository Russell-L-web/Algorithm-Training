#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main() {

    int a, b, c;
    double p, S;
    cout << "Enter the lengths of the three sides of the triangle: ";
    cin >> a >> b >> c;
    p = (a + b + c) / 2.0;
    S = sqrt(p * (p - a) * (p - b) * (p - c));
    cout << "The area of the triangle is: " << fixed << setprecision(1) << S << endl;
    
    return 0;
}