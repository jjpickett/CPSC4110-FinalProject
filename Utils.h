#include <complex>
#include <iomanip>

using namespace std;

#ifndef UTILS_H
#define UTILS_H

class Utils
{
  public:
    Utils();
    
    private: 
      string getPreparedRealNumber(double number);
      string getPreparedImaginaryNumber(double number);
    
    public: 
      string getOperator(complex<double> number);
      string printComplexNumber(complex<double> number);
      
      virtual ~Utils(){};
    
    
};
# endif