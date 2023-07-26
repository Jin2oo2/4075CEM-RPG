#ifndef FOREST_H
#define FOREST_H

#include <chrono>
#include <thread>
#include <iostream>
#include <vector>
#include "Player.hh"
#include "Monster.hh"
#include "battle.hh"

using namespace std;

class ForestMonsters : public Monster
{
public:
    ForestMonsters(string _name, int _level) : Monster(_name, _level) {}
};

void forest(Player player)
{
    ForestMonsters monster1("Verdant Viper", 2);
    ForestMonsters monster2("Shadow thorn", 1);
    ForestMonsters monster3("Grive Goliath", 1);

    string choice;
    bool result = false;
    this_thread::sleep_for(chrono::seconds(2));
    cout << "Nestled in the heart of a forgotten realm, the Enchanted Forest is a place of ominous beauty and unyielding danger. It stretches far and wide, an endless expanse of towering ancient trees, their gnarled branches twisted like the skeletal fingers of malevolent spirits. A perpetual mist hangs in the air, casting an eerie, ethereal glow over the forest floor and obscuring any sense of direction." << endl;
    this_thread::sleep_for(chrono::seconds(2));
    cout << "The forest is the home to 3 monsters:" << endl;
    this_thread::sleep_for(chrono::seconds(2));
    cout << "1. Verdant Viper: This forest-dwelling monster resembles a venomous snake, but it has emerald green scales and camouflages itself perfectly among the foliage. It strikes swiftly and silently, making it a feared predator in the woods." << endl;
    this_thread::sleep_for(chrono::seconds(2));
    cout << "2. Shadow Thorn: A sinister creature lurking in the darkest corners of the forest, with gnarled limbs and thorns covering its body. It preys on unsuspecting travelers, using the shadows to hide and strike from the darkness." << endl;
    this_thread::sleep_for(chrono::seconds(2));
    cout << "3. Grove Goliath: A massive, ancient creature that dwells deep within the heart of the forest. Covered in moss and leaves, this gentle giant is usually peaceful but can become fiercely protective of its territory if threatened. Its sheer size and power make it a force to be reckoned with." << endl;

    cout << "Enter 'E' to enter the enchanted forest: ";
    cin >> choice;

    if (choice == "E" || choice == "e")
    {
        cout << "So you have chosen to enter the deep forest, " << player.get_name() << "." << endl;

        string choice2;
        cout << "You have encountered the Shadow Thorn!" << endl;
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
            player.restore_health();
        }
        else if (choice2 == "F" || choice2 == "f")
        {
            cout << "You fled from Shadow Thorn." << endl;
        }
        else
        {
            cout << "Invalid choice." << endl;
            return;
        }

        cout << "Continuing deeper into the forest..." << endl;
        cout << "You have encountered the Grove Goliath!" << endl;
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
            player.restore_health();
        }
        else if (choice3 == "F" || choice3 == "f")
        {
            cout << "You fled from Grove Goliath." << endl;
        }
        else
        {
            cout << "Invalid choice." << endl;
            return;
        }

        cout << "Continuing deeper into the forest..." << endl;
        cout << "You have encountered the Verdant Viper, the final challenge!" << endl;
        cout << "This battle is necessary, as it tests you to find out if you really are worthy of being hailed as the Enchanted Conqueror." << endl;
        result = battle(player, monster1);

        if (!result)
        {
            cout << "You lost the game!" << endl;
            return;
        }

        cout << "You won the title of The Enchanted Conqueror!" << endl;
        cout << "All hail " << player.get_name() << "!" << endl;
    }
    else
    {
        cout << "Invalid choice." << endl;
    }
}

#endif

