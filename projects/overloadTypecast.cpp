/*Cpp programming
trying overloading typecast in here we overload int() to typecast our Cent class to int
and then for converting doller to Cent we typecast Dollers class to Cent class
*/
#include <iostream>
using namespace std;

class Cents {
    int m_nCents;
public:
    Cents(int nCents=0) {
        m_nCents = nCents;
    }
    int GetCents() { return m_nCents; }
    void SetCents(int nCents) {m_nCents=nCents; }
    //overload int cast
    operator int(){return m_nCents; } //class to int typecast
};
void PrintInt(int nValue)
{
    cout << nValue<<endl;
}

class Dollars {
    int m_nDollars;
public:

    Dollars(int nDollars=0) { m_nDollars = nDollars; }
    //Allow us to convert Dollars into Cents 
    operator Cents() { return Cents(m_nDollars * 100); }//class to class typecast
};
    
void PrintCents(Cents cCents){
    cout << cCents.GetCents()<<endl;
} 

int main(){
    Cents cCents(7);
    PrintInt(cCents.GetCents());//7

    //our geal
    Cents Cents(7);
    PrintInt(cCents); // 7
    /*line below equals to next 2 line 
        int nCents = static_cast<int>(cCents); 
        PrintInt(nCents); print 7
    */

    Dollars cDollars(9);
    // cDollars will be cast to a Cents PrintCents(cDollars);
    PrintCents(cDollars);
    return 0;
}