#ifndef SCENE_HPP
#define SCENE_HPP
#include <string>
#include <functional>

#include "graphics.hpp"
#include "widget.hpp"
#include "window.hpp"


class scene
{
    public:
        scene(int size_x, int size_y, char _tipusa, std::function<void()> draw);


    protected:
        int x=0;
        int y=0;
        int sx, sy;
        char tipusa;

    private:

};

#endif // SCENE_HPP
