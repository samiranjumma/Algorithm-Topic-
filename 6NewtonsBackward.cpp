#include <bits/stdc++.h>
using namespace std;

class NewtonBackwardInterpolation
{
private:
    double x[100], y[100], diffTable[100][100];
    int n;

public:
    NewtonBackwardInterpolation(double x[], double y[], int n)
    {
        this->n = n;
        for (int i = 0; i < n; i++)
        {
            this->x[i] = x[i];
            this->y[i] = y[i];
        }
        computeDifferenceTable();
    }

    // Compute backward difference table
    void computeDifferenceTable()
    {
        for (int i = 0; i < n; i++)
        {    
            diffTable[i][0] = y[i];
        }

        for (int j = 1; j < n; j++)
        {
            for (int i = n - 1; i >= j; i--)
            {
                diffTable[i][j] = diffTable[i][j - 1] - diffTable[i - 1][j - 1];
            }
        }
    }

    // Interpolation using backward formula
    double interpolate(double x_val)
    {
        double result = diffTable[n - 1][0];
        double term = 1;
        double h = x[1] - x[0];
        double p = (x_val - x[n - 1]) / h;

        for (int i = 1; i < n; i++)
        {
            term *= (p + (i - 1)) / i;
            result += term * diffTable[n - 1][i];
        }
        return result;
    }

    void printDifftable()
    {
        cout << "Newton's Backward Difference Table:" << endl;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j <= i; j++)
            {
                cout << diffTable[i][j] << "\t";
            }
            cout << endl;
        }
    }
};

int main()
{
    double x[] = {1, 2, 3, 4, 5};
    double y[] = {2.2, 2.8, 3.6, 4.5, 5.1};
    int n = 5;

    NewtonBackwardInterpolation newtonback(x, y, n);

    newtonback.printDifftable();

    double x_val = 4.5;
    cout << "Interpolated value at x = " << x_val << " = "
         << newtonback.interpolate(x_val) << endl;

    return 0;
}
