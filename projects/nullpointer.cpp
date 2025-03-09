/* Cpp programming
dev journey: 
in this code we practiced overloading 
NULL-pointers, 0-pointers, nullptr(c++ 11)
*/
#include <iostream>

void show(int val) {printf("Integer: %d\n", val); } 
void show(double val) { printf("Double: %lf\n", val); } 
void show(char const *val) { printf("String: %s\n", val); }

int main()
{
    show(0);
    /*NULL here can either represent 0 or (void*)0 that's why it has "call of overloaded ‘show(NULL)’ is ambiguous" error
    show(NULL);*/
    show((char *)0); 
    show(nullptr);// in C++ 11
}
