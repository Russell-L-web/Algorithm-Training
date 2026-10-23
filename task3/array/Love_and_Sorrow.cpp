#include <algorithm>
#include <iostream>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int arr[6666];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int sum[6666] = {0};
    for (int s = 0; s <= n - m; s++) {
        for (int i = 0; i < m; i++) {
            sum[s] += arr[s + i];
        }
    }

    sort(sum, sum + (n - m + 1));
    cout << endl << sum[0];

    return 0;
}