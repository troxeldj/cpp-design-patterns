#ifndef __ORINARY_PROTO_HPP
#define __ORDINARY_PROTO_HPP 
#include <iostream>
#include <string>

struct Address {
  std::string street, city;
  int suite;
};

struct Contact {
  std::string name;
  Address* address;
};
#endif