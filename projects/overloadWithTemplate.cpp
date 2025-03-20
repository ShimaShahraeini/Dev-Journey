/*Cpp programming
more Operator Overloading practice,
while practicing over loading pranthesis this question came up that what if we want to give multipul argument inside these pranthesis?
after searching i found 2 ways to do it and here i tried second way for first way run the "overloadParenthesis.cpp" file
2. Using Variadic Templates (C++11 and later):

    This approach is more flexible, allowing you to handle arguments of different types.
    However, it can be more complex to implement.
*/

#include <iostream>

class MyClass {
public:
    template <typename... Args>
    void operator()(Args... args) {
        processArgs(args...);
    }

private:
    template <typename T>
    void processArg(T arg) {
        std::cout << arg << " ";
    }

    template <typename T, typename... Args>
    void processArgs(T arg, Args... args) {
        processArg(arg);
        processArgs(args...);
    }

    void processArgs() { //base case
        std::cout << std::endl;
    }
};

int main() {
    MyClass obj;
    obj(1, 2.5, "hello");
    obj(10, 20);
    obj(); // No arguments
    return 0;
}