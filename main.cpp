#include "graphics.hpp"
#include "dropDownBox.hpp"
#include "inputBox.hpp"
#include "numberBox.hpp"
#include "submitButton.hpp"
#include "widget.hpp"
#include "window.hpp"
#include "justText.hpp"
#include "scene.hpp"

#include <iostream>
#include <vector>
#include <string>

using namespace std;
using namespace genv;



class mainWindow : public window
{
    public:
        mainWindow();
    fomenu * f1;         /// F
    /*lovarda * o1;        /// O
    legelo * l1;         /// L
    versenypalya * v1;   /// V
    naptar * n1;         /// N
    bolt * b1;           /// B
    menu * m1;           /// M */

//    void whichToDraw(char sceneTipusa);






};


mainWindow::mainWindow()
{
    f1 = new fomenu(640,480,'F');
    scenes.push_back(f1);
    cout << f1->sxret();

    //f1.draw();
    /*switch(sceneTipusa)
        {
        case 'F':
            f1.draw();
            break;*/


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
