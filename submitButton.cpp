#include "submitButton.hpp"
#include "graphics.hpp"
#include <iostream>

using namespace genv;

///Õsbutton

submitButton::submitButton(int x, int y, int sx, int sy, char _whichScene, std::string s)
    : widget(x,y,sx,sy,_whichScene), buttonLabel(s)
{

}

///Szöveg button
/*
textButton::textButton(window * parent, int x, int y, int sx, int sy, std::string s, std::string whatEvent)
    : submitButton(x,y,sx,sy,s),
    ostul(parent),
    _whatEvent(whatEvent)
{
}

void textButton::action() {
    ostul->anEvent(_whatEvent);
}*/

void submitButton::handle(genv::event ev) {
    if (is_selected(ev.pos_x, ev.pos_y)) {
        action();
    }
}

void submitButton::draw() {
    /*//if (_focused) gout << color(180,180,180);
         gout << color(130,130,130);
    gout << move_to(wx, wy) << box(wsx, wsy)
         << color(255,255,255);
    gout << move_to(wx+wsx/2-gout.twidth(buttonLabel)/2, wy+20)
         << text(buttonLabel);*/
    gout << move_to(wx,wy) << color(200,200,200) << box(wsx,wsy);
    gout << move_to(wx+10,wy+wsy-5) << color(0,0,0) << text(buttonLabel);

}

fButton::fButton(int x, int y, int sx, int sy, char _whichScene, std::string s, std::function<void()> functor) : submitButton(x,y,sx,sy,_whichScene,s), _functor(functor)
{
}

void fButton::handle(genv::event ev) {
    if (is_selected(ev.pos_x, ev.pos_y) && (ev.button==btn_left)  ) {
        this->_functor();
    }
}

/*void fButton::draw()
{
    gout << move_to(wx,wy) << color(200,200,200) << box(wsx,wsy);
    gout << move_to(wx+5,wy+wsy-2) << color(0,0,0) << text(buttonLabel);
}*/
