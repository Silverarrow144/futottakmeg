#ifndef JUSTTEXT_HPP
#define JUSTTEXT_HPP
#include <string>
#include "widget.hpp"
#include "graphics.hpp"

class justText : public widget {
protected:
    std::string _s;
public:
    justText(int x, int y, int sx, int sy, char whichScene, std::string s);
    virtual void draw();
    virtual bool focusable() const {return false;}
    void setText(std::string s) {_s=s;}
    virtual void handle(genv::event ev);
};

#endif // JUSTTEXT_HPP
