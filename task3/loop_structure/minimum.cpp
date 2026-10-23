#include <algorithm>
#include <iostream>
using namespace std;

int main() {
    int n;
    while (1) {
        cout << "Please enter a number (n <= 100):";
        cin >> n;
        if (n > 100 || n < 0) {
            cout << "Error: n is invalid!" << endl;
        } else {
            break;
        }
    }

    int arr[105];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr, arr + n);
    cout << arr[0] << endl;

    return 0;
}