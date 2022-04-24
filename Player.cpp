#include "Player.hpp"
using namespace coup;
Player::Player() {
    this->cash=0;
}

void Player::income() {
    this->cash++;
}
