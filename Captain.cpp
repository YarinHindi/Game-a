#include "Captain.hpp"
#include <algorithm>
using namespace coup;
Captain::Captain(Game &game, const string name): Player(game,name,"Captain") {
        this->lastStolenPlayer = nullptr;
}
void Captain::block(Player& other){
    if(other.lastAction!="Steal"||other.playerRole!="Captain"){
        throw invalid_argument("invalid block you cannot block this player");
    }
    other.cash-=min(other.cash,2);
}
void Captain::steal(Player &other) {
    this->lastAction="Steal";
    this->cash+=min(other.cash,2);
    other.cash= max(0,other.cash-2);
}

