#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int arr[110];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < n; i++) {
        int num, m;
        for (num = 0, m = 0; m < i + 1; m++) {
            if (arr[i] > arr[m])
                num++;
        }
        cout << num << " ";
    }

    return 0;
}