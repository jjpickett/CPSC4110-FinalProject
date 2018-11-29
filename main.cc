// Program illustrating the use of real() and
// imag() function
#include <complex>
#include "Algorithms.h"
using namespace std;

// driver function
int main()
{
    Algorithms algo;
    // defines the complex number: (10 + 2i)
    complex<double> mycomplex(10.0, 2.0);

    // prints the real part using the real function
    cout << "Real part: " << real(mycomplex) << endl;
    cout << "Imaginary part: " << imag(mycomplex) << endl;
    cout << "Last part: " << algo.getNum() << endl;
    return 0;
}