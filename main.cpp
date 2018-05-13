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
    //fButton * mentes;
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
    justText * verseny;
    justText * paciDolga;

    ///Bolt
    dropDownBox * nyeregVenni;
    dropDownBox * kantarVenni;
    dropDownBox * labvedoVenni;
    numberBox * szenaVenni;
    dropDownBox * gyogyVenni;
    inputBox * loNeve;
    fButton * loVenni;

    fButton * megvenni;

    gamemaster * GM;
};


mainWindow::mainWindow()
{
    GM = new gamemaster();
    vector<string> vv1 = {"Válassz lovat"};
    vector<string> vv2 = {"Válassz edzést"};

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

    scenes.push_back(f1);
    scenes.push_back(o1);
    scenes.push_back(l1);
    scenes.push_back(v1);
    scenes.push_back(n1);
    scenes.push_back(b1);
    scenes.push_back(m1);

    ///Fõmenü widgetei
    folytat = new fButton(270,150,100,20,'F',"Folytatás",[this](){this->actualType='O';});
    ujjatek = new fButton(270,190,100,20,'F',"Új játék",[this](){this->actualType='O';});
    /*mentes = new fButton(270,230,100,20,'F',"Mentés",[this](){
                         cout << "Itt kell a file-ba iratást meghívni, közvetve";
                         });*/
    //kilepes = new fButton(270,200,100,20,'F',"Kilépés",[this](){this->iNeedToStop=true;cout << this->iNeedToStop;});

    widgetek.push_back(folytat);
    widgetek.push_back(ujjatek);
    //widgetek.push_back(mentes);
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


    napVege = new fButton(550,420,80,40,'M',"Nap vége",[this](){});

    widgetek.push_back(napVege);

    ///Lovarda widgetei
    jobbNyil = new fButton(500,230,20,20,'O',">",[this](){});
    balNyil = new fButton(200,230,20,20,'O',"<",[this](){});

    widgetek.push_back(jobbNyil);
    widgetek.push_back(balNyil);

    etetes = new fButton(50,200,100,20,'O',"Etetés",[this](){});
    itatas = new fButton(50,230,100,20,'O',"Itatás",[this](){});
    csutakolas = new fButton(50,260,100,20,'O',"Csutakolás",[this](){});
    patakaparas = new fButton(50,290,100,20,'O',"Patakaparás",[this](){});
    kialmozas = new fButton(50,320,100,20,'O',"Kialmozás",[this](){});

    widgetek.push_back(etetes);
    widgetek.push_back(itatas);
    widgetek.push_back(csutakolas);
    widgetek.push_back(patakaparas);
    widgetek.push_back(kialmozas);

    nyereg = new dropDownBox(20,20,100,20,'O',vv1);
    kantar = new dropDownBox(130,20,100,20,'O',vv1);
    labvedo = new dropDownBox(240,20,100,20,'O',vv1);
    gyogyszer = new dropDownBox(350,20,100,20,'O',vv1);
    gyogyit = new fButton(50,350,100,20,'O',"Gyógyít",[this](){});

    widgetek.push_back(nyereg);
    widgetek.push_back(kantar);
    widgetek.push_back(labvedo);
    widgetek.push_back(gyogyszer);
    widgetek.push_back(gyogyit);

    tul = new justText(500,20,150,20,'O',"EZ");

    widgetek.push_back(tul);



    ///Legelõ widgetei
    paciEdzeni = new dropDownBox(20,20,150,20,'L',vv1);
    melyEdzes = new dropDownBox(180,20,150,20,'L',vv2);
    acceptEdzes = new fButton(340,20,150,20,'L',"Edzés",[this](){});
    lovagoltatas = new fButton(50,300,150,20,'L',"Lovagoltatás",[this](){});

    widgetek.push_back(paciEdzeni);
    widgetek.push_back(melyEdzes);
    widgetek.push_back(acceptEdzes);
    widgetek.push_back(lovagoltatas);

    ///Versenypálya widgetei
    paciVersenyre = new dropDownBox(20,20,150,20,'V',vv1);
    acceptVerseny = new fButton(340,20,150,20,'V',"Verseny",[this](){});
    nextVerseny = new justText(400,200,150,20,'V',"EZ");
    eredmeny = new justText(400,300,150,20,'V',"AZ");

    widgetek.push_back(paciVersenyre);
    widgetek.push_back(acceptVerseny);
    widgetek.push_back(nextVerseny);
    widgetek.push_back(eredmeny);

    ///Naptár widgetei
    verseny = new justText(20,20,150,20,'N',"AZ");
    paciDolga = new justText(20,200,150,20,'N',"AZ");

    widgetek.push_back(verseny);
    widgetek.push_back(paciDolga);

    ///Bolt widgetei
    nyeregVenni = new dropDownBox(20,20,100,20,'B',vv1);
    kantarVenni = new dropDownBox(130,20,100,20,'B',vv1);
    labvedoVenni = new dropDownBox(240,20,100,20,'B',vv1);
    szenaVenni = new numberBox(130,200,150,20,'B',1,100);
    gyogyVenni = new dropDownBox(350,20,100,20,'B',vv1);
    loNeve = new inputBox(20,350,100,20,'B',"");
    loVenni = new fButton(200,350,100,20,'B',"Lóvásárlás",[this](){});

    megvenni = new fButton(340,300,100,20,'B',"Vásárlás",[this](){});

    widgetek.push_back(nyeregVenni);
    widgetek.push_back(kantarVenni);
    widgetek.push_back(labvedoVenni);
    widgetek.push_back(szenaVenni);
    widgetek.push_back(gyogyVenni);
    widgetek.push_back(loNeve);
    widgetek.push_back(loVenni);

    widgetek.push_back(megvenni);
}




int main()
{
    event ev;
    //PlaySound(TEXT("irish.mp3"), NULL, SND_FILENAME);
    while (gin >> ev ){
        gout.open(640,480);
        mainWindow *TheWindow = new mainWindow;
        TheWindow->event_loop();
    }
    return 0;
}
