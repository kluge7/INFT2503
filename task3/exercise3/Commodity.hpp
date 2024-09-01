#ifndef COMMODITY_HPP
#define COMMODITY_HPP

#include <string>

using namespace std;

class Commodity {
  public:
    Commodity(const string &name_, int id_, double price_) 
        : name(name_), id(id_), price(price_) {}
    
    // Const is to ensure no modifcation of the object
    string get_name() const {
        return name;
    }
    
    int get_id() const {
        return id;
    }

    double get_price() const {
        return price;
    }

    double get_price(double quantity) const {
        return price * quantity;
    }

    double get_price_with_sales_tax(double quantity) const {
        return price * quantity * 1.25;
    }

    void set_price(double new_price) {
        price = new_price;
    }

  private:
    string name;
    int id;
    double price;
};

#endif 
