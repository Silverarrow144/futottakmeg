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

    ///Képernyõk
    fomenu * f1;         /// F
    lovarda * o1;        /// O
    legelo * l1;         /// L
    versenypalya * v1;   /// V
    naptar * n1;         /// N
    bolt * b1;           /// B
    menu * m1;           /// M

    ///Fõmenü
    fButton * folytat;
    fButton * ujjatek;
    fButton * mentes;
    //fButton * kilepes;

    ///Menü
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

    ///Legelõ
    dropDownBox * paciEdzeni;
    dropDownBox * melyEdzes;
    fButton * acceptEdzes;
    fButton * lovagoltatas;

    ///Versenypálya
    dropDownBox * paciVersenyre;
    fButton * acceptVerseny;
    justText * nextVerseny;
    justText * eredmeny;

    ///Naptár
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
    int x1=640;
    int y1=380;
    ///Képernyõk
    f1 = new fomenu(x1,480,'F');
    o1 = new lovarda(x1,y1,'O');
    l1 = new legelo(x1,y1,'L');
    v1 = new versenypalya(x1,y1,'V');
    n1 = new naptar(x1,y1,'N');
    b1 = new bolt(x1,y1,'B');
    m1 = new menu(0,380,x1,100,'M');

    //cout << f1->tipusa << endl;
    scenes.push_back(f1);
    scenes.push_back(o1);
    scenes.push_back(l1);
    scenes.push_back(v1);
    scenes.push_back(n1);
    scenes.push_back(b1);
    scenes.push_back(m1);

    //cout << scenes[0]->

    ///Fõmenü widgetei
    folytat = new fButton(270,80,100,20,'F',"Folytatás",[this](){this->actualType='O';});
    ujjatek = new fButton(270,120,100,20,'F',"Új játék",[this](){this->actualType='O';});
    mentes = new fButton(270,160,100,20,'F',"Mentés",[this](){
                         //this->actualType='O';
                         cout << "Itt kell a file-ba iratást meghívni, közvetve";
                         });
    //kilepes = new fButton(270,200,100,20,'F',"Kilépés",[this](){this->iNeedToStop=true;cout << this->iNeedToStop;});

    widgetek.push_back(folytat);
    widgetek.push_back(ujjatek);
    widgetek.push_back(mentes);
    //widgetek.push_back(kilepes);

    ///Lenti menü widgetei

    int menu_sx=140;
    int menu_sy=20;
    fom = new fButton(100,400,menu_sx,menu_sy,'M',"Fömenü",[this](){this->actualType='F';});
    lov = new fButton(250,400,menu_sx,menu_sy,'M',"Lovarda",[this](){this->actualType='O';});
    leg = new fButton(400,400,menu_sx,menu_sy,'M',"Legelö",[this](){this->actualType='L';});
    ver = new fButton(100,440,menu_sx,menu_sy,'M',"Versenypálya",[this](){this->actualType='V';});
    nap = new fButton(250,440,menu_sx,menu_sy,'M',"Naptár",[this](){this->actualType='N';});
    bol = new fButton(400,440,menu_sx,menu_sy,'M',"Bolt",[this](){this->actualType='B';});

    widgetek.push_back(fom);
    widgetek.push_back(lov);
    widgetek.push_back(leg);
    widgetek.push_back(ver);
    widgetek.push_back(nap);
    widgetek.push_back(bol);


    //napVege = new fButton();

    ///Lovarda widgetei


    ///Legelõ widgetei


    ///Versenypálya widgetei


    ///Naptár widgetei


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
    while (gin >> ev ){
        gout.open(640,480);
        mainWindow *TheWindow = new mainWindow;
        TheWindow->event_loop();
    }
    return 0;
}
