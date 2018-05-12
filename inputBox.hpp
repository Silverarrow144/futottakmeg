#ifndef INPUTBOX_HPP
#define INPUTBOX_HPP

#include "graphics.hpp"
#include "widget.hpp"
#include <string>
#include <iostream>
#include <vector>

class inputBox : public widget
{
    public:
        inputBox(int x, int y, int sx, int sy, std::string s);
        virtual void draw();
        virtual void handle(genv::event ev);
        virtual bool is_selected(int mouse_x, int mouse_y);
        std::string _inbox;
        inline std::string value() {return inbox;}

    protected:
        std::string inbox;
        int maxLength;
        int firstChar;

    private:
        std::string _s;
};

#endif // INPUTBOX_HPP
