#include <iostream>
#include <array>
#include <stdlib.h>
#include "../include/Player.hh"
#include "../include/Monster.hh"
using namespace std;

bool is_valid_path(char c)
{
    return (c == 's' || c == 'S' || c == 'f' || c == 'F' || c == 'd' || c == 'D' || c == 'c' || c == 'C');
}

// Used to battle when player encounters a monster
void battle(Player player, Monster monster)
{
    cout << "You are battling against\n" << monster << endl;

    int p_prev_health = player.get_health();
    int m_prev_health = monster.get_health();

    int p_normal_defence = player.get_defence();
    int m_normal_defence = monster.get_defence();

    bool player_turn = true;
    while (player.is_alive() && monster.is_alive())
    {
        if (player_turn)
        {
            // player choose to attack or defend
            cout << "It is your turn. Choose [A] for attacking, or [D] for defending" << endl;
            char choice;
            cin >> choice;
            if (choice == 'a' || choice == 'A') player.attack_enemy(monster);
            else if (choice == 'd' || choice == 'D')
            {
                cout << "Player is defending" << endl;
                int tmp_defence = player.get_defence() + (3*player.get_level());
                player.set_defence(tmp_defence);
                cout << "Player's defence increased from " << p_normal_defence << " to " << player.get_defence() << endl;
            }

            // Reset monster's health back to normal after player's turn
            monster.set_defence(m_normal_defence);
        }
        else
        {
            // Monster will randomly choose to attack or defence
            array<char, 3> choices = {'a', 'a', 'd'};
            int pos = rand() % 3;
            char choice = choices[pos];
            if (choice == 'a') monster.attack_enemy(player);
            else if (choice == 'd')
            {
                cout << "Monster is defending." << endl;
                int tmp_defence = monster.get_defence() + (3*monster.get_level());
                monster.set_defence(tmp_defence);
                cout << "Monster's defence increased from " << m_normal_defence << " to " << monster.get_defence() << endl;
            }

            // Reset player's health back to normal after monster's turn
            player.set_defence(p_normal_defence);
        }

        cout << "Player's current health: " << p_prev_health << " -> " << player.get_health() << endl;
        cout << "Monster's current health: " << m_prev_health << " -> " << monster.get_health() << endl;
        cout << endl;

        player_turn = !player_turn;
    }

    if (player.is_alive())
    {
        cout << "You killed " << monster.get_name() << endl;
        player.gain_experience(50);
    }
    else
    {
        cout << "You died. GAME OVER" << endl;
    }
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
    }
    else if (path == 's' || path == 'S')
    {
        cout << "You are going to the Labyrinth of Shadows" << endl;
    }
    else if (path == 'd' || path == 'D')
    {
        cout << "You are going to the scorching Desert of the Ancients" << endl;
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