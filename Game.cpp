#include "Game.hpp"
using namespace coup;
constexpr int  MaxPlayerNum  = 6;
Game::Game(){
    this->thePlayers = new vector<Player*>[MaxPlayerNum];
    this->currentTurn = 0;
}
Game::~Game() {
    delete [] this->thePlayers;

}
void Game::addPlayer(Player* player)const {
    this->thePlayers->push_back(player);

}
vector<string> Game::players() const {
    vector<string> ans;
    for (unsigned int i=0;i< this->thePlayers->size();i++){
        ans.push_back(this->thePlayers->at(i)->name);
    }
    return ans;
}
void Game::validAction(Player & player){
    if(this->thePlayers->at(this->currentTurn)!= &player){
        throw invalid_argument("this is not your turn");
    }
    this->currentTurn = (this->currentTurn+1) % this->thePlayers->size();
}
string Game::turn()const {
    return this->thePlayers->at(this->currentTurn)->name;
}
void Game::removePlayer(Player &player)const {
    for (unsigned int i = 0; i < this->thePlayers->size(); ++i) {
        if(this->thePlayers->at(i)==&player){
            this->thePlayers->erase(thePlayers->begin()+i,thePlayers->begin()+i+1);
            break;
        }
    }
}
void Game::revivePlayer(Player *player, unsigned int pos) const {
    this->thePlayers->insert(thePlayers->begin()+pos,player);
}
string Game::winner() const {
    if(this->thePlayers->size()!=1){
        throw invalid_argument("somthing went wrong with winner player");
    }
    return this->thePlayers->at(0)->name;
}