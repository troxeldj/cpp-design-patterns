#include "ordinary-cc.hpp"

int main() {
  // copy constructor
  Contact john{"John", new Address{"123 East Dr.", "London", 0}};
  Contact bill{john};
  bill.name = "bill";

  std::cout << "test\n";
}