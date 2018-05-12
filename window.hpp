#ifndef WINDOW_HPP
#define WINDOW_HPP

#include "graphics.hpp"
#include "widget.hpp"

class window
{
    public:
        window();
        void event_loop();
        virtual void anEvent(std::string whatEvent){}

    protected:
        std::vector<widget*>  widgetek;

    private:
};

#endif // WINDOW_HPP
