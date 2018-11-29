#include <iostream>
#include <complex>

using namespace std;

#ifndef ALGORITHMS_H
#define ALGORITHMS_H

class Algorithms
{
  public:
    Algorithms();
    
    complex<double> getSum(complex<double> myComplex1, complex<double> myComplex2);
    complex<double> getProduct(complex<double> myComplex1, complex<double> myComplex2);

    virtual ~Algorithms(){};

    
    
};
# endif