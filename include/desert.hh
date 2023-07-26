#ifndef DESERT_H
#define DESERT_H

#include <iostream>
#include <vector>
#include "Player.hh"
#include "Monster.hh"
#include "battle.hh"
using namespace std;

class DesertMonsters : public Monster
{

public:
     DesertMonsters(string _name , int _level) : Monster(_name , _level ){}
};

void Desert(Player player)
{
    DesertMonsters monster1 = DesertMonsters("Sand Serpant", 19);
    DesertMonsters monster2 = DesertMonsters("Scorchwing" , 18);
    DesertMonsters monster3 = DesertMonsters("Oasis Guardian", 20);

    string choice;
    cout<<"The Desert of the Damned is a desolate and inhospitable wasteland, shrouded in an aura of ancient curses and malevolent energies. "<<endl<<" It is said to be a place of eternal punishment, where the souls of the wicked and damned are condemned to suffer in perpetuity."<<endl<<"";
    cout<<"The forest is the home to 3 monsters"<<endl;
    cout<<"Sand Serpant"<<endl<<"The Sand Serpent is a fearsome creature that lurks beneath the shifting dunes of the desert."<<endl<<" It has a long, sinuous body covered in golden scales that help it blend seamlessly with the sand.";
    cout<<"Scorchwing"<<endl<<"Scorchwing is a massive, fire-breathing bird that rules the skies over the scorching desert. "<<endl<<"Its feathers are a brilliant mix of red, orange, and gold, resembling the flames it commands.";
    cout<<"Oasis Guardian"<<endl<<"The Oasis Guardian is a colossal, humanoid creature made entirely of living sand and vegetation."<<endl<<"It stands as a silent protector of the desert's hidden oases, ensuring the delicate balance of life within these rare sanctuaries is preserved.";

    //player.battle(monster1);

    cout<<"You have 2 choices either you enter the overworld or the underworld of the desert what do you choose?"<<"Enter O for the overworld and U for the underworld: ";
    cin>>choice;
    if (choice=="O"){
        cout<<"So you have chosen to enter the overworld of the damned desert"<<player.get_name();
        string choice2;
        cout<<"You have encountered the Sand Serpent!"<<"Do you wish to battle or flee?"<<endl<<"Enter B if you wish to battle or Enter F if you wish to flee: ";
        cin>>choice2;
        if (choice2=="B"){
            cout<<monster1;
            battle(player, monster1);
            // continue game based on the outcome
            if(player.is_alive()){
                cout<<player.get_name()<<"continues on their journey......";
            }
        }
        else{
            cout<<"You fled from The Snd Serpant";
            cout<<"Continuing on the overworld";
            cout<<"You have encountered the Oasis Guardian"<<endl<<"Do you wish to battle or flee?";
            cout<<"Enter B for battle or F for flee";
            string choice3;
            cin>>choice3;
            if(choice3=="B"){
                cout<<monster3;
                battle(player, monster3);
                if(player.is_alive()){
                    cout<<player.get_name()<<"continues on their journey......";
                }
                
            // continue based on the outcome
            }

           
        }
        cout<<player.get_name()<<"Now that you have faced one of the gretest challenges the desert can offer can offer one final challenge awaits you!";
        cout<<"The"<<monster2<<"Awaits you as the final challenge!";
        cout<<"This battle is necessary, as it tests you to find out if you really are worthy of being hailed as the desert conqueror";
        battle(player,monster2);
        if(player.is_alive()){
            cout<<"You have won the title of The Desert Conqueror";
            cout<<"All hail"<<player.get_name();
        }

    }


    else if (choice=="U"){
        //underworld code by ZAyn
    }
 
}

#endif
