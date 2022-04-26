#include "Contessa.hpp"
#include "Assassin.hpp"
using namespace coup;
Contessa::Contessa(Game &game, const string name): Player(game,name,"Contessa") {
}
void Contessa::block(Player &player) {
    if(player.playerRole!="Assassin"||player.lastAction!="Coup"){
        throw invalid_argument("Contessa cant block this player");
    }
    Assassin* temp = static_cast<Assassin*>(&player);
    if(temp->lastRemovedPlayer== nullptr){
        throw invalid_argument("Assassin has been couped already in this round");
    }
    game->addPlayer(temp->lastRemovedPlayer);
    temp->lastRemovedPlayer = nullptr;

}

