/*Cpp programming
more Operator Overloading practice 
uses a "dummy variable" or "dummy argument" for the postfix operators
*/


#include <iostream>
using namespace std;

class Digit{
    int m_nDigit;
public:
    Digit(int nDigit=0) { m_nDigit=nDigit;}
    Digit& operator++(); //prefix
    Digit& operator--(); //prefix
    Digit operator++(int); //postfix
    Digit operator--(int); //postfix
    int GetDigit() const {return m_nDigit;}
};
Digit& Digit::operator++(){
    if(m_nDigit==9) m_nDigit=0; 
    else ++m_nDigit;
    return *this; // Note that we return *this
}
Digit& Digit::operator--(){
    if (m_nDigit == 0) m_nDigit=9; 
    else --m_nDigit;
    return *this; // Note that we return *this
}
Digit Digit::operator++(int){
    Digit cResult(m_nDigit); //a temporary variable with our current digit
    ++(*this); // use prefix operator to increment this digit
    return cResult;//return camery result
}
Digit Digit::operator--(int){
    Digit cResult(m_nDigit);
    --(*this);
    return cResult;
}

int main() {
    Digit d1;
    cout << (++++d1).GetDigit() << endl; //2

    Digit d2(5);
    cout << (d2--).GetDigit() << endl;//4

    return 0;
}
