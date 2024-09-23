#ifndef __ORINARY_PROTO_HPP
#define __ORDINARY_PROTO_HPP 
#include <iostream>
#include <string>

struct Address {
  std::string street, city;
  int suite;

  Address(const Address& other) : street{other.street}, city{other.city}
  , suite{other.suite} {
  }

  Address(const std::string& street, const std::string& city, const int suite) : street{street}, city{city}, suite{suite} {};
};

struct Contact {
  std::string name;
  Address* address;

  Contact(const Contact& other) : name{other.name}, address{new Address{*other.address}} {}
  Contact(const std::string& name, Address& address) : name{name}, address{&address} {}
  Contact(const std::string& name, Address* address) : name{name}, address{address} {}
  ~Contact() {
    free(this->address);
  }
  private:
  Contact(){}
};
#endif