/*Cpp programming
Problems with multiple inheritance
Virtual Inheritance (The Solution):
    Solves the Diamond Problem: Prevents multiple copies of a base class.
    Reduces Memory Usage: Avoids redundant storage.
    Simplifies Code: Eliminates the need for explicit scope resolution to disambiguate base class members.
*/
#include <iostream>

using namespace std;

class PoweredDevice {
public:
    PoweredDevice(int nPower) {
        cout << "Powered Device: " << nPower << endl;
    }
};

class Scanner : virtual public PoweredDevice {
public:
    Scanner(int nScanner, int nPower) : PoweredDevice(nPower) {
        cout << "Scanner: " << nScanner << endl;
    }
};

class Printer : virtual public PoweredDevice {
public:
    Printer(int nPrinter, int nPower) : PoweredDevice(nPower) {
        cout << "Printer: " << nPrinter << endl;
    }
};

class Copier : public Scanner, public Printer {
public: // The Copier constructor is responsible for creating PoweredDevice
    Copier(int nScanner, int nPrinter, int nPower)
        : PoweredDevice(nPower), Scanner(nScanner, nPower), Printer(nPrinter, nPower) {}
};

int main() {
    Copier cCopier(1, 2, 3);
    /*
    PoweredDevice: 3
    Scanner: 1
    Printer: 2
    */
    return 0;
}