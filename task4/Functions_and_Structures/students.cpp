#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

struct Stu {
    string name;
    int a, b, c;
    int sum;
};

bool cmp(Stu x, Stu y) {
    return x.sum > y.sum;
}

int main() {
    int N;
    cin >> N;
    Stu students[1000];
    for (int i = 0; i < N; i++) {
        cin >> students[i].name >> students[i].a >> students[i].b >> students[i].c;
        students[i].sum = students[i].a + students[i].b + students[i].c;
    }

    sort(students, students + N, cmp);

    cout << students[0].name << " ";
    cout << students[0].a << " ";
    cout << students[0].b << " ";
    cout << students[0].c << endl;

    return 0;
}