#ifndef CITADEL_H
#define CITADEL_H
using namespace std;
#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <map>
#include <limits>
#include <ctime>
#include <sstream>
#include <chrono>
#include <thread>
#include "Player.hh"
#include "Monster.hh"
#include "battle.hh"

int main() 

{
    Player player("test", 50);

    CitadelMonsters monster1 = CitadelMonsters("The Frostbite Wyvern", 23);
    CitadelMonsters monster2 = CitadelMonsters("The Frostbound Golem", 25);
    CitadelMonsters monster3 = CitadelMonsters("The Glacial Specter", 26);
    CitadelMonsters monster4 = CitadelMonsters("The Frost King", 27);


    cout << "Amidst the desolate landscape of an icy realm, the Frozen Citadel stands as a monument of both majestic grandeur and perilous trials. It rises like a frosty titan, piercing the wintry skies with its towering spires." << "The entire structure is encased in ice, reflecting the cold, unforgiving nature of this place." << endl;
    this_thread::sleep_for(chrono::seconds(3));
	cout << "Within the Frozen Citadel reside four fearsome ice monsters, each guarding a relic of unimaginable power." << endl;
    this_thread::sleep_for(chrono::seconds(3));
	cout << "The Frostbite Wyvern" << endl;
	cout << "This ancient ice dragon glides effortlessly through the frozen air, with scales as blue as a frozen lake. Its breath can freeze anything it touches, making it an awe-inspiring yet deadly creature." << endl;
	
	this_thread::sleep_for(chrono::seconds(3));
	cout << "The Frostbound Golem" << endl;
	cout << "A massive, hulking creature sculpted from enchanted ice crystals, the Frostbound Golem is a guardian of immense strength. It can summon blizzards and ice storms to thwart intruders." << endl;
	
	this_thread::sleep_for(chrono::seconds(3));
	cout << "The Glacial Specter" << endl;
	cout << "A haunting apparition that flickers amidst the snowstorms, the Glacial Specter is almost invisible, making it a cunning and elusive adversary. Its touch can freeze a soul, leaving victims trapped in an icy prison." << endl;
	
	this_thread::sleep_for(chrono::seconds(3));
	cout << "The Frost King" << endl;
	cout << "Ruling over the Frozen Citadel, the Frost King is an enigmatic and formidable sorcerer. With a crown of ice and a staff that controls blizzards, he wields the power to freeze even the bravest hero's heart." << endl;
	
	this_thread::sleep_for(chrono::seconds(3));
	cout << "Now,, you stand at the entrance of the Frozen Citadel, facing a crucial decision." << endl;
	cout << "One path leads deeper into the Citadel's frozen heart, where danger and great challenges await." << endl;
	cout << "The other path takes you to a desolate, icy valley, holding secrets of its own." << endl;

    string choice; 
    string choice2;
    cout << "Enter 'D' if you wish to brave the depths of the Frozen Citadel, or enter 'V' if you choose to venture into the icy valley." << endl;
    cin >> choice;

    array<CitadelMonsters, 4> citadelMonstersArray = { monster1, monster2, monster3, monster4 };

    if (choice == "D")
    {

        cout << "So you have chosen to enter the deep forest " << player.get_name() << endl;
        for (const auto& monster : citadelMonstersArray) {
            string choice2;
            cout << "You have encountered " << monster.get_name() << "! Do you wish to battle or flee?" << endl;
            cout << "Enter 'B' if you wish to battle or 'F' if you wish to flee: ";
            cin >> choice2;

            if (choice2 == "F" || choice2 == "f") {
                cout << "You chose to flee, " << player.get_name() << "." << endl;
                cout << "You have fled from " << monster.get_name() << "." << endl;
            }
            else if (choice2 == "B" || choice2 == "b") {
                
                
                battle(player, monster);
                if (player.is_alive())
                {
                    continue;
                }
            }
            else {
                cout << "Invalid choice. Please enter 'B' or 'F'." << endl;
            }
        }

        return 0;
    }
	
}
#endif