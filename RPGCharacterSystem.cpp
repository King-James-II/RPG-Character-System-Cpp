#include <iostream>
#include <string>
using namespace std;

// Program: RPG Character System
// Description: Simulates a role-playing game character system using inheritance, polymorphism, and encapsulation.

// Base class representing a generic RPG character
class RPGCharacter {
protected:
    string name;
    int level;
    int health;

public:
    // Constructor
    RPGCharacter(const string& name, int level, int health)
        : name(name), level(level), health(health) {}

    // Virtual function to display character information
    virtual void displayInfo() const {
        cout << "Name: " << name << ", Level: " << level << ", Health: " << health << endl;
    }

    // Pure virtual function for attacking
    virtual void attack() const = 0; 
};

// Derived class representing a warlock character
class Warlock : public RPGCharacter {
private:
    int darkMagicPower;

public:
    // Constructor
    Warlock(const string& name, int level, int health, int darkMagicPower)
        : RPGCharacter(name, level, health), darkMagicPower(darkMagicPower) {}

    // Override base class's displayInfo function
    void displayInfo() const override {
        RPGCharacter::displayInfo();
        cout << "Class: Warlock, Dark Magic Power: " << darkMagicPower << endl;
    }

    // Override base class's attack function
    void attack() const override {
        cout << name << " casts a shadow bolt! Damage dealt: " << darkMagicPower << endl;
    }
};

// Derived class representing a druid character
class Druid : public RPGCharacter {
private:
    int natureMagicPower;

public:
    // Constructor
    Druid(const string& name, int level, int health, int natureMagicPower)
        : RPGCharacter(name, level, health), natureMagicPower(natureMagicPower) {}

    // Override base class's displayInfo function
    void displayInfo() const override {
        RPGCharacter::displayInfo();
        cout << "Class: Druid, Nature Magic Power: " << natureMagicPower << endl;
    }

    // Override base class's attack function
    void attack() const override {
        cout << name << " summons a thorn vine! Damage dealt: " << natureMagicPower << endl;
    }
};

int main() {
    // Create instances of warlock and druid characters
    Warlock warlock("Sargeras", 30, 250, 80);
    Druid druid("Malfurion", 35, 220, 60);

    // Display information about the characters and their attacks
    cout << "Warlock Information:" << endl;
    warlock.displayInfo();
    warlock.attack();
    cout << endl;

    cout << "Druid Information:" << endl;
    druid.displayInfo();
    druid.attack();
    cout << endl;

    return 0;
}
