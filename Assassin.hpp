#include <iostream>
using namespace std;
#include <string>
#include "Player.hpp"
namespace coup{
    class Assassin :public Player{
    public:
        Assassin(Game &game, const string & name);
        Player* lastRemovedPlayer;
        unsigned int removedPlayerIndex;

    };
}