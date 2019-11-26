#include "Figure.h"
using namespace Graph_lib;
Checker :: Checker (Graph_lib :: Window& win)
    :Circle (Point {0,0}, r)
{
    set_style (Line_style (Line_style :: solid, 2));
    win.attach (*this);
}

void Checker :: attach (Cell& c)
{
    if (is_attached()) throw std :: runtime_error ("error");
    cell = &c;
    move (c.center().x - center().x, c.center().y - center().y);
}

void Checker :: draw_lines () const
{
    Circle :: draw_lines ();
    if (color().visibility())
    {
        int r1 = radius() * f;
        fl_arc (center().x - r1, center().y - r1, r1 + r1, r1 + r1, 0, 360);
    }
}

BlackChecker :: BlackChecker (Graph_lib :: Window& win)
    :Checker (win)
{
    set_color (Color :: white);
    set_fill_color (Color :: black);
}

WhiteChecker :: WhiteChecker (Graph_lib :: Window& win)
    :Checker (win)
{
    set_color(Color :: black);
    set_fill_color(Color :: white);
}

