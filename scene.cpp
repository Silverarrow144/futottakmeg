#include "scene.hpp"
#include "graphics.hpp"
#include <iostream>
#include <fstream>

using namespace genv;
using namespace std;

scene::scene(int size_x, int size_y, char _tipusa) : sx(size_x), sy(size_y), tipusa(_tipusa){}

fomenu::fomenu(int size_x, int size_y, char _tipusa) : scene(size_x, size_y, _tipusa){}

lovarda::lovarda(int size_x, int size_y, char _tipusa) : scene(size_x, size_y, _tipusa){}

legelo::legelo(int size_x, int size_y, char _tipusa) : scene(size_x, size_y, _tipusa){}

versenypalya::versenypalya(int size_x, int size_y, char _tipusa) : scene(size_x, size_y, _tipusa){}

naptar::naptar(int size_x, int size_y, char _tipusa) : scene(size_x, size_y, _tipusa){}

bolt::bolt(int size_x, int size_y, char _tipusa) : scene(size_x, size_y, _tipusa){}

menu::menu(int _mx, int _my, int size_x, int size_y, char _tipusa) : mx(_mx), my(_my), scene(size_x, size_y, _tipusa){}

void fomenu::draw()
{
    ifstream cim;
    cim.open("fcim.kep");

    int kep_x, kep_y;
    cim >> kep_x >> kep_y;

    canvas kep;
    kep.open(kep_x,kep_y);
    kep.transparent(true);

    for(int y=0;y<kep_y;y++)
    {
        for(int x=0;x<kep_x;x++)
        {
            int r,g,b;
            cim >> r >> g >> b;
            kep << color(r,g,b) << move_to(x,y) << dot;
        }
    }

    gout << move_to(x,y) << color(100,100,255) << box(sx, sy/2-1);
    gout << move_to(x,sy/2) << color(0,150,0) << box(sx, sy/2);

    gout << stamp(kep,10,0);
}

void lovarda::draw(){
    ifstream file1;
    file1.open("vl2.kep");

    int kep_x, kep_y;
    file1 >> kep_x >> kep_y;

    canvas kep;
    kep.open(kep_x,kep_y);
    kep.transparent(true);

    for(int y=0;y<kep_y;y++)
    {
        for(int x=0;x<kep_x;x++)
        {
            int r,g,b;
            file1 >> r >> g >> b;
            kep << color(r,g,b) << move_to(x,y) << dot;
        }
    }



    gout << move_to(0,0) << color(155,100,0) << box(sx, sy);

    gout << stamp(kep,260,150);
}

void legelo::draw(){
    gout << move_to(0,0) << color(0,100,0) << box(sx, sy);
}

void versenypalya::draw(){
    gout << move_to(0,0) << color(100,200,100) << box(sx, sy);
}

void naptar::draw(){
    gout << move_to(0,0) << color(255,255,255) << box(sx, sy);
}

void bolt::draw(){
    gout << move_to(0,0) << color(200,0,0) << box(sx, sy);
}

void menu::draw(){
    gout << move_to(mx,my) << color(0,0,200) << box(sx, sy);
}
