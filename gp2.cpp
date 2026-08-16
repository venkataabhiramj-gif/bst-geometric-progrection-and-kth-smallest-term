#include <iostream>
using namespace std;

int main() {
    double a, r, sum = 0;
    int n, i;

    cout << "Enter first term: ";
    cin >> a;

    cout << "Enter common ratio: ";
    cin >> r;

    cout << "Enter number of terms: ";
    cin >> n;

    for (i = 1; i <= n; i++) {
        sum = sum + a;
        a = a * r;
    }

    cout << "Sum = " << sum;

    return 0;
}