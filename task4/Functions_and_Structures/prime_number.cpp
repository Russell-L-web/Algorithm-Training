#include <iostream>
using namespace std;

int main() {
    int n, a, b;
    cin >> n;

    for (int i = 2; i <= n / i; i++) {
        if (n % i == 0) {
            cout << n / i << endl;
            break;
        }
    }

    return 0;
}