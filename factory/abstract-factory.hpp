#ifndef __ABSTRACT_FAC_HPP
#define __ABSTRACT_FAC_HPP
#include <iostream>
#include <string>
#include <memory>
#include <map>
#include <functional>
struct HotDrink {
  virtual void prepare(int volume) = 0;
};

struct Tea : HotDrink {
  void prepare(int volume) override {
    std::cout << "Take tea bag, boil water, pour " << volume <<
    "ml, add some lemon" << std::endl;
  }
};

struct Coffee : HotDrink {
  void prepare(int volume) override {
   std::cout << "Take coffee grounds. Boil " << volume
   << " ml of water. Pour over coffee grounds." << std::endl;
  }
};

struct HotDrinkFactory {
  virtual std::unique_ptr<HotDrink> make() const = 0;
};

struct CoffeeFactory : HotDrinkFactory {
  std::unique_ptr<HotDrink> make() const override {
    return std::make_unique<Coffee>();
  }
};

struct TeaFactory : HotDrinkFactory {
  std::unique_ptr<HotDrink> make() const override {
    return std::make_unique<Tea>();
  }
};

class DrinkFactory {
  std::map<std::string, std::unique_ptr<HotDrinkFactory>> hot_factories;
public:
  DrinkFactory() {
    hot_factories["coffee"] = std::make_unique<CoffeeFactory>();
    hot_factories["tea"] = std::make_unique<TeaFactory>();
  }

  std::unique_ptr<HotDrink> make_drink(const std::string& name) {
    auto drink = hot_factories[name]->make();
    drink->prepare(200);
    return drink;
  }
};

class DrinkWithVolumeFactory {
  std::map<std::string, std::function<std::unique_ptr<HotDrink>()>> factories;

public:
  DrinkWithVolumeFactory() {
    factories["tea"] = [] {
      auto tea = std::make_unique<Tea>();
      tea->prepare(200);
      return tea;
    };
    factories["coffee"] = [] {
      auto coffee = std::make_unique<Coffee>();
      coffee->prepare(200);
      return coffee;
    };
  }

  inline std::unique_ptr<HotDrink>
  make_drink(const std::string& name) {
    return factories[name]();
  }
};


#endif