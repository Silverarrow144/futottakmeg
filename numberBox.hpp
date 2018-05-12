#ifndef NUMBERBOX_HPP
#define NUMBERBOX_HPP

#include "graphics.hpp"
#include "widget.hpp"

class numberBox : public widget
{
    public:
        numberBox(int x, int y, int sx, int sy, int iMin, int iMax);
        virtual void draw();
        virtual void handle(genv::event ev);
        int _cNumber;

    protected:
        int cNumber;
        int iMin, iMax;
        int maxSzam;

    private:
};

#endif // NUMBERBOX_HPP
