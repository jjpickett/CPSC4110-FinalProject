// Program illustrating the use of real() and
// imag() function
#include <iomanip>
#include <string>
#include "Algorithms.h"
#include "Utils.h"
using namespace std;

Algorithms algo;
Utils utils;

void calculateToffoli(int controlQubit1, int controlQubit2, int affectedQubit) {
  // Get the qubits as matrices
  vector<vector<complex<double>>> cntrlQubitTopMatrix(
      algo.getQubitMatrix(controlQubit1));
  vector<vector<complex<double>>> cntrlQubitBttmMatrix(
      algo.getQubitMatrix(controlQubit2));
  vector<vector<complex<double>>> affectedQubitMatrix(
      algo.getQubitMatrix(affectedQubit));

  // Get the tensor product of the control bits
  vector<vector<complex<double>>> qubitFirstTensor(
      algo.getTensorProduct(cntrlQubitTopMatrix, cntrlQubitBttmMatrix));
   
    // Get the tensor product of the control bits and the affected bit
  vector<vector<complex<double>>> qubitSecondTensor(
      algo.getTensorProduct(qubitFirstTensor, affectedQubitMatrix));

// Have the matrix multiply against the Toffoli gate
  vector<vector<complex<double>>> matrixResult(
      algo.getMatrixMultiplication(algo.getToffoli(), qubitSecondTensor));

// Display result
  for (size_t i = 0; i < matrixResult.size(); ++i) {
    for (size_t j = 0; j < matrixResult[0].size(); ++j) {
      cout << utils.printComplexNumber(matrixResult[i][j]);
    }
    cout << endl;
  }
}

int main() {
  int topQubit = 0, middleQubit = 0, bottomQubit = 0, gatedQubit = 2;
  cout << "Toffoli Program" << endl;
  cout << "Please enter your top Qubit." << endl;
  cin >> topQubit;
  cout << "Please enter your middle Qubit." << endl;
  cin >> middleQubit;
  cout << "Please enter your bottom Qubit." << endl;
  cin >> bottomQubit;

  cout << "Which Qubit has the gate? 0 (Top), 1 (middle), 2 (Bottom)" << endl;
  cin >> gatedQubit;

  // 0 is the Top Qubit being affected
  if (gatedQubit == 0) {
    calculateToffoli(middleQubit, bottomQubit, topQubit);
  } else if (gatedQubit == 1) {
    calculateToffoli(topQubit, bottomQubit, middleQubit);
  } else {
    calculateToffoli(topQubit, middleQubit, bottomQubit);
  }

  // calculateToffoli(topQubit, bottomQubit, );

  return 0;
}