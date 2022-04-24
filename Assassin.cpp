#include "Assassin.hpp"
using namespace coup;
Assassin::Assassin(Game game, string name) {
    this->name = name;
    game.addPlayer(name);
}
