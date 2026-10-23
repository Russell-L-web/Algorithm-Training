#include <iomanip>
#include <iostream>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    int a = 0, b = 0;
    int num1 = 0, num2 = 0;

    for (int i = 1; i <= n; i++) {
        if (i % k == 0) {
            a += i;
            num1++;
        } else {
            b += i;
            num2++;
        }
    }

    double c = 1.0 * a / num1;
    double d = 1.0 * b / num2;
    cout << fixed << setprecision(1) << c << " " << d << endl;

    return 0;
}