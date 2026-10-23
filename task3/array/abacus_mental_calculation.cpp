#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());

    int num = 0;
    bool counted[10005] = {false};

    for (int i = 0; i < n; i++) {
        for (int s = i + 1; s < n; s++) {
            for (int t = s + 1; t < n; t++) {
                if (arr[i] + arr[s] == arr[t]) {
                    if (counted[arr[t]] == false) {
                        num++;
                        counted[arr[t]] = true;
                    }
                }
            }
        }
    }

    cout << num << endl;

    return 0;
}