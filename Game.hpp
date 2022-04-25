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
        vector<string> players();
        void addPlayer(Player * player);
        void validAction(Player * player);
        string turn();
    };
}
#endif