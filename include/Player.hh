#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <vector>
#include "Character.hh"
#include "Monster.hh"
using namespace std;

class Player : public Character
{
private:
    int experience;
    vector<string> items;

public:
    Player(string _name, int _level) : Character(_name, _level)
    {
        experience = 0;
    }

    friend ostream& operator<<(ostream& os, const Player& player);

    void level_up(int amount)
    {
        level += amount;
        health += 15*amount;
        attack += 5*amount;
        defence += 5*amount;

        cout << "Player leveled up to " << level << "!" << endl;
        cout << endl;
    }

    void gain_experience(int amount)
    {
        experience += amount;
        if (experience >= 100)
        {
            int level_up_amount = experience / 100;
            experience = 0;
            level_up(level_up_amount);
        }
    }

};

// Output player class
ostream& operator<<(ostream& os, const Player& player)
{
    os << "Player name: " << player.name << endl;
    os << "Level: " << player.level << endl;
    os << "Health: " << player.health << endl;
    os << "Attack: " << player.attack << endl;
    os << "Defence: " << player.defence << endl;
    os << "Experience: " << player.experience << endl;
    return os;
}

#endif