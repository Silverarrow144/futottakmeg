#include "window.hpp"
#include <vector>
using namespace genv;

window::window()
{
    //widgetek =std::vector<widget*>();
    //ctor
}

void window::event_loop() {
    event ev;
    int focus = -1;
    while(gin >> ev) { //&& ev.keycode!=key_escape ) {
        /*for (widget * w : widgetek) {
            w->which_hightlited(ev.pos_x, ev.pos_y);
        }*/
        //Egérkattintásra
        if (ev.type == ev_mouse && ev.button==btn_left) {
            for (size_t i=0;i<widgetek.size();i++) {
                if (widgetek[i]->is_selected(ev.pos_x, ev.pos_y)) {
                        focus = i;

                        //Csak egy legyen focus-ban
                        for(size_t j=0;j<widgetek.size();j++)
                        {
                            widgetek[j]->in_focus=false;
                        }
                        widgetek[i]->in_focus=true;
                }
                //Ha bárhova máshova kattint
                else
                {
                    focus=-1;
                    widgetek[i]->in_focus=false;
                    for(size_t j=0;j<widgetek.size();j++)
                        if(widgetek[j]->in_focus)
                        {
                            focus=j;
                        }
                }
            }
        }

        //Ha nincs focus-ban
        if (focus!=-1) {
            widgetek[focus]->handle(ev);
        }

        /*//Kirajzolás
        for (Widget * w : widgets) {
            w->draw();
        }*/

        ///Kirajzolás
        for (size_t i=0;i<widgetek.size();i++) {
            widgetek[i]->draw();
        }

        gout << refresh;

        /*//File-ba iratás
        if(ev.type==ev_key && ev.keycode==key_enter)
        {
            ofstream myfile;
            myfile.open ("results.txt");
            int szam;
            string szov;
            string oLine;
            for (int i=0;i<widgets.size();i++)
            {
                szam=widgets[i]->szama();
                szov=widgets[i]->szovege();
                if(szam!=0)
                {
                    oLine= to_string(szam) + ' ' + szov;
                    myfile << oLine << endl;
                }
                else
                {
                    myfile << szov << endl;
                }
            }
            myfile.close();
        }*/
    }
}
