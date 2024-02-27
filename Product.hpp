#ifndef PRODUCT_HPP
#define PRODUCT_HPP
#include <iostream>
#include <unordered_map>
#include <string>

class Product {
private:
    std::unordered_map<std::string, double> products;
    double totalPrice;

public:
    Product() : totalPrice(0.0) {}

    void addProduct(const std::string& productName, double price) {
        if (products.find(productName) == products.end() || price < products[productName]) {
            totalPrice -= products[productName]; // Subtract the old price from the total
            products[productName] = price;
            totalPrice += price; // Add the new price to the total
        }
    }

    double getPrice(const std::string& productName) {
        return products.find(productName) != products.end() ? products[productName] : -1;
    }

   double getTotalPrice() const {
        return totalPrice;
    }
};




#endif