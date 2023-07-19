#ifndef CHARACTER_H
#define CHARACTER_H

#include <iostream>
#include <vector>
using namespace std;

class Character
{
protected:
    string name;
    int level, health, attack, defence;

public:
    Character(string _name, int _level)
    {
        name = _name;
        level = _level;
        health = 100 + ((_level - 1) * 15);
        attack = 35 + ((_level - 1) * 5);
        defence = 5 + ((_level - 1) * 5);
    }

    friend ostream& operator<<(ostream& os, const Character& character);

    // These are all getter and setter
    string get_name() const
    {
        return name;
    }

    void set_name(string new_name)
    {
        name = new_name;
    }

    int get_health() const
    {
        return health;
    }

    void set_health(int new_health)
    {
        health = new_health;
    }

    int get_level() const
    {
        return level;
    }

    void set_level(int new_level)
    {
        level = new_level;
    }

    int get_attack() const
    {
        return attack;
    }

    void set_attack(int new_attack)
    {
        attack = new_attack;
    }

    int get_defence() const
    {
        return defence;
    }

    void set_defence(int new_defence)
    {
        defence = new_defence;
    }


    bool is_alive()
    {
        return health > 0;
    }

    void attack_enemy(Character &enemy)
    {
        int damage = attack - enemy.get_defence();
        if (damage < 0) damage = 1;

        int new_health = enemy.get_health() - damage;
        enemy.set_health(new_health);

        cout << name << " attacked " << enemy.get_name() << endl;
    }
    
};

// Output player class
ostream& operator<<(ostream& os, const Character& character)
{
    os << "Character name: " << character.name << endl;
    os << "Level: " << character.level << endl;
    os << "Health: " << character.health << endl;
    os << "Attack: " << character.attack << endl;
    os << "Defence: " << character.defence << endl;
    return os;
}

#endif