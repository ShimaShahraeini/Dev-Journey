/*Cpp programming
dev journey 
// this file is just a practice and an exam of myself!
*/
#include <iostream>
#include <string>
using namespace std;

class Test{
    int number;
    string text;

public:
    static int innerInt;
    // Default constructor
    Test() : number(0), text("") {}
    // Constructor for int
    Test(int num) : number(num), text("") {}
    // Constructor for std::string
    Test(string txt) : number(0), text(txt) {}
    //copy Constructor
    Test(const Test& other) : number(other.number), text(other.text) {}
    //assignment operator
    Test& operator=(const Test& other);
    //Addition operator
    friend int operator+(const Test& obj, int num);
    friend int operator+(int num, const Test& obj);
    friend Test operator+(const Test& obj1, const Test& obj2);
    //Pre-increment operator
    Test& operator++();
    //Post-increment operator
    Test operator++(int);
    //Function call operator
    int operator()(int num, const string& str);
    // Implicit conversion to float
    operator float() const{
        return static_cast<float>(number);
    }
    //Add and Sub member function
    Test Add(int num);
    Test Sub(int num);
    int getNumber(){return number;}
    string getString(){return text;}


};
int Test::innerInt = 4; // Initialize innerInt

float print(float a){
    return a;
}
Test& Test::operator=(const Test& other){
    if(this != &other){
        number = other.number;
        text = other.text ;
    };
    return *this;
}
int operator+(const Test& obj, int num){
    return obj.number + num;
}
int operator+(int num, const Test& obj){
    return num + obj.number;
}
Test operator+(const Test& obj1, const Test& obj2) {
    Test result = obj1; // Copy obj1 (including text)
    result.number += obj2.number; // Add the numbers
    return result;
}
Test& Test::operator++(){
    number++;
    return *this;
}
Test Test::operator++(int) {
    Test result = *this;
    number++; // Increment AFTER copying
    return result;
}
int Test::operator()(int start, const string& search){
    if (start < 0 || start >= text.length()) {
        return -1; // Invalid start position
    }

    size_t found = text.find(search, start);
    if (found != string::npos) {
        return static_cast<int>(found);
    } else {
        return -1; // Not found
    }
}
Test Test::Add(int num){
    Test Result = *this;
    Result.number += num;
    return Result;
}
Test Test::Sub(int num){
    Test Result = *this;
    Result.number -= num;
    return Result;
}

int main(){
    Test  a3, a2(2), a("this is test");
    Test b(a), c=a2;
    cout << a + b.getNumber() << ", " << print(c) << endl;

    cout<< "b= " << b.getNumber()<<endl;
    b = (++a)++ + b;
    cout<< "b= " <<b.getNumber()<< ", a= " << a.getNumber()<<endl;

    b = a + a.Add(2).Sub(5) - b(4,"test") + Test::innerInt;
    cout<< "b= " << b.getNumber()<<endl;

    return 0;
}

/*
OUTPUT:
0, 2
b= 0
b= 1, a= 2
b= -3
*/