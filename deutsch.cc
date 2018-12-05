// Program illustrating the use of real() and
// imag() function
#include <iomanip>
#include <string>
#include "Algorithms.h"
#include "Utils.h"
using namespace std;

Algorithms algo;
Utils utils;





void calculateDeutsch(int func0, int func1) {
    // Get the qubits as matrices
//   vector<vector<complex<double>>> topQubitMatrix(algo.getQubitMatrix(func0));
//   vector<vector<complex<double>>> bttmQubitMatrix(algo.getQubitMatrix(func1));

//   vector<vector<complex<double>>> qubitTensorProduct(algo.getMatrixMultiplication(topQubitMatrix, bttmQubitMatrix));
  
//   vector<vector<complex<double>>> matrixResult(algo.getMatrixMultiplication(algo.getCNOT(), qubitTensorProduct));

  vector<vector<complex<double>>> matrixResult(algo.getUFMatrix(func0, func1));

  for (size_t i = 0; i < matrixResult.size(); ++i) {
    for (size_t j = 0; j < matrixResult[0].size(); ++j) {
      cout << utils.printComplexNumber(matrixResult[i][j]);
    }
    cout << endl;
  }
}

int main() {
  int func0 = 0, func1 = 0;
  cout << "Deutsch Program" << endl;
  cout << "Please enter what f(0) = ";
  cin >> func0;
  cout << "Please enter what f(1) = ";
  cin >> func1;

  calculateDeutsch(func0, func1);

  return 0;
}