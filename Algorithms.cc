#include "Algorithms.h"

Algorithms::Algorithms(){
}

/* Algorithm for calculating the sum of two complex numbers
 */
complex<double> Algorithms::getSum(complex<double> myComplex1, complex<double> myComplex2){
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
complex<double> Algorithms::getProduct(complex<double> myComplex1, complex<double> myComplex2){
    // Instantiate the Real Number and the Imaginary Number
    double rNum, iNum;

    // Get the product of the real numbers
    rNum = real(myComplex1) * real(myComplex2);

    // Add the products of the real and imaginary numbers
    iNum = (real(myComplex1) * imag(myComplex2)) + (imag(myComplex1) * real(myComplex2));

    // Multiply the imaginary numbers together. Since we always get i^2, we must multiply this by -1
    // We will then add this number to the current real number
    rNum = rNum + ((imag(myComplex1) * imag(myComplex2)) * (-1));

    // Apply the calculated Real and Imaginary numbers to result variable
    complex<double> result(rNum, iNum);

    // Return the result variable
    return result;
}

/* Algorithm for return the modulus of a complex number
 */
double Algorithms::getMod(complex<double> myComplex){
    // return the absolute of a complex number (same as modulus)
    return abs(myComplex);
}

/* Algorithm for return the conjugate of a complex number
 */
complex<double> Algorithms::getConj(complex<double> myComplex){
    // return the absolute of a complex number (same as modulus)
    return conj(myComplex);
}

/* Algorithm that calculates the dot-product of two n-dimension complex vectors 
*/
complex<double> Algorithms::getDotProductVector(vector<complex<double>> vectorOne, vector<complex<double>> vectorTwo){
    // Instantiate the result of the dot product
    complex<double> result = 0; 

    // Ensure vectors are the same size
    if (vectorOne.size() == vectorTwo.size()) {
        
        // Calculate the dot-product of the two vectors
        for(size_t i=0; i < vectorOne.size(); i++) {
            result = getSum(result, getProduct(vectorOne.at(i), vectorTwo.at(i)));
        }
        return result;
    }
    else {
        throw runtime_error("Error: Vectors must have the same dimensions in order to perform dot product"); 
    }
}

/* Algorithm that calculates the result of matrix addition 
*/
vector<vector<complex<double>>> Algorithms::getMatrixAddition(vector<vector<complex<double>>> matrixOne, vector<vector<complex<double>>> matrixTwo) {
    // Get the size of the matrices to add
    size_t columns = matrixOne[0].size(), 
        rows = matrixOne.size();

    // Matrix to store the result of the additon in
    vector<vector<complex<double>>> resultMatrix(rows);

    // Check to ensure matrices are the same size
    if(columns == matrixTwo[0].size() && rows == matrixTwo.size()) {        
        // Adding Two matrices
        for(size_t i = 0; i < rows; ++i) {
            for(size_t j = 0; j < columns; ++j) {
                resultMatrix[i].push_back(getSum(matrixOne[i][j], matrixTwo[i][j]));
            }
        }
        return resultMatrix;
    }
    else {
        throw runtime_error("Error: Matrices must have the same dimensions in order add");
    }
}

/* Algorithm that calculates the result of complex vector addition 
*/
complex<double> Algorithms::getComplexVectorAddition(vector<complex<double>> complexVector){
    // Instantiate the Real Number and the Imaginary Number
    double rNum = 0, iNum = 0;

    for(size_t i = 0; i < complexVector.size(); i++){
        rNum += real(complexVector[i]);
        iNum += imag(complexVector[i]);
    }

    // Apply the calculated Real and Imaginary numbers to temp variable
    complex<double> result(rNum, iNum);
    
    return result;
}