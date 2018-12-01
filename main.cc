// Program illustrating the use of real() and
// imag() function
#include "Algorithms.h"
using namespace std;

/** This is a test for Summing complex numbers
*/
void sumTest(){
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

/** This is a test for Multiplying complex numbers
*/
void productTest(){
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

    cout << "The product of the complex numbers is: " << real(cNumAns) << " + (" << imag(cNumAns) << "i)" << endl;
}

/** This is a test for getting the Modulo of a complex number
*/
void modTest(){
    Algorithms algo;

    double rNum, iNum;

    cout << "Please input the complex number as 10 2 (10+2i) " << endl;
    cin >> rNum >> iNum;

    complex<double> cNum(rNum, iNum);

    cout << "The Modulo of the complex numbers is: " << algo.getMod(cNum) << endl;
}

/** This is a test for getting the Conjugate of a complex number
*/
void conjTest(){
    Algorithms algo;

    double rNum, iNum;
    cout << "Please input first complex number as 10 2 (10+2i) " << endl;
    cin >> rNum >> iNum;

    complex<double> cNum(rNum, iNum);

    complex<double> cNumAns;

    cNumAns = algo.getConj(cNum);

    cout << "The conjugate of the complex numbers is: " << real(cNumAns) << " + (" << imag(cNumAns) << "i)" << endl;
}

/** This is a test for getting the Conjugate of a complex number
*/
void vectorDotProductTest(){
    Algorithms algo;
    
    vector<complex<double>> vectorOne;
    vector<complex<double>> vectorTwo;

    complex<double> cNum1(1, 0);
    complex<double> cNum2(0, 2);
    complex<double> cNum3(3, 0);
    complex<double> cNum4(4, 0);
    complex<double> cNum5(5, 0);
    complex<double> cNum6(6, 0);

    vectorOne.push_back(cNum1);
    vectorOne.push_back(cNum2);
    vectorOne.push_back(cNum3);
    vectorTwo.push_back(cNum4);
    vectorTwo.push_back(cNum5);
    vectorTwo.push_back(cNum6);

    complex<double> cNumAns;

    cNumAns = algo.getDotProductVector(vectorOne, vectorTwo);

    cout << "The dot-product of the two vectors is: " << real(cNumAns) << " + " << imag(cNumAns) << "i" << endl;
}

// driver function
int main()
{

    // ***** Uncomment the function to test capability

    //cout << "Sum Test" << endl;
    //sumTest();

    // cout << "Product Test" << endl;
    // productTest();
    
    // cout << "Mod Test" << endl;
    // modTest();

    // cout << "Conj Test" << endl;
    // conjTest();
    
    // try {
    //     cout << "Vector Dot-Product Test" << endl;
    //     vectorDotProductTest();
    // }
    // catch (runtime_error e) {
    //     cout << e.what() << endl;
    // }

    return 0;
}