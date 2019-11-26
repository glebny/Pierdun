#ifndef MYWINDOW_H
#define MYWINDOW_H

#include <iostream>
#include "C:/Users/Glbn/Documents/Graph_lib/Simple_window.h"
#include "C:/Users/Glbn/Documents/Graph_lib/Graph.h"

using namespace Graph_lib;


class MyWindow : public Simple_window
{
public:
    MyWindow (Point xy, int w, int h, const std::string& label):
        Simple_window (xy, w, h, label),
        quit_button {{x_max()-70, 20}, 70, 20, "quit", cb_quit}
    {
        attach (quit_button);
    }
    Button quit_button;
    static void cb_quit (Address, Address pw)
    {
        reference_to <MyWindow> (pw).quit();
    }
    void quit ()
    {
        hide ();
    }
};

#endif // MYWINDOW_H
