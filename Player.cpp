#include "Player.hpp"
using namespace coup;
Player::Player(Game & game, const string & name,const string & role) {
    this->cash = 0;
    this->game = &game;
    this->name = name;
    this->game->addPlayer(this);
    this->lastAction = "";
    this->playerRole = role;
}

void Player::income() {
    this->game->validAction(this);
    this->cash++;
    this->lastAction = "income";
}
void Player::foreign_aid(){
    this->game->validAction(this);
    this->cash+=2;
    this->lastAction = "foreign_aid";
}
int Player::coins() {
    return this->cash;
}
string Player::role() {
    return this->playerRole;
}
