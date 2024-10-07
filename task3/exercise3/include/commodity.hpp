#ifndef COMMODITY_HPP
#define COMMODITY_HPP

#include <string>

class Commodity {
    public:
        Commodity(std::string name_, int id_, double price_);
        std::string get_name() const;
        int get_id() const;
        double get_price() const;
        double get_price(double quantity) const;
        void set_price(double new_price);
        double get_price_with_sales_tax(double quantity) const;
    private:
        std::string name;
        int id;
        double price;
};

#endif