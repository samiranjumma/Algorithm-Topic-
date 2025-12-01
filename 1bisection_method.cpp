#include <bits/stdc++.h>
using namespace std;

class BisectionMethod {
private:
    double a;
    double b;
    double tolerance;

public:
    BisectionMethod(double fi, double se, double e)
        : a(fi), b(se), tolerance(e) {}

    double ValueCalculate(double x) {
        return pow(x, 2) - 2 * x - 4;   // f(x)
    }

    void Iteration() {

        double fa = ValueCalculate(a);
        double fb = ValueCalculate(b);

        if (fa * fb >= 0) {
            cout << "Invalid interval: f(a) and f(b) must have opposite signs.\n";
            return;
        }

        int i = 1;
        double mid, fmid;

        while (fabs(b - a) >= tolerance) {

            mid = (a + b) / 2.0;
            fmid = ValueCalculate(mid);

            printf("Iteration %d: mid = %.6f, f(mid) = %.6f\n", i, mid, fmid);
            i++;

            // Stopping condition when f(mid) is extremely close to zero
            if (fabs(fmid) == 0.0) {
                break;
            }

            if (fa * fmid < 0.0) {
                b = mid;
                fb = fmid;
            } else {
                a = mid;
                fa = fmid;
            }
        }

        printf("Final Root ≈ %.6f\n", mid);
    }
};

int main() {
    srand((unsigned) time(NULL));

    
    double a = (rand() % 101) - 50;   // random between -50 and 50
    double b = (rand() % 101) - 50;   // random between -50 and 50
    double tolerance = 0.0001;
    cout << fixed << setprecision(6);
    cout << "Random interval generated:\n";
    cout << "a = " << a << "   b = " << b << "\n";

    BisectionMethod bisector(a, b, tolerance);

    // Only call Iteration if interval is valid
    if (bisector.ValueCalculate(a) * bisector.ValueCalculate(b) < 0)
        bisector.Iteration();
    else
        cout << "No sign change found in interval. Bisection not possible.\n";

    return 0;
}
