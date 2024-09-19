#include "html.hpp"
#include "groovy-html.hpp"
#include "composite.hpp"


int main() {
  // builder
  HtmlBuilder builder {"ul"};
  builder.add_child("li", "hello");
  builder.add_child("li", "world");
  std::cout << builder.str() << "\n";

  //fluent builder
  HtmlElement e = HtmlElement::build("ul")
  ->add_child("li", "hello")
  .add_child("li", "world");
  std::cout << e.str() << "\n";

  // groovy builder
  std::cout << P {
    IMG {"http://pokemon.com/pikachu.png"}
  }
  << std::endl;
}