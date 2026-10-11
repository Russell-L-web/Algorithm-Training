#include <iostream>
#include <cmath>
using namespace std;

int main(){

    int a, b, c;
    cin >> a;
    b = 5 * a;
    c = 3 * a + 11;
    if (b < c) {
        cout << "Local";
    } else {
        cout << "Luogu";
    }
    
    return 0;
}