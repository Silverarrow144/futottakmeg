#include "widget.hpp"
#include "graphics.hpp"
using namespace genv;

widget::widget(int x, int y, int sx, int sy) : wx(x), wy(y), wsx(sx), wsy(sy)
{
    r=255;
    g=255;
    b=255;
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

//void widget::handle(event ev) {
//}
