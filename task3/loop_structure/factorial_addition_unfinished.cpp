#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int s = 1;
    int S = 0;
    for (int i = 1; i <= n; i++) {
        s *= i;
        S += s;
    }
    cout << S << endl;

    return 0;
}