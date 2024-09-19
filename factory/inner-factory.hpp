#ifndef __FACTORY_CLASS_HPP
#define __FACTORY_CLASS_HPP
#include "math.h"

struct Point {
private:
  Point(float x, float y) : x(x), y(y) {}
  struct PointFactory {
  private:
    PointFactory(){}

  public: 
    static Point NewCartesian(float x, float y) {return {x, y};}
    static Point NewPolar(float r, float theta) {return {r * cos(theta), r * sin(theta)};}
  };

public:
  float x, y;
  static PointFactory Factory;
};



#endif