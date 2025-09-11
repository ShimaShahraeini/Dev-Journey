/*Cpp programming
this code mostly was about memmory management inside classes but here is the concepts we practiced:
Dynamic Memory Allocation and Deallocation:
    The code demonstrates how to dynamically allocate memory for a character array using 'new' and how to deallocate it using 'delete'.
Destructor and constructor
    The importance of code it our self and customize it.
    destructor ensures that the dynamically allocated memory is released when a MyString object goes out of scope, preventing memory leaks.
Memory Management Responsibility:
    I learned that when you allocate memory dynamically, you are responsible for deallocating it.
Copy Constructor:
    Copy constructors and assignment operators are essential for classes that manage dynamic memory.
    Deep Copy:
        The copy constructor performs a deep copy, allocating new memory for the copied string.
        This prevents issues like double frees that occur with shallow copies.
    Handling Null Pointers:
        The copy constructor handles the case where the source string is null.
Assignment Operator Overloading:
        This ensures that assignment works correctly with objects while
        The code includes a self-assignment, This is crucial to prevent memory leaks and other errors when assigning an object to itself.
*/
#include <iostream>
#include <string>
#include <cstring>
using namespace std;

class MyString{
    char *m_pchString;
    int m_nLength;
public:
    MyString(const char* pchString="") //default constructor
    {
        // Find the length of the string plus one character for a terminator 
        m_nLength = strlen(pchString) + 1;
        m_pchString= new char[m_nLength]; // Allocate a buffer equal to this length 
        strcpy(m_pchString, pchString);
        m_pchString[m_nLength-1] ='\0';  // Make sure the string is terminated
    }
    MyString(const MyString& cSource) { //Copy constructor
        // because m_nLength is not a pointer, we can shallow copy it 
        m_nLength =cSource.m_nLength;
        // m_pchString is a pointer, so we need to deep copy it if it is non-null 
        if (cSource.m_pchString) {
            // allocate memory for our copy
            m_pchString = new char[m_nLength];
            // Copy the string into our newly allocated memory 
            strncpy(m_pchString, cSource.m_pchString, m_nLength);
        }
        else
            m_pchString = 0;
    }
    ~MyString(){  //destructor
        delete[] m_pchString;     //We need to deallocate our buffer
        m_pchString = 0;     // Set m_pchString to null just in case
    }
    // Assignment operator
    MyString& operator=(const MyString& cSource);
    char* GetString() { return m_pchString; } 
    int GetLength() { return m_nLength; }
};

    // Assignment operator
    MyString& MyString::operator=(const MyString& cSource) {
        if (this==&cSource) // check for self-assignment, if we miss this line memory leaking happens while self-assignment
        {
            cout <<"self-assignment is not happening!"<< endl;
            return *this;
        }
        delete[] m_pchString; // deallocate any value that this string is holding!
        // because m_nLength is not a pointer, we can shallow copy it
        m_nLength = cSource.m_nLength;
        // now we need to deep copy m_pchString
        if (cSource.m_pchString) {
            m_pchString = new char[m_nLength]; // allocate memory for our copy 
            strncpy(m_pchString, cSource.m_pchString, m_nLength);
        }
        else
            m_pchString = 0;
        return *this;
    }

int main(){
    /*
    //if we dont make the copy constructor, The shallow copy leads to a double-free error, which is a serious problem.
    MyString cHello("Hello, world!");
    {
        MyString cCopy=cHello; // use default copy constructor
        //Copy goes out of scope here
    }
    cout << cHello.GetString(); // this will crash

    OUTPUT: free(): double free detected in tcache 2
            Aborted (core dumped)
    */

    MyString cHello("Hello, world!");
    {
        MyString cCopy = cHello; // usa copy constructo
        //cCopy goes out of scope here
    }
    cout <<cHello.GetString()<< endl;

    cHello = cHello;  //calls assignment operator


    return 0;
}