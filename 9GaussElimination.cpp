#include <bits/stdc++.h>
using namespace std;
class GaussElimination{
private:
  int n;
  vector<vector<double>> augmentedMatrix;
public:
  //Constructor
  GaussElimination(int n){
    this->n = n;
    augmentedMatrix.assign(n, vector<double>(n + 1));
  }
  
  //input matrix
  void inputMatrix(){
    cout << "Input the augmented Matrix: ";
    for(int i = 0; i < n; i++){
      for(int j = 0; j <= n; j++){
        cin >> augmentedMatrix[i][j];
      }
    }
  }
  
  //Print matrix
  void printMatrix(){
    cout << "Current Matrix: \n";
    for(int row = 0; row < n; row++){
      for(int col = 0; col <= n; col++){
        cout << augmentedMatrix[row][col] << ' ';
      }
      cout << '\n';
    }
    cout << "----------------------------------\n";
  }
  
  //Forward Elimination 
  void forwardElimination(){
    for(int i = 0; i < n; i++){
      
      //STEP-1: Find max pivot row
      int pivotRow = i;
      for(int row = i + 1; row < n; row++){
        if(abs(augmentedMatrix[row][i]) > abs(augmentedMatrix[pivotRow][i])){
          pivotRow = row;
        }
      }
      
      //STEP-2: swap current row with pivot row if needed
      if(pivotRow != i){
        swap(augmentedMatrix[i], augmentedMatrix[pivotRow]);
        
        cout << "Swapped row " << i + 1 << "with best pivot row " 
        << pivotRow + 1 << '\n';
        printMatrix();
      }
      
      //STEP-3: Eliminates values below pivot
      for(int row = i + 1; row < n; row++){
        
        double factor = augmentedMatrix[row][i] / augmentedMatrix[i][i];
        cout << "Eliminating row " << row + 1 << "using row " << i + 1 
        << " factor = "
        << factor << '\n';
        for(int c = i; c <= n; c++){
          augmentedMatrix[row][c] -= factor * augmentedMatrix[i][c];
        }
        printMatrix();
      }
    }
  }

  // Back Substitution
  vector<double>backSubstitution(){
    vector<double>x(n);
    
    for(int i = n - 1; i >= 0; i--){
      x[i] = augmentedMatrix[i][n];
      for(int j = i + 1; j < n; j++){
        x[i] -= augmentedMatrix[i][j] * x[j];
      }
      x[i] /= augmentedMatrix[i][i];
    }
    
    return x;
  }
  
  //Printing the result
  void solve(){
    inputMatrix();
    printMatrix();
    
    forwardElimination();
    
    vector<double>ans = backSubstitution();
    cout << "Final Result \n";
    for(int i = 0; i < n; i++){
      cout << "x" << i + 1 << " = " << ans[i] << '\n';
    }
  }
};

int main() 
{
  int n; cin >> n;
  GaussElimination gauss(n);
  gauss.solve();
}

// 3
// 2 1 4 12
// 4 11 -1 33
// 8 -3 2 20

// OUtput
// x = 3, y = 2, z = 1













// #include <bits/stdc++.h>
// using namespace std;

// class GaussianElemination {
// private:
//     int rows, cols;
//     vector<vector<double>> matrix;

// public:
//     // Constructor: initialize matrix size (n × m)
//     GaussianElemination(int n, int m): rows(n), cols(m) {
//         matrix.resize(rows, vector<double>(cols, 0.0));
//     }

//     // Input augmented matrix [A|b]
//     void inputMatrix() {
//         for(int i = 0; i < rows; i++) {
//             for(int j = 0; j < cols; j++) {
//                 cin >> matrix[i][j];
//             }
//         }
//     }

//     // Perform Gaussian Elimination (Forward Elimination)
//     void Elemination() {
//         for(int i = 0; i < rows; i++) {

//             // -------------------------------
//             // Step 1: Pivot selection (partial pivoting)
//             // Find row with the maximum absolute pivot in column i
//             // -------------------------------
//             int maxRow = i;
//             for(int j = i+1; j < rows; j++) {
//                 if(abs(matrix[j][i]) > abs(matrix[maxRow][i])) {
//                     maxRow = j;
//                 }
//             }

//             // Swap current row with max pivot row
//             swap(matrix[i], matrix[maxRow]);

//             // -------------------------------
//             // Step 2: Eliminate values below pivot
//             // Make all rows below current one have 0 in column i
//             // -------------------------------
//             for(int k = i+1; k < rows; k++) {
//                 double factor = matrix[k][i] / matrix[i][i];

