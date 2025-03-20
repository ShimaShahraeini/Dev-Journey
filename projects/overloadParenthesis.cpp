/*Cpp programming
more Operator Overloading practice,
while practicing over loading pranthesis this question came up that what if we want to give multipul argument inside these pranthesis?
after searching i found 2 ways to do it and here i tried first way for second way run the "overloadWithTemplate.cpp" file
1. Using std::initializer_list (C++11 and later):

    This is the preferred and most type-safe method.
    std::initializer_list allows you to pass a list of elements of the same type.
*/


#include <iostream>
#include <cassert> //for assert
#include <initializer_list>
using namespace std;
#define size 4

class Matrix{
    double adData[size][size];
public:
    Matrix(){
        for(int i=0; i<size; i++)
            for(int j=0; j<size; j++)
                adData[i][j] = 0.0;
    }
    double& operator()(const int row, const int col);
    void operator()();
    void operator()(std::initializer_list<double> args);
    void printMatrix(); 

};
double& Matrix::operator()(const int row, const int col){
    assert(row>=0 && row<size);
    assert(col>=0 && col<size);
    return adData[row][col];
}
void Matrix::operator()(){
    for(int i=0; i<size; i++)
        for(int j=0; j<size; j++)
            adData[i][j] = 0.0;
}
void Matrix::operator()(std::initializer_list<double> args) {
    int index = 0;
    for (double value : args) {
        if (index >= size * size) {
            break; // Stop if we've filled the matrix
        }
        int row = index / size;
        int col = index % size;
        adData[row][col] = value;
        index++;
    }
}
void Matrix::printMatrix() {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cout << adData[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    Matrix cMatrix;
    cMatrix(1,2) = 3.5;
    cout << cMatrix(1,2)<<endl; //3.5
    cMatrix(); //erase cMatrix
    cout << cMatrix(1,2)<<endl; //0

    Matrix dMatrix;
    dMatrix({1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0, 11.0, 12.0});

    cout << "dMatrix:" << endl;
    dMatrix.printMatrix(); // Print the matrix

    return 0;
}
