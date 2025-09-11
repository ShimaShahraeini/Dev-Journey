/*Cpp programming
Operator Overloading 
Input/Output (<< and >>):
    These are friend functions because they need access to the private members of Point but are not member functions of the class itself.
Unary Minus (-):
    Overloads the unary minus operator, This is implemented as a member function, operating on the this object.
Logical Not (!):
    Overloads the logical not operator to check if a Point object is at the origin (0, 0, 0). This is also a member function.
the main focous in this code was overloading io stream operators and learn to overload operators as a member of a class not an friend.
*/


#include <iostream>
using namespace std;

class Point{
    double m_dX, m_dY, m_dZ;
public:
    Point(double dX=0.0, double dY=0.0, double dZ=0.0){
        m_dX = dX;
        m_dY = dY;
        m_dZ = dZ;
    }
    friend ostream& operator<<(ostream &out, Point &cPoint);
    friend istream& operator>> (istream &in, Point &cPoint);
    // overload negative (-) and logical not(!) with this
    Point operator-();
    bool operator! ();

    double GetX() {return m_dX;}
    double GetY() {return m_dY;}
    double GetZ() {return m_dZ;}
};
ostream& operator<< (ostream& out, Point &cPoint) {
    out << "(" << cPoint.m_dX << "," << cPoint.m_dY << "," << cPoint.m_dZ << ")" ;
    return out;
}
istream& operator>> (istream &in, Point &cPoint) { 
    cout << "enter your point: "<<endl;
    in >> cPoint.m_dX;
    in >> cPoint.m_dY;
    in >> cPoint.m_dZ;
    return in;
}

Point Point::operator-(){  //this->m_dX, this->m_dY, this->m_dZ)
    return Point(-m_dX, -m_dY, -m_dZ);
}
bool Point::operator!(){
    return (m_dX == 0.0 && m_dY == 0.0 && m_dZ == 0.0);
}

int main() {
    Point cPoint1, cPoint2;
    cin >> cPoint1>> cPoint2;
    cout << "your points:" << cPoint1 << " "<< cPoint2 << endl;
    cPoint1 = -cPoint1; 
    cPoint2 = -cPoint2;
    cout << "your points reversed :" << cPoint1 << " " << cPoint2 << endl;

    Point cPoint; //use default contructor to set to (0.0, 0.0, 0.0) 
    if(!cPoint){
        cout << "your new point is the orgin of coordinates! " << endl;
    }
    return 0;
}