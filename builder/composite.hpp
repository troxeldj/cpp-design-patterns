#ifndef __COMPOSITE_HPP
#define __COMPOSITE_HPP
#include <iostream>
#include <string>
struct Person {
  // address
  std::string street_address, post_code, city;

  // employment
  std::string company_name, position;
  int annual_income = 0;

  Person() {}

};


class PersonBuilderBase {
  protected:
    Person& person;

    explicit PersonBuilderBase(Person& person)
      : person{person} {}

  public:
    operator Person() {
      return std::move(person);
    }

    //builder facts
    PersonAddressBuilder lives() const;
};

class PersonBuilder : public PersonBuilderBase {
  Person p;

  public:
    PersonBuilder() : PersonBuilderBase{p} {}
};


class PersonAddressBuilder : public PersonBuilderBase {
  typedef PersonAddressBuilder self;
  public:
    explicit PersonAddressBuilder(Person& person)
      : PersonBuilderBase{person} {}

    self& at(std::string street_address) {
      person.street_address = street_address;
      return *this;
    }

    self& with_postcode(std::string post_code) {
      person.post_code = post_code;
      return *this;
    }

    self& in(std::string city) {
      person.city = city;
      return *this;
    }
};


#endif