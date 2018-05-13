#include "window.hpp"
#include <vector>
#include <iostream>
using namespace genv;
using namespace std;

window::window()
{
    //widgetek =std::vector<widget*>();
    //ctor
}

void window::clear_it()
{
    gout << move_to(0,0) << color(0,0,0) << box(640,480);
}

void window::event_loop() {
    event ev;

    while(gin >> ev) {


    for (size_t i=0;i<widgetek.size();i++){
        widgetek[i]->handle(ev);
    }

        ///Kirajzolás



            ///Képernyok
        for (size_t i=0;i<scenes.size();i++) {

            if(scenes[i]->tip()==actualType){
                scenes[i]->draw();
            }
            if(scenes[i]->tip()=='M' && actualType!='F' ){
                scenes[i]->draw();
            }
        }

            ///Widgetek
        for (size_t i=0;i<widgetek.size();i++) {
            if(widgetek[i]->getScene()==actualType){
            widgetek[i]->draw();
            }
            //cout << widgetek[i]->_whichScene;
        }



        gout << refresh;


    }
}
