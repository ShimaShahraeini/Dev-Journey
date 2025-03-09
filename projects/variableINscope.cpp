/*Cpp programming
dev journey: 
Used to access a global variable that is hidden by a local variable with the same name.
(The scope resolution operator ::)
we also learned:
- If you have nested local scopes (e.g., nested blocks within a function), you cannot directly use :: 
  to access variables in the outer blocks.
- :: is primarily for accessing namespace, class, and global scopes.
- For local scopes, you need to rely on the natural scope resolution rules of C++*/

#include <iostream>

int counter = 50; // global variable

int main()
{
    int counter = 10;
    // this counter refers to the // local variable
    for (int counter = 1; counter < 10; counter++)
    {
    printf("%d\n",
    ::counter   // global variable
    /           // divided by
    counter);   // local variable
    }
}