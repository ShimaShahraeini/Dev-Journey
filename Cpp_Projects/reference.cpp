/* Cpp programming
dev journey: 
Lvalues:

    Lvalues represent memory locations that persist beyond a single expression.
    They have names and addresses.
    Examples: variables (value), dereferenced pointers, elements of arrays.
    An lvalue reference creates an alias to an existing lvalue.
    lvalue reference must be initialized with an lvalue.
    Changes made through the reference affect the original lvalue.

Rvalues:

    Rvalues are temporary values that do not persist beyond the expression that creates them.
    They are typically the results of expressions, function calls that return non-reference values, and literals.
    Examples: literals (18), the result of intval().
    An rvalue reference creates an alias to an rvalue.
    rvalue reference can extend the lifetime of a temporary object.
    rvalue reference is used for move semantics and perfect forwarding

- This fails because you cannot bind a non-constant lvalue reference to a temporary object (rvalue).
  The temporary object's lifetime would end immediately, leaving a dangling reference.(1)
- A constant lvalue reference can bind to a temporary object, extending its lifetime to the lifetime of the reference(2)
- Rvalues are temporary and don't have persistent memory locations so Know that you cannot take the address of an rvalue.(3)
*/

#include <iostream>
using namespace std;

int intval(){
    return 5; //returns an rvalue (a temporary int).
}

void receive(int &value){
    cout << "int value parameter\n";
}
void receive(int &&value){
    cout << "int R-value parameter\n";
}
int main(){
    /*
    int &ir = intval(); //fails: refers to a temporary (1)*/
    int const &ic = intval(); ///OK: immutable temporary (2)
    /*
    int *ip = &intval();//fails: no Ivalue available (3)*/


    receive(18); //int R-value parameter
    int value = 5; 
    receive(value); //int value parameter
    receive(intval()); //int R-value parameter
}