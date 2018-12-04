// Program illustrating the use of real() and
// imag() function
#include <iomanip>
#include <string>
#include "Algorithms.h"
#include "Utils.h"
using namespace std;

Algorithms algo;
Utils utils;

void calculateCNOT(int topQubit, int bottomQubit) {
  vector<vector<complex<double>>> matrixOne(algo.getQubitMatrix(topQubit));

  for (size_t i = 0; i < matrixOne.size(); ++i) {
    for (size_t j = 0; j < matrixOne[0].size(); ++j) {
      cout << utils.printComplexNumber(matrixOne[i][j]);
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