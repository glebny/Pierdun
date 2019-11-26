#ifndef FIGURE_H
#define FIGURE_H

#include "Cell.h"

class Figure
{
public:
    virtual ~Figure () = default;
    virtual bool is_black () const = 0;
    virtual void attach (Cell& cell) = 0;
    void detach () {cell = nullptr;}
    bool is_attached () {return cell != nullptr;}
protected:
    Cell* cell {nullptr};
};

class Checker : public Figure, public Circle
{
public:
    Checker (Graph_lib :: Window& win);
    void attach(Cell &cell) override;
    void draw_lines() const override;
    static constexpr int r {int(0.9 * Cell :: size / 2)};
    static constexpr double f = 0.5;
};

class BlackChecker : public Checker
{
public:
    BlackChecker (Graph_lib :: Window& win);
    bool is_black () const override {return true;}
};

class WhiteChecker : public Checker
{
public:
    WhiteChecker (Graph_lib :: Window& win);
    bool is_black () const override {return false;}
};

#endif // FIGURE_H
