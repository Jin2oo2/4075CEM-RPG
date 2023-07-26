#ifndef BATTLE_H
#define BATTLE_H

#include <iostream>
#include <array>
#include <stdlib.h>
#include "../include/Player.hh"
#include "../include/Monster.hh"
using namespace std;

// Used to battle when player encounters a monster
bool battle(Player player, Monster monster)
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
        return true;
    }
    else
    {
        return false;
    }
}

#endif