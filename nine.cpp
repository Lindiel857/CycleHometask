#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
    int a;
    int counter = 0;
    cin >> a;
    for (int u = 0; u < a; u++) {
        int t;
        cin >> t;
        int i = 2;
        int y = 0;
        while (i <= sqrt(t)) {
            if (t % i == 0) {
                y = 1;
            }
            i += 1;
        }
        if ((y == 0) and (t > 1)) {
            counter += 1;
        }
    }
    cout << counter;
}
