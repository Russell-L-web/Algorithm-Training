#include <iostream>
#include <string>
using namespace std;

int main() {
    cout << "  * \n"
         << " *** \n"
         << "***** \n"
         << " *** \n"
         << "  * \n"
         << endl;
    
    int number = 3;
    for (int i = 1; i <= 3; i++){
        cout << string(3 - i, ' ') << string(i * 2 - 1, '*') << endl;
    }
    for (int i = 2; i >= 1; i--){
        cout << string(3 - i, ' ') << string(i * 2 - 1, '*') << endl;
    }
    return 0;
}