#ifndef CITY_HPP
#define CITY_HPP
#include "Product.hpp"

class Product;

class City {
private:
    std::unordered_map<std::string, Product> cities; // Map ofcities associated with city names
    double total;

public:
    City() : total(0.0) {}

    // Method to add a product to a city
    void addCity(const std::string& cityName, const Product& product) {
       cities[cityName] = product;
        total = product.getTotalPrice(); // Update the total price
    }

    // Method to retrieve the total price for a city
    double getTotal(const std::string& cityName) const {
        return total;
    }

    // Method to retrieve a product for a city
    Product getProduct(const std::string& cityName) const {
        return cities.at(cityName);
    }
};



#endif