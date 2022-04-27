#ifndef PLAYER_H
#define PLAYER_H
#include "Game.hpp"
#include <iostream>
using namespace std;
#include <string>
namespace coup{
    class Game;
    class Player{
    public:
        Game *game;
        Player(Game & game, const string & name,const string &role);
        int cash;
        string name;
        string playerRole;
        string lastAction;
        string role()const;
        virtual void income() ;
        void foreign_aid() ;
        int coins()const;
        void coup(Player& player);
    };
}
#endif