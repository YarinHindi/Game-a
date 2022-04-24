#include "Duke.hpp"
using namespace coup;
Duke::Duke(Game game, string name) {
    this->name = name;
    game.addPlayer(name);
}


