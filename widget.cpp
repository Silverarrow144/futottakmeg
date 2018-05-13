#include "widget.hpp"
#include "graphics.hpp"
using namespace genv;

widget::widget(int x, int y, int sx, int sy, char _whichScene) : wx(x), wy(y), wsx(sx), wsy(sy), whichScene(_whichScene)
{
}

bool widget::is_selected(int mouse_x, int mouse_y)
{
    return mouse_x>wx && mouse_x<wx+wsx && mouse_y>wy && mouse_y<wy+wsy;
}

void widget::which_hightlited(int mouse_x, int mouse_y)
{
    int a;
    a=-1;
}
