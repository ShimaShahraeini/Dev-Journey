/*Cpp programming
Inheritance is a powerful tool for code reuse and creating hierarchical relationships between classes.
Access specifiers control the visibility of class members.
    public: Members declared as public are accessible from anywhere.

    protected: Members declared as protected are accessible within the class itself, derived classes, and friend classes.
    When a class inherits from a base class in protected mode, the public members of the base class become protected members of the derived class.

    private (implicit): Members declared as private (or implicitly private) are only accessible within the class itself.
Constructors are used to initialize objects. and in multi-inheritance costructors are called from the first base till the last child.
and for distructor is opposite.
keep that in mind you are not allowed to give a value to the variablesof a class your inheriating from so we should call it's own constructor for initilizing it.
*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Person{
public:
    string m_strName;
    int m_nAge;
    bool m_blsMale;
    string GetName() { return m_strName; }
    int GetAge() { return m_nAge; }
    bool IsMale() { return m_blsMale; }
    Person(string strName = "", int nAge = 0, bool bisMale=false)
        : m_strName(strName), m_nAge(nAge), m_blsMale(bisMale)
        {}
};

// BaseballPlayer publicly inheriting Person
class BaseballPlayer : public Person {
    public:
        double m_dBattingAverage;
        int m_nHomeRuns;
        int m_nPlayerID; 
    
        BaseballPlayer(double dBattingAverage = 0.0, int nHomeRuns = 0, int playerID = 0, string strName = "", int nAge = 0, bool bisMale = false)
            : Person(strName, nAge, bisMale), m_dBattingAverage(dBattingAverage), m_nHomeRuns(nHomeRuns), m_nPlayerID(playerID) {}
    
        void printPlayerInfo() const {
            cout << "Player ID: " << m_nPlayerID << endl;
            cout << "Name: " << m_strName << endl;
            cout << "Age: " << m_nAge << endl;
            cout << "Male: " << (m_blsMale ? "Yes" : "No") << endl;
            cout << "Batting Average: " << m_dBattingAverage << endl;
            cout << "Home Runs: " << m_nHomeRuns << endl;
        }
    };

class Coach : protected Person {
public:
    vector<int> m_vPlayerIDs; // Vector to store player IDs
    
    Coach(string strName = "", int nAge = 0, bool bisMale = false)
        : Person(strName, nAge, bisMale) {}
    
    void addPlayer(int playerID) {
        m_vPlayerIDs.push_back(playerID);
    }
    
    void printCoachedPlayers() const {
        cout << "Coach: " << m_strName << endl;
        if (m_vPlayerIDs.empty()) {
            cout << "No players coached." << endl;
            return;
        }

        cout << "Coached Players IDs: ";
        for (int id : m_vPlayerIDs) {
            cout << id << " ";
        }
        cout << endl;
    }

    // Example of using protected members within Coach
    void printCoachInfo() const {
        cout << "Coach Name: " << m_strName << endl; // Accessible because they are protected in coach
        cout << "Coach Age: " << m_nAge << endl;
        cout << "Coach Male: " << (m_blsMale ? "Yes" : "No") << endl;
    }
};

int main(){
    // Create Baseball Players
    BaseballPlayer player1(0.300, 20, 1, "Joe", 25, true);
    BaseballPlayer player2(0.280, 15, 2, "Alice", 23, false);
    BaseballPlayer player3(0.250, 10, 3, "Bob", 28, true);

    // Create a Coach
    Coach coach("Mike", 40, true);

    // Assign Players to Coach
    coach.addPlayer(player1.m_nPlayerID);
    coach.addPlayer(player2.m_nPlayerID);

    // Print Player Information
    player1.printPlayerInfo();
    cout << endl;
    player2.printPlayerInfo();
    cout << endl;
    player3.printPlayerInfo();
    cout << endl;

    // Print Coach Information
    coach.printCoachedPlayers();

    coach.printCoachInfo(); // added this to show the protected variables are usable inside of the coach class.

    // The following lines would cause errors because the Person members are now protected in Coach:
    // cout << coach.GetName() << endl;
    // cout << coach.GetAge() << endl;

    return 0;
}