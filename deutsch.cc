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
  // The top qubit is always |0>
  vector<vector<complex<double>>> topQubitMatrix(algo.getQubitMatrix(0));
  // The bottom qubit is always |1>
  vector<vector<complex<double>>> bttmQubitMatrix(algo.getQubitMatrix(1));


// Get the tensor product of the qubits -- (|0> xor |1>)
  vector<vector<complex<double>>> qubitTensor(algo.getTensorProduct(topQubitMatrix, bttmQubitMatrix));

// Get the tensor product of the 2 hadamards -- (H xor H)
    vector<vector<complex<double>>> hadamardTensor(algo.getTensorProduct(algo.getHadamard(), algo.getHadamard()));

// Get the product of the hadamards and qubits -- ((H xor H) (|0> xor |1>))
vector<vector<complex<double>>> qubitAndHadamardProduct(algo.getMatrixMultiplication(hadamardTensor, qubitTensor));

// Post UF Calc -- ((Uf) (H xor H) (|0> xor |1>))
vector<vector<complex<double>>> postUFCalc(algo.getMatrixMultiplication(algo.getUFMatrix(func0, func1), qubitAndHadamardProduct));

// Calculate hadamard tensor identity -- (H xor I)
vector<vector<complex<double>>> hadamardIdentityMatrix(algo.getTensorProduct(algo.getHadamard(), algo.getIdentityMatrix(2)));

// Calculate final solution -- (H xor I) (Uf) (H xor H) (|0> xor |1>)
vector<vector<complex<double>>> completedMatrix(algo.getMatrixMultiplication(hadamardIdentityMatrix, postUFCalc));


// Display result
  for (size_t i = 0; i < completedMatrix.size(); ++i) {
    for (size_t j = 0; j < completedMatrix[0].size(); ++j) {
      cout << utils.printComplexNumber(completedMatrix[i][j]);
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