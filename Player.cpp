#include "Player.hpp"
#include "Assassin.hpp"
constexpr int coupAssassinCost = 3;
constexpr int coupRegPlayerCost = 7;
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
    this->game->validAction(*this);
    this->cash++;
    this->lastAction = "income";
}
void Player::foreign_aid(){
    this->game->validAction(*this);
    this->cash+=2;
    this->lastAction = "foreign_aid";
}
int Player::coins()const {
    return this->cash;
}
string Player::role()const {
    return this->playerRole;
}
void Player::coup(Player &player) {
    this->game->validAction(*this);
    if(this->playerRole=="Assassin"&&this->cash>=coupAssassinCost){
        Assassin* temp = dynamic_cast<Assassin*>(this);
        temp->lastRemovedPlayer = &player;
        for (unsigned int i = 0; i < this->game->thePlayers->size() ; ++i) {
            if(this->game->thePlayers->at(i)==&player){
                temp->removedPlayerIndex=i;
            }
        }
        this->game->removePlayer(player);
        this->cash-=coupAssassinCost;
        this->lastAction="Coup";
        return;
    }
    if(this->playerRole!="Assassin"&& this->cash>=coupRegPlayerCost) {
        this->game->removePlayer(player);
        this->cash -= coupRegPlayerCost;
        this->lastAction="Coup";
        return;
    }
    throw invalid_argument("invalid coup you cannot coup this player");
}

