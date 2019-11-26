#ifndef CELL_H
#define CELL_H

#include "Mywindow.h"

class Figure;

class Cell : public Button
{
public:
    static constexpr int size {70};
    enum Type
    {
        Black,
        White
    };
    Cell(Point xy, Graph_lib :: Callback cb_cell, Type t);
    void activate ();
    void deactive ();
    void reset_color();
    bool is_black () const { return type == Black;}
    bool has_figure () const {return fig != nullptr;}
    void attach_figure (Figure& f);
    Figure& detach_figure ();
    Point center () const;
    const Figure& figure () const {return *fig;}
    void attach(Graph_lib :: Window& win) override;
    protected:
    Type type;
    Figure* fig{nullptr};
};

#endif // CELL_H
