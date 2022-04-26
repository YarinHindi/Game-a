#include "Ambassador.hpp"
#include "Captain.hpp"
using namespace coup;
Ambassador::Ambassador(Game &game, const string name): Player(game,name,"Ambassador") {

}

void Ambassador::transfer(Player &first, Player &second) {
    game->validAction(*this);
    first.cash--;
    second.cash++;
}
void Ambassador::block(Player &player) {
    if(player.lastAction!="Steal"||player.playerRole!="Captain"){
        throw invalid_argument("invalid block you cannot block this player");
    }
    Captain* temp = static_cast<Captain*>(&player);
    if(temp->lastStolenPlayer== nullptr){
        throw invalid_argument("invalid block you cannot block this player");
    }
    player.cash-=2;
    temp->lastStolenPlayer->cash+=2;
    temp->lastStolenPlayer = nullptr;

}


