/*Cpp programming
    Templates are blueprints for generating classes or functions that work with various types.
    Template specialization lets you override the generic template definition for specific types.
    It provides a way to customize behavior based on the type being used.

Types of Template Specialization:

    Class Template Specialization:
        Allows you to provide a completely different implementation of a class template for a specific type.
        You can specialize the entire class or individual member functions.
    Function Template Specialization:
        Allows you to provide a different implementation of a function template for a specific type.
        Can specialize the entire function.
    Partial Template Specialization:
        Allows you to specialize a template for a subset of template parameters.
        Useful when you want to provide a specialized implementation for a group of related types.


*/
#include <iostream>
#include <cstring>
using namespace std;

template <typename T>
class Storage{
    T m_tValue;
public:
    Storage(T tValue) {
        m_tValue = tValue;
    }
    ~Storage() {}
    void Print(){
        cout <<m_tValue<<endl;
    }
};

// Specialize ENTIRE class for char*
template<>
class Storage<char*> {
    char* m_tValue;
public:
    // Constructor: Deep-copy the input string
    Storage(const char* tValue) {
        if (tValue) { // check if tValue is a valid pointer
            m_tValue = new char[strlen(tValue) + 1];
            strcpy(m_tValue, tValue);
        } else {
            m_tValue = nullptr;
        }
    }

    // Destructor: Free owned memory
    ~Storage() {
        if (m_tValue) {
            //cout << "Deleting storage for: " << m_tValue << endl;
            delete[] m_tValue;
        }
    }

    // Print: Safe access
    void Print() const {
        if (m_tValue) {
            cout << m_tValue << endl;
        } else {
            cout << "(null)" << endl;
        }

    }

    // Disable copying (or implement deep copy)
    Storage(const Storage&) = delete;
    Storage& operator=(const Storage&) = delete;
};

/*
// Specialize INDIVIDUAL methods for char*
template<>
Storage<char*>::Storage(char* tValue) { 
    m_tValue = new char[strlen(tValue)+1];
    strcpy(m_tValue, tValue);
}
template<>
Storage<char*>::~Storage(){
    delete[] m_tValue;}

*/
int main() {
    Storage<int> nValue(5);
    Storage<double> dValue(6.7);
    nValue.Print(); // ok
    dValue.Print(); // ok
    // but !!!
    char *strString = new char[40]; 
    strcpy(strString, "Hello, world!");
    Storage<char*> strValue(strString);
    delete strString;
    // Print out our value
    //This will exhibits undefined behavior (UB) UB means anything could happen - it might crash, print garbage, or even appear to work
    strValue.Print();
    //fix it using template specialization so we coded constructor and destructor specilizied for <*char>

    return 0;
}