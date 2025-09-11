/*Cpp programming
Problems with multiple inheritance
Multiple inheritance, where a class derives from more than one base class, can introduce several challenges, most notably the "diamond problem." 
Virtual inheritance is a solution designed to address this. which you can see the code in virtual_inheritance.cpp file*/
#include <iostream>

using namespace std;

class USBDevice {
    long m_IID;
public:
    USBDevice(long ID): m_IID(ID) {}
    long GetID(){return m_IID; }
};

class NetworkDevice {
    long m_IID;
public:
    NetworkDevice(long ID): m_IID(ID){}
    long GetID(){return m_IID;}
};

class WirelessAdaptor: public USBDevice, public NetworkDevice {
public:
    WirelessAdaptor(long IUSBID, long INetworkID)
    : USBDevice (IUSBID), NetworkDevice(INetworkID){}
};
int main(){
        
    WirelessAdaptor c54G(5442, 181742);
    cout << c54G.GetID(); // Which GetID() do we call
    /* this function call is ambiguous, and you will receive a compiler error if you try to compile it*/
    cout << c54G.USBDevice::GetID() << endl;

    return 0;
}