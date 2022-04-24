#ifndef PLAYER_H
#define PLAYER_H
#include "Game.hpp"
#include <iostream>
using namespace std;
#include <string>
namespace coup{
    class Player{
//    private :
//      int cash;
//      string name;
    public:
        Player();
        int cash;
        string name;
        void income() ;
        void foreign_aid() ;
        void coup(string name);
    };
}
#endif