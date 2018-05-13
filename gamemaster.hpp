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

        vector<string> nyergek = {"sz�vetnyeger","M�b�r nyereg","B�r nyereg","Delux nyereg"} ;
        vector<string> kantarok = {"K�t�l","M�b�r kant�r","B�rkant�r","Delux kant�r"} ;
        vector<string> labvedok = {"F�sli","Szivacsos","Ellen�ll�","Er�s"};
        vector<string> loallapotok = {"J�","�hezik","Kisz�rad","Koszos","Patagyullad�s","�melyg�s"};

        vector<string> vettNyereg;
        vector<string> vettKantar;
        vector<string> vettVedo;




    private:
};

#endif // GAMEMASTER_HPP
