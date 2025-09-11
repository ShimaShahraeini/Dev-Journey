/*Cpp programming
dev journey: 
1. assert segment:
    assert is a preprocessor macro defined in the <cassert> header.
    assert is primarily used to verify assumptions and conditions within your code during development.
    It helps you identify situations where your code is behaving unexpectedly, indicating a bug.
    can also serve as a form of documentation, clearly stating the expected conditions at certain points in your code.
2. inline function:
    The inline keyword is a request to the compiler, not a command. The compiler may or may not inline the function.
    The compiler considers factors like function size, complexity, and frequency of calls when deciding whether to inline a function.
    it's purpose is Reduceing Function Call Overhead and Improving Performance
3. template:
    Templates allow you to write code that is independent of specific data types.
    You can create functions and classes that can be used with various data types, reducing code duplication.
    Templates provide compile-time polymorphism, meaning that the appropriate code is generated at compile time based on the data types used.

*/

#include <iostream>
#include <cassert>

int divide(int numerator, int denominator) {
    assert(denominator != 0);
    return numerator / denominator;
}

inline int square(int x) {
    return x * x;
}
//Now when the program compiles main(), it will create machine code as if main() had been written like this: result2 = 5*5;

// return type depends on template parameters template <typename T, typename U>
// this is the template parameter declaration 
template <typename T, typename U> // this is the template parameter declaration 
auto add(T t, U u) -> decltype(t + u) { //c++ 11
    return t + u;
}

int main() {
    int result3 = add(10, 20);
    std::cout << "Int add: " << result3 << std::endl;
    double result4 = add(3.14, 7);
    std::cout << "Double add: " << result4 << std::endl;
    result3 = add<int>(3.14, 2.71);
    std::cout << "Double forced to Int add: " << result3 << std::endl;

    int result2 = square(5); // Compiler may inline this call
    std::cout << "Square: " << result2 << std::endl;

    int result1 = divide(10, 2); // Corrected call
    std::cout << "Divide: " << result1 << std::endl;

    result1 = divide(5, 0); // This will trigger an assert failure
    std::cout << "Dvide: " << result1 << std::endl;

    return 0;
}

/*output:
Int add: 30
Double add: 10.14
Double forced to Int add: 5
Square: 25
Divide: 5
calculator: learningCalculator.cpp:19: int divide(int, int): Assertion `denominator != 0' failed.
Aborted (core dumped)
*/