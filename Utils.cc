#include "Utils.h"

Utils::Utils(){
}

/* Determines which operator to put between a Complex Number
 */
string Utils::getOperator(complex<double> number) {
    return imag(number) > 0 ? " + " : "";
}

/* Returns the string representation of a Real Number
 */
string Utils::getPreparedRealNumber(double number) {
    ostringstream stringStream;
    number == 0 ? stringStream << "" : stringStream << number;
    return stringStream.str();
}

/* Returns the string representaion of an Imaginary Number
 */
string Utils::getPreparedImaginaryNumber(double number) {
    ostringstream stringStream;
    number == 0 ? stringStream << "" : stringStream << number << "i";
    return stringStream.str();
}

/* Prints a formatted version of a complex number
 */
string Utils::printComplexNumber(complex<double> number) {
    ostringstream stringStream;
    if(real(number) == 0 && imag(number) == 0) {
        stringStream    << right 
                        << setw(8) 
                        << "0";
    }
    else {
        stringStream    << right 
                        << setw(8) 
                        << getPreparedRealNumber(real(number)) 
                        << getOperator(number) 
                        << left 
                        << setw(8) 
                        << getPreparedImaginaryNumber(imag(number));
    }

    return stringStream.str();
}