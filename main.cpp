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
    scene * fomenu;         /// F
    scene * lovarda;        /// O
    scene * legelo;         /// L
    scene * versenypalya;   /// V
    scene * naptar;         /// N
    scene * bolt;           /// B
    scene * menu;           /// M

    void whichToDraw(char sceneTipusa)
    {
        switch(sceneTipusa)
        {
        case 'F':
            //drawthis
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
    }





};






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
    //theWindow *TheWindow = new theWindow;
    //TheWindow->event_loop();
    }
    return 0;
}
