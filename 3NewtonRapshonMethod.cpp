#include <bits/stdc++.h>
using namespace std;
#define tolerance 1e-5

class NewtonRaphson {
private:
    double x0;  // initial guess

public:
    NewtonRaphson() {
        randomNumberGenerator();
    }

    // Example function: f(x) = x^3 - 3x - 1
    double function(double x) {
        return x * x * x - 3 * x - 1;
    }

    // Derivative: f'(x) = 3x^2 - 3
    double derivative(double x) {
        return 3 * x * x - 3;
    }

    // Generate random initial guess
    void randomNumberGenerator() {
        srand(time(0));
        x0 = rand() % 201 - 100;  // random between -100 and 100
    }

    // Newton-Raphson Iteration
    void findRoot() {
        double x = x0;
        int iter = 0;

        while (fabs(function(x)) >= tolerance) {
            double d = derivative(x);
            if (d == 0) { // avoid division by zero
                cout << "Derivative is zero. Stopping iteration.\n";
                return;
            }

            double x1 = x - function(x) / d;

            cout << "Iteration " << ++iter << ": x = " << x1 << '\n';

            if (fabs(x1 - x) < tolerance) {
                cout << "The root is approximately: " << x1 << '\n';
                return;
            }

            x = x1;
        }

        cout << "The root is approximately: " << x << '\n';
    }

    void equation() {
        cout << "Equation: x^3 - 3x - 1" << '\n';
    }

    void displayInitialGuess() {
        cout << "Initial guess: " << x0 << '\n';
    }
};

int main() {
    NewtonRaphson nr;
    nr.displayInitialGuess();
    nr.findRoot();
    return 0;
}
