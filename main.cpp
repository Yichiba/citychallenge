#include "City.hpp"
#include"Product.hpp"

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <vector>

void process_chunk(const std::string& chunk,City& cities){
    std::stringstream ss(chunk);
    std::string line;
    Product product;

    while (std::getline(ss, line, '\n')) {
        std::stringstream line_ss(line);
        std::string city_name, product_name, price_str;
            std::cout << line<< std::endl;

        if (std::getline(line_ss, city_name, ',') &&
            std::getline(line_ss, product_name, ',') &&
            std::getline(line_ss, price_str)){
            }
            double price = std::stod(price_str);
            product.addProduct(product_name,price);
            cities.addCity(city_name,product);
            // std::cout << <<" "<< product_name <<" " << price << std::endl;
            return ;
            exit(0);
    }

}


            // // Check if city exists in map, create if not
            // if (cities.find(city_name) == cities.end()) {
            //     cities[city_name] = City(city_name);
            // }

            // Add product to the city
            // cities[city_name].addProduct(product_name, price);
        // }
    // }

    // // Example: Print cities and their products
    // for (const auto& [city_name, city] : cities) {
    //     std::cout << "City: " << city.getName() << std::endl;
    //     for (const auto& [product_name, price] : city.getProducts()) {
    //         std::cout << "   Product: " << product_name << ", Price: " << price << std::endl;
        // }
    // }


void read_input(const std::string& filename) {
    City cities;
    std::ifstream file(filename, std::ios::binary);
    if (!file.is_open()) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return;
    }
    constexpr std::streamsize CHUNK_SIZE =1024 * 1024; // 2 MB in bytes
    char buffer[CHUNK_SIZE];

    while (file.read(buffer, CHUNK_SIZE)) {
    process_chunk(std::string(buffer, file.gcount()),cities);
    std::cout <<cities
    exit(0);
        //chuks work on !!! 
    }

    if (file.gcount() > 0) {
        // std::cout.write(buffer, file.gcount());
    }
    file.close();
}

#include <chrono>

int main() {
    auto start = std::chrono::high_resolution_clock::now();
    read_input("input.txt");
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;
    std::cout << "Execution time: " << duration.count() << " seconds" << std::endl;

    return 0;
}
