//using namespace std;
//#include <string>
namespace coup{
    class Ambassador :public Player{
    private:
        Game game;
    public:
        Ambassador(Game game,string name);
        void income() ;
        void foreign_aid() ;
        void coup(string name) ;
    };
}