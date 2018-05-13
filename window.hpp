#ifndef WINDOW_HPP
#define WINDOW_HPP

#include "graphics.hpp"
#include "widget.hpp"
#include "scene.hpp"



class window
{
    public:
        window();
        void event_loop();
        virtual void anEvent(std::string whatEvent){}
        void clear_it();
        char actualType='F';

    protected:
        std::vector<widget*> widgetek;
        std::vector<scene*> scenes;

    private:
};

#endif // WINDOW_HPP
