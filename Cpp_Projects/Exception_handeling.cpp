/*Cpp programming
to see how exeptions work and use try-catch
*/
#include <iostream>
using namespace std;

void Last() {
    cout << "Start Last" << endl;
    cout << "4 throwing int"; 
    throw -1;
    cout << "End Last" << endl;
}

void Third(){
    cout << "Start Third" << endl; 
    Last();
    cout<<"End Third" << endl;
}
    
void Second(){
    cout << "Start Second" << endl;
    try {
        Third();
    }
    catch(double) {
        cerr << "2 caught double";
    }
    cout << "End Second" << endl;
}
void First() {
    cout << "Start First" << endl;
    try {
        Second();
    } catch (int) {
        cerr << "1 caught int\n";
    } catch (double) {    cerr << "1 caught double\n";
        cerr << "1 caught double\n";
    }
    cout << "End First" << endl;
}

int main() {
    cout << "Start main" << endl;
    try {
        First();
    }
    catch (int){
        cerr << "main caught int\n";
    }
    cout << "End main" << endl;
}

/*
OUTPUT:
Start main
Start First
Start Second
Start Third
Start Last
4 throwing int1 caught int
End First
End main
*/