// Program illustrating the use of real() and
// imag() function
#include "Algorithms.h"
#include <iomanip>
#include <string>
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

    int size;
    double rNum, iNum;

    cout << "Enter the dimension of the vectors: ";
    cin >> size;

    // Storing elements of first vector entered by user.
    for(int i = 0; i < size; ++i){
        cout << "Enter element " << i + 1 << " for vector one as 10 2 (10+2i): ";
        cin >> rNum >> iNum;
        complex<double> cNum(rNum, iNum);
        vectorOne.push_back(cNum);
    }

    // Storing elements of second vector entered by user.
    for(int i = 0; i < size; ++i){
        cout << "Enter element " << i + 1 << " for vector two as 10 2 (10+2i): ";
        cin >> rNum >> iNum;
        complex<double> cNum(rNum, iNum);
        vectorTwo.push_back(cNum);
    }

    complex<double> cNumAns;

    cNumAns = algo.getDotProductVector(vectorOne, vectorTwo);

    cout << "The dot-product of the two vectors is: " << real(cNumAns) << " + " << imag(cNumAns) << "i" << endl;
}

void matrixAdditionTest(){
    Algorithms algo;

    int rows, columns;
    double rNum, iNum;

    cout << "Enter number of rows: ";
    cin >> rows;

    cout << "Enter number of columns: ";
    cin >> columns;

    vector<vector<complex<double>>> matrixOne(rows);
    vector<vector<complex<double>>> matrixTwo(rows);

    cout << endl << "Enter values for the first matrix: " << endl;
    
    // Storing elements of first matrix entered by user.
    for(int i = 0; i < rows; ++i) {    
        for(int j = 0; j < columns; ++j)
        {
            cout << "Enter firstMatrix[" << i + 1 <<"][" << j + 1 << "] as 10 2 (10+2i): ";
            cin >> rNum >> iNum;
            complex<double> cNum(rNum, iNum);
            matrixOne[i].push_back(cNum);
        }
    }  

    // Storing elements of second matrix entered by user.
    cout << endl << "Enter elements of 2nd matrix: " << endl;
    for(int i = 0; i < rows; ++i) {
       for(int j = 0; j < columns; ++j)
       {
            cout << "Enter secondMatrix[" << i + 1 <<"][" << j + 1 << "] as 10 2 (10+2i): ";
            cin >> rNum >> iNum;
            complex<double> cNum(rNum, iNum);
            matrixTwo[i].push_back(cNum);
       }
    }
    cout << endl;

    vector<vector<complex<double>>> resultMatrix;

    resultMatrix = algo.getMatrixAddition(matrixOne, matrixTwo);

    cout << "Resulting Matrix:" << endl;

    for(int i = 0; i < rows; ++i) {
       for(int j = 0; j < columns; ++j)
       {
            ostringstream iStream;
            iStream << imag(resultMatrix[i][j]) << 'i';

            cout << right << setw(8) << real(resultMatrix[i][j]) << " + " << left << setw(8) << iStream.str();
       }
       cout << endl;
    }
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

    // try {
    //     cout << "Matrix Addition Test" << endl;
    //     matrixAdditionTest();
    // }
    // catch (runtime_error e) {
    //     cout << e.what() << endl;
    // }

    return 0;
}