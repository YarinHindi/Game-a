#ifndef GAME_H
#define GAME_H
#include <iostream>
using namespace std;
#include <string>
#include <vector>
#include "Player.hpp"
#include <stdexcept>
namespace coup{
    class Player;
    class Game {
//    private:
//        vector<string> thePlayers;
    public :
        vector<Player*>* thePlayers;
        unsigned int currentTurn;
        Game();
        ~Game();
        vector<string> players() const;
        void addPlayer(Player * player)const;
        void revivePlayer(Player * player,unsigned int pos)const;
        void validAction(Player & player);
        void removePlayer(Player &player)const;
        string turn()const;
        string winner()const;
    };
}
#endif