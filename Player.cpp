#include "Player.hpp"
#include "Assassin.hpp"
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
int Player::coins() {
    return this->cash;
}
string Player::role() {
    return this->playerRole;
}
void Player::coup(Player &player) {
    if(this->playerRole=="Assassin"&&this->cash>=3){
        cout<<"inside"<<endl;
        Assassin* temp = static_cast<Assassin*>(this);
        temp->lastRemovedPlayer = &player;
        this->game->removePlayer(player);
        this->cash-=3;
        this->lastAction="Coup";
        return;
    }
    if(this->playerRole!="Assassin"&& this->cash>=7) {
        this->game->removePlayer(player);
        this->cash -= 7;
        this->lastAction="Coup";
        return;
    }
    throw invalid_argument("invalid coup you cannot coup this player");
}

