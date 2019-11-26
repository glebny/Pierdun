#ifndef BOARD_H
#define BOARD_H

#include "Mywindow.h"
#include "Figure.h"


class Board : public MyWindow
{
public:
    Board (Point xy);
    static constexpr int N {4};
    static constexpr int max_N {8};
    Cell& at (Point xy);
    Cell& at (char c, int x);
private:
    Marks marks_x;
    Marks marks_y;
    Vector_ref <Cell> cells;
    Vector_ref <Figure> figures;
    static constexpr int cell_size {70};
    static void cb_cell (Address pwid, Address pwin)
    {
        reference_to <Board> (pwin).clicked(pwid);
    }
    void clicked (Address pwid);
    Cell* selected_cell {nullptr};
};

#endif // BOARD_H
