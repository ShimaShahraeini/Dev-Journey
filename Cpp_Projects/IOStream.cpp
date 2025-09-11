/*Cpp programming
dev journey: 
buffer overflow when user enters more charecter than it should and it's out of range, how to deal with it?*/

#include <iostream>
#include <iomanip>
#include <limits> //for numeric_limits
using namespace std;


int main() {

    cout<<"Enter your name: " << endl;
    char name[10];
    cin >> name;    //if user enter more charecter it cuase " *** stack smashing detected ***: terminated " error!
    cout << "Your name is "<<name<< endl;

    /*C++ provides a manipulator known as setw (in the iomanip.h header) that can 
    be used to limit the number of characters read in from a stream.*/

    cout<<"Enter your last name: " << endl; 
    char lastName[10];
    cin >> setw(10) >> lastName;

    /*While setw(10) limits the number of characters read into lastName,
    it doesn't prevent the user from typing more characters (plus the null terminator).
    If the user enters more than 9 characters, the extra characters remain in the input buffer.
    Any remaining characters will be left in the stream until the next extraction"*/
    cout << "Your last name is "<<lastName<< endl;

    // Clear the input buffer before cin.getline()
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear up to newline

    //Solution:
    cout << "Enter what city are you from: " << endl;
    char city[10];
    cin.getline(city, 10);

    if (cin.fail()) {
        //if user input more than 9 charecter for city error happens!
        cerr << "Error reading city." << endl;
        return 1;
    }
    cout << "You are from "<<city<< endl;

    cout<<"Enter your age: " << endl;
    int nAge;
    cin >> nAge;

    if (nAge <= 0) {
        cerr << "Oops, you entered an invalid age!"<< endl;
        return 1;
    }
    cout <<endl<< "Your name is "<<name<< endl;
    cout << "Your last name is "<<lastName<< endl;
    cout << "You are from "<<city<< endl;
    cout << "Your age is "<<nAge <<" years old" << endl;

    return 0;
}
