#include <complex>
#include <iostream>
#include <vector>

using namespace std;

#ifndef ALGORITHMS_H
#define ALGORITHMS_H

class Algorithms {
 public:
  Algorithms();

  complex<double> getSum(complex<double> myComplex1,
                         complex<double> myComplex2);
  complex<double> getProduct(complex<double> myComplex1,
                             complex<double> myComplex2);
  complex<double> getMod(complex<double> myComplex);
  complex<double> getConj(complex<double> myComplex);
  complex<double> getComplexVectorAddition(
      vector<complex<double>> complexVector);
  complex<double> getDotProductVector(vector<complex<double>> vectorOne,
                                      vector<complex<double>> vectorTwo);
  vector<vector<complex<double>>> getMatrixAddition(
      vector<vector<complex<double>>> matrixOne,
      vector<vector<complex<double>>> matrixTwo);
  vector<vector<complex<double>>> getMatrixMultiplication(
      vector<vector<complex<double>>> matrixOne,
      vector<vector<complex<double>>> matrixTwo);
  vector<vector<complex<double>>> getTensorProduct(
      vector<vector<complex<double>>> matrixOne,
      vector<vector<complex<double>>> matrixTwo);
  bool isHermitian(vector<vector<complex<double>>> matrix);

  vector<vector<complex<double>>> getPauliMatriceX();
  vector<vector<complex<double>>> getPauliMatriceY();
  vector<vector<complex<double>>> getPauliMatriceZ();
  vector<vector<complex<double>>> getHadamard();
  vector<vector<complex<double>>> getQubitMatrix(int qubit);

  vector<vector<complex<double>>> getCNOT();
  vector<vector<complex<double>>> getToffoli();
  vector<vector<complex<double>>> getUFMatrix(int func0, int func1);
  vector<vector<complex<double>>> getIdentityMatrix(int size);

  virtual ~Algorithms(){};
};
#endif