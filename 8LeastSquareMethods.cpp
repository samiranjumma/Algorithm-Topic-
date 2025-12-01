#include <bits/stdc++.h>
using namespace std;
class LeastSquareMethod{
  private:
    double x[100], y[100];
    int n;
    double a, b;
  public:
  
    //Constructor
    LeastSquareMethod(int size){
      this->n = size;
      this->a = 0;
      this->b = 0;
    }
    //Input x and y 
    void inputValues(){
      cout << "\nEnter x values: ";
      for(int i = 0; i < n; i++) cin >> x[i];
      cout << "\nEnter y values: ";
      for(int i = 0; i < n; i++) cin >> y[i];
    }
    
    //Perform Least Square Fitting
    void fitline(){
      double sumX = 0, sumY = 0, sumXY = 0, sumX2 = 0;
      for(int i = 0; i < n; i++){
        sumX += x[i];
        sumY += y[i];
        sumXY += x[i] * y[i];
        sumX2 += x[i] * x[i];
      }
      b = (n * sumXY - sumY * sumX) / (n * sumX2 - sumX * sumX);
      a = (sumY - b * sumX) / n;
      cout << "\nThe value of a is " << a << '\n';
      cout << "The value of b is " << b << '\n';
    }
    
    //Print final equation
    void printEquation(){
      cout << "\nThe fitted line is:\n";
      cout << " y = " << a << " + " << b << " x\n";
    }
};
int main() 
{
  int n;
  cout << "Enter number of data points: ";
  cin >> n;
  LeastSquareMethod ls(n);
  ls.inputValues();
  ls.fitline();
  ls.printEquation();
}

// 5
// 1 2 3 4 5
// 0.6 2.4  3.5 4.8 5.7

// The value of a is -0.38
// The value of b is 1.26

// The fitted line is:
//  y = -0.38 + 1.26 x