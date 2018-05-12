#ifndef SUBMITBUTTON_HPP
#define SUBMITBUTTON_HPP

#include "graphics.hpp"
#include "widget.hpp"
#include "window.hpp"
#include <functional>
#include <string>

///Button õswidget
class submitButton : public widget
{
    public:
        submitButton(int x, int y, int sx, int sy, std::string s);
        virtual void draw();
        virtual void handle(genv::event ev);
        virtual void action()=0;

    protected:

    private:
        std::string buttonLabel;
};


///Text button

class textButton : public submitButton
{
    window * ostul;
    std::string _whatEvent;
public:
    textButton(window * parent, int x, int y, int sx,
                int sy, std::string s, std::string whatEvent);
    virtual void action();

    //protected:


    //private:


};

///Pointer button

class poiterButton : public submitButton{
    window *_parent;
    void (*_fvmut)(window *);
public:
    pointerButton (window* parent, int x, int y, int sx, int sy, std::string s, void(*fvmut)(window *));
    virtual void action();
};


///Functor button

class fButton : public submitButton {
    std::function<void()> _functor;
public:
    FunctorButton(int x, int y, int sx,
                int sy, std::string s, std::function<void()> functor);
    void action();
};


///Egyéb

#endif // SUBMITBUTTON_HPP
