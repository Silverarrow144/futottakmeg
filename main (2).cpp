#include <iostream>
#include "graphics.hpp"
#include "dropDownBox.hpp"
#include "inputBox.hpp"
#include "numberBox.hpp"
#include "submitButton.hpp"
#include "widget.hpp"
#include "window.hpp"
#include "justText.hpp"
#include <vector>

using namespace std;
using namespace genv;

class acceptButton;

class theWindow : public window
{
    public:
    dropDownBox *dr1;
    inputBox *in1;
    numberBox *num1;
    submitButton *sub1;
    textButton *tx1;
    acceptButton *ab1;
    justText *jtx1;
    theWindow();

    ///Cselekvés
    void anEvent(string whatEvent) {
        if (whatEvent == "egyenlo") {
            jtx1->setText(in1->value());
        }
    }
    static void fv(window *);
    void valami() {
        jtx1->setText("sikerult");
    }

};

class acceptButton : public submitButton
{
    theWindow *theWindowParent;
    public:
    acceptButton(theWindow * parent, int x, int y, int sx,
                int sy, std::string s)
                :submitButton(x, y, sx, sy, s) {
        theWindowParent = parent;
    }
    virtual void action() ;

};

theWindow::theWindow()
{
        tx1 = new textButton(this, 10, 10, 100, 40,"oda", "egyenlo");
        jtx1 = new justText(175,20,100,40,"pipa");
        in1 = new inputBox(10,100,100,40,"editor");
        ab1 = new acceptButton(this, 10,200,100,40,"vbut");
        //fvptrbutton = new pointerButton(this, 10,250,100,40,"fvptr",MyWindow::fv);
        //functorbutton = new fButton(10,300,100,40,"functor",
                                       //   [this](){this->valami();});
        widgetek.push_back(jtx1);
        widgetek.push_back(in1);
        widgetek.push_back(tx1);
        widgetek.push_back(ab1);
        //widgets.push_back(fvptrbutton);
        //widgets.push_back(functorbutton );
}

void theWindow::fv(window *w) {
    theWindow * mw = dynamic_cast<theWindow*>(w);
    if (mw) {
        mw->valami();
    }
}


void acceptButton::action()
{
    theWindowParent->valami();
    //cout << "Ez";
}


int main()
{
    gout.open(400,400);         ///Megoldani változóval a méretek megadását!!
    theWindow *TheWindow = new theWindow;
    TheWindow->event_loop();
    return 0;
}
