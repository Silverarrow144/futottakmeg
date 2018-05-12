#ifndef SCENE_HPP
#define SCENE_HPP
#include <string>
#include <functional>

#include "graphics.hpp"
#include "widget.hpp"
//#include "window.hpp"
//#include "graphics.hpp"
#include <vector>


class scene
{
    public:
        scene(int size_x, int size_y, char _tipusa);
        virtual void draw() = 0;
        char tip() {return tipusa;}
        int sxret() {return sx;}

    protected:
        int x=0;
        int y=0;
        int sx, sy;
        char tipusa;

    private:

};


class fomenu : public scene
{
public:
    fomenu(int size_x, int size_y, char _tipusa);
    virtual void draw();

};



#endif // SCENE_HPP
