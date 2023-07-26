#ifndef DESERT_H
#define DESERT_H

#include <chrono>
#include <thread>
#include <iostream>
#include <vector>
#include "Player.hh"
#include "Monster.hh"
#include "battle.hh"
using namespace std;

class DesertMonsters : public Monster
{
public:
    DesertMonsters(string _name, int _level) : Monster(_name, _level) {}
};

void Desert(Player player)
{
    DesertMonsters monster1("Sand Serpent", 19);
    DesertMonsters monster2("Scorchwing", 18);
    DesertMonsters monster3("Oasis Guardian", 20);

    string choice;
    bool result;
    this_thread::sleep_for(chrono::seconds(3));
    cout << "The Desert of the Damned is a desolate and inhospitable wasteland, shrouded in an aura of ancient curses and malevolent energies." << endl;
    this_thread::sleep_for(chrono::seconds(3));
    cout << "It is said to be a place of eternal punishment, where the souls of the wicked and damned are condemned to suffer in perpetuity." << endl;
    this_thread::sleep_for(chrono::seconds(3));
    cout << "The desert is the home to 3 monsters:" << endl;
    this_thread::sleep_for(chrono::seconds(3));
    cout << "1. Sand Serpent: The Sand Serpent is a fearsome creature that lurks beneath the shifting dunes of the desert. It has a long, sinuous body covered in golden scales that help it blend seamlessly with the sand." << endl;
    this_thread::sleep_for(chrono::seconds(3));
    cout << "2. Scorchwing: Scorchwing is a massive, fire-breathing bird that rules the skies over the scorching desert. Its feathers are a brilliant mix of red, orange, and gold, resembling the flames it commands." << endl;
    this_thread::sleep_for(chrono::seconds(3));
    cout << "3. Oasis Guardian: The Oasis Guardian is a colossal, humanoid creature made entirely of living sand and vegetation. It stands as a silent protector of the desert's hidden oases, ensuring the delicate balance of life within these rare sanctuaries is preserved." << endl;

    cout << "You have 2 choices, either you enter the overworld or the underworld of the desert. What do you choose?" << endl;
    cout << "Enter 'O' for the overworld and 'U' for the underworld: ";
    cin >> choice;

    if (choice == "O" || choice == "o")
    {
        cout << "So you have chosen to enter the overworld of the Desert of the Damned, " << player.get_name() << "." << endl;

        string choice2;
        cout << "You have encountered the Sand Serpent!" << endl;
        cout << "Do you wish to battle or flee?" << endl;
        cout << "Enter 'B' if you wish to battle or 'F' if you wish to flee: ";
        cin >> choice2;

        if (choice2 == "B" || choice2 == "b")
        {
            cout << monster2 << endl;
            result = battle(player, monster2);

            if (!result)
            {
                cout << "You lost." << endl;
                return;
            }

            cout << "You won!" << endl;
            player.gain_experience(50);
        }
        else if (choice2 == "F" || choice2 == "f")
        {
            cout << "You fled from the Sand Serpent." << endl;
        }
        else
        {
            cout << "Invalid choice." << endl;
            return;
        }

        cout << "Continuing deeper into the desert overworld..." << endl;
        cout << "You have encountered the Oasis Guardian!" << endl;
        cout << "Do you wish to battle or flee?" << endl;
        cout << "Enter 'B' for battle or 'F' for flee: ";
        string choice3;
        cin >> choice3;

        if (choice3 == "B" || choice3 == "b")
        {
            cout << monster3 << endl;
            result = battle(player, monster3);

            if (!result)
            {
                cout << "You lost." << endl;
                return;
            }

            cout << "You won!" << endl;
            player.gain_experience(50);
        }
        else if (choice3 == "F" || choice3 == "f")
        {
            cout << "You fled from the Oasis Guardian." << endl;
        }
        else
        {
            cout << "Invalid choice." << endl;
            return;
        }

        cout << "Continuing deeper into the desert overworld..." << endl;
        cout << "You have encountered Scorchwing, the final challenge!" << endl;
        cout << "This battle is necessary, as it tests you to find out if you really are worthy of being hailed as the Desert King." << endl;
        result = battle(player, monster1);

        if (!result)
        {
            cout << "You lost the game!" << endl;
            return;
        }

        cout << "You won the title of The Desert King!" << endl;
        cout << "All hail " << player.get_name() << "!" << endl;
    }
    else if (choice == "U" || choice == "u")
    {
        // Code for the underworld of the desert goes here (by zayn)
    }
    else
    {
        cout << "Invalid choice." << endl;
    }
}

#endif


