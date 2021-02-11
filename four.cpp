#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
    double x;
    cin >> x;
    double p = 1;
    double q = x;
    double k = 0.000001;
    while (abs(p - q) > k) {
        p = q;
        q = (x/q + q) / 2.0;
    }
    cout << q << ' ' << sqrt(x);
}
