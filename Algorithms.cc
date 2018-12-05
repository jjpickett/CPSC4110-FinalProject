#include "Algorithms.h"

Algorithms::Algorithms() {}

/* Algorithm for calculating the sum of two complex numbers
 */
complex<double> Algorithms::getSum(complex<double> myComplex1,
                                   complex<double> myComplex2) {
  // Instantiate the Real Number and the Imaginary Number
  double rNum, iNum;
  // Add the Real numbers of the two complex numbers together
  rNum = real(myComplex1) + real(myComplex2);

  // Add the Imaginary numbers of the two complex numbers together
  iNum = imag(myComplex1) + imag(myComplex2);

  // Apply the calculated Real and Imaginary numbers to result variable
  complex<double> result(rNum, iNum);

  // Return the result variable
  return result;
}

/* Algorithm for calculating the product of two complex numbers
 */
complex<double> Algorithms::getProduct(complex<double> myComplex1,
                                       complex<double> myComplex2) {
  // Instantiate the Real Number and the Imaginary Number
  double rNum, iNum;

  // Get the product of the real numbers
  rNum = real(myComplex1) * real(myComplex2);

  // Add the products of the real and imaginary numbers
  iNum = (real(myComplex1) * imag(myComplex2)) +
         (imag(myComplex1) * real(myComplex2));

  // Multiply the imaginary numbers together. Since we always get i^2, we must
  // multiply this by -1 We will then add this number to the current real number
  rNum = rNum + ((imag(myComplex1) * imag(myComplex2)) * (-1));

  // Apply the calculated Real and Imaginary numbers to result variable
  complex<double> result(rNum, iNum);

  // Return the result variable
  return result;
}

/* Algorithm for return the modulus of a complex number
 */
complex<double> Algorithms::getMod(complex<double> myComplex) {
  // return the absolute of a complex number (same as modulus)
  complex<double> result(real(myComplex), imag(myComplex) * -1);
  return result;
}

/* Algorithm for return the conjugate of a complex number
 */
complex<double> Algorithms::getConj(complex<double> myComplex) {
  // return the absolute of a complex number (same as modulus)
  return conj(myComplex);
}

/* Algorithm that calculates the result of complex vector addition
 */
complex<double> Algorithms::getComplexVectorAddition(
    vector<complex<double>> complexVector) {
  // Instantiate the Real Number and the Imaginary Number
  double rNum = 0, iNum = 0;

  // Loop through the vector and add the real numbers together and the imaginary
  // numbers together
  for (size_t i = 0; i < complexVector.size(); i++) {
    rNum += real(complexVector[i]);
    iNum += imag(complexVector[i]);
  }

  // Apply the calculated Real and Imaginary numbers to result variable
  complex<double> result(rNum, iNum);

  // Return Result
  return result;
}

/* Algorithm that calculates the dot-product of two n-dimension complex vectors
 */
complex<double> Algorithms::getDotProductVector(
    vector<complex<double>> vectorOne, vector<complex<double>> vectorTwo) {
  // Instantiate the result of the dot product
  complex<double> result = 0;

  // Ensure vectors are the same size
  if (vectorOne.size() == vectorTwo.size()) {
    // Calculate the dot-product of the two vectors
    for (size_t i = 0; i < vectorOne.size(); i++) {
      result = getSum(result, getProduct(vectorOne.at(i), vectorTwo.at(i)));
    }
    return result;
  } else {
    throw runtime_error(
        "Error: Vectors must have the same dimensions in order to perform dot "
        "product");
  }
}

/* Algorithm that calculates the result of matrix addition
 */
vector<vector<complex<double>>> Algorithms::getMatrixAddition(
    vector<vector<complex<double>>> matrixOne,
    vector<vector<complex<double>>> matrixTwo) {
  // Get the size of the matrices to add
  size_t columns = matrixOne[0].size(), rows = matrixOne.size();

  // Matrix to store the result of the additon in
  vector<vector<complex<double>>> resultMatrix(rows);

  // Check to ensure matrices are the same size
  if (columns == matrixTwo[0].size() && rows == matrixTwo.size()) {
    // Adding Two matrices
    for (size_t i = 0; i < rows; ++i) {
      for (size_t j = 0; j < columns; ++j) {
        resultMatrix[i].push_back(getSum(matrixOne[i][j], matrixTwo[i][j]));
      }
    }
    return resultMatrix;
  } else {
    throw runtime_error(
        "Error: Matrices must have the same dimensions in order add");
  }
}

/* Algorithm that calculates the result of matrix multiplication
 */
