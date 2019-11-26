#include "Figure.h"

Cell :: Cell (Point p, Graph_lib :: Callback cb, Type t)
    :Button {p, size, size, " ", cb},
      type {t}
{}

void Cell :: attach (Graph_lib :: Window &win)
{
    Button :: attach (win);
    {
        if (pw) pw -> color (type == Black ? Graph_lib :: Color :: blue : Graph_lib :: Color :: white);
    }
}

void Cell ::attach_figure (Figure& f)
{
    if (fig)
        throw std::runtime_error("error");
    fig = &f;
    f.attach (*this);
}

Figure& Cell :: detach_figure ()
{
    if (fig)
    {
        Figure* buf = fig;
        fig -> detach();
        fig = nullptr;
        return *buf;
    }
    throw std::runtime_error("error");
}

Point Cell :: center () const
{
    if (pw)
    {
        return Point {loc.x + width / 2, loc.y + height / 2};
    }
}

void Cell :: activate()
{
    if (pw)
    {
        pw -> color (FL_SELECTION_COLOR);
    }
}

void Cell :: deactive()
{
    reset_color();
}

void Cell :: reset_color()
{
    if (pw)
    {
        if (is_black()) pw -> color (Color :: blue);
        else pw -> color (Color :: white);
    }
}
