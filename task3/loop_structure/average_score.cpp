#include <algorithm>
#include <iomanip>
#include <iostream>

using namespace std;

int main() {
    int n, i;
    cin >> n;
    int arr[1005];
    for (i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    int sum = 0;
    for (i = 1; i < n - 1; i++) {
        sum += arr[i];
    }

    float score = 1.0 * sum / (n - 2);
    cout << fixed << setprecision(2) << score << endl;

    return 0;
}