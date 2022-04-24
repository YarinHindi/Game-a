#include "Game.hpp"
using namespace coup;
Game::Game(){
    cout<<"hello"<<endl;
    this->thePlayers = new vector<string>[6];

}

void Game::addPlayer(string name) {
    this->thePlayers->push_back(name);
}
vector<string> Game::players() {
    return *this->thePlayers;
}