#include <iostream>
#include <string>
using namespace std;

struct Stu {
    int num;
    int score;
    int expand;
    int composite() {
        return score * 7 + expand * 3;
    };
    int total() {
        return score + expand;
    };
};

string isExcellent(Stu a) {
    if ((a.total() > 140) && (a.composite() >= 800)) {
        return "Excellent";
    } else {
        return "Not excellent";
    }
}

int main() {
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        Stu student;
        cin >> student.num >> student.score >> student.expand;
        cout << isExcellent(student) << endl;
    }

    return 0;
}