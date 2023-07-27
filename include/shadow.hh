#ifndef SHADOW_H
#define SHADOW_H

#include <iostream>
#include <vector>
#include "Player.hh"
#include "Monster.hh"
#include "battle.hh"
using namespace std;

class ShadowMonsters : public Monster
{

public:
    ShadowMonsters(string _name, int _level) : Monster(_name, _level) {}
};

void shadow(Player player)
{
    ShadowMonsters monster1 = ShadowMonsters("Skeleton", player.get_level());
    ShadowMonsters monster2 = ShadowMonsters("Witch", player.get_level());
    ShadowMonsters monster3 = ShadowMonsters("Grim Reaper", player.get_level() + 1);


    std::vector<Monster> shadowMonstersVector;


    shadowMonstersVector.push_back(monster1);
    shadowMonstersVector.push_back(monster2);
    shadowMonstersVector.push_back(monster3);

    string choice;


    for (const Monster& monster : shadowMonstersVector) {
        std::cout << monster.get_name() << std::endl;
        if (monster.get_name() == "Skeleton")
        {
            cout << "These are the living dead. These creatures are risen from their graves by the Grim Reaper's dark magic." << "They prey on every living creature.";
        }
        if (monster.get_name() == "Witch")
        {
            cout << "They are the creatures who can cast magic spells and curses. They have several dark magic powers." << endl << "Witches can easily detect unusual moments and would try to neutralise any trespasser.";
        }
        if (monster.get_name() == "Grim Reaper")
        {
            cout << "Grim Reaper is the strongest power in this realm." << endl << "Grim Reaper not only has magical abilities, but also a scythe which can end any enemy in a single swing.";
        }
    }


    cout << "In a faraway land lies a mysterious and dark realm named Shadow. This region is forever engulfed in darkness, and its inhabitants live beneath an ever-present silver moon that never disappears. Once a prosperous kingdom, this land has fallen under an ancient curse inflicted by the malevolent Grim Reaper, leaving it trapped in eternal twilight." << endl;
    cout << "The realm of shadow is inhabited by 3 different creatures" << endl;
    cout << "Skeleton" << endl << "These are the living dead. These creatures are risen from their graves by the Grim Reaper's dark magic." << "They prey on every living creature.";
    cout << "Witch" << endl << "They are the creatures who can cast magic spells and curses. They have several dark magic powers." << endl << "Witches can easily detect unusual moments and would try to neutralise any trespasser.";
    cout << "Grim Reaper" << endl << "Grim Reaper is the strongest power in this realm." << endl << "Grim Reaper not only has magical abilities, but also a scythe which can end any enemy in a single swing.";

    //player.battle(monster1);

    cout << "You're presented with 2 choices." << player.get_name() << "Enter the Shadow realm" << endl << "Enter the graveyard" << endl << "Enter L if you wish to enter the Shadow Realm or enter R if you wish to enter the graveyard";
    cin >> choice;
    if (choice == "L") {
        cout << "You're brave to enter the shadow realm! Beware! Only the chosen one would be able to go through this realm alive!" << player.get_name();
        string choice2;
        cout << "Oh no! There's a witch in sight!" << "Are you brave enough to face her or you have a different strategy?" << endl << "Enter B if you wish to battle or Enter F if you wish to escape";
        cin >> choice2;
        if (choice2 == "B") {
            cout << monster1;
            battle(player, monster2);
            // continue game based on the outcome
        }
        else {
            cout << "You chose to flee for now.";
        }
        cout << "Continuing down the deep forest";
        cout << "You have encountered the Grive Goliath" << endl << "Do you wish to battle or flee?";
        cout << "Enter B for battle or F for flee";
        string choice3;
        cin >> choice3;
        if (choice3 == "B") {
            cout << monster3;
            battle(player, monster3);
            // continue based on the outcome
        }
        else {
            cout << "You chose to flee" << player.get_name();
        }


    }
}

#endif

