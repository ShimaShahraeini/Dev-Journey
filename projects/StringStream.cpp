/*Cpp programming
dev journey: 
A stream is a continuous flow of data, whether it's characters, bytes, or other units of information.
Abstraction: A stream hides the details of how data is actually read or written.
You interact with the stream using a consistent set of operations, without needing to know the specifics of the data source or destination. 
Stream classes for strings:
- One of the primary uses of string streams is to buffer output for display at a later time, or to process input line-by-line
. std::stringstream is a versatile tool for string manipulation.
. You can use familiar input/output operators (<< and >>) with stringstreams.
. Clearing the buffer and error states is essential for reusing stringstreams.
. Stringstreams can be used to convert strings into other data types.
. Stringstreams act just like cin, in that white space is the deliminator.
Stream states (Flags):
Operations on streams may fail for various reasons. Whenever an operation fails, further operations on the stream are suspended. It is possible to inspect, set and possibly clear the condition state of streams, allowing a program to repair the problem rather than having to abort.
- ios::goodbit -> Everything is okay (none of the other three condition flags)
- ios::badbit -> Some kind of fatal error occurred (eg, the program tried read past the end of a file) 
- ioseofbit -> The stream has reached the end of a file
- failbit -> A non-fatal error occurred (eg, the user entered letters when the program was expecting an integer)
*/

#include <iostream>
#include <sstream>
#include <string> // Include string header
using namespace std;

void state() {
    cout << cin.bad() << cin.fail() << cin.eof() << cin.good() << '\n';
}

int main() {
    std::stringstream os; 
    os << "en garde!" << endl; // set the stringstream buffer to "en garde"
    os.str("en garde!"); // set the stringstream buffer to "en garde"
    cout << os.str()<<endl;

    os.str(""); // erase the buffer
    os.str(std::string()); // erase the buffer
    os.clear(); // erase the buffer

    os << "12345 67.89"; // insert a string of numbers into the stream
    string strValue;
    os >> strValue;
    string strValue2;
    os >> strValue2;
    cout << strValue << "-" << strValue2 << endl;

    /*
    int nValue;
    double dValue:
    os >> nValue >> dValue;*/
    //12345-67.89

    string line;
    int x;
    cin >> x; // shima(not an int)
    state(); // 0100

    cin.clear();/* Whenever an operation fails, further operations on the stream are suspended(if you comment this line, you'll see) */

    cin >> line; //shima
    state(); //0001

    getline(cin, line); //to prove that getline actully get the Enter
    state(); //0001

    return 0;
}