vector<vector<complex<double>>> Algorithms::getMatrixMultiplication(
    vector<vector<complex<double>>> matrixOne,
    vector<vector<complex<double>>> matrixTwo) {
  // Get the size of the matrices to multiply
  size_t matrixOneRows = matrixOne.size(),
         matrixOneColumns = matrixOne[0].size(),
         matrixTwoRows = matrixTwo.size(),
         matrixTwoColumns = matrixTwo[0].size();

  // Matrix to store the result of the multiplication in
  vector<vector<complex<double>>> resultMatrix(matrixOneRows);

  // Check to ensure matrices are able to be multiplied
  if (matrixOneColumns == matrixTwoRows) {
    // Multiplying two matrices
    for (size_t i = 0; i < matrixOneRows; ++i) {
      for (size_t j = 0; j < matrixTwoColumns; ++j) {
        complex<double> sum;
        for (size_t k = 0; k < matrixOneColumns; ++k) {
          sum = getSum(sum, getProduct(matrixOne[i][k], matrixTwo[k][j]));
        }
        resultMatrix[i].push_back(sum);
      }
    }
    return resultMatrix;
  } else {
    throw runtime_error(
        "Error: # of columns in Matrix One must equal # of rows in Matrix Two");
  }
}

/* Algorithm that calculates the tensor product of two matrices
 */
vector<vector<complex<double>>> Algorithms::getTensorProduct(
    vector<vector<complex<double>>> matrixOne,
    vector<vector<complex<double>>> matrixTwo) {
  // Get the size of the matrices to multiply
  size_t matrixOneRows = matrixOne.size(),
         matrixOneColumns = matrixOne[0].size(),
         matrixTwoRows = matrixTwo.size(),
         matrixTwoColumns = matrixTwo[0].size();

  // Matrix to store the result of the multiplication in
  vector<vector<complex<double>>> resultMatrix(matrixOneRows * matrixTwoRows);

  // Keeps track of which row to insert the products in the result matrix
  size_t rowNumber = 0;

  // Loop through the first matrix
  for (size_t i = 0; i < matrixOneRows; ++i) {
    for (size_t j = 0; j < matrixOneColumns; ++j) {
      // Loop through the second matrix and multiply each element by the element
      // in matrix one
      for (size_t i2 = 0; i2 < matrixTwoRows; ++i2) {
        for (size_t j2 = 0; j2 < matrixTwoColumns; ++j2) {
          resultMatrix[rowNumber + i2].push_back(
              getProduct(matrixOne[i][j], matrixTwo[i2][j2]));
        }
      }
    }
    // Increment the row number
    rowNumber += matrixTwoRows;
  }
  return resultMatrix;
}

/* Algorithm returns True if matrix is Hermitian. False if it is not Hermitian.
 */
bool Algorithms::isHermitian(vector<vector<complex<double>>> matrix) {
  // Get the size of the matrices to multiply
  size_t matrixRows = matrix.size(), matrixColumns = matrix[0].size();

  // Sets is Hermitian to true
  bool isHermitian = true;

  // Check to ensure matrices are able to be multiplied
  if (matrixRows == matrixColumns) {
    for (size_t i = 0; i < matrixRows; ++i) {
      for (size_t j = 0; j < matrixColumns; ++j) {
        // If the adjoint matrix does not equal the original, then the matrix is
        // not hermitian
        if (matrix[i][j] != getMod(matrix[j][i])) {
          isHermitian = false;
        }
      }
    }
  } else {
    throw runtime_error(
        "Error - Hermitian Check: # of columns and rows must be the same to "
        "check for Hermitian");
  }

  return isHermitian;
}

/* X Pauli Matrice
 */
vector<vector<complex<double>>> Algorithms::getPauliMatriceX() {
  vector<vector<complex<double>>> outerMatrix;
  vector<complex<double>> innerMatrix;

  complex<double> temp(real(0), imag(0));
  innerMatrix.push_back(temp);

  temp.real(1);
  temp.imag(0);

  innerMatrix.push_back(temp);

  outerMatrix.push_back(innerMatrix);
  innerMatrix.clear();

  innerMatrix.push_back(temp);

  temp.real(0);
  temp.imag(0);
  innerMatrix.push_back(temp);

  outerMatrix.push_back(innerMatrix);

  return outerMatrix;
}

/* Y Pauli Matrice
 */
vector<vector<complex<double>>> Algorithms::getPauliMatriceY() {
  vector<vector<complex<double>>> outerMatrix;
  vector<complex<double>> innerMatrix;

  complex<double> temp(real(0), imag(0));
  innerMatrix.push_back(temp);

  temp.real(0);
  temp.imag(-1);

  innerMatrix.push_back(temp);

  outerMatrix.push_back(innerMatrix);

  innerMatrix.clear();

  temp.imag(1);
  innerMatrix.push_back(temp);

  temp.real(0);
  temp.imag(0);
  innerMatrix.push_back(temp);

  outerMatrix.push_back(innerMatrix);

  return outerMatrix;
}

/* Z Pauli Matrice
 */
vector<vector<complex<double>>> Algorithms::getPauliMatriceZ() {
  vector<vector<complex<double>>> outerMatrix;
  vector<complex<double>> innerMatrix;

  complex<double> temp(real(1), imag(0));
  innerMatrix.push_back(temp);

  temp.real(0);
  temp.imag(0);

  innerMatrix.push_back(temp);

  outerMatrix.push_back(innerMatrix);

  innerMatrix.clear();

  innerMatrix.push_back(temp);

  temp.real(-1);
  temp.imag(0);
  innerMatrix.push_back(temp);

  outerMatrix.push_back(innerMatrix);

  return outerMatrix;
}

