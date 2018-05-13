#include "graphics.hpp"
#include "dropDownBox.hpp"
#include "inputBox.hpp"
#include "numberBox.hpp"
#include "submitButton.hpp"
#include "widget.hpp"
#include "window.hpp"
#include "justText.hpp"
#include "scene.hpp"
#include "gamemaster.hpp"

#include <iostream>
#include <vector>
#include <string>

using namespace std;
using namespace genv;



class mainWindow : public window
{
    public:
    mainWindow();

    ///K�perny�k
    fomenu * f1;         /// F
    lovarda * o1;        /// O
    legelo * l1;         /// L
    versenypalya * v1;   /// V
    naptar * n1;         /// N
    bolt * b1;           /// B
    menu * m1;           /// M

    ///F�men�
    fButton * folytat;
    fButton * ujjatek;
    fButton * mentes;
    fButton * kilepes;

    ///Men�
    fButton * fom;
    fButton * lov;
    fButton * leg;
    fButton * ver;
    fButton * nap;
    fButton * bol;

    fButton * napVege;

    ///Lovarda
    fButton * jobbNyil;
    fButton * balNyil;

    numberBox * szena;
    fButton * etetes;
    fButton * itatas;
    fButton * csutakolas;
    fButton * patakaparas;
    fButton * kialmozas;

    dropDownBox * nyereg;
    dropDownBox * kantar;
    dropDownBox * labvedo;
    dropDownBox * gyogyszer;
    fButton * gyogyit;

    justText * tul;

    ///Legel�
    dropDownBox * paciEdzeni;
    dropDownBox * melyEdzes;
    fButton * acceptEdzes;
    fButton * lovagoltatas;

    ///Versenyp�lya
    dropDownBox * paciVersenyre;
    fButton * acceptVerseny;
    justText * nextVerseny;
    justText * eredmeny;

    ///Napt�r
    fButton * kinezet;
    justText * verseny;
    justText * paciDolga;

    ///Bolt
    //Side menu
    dropDownBox * nyeregVenni;
    dropDownBox * kantarVenni;
    dropDownBox * labvedoVenni;
    numberBox * szenaVenni;
    dropDownBox * gyogyVenni;
    numberBox * loVenni;

    fButton * megvenni;


    gamemaster * GM;
};


mainWindow::mainWindow()
{
    ///K�perny�k
    f1 = new fomenu(640,480,'F');
    o1 = new lovarda(640,380,'O');
    l1 = new legelo(640,380,'L');
    v1 = new versenypalya(640,380,'V');
    n1 = new naptar(640,380,'N');
    b1 = new bolt(640,380,'B');
    m1 = new menu(0,380,640,100,'M');

    //cout << f1->tipusa << endl;
    scenes.push_back(f1);
    scenes.push_back(o1);
    scenes.push_back(l1);
    scenes.push_back(v1);
    scenes.push_back(n1);
    scenes.push_back(b1);
    scenes.push_back(m1);

    //cout << scenes[0]->

    ///F�men� widgetei
    folytat = new fButton(270,80,100,20,'F',"Folytat�s",[this](){
                          this->actualType='O';
                          });
    //cout << this->actualType;
    widgetek.push_back(folytat);
    //cout << widgetek[0]->_whichScene;

    ///Lenti men� widgetei


    ///Lovarda widgetei


    ///Legel� widgetei


    ///Versenyp�lya widgetei


    ///Napt�r widgetei


    ///Bolt widgetei

}

/*void whichToDraw(char sceneTipusa)
    {
        switch(sceneTipusa)
        {
        case 'F':
            f1.draw();
            break;
        case 'O':
            //drawthis
            break;
        case 'L':
            //drawthis
            break;
        case 'V':
            //drawthis
            break;
        case 'N':
            //drawthis
            break;
        case 'B':
            //drawthis
            break;
        }
    }*/



/*void theWindow::fv(window *w) {
    theWindow * mw = dynamic_cast<theWindow*>(w);
    if (mw) {
        mw->valami();
    }
}*/


int main()
{
    event ev;
    while (gin >> ev){
    gout.open(640,480);
    mainWindow *TheWindow = new mainWindow;
    TheWindow->event_loop();
    }
    return 0;
}
