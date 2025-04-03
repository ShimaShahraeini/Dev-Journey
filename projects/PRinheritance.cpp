/*Cpp programming
using pointers and refrences in inheritance
shows that without the virtual keyword, these base class pointers and references call the base class's function,
even though they point to a childs object.
virtual enables runtime polymorphism, allowing the correct function to be called when using base class pointers or references.
*/
#include <iostream>

using namespace std;

class Base { 
protected:
    int m_nValue;
public:
    Base(int nValue): m_nValue(nValue) {}

    //virtual const char* GetName(){return "Base";} this line change the output!
    const char* GetName(){return "Base";} 
    int GetValue() { return m_nValue; }
};
class Derived: public Base{
public:
    Derived(int nValue): Base(nValue) {}

    const char* GetName() { return "Derived"; }
    int GetValueDoubled() { return m_nValue *2;}
};
int main() {
    Derived cDerived(5); 
    cout << "cDerived is " << cDerived.GetName() << " and has value " << cDerived.GetValue() << endl;
    Derived &rDerived = cDerived;
    cout << "rDerived is a " << rDerived.GetName() << " and has value " << rDerived.GetValue() << endl;
    Derived *pDerived = &cDerived; 
    cout << "pDerived is a " << pDerived->GetName() <<" and has value " << pDerived->GetValue() << endl;

    cout <<"________________"<<endl;
    //in a obj of a base class who points to a drived class we want getName drived not base, and if you dont mention virtuall it gets base
    //These are both legall 
    Base &rBase = cDerived; 
    Base *pBase = &cDerived;
    cout << "cDerived is " << cDerived.GetName() << " and has value " << cDerived.GetValue() << endl;
    cout << "rBase is a " << rBase.GetName() << " and has value " << rBase.GetValue() << endl;
    cout << "pBase is a " << pBase->GetName() <<" and has value " << pBase->GetValue() << endl;

    //thats why the soulotion is to declare Getname as a virtual(keep this in mind that you can just use it on base class but it's better to mention it in every classes)

    return 0;
}