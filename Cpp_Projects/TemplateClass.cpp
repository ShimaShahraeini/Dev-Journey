/*Cpp programming
making template class
*/
#include <iostream>
#include <assert.h>
using namespace std;

template <typename T>
class Array{    // template class
    int m_nLength;
    T *m_ptData;
public:
    Array(){m_nLength = 0; m_ptData = 0; }
    Array(int nLength) {
        m_ptData= new T[nLength];
        m_nLength = nLength;
    }
    ~Array(){ 
        delete[] m_ptData; 
        m_ptData = 0; 
    }
    T& operator() (int nIndex) {
        assert(nIndex>= 0 && nIndex< m_nLength);
        return m_ptData[nIndex];
    }
    int GetLength();
    void Print() const {
        cout << "Array contents (" << m_nLength << " elements): ";
        for (int i = 0; i < m_nLength; ++i) {
            cout << m_ptData[i];
            if (i < m_nLength - 1) cout << ", ";
        }
        cout << endl;
    }
};
template<typename T>
int Array<T>::GetLength() { return m_nLength; }

int main() {
    // Create arrays
    Array<int> intArray(12); 
    Array<double> doubleArray(12);
    
    // Fill arrays with values
    for (int n = 0; n < 12; n++) {
        intArray(n) = n; 
        doubleArray(n) = n + 0.5;
    }
    
    // Print array contents
    cout << "Integer Array:" << endl;
    intArray.Print();
    
    cout << "\nDouble Array:" << endl;
    doubleArray.Print();
    
    // Demonstrate element access
    cout << "\nAccessing specific elements:" << endl;
    cout << "intArray[5] = " << intArray(5) << endl;
    cout << "doubleArray[7] = " << doubleArray(7) << endl;
    
    // Show array lengths
    cout << "\nArray lengths:" << endl;
    cout << "intArray length: " << intArray.GetLength() << endl;
    cout << "doubleArray length: " << doubleArray.GetLength() << endl;
    return 0;
}