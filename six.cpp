#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
    int a = 100;
    while (a < 1000) {
        if (pow((a / 100), 3) + pow(((a % 100) / 10), 3) + pow(a%10, 3) == a) {
            cout << a << ' ';
        }
        a += 1;
    }
}
