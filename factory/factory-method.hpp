#ifndef __FACTORY_METHOD_HPP
#define __FACTORY_METHOD_HPP
#include "math.h"

struct Point {
  float x;
  float y;


  protected:
  Point(const float x, const float y) : x{x}, y{y} {}

  public:
  static Point NewCartesian(float x, float y) {
    return {x, y};
  }

  static Point NewPolar(float r, float theta) {
    return {r * cos(theta), r * sin(theta)};
  }
};



#endif