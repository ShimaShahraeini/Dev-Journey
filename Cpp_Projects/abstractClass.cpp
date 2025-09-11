/*Cpp programming
Abstract Classes and Pure Virtual Functions:
    Pure virtual functions have = 0 and are meant to be overridden by derived classes.
    Abstract classes are used to define interfaces and enforce a certain structure on derived classes.
Purpose of Abstract Classes:

    To define a common interface for a group of related classes.
    To prevent the creation of objects of the base class when it doesn't make sense to do so.
    To ensure that derived classes implement essential methods.

Virtual Destructor in parent class:
    This is crucial for proper cleanup when deleting derived class objects through base class pointers.
    Without a virtual destructor, only the Animal destructor would be called, potentially leading to memory leaks if the derived classes have their own allocated resources.
*/
#include <iostream>

using namespace std;

class Animal{
protected:
    string m_strName;
    Animal(string strName): m_strName(strName) {}
public:
    string GetName() { return m_strName; } 
    //virtual const char* Speak() { return "???"; } lets declares a pure virtual function. That makes Animal an abstract class.
    virtual const char* Speak() = 0;

    virtual ~Animal() { // Virtual destructor
        cout << "Animal destructor for " << m_strName << endl;
    }
};

class Cat: public Animal {
public:
    Cat(string strName): Animal(strName) {} 
    virtual const char* Speak() {return "Meow";}//you have to redefine this cuase parent class is abstract

    ~Cat() override { // Derived class destructor
        cout << "Cat destructor for " << m_strName << endl;
    }
};

class Dog: public Animal {
public:
    Dog(string strName): Animal(strName) {} 
    virtual const char* Speak() { return "Woof";}//you have to redefine this cuase parent class is abstract

    ~Dog() override { // Derived class destructor
        cout << "Dog destructor for " << m_strName << endl;
    }
};

void Report(Animal &rAnimal) {
    cout << rAnimal.GetName() <<" says "<< rAnimal.Speak() << endl;
    //Without the pure virtual function in the base class,
    // and only a regular virtual function, the base class could be instantiated,
    // and then the base class Speak function would be called.(the line commented and befor making it abstract)
}

int main() {
    //Animal cAnimal; //you cant make obj of animal cuase this class is abstract
    Cat cCat("Fred");
    Dog cDog("Garbo");
    Report(cCat); // Fred says Meow 
    Report(cDog); // Garbo says Woof
/*
Thecode bellow demonstrates how to create an array of pointers to Animal objects.
This is essential for working with polymorphic collections of objects.
This allows you to work with derived class objects through base class pointers.

    cout<<"____________"<<endl;

    Cat cFred("Fred"), cTyson("Tyson"), cZeke("Zeke");
    Dog cGarbo("Garbo"), cPooky("Pooky"), cTruffle("Truffle");
    // Set up an array of pointers to animals, and set these pointers to our Cat and Dog objects 
    Animal* apcAnimals[] = {&cFred, &cGarbo, &cPooky, &cTruffle, &cTyson, &cZeke};
    for (int i=0; i< 6; i++)
    cout << apcAnimals[i]->GetName() <<" says " << apcAnimals[i]->Speak() << endl;

    */
    return 0;
}