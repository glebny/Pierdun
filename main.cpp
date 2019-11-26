#include <iostream>
#include <sstream>
#include <exception>

#include "C:/Users/Glbn/Documents/Graph_lib/Graph.h"

using namespace Graph_lib;
#include "Board.h"


int main ()
try
{
    Board desk ({100,100});
    return gui_main();
}
catch (std::exception& e)
{
  std::cerr << e.what() << std::endl;
  return 1;
}
catch (...)
{
  std::cerr <<"Oops, something went wrong..."<< std::endl;
  return 2;
}
//ea
