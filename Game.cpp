#include "Game.hpp"
using namespace coup;
Game::Game(){
    cout<<"hello"<<endl;
    this->thePlayers = new vector<Player*>[6];
    this->currentTurn = 0;
}
void Game::addPlayer(Player* player) {
    this->thePlayers->push_back(player);

}
vector<string> Game::players() {
    vector<string> ans;
    for (unsigned int i=0;i< this->thePlayers->size();i++){
        ans.push_back(this->thePlayers->at(i)->name);
    }
    return ans;
}
void Game::validAction(Player * player){
    if(this->thePlayers->at(this->currentTurn)!= player){
        throw invalid_argument("this is not your turn");
    }
    this->currentTurn = (this->currentTurn+1) % this->thePlayers->size();
}
string Game::turn() {
    return this->thePlayers->at(this->currentTurn)->name;
}