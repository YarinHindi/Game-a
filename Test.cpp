#include "doctest.h"
#include "Player.hpp"
#include "Duke.hpp"
#include "Assassin.hpp"
#include "Ambassador.hpp"
#include "Captain.hpp"
#include "Contessa.hpp"
using namespace coup;
using namespace std;
TEST_CASE("add Players to game and check game status"){
    Game game_1{};
    /* This player drew the "Duke" card, his name is Moshe
    and he is a player in game_1 */
    Duke duke{game_1, "Moshe"};
    Assassin assassin{game_1, "Yossi"};
    Ambassador ambassador{game_1, "Meirav"};
    Captain captain{game_1, "Reut"};
    Contessa contessa{game_1, "Gilad"};
    CHECK(duke.cash==0);
    CHECK(assassin.cash==0);
    CHECK(ambassador.cash==0);
    CHECK(captain.cash==0);
    CHECK(contessa.cash==0);
    duke.tax();
    CHECK(duke.cash==3);
    CHECK_THROWS(duke.coup(assassin));
    assassin.foreign_aid();
    CHECK(assassin.cash==2);
    ambassador.transfer(duke,assassin);
    CHECK(assassin.cash==3);
    captain.steal(duke);
    CHECK(duke.cash==0);
    contessa.foreign_aid();
    CHECK(contessa.cash==2);
    CHECK_THROWS(assassin.coup(ambassador));
    duke.foreign_aid();
    CHECK_NOTHROW(assassin.coup(captain));
    vector<string> players = game_1.players();
    CHECK(players.size()==4);
    contessa.block(assassin);
    CHECK(game_1.turn()=="Meirav");
    players = game_1.players();
    CHECK(players.size()==5);
    CHECK(players.at(3)=="Reut");
    CHECK_NOTHROW(ambassador.foreign_aid());
    CHECK_NOTHROW(captain.foreign_aid());
    CHECK_NOTHROW(contessa.foreign_aid());
    CHECK_NOTHROW(duke.tax());
    CHECK_NOTHROW(assassin.foreign_aid());
    CHECK_NOTHROW(ambassador.foreign_aid());
    CHECK_NOTHROW(captain.foreign_aid());
    CHECK_NOTHROW(contessa.foreign_aid());
    CHECK_NOTHROW(duke.tax());
    CHECK_NOTHROW(assassin.foreign_aid());
    CHECK_NOTHROW(ambassador.foreign_aid());
    CHECK_NOTHROW(captain.foreign_aid());
    CHECK_NOTHROW(contessa.foreign_aid());
    CHECK_NOTHROW(duke.tax());
    CHECK_NOTHROW(assassin.foreign_aid());
    CHECK_NOTHROW(ambassador.foreign_aid());
    CHECK_NOTHROW(captain.foreign_aid());
    CHECK_NOTHROW(contessa.foreign_aid());
    CHECK_NOTHROW(duke.tax());
    CHECK_NOTHROW(assassin.foreign_aid());
    CHECK_NOTHROW(ambassador.coup(captain));
    CHECK_NOTHROW(contessa.coup(duke));
    CHECK_NOTHROW(assassin.coup(contessa));
    CHECK_NOTHROW(ambassador.income());
    CHECK_THROWS(game_1.winner());
    CHECK_NOTHROW(assassin.coup(ambassador));
    CHECK(game_1.winner()=="Yossi");

}