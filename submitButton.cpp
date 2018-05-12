#include "submitButton.hpp"
#include "graphics.hpp"
#include <iostream>

using namespace genv;

///Õsbutton

submitButton::submitButton(int x, int y, int sx, int sy, std::string s)
    : widget(x,y,sx,sy), buttonLabel(s)
{
    //ctor
}

///Szöveg button

textButton::textButton(window * parent, int x, int y, int sx, int sy, std::string s, std::string whatEvent)
    : submitButton(x,y,sx,sy,s),
    ostul(parent),
    _whatEvent(whatEvent)
{
}


void textButton::action() {
    ostul->anEvent(_whatEvent);
}

void submitButton::handle(genv::event ev) {
    if (ev.keycode==' ' || is_selected(ev.pos_x, ev.pos_y)) {
        action();
        //gout << dot;
    }
}

void submitButton::draw() {
    //if (_focused) gout << color(180,180,180);
         gout << color(130,130,130);
    gout << move_to(wx, wy) << box(wsx, wsy)
         << color(255,255,255);
    gout << move_to(wx+wsx/2-gout.twidth(buttonLabel)/2, wy+20)
         << text(buttonLabel);
}

