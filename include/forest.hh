#ifndef FOREST_H
#define FOREST_H

#include <iostream>
#include <vector>
#include "Player.hh"
#include "Monster.hh"
#include "battle.hh"
using namespace std;

class ForestMonsters : public Monster
{

public:
     ForestMonsters(string _name , int _level) : Monster(_name , _level ){}
};

void forest(Player player)
{
    ForestMonsters monster1 = ForestMonsters("Verdant Viper", 19);
    ForestMonsters monster2 = ForestMonsters("Shadow thorn" , 18);
    ForestMonsters monster3 = ForestMonsters("Grive Goliath", 20);

    string choice;
    cout<<"Nestled in the heart of a forgotten realm, the Enchanted Forest is a place of ominous beauty and unyielding danger. It stretches far and wide, an endless expanse of towering ancient trees, their gnarled branches twisted like the skeletal fingers of malevolent spirits. A perpetual mist hangs in the air, casting an eerie, ethereal glow over the forest floor and obscuring any sense of direction."<<endl;
    cout<<"The forest is the home to 3 monsters"<<endl;
    cout<<"Verdant Viper"<<endl<<"This forest-dwelling monster resembles a venomous snake, but it has emerald green scales and camouflages itself perfectly among the foliage."<<endl<<"It strikes swiftly and silently, making it a feared predator in the woods.";
    cout<<"Shadow Thorn"<<endl<<"A sinister creature lurking in the darkest corners of the forest, with gnarled limbs and thorns covering its body."<<endl<<"It preys on unsuspecting travelers, using the shadows to hide and strike from the darkness.";
    cout<<"Grove Goliath"<<endl<<"A massive, ancient creature that dwells deep within the heart of the forest. Covered in moss and leaves, this gentle giant is usually peaceful but can become fiercely protective of its territory if threatened."<<endl<<"Its sheer size and power make it a force to be reckoned with.";

    //player.battle(monster1);

    cout<<"There are choices in front of you"<<player.get_name()<<"One lead to the deep forest"<<endl<<"While the other leads to a clearing"<<endl<<"Enter L if you wish to enter the deep forest or enter R if you wish to enter the valley";
    cin>>choice;
    if (choice=="L"){
        cout<<"So you have chosen to enter the deep forest"<<player.get_name();
        string choice2;
        cout<<"You have encountered the Shadow Thorn!"<<"Do you wish to battle or flee?"<<endl<<"Enter B if you wish to battle or Enter F if you wish to flee";
        cin>>choice2;
        if (choice2=="B"){
            cout<<monster1;
            battle(player, monster2);
            // continue game based on the outcome
        }
        else{
            cout<<"You fled from Shadow Thorn";
        }
        cout<<"Continuing down the deep forest";
        cout<<"You have encountered the Grive Goliath"<<endl<<"Do you wish to battle or flee?";
        cout<<"Enter B for battle or F for flee";
        string choice3;
        cin>>choice3;
        if(choice3=="B"){
            cout<<monster3;
            battle(player, monster3);
            // continue based on the outcome
        }
        else{
            cout<<"You chose to flee"<<player.get_name();
        }

        
    }
}

#endif

