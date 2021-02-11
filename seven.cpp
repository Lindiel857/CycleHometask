#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
    int a;
    cin >> a;
    int p = 0;
    int q = 1;
    for (int i = 0; i < a; i++) {
        q = p + q;
        p = q - p;
        cout << q << ' ';
    }
}
