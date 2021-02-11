#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
    int a = 100;
    while (a < 1000) {
        if ((a*a) % 1000 == a) {
            cout << a << ' ';
        }
        a += 1;
    }
}
