/*Cpp programming
Partial Template Specialization:
*/
#include <iostream>
#include <cstring>
using namespace std;

//nSize is the expression parameter 
template <typename T, int nSize>
class Buffer{
    // The expression parameter controls the size of the array
    T m_atBuffer[nSize];
public:
    T* GetBuffer(){return m_atBuffer; }

    T& operator[](int nIndex) {
        return m_atBuffer[nIndex];
    }
};

// Generic version (for non-char)
template<typename T, int nSize>
void PrintBufferString(Buffer<T, nSize> &rcBuf) {
    for (int i = 0; i < nSize; ++i) {
        cout << rcBuf[i] << (i < nSize - 1 ? ", " : "");
    }
    cout << endl;
}

// Specialized version for char
// Solve problem using Partial template specialization 
template<int nSize>
void PrintBufferString(Buffer<char, nSize> &rcBuf)
{
    cout << rcBuf.GetBuffer() << endl;
}

int main() {
    Buffer<char, 10> cChar10Buffer;
    strcpy(cChar10Buffer.GetBuffer(), "Ten");
    PrintBufferString(cChar10Buffer); //Ten 

    Buffer<int, 10> cint10Buffer;
    for (int n=0; n < 10; n++)
        cint10Buffer[n]=n;
    //print the address of pointer 
    PrintBufferString(cint10Buffer);
    return 0;
}