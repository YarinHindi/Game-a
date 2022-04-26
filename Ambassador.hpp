#include <iostream>
using namespace std;
#include <string>
#include "Player.hpp"
namespace coup{
    class Ambassador :public Player{
    public:
        Ambassador(Game &game, const string name);
        void transfer(Player& first,Player &second);
        void block(Player& player);

    };
}