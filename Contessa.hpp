//using namespace std;
//#include <string>
namespace coup{
    class Contessa :public Player{
    private:
        Game game;
    public:
        Contessa(Game game,string name);
        void income() ;
        void foreign_aid() ;
        void coup(string name) ;
    };
}