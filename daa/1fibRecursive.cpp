// Design and Analysis of Algorithms
#include <iostream>
using namespace std;

int stepCount = 0;

int fibRecursive(int n) {
    stepCount++;
    if (n == 0) return 0;
    if (n == 1) return 1;
    return fibRecursive(n - 1) + fibRecursive(n - 2);
}

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;

    stepCount = 0;
    int result = fibRecursive(n);
    cout << "Fibonacci(" << n << ") = " << result << endl;
    cout << "Steps (Recursive): " << stepCount << endl;
}
