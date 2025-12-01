#include<bits/stdc++.h>
using namespace std;
class NewtonsForward{
private:
  double x[100], y[100], diffTable[100][100];
  int n;
public:
  //Constructor
  NewtonsForward(int n){
    this->n = n;
  }
  
  //Take input Values
  void inputValues(){
    cout << "Enter x values: \n";
    for(int i = 0; i < n; i++) cin >> x[i];
    cout << "Enter y values: \n";
    for(int i = 0; i < n; i++) cin >> y[i];
  }
  
  //Calculate Difference Table
  void computeDifferenceTable(){
    //Step 1
    for(int i = 0; i < n; i++){
      diffTable[i][0] = y[i];
    }
    
    //step 2 
    for(int j = 1; j < n; j++){
      for(int i = 0; i < n - j; i++){
        diffTable[i][j] = diffTable[i + 1][j - 1] - diffTable[i][j - 1];
      }
    }
  }
  
  //Compute the interpolate at y(x_val)
  double computeInterpolate(double x_value){
    double result = diffTable[0][0];
    double h = x[1] - x[0];
    double p = (x_value - x[0]) / h;
    
    double term = 1;
    for(int i = 1; i < n; i++){
      term *= (p - (i - 1)) / i;
      result += term * diffTable[0][i];
    }
    return result;
  }
  
  //Printing the result 
  void printDifferenceTable(){
    cout << "\nNewtons Forward Difference Table is: \n";
    for(int i = 0; i < n; i++){
      for(int j = 0; j < n - i; j++){
        cout << diffTable[i][j] << '\t';
      }
      cout << '\n';
    }
  }
};

int main() {
  int n;
  cout << "Enter the number of data points: ";
  cin >> n;  
  
  NewtonsForward newton(n);
  newton.inputValues();
  newton.computeDifferenceTable();
  newton.printDifferenceTable();
  
  double x_value;
  cout << "Enter the x value: \n";
  cin >> x_value;
  
  cout << "Interpolated value at x = " << x_value << " is "
  << newton.computeInterpolate(x_value) << '\n';
	return 0;
}

//Input
// 4
// 0 1 2 3
// 1 0 1 10
// .5

// output
// Interpolated value at x = 0.5 is 0.625