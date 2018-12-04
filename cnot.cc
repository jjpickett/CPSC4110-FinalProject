// Program illustrating the use of real() and
// imag() function
#include <iomanip>
#include <string>
#include "Algorithms.h"
#include "Utils.h"
using namespace std;

Algorithms algo;
Utils utils;

void calculateCNOT(int topQubit, int bttmQubit) {
    // Get the qubits as matrices
  vector<vector<complex<double>>> topQubitMatrix(algo.getQubitMatrix(topQubit));
  vector<vector<complex<double>>> bttmQubitMatrix(algo.getQubitMatrix(bttmQubit));

  vector<vector<complex<double>>> qubitTensorProduct(algo.getTensorProduct(topQubitMatrix, bttmQubitMatrix));
  
  vector<vector<complex<double>>> matrixResult(algo.getMatrixMultiplication(algo.getCNOT(), qubitTensorProduct));

  for (size_t i = 0; i < matrixResult.size(); ++i) {
    for (size_t j = 0; j < matrixResult[0].size(); ++j) {
      cout << utils.printComplexNumber(matrixResult[i][j]);
    }
    cout << endl;
  }
}

int main() {
  int topQubit = 0, bottomQubit = 0;
  cout << "CNOT Program" << endl;
  cout << "Please enter your top Qubit." << endl;
  cin >> topQubit;
  cout << "Please enter your bottom Qubit." << endl;
  cin >> bottomQubit;

  calculateCNOT(topQubit, bottomQubit);

  return 0;
}