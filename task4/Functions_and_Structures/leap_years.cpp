#include <iostream>
using namespace std;

bool isLeapYear(int a) {
    if ((a % 4 == 0 && a % 100 != 0) || (a % 400 == 0)) {
        return 1;
    }
    return 0;
}

int main(void) {
    int x, y;
    cin >> x >> y;
    int arr[355];
    int num = 0;
    for (; x <= y; x++) {
        if (isLeapYear(x)) {
            arr[num] = x;
            num++;
        }
    }

    cout << num << endl;

    for (int i = 0; i < num; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}