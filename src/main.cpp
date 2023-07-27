#include <iostream>
#include <array>
#include <stdlib.h>
#include "../include/Player.hh"
#include "../include/Monster.hh"
#include "../include/forest.hh"
#include "../include/desert.hh"
using namespace std;

bool is_valid_path(char c)
{
    return (c == 's' || c == 'S' || c == 'f' || c == 'F' || c == 'd' || c == 'D' || c == 'c' || c == 'C');
}

void start_game()
{
    // first introduction of the game
    cout << endl;
    cout << "In the magical realm of Eldoria, our brave hero sets off on an epic quest to find treasure hidden in four different areas. \nAlong the way, they must face fierce monsters in thrilling battles to claim their ultimate prize..." << endl;
    cout << endl;
    
    // user initialization 
    string user_name;
    cout << "Type your name: ";
    cin >> user_name;
    Player player = Player(user_name, 1);;
    if (user_name == "invincible" || user_name == "Invincible") 
    {
        player.level_up(99);
    }

    cout << player << endl;
    cout << endl;

    // Player choose which path to go 
    cout << "Your journey begins..." << endl;
    cout << "There are 4 different paths to relics in front of you. \nWhich path will you choose: [F] for the Enchanted Forest, [S] for the Labyrinth of Shadows, [D] for the scorching Desert of the Ancients, and [C] for the Frozen Citadel." << endl;
    cout << "Path: ";
    char path;
    cin >> path;

    while (!is_valid_path(path))
    {
        cout << "The path you typed doesn't exist. Please type f, s, d, or c." << endl;
        cout << "Path: ";
        cin >> path;
    }

    // from here the areas branch off using if statement
    if (path == 'f' || path == 'F')
    {
        cout << "You are going to the Enchanted Forest" << endl;
        forest(player);
    }
    else if (path == 's' || path == 'S')
    {
        cout << "You are going to the Labyrinth of Shadows" << endl;
    }
    else if (path == 'd' || path == 'D')
    {
        cout << "You are going to the scorching Desert of the Damned" << endl;
        Desert(player);
    }
    else if (path == 'c' || path == 'C')
    {
        cout << "You are going to the Frozen Citadel" << endl;
    }
    

}

int main()
{   
    start_game();

    return 0;
}
