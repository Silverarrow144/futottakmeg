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
        submitButton(int x, int y, int sx, int sy, char _whichScene, std::string s);
        virtual void draw();
        virtual void handle(genv::event ev);
        virtual void action()=0;

    protected:

    private:
        std::string buttonLabel;
};

///Functor button

class fButton : public submitButton {
    std::function<void()> _functor;
public:
    fButton(int x, int y, int sx, int sy, char _whichScene, std::string s, std::function<void()> functor);
    void action(){}
    void handle(genv::event ev);
};

#endif // SUBMITBUTTON_HPP
