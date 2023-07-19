#ifndef MONSTER_H
#define MONSTER_H

#include <iostream>
#include <vector>
#include "Character.hh"
#include "Player.hh"
using namespace std;

class Monster : public Character
{
public:
    Monster(string _name, int _level) : Character(_name, _level) {}

    friend ostream& operator<<(ostream& os, const Monster& monster);

    virtual void growl(){}

};

ostream& operator<<(ostream& os, const Monster& monster)
{
    os << "Monster name: " << monster.name << endl;
    os << "Level: " << monster.level << endl;
    os << "Health: " << monster.health << endl;
    os << "Attack: " << monster.attack << endl;
    os << "Defence: " << monster.defence << endl;
    return os;
}

#endif