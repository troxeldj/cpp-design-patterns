// #include "factory-method.hpp"
// #include "factory-class.hpp"
//#include "inner-factory.hpp"
#include "abstract-factory.hpp"


int main() {
  // factory method
  //Point p = Point::NewCartesian(10, 10);
  //Point p2 = Point::NewPolar(2, 0.75);

  // factory class
  //Point p = PointFactory::NewCartesian(10, 10);
  //Point p2 = PointFactory::NewPolar(30, 0.9);

  // inner factory
  //Point p = Point::Factory.NewCartesian(10, 10);
  //Point p2 = Point::Factory.NewPolar(30, 0.9);

  //Abstract Factory
  DrinkFactory df{};
  auto coffee = df.make_drink("coffee");
  auto tea = df.make_drink("tea");
}