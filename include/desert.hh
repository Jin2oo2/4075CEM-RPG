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
    DesertMonsters monster1("Sand Serpent", 1);
    DesertMonsters monster2("Scorchwing", 2);
    DesertMonsters monster3("Oasis Guardian", 1);
    DesertMonsters monster4("Sand Wyrm", 2);
    DesertMonsters monster5("Sand Golem", 1);
    DesertMonsters monster6("Mirage Djinn", 2);

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
            result = battle(player, monster1);
            player.restore_health();

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
        result = battle(player, monster2);

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
        string choice;
    bool result;


    DesertMonsters monster4("Sand Wyrm", player.get_level());
    DesertMonsters monster5("Sand Golem", player.get_level());
    DesertMonsters monster6("Mirage Djinn", player.get_level()+1);
    std::vector<Monster> desertMonsters;


    desertMonsters.push_back(monster4);
    desertMonsters.push_back(monster5);
    desertMonsters.push_back(monster6);


for (const Monster& monster : desertMonsters) {
        std::cout << monster.get_name() << std::endl;
        if (monster.get_name() == "Sand Wrym")
        {
            cout << "These are the living dead. These creatures are risen from their graves by the Grim Reaper's dark magic." << "They prey on every living creature.";
        }
        if (monster.get_name() == "Sand Golem")
        {
            cout << "They are the creatures who can cast magic spells and curses. They have several dark magic powers." << endl << "Witches can easily detect unusual moments and would try to neutralise any trespasser.";
        }
        if (monster.get_name() == "Mirage Djinn")
        {
            cout << "Grim Reaper is the strongest power in this realm." << endl << "Grim Reaper not only has magical abilities, but also a scythe which can end any enemy in a single swing.";
        }
    }


    this_thread::sleep_for(chrono::seconds(3));
    cout << "Long ago, in a world where vast deserts spread under the scorching sun, an ancient civilization thrived. The people of this land mastered the art of harnessing the desert's power, constructing magnificent cities atop the sand dunes until it was struck by a calamity which ended the civilization and turned the region into ruins. Now, it's home to deadly underworld creatures." << endl;
    this_thread::sleep_for(chrono::seconds(3));
    cout << " Here, beneath the surface, exist strange and magnificent creatures that have adapted to the harsh environment." << endl;
    this_thread::sleep_for(chrono::seconds(3));
    cout << "The underworld desert is the home to 3 monsters:" << endl;
    this_thread::sleep_for(chrono::seconds(3));
    cout << "1. Sand Wrym: The Sand Wyrm is a massive, burrowing creature that roams the desert sands. It is serpent-like in appearance, with tough, scaled skin that helps protect it from the harsh environment. The Sand Wyrm is known for its powerful jaw and venomous fangs, making it a formidable opponent to face." << endl;
    this_thread::sleep_for(chrono::seconds(3));
    cout << "2. Sand Golem: The Cactus Golem is a creature born from ancient magic merging with the glistening sand from the underworld and it has a humanoid form. As this adversary is born from sand particles, it can camoflage really easily in it's surroundings making it a challenging adversary." << endl;
    this_thread::sleep_for(chrono::seconds(3));
    cout << "3. Mirage Djinn : The Mirage Djinn is a mystical and elusive creature that harnesses the power of illusions. It appears as a shimmering figure with shifting shapes, making it difficult to discern its true form. The Djinn thrives on confusion and tricks to outwit its opponents." << endl;
    cout << "So you have chosen to enter the underworld of the Desert of the Damned, " << player.get_name() << "." << endl;

        string choice2;
        cout << "You have encountered the Sand Golem !" << endl;
        cout << "Do you wish to battle or flee?" << endl;
        cout << "Enter 'B' if you wish to battle or 'F' if you wish to flee: ";
        cin >> choice2;

        if (choice2 == "B" || choice2 == "b")
        {
            result = battle(player, monster1);
            player.restore_health();

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
            cout << "You fled from the Sand Golem." << endl;
        }
        else
        {
            cout << "Invalid choice." << endl;
            return;
        }

        cout << "Continuing deeper into the desert underworld..." << endl;
        cout << "You have encountered the Sand Wrym!" << endl;
        cout << "Do you wish to battle or flee?" << endl;
        cout << "Enter 'B' for battle or 'F' for flee: ";
        string choice3;
        cin >> choice3;

        if (choice3 == "B" || choice3 == "b")
        {

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
            cout << "You fled from the Sand Wrym." << endl;
        }
        else
        {
            cout << "Invalid choice." << endl;
            return;
        }

        cout << "Continuing deeper into the desert underworld..." << endl;
        cout << "You have encountered Mirage Djinn, the final boss!" << endl;
        cout << "This battle will decide if you'll be able to escape the underworld and continue your adventure or stay trapped in the underworld forever." << endl;
        result = battle(player, monster6);

        if (!result)
        {
            cout << "You lost the game!" << endl;
            return;
        }

        cout << "You defeated the Mirage Djinn! After the legendary triumph, you can now continue to the next world!" << endl;
    }

   
    

    else
    {
        cout << "Invalid choice." << endl;
    }
}

#endif


