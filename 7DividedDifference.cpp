#include <bits/stdc++.h>
using namespace std;

class NewtonDividedDifference
{
private:
    double x[100], y[100], diffTable[100][100];
    int n;

public:
    NewtonDividedDifference(double x[], double y[], int n)
    {
        this->n = n;
        for (int i = 0; i < n; i++)
        {
            this->x[i] = x[i];
            this->y[i] = y[i];
        }
        computeDifferenceTable();
    }

    // Compute divided difference table
    void computeDifferenceTable()
    {
        for (int i = 0; i < n; i++)
        {
            diffTable[i][0] = y[i];
        }

        for (int j = 1; j < n; j++)
        {
            for (int i = 0; i < n - j; i++)
            {
                diffTable[i][j] = (diffTable[i + 1][j - 1] - diffTable[i][j - 1]) /
                                  (x[i + j] - x[i]);
            }
        }
    }

    // Newton divided difference interpolation
    double interpolate(double x_val)
    {
        double result = diffTable[0][0];
        double term = 1;

        for (int i = 1; i < n; i++)
        {
            term *= (x_val - x[i - 1]);
            result += term * diffTable[0][i];
        }

        return result;
    }

    void printDifftable()
    {
        cout << "Divided Difference Table:" << endl;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n - i; j++)
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

    NewtonDividedDifference newtonDD(x, y, n);

    newtonDD.printDifftable();

    double x_val = 2.5;
    cout << "Interpolated value at x = " << x_val << " = "
         << newtonDD.interpolate(x_val) << endl;

    return 0;
}
