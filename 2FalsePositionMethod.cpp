#include <bits/stdc++.h>
using namespace std;
#define tolerance 1e-5

class FalsePosition {
private:
    double a, b;

public:
    FalsePosition() {
        randomNumberGenerator();
    }

    void randomNumberGenerator() {
        srand(time(0));
        do {
            a = rand() % 201 - 100;  // random between -100 and 100
            b = rand() % 201 - 100;
        } while (a == b || function(a) * function(b) >= 0);
    }

    double function(double x) {
        return x * x * x - 3 * x - 1;
    }

    void findRoot() {
        double c;
        while (fabs(b - a) >= tolerance) {
            // False position formula
            c = (a * function(b) - b * function(a)) / (function(b) - function(a));

            if (fabs(function(c)) < tolerance) {
                cout << "The root is approximately: " << c << '\n';
                return;
            } else if (function(c) * function(a) < 0) {
                b = c;
            } else {
                a = c;
            }

            cout << "The root is approximately: " << c << '\n';
        }
    }

    void displayInterval() {
        cout << "Generated interval: [" << a << ", " << b << "]\n";
        cout << "f(a) = " << function(a) << ", f(b) = " << function(b) << '\n';
    }

    void equation() {
        cout << "Equation: x^3 - 3x - 1" << '\n';
    }
};

int main() {
    FalsePosition fp;
    fp.findRoot();
    fp.displayInterval();
    return 0;
}
