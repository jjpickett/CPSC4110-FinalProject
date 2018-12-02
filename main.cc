// Program illustrating the use of real() and
// imag() function
#include <iomanip>
#include <string>
#include "Algorithms.h"
#include "Utils.h"
using namespace std;

Algorithms algo;
Utils utils;

/** This is a test for Summing complex numbers
 */
void sumTest() {
  double rNum1, iNum1, rNum2, iNum2;
  cout << "Please input first complex number as 10 2 (10+2i) " << endl;
  cin >> rNum1 >> iNum1;
  cout << "Please input second complex number as 10 2 (10+2i) " << endl;
  cin >> rNum2 >> iNum2;

  complex<double> cNum1(rNum1, iNum1);
  complex<double> cNum2(rNum2, iNum2);

  complex<double> cNumAns;

  cNumAns = algo.getSum(cNum1, cNum2);

  cout << "The sum of the complex numbers is: " << real(cNumAns) << " + ("
       << imag(cNumAns) << "i)" << endl;
}

/** This is a test for Multiplying complex numbers
 */
void productTest() {
  double rNum1, iNum1, rNum2, iNum2;
  cout << "Please input first complex number as 10 2 (10+2i) " << endl;
  cin >> rNum1 >> iNum1;
  cout << "Please input second complex number as 10 2 (10+2i) " << endl;
  cin >> rNum2 >> iNum2;

  complex<double> cNum1(rNum1, iNum1);
  complex<double> cNum2(rNum2, iNum2);

  complex<double> cNumAns;

  cNumAns = algo.getProduct(cNum1, cNum2);

  cout << "The product of the complex numbers is: " << real(cNumAns) << " + ("
       << imag(cNumAns) << "i)" << endl;
}

/** This is a test for getting the Modulo of a complex number
 */
void modTest() {
  double rNum, iNum;

  cout << "Please input the complex number as 10 2 (10+2i) " << endl;
  cin >> rNum >> iNum;

  complex<double> cNum(rNum, iNum);

  complex<double> result = algo.getMod(cNum);

  cout << "The Modulo of the complex numbers is: " << real(result) << " + ("
       << imag(result) << "i)" << endl;
}

/** This is a test for getting the Conjugate of a complex number
 */
void conjTest() {
  double rNum, iNum;
  cout << "Please input first complex number as 10 2 (10+2i) " << endl;
  cin >> rNum >> iNum;

  complex<double> cNum(rNum, iNum);

  complex<double> cNumAns;

  cNumAns = algo.getConj(cNum);

  cout << "The conjugate of the complex numbers is: " << real(cNumAns) << " + ("
       << imag(cNumAns) << "i)" << endl;
}

/** This is a test for getting the Dot Product of a complex vectors
 */
void vectorDotProductTest() {
  vector<complex<double>> vectorOne;
  vector<complex<double>> vectorTwo;

  int size;
  double rNum, iNum;

  cout << "Enter the dimension of the vectors: ";
  cin >> size;

  // Storing elements of first vector entered by user.
  for (int i = 0; i < size; ++i) {
    cout << "Enter element " << i + 1 << " for vector one as 10 2 (10+2i): ";
    cin >> rNum >> iNum;
    complex<double> cNum(rNum, iNum);
    vectorOne.push_back(cNum);
  }

  // Storing elements of second vector entered by user.
  for (int i = 0; i < size; ++i) {
    cout << "Enter element " << i + 1 << " for vector two as 10 2 (10+2i): ";
    cin >> rNum >> iNum;
    complex<double> cNum(rNum, iNum);
    vectorTwo.push_back(cNum);
  }

  complex<double> cNumAns;

  cNumAns = algo.getDotProductVector(vectorOne, vectorTwo);

  cout << "The dot-product of the two vectors is: " << real(cNumAns) << " + "
       << imag(cNumAns) << "i" << endl;
}

/** This is a test for getting the Matrix Addition of complex matrices
 */
void matrixAdditionTest() {
  int rows, columns;
  double rNum, iNum;

  cout << "Enter number of rows: ";
  cin >> rows;

  cout << "Enter number of columns: ";
  cin >> columns;

  vector<vector<complex<double>>> matrixOne(rows);
  vector<vector<complex<double>>> matrixTwo(rows);

  cout << endl << "Enter values for the first matrix: " << endl;

  // Storing elements of first matrix entered by user.
  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < columns; ++j) {
      cout << "Enter firstMatrix[" << i + 1 << "][" << j + 1
           << "] as 10 2 (10+2i): ";
      cin >> rNum >> iNum;
      complex<double> cNum(rNum, iNum);
      matrixOne[i].push_back(cNum);
    }
  }

  // Storing elements of second matrix entered by user.
  cout << endl << "Enter elements of 2nd matrix: " << endl;
  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < columns; ++j) {
      cout << "Enter secondMatrix[" << i + 1 << "][" << j + 1
           << "] as 10 2 (10+2i): ";
      cin >> rNum >> iNum;
      complex<double> cNum(rNum, iNum);
      matrixTwo[i].push_back(cNum);
    }
  }
  cout << endl;

  vector<vector<complex<double>>> resultMatrix;

  resultMatrix = algo.getMatrixAddition(matrixOne, matrixTwo);

  cout << "Resulting Matrix:" << endl;

  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < columns; ++j) {
      cout << utils.printComplexNumber(resultMatrix[i][j]);
    }
    cout << endl;
  }
}

/** This is a test for getting the Sum of a complex vector
 */
