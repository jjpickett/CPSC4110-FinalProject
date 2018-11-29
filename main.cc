// Program illustrating the use of real() and
// imag() function
#include "Algorithms.h"
using namespace std;

/** This is a test for Summing Complex numbers
*/
void sumTest()
{
    Algorithms algo;

    double rNum1, iNum1, rNum2, iNum2;
    cout << "Please input first complex number as 10 2 (10+2i) " << endl;
    cin >> rNum1 >> iNum1;
    cout << "Please input second complex number as 10 2 (10+2i) " << endl;
    cin >> rNum2 >> iNum2;

    complex<double> cNum1(rNum1, iNum1);
    complex<double> cNum2(rNum2, iNum2);

    complex<double> cNumAns;

    cNumAns = algo.getSum(cNum1, cNum2);

    cout << "The sum of the complex numbers is: " << real(cNumAns) << " + (" << imag(cNumAns) << "i)" << endl;
}

/** This is a test for Multiplying Complex numbers
*/
void productTest()
{
    Algorithms algo;

    double rNum1, iNum1, rNum2, iNum2;
    cout << "Please input first complex number as 10 2 (10+2i) " << endl;
    cin >> rNum1 >> iNum1;
    cout << "Please input second complex number as 10 2 (10+2i) " << endl;
    cin >> rNum2 >> iNum2;

    complex<double> cNum1(rNum1, iNum1);
    complex<double> cNum2(rNum2, iNum2);

    complex<double> cNumAns;

    cNumAns = algo.getProduct(cNum1, cNum2);

    cout << "The product1 4 of the complex numbers is: " << real(cNumAns) << " + (" << imag(cNumAns) << "i)" << endl;
}

// driver function
int main()
{

    //cout << "Sum Test" << endl;
    //sumTest();

    cout << "Product Test" << endl;
    productTest();

    return 0;
}
