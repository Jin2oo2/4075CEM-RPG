using namespace std;
#include <string> 

class CitadelMonsters : public Monster
{

public:
     CitadelMonsters(string _name , int _level) : Monster(_name , _level ){}
};

void Citadel(Player player)
{
    CitadelMonsters monster1 = CitadelMonsters("The Frostbite Wyvern", 23);
    CitadelMonsters monster2 = CitadelMonsters("The Frostbound Golem" , 25);
    CitadelMonsters monster3 = CitadelMonsters("The Glacial Specter", 26);
    CitadelMonsters monster4 = CitadelMonsters("The Frost King", 27);

    string choice;
   cout << "Amidst the desolate landscape of an icy realm, the Frozen Citadel stands as a monument of both majestic grandeur and perilous trials. It rises like a frosty titan, piercing the wintry skies with its towering spires." 
   <<"The entire structure is encased in ice, reflecting the cold, unforgiving nature of this place." << endl;
cout << "Within the Frozen Citadel reside four fearsome ice monsters, each guarding a relic of unimaginable power." << endl;
cout << "The Frostbite Wyvern" << endl;
cout << "This ancient ice dragon glides effortlessly through the frozen air, with scales as blue as a frozen lake. Its breath can freeze anything it touches, making it an awe-inspiring yet deadly creature." << endl;
cout << "The Frostbound Golem" << endl;
cout << "A massive, hulking creature sculpted from enchanted ice crystals, the Frostbound Golem is a guardian of immense strength. It can summon blizzards and ice storms to thwart intruders." << endl;
cout << "The Glacial Specter" << endl;
cout << "A haunting apparition that flickers amidst the snowstorms, the Glacial Specter is almost invisible, making it a cunning and elusive adversary. Its touch can freeze a soul, leaving victims trapped in an icy prison." << endl;
cout << "The Frost King" << endl;
cout << "Ruling over the Frozen Citadel, the Frost King is an enigmatic and formidable sorcerer. With a crown of ice and a staff that controls blizzards, he wields the power to freeze even the bravest hero's heart." << endl;
cout << "Now, " << player.get_name() << ", you stand at the entrance of the Frozen Citadel, facing a crucial decision." << endl;
cout << "One path leads deeper into the Citadel's frozen heart, where danger and great challenges await." << endl;
cout << "The other path takes you to a desolate, icy valley, holding secrets of its own." << endl;
cout << "Enter 'D' if you wish to brave the depths of the Frozen Citadel, or enter 'V' if you choose to venture into the icy valley." << endl;

    if (choice=="D")
    {
        
        
        cout<<"So you have chosen to enter the Icy Citadel"<<player.get_name();
        string choice2;
        cout<<"You have encountered The Frostbound Golem!"<<"Do you wish to battle or flee?"<<endl<<"Enter B if you wish to battle or Enter F if you wish to flee";
        cin>>choice2;
        if (choice2=="B"){
            cout<<monster1;
            battle(player, monster2);
            // continue game based on the outcome
        }
        else{
            cout<<"You fled from Shadow Thorn";
        }
        cout<<"Continuing down the Icy Citadel";
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