void complexVectorSumTest() {
  Algorithms algo;

  double rNum, iNum;
  int vectorSize;
  vector<complex<double>> complexVector;

  cout << "Please input the size of your complex vector" << endl;
  cin >> vectorSize;

  for (int i = 0; i < vectorSize; i++) {
    cout << "Please input a complex number as 10 2 (10+2i) " << endl;
    cin >> rNum >> iNum;
    complex<double> temp(rNum, iNum);
    complexVector.push_back(temp);
  }

  complex<double> cNumAns;

  cNumAns = algo.getComplexVectorAddition(complexVector);

  cout << "The sum of the complex numbers is: " << real(cNumAns) << " + ("
       << imag(cNumAns) << "i)" << endl;
}

void matrixMultiplicationTest() {
  int matrixOneRows, matrixOneColumns, matrixTwoRows, matrixTwoColumns;
  double rNum, iNum;

  cout << "Enter number of rows for Matrix One: ";
  cin >> matrixOneRows;

  cout << "Enter number of columns for Matrix One: ";
  cin >> matrixOneColumns;

  cout << "Enter number of rows for Matrix Two: ";
  cin >> matrixTwoRows;

  cout << "Enter number of columns for Matrix Two: ";
  cin >> matrixTwoColumns;

  vector<vector<complex<double>>> matrixOne(matrixOneRows);
  vector<vector<complex<double>>> matrixTwo(matrixTwoRows);

  cout << endl << "Enter values for the first matrix: " << endl;

  // Storing elements of first matrix entered by user.
  for (int i = 0; i < matrixOneRows; ++i) {
    for (int j = 0; j < matrixOneColumns; ++j) {
      cout << "Enter value for Matrix One [" << i + 1 << "][" << j + 1
           << "] as 10 2 (10+2i): ";
      cin >> rNum >> iNum;
      complex<double> cNum(rNum, iNum);
      matrixOne[i].push_back(cNum);
    }
  }

  // Storing elements of second matrix entered by user.
  cout << endl << "Enter value for Matrix Two: " << endl;
  for (int i = 0; i < matrixTwoRows; ++i) {
    for (int j = 0; j < matrixTwoColumns; ++j) {
      cout << "Enter secondMatrix[" << i + 1 << "][" << j + 1
           << "] as 10 2 (10+2i): ";
      cin >> rNum >> iNum;
      complex<double> cNum(rNum, iNum);
      matrixTwo[i].push_back(cNum);
    }
  }
  cout << endl;

  vector<vector<complex<double>>> resultMatrix;

  resultMatrix = algo.getMatrixMultiplication(matrixOne, matrixTwo);

  cout << "Resulting Matrix:" << endl;

  for (size_t i = 0; i < resultMatrix.size(); ++i) {
    for (size_t j = 0; j < resultMatrix[0].size(); ++j) {
      cout << utils.printComplexNumber(resultMatrix[i][j]);
    }
    cout << endl;
  }
}

void tensorProductTest() {
  int matrixOneRows, matrixOneColumns, matrixTwoRows, matrixTwoColumns;
  double rNum, iNum;

  cout << "Enter number of rows for Matrix One: ";
  cin >> matrixOneRows;

  cout << "Enter number of columns for Matrix One: ";
  cin >> matrixOneColumns;

  cout << "Enter number of rows for Matrix Two: ";
  cin >> matrixTwoRows;

  cout << "Enter number of columns for Matrix Two: ";
  cin >> matrixTwoColumns;

  vector<vector<complex<double>>> matrixOne(matrixOneRows);
  vector<vector<complex<double>>> matrixTwo(matrixTwoRows);

  cout << endl << "Enter values for the first matrix: " << endl;

  // Storing elements of first matrix entered by user.
  for (int i = 0; i < matrixOneRows; ++i) {
    for (int j = 0; j < matrixOneColumns; ++j) {
      cout << "Enter value for Matrix One [" << i + 1 << "][" << j + 1
           << "] as 10 2 (10+2i): ";
      cin >> rNum >> iNum;
      complex<double> cNum(rNum, iNum);
      matrixOne[i].push_back(cNum);
    }
  }

  // Storing elements of second matrix entered by user.
  cout << endl << "Enter value for Matrix Two: " << endl;
  for (int i = 0; i < matrixTwoRows; ++i) {
    for (int j = 0; j < matrixTwoColumns; ++j) {
      cout << "Enter secondMatrix[" << i + 1 << "][" << j + 1
           << "] as 10 2 (10+2i): ";
      cin >> rNum >> iNum;
      complex<double> cNum(rNum, iNum);
      matrixTwo[i].push_back(cNum);
    }
  }
  cout << endl;

  vector<vector<complex<double>>> resultMatrix;

  resultMatrix = algo.getTensorProduct(matrixOne, matrixTwo);

  cout << "Resulting Matrix:" << endl;

  for (size_t i = 0; i < resultMatrix.size(); ++i) {
    for (size_t j = 0; j < resultMatrix[0].size(); ++j) {
      cout << utils.printComplexNumber(resultMatrix[i][j]);
    }
    cout << endl;
  }
}

// driver function
int main() {
  // ***** Uncomment the function to test capability
  try {
    // cout << "Sum Test" << endl;
    // sumTest();

    // cout << "Product Test" << endl;
    // productTest();

    // cout << "Mod Test" << endl;
    // modTest();

    // cout << "Conj Test" << endl;
    // conjTest();

    // cout << "Complex Vector Sum Test" << endl;
    // complexVectorSumTest();

    // cout << "Vector Dot-Product Test" << endl;
    // vectorDotProductTest();

    // cout << "Matrix Addition Test" << endl;
    // matrixAdditionTest();

    // cout << "Matrix Multiplication Test" << endl;
    // matrixMultiplicationTest();

    // cout << "Tensor Product Test" << endl;
    // tensorProductTest();

    // cout << "Is Hermitian Test" << endl;
    // isHermitianTest();
  } catch (runtime_error e) {
    cout << e.what() << endl;
  }

  return 0;
}