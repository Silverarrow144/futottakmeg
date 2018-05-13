#include "numberBox.hpp"
#include "graphics.hpp"
#include <sstream>
#include <iostream>
#include <math.h>

using namespace genv;

numberBox::numberBox(int x, int y, int sx, int sy, char _whichScene, int iMin, int iMax)
    : widget(x,y,sx,sy,_whichScene), iMin(iMin), iMax(iMax)
{
    cNumber=0;
    maxSzam=(wsx-35)/9;
}

void numberBox::draw() {

    std::stringstream t;
    std::stringstream tt;
    t << cNumber;
    int szamjegy=t.str().size();
    for(int i=0;i<(maxSzam-szamjegy);i++)
    {
        tt << ' ';
    }
    tt << cNumber;

    ///Doboz + szöveg
    gout << move_to(wx, wy) << box(wsx, wsy);
    gout << move_to(wx+2, wy+2) << color(170,170,170) << box(wsx-4, wsy-4);
    gout << color(0,0,0) << move_to(wx+15,wy+20) << text(tt.str());

    ///Fel nyíl
    gout << move_to(wx+wsx-10,wy+6) << line_to(wx+wsx-6,wy+10);
    gout << move_to(wx+wsx-10,wy+6) << line_to(wx+wsx-14,wy+10);

    ///Le nyíl
    gout << move_to(wx+wsx-10,wy+wsy-6) << line_to(wx+wsx-6,wy+wsy-10);
    gout << move_to(wx+wsx-10,wy+wsy-6) << line_to(wx+wsx-14,wy+wsy-10);

    ///Vonal
    gout << color(130,130,130);
    gout << move_to(wx+wsx-18,wy+3) << line_to(wx+wsx-18,wsy+wy-3);
}

void numberBox::handle(event ev)
{
    if (iMax>(pow(10,maxSzam))-1)
    {
        iMax=(pow(10,maxSzam))-1;
    }
    if (iMin<0-(pow(10,maxSzam))+1)
    {
        iMin=0-(pow(10,maxSzam-1))+1;
    }

    ///1-et fel
    if ( ( ( (ev.button==btn_left) && (ev.pos_x>wx+wsx-18) && (ev.pos_x<wx+wsx) && (ev.pos_y>wy) && (ev.pos_y<wy+15)  ) || (ev.keycode==key_up) )  && (cNumber<iMax)  )
    {
        cNumber++;
    }

    ///1-et le
    if ( ( (ev.button==btn_left && (ev.pos_x>wx+wsx-18) && (ev.pos_x<wx+wsx) && (ev.pos_y>wy+wsy-15) && (ev.pos_y<wy+wsy) ) || (ev.keycode==key_down) ) && (cNumber>iMin)   )
    {
        cNumber--;
    }

    ///10-et fel
    if ( (ev.keycode==key_pgup) && (cNumber+9<iMax) )
    {
        cNumber+=10;
    }

    ///10-et le
    if ( (ev.keycode==key_pgdn) && (cNumber-9>iMin) )
    {
        cNumber-=10;
    }
}

