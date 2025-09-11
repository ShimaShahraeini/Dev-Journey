/*Cpp programming
this was also a test that given the main part of the code i should implemented
the class cent and function avarage while using the templat!
*/
#include <iostream>

using namespace std;

class Cent { 
private:
    int m_nValue;
public:
    Cent(int nValue): m_nValue(nValue) {}
    Cent() : m_nValue(0) {}  // Default constructor
    int GetValue() const { return m_nValue; }
    Cent& operator+=(const Cent& nValue);
    Cent& operator/=(const Cent& nValue);
    friend ostream& operator<< (ostream& out, const Cent &cArray);
};

Cent& Cent::operator+=(const Cent& nValue) {
    m_nValue += nValue.m_nValue;
    return *this;  // Return reference to this object
}

Cent& Cent::operator/=(const Cent& nValue) {
    m_nValue /= nValue.m_nValue;
    return *this;  // Return reference to this object
}

ostream& operator<< (ostream& out, const Cent &cArray) {
    out << "sum: " << cArray.GetValue();
    return out;
}

template <class T>
T Average(T *atArray, int nNumValues){
    T tSum = 0;
    for (int nCount=0; nCount < nNumValues; nCount++)
    tSum += atArray[nCount];
    tSum /= nNumValues;
    return tSum;
}

int main() {
    //write the rest of the code based on these 2 line of code!
    Cent CArray[] = { Cent(5), Cent(10), Cent(15), Cent(14) };
    cout << Average(CArray, 4) << endl;

    return 0;
}