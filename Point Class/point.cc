#include "point.h"

point::point(double init_x, double init_y)
  {
    x = init_x;
    y = init_y;}
void point::shift(double dx, double dy)
{
  x = x+dx;
  y = y+dy;
}

double point::get_x() const
{
  return x;
}
double point::get_y() const
{
  return y;
}
