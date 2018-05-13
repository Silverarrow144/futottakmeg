#ifndef GAMEMASTER_HPP
#define GAMEMASTER_HPP

#include "graphics.hpp"
#include <vector>
#include <string>

using namespace std;

class gamemaster
{
    public:
        gamemaster();

    protected:
        int penz, honap, nap, szenaMenny;

        vector<string> nyergek = {"szövetnyeger","Mûbõr nyereg","Bõr nyereg","Delux nyereg"} ;
        vector<string> kantarok = {"Kötél","Mûbõr kantár","Bõrkantár","Delux kantár"} ;
        vector<string> labvedok = {"Fásli","Szivacsos","Ellenálló","Erõs"};
        vector<string> loallapotok = {"Jó","Éhezik","Kiszárad","Koszos","Patagyulladás","Émelygés"};

        vector<string> vettNyereg;
        vector<string> vettKantar;
        vector<string> vettVedo;




    private:
};

#endif // GAMEMASTER_HPP
