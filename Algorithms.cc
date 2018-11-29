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
