#include "inputBox.hpp"
#include "graphics.hpp"
#include <iostream>

using namespace genv;

inputBox::inputBox(int x, int y, int sx, int sy, std::string _s)
    : widget(x,y,sx,sy)
{
    inbox="";
    maxLength=sx/9;
    firstChar=0;
}

void inputBox::draw() {
    if(in_focus)
    {
        gout << color(r,g,0);
    }
    else
    {
        gout << color(r,g,b);
    }
    gout << move_to(wx, wy) << box(wsx, wsy);
    gout << move_to(wx+2, wy+2) << color(170,170,170) << box(wsx-4, wsy-4);
    gout << color(0,0,0) << move_to(wx+9,wy+20);
    if(inbox.length()>maxLength)
    {
        gout << text(inbox.substr(firstChar,maxLength));
    }
    else
    {
        gout << text(inbox);
    }
}

void inputBox::handle(event ev)
{
    ///Kiiratás ascii
    if (ev.type==ev_key && ( (ev.keycode>31 && ev.keycode<123) || (ev.keycode>192 && ev.keycode<253) ) && in_focus)
    {
        inbox+=ev.keycode;
        if(inbox.length()>maxLength)
        {
            firstChar=inbox.length()-maxLength;
        }
    }
    ///Visszatörlés
    if (ev.type==ev_key && ev.keycode==key_backspace && in_focus && inbox.length()>0 )
    {
        inbox.pop_back();
        if(inbox.length()>maxLength)
        {
            firstChar=inbox.length()-maxLength;
        }
    }

    if(ev.keycode==key_enter)
    {
        std::cout << inbox;
    }
}



bool inputBox::is_selected(int mouse_x, int mouse_y)
{
    return mouse_x>wx && mouse_x<wx+wsx && mouse_y>wy && mouse_y<wy+wsy;
}
