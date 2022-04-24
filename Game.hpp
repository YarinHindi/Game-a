#ifndef GAME_H
#define GAME_H
#include <iostream>
using namespace std;
#include <string>
#include <vector>
namespace coup{
    class Game {
//    private:
//        vector<string> thePlayers;
    public :
        vector<string>* thePlayers;
        Game();
        vector<string> players();
        void addPlayer(string name);
        string turn();
    };
}
#endif