/*Cpp programming
dev journey: 
To repeatedly prompt the user to enter their age until a valid positive integer is entered.
- cin.ignore() is used to remove characters from the input buffer. This is particularly useful for:

    Clearing leftover characters after input operations.   
    Skipping unwanted characters, such as newline characters (\n).
    Preventing buffer overflows.
    Handling invalid input.
*/
#include <iostream>
#include <string>

using namespace std;

int main() {
    
    int nAge;
    while (1){
        cout << "Enter your age: "<<endl;
        cin>> nAge; // user enter the following: 23dncdiklikd
        if (cin.fail())//no extraction took place
        {
            cin.clear(); // reset the state bits back to goodbit so we can use ignore() 
            cin.ignore(1000, '\n'); // clear out the bad input from the stream. 
            continue; // try again
        }
            
        cin.ignore(1000, '\n');// clear out any additional input from the stream

        if (nAge <= 0) // make sure nAge is positive
            continue;
        break;
    };
    cout<<"you are "<<nAge<<" years old."<<endl;

    return 0;
}