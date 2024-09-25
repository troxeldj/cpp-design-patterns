#ifndef __BRIDGE_HPP
#define __BRIDGE_HPP
#include <iostream>

class Renderer {
public:
  virtual void render_circle(float x, float y, float radius) = 0;
};

class VectorRenderer : public Renderer {
  public:
  void render_circle(float x, float y, float radius) override {
    std::cout << "Drawing a vector circle of radius " << radius << "\n";
  }
};

class RasterRenderer : public Renderer {
  public:
  void render_circle(float x, float y, float radius) override {
    std::cout << "Rasterizing a circle of radius " << radius << "\n";
  }
};

class Shape {
protected:
  Renderer& renderer;
  Shape(Renderer& renderer) : renderer{renderer} {}
public:
  virtual void draw() = 0;
  virtual void resize(float factor) = 0;
};

class Circle : public Shape {
public:
  float x, y, radius;

  void draw() override {
    renderer.render_circle(x, y, radius);
  }

  void resize(float factor) override {
    radius *= factor;
  }

  Circle(Renderer& renderer, float x, float y, float radius) : 
  Shape{renderer}, x{x}, y{y}, radius{radius} {}
};


#endif