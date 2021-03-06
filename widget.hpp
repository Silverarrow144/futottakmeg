#ifndef WIDGET_HPP
#define WIDGET_HPP

#include "graphics.hpp"
#include <vector>

///Ancient Class

class widget
{
    public:
        widget(int x, int y, int sx, int sy, char _whichScene);
        virtual bool is_selected(int mouse_x, int mouse_y);
        virtual void which_hightlited(int mouse_x, int mouse_y);
        virtual void draw() = 0;
        virtual void handle(genv::event ev) = 0;
        bool in_focus=false;
        char getScene(){return whichScene;}

    protected:
        int wx, wy, wsx, wsy;
        int r,g,b;
        char whichScene;

    private:
};

#endif // WIDGET_HPP
