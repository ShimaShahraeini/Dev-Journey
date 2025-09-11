/*Cpp programming
Redefining functionality in a derived class*/
#include <iostream>

using namespace std;
class Base { 
protected:
    int m_nValue;
    void PrintValue(){ cout << m_nValue <<endl;}
public:
    Base(int nValue) : m_nValue(nValue){}
    void Identify() { cout << "I am a Base"<<endl; }
};
class Derived: public Base {
public:
    Derived(int nValue): Base(nValue) { }
    int GetValue() { return m_nValue; } // Adding function member
    // Here's our modified function
    void Identify() { 
        //whith this line we force the function to do the parents work first.
        Base::Identify(); //if one write Identify(); then an infinite loop!
        cout << "I am a Derived"<<endl; 
    }

    //Base::PrintValue was inherited as protected, so the publishing/access 
    // But we're changing it to public by declaring it in the this section
    void PrintValue() { Base::PrintValue(); } // re-declare it in the public scope.

};
    
int main(){
        
    Derived cDerived(5);
    Base cBase(5);

    cBase.Identify(); // I am a Base
    cDerived.Identify(); //I am a Base I am a Derived

    /*The following won't work because 
    has been redefined as private */ 
    //cout << cDerived.m_nValue; // error

    // PrintValue is public in Derived, so this is ok
    cDerived.PrintValue(); // prints 5

    return 0;
}