/* Hadamard Matrix
 */
vector<vector<complex<double>>> Algorithms::getHadamard() {
  vector<vector<complex<double>>> outerMatrix;
  vector<complex<double>> innerMatrix;

  complex<double> temp(real(1 / sqrt(2)), imag(0));
  innerMatrix.push_back(temp);
  innerMatrix.push_back(temp);

  outerMatrix.push_back(innerMatrix);

  innerMatrix.clear();

  innerMatrix.push_back(temp);

  temp.real(-1 / sqrt(2));
  innerMatrix.push_back(temp);

  outerMatrix.push_back(innerMatrix);

  return outerMatrix;
}

/* Get Qubit Matrix
 */
vector<vector<complex<double>>> Algorithms::getQubitMatrix(int qubit) {
  vector<vector<complex<double>>> outerMatrix;
  vector<complex<double>> innerMatrix;
  complex<double> temp(real(0), imag(0));

  if (qubit) {
    // Top
    temp.real(0);
    innerMatrix.push_back(temp);
    outerMatrix.push_back(innerMatrix);

    innerMatrix.clear();

    // Bottom
    temp.real(1);
    innerMatrix.push_back(temp);
    outerMatrix.push_back(innerMatrix);

  } else {
    // Top
    temp.real(1);
    innerMatrix.push_back(temp);
    outerMatrix.push_back(innerMatrix);

    innerMatrix.clear();

    // Bottom
    temp.real(0);
    innerMatrix.push_back(temp);
    outerMatrix.push_back(innerMatrix);
  }

  return outerMatrix;
}

/* Get CNOT Matrix
 */
vector<vector<complex<double>>> Algorithms::getCNOT() {
  vector<vector<complex<double>>> outerMatrix;
  vector<complex<double>> innerMatrix;

  complex<double> temp(real(1), imag(0));
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      if ((i == 0 && j == 0) || (i == 1 && j == 1) || (i == 2 && j == 3) ||
          (i == 3 && j == 2)) {
        temp.real(1);
      } else {
        temp.real(0);
      }

      innerMatrix.push_back(temp);
    }
    outerMatrix.push_back(innerMatrix);
    innerMatrix.clear();
  }

  return outerMatrix;
}

/* Get Toffoli Matrix
 */
vector<vector<complex<double>>> Algorithms::getToffoli() {
  vector<vector<complex<double>>> outerMatrix;
  vector<complex<double>> innerMatrix;

  complex<double> temp(real(1), imag(0));
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      if (((i == j) && (i < 6)) || ((i == 6 && j == 7) || (i == 7 && j == 6))) {
        temp.real(1);
      } else {
        temp.real(0);
      }

      innerMatrix.push_back(temp);
    }
    outerMatrix.push_back(innerMatrix);
    innerMatrix.clear();
  }

  return outerMatrix;
}

/* Generate Uf Matrix
 */
vector<vector<complex<double>>> Algorithms::getUFMatrix(int func0, int func1) {
  vector<vector<complex<double>>> outerMatrix;
  vector<complex<double>> innerMatrix;

  complex<double> temp(real(0), imag(0));
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      // If f(x) is a constant 0
      if ((func0 == 0) && (func1 == 0)) {
        if (i == j) {
          temp.real(1);
        } else {
          temp.real(0);
        }

      } else if ((func0 == 0) && (func1 == 1)) {
        if (((i == j) && i < 2) || (i == 2 && j == 3) || (i == 3 && j == 2)) {
          temp.real(1);
        } else {
          temp.real(0);
        }
      } else if ((func0 == 1) && (func1 == 0)) {
        if ((i == 0 && j == 1) || (i == 1 && j == 0) || ((i == j) && i > 1)) {
          temp.real(1);
        } else {
          temp.real(0);
        }
      } else {
        if ((i == 0 && j == 1) || (i == 1 && j == 0) || (i == 2 && j == 3) ||
            (i == 3 && j == 2)) {
          temp.real(1);
        } else {
          temp.real(0);
        }
      }

      innerMatrix.push_back(temp);
    }
    outerMatrix.push_back(innerMatrix);
    innerMatrix.clear();
  }

  return outerMatrix;
}

/* Get Identity Matrix
 */
vector<vector<complex<double>>> Algorithms::getIdentityMatrix(int size) {
  vector<vector<complex<double>>> outerMatrix;
  vector<complex<double>> innerMatrix;

  complex<double> temp(real(1), imag(0));
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      if ((i == j)) {
        temp.real(1);
      } else {
        temp.real(0);
      }

      innerMatrix.push_back(temp);
    }
    outerMatrix.push_back(innerMatrix);
    innerMatrix.clear();
  }

  return outerMatrix;
}
