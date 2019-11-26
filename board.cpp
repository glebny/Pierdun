#include "Board.h"

Cell :: Type type_of_cell (int i, int j)
{
    if ( (i + j) % 2 == 0)
        return Cell :: Type :: Black;
    else
        return Cell :: Type :: White;
}

std :: string letters_x ()
{
    std :: string s;
    for (int i = 0; i < Board :: N; ++i)
    {
        s += i + 'a';
    }
    return s;
}

std :: string letters_y ()
{
    std :: string s;
    for (int i = 0; i < Board :: N; ++i)
    {
        s += '1' + i;
    }
    return s;
}

Cell& Board :: at (Point xy)
{
    int i = (xy.x - 30) / cell_size;
    int j = (xy.y - 20) / cell_size;
    return at ('a' + i, j);
}

Cell& Board :: at (char i, int j)
{
    return cells [i - 'a' + j - 1];
}

Board :: Board (Point xy) :
    MyWindow (xy, N * cell_size + 100, N * cell_size + 40, "checkers"),
    marks_x {letters_x ()},
    marks_y {letters_y ()}
{
    static constexpr int size_marks {N * cell_size};
    for (int i = 0; i < N; ++i)
    {
        marks_x.add (Point {i * cell_size + 30 + cell_size / 2, 30 + size_marks});
        marks_y.add (Point {20, i * cell_size + 20 + cell_size / 2});
    }

    size_range (size_marks + 100, size_marks + 40, size_marks + 100, size_marks + 40);
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            cells.push_back (new Cell {Point {30 + i * cell_size, 20 + j * cell_size}, cb_cell, type_of_cell (i,j)});
            attach (cells [cells.size() - 1]);
        }
    }
    using Positions = std::vector <std::pair <char, int>>;
    for (auto [c, j] : Positions { {'a', 1}, {'c', 1}})
    {
        figures.push_back (new BlackChecker {*this});
        at (c, j).attach_figure (figures [figures.size() - 1]);
    }
    for (auto [c, j] : Positions { {'b', 4}, {'d', 4}})
    {
        figures.push_back (new WhiteChecker {*this});
        at (c, j).attach_figure (figures [figures.size() - 1]);
    }
}

void Board :: clicked (Address wid)
{
    if (!wid) throw std :: runtime_error ("error");
    Fl_Widget& w = Graph_lib :: reference_to<Fl_Widget> (wid);
    Cell& c = at (Point{w.x(),w.y()});
    if (!c.is_black()) return;
    if (!selected_cell)
    {
        if (c.has_figure())
        {
            selected_cell = &c;
            c.activate();
        }
        else
        {
            selected_cell -> deactive();
            if (selected_cell == &c)
            {
                selected_cell = nullptr;
            }
            else if (c.has_figure())
            {
                selected_cell = &c;
                c.activate();
            }
            else
            {
                c.attach_figure(selected_cell -> detach_figure());
                selected_cell = nullptr;
            }
        }
    }
    Fl :: redraw();
}
