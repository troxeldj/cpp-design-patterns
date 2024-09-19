#ifndef __HTML_HPP
#define __HTML_HPP

#include <iostream>
#include <string>
#include <vector>
#include <memory>
struct HtmlElement {
 std::string name;
 std::string text;
 std::vector<HtmlElement> elements;

  HtmlElement(){}
  HtmlElement(const std::string& name, const std::string& text) : 
  name(name), text(text) {}

  std::string str(int indent = 0) {
  }
  
  static std::unique_ptr<HtmlFluentBuilder> build(const std::string& root_name) {
    return std::make_unique<HtmlFluentBuilder>(root_name);
  }

};

struct HtmlBuilder {
  HtmlElement root;
  HtmlBuilder(std::string root_name) {
    root.name = root_name;
  }
  void add_child(std::string childName, std::string childText) {
    HtmlElement e{childName, childText};
    root.elements.emplace_back(e);
  }
  std::string str() {return root.str();}
};

struct HtmlFluentBuilder {
  HtmlElement root;
  HtmlFluentBuilder(std::string root_name) {
    root.name = root_name;
  }
  HtmlFluentBuilder& add_child(std::string childName, std::string childText) {
    HtmlElement e{childName, childText};
    root.elements.emplace_back(e);
    return *this;
  }
  std::string str() {return root.str();}

  operator HtmlElement() const {return root;}
};

#endif