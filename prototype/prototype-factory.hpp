#ifndef __PROTO_FACT_HPP 
#define __PROTO_FACT_HPP 
#include <memory.h>
#include "ordinary-cc.hpp"


struct EmployeeFactory {
  static Contact main;
  static Contact aux;

  static std::unique_ptr<Contact> NewMainOfficeEmployee(std::string name, int suite) {
    return NewEmployee(name, suite, main);
  }

  static std::unique_ptr<Contact> NewAuxOfficeEmployee(std::string name, int suite) {
    return NewEmployee(name, suite, aux);
  }

private:
  static std::unique_ptr<Contact> NewEmployee(std::string name, int suite, Contact& proto) {
    std::unique_ptr<Contact> result = std::make_unique<Contact>(proto);
    result->name = name;
    result->address->suite = suite;
    return result;
  }
};

#endif
