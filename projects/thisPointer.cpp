/*Cpp programming
dev journey: 
.    When you call a non-static member function of a class, the compiler implicitly passes a pointer to the object on which the function is called. This pointer is 'this'.
.    'this' always points to the object that is currently invoking the member function.
.    You can use 'this' to explicitly access the member variables and member functions of the current object.
.    'this' is particularly useful when you have local variables or function parameters with the same names as member variables. It helps to disambiguate them.
.    You can use 'this' to return a reference or a pointer to the current object, enabling method chaining.
This code demonstrates method chaining, a powerful technique that allows you to call multiple member functions in a single line.
It works because each of the Add, Sub, and Mult functions returns a reference to the Calc object.
*/
#include <iostream>
class Calc{
    private:
        int m_nValue;
    public:
        Calc(){m_nValue = 0;}

        Calc& Add(int nValue){m_nValue+=nValue; return *this;} //It returns a reference to the Calc object itself (*this). This allows for method chaining.
        Calc& Sub(int nValue){m_nValue-=nValue; return *this;}
        Calc& Mult(int nValue){m_nValue*=nValue; return *this;}

        int GetValue(){return m_nValue;}
};
int main() {
    Calc c;
    c.Add(5).Sub(3).Mult(4);
    std::cout << "result: " << c.GetValue() << std::endl;

    return 0;
}
