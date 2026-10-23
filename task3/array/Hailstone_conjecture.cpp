#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int arr[1000];
    int num = 0;
    arr[0] = n;

    while (n > 1) {
        if (n % 2 == 1) {
            n = n * 3 + 1;
        } else {
            n /= 2;
        }
        num++;
        arr[num] = n;
    }

    for (; num >= 0; num--) {
        cout << arr[num] << " ";
    }

    return 0;
}