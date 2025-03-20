/*Cpp programming
dev journey: 
1. Customizing Operators:
    The core concept is operator overloading, which allows you to redefine how operators (like +) behave with user-defined types (like your Cents class).
    This makes your classes more intuitive to use, as you can apply familiar operators to them.

2. Friend Functions:
    The operator+ functions are declared as friend functions. This grants them access to the private members of the Cents class (m_nCents).
    Friend functions are not member functions, but they have special access privileges.
*/


#include <iostream>
using namespace std;

class Cents {
    int m_nCents;
public:
    Cents(int nCents){m_nCents = nCents;}
    // Overload cCents + int
    friend Cents operator+(const Cents &cCents, int nCents);
    // Overload int + cCents
    friend Cents operator+(int nCents, const Cents &cCents);
    int GetCents(){return m_nCents;}
};

// note: this function is not a member function!
Cents operator+(const Cents &cCents, int nCents){
    return Cents(cCents.m_nCents + nCents);
}
    
    
// note: this function is not a member function!
Cents operator+(int nCents, const Cents &cCents) {
    return Cents(nCents + cCents.m_nCents); 
}

int main() {

    Cents c1= Cents(4) + 6;
    Cents c2 = 6 + Cents(4);
    cout << "c1 contains:" << c1.GetCents() << ", c2 contains:" << c2.GetCents() << endl;
    return 0;
}