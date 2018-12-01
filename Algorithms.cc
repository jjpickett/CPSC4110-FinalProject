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

    // Apply the calculated Real and Imaginary numbers to temp variable
    complex<double> temp(rNum, iNum);

    // Return the temp variable
    return temp;
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

    // Apply the calculated Real and Imaginary numbers to temp variable
    complex<double> temp(rNum, iNum);

    // Return the temp variable
    return temp;
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
        for(int i=0; i < vectorOne.size(); i++) {
            result = getSum(result, getProduct(vectorOne.at(i), vectorTwo.at(i)));
        }
        return result;
    }
    else {
        throw runtime_error("Error: Vectors must have the same dimensions in order to perform dot product"); 
    }
}