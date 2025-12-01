#include <bits/stdc++.h>
using namespace std;
#define tolerance 1e-5

class Secant {
private:
    double x0, x1;  // two initial guesses

public:
    Secant() {
        randomNumberGenerator();
    }

    // Example function: f(x) = x^3 - 3x - 1
    double function(double x) {
        return x * x * x - 3 * x - 1;
    }

    // Generate two random distinct guesses
    void randomNumberGenerator() {
        srand(time(0));
        do {
            x0 = rand() % 201 - 100;  // between -100 and 100
            x1 = rand() % 201 - 100;
        } while (x0 == x1);
    }

    // Secant Method Iteration
    void findRoot() {
        double f0 = function(x0), f1 = function(x1);
        int iter = 0;

        while (fabs(x1 - x0) >= tolerance) {
            if (fabs(f1 - f0) < 1e-12) { // avoid division by zero
                cout << "Division by zero risk. Stopping iteration.\n";
                return;
            }

            double x2 = x1 - f1 * (x1 - x0) / (f1 - f0);

            cout << "Iteration " << ++iter << ": x = " << x2 << '\n';

            if (fabs(function(x2)) < tolerance) {
                cout << "The root is approximately: " << x2 << '\n';
                return;
            }

            // Shift values for next iteration
            x0 = x1;
            f0 = f1;
            x1 = x2;
            f1 = function(x1);
        }

        cout << "The root is approximately: " << x1 << '\n';
    }

    void equation() {
        cout << "Equation: x^3 - 3x - 1" << '\n';
    }

    void displayInitialGuesses() {
        cout << "Initial guesses: x0 = " << x0 << ", x1 = " << x1 << '\n';
    }
};

int main() {
    Secant sec;
    sec.displayInitialGuesses();
    sec.findRoot();
    return 0;
}
