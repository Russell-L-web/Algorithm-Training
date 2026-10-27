#include <cmath>
#include <iomanip>
#include <iostream>

using namespace std;

struct dot {
    double x;
    double y;
};

double dist(dot p1, dot p2) {
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

double curcum(dot p1, dot p2, dot p3) {
    return dist(p1, p2) + dist(p1, p3) + dist(p2, p3);
}

int main(void) {
    dot a, b, c;
    cin >> a.x >> a.y;
    cin >> b.x >> b.y;
    cin >> c.x >> c.y;

    double ans = curcum(a, b, c);
    cout << fixed << setprecision(2) << ans << endl;

    return 0;
}