//                 // Update row k: row_k = row_k – factor * row_i
//                 for(int j = i; j < cols; j++) {
//                     matrix[k][j] -= (factor * matrix[i][j]);
//                 }
//             }
//         }
//     }

//     // Back substitution to find final solutions
//     vector<double> backSubstitution() {
//         vector<double> solution(rows, 0.0);

//         // Solve from bottom row to top
//         for (int i = rows - 1; i >= 0; --i) {
//             // Start with the RHS value
//             solution[i] = matrix[i][cols - 1];

//             // Subtract known variables already solved
//             for (int j = i + 1; j < rows; ++j) {
//                 solution[i] -= matrix[i][j] * solution[j];
//             }

//             // Divide by coefficient of the variable
//             solution[i] /= matrix[i][i];
//         }
//         return solution;
//     }
// };

// int main() {
//     int n;
//     cin >> n;

//     // Create Gaussian Elimination object with augmented matrix size (n × n+1)
//     GaussianElemination gass(n, n+1);

//     // Input augmented matrix
//     gass.inputMatrix();

//     // Convert matrix to upper triangular form
//     gass.Elemination();

//     // Perform back substitution to get solution
//     vector<double> ans = gass.backSubstitution();

//     // Output final solution
//     for(auto u: ans) {
//         cout << u << "\n";
//     }
// }

// /*
// Input Example:
// 3
// 3 2 -4 3
// 2 3 3 15
// 5 -3 1 14

// Output:
// 3
// 1
// 2
// */

// // #include <bits/stdc++.h>
// // using namespace std;

// // // Print matrix (for debugging / learning)
// // void printMatrix(vector<vector<double>> &a) {
// //     cout << "\nCurrent Matrix:\n";
// //     for (auto &row : a) {
// //         for (auto &x : row) {
// //             cout << setw(10) << x << " ";
// //         }
// //         cout << "\n";
// //     }
// //     cout << "--------------------------------------\n";
// // }

// // int main() {
// //     int n = 3;  // For this specific equation
// //     vector<vector<double>> a = {
// //         {3, 2, -4, 3},
// //         {2, 3, 3, 15},
// //         {5, -3, 1, 14}
// //     };

// //     cout << "Initial Augmented Matrix:\n";
// //     printMatrix(a);

// //     // ------------------------------------------------------
// //     // Step 1: Forward Elimination (Gaussian Elimination)
// //     // ------------------------------------------------------
// //     for (int i = 0; i < n; i++) {

// //         // ====== Step A: Pivot Selection (Partial Pivoting) ======
// //         int pivotRow = i;
// //         for (int r = i + 1; r < n; r++) {
// //             if (fabs(a[r][i]) > fabs(a[pivotRow][i])) {
// //                 pivotRow = r;
// //             }
// //         }

// //         // swap if a better pivot is found
// //         if (pivotRow != i) {
// //             swap(a[i], a[pivotRow]);
// //             cout << "Swapped Row " << i+1 
// //                  << " with Row " << pivotRow+1 
// //                  << " (to choose best pivot).\n";
// //             printMatrix(a);
// //         }

// //         // ====== Step B: Eliminate below pivot ======
// //         for (int r = i + 1; r < n; r++) {
// //             double factor = a[r][i] / a[i][i];

// //             cout << "Eliminating Row " << r+1 
// //                  << " using Row " << i+1 
// //                  << " with factor = " << factor << "\n";

// //             for (int c = i; c <= n; c++) {
// //                 a[r][c] -= factor * a[i][c];
// //             }

// //             printMatrix(a);
// //         }
// //     }

// //     // ------------------------------------------------------
// //     // Step 2: Back Substitution
// //     // ------------------------------------------------------
// //     vector<double> x(n);

// //     for (int i = n - 1; i >= 0; i--) {
// //         x[i] = a[i][n]; // RHS
// //         for (int j = i + 1; j < n; j++) {
// //             x[i] -= a[i][j] * x[j];
// //         }
// //         x[i] /= a[i][i];
// //     }

// //     // ------------------------------------------------------
// //     // Step 3: Print Solution
// //     // ------------------------------------------------------
// //     cout << "\nFinal Solution:\n";
// //     for (int i = 0; i < n; i++) {
// //         cout << "x" << i+1 << " = " << x[i] << "\n";
// //     }

// //     return 0;
// // }
