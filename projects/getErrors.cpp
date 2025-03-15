/*Cpp programming
dev journey: 
as you can see from main we learend 5 thing about 'get' here. run any funtion from paragraph1 to paragraph5 individually to practice*/

#include <iostream>
#include <limits> //for numeric_limits
using namespace std;

void paragraph1(){
    char p1[11];
    cout<<"Enter 1st pragraph: " << endl;
    cin.get(p1, 11); //input: Hello my name is Shima
    cout << p1 << endl; //output: Hello my n

    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear up to newline
    return;
}
void paragraph2_3(){
    char p2[11], p3[11];
    cout<<"Enter 2sc pragraph: " << endl;
    cin.get(p2, 11); //input: Hello!(enter)
    cout << p2 << endl; //output: Hello

    cin.get(p3, 11);
    cout <<"3rd paragraph= "<< p3 << endl;

    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ensure buffer is clear
    cin.clear(); // Clear the error state of cin
    return;
}
void paragraph4(){
    char p4[30];
    cout<<"Enter 4th pragraph: " << endl;
    cin.getline(p4, 30);
    cout << p4 << endl;
    cout << cin.gcount() << "characters were read" << endl;

    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear up to newline
    cin.clear(); // Clear the error state of cin
    return;
}
void paragraph5(){
    string p5;
    cout << "Enter 5th paragraph (max 30 characters): " << endl;
    getline(cin, p5);

    if (p5.length() > 30) {
        cout << "Input too long, truncating to 30 characters." << endl;
        p5.resize(30); // Truncate the string
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear excess
    }

    cout <<"paragraph5 is: "<< p5 << endl;
    cout << p5.length() << " characters were read" << endl;
    return;
}
void paragraph6(){
    char ch;
    /*
    cout <<endl<< "enter a paragraph: "<< endl;
    while (cin >> ch){
        cout << ch;
    }
    input: Hello everyone ,output: Helloeveryone
    */

    cout <<"enter 6rd paragraph: "<< endl;
    while (cin.get(ch)){
        cout << ch;
    }
    //input: Hello everyone ,output: Hello everyone
    return;
}


int main() {

    // 1. get() only read the first 10 characters and put others in buffer
    paragraph1();


    /* 2. One important thing to note about get() is that it does not read in a newline
    character! This can cause some unexpected results */
    paragraph2_3();


    /* 3. Consequently, getline() like get() but reads the newline as well */
    //If you need to know how many character were extracted by the last call of getline(), use gcount() */
    paragraph4();


    /* 4.keep in mind: (overflow) getline() does not have a built-in mechanism to limit the number of characters read.
    Therefore, if the user enters more than you intend, the extra characters remain in the input buffer, affecting subsequent input operations.*/
    // A special version of getline() for std::string
    paragraph5();


    // 5. The extraction operator works with "formatted" data -- that is, it skips whitespace (blanks, tabs, and newlines)
    paragraph6();

    return 0;
}