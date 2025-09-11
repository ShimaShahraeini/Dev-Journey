/*Cpp programming
dev journey: 
in this code we got users age as an string and we use "isdigit" to make sure whatever user inputs is all dijits(0-9)!
*/
#include <iostream>
#include <string>
#include <cctype> // For isdigit()
#include <stdexcept> // For stoi exceptions

using namespace std;

int main() {
    cout << "Enter your age: ";
    string strAge;
    cin >> strAge;

    bool isValid = true;
    for (size_t nIndex = 0; nIndex < strAge.length(); nIndex++) {
        if (!isdigit(strAge[nIndex])) {
            isValid = false;
            break; // Exit the loop if a non-digit is found
        }
    }

    if (isValid) {
        try{
            int age = stoi(strAge); // Convert to integer
            cout << "Your age is: " << age << endl;
        } catch (const invalid_argument& e){
            cout << "Invalid input" << endl;
        } catch (const out_of_range& e){
            cout << "Input out of range" << endl;
        }
    } else {
        cout << "Invalid age input. Please enter digits only." << endl;
    }

    return 0;
}