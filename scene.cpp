#include "scene.hpp"
#include "graphics.hpp"
#include <iostream>

using namespace genv;
using namespace std;

scene::scene(int size_x, int size_y, char _tipusa) : sx(size_x), sy(size_y), tipusa(_tipusa)
{

}

fomenu::fomenu(int size_x, int size_y, char _tipusa) : scene(size_x, size_y, _tipusa)
{

}

void fomenu::draw()
{
    gout << move_to(0,0) << color(100,100,255) << box(sx, sy/2-1);
    //cout << sx << ' ' << sy;
    gout << move_to(0,sy/2) << color(0,150,0) << box(sx, sy/2);
    //gout << move_to(10,10) << color(255,255,255) << box(10,10);
}
