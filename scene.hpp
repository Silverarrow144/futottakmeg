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

class lovarda : public scene
{
public:
    lovarda(int size_x, int size_y, char _tipusa);
    virtual void draw();

};

class legelo : public scene
{
public:
    legelo(int size_x, int size_y, char _tipusa);
    virtual void draw();

};

class versenypalya : public scene
{
public:
    versenypalya(int size_x, int size_y, char _tipusa);
    virtual void draw();

};

class naptar : public scene
{
public:
    naptar(int size_x, int size_y, char _tipusa);
    virtual void draw();

};

class bolt : public scene
{
public:
    bolt(int size_x, int size_y, char _tipusa);
    virtual void draw();

};

class menu : public scene
{
protected:
    int mx, my;
public:
    menu(int _mx, int _my, int size_x, int size_y, char _tipusa);
    virtual void draw();

};



#endif // SCENE_HPP
