/*Cpp programming
C++ doesn't have a finally keyword like some other languages (e.g., Java, C#).
However, you can achieve the same behavior using a few common patterns:

1. Resource Acquisition Is Initialization (RAII)
    This is the most idiomatic and recommended way to handle cleanup in C++.
    RAII relies on the fact that destructors are automatically called when an object goes out of scope,
    regardless of whether an exception was thrown.(in this code we tryed this which is the prefferd method)
2. Lambda Expressions
    You can also use lambda expressions to define the cleanup action directly within the scope where it's needed:
    A lambda expression cleanup is created to define the cleanup action.
    The cleanup() function is called manually after the try-catch block.
3. Using a function
    You can also use a function to do the cleanup job.

Resource Acquisition Is Initialization (RAII):
    Automatic Cleanup: Resources are guaranteed to be released, even in the presence of exceptions.
    Simplified Code: You don't need to manually manage resource release in every possible exit path.
    Exception Safety: Prevents resource leaks and ensures consistent program state.
*/
#include <iostream>
#include <fstream>
#include <stdexcept>
#include <functional>
using namespace std;

class FileCloser {
public:
    FileCloser(ofstream& file) : file_(file) {}
    ~FileCloser() {
        if (file_.is_open()) {
            cout << "Closing file.\n";
            file_.close();
        }
    }
private:
    ofstream& file_;
};

void writeFile(const string& filename, const string& content) {
    ofstream file(filename);

    if (!file.is_open()) {
        throw runtime_error("Failed to open file.");
    }

    FileCloser closer(file); // RAII object for file closing

    try {
        cout << "Writing to file.\n";
        file << content;
        // Simulate an error
        if (content.find("error") != string::npos) { //It represents "no position", It's used as a sentinel value to indicate that the substring was not found.
            throw runtime_error("Error in content.");
        }
        cout << "File write successful.\n";
    } catch (const exception& e) {
        cerr << "Caught exception: " << e.what() << "\n";
    }

    // File is automatically closed when 'closer' goes out of scope.
}

int main() {
    writeFile("test.txt", "This is some content.");
    writeFile("error.txt", "This content contains an error.");
    return 0;
}