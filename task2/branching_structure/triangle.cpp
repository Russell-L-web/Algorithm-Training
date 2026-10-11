#include <algorithm>
#include <cmath>
#include <iostream>


using namespace std;

int main() {
    int arr[3];
    cin >> arr[0] >> arr[1] >> arr[2];
    sort(arr, arr + 3);
    int a = arr[0];
    int b = arr[1];
    int c = arr[2];

    if (a + b < c) {
        cout << "Not triangle" << endl;
    } else if (pow(a, 2) + pow(b, 2) < pow(c, 2)) {
        cout << "Obtuse triangle" << endl;
    } else if (pow(a, 2) + pow(b, 2) > pow(c, 2)) {
        cout << "Acute triangle" << endl;
    } else if (pow(a, 2) + pow(b, 2) == pow(c, 2)) {
        cout << "Right triangle" << endl;
    }

    if (a == b) {
        cout << "Isosceles triangle" << endl;
    }

    if (a == b && b == c) {
        cout << "Equilateral triangle" << endl;
    }

    return 0;
}