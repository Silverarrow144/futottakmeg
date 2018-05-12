#ifndef DROPDOWNBOX_HPP
#define DROPDOWNBOX_HPP

#include "graphics.hpp"
#include "widget.hpp"
#include <string>
#include <iostream>
#include <vector>

class dropDownBox : public widget
{
    public:
        dropDownBox(int x, int y, int sx, int sy, std::vector<std::string> v);
        virtual void draw();
        virtual void handle(genv::event ev);
        virtual bool is_dropdown();
        virtual void which_hightlited(int mouse_x, int mouse_y);
        virtual bool is_selected(int mouse_x, int mouse_y);
        std::string _inbox;

    protected:
        bool _dropdown;
        std::string inbox;
        std::vector<std::string> v;
        int w_h, b_h;
        int dropLength;
        int theFirst;

    private:
};

#endif // DROPDOWNBOX_HPP
