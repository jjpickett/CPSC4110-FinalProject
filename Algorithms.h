#include <iostream>
#include <complex>
#include <vector>

using namespace std;

#ifndef ALGORITHMS_H
#define ALGORITHMS_H

class Algorithms
{
  public:
    Algorithms();
    
    complex<double> getSum(complex<double> myComplex1, complex<double> myComplex2);
    complex<double> getProduct(complex<double> myComplex1, complex<double> myComplex2);
    double getMod(complex<double> myComplex);
    complex<double> getConj(complex<double> myComplex);
    complex<double> getDotProductVector(vector<complex<double>> vectorOne, vector<complex<double>> vectorTwo);

    virtual ~Algorithms(){};

    
    
};
# endif