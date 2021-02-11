#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
    int a;
    cin >> a;
    int counter = 0;
    for (int u = 0; u < a; u++) {
        int t;
        cin >> t;
        int j = 0;
        int i = 1;
        while (i <= t) {
            i = i + j;
            j = i - j;
            if (i == t) {
                counter += 1;
            }
        }
    }
    cout << counter;
}
