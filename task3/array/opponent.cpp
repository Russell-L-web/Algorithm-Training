#include <cmath>
#include <iostream>

using namespace std;

int main(void) {
    int N;
    cin >> N;
    int arr[1005][3];
    int sum[1005];
    for (int i = 0; i < N; i++) {
        cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
        sum[i] = arr[i][0] + arr[i][1] + arr[i][2];
    }

    int num = 0;
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            if (abs(arr[i][0] - arr[j][0]) <= 5 && abs(arr[i][1] - arr[j][1]) <= 5 &&
                abs(arr[i][2] - arr[j][2]) <= 5 && abs(sum[i] - sum[j]) <= 10) {
                num++;
            }
        }
    }

    cout << num << endl;

    return 0;
}