#include "justText.hpp"
#include <string>
#include <iostream>
using namespace std;
using namespace genv;

justText::justText(int x, int y, int sx, int sy, char whichScene, string s) : widget(x,y,sx,sy,whichScene) {
    _s=s;
}
void justText::draw() {
    gout << color(0,0,0) << move_to(wx, wy) << box(wsx, wsy) << color(255,255,255);
    gout << move_to(wx,wy+20) << color(255,255,255) << text(_s);
}

void justText::handle(event ev) {
    //cout << ' ';
}
