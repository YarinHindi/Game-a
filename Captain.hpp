//using namespace std;
//#include <string>
namespace coup{
    class Captain :public Player{
    private:
        Game game;
    public:
        Captain(Game game,string name);
        void income() ;
        void foreign_aid() ;
        void coup(string name) ;
    };
}