#include "dropDownBox.hpp"
#include "graphics.hpp"

using namespace genv;

dropDownBox::dropDownBox(int x, int y, int sx, int sy, char whichScene, std::vector<std::string> v)
    : widget(x,y,sx,sy,whichScene), v(v)
{
    _dropdown=false;
    inbox=v[0];
    w_h=-1;
    b_h=-1;
    dropLength=5*21;
    theFirst=0;
}

void dropDownBox::which_hightlited(int mouse_x, int mouse_y)
{
    if (mouse_x>wx && mouse_x<wx+wsx)
    for(int i=theFirst;i<theFirst+5 && i<v.size();i++)
    {
        if(mouse_y>wy+wsy+3+(i-theFirst)*20 && mouse_y<wy+wsy+25+(i-theFirst)*20)
        {
            w_h=i-theFirst;
        }
    }
    else
    {
        w_h=-1;
    }
}

void dropDownBox::draw() {
    if (w_h>-1)
    {
        b_h=w_h+theFirst;
    }

    ///Doboz + szöveg
    if (in_focus==false)
    {
        _dropdown=false;
    }
    if(in_focus)
    {
        gout << color(r,g,0);
    }
    else
    {
        gout << color(r,g,b);
    }
    gout << move_to(wx, wy) << box(wsx, wsy);
    gout << move_to(wx+2, wy+2) << color(170,170,170) << box(wsx-4, wsy-4);
    gout << color(0,0,0) << move_to(wx+15,wy+20) << text(inbox);

    ///Le nyíl
    gout << move_to(wx+wsx-10,wy+wsy-12) << line_to(wx+wsx-6,wy+wsy-16);
    gout << move_to(wx+wsx-10,wy+wsy-12) << line_to(wx+wsx-14,wy+wsy-16);

    ///Vonal
    gout << color(130,130,130);
    gout << move_to(wx+wsx-18,wy+3) << line_to(wx+wsx-18,wsy+wy-3);

    ///Lenyíló lista
    if(_dropdown)
    {
        gout << color(180,180,180) << move_to(wx,wy+wsy+1) << box(wsx+1,dropLength+1);
        gout << color(140,140,140) << move_to(wx,wy+wsy+1) << box(wsx,dropLength);
        gout << color(255,255,255) << move_to(wx+2,wy+wsy+3) << box(wsx-4,dropLength-4);


        ///Szöveg kiiratása
        for(int i=theFirst;i<theFirst+5 && i<v.size();i++)
        {
            std::string now;
            now=v[i];
            gout << color(0,0,0) << move_to(wx+5,wy+wsy+20+(i-theFirst)*20) << text(now);
        }
        if(w_h>-1)
        {
            gout << color(0,0,150);
            gout << move_to(wx+2,wy+wsy+3+w_h*20) << box(wsx-4,22);
            gout << color(255,255,255) << move_to(wx+5,wy+wsy+20+w_h*20) << text(v[w_h+theFirst]);
        }
        if(b_h>-1)
        {
            gout << color(0,0,150);
            gout << move_to(wx+2,wy+wsy+3+(b_h-theFirst)*20) << box(wsx-4,22);
            gout << color(255,255,255) << move_to(wx+5,wy+wsy+20+(b_h-theFirst)*20) << text(v[b_h]);
        }
    }
    else
    {
        gout << color(0,0,0) << move_to(wx,wy+wsy+1) << box(wsx+1,dropLength+1);
    }
}

void dropDownBox::handle(event ev)
{
    ///Kattintásra lenyílás
    if ( ( (ev.button==btn_left) && (ev.pos_x>wx+wsx-18) && (ev.pos_x<wx+wsx) && (ev.pos_y>wy) && (ev.pos_y<wy+wsy)  ) )
    {
        if (_dropdown)
        {
            _dropdown=false;
        }
        else
        {
            _dropdown=true;
        }
    }

    ///O-val lenyílás
    if (in_focus && ev.type==ev_key && ev.keycode=='o')
    {
        if (_dropdown)
        {
            _dropdown=false;
        }
        else
        {
            _dropdown=true;
        }
    }

    ///Kiválasztás egérre
    if ((w_h>-1) && (ev.button==btn_left) && (ev.pos_x>wx+2) && (ev.pos_x<wx+wsx-2) && (ev.pos_y>wy+wsy+3) && (ev.pos_y<wy+wsy+dropLength-3) )
    {
        inbox=v[w_h+theFirst];
        _dropdown=false;
    }

    ///Kurzorral lépegetés
    if (  (  (ev.keycode==key_up) || (ev.keycode==key_down)   ) && _dropdown   )
    {
        if (ev.keycode==key_up && b_h>-1)
        {
            b_h--;
            if(b_h<theFirst && theFirst>0)
            {
                theFirst--;
            }
        }
        if ((ev.keycode==key_down))
        {
            int ennel=v.size()-1;
            if (b_h<ennel)
            {
                b_h++;
                if (b_h>theFirst+4)
                {
                    theFirst++;
                }
            }
        }
    }

    ///Egérrel görgetés
    if ( ev.type==ev_mouse && (ev.button==btn_wheelup || ev.button==btn_wheeldown) && _dropdown  )
    {
        if (ev.button==btn_wheelup && theFirst>0)
        {
            theFirst--;
        }

        if (ev.button==btn_wheeldown && theFirst<v.size()-5)
        {
            theFirst++;
        }
    }

    ///Enterrel kiválasztás
    if ( (ev.type==ev_key) && (ev.keycode==key_enter) && (b_h>-1) )
    {
        inbox=v[b_h];
        _dropdown=false;
    }
}


bool dropDownBox::is_dropdown()
{
    return _dropdown;
}

bool dropDownBox::is_selected(int mouse_x, int mouse_y)
{
    if (_dropdown)
    {
        return mouse_x>wx && mouse_x<wx+wsx && mouse_y>wy && mouse_y<wy+2*wsy+101;
    }
    else
    {
        return mouse_x>wx && mouse_x<wx+wsx && mouse_y>wy && mouse_y<wy+wsy;
    }
}
